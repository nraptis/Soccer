#include "TwistExpander_BasketBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_BasketBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9D1D74B32E8977C1ULL + 0xA9E11F09588D29B2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x97AA37D0ADDD67D3ULL + 0xBD573B87AEA81B19ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF5747494548293BBULL + 0x9481A51DEE0ADD0CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBD3D37D8BC2D6CB7ULL + 0xCCACCC60E87B4CB7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB8FDF16738217F75ULL + 0xE8F5A3F0B1457826ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAB371DB15E8B838DULL + 0xDB570BD6005EBD77ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE74563C5AF22DCAFULL + 0xF998CE59C2557EE4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC9B1D25019BB58DDULL + 0xF361AAEC79C36618ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFA7172FC692D4449ULL + 0xBAB6F6E2844B1F8DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8C6DA7F6447F94CFULL + 0xE9F29597144C5E10ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCC1761ED1D4227FFULL + 0xBDDB990F6460380BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFB2BE3AC8A4DF8CFULL + 0xD5281BB3CBD73B6CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9996266C9251BB87ULL + 0xF670C741B9612EC1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA66C43B89F6F08EFULL + 0xD71D5A7CC60D0830ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC27ECBF2BD9C92CDULL + 0x8B65763F12649E99ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBA0EDF30B0D3ABE7ULL + 0xA365C92461CE3781ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4245U)) & S_BLOCK1], 53U) ^ RotL64(pSnow[((aIndex + 3282U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2249U)) & S_BLOCK1], 39U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 24U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aScatter, 13U)) + 17711946802293254150U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 18U)) + 16652362590489569378U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aPrevious, 11U)) + 6972810344198183097U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 37U)) + 13117100889782940546U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 13199305696782626591U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 27U)) + 992156184392760945U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 22U)) + RotL64(aCarry, 57U)) + 13791265442074543880U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 53U)) + 17057087245252294859U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 43U)) + 13444195995883541046U) + aNonceWordH;
            aOrbiterE = (aWandererH + RotL64(aIngress, 5U)) + 6723678233676059420U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 7913379431208430475U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4481887195529300665U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11892724101424384078U;
            aOrbiterH = RotL64((aOrbiterH * 3468639499716604111U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7700902083270424194U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1888001433557140271U;
            aOrbiterD = RotL64((aOrbiterD * 8975562955027025349U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14996753906788986929U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 939004845422123765U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2507090308972292313U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 11922230289291941807U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15681187459741147199U;
            aOrbiterK = RotL64((aOrbiterK * 10124947739653819101U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9119043713532718155U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8327697433992362166U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 11157657162184304567U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13630755116592440359U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 771252613886022889U;
            aOrbiterI = RotL64((aOrbiterI * 2958918915223536519U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8524239721467527770U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 17732617735422435572U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 13992947983987668631U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5265753270696005619U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14456128349522985053U;
            aOrbiterC = RotL64((aOrbiterC * 5406509991740849617U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12909993509014176457U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10113568710432654194U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6857806395910432831U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14818978163348513071U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17843349910031998923U;
            aOrbiterF = RotL64((aOrbiterF * 13608449524810499593U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12589077818524017161U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17711946802293254150U;
            aOrbiterE = RotL64((aOrbiterE * 9454569713107675231U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 36U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterI, 6U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 24U) + RotL64(aOrbiterH, 27U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterC, 37U)) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 51U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 23U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterA, 46U)) + aOrbiterF) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterB, 19U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6319U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5630U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 8339U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8606U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 4U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aScatter, 21U)) + 9630214189402543339U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 4072576573737526819U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 24U)) + 15994787452709618869U) + aNonceWordE;
            aOrbiterF = ((aWandererF + RotL64(aCross, 47U)) + 6403240137132259482U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 10229266900170507720U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 51U)) + 5025294577989748989U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 37U)) + 16696461238217956883U) + aNonceWordF;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 5U)) + 9878318855341719119U) + aNonceWordC;
            aOrbiterG = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 16086635438116177346U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 34U)) + 12295437783084203730U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 19U)) + 7681150419912842402U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2639104034287637448U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12298170009332243573U;
            aOrbiterK = RotL64((aOrbiterK * 9397919591171238575U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3485932317267669626U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16569551670038752475U;
            aOrbiterD = RotL64((aOrbiterD * 8139802826402217631U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4448490103784103954U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14510534073046885941U;
            aOrbiterJ = RotL64((aOrbiterJ * 7777192047386438305U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4286195398675733451U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15790355933840266463U;
            aOrbiterC = RotL64((aOrbiterC * 13342257823027075501U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6362891510370156055U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 15121822034579983174U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7268045994574844937U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13817341015719915628U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14113474087906143783U;
            aOrbiterE = RotL64((aOrbiterE * 12838910141533126059U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9988301252236121106U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11287477288382171758U;
            aOrbiterF = RotL64((aOrbiterF * 4979297247881426383U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9491727010910328644U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7961202721830514030U;
            aOrbiterH = RotL64((aOrbiterH * 16300364540313620767U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10058066852293995222U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 541563830282750968U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1516823517052019845U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7791201128863372861U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8334318157449352359U;
            aOrbiterB = RotL64((aOrbiterB * 2924838607279239375U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6861081455774799715U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9630214189402543339U;
            aOrbiterA = RotL64((aOrbiterA * 10837610668580336781U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 14U) + aOrbiterK) + RotL64(aOrbiterD, 57U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterE, 14U)) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterI, 11U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 10U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterD, 23U)) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 38U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 24U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15362U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14774U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 11125U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 11809U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 13U) + RotL64(aCarry, 60U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 12206125048349568300U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 3U)) + 5843520589343188818U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 37U)) + 12195046124287121687U) + aNonceWordP;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 51U)) + 16769779119214020640U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 20U)) + 5257603646260695833U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 13U)) + 8523523946234886745U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 57U)) + 7316024684200084096U) + aNonceWordG;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 11996978575084115207U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 48U)) + RotL64(aCarry, 21U)) + 15491711479085513628U;
            aOrbiterF = (aWandererC + RotL64(aCross, 5U)) + 6036648530996821484U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 35U)) + 926323222234121863U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2700323841295743492U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5852273765810284935U;
            aOrbiterC = RotL64((aOrbiterC * 16665696735016345215U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11697397483133538067U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17777142964957007194U;
            aOrbiterA = RotL64((aOrbiterA * 6338967222543284999U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10892176201151170298U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11759700374509499684U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14247697264744736081U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11343756773329590643U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15785048929757652350U;
            aOrbiterG = RotL64((aOrbiterG * 17208103574389502597U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7508839228498497238U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 13088508510402094665U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 15730279447009669103U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16259236641717377699U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11228995722951003980U;
            aOrbiterF = RotL64((aOrbiterF * 4870092259515181323U), 51U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 13775851561528617086U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3023564646900497080U;
            aOrbiterD = RotL64((aOrbiterD * 9936548213275464131U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 154952467284609583U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14239675888632174461U;
            aOrbiterK = RotL64((aOrbiterK * 1370550680736926425U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 168749514558708557U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5070416708211422927U;
            aOrbiterH = RotL64((aOrbiterH * 13631900152346927703U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1961290602001581341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12235345489656113478U;
            aOrbiterE = RotL64((aOrbiterE * 14403534235273302211U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2295581049708176078U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12206125048349568300U;
            aOrbiterI = RotL64((aOrbiterI * 6008868846674396181U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 20U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterH, 35U));
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterH, 27U)) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterD, 37U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 24U)) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterH, 51U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterA, 47U)) + aOrbiterB) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 19U));
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterI, 43U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterI, 14U)) + aOrbiterG) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21267U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 20878U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17722U)) & S_BLOCK1], 26U) ^ RotL64(mSource[((aIndex + 21117U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCross, 3U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aPrevious, 29U)) + 12669015908335980355U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 3U)) + 5438715179868613192U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aScatter, 52U)) + RotL64(aCarry, 5U)) + 13172104448184536460U) + aNonceWordL;
            aOrbiterD = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 13421421503244744803U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 13327113302994856582U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 35U)) + 4671768205922454413U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 39U)) + 5355759962838579929U) + aNonceWordK;
            aOrbiterC = (aWandererJ + RotL64(aCross, 57U)) + 6691720614265406851U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 13U)) + 7063906424700911378U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 18U)) + 17328616394166672263U;
            aOrbiterI = (aWandererB + RotL64(aCross, 27U)) + 1542940602574207068U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7203866278803132454U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 993485696233139264U;
            aOrbiterH = RotL64((aOrbiterH * 11609009908810366447U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15659679028507488331U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 18321361454094675842U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 3966860765622641843U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9633319822696783352U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3496559332232402963U;
            aOrbiterB = RotL64((aOrbiterB * 7772060229838162977U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 1918349708324205526U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7701088402761359134U;
            aOrbiterE = RotL64((aOrbiterE * 9649485438465644795U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6006824348814439686U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 18088375375347012557U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12801082943086128385U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12816533373478543584U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17951880253818836433U;
            aOrbiterG = RotL64((aOrbiterG * 8935839101517220201U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11311632024372748238U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9891349164779752351U;
            aOrbiterA = RotL64((aOrbiterA * 11405973752233193209U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 711130292000437038U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17818800917771709681U;
            aOrbiterI = RotL64((aOrbiterI * 10567029732245868263U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10188714200240109442U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9745615081760948652U;
            aOrbiterF = RotL64((aOrbiterF * 9321909462220134035U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6508703788527163965U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7536038073603467381U;
            aOrbiterK = RotL64((aOrbiterK * 12015514242701199813U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2793951597846756844U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12669015908335980355U;
            aOrbiterD = RotL64((aOrbiterD * 7355285540199760689U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 4U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 11U)) + aOrbiterG) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 34U) + aOrbiterH) + RotL64(aOrbiterI, 20U)) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 58U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterE, 38U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23463U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 22567U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24849U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 26497U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 60U)) ^ (RotL64(aCross, 29U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererE + RotL64(aScatter, 60U)) + 10726035965553989335U) + aNonceWordE;
            aOrbiterA = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 967354339530195662U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 43U)) + 10834593005478605624U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 1012888282838656933U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 51U)) + 15283530351725183253U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 22U)) + RotL64(aCarry, 21U)) + 11724495956731703750U) + aNonceWordD;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 39U)) + 4288330117317505776U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 10894778070022873473U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 13U)) + 15563886747621617467U;
            aOrbiterF = (aWandererA + RotL64(aCross, 41U)) + 11182488628562891937U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 3U)) + 10420140066310588580U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11775138062167543111U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16545391898578161683U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 14588306527161321535U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1550144656312299266U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14903504853138279883U;
            aOrbiterB = RotL64((aOrbiterB * 8003033561266164387U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 309935535526750396U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13991265868040011411U;
            aOrbiterI = RotL64((aOrbiterI * 2887531132228588441U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1755976294857114222U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2259275858478396846U;
            aOrbiterF = RotL64((aOrbiterF * 7416165760067878161U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4838175912944552936U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12307900457200936013U;
            aOrbiterE = RotL64((aOrbiterE * 14719363144850838805U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18025411832912225805U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 981375022769564523U;
            aOrbiterC = RotL64((aOrbiterC * 15869361544011831483U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 3174014054982742562U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8119692378748963609U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 3072354179707448489U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14502863160788675807U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1207582534593709516U;
            aOrbiterK = RotL64((aOrbiterK * 3045412087535529357U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 5838011917777875072U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 434594114594643600U;
            aOrbiterJ = RotL64((aOrbiterJ * 1591023655239709931U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15711060039063734443U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8307150522686198490U;
            aOrbiterA = RotL64((aOrbiterA * 2082452039297764679U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5805686529930815226U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10726035965553989335U;
            aOrbiterG = RotL64((aOrbiterG * 5563221485243331689U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 44U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterC, 19U));
            aWandererH = aWandererH + ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterG, 13U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterJ, 34U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 46U) + RotL64(aOrbiterA, 41U)) + aOrbiterE) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 13U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterF, 28U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 47U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterA, 43U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29034U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 32612U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31135U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31268U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 40U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererB + RotL64(aCross, 29U)) + 17019646486641172469U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 57U)) + 12276141179299971572U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 26U)) + RotL64(aCarry, 57U)) + 3617241694029841555U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 13U)) + 6967963401259371737U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 6340709284279891017U) + aNonceWordO;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 456065368903896482U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 53U)) + 17686765719908116203U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 3U)) + 1322045955429785736U) + aNonceWordI;
            aOrbiterD = (aWandererF + RotL64(aScatter, 19U)) + 5163772703302372887U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 35U)) + 13268431135020363252U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 10U)) + 6538789950366849332U) + aOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10390344544314544893U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5087084271300584267U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 15149302947570776165U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13423071121590981727U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18324443012024134729U;
            aOrbiterJ = RotL64((aOrbiterJ * 15814349432207734533U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4129091815978464507U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 17024797553831962245U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3137753479364378175U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6501545108779991661U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11930037791867597447U;
            aOrbiterF = RotL64((aOrbiterF * 4904739567549702851U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4667298703308315851U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6315980380900062127U;
            aOrbiterA = RotL64((aOrbiterA * 12080555704907924637U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12732382340390769888U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7792095326183864547U;
            aOrbiterD = RotL64((aOrbiterD * 12645556660611824631U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17428384983571405782U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3193205313177048443U;
            aOrbiterB = RotL64((aOrbiterB * 14488006565106259731U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2813743367131107264U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2742138679703780981U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18356569025783532225U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6270291142961043031U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3490174937775044998U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13879285210885619613U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13182535825771438942U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13047228760732694484U;
            aOrbiterI = RotL64((aOrbiterI * 10365428317468779549U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 17926326514553542739U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17019646486641172469U;
            aOrbiterH = RotL64((aOrbiterH * 13978838314848228053U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 24U) + aOrbiterB) + RotL64(aOrbiterC, 57U)) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterK, 37U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 47U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 6U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterF, 51U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 53U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 27U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterC, 34U)) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordN;
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

void TwistExpander_BasketBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x891D297442DE7939ULL + 0xCBA02CFB460C4D06ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD47688FA2E531E93ULL + 0xE6B2899FFAEFDD1AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC8E32F016D507159ULL + 0xD3648FD72975723DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF163E216BA63DEA3ULL + 0xD2832E0F6E5E8DE5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD573076DA85FAD7FULL + 0xA87394672DBF62DBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEFB55003AEE6081BULL + 0xAB0AD8F2CE4D2324ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDD5F1A96D09799E1ULL + 0x8F224398233555D8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC83CDCAD71FA5F35ULL + 0xDCA3972F9CE359C0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD4D27F997530F141ULL + 0x8DA0F9B92AE0475BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB23F74E2136A2581ULL + 0xBA37276CB527D9A6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9003F57D96CCB687ULL + 0xBB32D00C2FE5EF45ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAF45FA832405D34DULL + 0xA69DD7A388CD0A8AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB888FCA149A9F977ULL + 0xE977245351B55478ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC612BAABA06D8923ULL + 0x92B574650F8771A4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEB11DECBEF03EA95ULL + 0x8FA6E349C66A1844ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE92590BD4F763FE1ULL + 0x855387F6163EBA8AULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2435U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4577U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6481U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 5834U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 15910560457440369082U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 22U)) + 17953072986407436888U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 15446940721193538669U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 57U)) + 3020785262774422009U) + aNonceWordO;
            aOrbiterA = (aWandererC + RotL64(aIngress, 3U)) + 7001288645424994404U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 53U)) + 13385250665458462689U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 10U)) + 4841895644623005949U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 13053476783239482065U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 35U)) + 641996979335975244U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16211238020928688299U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12715448751323279480U;
            aOrbiterJ = RotL64((aOrbiterJ * 2116880429675303291U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17784406727699995290U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16626339815786580778U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13940754474750138041U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9035070625716345139U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6085848172494001945U;
            aOrbiterC = RotL64((aOrbiterC * 10405728912339646693U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1177103851507561053U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2281901691017816407U;
            aOrbiterI = RotL64((aOrbiterI * 3142197009403602497U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9040984343694325070U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13334258224023902365U;
            aOrbiterK = RotL64((aOrbiterK * 4782523727707164869U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1079824790138592518U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14024082692012948652U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3219489374333737903U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2966776524421278970U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5510281854029308547U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9275402927591867297U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7126632329316720048U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1476827035602733472U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2217671289726794033U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6470212302133184965U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4172257438373147415U;
            aOrbiterA = RotL64((aOrbiterA * 4449314239630366533U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 30U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 30U) + aOrbiterH) + RotL64(aOrbiterE, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 30U)) + aNonceWordH);
            aWandererA = aWandererA + ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterD, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterB, 35U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 58U) + aOrbiterE) + RotL64(aOrbiterD, 4U));
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12810U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 8423U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14056U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12923U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 10U) + RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aIngress, 23U)) + 9630214189402543339U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 19U)) + 4072576573737526819U) + aNonceWordD;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 35U)) + 15994787452709618869U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 6403240137132259482U) + aNonceWordH;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 28U)) + RotL64(aCarry, 53U)) + 10229266900170507720U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 5025294577989748989U) + aNonceWordJ;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 3U)) + 16696461238217956883U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aCross, 47U)) + 9878318855341719119U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 14U)) + 16086635438116177346U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12295437783084203730U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 7681150419912842402U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7289497379725191451U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2639104034287637448U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12298170009332243573U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 9397919591171238575U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3485932317267669626U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16569551670038752475U;
            aOrbiterF = RotL64((aOrbiterF * 8139802826402217631U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4448490103784103954U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14510534073046885941U;
            aOrbiterE = RotL64((aOrbiterE * 7777192047386438305U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4286195398675733451U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15790355933840266463U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13342257823027075501U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6362891510370156055U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15121822034579983174U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7268045994574844937U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13817341015719915628U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14113474087906143783U;
            aOrbiterD = RotL64((aOrbiterD * 12838910141533126059U), 39U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 9988301252236121106U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11287477288382171758U;
            aOrbiterJ = RotL64((aOrbiterJ * 4979297247881426383U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9491727010910328644U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7961202721830514030U;
            aOrbiterK = RotL64((aOrbiterK * 16300364540313620767U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 52U));
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 22U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aNonceWordN) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterG, 51U));
            aWandererH = aWandererH + (((RotL64(aIngress, 56U) + aOrbiterB) + RotL64(aOrbiterG, 43U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 11U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterD, 5U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterD, 57U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 12U) + aOrbiterE) + RotL64(aOrbiterF, 34U)) + aNonceWordL);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20317U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22744U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22753U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18027U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 54U)) + (RotL64(aCross, 35U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 4622023259121087483U) + aNonceWordG;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 20U)) + RotL64(aCarry, 41U)) + 10253505250223501352U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 17133877904420462669U) + aNonceWordN;
            aOrbiterD = ((aWandererI + RotL64(aCross, 57U)) + 6162827793741796700U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aIngress, 51U)) + 9610986424765907615U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 35U)) + 11210747154264753754U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 39U)) + 16554205219580654546U;
            aOrbiterI = (aWandererD + RotL64(aCross, 46U)) + 10352576357413766388U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 29U)) + 3651845783283479752U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 18145542190463500476U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5415609566767162857U;
            aOrbiterG = RotL64((aOrbiterG * 6474184559323816389U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2033734872464201570U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3507213117125813345U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5453058336688881113U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8716253393049851856U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 695984869565941856U;
            aOrbiterD = RotL64((aOrbiterD * 8377921610764044735U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7661578828878284931U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 906654265099155956U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8117625377607536949U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6050049984731254612U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17882717590338190821U;
            aOrbiterK = RotL64((aOrbiterK * 10807367411402733215U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4996521991532815957U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4246460672800604436U;
            aOrbiterA = RotL64((aOrbiterA * 12047466401960824903U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8700148116452518842U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10039050281847466206U;
            aOrbiterH = RotL64((aOrbiterH * 11884791271239660157U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4513844680425845372U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3037563127442815153U;
            aOrbiterI = RotL64((aOrbiterI * 18363509277992292407U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 1005237931570968724U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1373258132025712065U;
            aOrbiterE = RotL64((aOrbiterE * 10458020799382532395U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterA, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterE, 40U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterD, 11U)) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterH, 53U));
            aWandererI = aWandererI + ((((RotL64(aCross, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aNonceWordD);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterK, 18U)) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 23U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27097U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31328U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27871U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 31552U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 4U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 42U)) + 5510690816044082200U) + aNonceWordB;
            aOrbiterK = (aWandererE + RotL64(aScatter, 23U)) + 15967820875033940530U;
            aOrbiterF = (aWandererH + RotL64(aCross, 57U)) + 539348720848176221U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 27U)) + 15779318183635560817U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 18U)) + 14511058534424187469U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 5811130556873428391U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 1085928476499444025U) + aNonceWordA;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 6973335316600768130U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 5U)) + 10747243745475009744U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 1072260008981349754U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2018772405352495753U;
            aOrbiterF = RotL64((aOrbiterF * 10840562112080574241U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1092091597048996547U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15103140149542167197U;
            aOrbiterA = RotL64((aOrbiterA * 621856991658027989U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13194619321108681542U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16749188603268621850U;
            aOrbiterC = RotL64((aOrbiterC * 9575408950550922039U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7427959503086895166U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9895804051379551393U;
            aOrbiterH = RotL64((aOrbiterH * 2701997336201570715U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4526020800679774259U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4484850928870048176U;
            aOrbiterG = RotL64((aOrbiterG * 17556987520625677313U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 1837404844299040155U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15213208978489570694U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7062740584650274133U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9615231781751396800U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15872192167825648096U;
            aOrbiterD = RotL64((aOrbiterD * 2900526493682580729U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12530672039655918903U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10617836782870315804U;
            aOrbiterB = RotL64((aOrbiterB * 9716778004909794973U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 550750725406860977U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3498554352021622907U;
            aOrbiterK = RotL64((aOrbiterK * 9846933294851238495U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 14U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 6U) + aOrbiterB) + RotL64(aOrbiterA, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterK, 14U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 3U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 43U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 27U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterA, 47U));
            aWandererA = aWandererA + ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 10U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aCross, 56U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterC, 21U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordK);
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

void TwistExpander_BasketBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9979AD0A4C17A457ULL + 0xC74C9D6614A4B010ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBB1920661628B7CDULL + 0xC7A19EEBAED5942AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB6DE85E5C2979813ULL + 0xC354145E91EB113EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF23B4F45F3F91129ULL + 0xBA4BD6E11D14056DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC81DCF10FBADA18DULL + 0x88A081C338F742ECULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF33A62000A85FC87ULL + 0xBB0362FEB89E9977ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF92A1AE3C8DD69FFULL + 0xD053DE2A94F3D5E7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD898265952490105ULL + 0xA7292F0E8F344DA5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x96E5835164820A31ULL + 0xB0C9CFE4AB407E0AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x80B1ECAC77ECDAD1ULL + 0xD959E0DC90718116ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x99FB70226E1CD1FDULL + 0xF469C6F0459E9579ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x94A42BD2346A4A17ULL + 0xD5DA3448043897E8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD3BAFDD6D436E7D7ULL + 0xB848A00C28AE424DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC1E944E26FDC0795ULL + 0xD0983D203CF25939ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE186A185C7B58A47ULL + 0x983394F8C2DD7CE4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9934D706E646D6BDULL + 0xDCB972930A3C2688ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2340U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 7699U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3503U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1424U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 51U) + RotL64(aPrevious, 26U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererI + RotL64(aCross, 37U)) + 11039986441331892533U) + aOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 6U)) + RotL64(aCarry, 35U)) + 6256024955965426119U) + aNonceWordH;
            aOrbiterA = (aWandererE + RotL64(aScatter, 47U)) + 9857443189988995666U;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 11900944813380998208U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 8422577734978875541U) + aNonceWordJ;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 3100835100713928724U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11871553509810206993U;
            aOrbiterA = RotL64((aOrbiterA * 15501681886909921677U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17614749493763417027U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3638372131856199916U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 480683274898147025U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6582275259281025770U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17016882418498941958U;
            aOrbiterK = RotL64((aOrbiterK * 4269869255230867823U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 1747214688658984715U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9356088987044015278U;
            aOrbiterC = RotL64((aOrbiterC * 16221733545319753695U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4056238112133473456U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16013150119949532998U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 12913648646318115315U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 53U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 57U)) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 42U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 54U) + aOrbiterD) + RotL64(aOrbiterK, 21U)) + aNonceWordC);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 29U)) + aNonceWordB) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15605U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 8375U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11727U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 12199U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 48U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererA + RotL64(aCross, 5U)) + 6163290588946759209U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 47U)) + 7342672468560105447U) + aNonceWordO;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 11574563167017282321U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 2254820206194758964U;
            aOrbiterC = ((((aWandererH + RotL64(aCross, 28U)) + RotL64(aCarry, 47U)) + 1469783447473099498U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14174828900676165088U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16277954291890598132U;
            aOrbiterB = RotL64((aOrbiterB * 4608888834164373691U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14845750668693136766U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 150099699692047766U;
            aOrbiterC = RotL64((aOrbiterC * 7644895634421086357U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1200784917165131703U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 9469982764806754302U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17851969334511301943U), 37U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 10956702761701710182U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 7915506894975487807U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8874108311712727983U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17335794183733623213U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 557028996286989506U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3993359298602424281U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 30U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 29U)) + aNonceWordG) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterB, 19U)) + aNonceWordE) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterG, 60U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23446U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22227U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18348U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24122U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 19U)) ^ (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aCross, 11U)) + 2783898056762489197U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 43U)) + 7177192902873343053U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 52U)) + RotL64(aCarry, 47U)) + 12254703232691980774U) + aNonceWordP;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 15446547245691219559U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 888475203006174856U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3649183529366307877U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 4642631047518805167U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 14791564497487717167U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6108329730724782250U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8334054653023816636U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 9352516059501924393U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5891895375031474350U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 3176720746238477862U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 1869961473768307911U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6111038696865301675U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11914998302228682704U;
            aOrbiterB = RotL64((aOrbiterB * 11738924766359642853U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17005063057791320948U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 18333780598768130670U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5416759844884107303U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 58U);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterI, 47U)) + aNonceWordO);
            aWandererA = aWandererA + ((((RotL64(aCross, 22U) + RotL64(aOrbiterF, 14U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 23U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aNonceWordM) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 12U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29716U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27060U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31429U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((aIndex + 28206U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 51U)) + (RotL64(aCarry, 18U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 8793908991006073956U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 36U)) + RotL64(aCarry, 53U)) + 2932916283348441943U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 13U)) + 11069042087940968262U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 14369628676782894441U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 53U)) + 8602903272780978282U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3827036107178568820U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8905245209036772489U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5744017326197157667U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13331387530760017893U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9880107580289737823U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10302652857542703753U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10199619040626900278U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2466307560891374281U;
            aOrbiterE = RotL64((aOrbiterE * 6295342978834217571U), 57U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 13973403407981259448U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 2851460278409385243U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11226902976321781743U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10365453393815690776U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2382382358987358791U;
            aOrbiterJ = RotL64((aOrbiterJ * 481563628980705781U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + aNonceWordO);
            aWandererK = aWandererK + ((((RotL64(aCross, 51U) + RotL64(aOrbiterH, 60U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterD, 23U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 43U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordL);
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

void TwistExpander_BasketBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA259B2AF71C18771ULL + 0xC7FC9FE599EACF6DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA0992DE9DE6C95A9ULL + 0xA3FB128947C63008ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD38ABCC2214DC88DULL + 0xE268BEEC831A4BA0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFA543216D6EF4E3BULL + 0xF241728AEDD7BFC2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x896BC7E69FB6560FULL + 0xA0BCD15F509DEE91ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC921165C45000D2DULL + 0xCEDC63F9E5C25938ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDCA6CBF8F0344F15ULL + 0xC4A29B8642520C99ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD1B70ECA89EA4397ULL + 0x937CA0782553BCF9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFAEEBD53E723117DULL + 0xA0FD5969862CE1D6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8BE10E7B58D79F6BULL + 0xF8003CF00EA85ABAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF11AD45C42B2FC69ULL + 0xF6E5F537AFE6B49AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x86FBC56F963316F1ULL + 0x82733400623CAC5DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAFE8F82A8D32435DULL + 0xA51684107828921CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9125FF084DBC5983ULL + 0xE017E640899826F5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB935C47ABF2E463FULL + 0xF37AC93FD561DE75ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDCF7ABF8A2808585ULL + 0xED2F2B850C90936DULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2634U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 5932U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2538U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4594U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 36U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 18302975933754610273U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 20U)) + 16736972646771456082U) + aNonceWordH;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 3U)) + 17389406266488137442U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 5252511566486165539U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 5730715427422747640U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aCross, 29U)) + 6412695646456045825U) + aNonceWordD;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 51U)) + 9539701605708994494U) + aNonceWordB;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18355107116412945722U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11735742491750132942U;
            aOrbiterK = RotL64((aOrbiterK * 18129835093627763685U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12363819388562658842U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5861430292304371543U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12989055611235382695U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 15027487084595017708U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 7012850020745791926U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 15952928839355613939U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11904871669287886120U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11199760114477343208U;
            aOrbiterH = RotL64((aOrbiterH * 7156374911847525867U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3856004502263742700U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3705931243173921893U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 10334871178498711485U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12305785390539209389U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 18057980996551978823U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4850564181113470859U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3229431819292153014U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2994716629242460094U;
            aOrbiterE = RotL64((aOrbiterE * 1029427328395257917U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 6U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 19U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 41U)) + aOrbiterD) + aNonceWordE) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 36U) + aOrbiterI) + RotL64(aOrbiterH, 6U));
            aWandererK = aWandererK + (((((RotL64(aCross, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordM) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8466U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 12976U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14750U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((aIndex + 11402U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 14U)) + RotL64(aCarry, 51U)) + 7948891781097675369U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 3U)) + 13928362874228230226U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 47U)) + 10776180542602258926U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 27U)) + 5735115172149470447U) + aNonceWordP;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 21U)) + 5353591822981766987U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 562301708107268570U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 10467810247578364868U) + aNonceWordN;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14541630141152308564U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2350076897065139429U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12222554362482034393U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17519109078651162228U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6061035173339902910U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10021905773432907835U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15654836633731000065U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13723521735153718904U;
            aOrbiterA = RotL64((aOrbiterA * 14459516479283070563U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2849680038315532197U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17336102435576647923U;
            aOrbiterG = RotL64((aOrbiterG * 10984689101753586739U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7671010488872356142U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11485114338165600777U;
            aOrbiterJ = RotL64((aOrbiterJ * 4162584865462407791U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 8759060657343458985U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11009137869375286581U;
            aOrbiterI = RotL64((aOrbiterI * 8741417343929809115U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 15792999392743144135U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6180808423175992479U;
            aOrbiterD = RotL64((aOrbiterD * 13681230339693676907U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 58U) + aOrbiterD) + RotL64(aOrbiterJ, 60U)) + aNonceWordI) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordH);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24241U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 18277U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17369U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((aIndex + 22939U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 37U)) ^ (RotL64(aCross, 24U) ^ RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererG + RotL64(aScatter, 53U)) + 9774364261626083532U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 18059001521926116420U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 10615626210406381148U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 10536484278007898620U) + aNonceWordB;
            aOrbiterD = (aWandererB + RotL64(aScatter, 44U)) + 13320663045139972700U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 35U)) + 17127001787268166583U;
            aOrbiterC = (aWandererF + RotL64(aCross, 13U)) + 16742574590844166551U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 8347719720758228053U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 13502468705946051986U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13822952083584784695U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3512687886188904904U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 495660316165795934U;
            aOrbiterH = RotL64((aOrbiterH * 6724596801190194913U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5092722552034477356U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15641128019608284015U;
            aOrbiterK = RotL64((aOrbiterK * 3621036395703527059U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15421873776811085458U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17978775513204574125U;
            aOrbiterJ = RotL64((aOrbiterJ * 18359600395119440183U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16617179197537669849U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1931805387534012528U;
            aOrbiterD = RotL64((aOrbiterD * 3400139345857733775U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9544923119559308431U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12930999400470173353U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16791006919271490005U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13673733276226249890U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 2032263473309124738U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3088728329261360607U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 29U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 11U)) + aOrbiterK) + aNonceWordF) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25153U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 26953U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24684U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 28022U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 41U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 26U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 57U)) + 14157904117287696136U) + aNonceWordO;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 7369512677371640676U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 30U)) + 8411250745902073798U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 37U)) + 5002041814539710275U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 23U)) + 9538041410816283124U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 5210700103927513061U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 7600709399101287982U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2366369466696580499U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5544575244203019109U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16231219246786333057U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 8710073749110329779U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15998211310115361630U;
            aOrbiterE = RotL64((aOrbiterE * 15275657696897688955U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15354357553877376422U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10657523549259276169U;
            aOrbiterJ = RotL64((aOrbiterJ * 13695239532898311073U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 10405750198355464768U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3465819693133515142U;
            aOrbiterG = RotL64((aOrbiterG * 14678343718277562799U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16724189641701408630U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3484340153620198872U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17247547677520703125U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7420442404884871126U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11138445997256757636U;
            aOrbiterB = RotL64((aOrbiterB * 11167543379937571127U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 1428191560884663125U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16950093140800653985U;
            aOrbiterD = RotL64((aOrbiterD * 4423012306984814805U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 40U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 12U) + aOrbiterJ) + RotL64(aOrbiterD, 21U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterE, 41U)) + aNonceWordF);
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 47U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 34U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordK);
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

void TwistExpander_BasketBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE50DD498299333B9ULL + 0xE34B4E1BBD4F3377ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB9662A8F2BD2B045ULL + 0xDB1B5D1C36020BA7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFF723508C16787AFULL + 0xFC0902CB5CB7C41DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x81739CE4C15AA49FULL + 0x8BB5FC1ECB8D79FBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE14DB4FADBA94D93ULL + 0x84A09DE047FFBB19ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB440A83660347837ULL + 0x97F1ABC884006C67ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA218365572917AF1ULL + 0xF561DEC457FCEEEDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFB0F97C080296D85ULL + 0x83B29BB596C94228ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE934B7E7D24790B1ULL + 0xFD10B45521599F37ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x83A616C13984C707ULL + 0xEAC284CE55192B7EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAD1843A1E5C4DB95ULL + 0xB6663124EF970F56ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x967E45AA1EE0DD31ULL + 0xF181273D680A9B0FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFDC6094640CA997DULL + 0xD195F5F22A6C3DCAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x98536CBA83459ED3ULL + 0xC6FF2FEC7660870EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBEC013DEBD696843ULL + 0xE0C9F2DFF34A868DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE23AD2D4B1F67697ULL + 0xBD973971C6A6BF5CULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 777U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1684U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 604U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((aIndex + 7843U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 29U) + RotL64(aCarry, 10U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aIngress, 50U)) + 16183871922837164759U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 13U)) + 7002058258090219055U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 5650868611888303705U;
            aOrbiterI = ((((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 11899839660943876690U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 15349649504488111111U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 29U)) + 14060149569086744970U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 57U)) + 12920917574225030112U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2831994965175330135U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18312543585028439192U;
            aOrbiterC = RotL64((aOrbiterC * 11618182708195744321U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11657562205118394239U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10850792819281246052U;
            aOrbiterF = RotL64((aOrbiterF * 10663100544207879337U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17810371216216125323U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7963413941144223128U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 534217972450595401U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5498715358793875584U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9256727548911651373U;
            aOrbiterK = RotL64((aOrbiterK * 10498848323914000989U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17246360111302191699U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 18309978718113983369U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18267472694666221077U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 3100998994319502921U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8129301860291235970U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17847033539279176187U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1889641029473279114U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16538494307002917945U;
            aOrbiterG = RotL64((aOrbiterG * 8081488217920885783U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterH, 13U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 43U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterE, 29U));
            aWandererC = aWandererC + (((((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 27U)) + aNonceWordO) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterG, 58U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12560U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15549U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10530U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16046U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 10U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 15726877954695761686U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 3U)) + 14187652171881943587U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 8420423151313882782U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 51U)) + 14942322692433259283U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 11U)) + 7272331475919796255U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 154504365041805840U) + aNonceWordC;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 35U)) + 17475491222554948786U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5759181483165339605U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5993060214499322845U;
            aOrbiterK = RotL64((aOrbiterK * 10799489831896153301U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10901786237875941844U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17135786595614068473U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15923538730142047043U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5208202073886811165U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6821452921018900631U;
            aOrbiterJ = RotL64((aOrbiterJ * 13119330055184115669U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13348064837402206969U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8967943922403445136U;
            aOrbiterF = RotL64((aOrbiterF * 300168481725373093U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8130283784171430891U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6351113882502502876U;
            aOrbiterE = RotL64((aOrbiterE * 15960622823993072903U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6894708729226455769U) + aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 12065058511247133944U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 5432601727436935831U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17138279326229372741U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12987698199066890628U;
            aOrbiterH = RotL64((aOrbiterH * 12665716655177320977U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aCross, 12U) + aOrbiterJ) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 29U)) + aNonceWordP) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 21U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 37U)) + aOrbiterK) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterH, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19295U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17088U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17122U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((aIndex + 21555U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 48U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 6973892330986118220U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 9886813896272094864U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 10996306582517553173U) + aNonceWordK;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 43U)) + 8490648283899856223U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 37U)) + 105141713530704655U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 18U)) + 3114337422810562588U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 51U)) + 980857684690886131U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6562042345807072665U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15665371138706353619U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 8086237578564620623U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18113013571374375028U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17405346422601997299U;
            aOrbiterB = RotL64((aOrbiterB * 11162604605443005253U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5130876096426182506U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1813821672299154629U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15478100342425611875U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 15793814882743306728U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13925299440495476399U;
            aOrbiterE = RotL64((aOrbiterE * 12049601510660117401U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9924458846049579438U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7810034662781768090U;
            aOrbiterG = RotL64((aOrbiterG * 10310594595026622513U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12812586478656872854U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 5709576448057435237U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9101555233909853025U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 7839807649914541516U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4717944526755429647U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 8515229146471335721U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 48U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 27U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 34U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + aNonceWordO);
            aWandererH = aWandererH + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 57U)) + aOrbiterG) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 51U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterK, 41U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27518U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((aIndex + 30928U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28306U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 28936U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 36U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aCross, 26U)) + 3255291173184001106U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 51U)) + 15308468160116255528U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 18186972408589866656U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 4439324265978331914U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 13099263173016322486U;
            aOrbiterK = (aWandererK + RotL64(aCross, 35U)) + 7041561081767500660U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 57U)) + 6196422612687812971U) + aNonceWordG;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7664260932541281413U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17802347823020441056U;
            aOrbiterI = RotL64((aOrbiterI * 2220679459017369255U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4253107484061190446U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13799496534030645312U;
            aOrbiterK = RotL64((aOrbiterK * 9167675060053848207U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 14252892847595951926U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5663527578664291422U;
            aOrbiterA = RotL64((aOrbiterA * 18314294235895182465U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11148755959699137661U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17036900929333594592U;
            aOrbiterC = RotL64((aOrbiterC * 16041243617369003291U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2403828181385259549U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 17813580350434928194U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 13666780980793857831U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5623611126885414523U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7293224381174846969U;
            aOrbiterB = RotL64((aOrbiterB * 7032561584670788117U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10602620906929686163U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 18015916257203385982U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 10684090189688871993U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 47U)) + aOrbiterG) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 26U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterI, 41U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 53U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 13U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 52U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_BasketBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA6C5D8679B4E3303ULL + 0x9CEF4D5CBB967F64ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x924A38F9DC96362BULL + 0xEE770E95F5365453ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB1B92C5D41931D8DULL + 0xE2D6D414A1C5641CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9C01D26FBABBD17DULL + 0xD8FE9C016343AC75ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE4C1FE02EAF6E373ULL + 0xA29B12BC755B7EAAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD01454B0766134DBULL + 0xA7C0D1B4F3ECECB1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB29BB8AA4657AA6DULL + 0x984B4C1A16C37442ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF1CE6D519795D203ULL + 0xC385C72A31711677ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x82691379197F8233ULL + 0x8738AF09D761C382ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE2AE1167962CC8D7ULL + 0xC4AF70FA297142C9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9E1BB2166F603C0FULL + 0xED42AF436EB0243AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF1C83F2AA458A82FULL + 0xD020C3B5990E88FAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDC8AB4556ECD2825ULL + 0xD210B61E1C60DA8CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB952039D49798AD9ULL + 0x843681A1671A77E9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x90049ECF4967E3E9ULL + 0xFA970CA5028ED16DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE9E96E1E589DE81FULL + 0xE4E50D48B8C3528EULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 446U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((aIndex + 698U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2672U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5573U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 36U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 12380376990224645149U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 13U)) + 18296928500297384014U;
            aOrbiterA = (aWandererB + RotL64(aCross, 47U)) + 3550626816361145100U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 22U)) + RotL64(aCarry, 29U)) + 2667792936946706027U;
            aOrbiterD = (aWandererH + RotL64(aCross, 3U)) + 12020969779370926953U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 737340727886903447U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 41U)) + 1681797651799760502U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 5U)) + 2956186342689489064U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 10U)) + 1876852870402977177U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aPrevious, 57U)) + 6433205819353555071U;
            aOrbiterK = (aWandererE + RotL64(aCross, 19U)) + 9065076854974222998U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3254410578766789992U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2005081975473815576U;
            aOrbiterA = RotL64((aOrbiterA * 9947701153722014085U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15992999234834560419U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3458344156815120948U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1668460113964608051U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17069783053664877727U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1260234710193913099U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4561226779897414381U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3825186451876061335U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2905344294992827535U;
            aOrbiterF = RotL64((aOrbiterF * 2469896090698580795U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 18141402347899180617U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8760129857609925066U;
            aOrbiterH = RotL64((aOrbiterH * 2507999156108123047U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 594052473780678210U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13216719212966128379U;
            aOrbiterC = RotL64((aOrbiterC * 10691355329696722303U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10029948739466316169U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11912428807431992996U;
            aOrbiterK = RotL64((aOrbiterK * 85016510811938307U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8735634019801417287U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 12785916159063273545U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1161917531260663357U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 367752057919802452U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3961036242431041564U;
            aOrbiterD = RotL64((aOrbiterD * 16352646009782597315U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3858415336170090719U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14325258358254321551U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 12080431158781060059U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16872184337970977180U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12380376990224645149U;
            aOrbiterE = RotL64((aOrbiterE * 16559121155413059221U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 46U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterC, 57U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterI, 39U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterA, 53U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 6U)) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aScatter, 20U) + RotL64(aOrbiterA, 37U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 27U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 47U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterD, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 14U) + aOrbiterK) + RotL64(aOrbiterC, 10U)) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10840U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8566U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9101U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 14117U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 24U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 39U)) + 826930775230515406U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 28U)) + 5137814617363250861U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 5U)) + 14761561947426681616U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 57U)) + 12773023438753662590U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 37U)) + 7331345852207096322U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 20U)) + RotL64(aCarry, 3U)) + 3899381212671247460U) + aNonceWordC;
            aOrbiterD = (aWandererB + RotL64(aCross, 23U)) + 10072004147620068599U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 3424585039401897560U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 8246760141625966321U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 11U)) + 3655992860610853290U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aCross, 41U)) + 11154618022505863898U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15629361991059709973U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10842068502278489664U;
            aOrbiterE = RotL64((aOrbiterE * 17223002513104960799U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5571312349016336686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 589313823745748879U;
            aOrbiterK = RotL64((aOrbiterK * 1356685926549786027U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13633457935771935260U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12684602052812183096U;
            aOrbiterG = RotL64((aOrbiterG * 4689206269919806711U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5711307583717354204U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7181854170553728211U;
            aOrbiterD = RotL64((aOrbiterD * 9835601115561325911U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 1884620014396115821U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1471516373272364262U;
            aOrbiterB = RotL64((aOrbiterB * 5126319375714848029U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 742739371092077733U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8075893317715227838U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11208274111743259795U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8179547722249281263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15305282712174742323U;
            aOrbiterH = RotL64((aOrbiterH * 7951986906055462929U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1430543231751281079U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14585341768267283387U;
            aOrbiterA = RotL64((aOrbiterA * 313213844964269133U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8123889986027932297U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2081696191347150910U;
            aOrbiterF = RotL64((aOrbiterF * 4869653441012615053U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10166788886199265936U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15927074835525735601U;
            aOrbiterC = RotL64((aOrbiterC * 6747650218540675523U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6997764816848988590U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 826930775230515406U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9943232461538279601U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 52U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 22U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 56U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterD, 35U));
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterC, 11U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterA, 19U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterK, 41U)) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterG, 43U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 22U) + aOrbiterB) + RotL64(aOrbiterE, 21U));
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 27U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 53U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 58U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18226U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23357U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21298U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19449U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 22U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 3973833383430652211U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 21U)) + 5760227042747169187U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 24U)) + RotL64(aCarry, 21U)) + 4923009065139227286U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 1477807307009107590U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 11U)) + 5707194514329007301U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 47U)) + 5340439728375269724U;
            aOrbiterH = (aWandererC + RotL64(aCross, 43U)) + 17080457898946572387U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 53U)) + 281559150259472813U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 57U)) + 16160633048230910560U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 26U)) + 9003989610509592121U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 29U)) + 10579322462808454333U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 15059383289528723069U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10417647757852880956U;
            aOrbiterK = RotL64((aOrbiterK * 1457919230286043137U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14484665027393813330U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12344463053485837974U;
            aOrbiterC = RotL64((aOrbiterC * 5762654194001525041U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5826453246659297805U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12547902286376986223U;
            aOrbiterD = RotL64((aOrbiterD * 2982850000322672789U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9637855144278126174U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2132744427444501938U;
            aOrbiterG = RotL64((aOrbiterG * 5911587798564836199U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9248933938130311231U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13274297928717090383U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2901398809555237563U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3690262236918560930U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3626005326410800344U;
            aOrbiterF = RotL64((aOrbiterF * 13030443356669355355U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10801089744186148218U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5446653082176311031U;
            aOrbiterB = RotL64((aOrbiterB * 4594267575901248321U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3205541585889107366U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4532327942368884436U;
            aOrbiterE = RotL64((aOrbiterE * 16287094987689326229U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9755333481079721632U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 722154154363571049U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11002432494248958957U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8071668483354405205U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8770466248803121315U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 12780438190628717807U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1999251593502332271U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3973833383430652211U;
            aOrbiterI = RotL64((aOrbiterI * 5325244982474631559U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 12U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterC, 5U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 54U) + aOrbiterD) + RotL64(aOrbiterB, 44U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 27U)) + aOrbiterG) + aNonceWordL);
            aWandererA = aWandererA + ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 13U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterA, 11U));
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 42U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterG, 19U)) + aNonceWordD);
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 36U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30387U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26496U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27237U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 26819U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aIngress, 23U)) + 9133751643283278896U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 47U)) + 8971581804375380408U) + aNonceWordH;
            aOrbiterK = (aWandererG + RotL64(aScatter, 35U)) + 12559650383714566592U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 53U)) + 15753206088872859163U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 60U)) + 7640756270450762350U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 27U)) + 7340073357551376125U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aCross, 29U)) + 5270256573644196046U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 57U)) + 3567367996479995928U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 12U)) + RotL64(aCarry, 57U)) + 11939634537492733738U;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 7051817732424527120U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 1730487669951837941U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18009252467909454817U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2361024272031696442U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 15215151562500226027U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15902755877642960397U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12243517544704116184U;
            aOrbiterF = RotL64((aOrbiterF * 2576071074148141447U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16846181962302186187U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 636121425116506681U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17075030673338779993U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6887385655828217318U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3705834550934775862U;
            aOrbiterB = RotL64((aOrbiterB * 11275428284929594435U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11165142437077969438U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 6426659930331618269U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 17170640810530893705U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 12629082390899315789U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4277510580069574724U;
            aOrbiterH = RotL64((aOrbiterH * 9829125163412708305U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13814834144170469978U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3698381854100295826U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5126359230872258015U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11623170635983579937U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7247413650388803796U;
            aOrbiterI = RotL64((aOrbiterI * 3403219499465560059U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3129755194359521145U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4081016725582134919U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11564414998539605389U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15878346077922215753U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2974440187796944059U;
            aOrbiterE = RotL64((aOrbiterE * 783253926537018373U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3922344163443096356U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9133751643283278896U;
            aOrbiterA = RotL64((aOrbiterA * 16887991698415418429U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 40U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterI, 60U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterA, 5U));
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 39U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 58U) + RotL64(aOrbiterH, 34U)) + aOrbiterF) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 29U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterF, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterG, 21U));
            aWandererC = aWandererC + (((RotL64(aCross, 60U) + RotL64(aOrbiterK, 23U)) + aOrbiterB) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordP);
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

void TwistExpander_BasketBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA1850CD88958D2F7ULL + 0x8C694F38FE8C3EF8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBD9D0C65F564DA7FULL + 0xCBA05408DED49CD8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAB20510FC6DC9703ULL + 0xD1977FB30E44D3C0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9A942B8459276A6FULL + 0xF8D7A27DA78C04FBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF85BB9A91DE41C1BULL + 0xC963FD74202B6DA6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE636FD1272EE425DULL + 0xDBCFB116A024B008ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCF1ED8627E9D9C91ULL + 0xB2CA1ABAA76FE630ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD247788E23FE747FULL + 0xB64F07D5EC48FB62ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC5FE7FAAFC81487FULL + 0xA3C04CD36BE8A768ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x914F2CB75AA6D353ULL + 0xE00A4BDD9118CB6DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF065EABA92EE9131ULL + 0xD8719C17DB4ED5E4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFED79BFEE6873DF3ULL + 0x9D3AF8DAE75F624DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD0EF470FA409B6C9ULL + 0xE1E10C70AABA42CBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDD168610377BE1B9ULL + 0xE0A572D59CBA575CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEAE25DAFE1B754C9ULL + 0x9F340E7B79C933FFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x829EAD043DA191E7ULL + 0xF1FE8B58CD7E7E33ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 37U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4536U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 722U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 3060U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 40U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererE + RotL64(aCross, 52U)) + RotL64(aCarry, 41U)) + 3917730204724097072U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 43U)) + 1874642340716212824U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 6900165757434854160U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 5U)) + 12750946097023807161U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 34U)) + 6563216048479513594U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 23U)) + 14960240191349450795U;
            aOrbiterK = ((((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 16306180275951788289U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererC + RotL64(aCross, 19U)) + 6502066618271045547U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aScatter, 47U)) + 6219852857850888738U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2272931312452845850U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3028929882263199463U;
            aOrbiterC = RotL64((aOrbiterC * 11005324285856805069U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6067393030073568112U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10094809900437037258U;
            aOrbiterI = RotL64((aOrbiterI * 18095564940730322769U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5962414178157074575U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15755563045799129417U;
            aOrbiterE = RotL64((aOrbiterE * 3692603590609922031U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6321455513889880590U) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1197435601998121700U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 17693996266260557625U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 12496949381666299968U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6357070235648527030U;
            aOrbiterF = RotL64((aOrbiterF * 2931486644220862433U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8423760160877540210U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8090246492554850768U;
            aOrbiterA = RotL64((aOrbiterA * 2949407491181921633U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11436635942985063755U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17086363141014359856U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10504127577318206801U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10734017887545474935U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 375515325165740779U;
            aOrbiterG = RotL64((aOrbiterG * 9980486695448151709U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5217148491945389821U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14696058217023530058U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11026674782236654799U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 52U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterI, 39U));
            aWandererH = aWandererH + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterH, 10U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 47U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterH, 23U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterI, 27U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 34U) + aOrbiterI) + RotL64(aOrbiterK, 51U)) + aNonceWordC) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterI, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6219U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 10028U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10298U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 9431U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 24U)) + RotL64(aCarry, 29U)) + 3561491146322798260U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 47U)) + 7075025056181885339U;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 9230910887904171613U) + aNonceWordM;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 4119781172609908917U) + aNonceWordN;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 41U)) + 17155609083870983149U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 51U)) + 2423018561430181695U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 30U)) + 12957280305617615744U;
            aOrbiterG = (((aWandererK + RotL64(aCross, 19U)) + 2461704174772065813U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aWandererD + RotL64(aIngress, 57U)) + 7907123257849391997U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7257868138318960007U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16425903703085702285U;
            aOrbiterJ = RotL64((aOrbiterJ * 7996935869077231999U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2990822664594079467U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5654819006718953817U;
            aOrbiterE = RotL64((aOrbiterE * 4465096036756887801U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12183676471235678779U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 15026286960542123922U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17199049329995315279U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12169080607071830522U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2906296852254787499U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6754514406846040163U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3029858695410344584U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14406410317495954566U;
            aOrbiterA = RotL64((aOrbiterA * 9663780721657983421U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11048818178401163861U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 13622063920319445043U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2516025554421589857U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2642646089141233277U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12761571777929273548U;
            aOrbiterB = RotL64((aOrbiterB * 5518252696078700127U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 7753802695131502382U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8510425459525030222U;
            aOrbiterC = RotL64((aOrbiterC * 12412361423636026483U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13522645164493316722U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1437430302489702713U;
            aOrbiterH = RotL64((aOrbiterH * 14019316635365783545U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 18U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterC, 23U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterH, 34U)) + aNonceWordH);
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterI, 43U));
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 14U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 5U)) + aOrbiterE) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererA, 54U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12996U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 11736U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13993U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 15585U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 18U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 30U)) + 898812731947995389U) + aOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 51U)) + 8677347622525527167U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 29U)) + 770321564027567654U;
            aOrbiterJ = ((((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 11020474858081526395U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 13U)) + 17289793580414993470U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 10111912559295118444U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 19U)) + 8083622125544542011U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 5U)) + 7149858558922988240U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 58U)) + 5919683821379905699U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6860902846079238714U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15083517836867542075U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4686657139237578325U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14852868368708376381U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9860233289028878323U;
            aOrbiterH = RotL64((aOrbiterH * 13418143547952204667U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 772406119079116272U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7971141501337627589U;
            aOrbiterJ = RotL64((aOrbiterJ * 10168120622976358617U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8478568022896691911U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 4027604850785607101U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4826627523578901467U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17199331557841535430U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 7515957656979776361U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5468950152869656599U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17138249294921502391U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16236812863923234668U;
            aOrbiterK = RotL64((aOrbiterK * 2925542836624164807U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 16941524155859123682U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11240343728857342866U;
            aOrbiterC = RotL64((aOrbiterC * 7281012444214294659U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15163914964139858328U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6673576554415729652U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 1558880328574736975U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5399050402101642989U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11806006719060024615U;
            aOrbiterE = RotL64((aOrbiterE * 15782156615926092159U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 58U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterA, 41U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 53U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterI, 14U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterK, 23U));
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 3U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 28U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 4U) + aOrbiterD) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 56U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20828U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21199U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21670U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((aIndex + 17746U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 3U) + RotL64(aIngress, 22U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aScatter, 34U)) + 5568146815535263910U) + aNonceWordI;
            aOrbiterA = (aWandererG + RotL64(aIngress, 3U)) + 7736084960873834666U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 1336413621817562093U) + aNonceWordE;
            aOrbiterE = (aWandererF + RotL64(aCross, 27U)) + 5218462026934984692U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 13U)) + 7048890985969555935U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 13415955213864702118U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 58U)) + RotL64(aCarry, 21U)) + 5657023257021528548U;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 43U)) + 14338310943137497116U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aWandererI + RotL64(aIngress, 39U)) + 12305161641833950473U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14514226578370459131U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12692904083266024340U;
            aOrbiterI = RotL64((aOrbiterI * 14800805065279908839U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11012959130001327964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7106471380403489078U;
            aOrbiterK = RotL64((aOrbiterK * 515626559384817223U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3718101961355280891U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13364192077222322664U;
            aOrbiterG = RotL64((aOrbiterG * 1411328915372590283U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6720867800318913440U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 14497243926965866546U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 13595058589060114653U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5789056168233262435U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14438482587495779937U;
            aOrbiterE = RotL64((aOrbiterE * 10593535547917767263U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 313917798940179945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15241845511889502917U;
            aOrbiterJ = RotL64((aOrbiterJ * 16483477103771326107U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3591957424821693032U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1559050939014453558U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17933346117866604725U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15340590914441451383U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5538037287390050110U;
            aOrbiterC = RotL64((aOrbiterC * 4082576643144951473U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4151270491894969214U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 263593701314144898U;
            aOrbiterA = RotL64((aOrbiterA * 10372046955804512457U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterK, 36U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 51U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 57U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 50U) + aOrbiterK) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 12U)) + aNonceWordD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterE, 41U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25101U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25410U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25768U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23266U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCross, 43U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererH + RotL64(aPrevious, 51U)) + 2571116506511057880U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 57U)) + 13112435411509707292U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 39U)) + 10403251762787357256U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 8461951095541400405U) + aNonceWordF;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 30U)) + 9890793478557463815U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 47U)) + 3030229465991783707U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 13U)) + 7273848154043719247U) + aNonceWordP;
            aOrbiterH = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 10681774862516028276U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aIngress, 22U)) + RotL64(aCarry, 19U)) + 7105082755586853104U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 6588579345319551129U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14616333550242386092U;
            aOrbiterA = RotL64((aOrbiterA * 2934574715879306337U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15439666290229654921U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3360304356760164799U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5164191920584106237U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14438730801970761889U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14515616787452085729U;
            aOrbiterH = RotL64((aOrbiterH * 2041601927968559821U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4167853822635132419U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8950982233003320239U;
            aOrbiterI = RotL64((aOrbiterI * 887144270884244907U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12391327853728029953U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 7100871010552394421U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16552349374101955967U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15381697462381887944U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6801677551341079401U;
            aOrbiterF = RotL64((aOrbiterF * 13325954438427340703U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 947011315719204867U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6356920162398333481U;
            aOrbiterK = RotL64((aOrbiterK * 5566721941682667419U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 8910262020598577378U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8778455415977526457U;
            aOrbiterJ = RotL64((aOrbiterJ * 4092470497616637283U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5585696961453127223U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9670655481681494412U;
            aOrbiterC = RotL64((aOrbiterC * 7863197168965036383U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 48U) + RotL64(aOrbiterI, 58U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + aNonceWordE);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + aNonceWordI) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 23U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterF, 11U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 30U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterK, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29393U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 27345U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29435U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((aIndex + 27589U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 8101351470141807662U) + aNonceWordJ;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 3U)) + 6965474099521076705U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 12U)) + RotL64(aCarry, 53U)) + 6803828268885684784U;
            aOrbiterF = ((((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 13454235922950972488U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aWandererB + RotL64(aIngress, 23U)) + 11678091885751244777U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 27U)) + 5307134544628507141U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 47U)) + 4873703518950429353U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aCross, 43U)) + 8542156221858586039U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 36U)) + 3993726182905296513U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12113047622035464386U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1944244448665721151U;
            aOrbiterB = RotL64((aOrbiterB * 7010050836758762003U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 12914188029425467576U) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2486762763475327024U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12319769994433811617U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14580191602982245481U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12093414832400135066U;
            aOrbiterD = RotL64((aOrbiterD * 12720286833215690663U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13623906997320021065U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9977356009806428696U;
            aOrbiterI = RotL64((aOrbiterI * 2005536391712733499U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3694954095397810851U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11453812627797091638U;
            aOrbiterC = RotL64((aOrbiterC * 13730420725113907161U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 542311345544726351U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3024285045990499484U;
            aOrbiterJ = RotL64((aOrbiterJ * 5153745952148205645U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 15397664082460849530U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10716856680110815056U;
            aOrbiterF = RotL64((aOrbiterF * 13947203772929252823U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 833342121331428547U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1111339940097269219U;
            aOrbiterG = RotL64((aOrbiterG * 17991642769781175473U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9312963978841402871U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 8225496710723213204U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 894499195498817065U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterK, 52U)) + aNonceWordH) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 13U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 22U) + aOrbiterI) + RotL64(aOrbiterE, 37U)) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 23U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 56U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterF, 41U)) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 36U) + aOrbiterF) + RotL64(aOrbiterE, 19U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordL);
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

void TwistExpander_BasketBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA57F860CC1F65C55ULL + 0xD2BAB3C31DCB19D2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF37E5AC0588AC717ULL + 0xE6DE54DA25C0957CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x95202C4615C640D7ULL + 0xB5CB1406A2E60A4BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x971F228143486735ULL + 0x80DAA7CF1135E8E6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB7576D3D890D8E61ULL + 0x94AC22BD3714B5E5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8071019488C95EAFULL + 0x9CF321422C53DC70ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB301294EDFB1F3D5ULL + 0xB3240413227321ABULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDD860ACE66EE4E13ULL + 0x8843D000A47FC720ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDFBFD013BED5256FULL + 0xD98A909F9591C00BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xEA3919E0B097A195ULL + 0xEA4850E01F0FC59BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x813EB743407F7CF3ULL + 0xA4E362C5F7EDBE0AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF29D8019EED9C1A3ULL + 0x92DC9D2279720754ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB1CA8EAEE347F55BULL + 0xC050630F33005F0AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8850D16A7921A275ULL + 0xCC56BF60697CDA14ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8DC4F74387E75D95ULL + 0x9EBC36995A10FC51ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD5F57FCDA7E32AABULL + 0xD8484EE756697AD4ULL);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 550U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4326U)) & W_KEY1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4889U)) & W_KEY1], 57U) ^ RotL64(mSource[((aIndex + 2213U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 22U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (((aWandererI + RotL64(aCross, 34U)) + RotL64(aCarry, 51U)) + 15813325389431304548U) + aNonceWordA;
            aOrbiterE = (aWandererD + RotL64(aScatter, 3U)) + 2223874171125403602U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 47U)) + 5510483568496824130U) + aPhaseAOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 15474152493495661876U) + aPhaseAOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 16846339705130829195U) + aNonceWordL;
            aOrbiterG = ((aWandererA + RotL64(aCross, 41U)) + 1289670576865739669U) + aNonceWordN;
            aOrbiterC = (aWandererC + RotL64(aIngress, 11U)) + 18017354919647006944U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8539685539928984921U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3333721400836704048U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3745286323481400085U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2261560416623815491U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4377786131746816567U;
            aOrbiterD = RotL64((aOrbiterD * 9164777834392621157U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 18047393176583722719U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8184724021940434631U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 9800116157750921119U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10469895939183324807U) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14543391765109879223U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 4817987697437667225U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5757225781746158178U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3539000495894022869U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1032298408884695925U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11288971092707065923U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2761384065186568294U;
            aOrbiterK = RotL64((aOrbiterK * 3323838837427471051U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 7120580145300417101U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6977246291769372866U;
            aOrbiterE = RotL64((aOrbiterE * 15170353875184253779U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterD, 19U));
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 44U) + aOrbiterG) + RotL64(aOrbiterK, 27U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterC, 34U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + aNonceWordG);
            aWandererI = aWandererI + (((((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 21U)) + aNonceWordP) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 36U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordD);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8956U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 9280U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7242U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7333U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 58U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aIngress, 19U)) + 9080426856729228705U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 7851218321653539276U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 28U)) + 7023344692919298036U) + aNonceWordC;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 9772846154227440734U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 35U)) + 12008298632429608431U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 23U)) + 12201090455849562875U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 3U)) + 9498721803411445471U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 351203764023093632U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4966360430644539250U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 10138518378274592739U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9194167899071345693U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4922477697284269116U;
            aOrbiterH = RotL64((aOrbiterH * 8444814161720407881U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15742625291642356429U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7528703106518431730U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11530049278751507567U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15279053574704935317U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2425839793660355555U;
            aOrbiterA = RotL64((aOrbiterA * 11486964816849830667U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 13209849392400008898U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9041500097716231309U;
            aOrbiterJ = RotL64((aOrbiterJ * 340661035700748739U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7885423750878814599U) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 1992993999902904603U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1478629826632201617U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6120758615019314102U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8529621625846992066U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 8485991471612862467U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 4U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 22U) + aOrbiterH) + RotL64(aOrbiterD, 35U)) + aPhaseAWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterG, 47U)) + aNonceWordH);
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterG, 54U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA) + aNonceWordG);
            aWandererG = aWandererG + (((((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 11U)) + aNonceWordD) + aPhaseAWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 27U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16121U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14174U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12136U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[((aIndex + 14842U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 56U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 53U)) + 12809562813316740345U) + aNonceWordM;
            aOrbiterK = (aWandererB + RotL64(aCross, 5U)) + 17084212535326321199U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 16074921689983846769U;
            aOrbiterF = ((((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 14027986153007120145U) + aPhaseAOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 27U)) + 7633455951809250227U) + aNonceWordA;
            aOrbiterC = (aWandererJ + RotL64(aCross, 34U)) + 340989348513370174U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 5307820377645020116U) + aPhaseAOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5605285015771527274U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5293500434746182790U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17674669610895537063U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7263156475892261811U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10672879570907433005U;
            aOrbiterK = RotL64((aOrbiterK * 2506338667179450741U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16659226780900986107U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9774892622769850665U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7487477727543183211U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10728057184108279042U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5032485856947407217U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16651577903809154285U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14642241075374862345U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 8386481273395203518U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11649977733867003445U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2874153265304098104U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11519900149177261000U;
            aOrbiterC = RotL64((aOrbiterC * 2010158758971864505U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8885690878540115768U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4482143389870987714U;
            aOrbiterE = RotL64((aOrbiterE * 7105332459437434281U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterA, 5U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterA, 35U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 57U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 12U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterI, 51U)) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 41U)) + aPhaseAWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16391U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21248U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17767U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 19144U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 54U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 4U)) + RotL64(aCarry, 11U)) + 1898718075389870739U) + aNonceWordH;
            aOrbiterD = (aWandererB + RotL64(aCross, 43U)) + 5631794889237247403U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 27U)) + 18219714659484524607U) + aNonceWordF;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 57U)) + 15419581386225732921U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 9125575431710198210U) + aPhaseAOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aWandererC + RotL64(aScatter, 13U)) + 12205871520544965505U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 7617534300497343422U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 18017579105368135814U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10693882161946020042U;
            aOrbiterE = RotL64((aOrbiterE * 2326507900303932855U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11669615701700895306U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11045110212889232165U;
            aOrbiterH = RotL64((aOrbiterH * 5965171269273719849U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 18019107802806469913U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12315940560472528716U;
            aOrbiterD = RotL64((aOrbiterD * 4505122470351404065U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4899009736070044310U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17412253404253730364U;
            aOrbiterI = RotL64((aOrbiterI * 10791901166391946485U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 4826286251927854181U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4523455921321845084U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14534103906736598099U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4132514462154182215U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 7164745605985109269U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14107325508977225261U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6297434295807635654U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8813887638672996646U;
            aOrbiterC = RotL64((aOrbiterC * 17495632530773158201U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterI, 27U)) + aPhaseAWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterA, 11U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterD, 44U)) + RotL64(aCarry, 11U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterA, 57U));
            aWandererC = aWandererC + ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 5U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 14U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25689U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 27042U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25587U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23525U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCarry, 47U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aCross, 13U)) + 5573188770530340913U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 43U)) + 1431772230889897111U) + aNonceWordK;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 4809192776429682319U;
            aOrbiterB = ((((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 5576603692574369341U) + aPhaseAOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 2720143226007220386U;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 50U)) + 17220328778565331629U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 57U)) + 9629485808442089423U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1136998437010390983U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11893390497814523841U;
            aOrbiterK = RotL64((aOrbiterK * 5329621622743089531U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 1764986431917532370U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1741014798007010376U;
            aOrbiterE = RotL64((aOrbiterE * 13414914086049500731U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 12221368453236547044U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 7694538641172350430U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8439120733670016501U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17472344518811560603U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3308740700728172984U;
            aOrbiterG = RotL64((aOrbiterG * 15290400462887712083U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9535358833412446771U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11192312491731312451U;
            aOrbiterA = RotL64((aOrbiterA * 17405609148475445743U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14850451970047190039U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11932493299452443256U;
            aOrbiterJ = RotL64((aOrbiterJ * 7964808728820467795U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5972619895614731870U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17174497535809891690U;
            aOrbiterH = RotL64((aOrbiterH * 15471084511364572533U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterE, 5U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterE) + aNonceWordE) + aPhaseAWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 41U)) + aOrbiterB) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 18U) + aOrbiterJ) + RotL64(aOrbiterK, 54U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 22U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28634U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31266U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28464U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 30749U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 37U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 19U)) + 4773124477323378268U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 16848723289435796005U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 37U)) + 13846642134917107058U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (aWandererC + RotL64(aCross, 26U)) + 6472057872482789939U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 2747019500690707226U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 9003965289739733880U) + aNonceWordJ;
            aOrbiterI = (aWandererI + RotL64(aIngress, 11U)) + 3013390651936257377U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3331004709895625067U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15355010435553517129U;
            aOrbiterE = RotL64((aOrbiterE * 8322759117004876831U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7709870658004280052U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13568728443963926564U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 6736090830113688981U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12409548853419307131U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 969183352023661537U;
            aOrbiterC = RotL64((aOrbiterC * 5549220554838837145U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 15370309834426476775U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3896803894396631184U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11018830202891911603U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10848873633291935766U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12885336509190543440U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1487357252619221365U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8252290890093788010U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9201553615601641350U;
            aOrbiterD = RotL64((aOrbiterD * 420321130559162915U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14014209645503188472U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4015071464301844550U;
            aOrbiterA = RotL64((aOrbiterA * 17444195018239904971U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 42U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 35U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF) + aNonceWordF);
            aWandererE = aWandererE + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + aNonceWordE) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterF, 21U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 43U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aCross, 12U) + aOrbiterC) + RotL64(aOrbiterF, 28U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_BasketBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC3FA78BD4AD5DEEDULL + 0x844368D1D3BD99D4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8BD738EABCF0B303ULL + 0xC4F4D6BE6A67CBA4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB75B493002261683ULL + 0xD38F271280C93750ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC364CAE23417C3E7ULL + 0x9FA22EE708DCBB46ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9261D291C9ED2707ULL + 0x855F7D8F97EA1C21ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA9AD116FCD0DC5D9ULL + 0xE266DAEDB5CBA193ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x84AA453953C0E211ULL + 0xE1DFC56EC10943B2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8C775478B6B6FB35ULL + 0xE416979B9991584BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF49A6F46DDFA0151ULL + 0x8201D553345D5B05ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC649A5098320D139ULL + 0xE964990E4E320C50ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFB36BEF3D3D1E317ULL + 0xBF4DC44EFDBEDD99ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD8CF45A8A2D14EF7ULL + 0x8EE655CBC23E066DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA1A02791708995C1ULL + 0xD646FD44AC2455A3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x95E46766AE4FBF39ULL + 0xB98C98D56BD07478ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFA064F2E0CA42BE3ULL + 0xBC5046928135A286ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB2C5043407AEC319ULL + 0xD5F91E70B87AD42DULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 104U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 3521U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2365U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 1U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 29U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 56U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aScatter, 47U)) + 12046647397183218524U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 2760779375026461991U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 13735454443176855650U) + aPhaseBOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 4370377000586647724U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 58U)) + 14566322384189969094U) + aNonceWordO;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5056565959818422786U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8795403810686579209U;
            aOrbiterG = RotL64((aOrbiterG * 11205867337479457471U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9625947666256011567U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1703669290934254701U;
            aOrbiterB = RotL64((aOrbiterB * 5763881345676123583U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6664070663184147951U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2104148316797553431U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12887842067180975983U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1197910004222596145U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9922977170060903197U;
            aOrbiterC = RotL64((aOrbiterC * 13047828062605568603U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2048376210852567829U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12568990647075931409U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9860242601194210927U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + RotL64(aOrbiterI, 30U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 20U) + RotL64(aOrbiterB, 53U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 21U)) + aOrbiterG) + aNonceWordK);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7866U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7045U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9830U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9200U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 36U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 1866656689936219099U) + aNonceWordD;
            aOrbiterE = ((((aWandererB + RotL64(aIngress, 60U)) + RotL64(aCarry, 57U)) + 2312314528139448289U) + aPhaseBOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 13U)) + 3554037526469185237U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 405707755060974111U) + aPhaseBOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 35U)) + 1862976326004007697U) + aNonceWordJ;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12992483065443288263U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3793854946371595197U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 1819119223110966487U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 4244007978867369382U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10280867500312580308U;
            aOrbiterJ = RotL64((aOrbiterJ * 13729899124177931289U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 472563452959164242U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12041770406895816553U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17811798500132002631U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6118634015704900486U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 13637107920449233307U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 17712028184714868053U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16673735670669318830U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8602681273646630496U;
            aOrbiterB = RotL64((aOrbiterB * 6995213887710749241U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 46U) + RotL64(aOrbiterB, 5U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + aNonceWordC);
            aWandererB = aWandererB + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12763U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((aIndex + 13842U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14717U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12844U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aIngress, 42U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 54U)) + 1142447269198373880U) + aNonceWordM;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 10581460640040336191U;
            aOrbiterI = ((((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 14703062773878202900U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 15737525756286914746U) + aPhaseBOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 43U)) + 16178774478273186999U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 2514897053906809160U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13702496607592508464U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 16540143680974064057U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 18030885275418337965U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5241783876161655984U;
            aOrbiterF = RotL64((aOrbiterF * 10970981186787227937U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 2807052676283587925U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8022804576763271327U;
            aOrbiterG = RotL64((aOrbiterG * 11727096043219370577U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15597099852232205860U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1538435607932096400U;
            aOrbiterJ = RotL64((aOrbiterJ * 7900752511710516981U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11147868774413615365U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 9325213746830411568U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 561819005818948769U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 52U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            aWandererK = aWandererK + (((((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 36U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aNonceWordD) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 11U)) + aOrbiterF) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19228U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 21135U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20950U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 16983U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 23U) + RotL64(aCarry, 54U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 39U)) + 15726877954695761686U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 27U)) + 14187652171881943587U) + aPhaseBOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 8420423151313882782U) + aPhaseBOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 14942322692433259283U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 14U)) + RotL64(aCarry, 35U)) + 7272331475919796255U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 154504365041805840U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17475491222554948786U;
            aOrbiterB = RotL64((aOrbiterB * 2095330528612694779U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5759181483165339605U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5993060214499322845U;
            aOrbiterE = RotL64((aOrbiterE * 10799489831896153301U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10901786237875941844U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 17135786595614068473U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15923538730142047043U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 5208202073886811165U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6821452921018900631U;
            aOrbiterA = RotL64((aOrbiterA * 13119330055184115669U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 13348064837402206969U) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8967943922403445136U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 300168481725373093U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 6U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + aNonceWordF);
            aWandererA = aWandererA + ((((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 57U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterE, 48U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterF, 21U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22526U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25000U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26260U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23004U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 6U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 47U)) + 3105313968748067810U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 5U)) + 9977249451119627064U) + aNonceWordA;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 43U)) + 17941392803495349366U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aIngress, 14U)) + RotL64(aCarry, 13U)) + 4279533326705471133U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 13983828966811580039U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 3983490984234810378U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 308786542215259956U;
            aOrbiterJ = RotL64((aOrbiterJ * 4366245356597769425U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8443607695364427037U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14939626441464340668U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16793255020331774983U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9350693577306121110U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1717071159396961752U;
            aOrbiterE = RotL64((aOrbiterE * 11062480662625054525U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15911765265202100610U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 14898546272333182767U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 2674900543810733067U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3560903518513465868U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5367062725726860234U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8521908836601319553U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 28U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterH, 11U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + aNonceWordL) + aPhaseBWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32624U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27537U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30888U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 31423U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aIngress, 20U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aIngress, 56U)) + RotL64(aCarry, 29U)) + 16124889768301047791U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 11912338587186717280U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 8594012868813114354U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 35U)) + 18281043566156682815U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 27U)) + 16853106130200942302U) + aNonceWordA;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2611212958619673086U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 18039472325066855180U;
            aOrbiterF = RotL64((aOrbiterF * 10213999643376367785U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14495785571345122046U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 4556063793412832418U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13166927543135467627U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 14896419970271244358U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 880028529183500036U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 14228281807461251361U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2379557167489415783U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11854373946064529806U;
            aOrbiterJ = RotL64((aOrbiterJ * 150755294320438887U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1487252775956449964U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12777924204511625545U;
            aOrbiterE = RotL64((aOrbiterE * 1366019527386994789U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 48U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + aPhaseBWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterK, 3U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 26U)) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterE, 13U)) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordK;
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_BasketBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD3D3C28742A5A2A7ULL + 0xE772FAD4F4B6EFB7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9DB8AB1154A8B831ULL + 0xFD98EAA7EC96BB06ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD60122E0180937A9ULL + 0xF03999098B07302BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF9319D5200AD29F7ULL + 0xCC6FF8F766608D4DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFE62492E4CCB93F9ULL + 0xE6A1B7905E405F8DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBEA5A8790260539BULL + 0xB1383208159FC55CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE2426EBD5581420BULL + 0xE56D8EA8BA9143C5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x83AC4F1B9562C57DULL + 0xD12C874D60E298AEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF7B6AE189C028379ULL + 0xF33BC4CB14E627F7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9ABA93CBAE0C6535ULL + 0xC6D4CC79C80A82ABULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE3EBAFEE8B3F87B3ULL + 0xF36C784B25585FD3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC76BFFA2D578E665ULL + 0x9047AF124E2B1B3CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBE326C9CF4AB99F7ULL + 0xC94F1D47A7D77BC9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x84326DA1D19987E5ULL + 0x97BD6B3BFCA538F1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x80AE089615CC8635ULL + 0x9879EE383008BAC4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE06DE14EBFA9D2C7ULL + 0x9BB72A77642878EAULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 211U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 1429U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3329U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 2385U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 56U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = (aWandererI + RotL64(aIngress, 46U)) + 16462052553719977502U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 57U)) + 12337064059566619581U) + aPhaseCOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 15801005007094515447U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 8228706742665081656U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 11006723027845190869U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 6U)) + 18173765337829177450U) + aNonceWordN;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 51U)) + 530215083653542558U) + aNonceWordP;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 19U)) + 6608611827035564511U;
            aOrbiterD = (aWandererC + RotL64(aCross, 27U)) + 2246051826221626809U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5228575308895381421U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10999213210689606857U;
            aOrbiterH = RotL64((aOrbiterH * 5467601259546342925U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3773371037240485696U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 8887985779436152504U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 698713082830739677U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11150566414723818350U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8336366151003049546U;
            aOrbiterK = RotL64((aOrbiterK * 9033771197242493699U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13233968794237090787U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8172558473508478819U;
            aOrbiterD = RotL64((aOrbiterD * 17837070423649268435U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 133564480283347997U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15104810248883567064U;
            aOrbiterC = RotL64((aOrbiterC * 706802420642303533U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9138629520201127075U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 13993086066341664080U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 4875046427147105077U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6547273508580516932U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 9838727018769865759U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11395273371936839815U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11685694999526122626U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8945983172566303116U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17791527981004597623U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 17606249889617356327U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9296903152000480008U;
            aOrbiterJ = RotL64((aOrbiterJ * 18066622289408024413U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 20U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterE, 29U));
            aWandererD = aWandererD + ((RotL64(aCross, 20U) + RotL64(aOrbiterC, 57U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererI = aWandererI + (((((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 12U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordO) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterC, 43U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 24U) + aOrbiterE) + RotL64(aOrbiterJ, 47U));
            aWandererG = aWandererG + (((((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 43U)) + aNonceWordE) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterC, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9998U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14712U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10192U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16332U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 22U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 16189787374324972735U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 57U)) + 17563763730956242224U) + aNonceWordG;
            aOrbiterI = (aWandererI + RotL64(aCross, 18U)) + 10572803498593789385U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 21U)) + 7713105232072974166U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 23U)) + 10760839534772718139U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 27U)) + 13397069448391230253U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 41U)) + 4569255679998375682U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 9888769350817876949U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 14U)) + 11351796060878856300U) + aNonceWordL;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 18153775071965707204U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1282846411145853435U;
            aOrbiterI = RotL64((aOrbiterI * 12294455920906257823U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16457743979262460660U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 173493260775251032U;
            aOrbiterA = RotL64((aOrbiterA * 4935807229040883505U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3927345926316409630U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5158769729850853623U;
            aOrbiterD = RotL64((aOrbiterD * 2446452358663812945U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12331351600010165154U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3940794200348684050U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 13248997263062075043U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11248514843822945425U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1391497323278226522U;
            aOrbiterK = RotL64((aOrbiterK * 8376841806072565005U), 47U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 13265623528678787307U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2802033745265647317U;
            aOrbiterB = RotL64((aOrbiterB * 3437626962562016147U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6938444301018051844U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1086544666755559028U;
            aOrbiterG = RotL64((aOrbiterG * 16039728388882079889U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16156443117365816536U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3619942859562697142U;
            aOrbiterH = RotL64((aOrbiterH * 7589346043159112151U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17681848914912743292U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8848238631758130416U;
            aOrbiterC = RotL64((aOrbiterC * 810402256099500607U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 40U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + aNonceWordB);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 6U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterH, 11U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterC, 27U));
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterD, 22U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterK, 39U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterD, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 14U) + aOrbiterA) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23856U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((aIndex + 18374U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24075U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17232U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aIngress, 27U)) + (RotL64(aCross, 13U) + RotL64(aPrevious, 47U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 13U)) + 13442819395490639310U) + aNonceWordC;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 28U)) + 8187292523194120936U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 11469697159823131388U) + aPhaseCOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aCross, 47U)) + 13414083692375929653U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 35U)) + 11404010733687907517U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 6783212827186218247U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 3U)) + 8561131439340372614U) + aPhaseCOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 6252609642004429113U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 56U)) + 12804867444200448952U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2739648749603690781U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14808861217017399752U;
            aOrbiterE = RotL64((aOrbiterE * 373911885694012101U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17588866502571268888U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5882260142735642980U;
            aOrbiterH = RotL64((aOrbiterH * 7688252946143263869U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15493099088132862949U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5175647411532429582U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 15226544495598541883U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 14279707376173642767U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 6826363572161275158U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5263708315440161809U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13267185753040999992U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9980987858092888720U;
            aOrbiterC = RotL64((aOrbiterC * 13210290848800728635U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3582972937645514549U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10140409019562890804U;
            aOrbiterD = RotL64((aOrbiterD * 6944490201647678479U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6160444117287330557U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16344602960561293113U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2319964919335633293U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3497141036108337171U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 91269118352540308U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5160060720189045505U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12739932748793144857U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12820180915064791197U;
            aOrbiterB = RotL64((aOrbiterB * 5843849637411948699U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 44U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterD, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 43U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 10U)) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterE, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 50U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 43U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 3U)) + aPhaseCWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31399U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 31430U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27187U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneD[((aIndex + 27644U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 3684295017013759987U;
            aOrbiterH = (aWandererB + RotL64(aCross, 60U)) + 6740408842457292881U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 19U)) + 4563975890702399441U) + aPhaseCOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 797804144825287940U) + aNonceWordM;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 27U)) + 2763779540450101303U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 11U)) + 13211846164102089685U) + aNonceWordP;
            aOrbiterK = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 15214578447281401982U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 34U)) + 13745208628754232427U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 23U)) + 17358621225969190747U) + aPhaseCOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 779739369960480023U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4370963533701407813U;
            aOrbiterC = RotL64((aOrbiterC * 3123135216876641039U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6061333005507739975U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3589705340762734456U;
            aOrbiterF = RotL64((aOrbiterF * 16499293983611196967U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10607697666369230567U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 9356757995305239271U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 10945513661439954731U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10093033335903048138U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11037328061699834100U;
            aOrbiterA = RotL64((aOrbiterA * 11189760551792389605U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 558431161176115540U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17795680919453449358U;
            aOrbiterJ = RotL64((aOrbiterJ * 3910117359996283803U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 6096779391116214109U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17594243286880690775U;
            aOrbiterE = RotL64((aOrbiterE * 12655610181937429915U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15414704802398002423U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18040588240488602196U;
            aOrbiterI = RotL64((aOrbiterI * 16344249573086571225U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14636298592697156931U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9677305688594936561U;
            aOrbiterB = RotL64((aOrbiterB * 8354776999961642997U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16408025751875050713U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10018342878801454965U;
            aOrbiterH = RotL64((aOrbiterH * 10349132962708124117U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 44U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 39U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 30U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 30U) + aOrbiterI) + RotL64(aOrbiterE, 35U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 57U) + RotL64(aOrbiterI, 23U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterK, 58U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterB, 3U)) + aOrbiterK) + aNonceWordJ);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterA) + aPhaseCWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 10U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordD);
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

void TwistExpander_BasketBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAC71ADA62BF5F331ULL + 0xEB3771909E2A79F2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD04D4C16422589D1ULL + 0xB5A4B03981935D34ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC431D22C9DE0A98DULL + 0xE5A8A76D5FE2E8E6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9383F7A8117AD089ULL + 0xE8340EC310FB04D9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDDEE2F2C59AC5219ULL + 0xDF8F842F3DA116EDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAAF45B7ED9D46DFBULL + 0xE6A920926FBC9A94ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE63ECB2FB5A1F5FFULL + 0xBBB2FA0504F9BC1AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xACBF5365BEBED2A3ULL + 0x82B46C71BE2D2FD4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC7C97DDF4E70DAB9ULL + 0xE345BB9D07CB5FFEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF53105B7224A0D0DULL + 0xBBAD40BC6AE438C6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8A93A5E95CE28A83ULL + 0x97C65C8BAEA56688ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA20650001BC74B49ULL + 0xDAD93021C009D07DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDCC3651D47BD28A1ULL + 0xA84C7A89BA05FA95ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD4F72C98BB668D97ULL + 0xD48DFBD9365B0D7FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8D9AC72BFE06239FULL + 0xED64A6AA62C882C3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD9795222FA3BBC37ULL + 0x872CFC812D2A19FBULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3475U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4139U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5347U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 4475U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 58U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 43U) + RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 5041131702736607991U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 50U)) + 9295010428212681446U) + aNonceWordF;
            aOrbiterD = (aWandererA + RotL64(aScatter, 47U)) + 6235875895358766017U;
            aOrbiterB = (aWandererI + RotL64(aCross, 23U)) + 2622227802531866918U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 43U)) + 3888894734834524972U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aIngress, 11U)) + 241682012014701753U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 37U)) + 15758000422451568079U) + aNonceWordC;
            aOrbiterC = (((aWandererB + RotL64(aCross, 14U)) + 2061944548396976912U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 8177144990755754531U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 554978075608818497U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 19U)) + 250408260560714933U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8700027645880997552U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10026130047465480902U;
            aOrbiterD = RotL64((aOrbiterD * 12417270861933696623U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9785843014096326696U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9998582683258411251U;
            aOrbiterG = RotL64((aOrbiterG * 7197956237569462269U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13817734599383455151U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6647207154174092691U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 1578528131687283531U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4957715980509035719U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4994885315786213197U;
            aOrbiterB = RotL64((aOrbiterB * 5676683798126497011U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5072908311783966503U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5535039946192891515U;
            aOrbiterF = RotL64((aOrbiterF * 2989412783482309753U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6594577050344146271U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8750154123258714856U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6942158167127532003U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3514769314840874873U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8626045200273524281U;
            aOrbiterK = RotL64((aOrbiterK * 4315441782689789689U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8524870284841706517U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1841819423572964209U;
            aOrbiterI = RotL64((aOrbiterI * 9802481758007234681U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12668382464510772517U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6330331402801670515U;
            aOrbiterJ = RotL64((aOrbiterJ * 9096920618612750935U), 21U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 10346986196055766087U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10932918162471200996U;
            aOrbiterC = RotL64((aOrbiterC * 6863632877625141567U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6264557195446069146U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5041131702736607991U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4978591546106895045U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 56U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 28U) + aOrbiterE) + RotL64(aOrbiterD, 43U));
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterC) + aPhaseDWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 14U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterF, 23U)) + aNonceWordB) + aPhaseDWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterB, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 39U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 35U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 48U)) + aOrbiterK) + aNonceWordI);
            aWandererB = aWandererB + ((RotL64(aIngress, 48U) + aOrbiterG) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10110U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 10688U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7153U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 9129U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 10U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aScatter, 37U)) + 9220392006207660113U;
            aOrbiterG = (aWandererI + RotL64(aCross, 51U)) + 11305018553489132882U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 21U)) + 5860373868073513684U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 28U)) + 12319586170883987589U) + aPhaseDOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 13U)) + 14072333614354649021U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 3U)) + 9332158529453194608U) + aNonceWordG;
            aOrbiterE = (aWandererG + RotL64(aIngress, 41U)) + 3860569321145958686U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 6U)) + RotL64(aCarry, 3U)) + 8119005668901240093U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 13918259792880333239U) + aNonceWordH;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 6938856216758228704U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 43U)) + 3960905839118710604U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 6043879193734253929U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15691425268831319195U;
            aOrbiterK = RotL64((aOrbiterK * 7189195135654636271U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14912209933584715274U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16180183395910618923U;
            aOrbiterG = RotL64((aOrbiterG * 3942858974766467849U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4966642362507707776U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6962226782462822861U;
            aOrbiterJ = RotL64((aOrbiterJ * 3647802407741095419U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12409120845092026295U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2302946450253872465U;
            aOrbiterE = RotL64((aOrbiterE * 7099576330777297911U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16118304388937163838U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 15968419034359049422U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11736207775827080165U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17098982091525008231U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10298979200690822062U;
            aOrbiterC = RotL64((aOrbiterC * 12620028874653521945U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 552826643694256437U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11786560990790695378U;
            aOrbiterI = RotL64((aOrbiterI * 11190309640069208311U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13730399230389329793U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17614226859252305432U;
            aOrbiterF = RotL64((aOrbiterF * 2640019643570222977U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1062738267846296283U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13959480457644980835U;
            aOrbiterB = RotL64((aOrbiterB * 1194145909157002977U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 4635071137794189167U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13374502212707796180U;
            aOrbiterH = RotL64((aOrbiterH * 129680788767298945U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11479902881487238033U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9220392006207660113U;
            aOrbiterA = RotL64((aOrbiterA * 1437457810224888809U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 6U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aScatter, 26U) + aOrbiterC) + RotL64(aOrbiterD, 43U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 60U)) + aOrbiterE) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterI, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 23U)) + aOrbiterB) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterI, 11U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 39U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterH, 35U)) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aScatter, 30U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterG, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14140U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 13659U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13367U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 13246U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 9041099828460168106U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 48U)) + 12883711604096848454U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 51U)) + 17420968786226443079U) + aNonceWordJ;
            aOrbiterE = ((aWandererD + RotL64(aCross, 13U)) + 3448213891716125104U) + aPhaseDOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 19U)) + 11866455977445336560U) + aPhaseDOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aScatter, 37U)) + 4119356835384495905U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 2186212599698637068U) + aNonceWordG;
            aOrbiterJ = (aWandererA + RotL64(aCross, 11U)) + 6506144898969301620U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 39U)) + 12556800923644051626U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 34U)) + 4075551535185182945U) + aNonceWordM;
            aOrbiterI = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 17877694808492008749U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5553428900598223316U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14362304852277160675U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11415103199856419303U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9174200302876075831U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16110739511917638547U;
            aOrbiterH = RotL64((aOrbiterH * 7004356839428657949U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10189881974519849402U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2128076632642616677U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 8860453653433114929U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18133523799074400083U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9916472958834153766U;
            aOrbiterD = RotL64((aOrbiterD * 3454601168808001733U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10274457562795569227U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14134814273275356425U;
            aOrbiterJ = RotL64((aOrbiterJ * 15912501063665343159U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6394306369514735480U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4825761192736485643U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12534544147331805643U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5672807934779206275U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3881953574159390421U;
            aOrbiterK = RotL64((aOrbiterK * 7448770570912161095U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12012232712634303203U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14176392925893052596U;
            aOrbiterE = RotL64((aOrbiterE * 11288668529893084583U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 307148402076391033U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15380446373458263079U;
            aOrbiterA = RotL64((aOrbiterA * 15228462337097647933U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 4654312690816676129U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10818029316701301859U;
            aOrbiterF = RotL64((aOrbiterF * 16245734506125913215U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7340370713289840635U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9041099828460168106U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1807356802142268373U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 30U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 39U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 20U) + aOrbiterE) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 21U));
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterB, 3U));
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterE, 26U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 57U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 34U) + aOrbiterG) + RotL64(aOrbiterF, 43U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterD) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 38U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 20667U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 20459U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16870U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 19532U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 12U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererE + RotL64(aIngress, 44U)) + 12426357877879529292U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 12604900366173639176U;
            aOrbiterF = (aWandererC + RotL64(aCross, 5U)) + 13511119007338929401U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 23U)) + 9878720081166788060U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererH + RotL64(aIngress, 37U)) + 15463195409806395076U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 42U)) + RotL64(aCarry, 41U)) + 6407922778852833423U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 13U)) + 7690427254160734016U) + aNonceWordJ;
            aOrbiterE = (aWandererF + RotL64(aScatter, 51U)) + 18030974031722143619U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 17983938038322737041U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 11U)) + 16605512170117753884U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 29U)) + 681802273302348322U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15550312921312083819U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17824154101711884508U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7358612830654795357U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1939207786756735430U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3132864634777826569U;
            aOrbiterD = RotL64((aOrbiterD * 13606281919426730325U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12822929773923954849U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16576106045887115660U;
            aOrbiterB = RotL64((aOrbiterB * 16370914370769903051U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2398825881649235260U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13700821892926092479U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 10830623703416956043U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2439833784883391606U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15870638514107637833U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3797380922767479287U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9165457123134229670U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8736642509192659417U;
            aOrbiterK = RotL64((aOrbiterK * 16219277537523484065U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9232719746484835693U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7826680628853322541U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 12578050118133526187U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14323652326982518782U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2254524512851399313U;
            aOrbiterJ = RotL64((aOrbiterJ * 4119339547645451149U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14459632243829356472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8591197056749497716U;
            aOrbiterG = RotL64((aOrbiterG * 13053836520694721881U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17220196418897000411U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7186579019945992185U;
            aOrbiterH = RotL64((aOrbiterH * 12406048515179065691U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7554005180895698880U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12426357877879529292U;
            aOrbiterI = RotL64((aOrbiterI * 5090046967147694465U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 12U);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 39U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterH, 23U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 29U)) + aNonceWordL);
            aWandererF = aWandererF ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterB, 46U)) + aOrbiterH) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterF, 29U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 35U)) + aOrbiterE);
            aWandererE = aWandererE + (((((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 53U)) + aNonceWordB) + aPhaseDWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterG, 43U));
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterB, 26U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aPrevious, 14U) + aOrbiterK) + RotL64(aOrbiterI, 41U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererG, 12U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24152U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 24032U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22895U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 25932U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 57U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 36U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererD + RotL64(aCross, 21U)) + 11039986441331892533U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 10U)) + RotL64(aCarry, 47U)) + 6256024955965426119U) + aNonceWordD;
            aOrbiterC = (aWandererH + RotL64(aScatter, 29U)) + 9857443189988995666U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 11900944813380998208U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 13U)) + 8422577734978875541U;
            aOrbiterD = (aWandererB + RotL64(aCross, 3U)) + 3100835100713928724U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 27U)) + 11871553509810206993U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 52U)) + RotL64(aCarry, 19U)) + 17614749493763417027U) + aNonceWordB;
            aOrbiterA = ((aWandererK + RotL64(aCross, 5U)) + 3638372131856199916U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 35U)) + 6582275259281025770U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aIngress, 23U)) + 17016882418498941958U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1747214688658984715U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9356088987044015278U;
            aOrbiterC = RotL64((aOrbiterC * 16221733545319753695U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4056238112133473456U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16013150119949532998U;
            aOrbiterD = RotL64((aOrbiterD * 12913648646318115315U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16076621211111834889U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 9940824359571581765U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11624767861336495331U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15624084004784515753U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7630989544834680335U;
            aOrbiterI = RotL64((aOrbiterI * 12261063237156822067U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 18003586430673313786U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1654118743290334161U;
            aOrbiterE = RotL64((aOrbiterE * 1153250137357176071U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3254189676528343910U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 15629083361573065165U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17024833368570949107U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10056859810555674806U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15976683222786846254U;
            aOrbiterH = RotL64((aOrbiterH * 2801754232182942635U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11872378594829637933U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7633773773528713489U;
            aOrbiterA = RotL64((aOrbiterA * 8218288492011593353U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16305188578382203720U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13293036594949754170U;
            aOrbiterB = RotL64((aOrbiterB * 1300645662609848183U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15185013801659166674U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11562899709899198100U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 9115495024409604629U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1525205566739385260U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11039986441331892533U;
            aOrbiterJ = RotL64((aOrbiterJ * 9802284050237622047U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterC, 51U)) + aPhaseDWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 26U) + aOrbiterA) + RotL64(aOrbiterF, 18U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterF, 47U));
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterK, 41U)) + aPhaseDWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 37U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterA, 5U)) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterD, 35U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterI, 10U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28449U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 32505U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30075U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 28620U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 3U)) + (RotL64(aCarry, 40U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aPrevious, 13U)) + 2330952702412094686U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 57U)) + 7820188225935060799U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 46U)) + 9347644591709839145U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 43U)) + 2288624878446846870U) + aNonceWordH;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 19U)) + 9358977729492824128U) + aPhaseDOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 1858511275052455039U;
            aOrbiterG = (aWandererI + RotL64(aCross, 35U)) + 13715478509322292552U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 16413396625604260455U;
            aOrbiterH = (aWandererA + RotL64(aCross, 27U)) + 17714322215518432705U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 24U)) + 16188315436202861122U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 5564445841368207813U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13717068949900594673U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14143659432287313765U;
            aOrbiterA = RotL64((aOrbiterA * 17281441046722262917U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5729546141908425670U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4297827922736712074U;
            aOrbiterK = RotL64((aOrbiterK * 13631630436759768885U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 829520109395163673U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11547160328525174295U;
            aOrbiterJ = RotL64((aOrbiterJ * 4759690159673049775U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2907177944512117206U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11100346409065275671U;
            aOrbiterG = RotL64((aOrbiterG * 17927994356809011637U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1344592529249949068U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6470438516791143572U;
            aOrbiterI = RotL64((aOrbiterI * 13339390828725370475U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5217751823741520847U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 5371275223586938039U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 12318403075523724125U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14218103150268532919U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1367628876596800571U;
            aOrbiterC = RotL64((aOrbiterC * 13777531272321533137U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2372041991018455610U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9870744274890595581U;
            aOrbiterD = RotL64((aOrbiterD * 12093443117747395585U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15531376915156611594U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11166549148968363252U;
            aOrbiterF = RotL64((aOrbiterF * 10024372567841218915U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8555942275137258839U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3304132937209624841U;
            aOrbiterB = RotL64((aOrbiterB * 7965093976633155809U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14825330575158830172U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2330952702412094686U;
            aOrbiterE = RotL64((aOrbiterE * 9146641978165131495U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterE, 39U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterF, 57U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 44U));
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 46U) + aOrbiterG) + RotL64(aOrbiterF, 37U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 18U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordB);
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

void TwistExpander_BasketBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x81A342BF2D683E0DULL + 0xDDA934E36EFFDBDFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEFF9DED8107169C3ULL + 0xCDB1A9E9045C3EABULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x960F746BC603AEF3ULL + 0xDE12AB86ACE6ACE8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB2202DADD3359977ULL + 0xEE7656050487B93CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD72C280516AD406FULL + 0x9D7391E560C443B0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDA4A617039A16831ULL + 0xBEC4656DB904110DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD446AB70578B078DULL + 0xFFB91EA6B68374ACULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBBF66934B94E1FB3ULL + 0x894D4B5B913C4186ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD43BFF0B78D0CC27ULL + 0x856E6DE77ABA17CBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x878A9DAAB97EA331ULL + 0xDABB237EA18754D6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA078B6D32C36C091ULL + 0xB4A72EFF8555E4A2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA6066D4E00643FFFULL + 0xD1CFA009C4869994ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAC2593C0DFC10393ULL + 0x8AC963025BC7E4F5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDDBE96A35381C923ULL + 0x81FB4DA19F7EE8EDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8FC8DFFC3DEF2191ULL + 0x85761E8FFD1DDEE7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x942B6468EDABF025ULL + 0xBA817B17B6313D5FULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3270U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4959U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2530U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4677U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 28U) + RotL64(aCross, 43U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 51U)) + 16160838483846078448U) + aNonceWordK;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 46U)) + RotL64(aCarry, 27U)) + 15404960896190227946U) + aNonceWordJ;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 16904160594024977199U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 17790460246821031802U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 3U)) + 16395168254086971959U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 23U)) + 7484373204039901786U) + aPhaseEOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aCross, 11U)) + 18026814691322913510U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 27U)) + 15244817793136966450U) + aNonceWordI;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 14U)) + 5795491730356335666U) + aPhaseEOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aCross, 39U)) + 3163873518027801504U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 21U)) + 2690791759507349172U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17898067251167087906U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8028010015006604239U;
            aOrbiterJ = RotL64((aOrbiterJ * 5601629670521300241U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7304739457289910555U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6476837815096530043U;
            aOrbiterK = RotL64((aOrbiterK * 16380545138701113267U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14242499233467960602U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17305645693017634630U;
            aOrbiterH = RotL64((aOrbiterH * 14442976693206929569U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9772864059444171908U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7897200728282156408U;
            aOrbiterA = RotL64((aOrbiterA * 816306719390807411U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4890999319172950996U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8165132649356094963U;
            aOrbiterF = RotL64((aOrbiterF * 17297706071263690189U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9342923520083533265U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7213639583505088067U;
            aOrbiterC = RotL64((aOrbiterC * 1349251979649428909U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4079475132684197272U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3350998022472827283U;
            aOrbiterB = RotL64((aOrbiterB * 948841791460066265U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2479140576609216238U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7703147534931674972U;
            aOrbiterG = RotL64((aOrbiterG * 11419116495223970801U), 39U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 9050277787914448469U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13295888852307317371U;
            aOrbiterE = RotL64((aOrbiterE * 3027097172772140975U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15380254190549884741U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17653690414528791774U;
            aOrbiterI = RotL64((aOrbiterI * 15923958179714368315U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6825072759468337036U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16160838483846078448U;
            aOrbiterD = RotL64((aOrbiterD * 11690325563580492415U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 26U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 27U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 21U)) + aOrbiterH) + aNonceWordA);
            aWandererG = aWandererG + ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 3U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 50U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aIngress, 58U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterC, 47U)) + aNonceWordD);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 41U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 52U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 30U) + aOrbiterI) + RotL64(aOrbiterA, 43U));
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 37U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 52U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8272U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 10911U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6602U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9689U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 58U)) + (RotL64(aIngress, 37U) + RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aScatter, 18U)) + RotL64(aCarry, 57U)) + 12809562813316740345U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 41U)) + 17084212535326321199U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 51U)) + 16074921689983846769U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 47U)) + 14027986153007120145U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 54U)) + RotL64(aCarry, 3U)) + 7633455951809250227U) + aNonceWordE;
            aOrbiterK = (aWandererC + RotL64(aScatter, 11U)) + 340989348513370174U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 21U)) + 5307820377645020116U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 5605285015771527274U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 27U)) + 5293500434746182790U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 3U)) + 7263156475892261811U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 29U)) + 10672879570907433005U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16659226780900986107U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9774892622769850665U;
            aOrbiterD = RotL64((aOrbiterD * 7487477727543183211U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10728057184108279042U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5032485856947407217U;
            aOrbiterI = RotL64((aOrbiterI * 16651577903809154285U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14642241075374862345U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8386481273395203518U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11649977733867003445U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2874153265304098104U) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 11519900149177261000U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2010158758971864505U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8885690878540115768U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4482143389870987714U;
            aOrbiterB = RotL64((aOrbiterB * 7105332459437434281U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17469068567801886615U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 5121422018622394837U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14823827133212643467U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3130788210672745618U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6139244627510113216U;
            aOrbiterC = RotL64((aOrbiterC * 2640754184921507389U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10488511756324474710U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1760223670304953696U;
            aOrbiterK = RotL64((aOrbiterK * 4007062295003769311U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2232708414171096783U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17497492434939621063U;
            aOrbiterH = RotL64((aOrbiterH * 9850565931511937725U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 8199114561613022892U) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15432482434863050835U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14271143436318169871U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14991531324947777062U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 12809562813316740345U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 4487021480964944879U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 6U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 23U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterI, 11U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterB, 6U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 39U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterD, 41U));
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterA, 51U)) + aPhaseEWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterC, 27U));
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 21U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 56U) + aOrbiterA) + RotL64(aOrbiterB, 58U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererI, 30U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 12671U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 11963U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11945U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 11877U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 58U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aCross, 19U)) + 11450949896247900941U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 3U)) + 3905542253538116335U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 51U)) + 9529740545977785305U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 26U)) + RotL64(aCarry, 39U)) + 1856876631533143492U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 84253466320181686U) + aNonceWordJ;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 35U)) + 12577480918745432444U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 53U)) + 5625703170397704029U) + aPhaseEOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 28U)) + 694608607323629282U) + aPhaseEOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 3993981243536262204U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 47U)) + 4119215953484892051U;
            aOrbiterF = (aWandererD + RotL64(aCross, 41U)) + 8785040118556157146U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16234403619456882890U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10398727475672860610U;
            aOrbiterI = RotL64((aOrbiterI * 5086871400049644715U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 18327987141759096769U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2645964788056875452U;
            aOrbiterJ = RotL64((aOrbiterJ * 8778681366114628045U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2859452497983106129U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7196557924940881076U;
            aOrbiterH = RotL64((aOrbiterH * 14415389907490256711U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 930127943984174668U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15673596916054795749U;
            aOrbiterK = RotL64((aOrbiterK * 7505660488733199479U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16673140529110941163U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2258448294877833760U;
            aOrbiterE = RotL64((aOrbiterE * 1821550319748977445U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6870209259643931219U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 12749790107942194104U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4871407285968611725U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17131374134617173866U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6426448390733751612U;
            aOrbiterG = RotL64((aOrbiterG * 12490559588384058417U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15592826434339731146U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14182944418026376183U;
            aOrbiterB = RotL64((aOrbiterB * 7218860482893476233U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17447476498234456596U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 972861017466618022U;
            aOrbiterC = RotL64((aOrbiterC * 9610670431280153921U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13185309156950240549U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14442284480744008537U;
            aOrbiterD = RotL64((aOrbiterD * 2907844852105175837U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 7816745313858811117U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11450949896247900941U;
            aOrbiterF = RotL64((aOrbiterF * 18317765298694454463U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 44U) + aOrbiterI) + RotL64(aOrbiterF, 41U)) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterK, 51U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 26U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aCross, 22U) + aOrbiterE) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterF, 60U));
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 29U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterD, 11U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21377U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 20577U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19550U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 20364U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 19U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = (aWandererI + RotL64(aCross, 6U)) + 2672739400294801233U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 23U)) + 8475624545015101850U) + aNonceWordA;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 11U)) + 1252755112289831257U) + aNonceWordK;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 29U)) + 7938039507649183387U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 57U)) + 8167413146948861022U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 53U)) + 17712313989694374353U) + aPhaseEOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aScatter, 27U)) + 7637042279892596975U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 47U)) + 15770412950033467341U;
            aOrbiterA = (aWandererC + RotL64(aCross, 43U)) + 3951812021898608685U;
            aOrbiterE = ((((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 8656983621098246507U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 17943342344730687317U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3087677463651608668U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 16493240011924342788U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16898479041530771871U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7750923317452683057U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2185924841611106546U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 708072658250726381U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14676868738946722416U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6849098251696302393U;
            aOrbiterG = RotL64((aOrbiterG * 2599806275837778069U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17817755047153606419U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9900465270314068757U;
            aOrbiterI = RotL64((aOrbiterI * 9267925873983176685U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11380000891112113701U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15930503831156546113U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 14450535035065393845U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5439183530402949780U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3731802052051181843U;
            aOrbiterA = RotL64((aOrbiterA * 7739775058947333169U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 14432344583247783600U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16192098795467501636U;
            aOrbiterE = RotL64((aOrbiterE * 6285466374319549047U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1523272672673940290U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7462092373525113574U;
            aOrbiterF = RotL64((aOrbiterF * 15067751170235540679U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4612539457663050732U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7959404391235752875U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 137834571274065007U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11853468935131763944U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3575434598998149168U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16971321675425065041U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6135993440654291404U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2672739400294801233U;
            aOrbiterJ = RotL64((aOrbiterJ * 12891757276825641567U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 47U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterG, 43U)) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 41U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 34U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterK, 37U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 51U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aPrevious, 50U) + RotL64(aOrbiterF, 13U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterA, 29U));
            aWandererK = aWandererK + ((((RotL64(aCross, 21U) + RotL64(aOrbiterA, 20U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 5U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 39U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23689U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 22694U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22838U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23234U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 11U)) + 2915859148137000694U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 41U)) + 210680583721444425U) + aNonceWordI;
            aOrbiterA = ((aWandererK + RotL64(aCross, 13U)) + 6668118118775650387U) + aPhaseEOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 50U)) + 15794200818099010989U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 6565076707062828369U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 16323164497808856719U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 7965435318816716560U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 53U)) + 7390281030573369017U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 19U)) + 2269738866911824875U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 29U)) + 9664014216039993873U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererI + RotL64(aCross, 48U)) + 18284857398028357633U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 367667619795303009U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7935945060956274197U;
            aOrbiterA = RotL64((aOrbiterA * 5481786693511955209U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16683666162337789540U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10655658270998102390U;
            aOrbiterC = RotL64((aOrbiterC * 15231596813382239841U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8307037916581540297U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 3247742749860703524U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 15052136713218656641U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10446792483683818139U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16374602929344972364U;
            aOrbiterF = RotL64((aOrbiterF * 12599903932725787599U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2411334498322777183U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1093701164116833765U;
            aOrbiterJ = RotL64((aOrbiterJ * 13129220206835381729U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17018480952982840635U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17348395690080029814U;
            aOrbiterE = RotL64((aOrbiterE * 6212591395713433257U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16111252311283623152U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 12776492920397785951U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6136009241593081821U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12214538600808144816U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10043377462096783363U;
            aOrbiterG = RotL64((aOrbiterG * 14639467375095185877U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5101561512438055661U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3683207847147603335U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14355438383379198639U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14446947359104987749U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7596096688268335354U;
            aOrbiterI = RotL64((aOrbiterI * 13522935803383107145U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14015424109468938015U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2915859148137000694U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3653144205211106817U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 10U);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 44U) + RotL64(aOrbiterH, 13U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterD, 41U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterC, 47U));
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterI, 54U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterB, 29U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterF, 43U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterK, 36U));
            aWandererD = aWandererD + ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31198U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 29515U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29874U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28546U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 50U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = ((aWandererH + RotL64(aCross, 47U)) + 17936518874386450467U) + aPhaseEOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 13722737841589910344U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 56U)) + 11774969167948715796U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aScatter, 51U)) + 3640101505680493777U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 1369495382725650822U) + aNonceWordA;
            aOrbiterG = (aWandererE + RotL64(aIngress, 41U)) + 11827310354654653345U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 13U)) + 186037671377175394U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 20U)) + RotL64(aCarry, 19U)) + 11428829344234627340U;
            aOrbiterH = (aWandererG + RotL64(aCross, 3U)) + 2275016369870029068U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 37U)) + 15471646673734798328U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 35U)) + 12172082573115640145U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6626736341348283154U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12220614992483863623U;
            aOrbiterJ = RotL64((aOrbiterJ * 8137086205714097487U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 13157102324253760215U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4143587482368093601U;
            aOrbiterC = RotL64((aOrbiterC * 5060677690991506895U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11007575246013796426U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11721585930088637162U;
            aOrbiterG = RotL64((aOrbiterG * 15009627907125738519U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5720789204450196217U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3094696226821431648U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4412033981712165541U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14675830108100986773U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9444071495289719645U;
            aOrbiterK = RotL64((aOrbiterK * 10983136361953366557U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5106753847015199956U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7585421898593510010U;
            aOrbiterH = RotL64((aOrbiterH * 140996914192351011U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11746948407655524690U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16336323220286344483U;
            aOrbiterI = RotL64((aOrbiterI * 6590417628835864497U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8030445186765781136U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 276034088015165891U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7626025612710225099U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8116955322602209153U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5704503350608834450U;
            aOrbiterF = RotL64((aOrbiterF * 7049558959583832449U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8063875087087055875U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1111816778196345760U;
            aOrbiterE = RotL64((aOrbiterE * 13820440198677609571U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7702895879089714461U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17936518874386450467U;
            aOrbiterB = RotL64((aOrbiterB * 12767279443267850009U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 58U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 28U) + aOrbiterG) + RotL64(aOrbiterB, 5U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 56U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 21U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 11U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aCross, 26U) + RotL64(aOrbiterA, 51U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 23U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aCross, 39U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + aNonceWordP) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterI, 44U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordH);
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

void TwistExpander_BasketBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC882F5EC0CC1A02BULL + 0xE6EB644AC639F1A6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCBBF911277BCAFFBULL + 0xBE0D68CC08364D7EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF300D2D5D0EAA0EFULL + 0xA8B42776174C549FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x88784515813EFEBBULL + 0xC3303978419065C9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE5F14791D02F473FULL + 0xA0347E8BA7DC9CA2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x847ECD52828EFB19ULL + 0xCDB88CC746B9DD74ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB2D57436035C6E85ULL + 0xAD4176A79352FFB0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE822DDC5AE38B783ULL + 0xD1640B9B8D56BC01ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xABC9F2380880BCC1ULL + 0xD5776BD74579DD06ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAD2922B410C56D15ULL + 0x825B440F3F709643ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC4703449599C1D1DULL + 0x86483CC3C2412E4BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA1B84C248BD36B1DULL + 0xD1A3D7672259D66EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFD2A3C71B5B2CC8DULL + 0xBD6653B9034B75EFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA305416F45CD6D1DULL + 0xF019DF40BFC19AD4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBFD0B46FE31D941DULL + 0xB7E2A1D107F422E6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x813DAF04072DD381ULL + 0x8169970651A75F4FULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 183U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((aIndex + 540U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1485U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 4925U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 28U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aCross, 47U)) + 5576732410244514238U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 2833808925935929629U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 41U)) + 3670188682914544792U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 15759072378887814995U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 53U)) + 13934007231137439994U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 44U)) + RotL64(aCarry, 27U)) + 11022225696007690512U) + aNonceWordA;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 37U)) + 16989177104453635790U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 39U)) + 9256930045263527091U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 23U)) + 17788596104417068290U;
            aOrbiterE = (aWandererC + RotL64(aCross, 14U)) + 17044369456673337625U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 57U)) + 1310908395523250343U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12067065689034065422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15130844248737512262U;
            aOrbiterK = RotL64((aOrbiterK * 9409499577465934107U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14532689204495587494U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8198147292120244178U;
            aOrbiterD = RotL64((aOrbiterD * 1418356389507740991U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5485494458627163347U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10830008207150307611U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6526039534042499457U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17770065502486618029U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6397859353395335459U;
            aOrbiterF = RotL64((aOrbiterF * 14286997752368893825U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5128700697381508319U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7103394110057060499U;
            aOrbiterA = RotL64((aOrbiterA * 5053680689949149633U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16024401282261796979U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12818445221897253410U;
            aOrbiterG = RotL64((aOrbiterG * 11450004517784155405U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13386978409145916350U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16740821954556699503U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5376430209628515105U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 313978038530994953U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1355733685461795345U;
            aOrbiterB = RotL64((aOrbiterB * 15955927322082619735U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12590581077253956064U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2298195367575496005U;
            aOrbiterI = RotL64((aOrbiterI * 17512801361187006363U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11847450675712272468U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5914296379577670282U;
            aOrbiterH = RotL64((aOrbiterH * 14574813500616811367U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 16901317262621287065U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5576732410244514238U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 4514943876091531567U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 38U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 37U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 47U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 53U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterH, 60U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 57U)) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 13U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterF, 22U)) + aPhaseFWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 11U)) + aOrbiterB) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterB, 5U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterC, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10429U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10708U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9567U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((aIndex + 9747U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aCross, 39U)) + 7632760812370906911U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 53U)) + 6007174525479723089U) + aNonceWordM;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 11U)) + 3362829642521821048U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 18009548556107978286U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aCross, 6U)) + RotL64(aCarry, 39U)) + 17880909432272697327U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 15961567935420752568U) + aNonceWordL;
            aOrbiterE = (aWandererG + RotL64(aScatter, 3U)) + 10136559064656837921U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 57U)) + 17622019364405410277U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 35U)) + 6927494824421416306U;
            aOrbiterI = (aWandererD + RotL64(aCross, 28U)) + 7125170407794874847U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 19U)) + 12342273503071032250U) + aNonceWordN;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14997696377476124836U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14874498694181230698U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4026127545746010937U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2549397729130885686U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4217995818662767955U;
            aOrbiterG = RotL64((aOrbiterG * 5525525344485251063U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4706089044415442525U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17983900172670031015U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 541552737180932879U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1904937798143929988U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10620877287033139483U;
            aOrbiterE = RotL64((aOrbiterE * 16711012562024287213U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15681091173163181525U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2655543246639000084U;
            aOrbiterK = RotL64((aOrbiterK * 16686375598149755947U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2647895110857289213U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5581609212017175954U;
            aOrbiterA = RotL64((aOrbiterA * 15330263616699031311U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13609076329627787987U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6244266279516622070U;
            aOrbiterJ = RotL64((aOrbiterJ * 12488345779236971095U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5289624364508923581U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16351476803965903112U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9012522724650442597U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2731198704224650506U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4177455951984414332U;
            aOrbiterH = RotL64((aOrbiterH * 2567165277406175517U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3031687737578718714U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 4866790771642413883U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1139524449666360541U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12903299652398385014U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7632760812370906911U;
            aOrbiterD = RotL64((aOrbiterD * 7924544687662448385U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 10U);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + aNonceWordI);
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 26U) + aOrbiterH) + RotL64(aOrbiterG, 21U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterK, 38U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 11U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 35U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 53U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterD, 19U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 38U) + aOrbiterF) + RotL64(aOrbiterB, 48U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 22U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13151U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15403U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11927U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12186U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 21U)) ^ (RotL64(aIngress, 60U) + RotL64(aCross, 47U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aCross, 50U)) + 4204560462077827182U) + aNonceWordE;
            aOrbiterA = ((((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 6572370199668594039U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 41U)) + 15958999876732622825U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 19U)) + 9969349486879280377U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 39U)) + 15450238998293956181U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 27U)) + 9128619863683138259U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 24U)) + 5691270563628979565U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 43U)) + 5901029710568933106U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 10442738941988588834U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 29U)) + 3508116020325721993U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 13221917083569767259U) + aNonceWordC;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11627915460377128176U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17858261365514253433U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7535577636975884641U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4294837988806295989U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11242915481585070249U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 17540688242763829319U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13030663829236027109U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7451948220723185149U;
            aOrbiterA = RotL64((aOrbiterA * 5191778587712222029U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5575508866505031037U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 5161096033789876794U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16843827915802461797U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3980482740649505122U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11188906150207270241U;
            aOrbiterI = RotL64((aOrbiterI * 408550837615188413U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4435504916461645189U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9970252853543702833U;
            aOrbiterG = RotL64((aOrbiterG * 5829143716916091997U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3766347619186305854U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11004616087340082895U;
            aOrbiterH = RotL64((aOrbiterH * 14469267845747063735U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17600791542296175812U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2556224430252009744U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 14469426539907112137U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8575243768637573595U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9439245636611632007U;
            aOrbiterC = RotL64((aOrbiterC * 7519813655810877223U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8376104683205641052U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16877378648551624650U;
            aOrbiterJ = RotL64((aOrbiterJ * 13806644088125335467U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8060622208866138617U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4204560462077827182U;
            aOrbiterD = RotL64((aOrbiterD * 8407034104111382011U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 56U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 53U)) + aOrbiterF) + aNonceWordF);
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterI, 13U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 6U) + aOrbiterC) + RotL64(aOrbiterA, 4U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 19U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterK, 24U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterG, 41U)) + aNonceWordO) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + aNonceWordP);
            aWandererK = aWandererK + (((RotL64(aPrevious, 10U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 6U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16895U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 21410U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17203U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((aIndex + 17190U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 42U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aIngress, 11U)) + 10336802574069791273U) + aNonceWordP;
            aOrbiterF = (aWandererC + RotL64(aCross, 23U)) + 169025388197058936U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 58U)) + 6541354188379168846U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 5U)) + 16223920526599306104U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 12756613707692514808U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 5082475548176484035U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 29U)) + 4907435526952698526U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 56U)) + RotL64(aCarry, 5U)) + 14236627073831834337U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 41U)) + 11502511046130497584U) + aNonceWordE;
            aOrbiterH = (aWandererF + RotL64(aIngress, 19U)) + 3679044835550219497U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 47U)) + 11254838916686736746U) + aPhaseFOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 10582608424233200966U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10449735026385340313U;
            aOrbiterG = RotL64((aOrbiterG * 7363770199734997411U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4628253464169957835U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17664454668473204465U;
            aOrbiterI = RotL64((aOrbiterI * 4234720298731378527U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3798386391743884889U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1379331161819246587U;
            aOrbiterE = RotL64((aOrbiterE * 13086160171095077295U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9816600392407327227U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 16781971616348376878U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12503867584828289879U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4807797577690520554U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2492057261148595922U;
            aOrbiterJ = RotL64((aOrbiterJ * 9453302540675483005U), 37U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 7909676419643119585U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 256053568910383007U;
            aOrbiterC = RotL64((aOrbiterC * 11965085163352053161U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16179914439220412472U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3968867762761955845U;
            aOrbiterH = RotL64((aOrbiterH * 7473632378251893139U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7474832923901283742U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4736994731050735779U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 9839654409121414047U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 596484364660389193U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13822222274464306169U;
            aOrbiterA = RotL64((aOrbiterA * 1723502278319885511U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16307920280681985443U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3505106171801702915U;
            aOrbiterF = RotL64((aOrbiterF * 8479675421552861243U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4987142580981135150U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10336802574069791273U;
            aOrbiterD = RotL64((aOrbiterD * 2670706512498539705U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterF, 53U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 28U) + aOrbiterC) + RotL64(aOrbiterJ, 30U));
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterK, 41U)) + aPhaseFWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 35U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 23U)) + aNonceWordK) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 30U) + RotL64(aOrbiterH, 21U)) + aOrbiterE) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 46U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterD, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25997U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 27240U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26152U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 26093U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 42U)) ^ (RotL64(aIngress, 13U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererC + RotL64(aScatter, 11U)) + 14686411261024919129U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 53U)) + 7514582233957632005U;
            aOrbiterH = (aWandererA + RotL64(aCross, 29U)) + 6520710480103365552U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 44U)) + 1983621978676188036U;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 9003524602590749672U) + aPhaseFOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 6428568234045228995U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 8656552687136446989U) + aNonceWordF;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 41U)) + 16916248288415922490U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 57U)) + 9740237548002535784U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 23U)) + 907561000814618339U) + aPhaseFOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aScatter, 14U)) + 4751108900841197631U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 167774899400732287U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11907484918310854962U;
            aOrbiterH = RotL64((aOrbiterH * 7213139491146402985U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14910318613649863924U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14882888155751455276U;
            aOrbiterI = RotL64((aOrbiterI * 11394136445442060201U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16175942562693781908U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11022373758481651102U;
            aOrbiterF = RotL64((aOrbiterF * 6836331461393816027U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12548405399045031548U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10850926364556828443U;
            aOrbiterG = RotL64((aOrbiterG * 16231561687709867431U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13391684887911141790U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 14648937281264822988U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6533299316940026059U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 8298658887198526821U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13822977698661348891U;
            aOrbiterC = RotL64((aOrbiterC * 17769262972278410937U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7505646847564645719U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3238749538197209166U;
            aOrbiterK = RotL64((aOrbiterK * 15394286542600778567U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15853506915123709257U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8426329899401071248U;
            aOrbiterD = RotL64((aOrbiterD * 1330397096577715113U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14848635392815613098U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3549927798350175044U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1899044682313056949U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1798973117197750802U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13056711228618953977U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 9102877396419306689U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1395893547965799281U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 14686411261024919129U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 17075377081365066067U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterH, 48U)) + aNonceWordK);
            aWandererH = aWandererH + ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 19U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterF) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 29U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 6U) + aOrbiterJ) + RotL64(aOrbiterC, 53U));
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 51U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterE, 56U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterC, 35U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 36U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 56U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29893U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 28087U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28950U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 30097U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 18U)) + 6916817163240024692U) + aNonceWordF;
            aOrbiterI = (aWandererE + RotL64(aIngress, 47U)) + 14554930751292077817U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 41U)) + 1098305064484336101U;
            aOrbiterK = (aWandererG + RotL64(aCross, 27U)) + 12192821172420471527U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 2435134991707318845U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 1896745368738512624U) + aNonceWordP;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 29U)) + 1114996424222923873U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 50U)) + RotL64(aCarry, 39U)) + 9839135798371512656U;
            aOrbiterG = (aWandererA + RotL64(aCross, 5U)) + 8037967239603177043U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 3U)) + 15185468738487237432U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 57U)) + 4912098316394854543U) + aPhaseFOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13142688607850380888U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4507379759608945839U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2989332387754215967U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7299006009652289342U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5390655277207053627U;
            aOrbiterF = RotL64((aOrbiterF * 10973744708856143715U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6744737023577785725U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15539737698867067285U;
            aOrbiterE = RotL64((aOrbiterE * 4686092035261336911U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13329866734681377952U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13284937458969166257U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3965985432462699445U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8695002088915702168U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3858059421620839286U;
            aOrbiterD = RotL64((aOrbiterD * 9559783727301092937U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6609163873243179836U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9416165620556710540U;
            aOrbiterG = RotL64((aOrbiterG * 240385043740268229U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1578449067529000433U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14309000104419489303U;
            aOrbiterH = RotL64((aOrbiterH * 7599078306153684729U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15785180680737461320U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10099222679918382021U;
            aOrbiterC = RotL64((aOrbiterC * 2012232597046182581U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10666287769220108179U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 13648647399222807034U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 10772381733103127201U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9292207828896796810U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9155130791347443553U;
            aOrbiterI = RotL64((aOrbiterI * 16838229790655977057U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11334395119119245556U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6916817163240024692U;
            aOrbiterK = RotL64((aOrbiterK * 9640906826978028183U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 26U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 18U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aCross, 53U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 37U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aIngress, 20U) + aOrbiterB) + RotL64(aOrbiterD, 29U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 53U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterE, 21U));
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterE, 5U)) + aOrbiterI) + aNonceWordG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterF, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordA);
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

void TwistExpander_BasketBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8A30D83D938DDDB5ULL + 0xD6D45141B93A9344ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA85E4B3F110B0FC9ULL + 0x9E8F6036F851DB75ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD1FD145829682A19ULL + 0x9F99964F0C08FE53ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9D6FD9AD39EF6FF7ULL + 0x9CC2D6A972E322FCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x83E1B5BA2DCABDCBULL + 0xA6DDA1A550F7487AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE34FE0E08E7066D5ULL + 0xAC04796C59FAA9CCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD11C8BAA60D90E45ULL + 0x861243C0E3AFF940ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAF66E9BA460D6F3DULL + 0x89E5F8628088CF2DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8BD7837953961F8BULL + 0xEEEFA2AEE562F333ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDC36F6970FC89BA7ULL + 0x809A27B3D90D610FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x966A4E726B275CE3ULL + 0x90E13EAD6FCC0C62ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x92F624B5AD666AEBULL + 0xA581AC1A1532FF78ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8AB0CC1E42C15B09ULL + 0x8F055C3DBB4CDE13ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD2F1E3BD6068632FULL + 0xBF01B42827AABF79ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD015C2E9AA2D9DABULL + 0xF7FD64689A920654ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE22280E1B660FFEFULL + 0xC3281BD35604FA8BULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3667U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 210U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2974U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1483U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 40U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 13714409587461539863U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 57U)) + 14101156723903265839U) + aNonceWordF;
            aOrbiterF = (aWandererF + RotL64(aScatter, 43U)) + 7063754562895369001U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 12320578575245519386U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 22U)) + 11744826789631008424U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 8744816505096675597U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 29U)) + 10405435520084528645U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 19U)) + 1463157688070683543U) + aNonceWordC;
            aOrbiterG = (aWandererI + RotL64(aCross, 12U)) + 12379603577919617703U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 3U)) + 1343439118031348146U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 35U)) + 16118850268070235540U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14116264435819277136U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5251698273012432109U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1495818611622063967U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14806408656041403829U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11569345414052398227U;
            aOrbiterE = RotL64((aOrbiterE * 9913158908301414861U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17063874769147888574U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9927420478679581917U;
            aOrbiterJ = RotL64((aOrbiterJ * 9042782809534196563U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2550285599827162167U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17801534123304996448U;
            aOrbiterH = RotL64((aOrbiterH * 2160836889363614721U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6456685241021762041U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17064208177372969289U;
            aOrbiterI = RotL64((aOrbiterI * 13726627607233302493U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18279938244131982650U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8211002229712129419U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12931373380977640645U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12795832560781931767U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 286378504074349650U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 85453101173293509U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5835304250436889513U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12704972686724379659U;
            aOrbiterA = RotL64((aOrbiterA * 1198789639656336053U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12555700587254295099U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6740149669657971715U;
            aOrbiterC = RotL64((aOrbiterC * 9376048577305482691U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1541392147096889431U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16891341703173286949U;
            aOrbiterD = RotL64((aOrbiterD * 697452963711223355U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8811637585092392653U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13714409587461539863U;
            aOrbiterB = RotL64((aOrbiterB * 2578939920876994763U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 36U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterC, 30U)) + aPhaseFWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 54U) + RotL64(aOrbiterK, 41U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 47U)) + aNonceWordB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterE, 39U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterH, 50U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 34U) + aOrbiterF) + RotL64(aOrbiterE, 53U));
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterI, 43U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 11U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 58U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5995U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10041U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5732U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((aIndex + 9702U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aCross, 53U)) + 9751314027302668907U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 12175450995523107056U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 26U)) + 17519694958730119552U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 9093525527925682263U) + aPhaseFOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 37U)) + 3713831321786810138U) + aNonceWordJ;
            aOrbiterC = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 10108355209191835040U) + aNonceWordA;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 35U)) + 12956307447311314768U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aIngress, 23U)) + 1904298513945877359U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 60U)) + 4658049993308574460U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 41U)) + 9826333658248851902U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 21U)) + 12058666914724365134U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2516574707110528099U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13335308331049750235U;
            aOrbiterA = RotL64((aOrbiterA * 5880227828760598587U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8230749255538495304U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16536559486797811486U;
            aOrbiterF = RotL64((aOrbiterF * 7097036838156464969U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12387639130570188998U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 8459259798142872020U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 8001346480955847013U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16083784052002800300U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1957284290736468379U;
            aOrbiterE = RotL64((aOrbiterE * 5046501301740813065U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7349538179311335863U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16395170077006105258U;
            aOrbiterG = RotL64((aOrbiterG * 4230485452156662763U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3317652065873784068U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5517155804799120700U;
            aOrbiterK = RotL64((aOrbiterK * 9789270651974719183U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5568525912112200094U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9334250662962319598U;
            aOrbiterD = RotL64((aOrbiterD * 5034887614541768961U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5641394627075994165U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13524971148931512745U;
            aOrbiterC = RotL64((aOrbiterC * 3699457147759854357U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15124425790244392471U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7896294947517723306U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7526632360108129915U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15241686066829586263U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12099799118961857495U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10456171163074630861U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17529688916595727188U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9751314027302668907U;
            aOrbiterB = RotL64((aOrbiterB * 521888849578281715U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 14U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 47U)) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + aPhaseFWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 34U) + aOrbiterI) + RotL64(aOrbiterB, 5U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterG) + aNonceWordN) + aPhaseFWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 37U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterI, 27U));
            aWandererF = aWandererF + ((RotL64(aIngress, 36U) + RotL64(aOrbiterF, 10U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11749U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13662U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12791U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((aIndex + 14241U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 34U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 18U)) + RotL64(aCarry, 47U)) + 6342299552323486695U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 12692748514781367538U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 57U)) + 8202639945493229155U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 41U)) + 4439975701793231639U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aIngress, 27U)) + 16774235182859553759U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 8764155413335405667U;
            aOrbiterA = (aWandererK + RotL64(aCross, 35U)) + 7167848811974967685U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 20U)) + 16768278912125334220U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 39U)) + 9090838954826296201U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 3U)) + 7644075729758006298U) + aNonceWordO;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 43U)) + 17326182797908071215U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16158809721888137555U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8029938783858263694U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 12628072435324195483U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 8716553521415553404U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7012599977009208840U;
            aOrbiterK = RotL64((aOrbiterK * 8775355876188948851U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13250558696578541499U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13705957059101025396U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16889495686487056367U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2796775206291902461U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13741676263512390669U;
            aOrbiterC = RotL64((aOrbiterC * 10455782033465595947U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1691908360612389252U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4114939415206031540U;
            aOrbiterF = RotL64((aOrbiterF * 2797401802892718297U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2374911514440738727U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12377616933668803091U;
            aOrbiterH = RotL64((aOrbiterH * 2505164835116651215U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 681094033415259645U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13841322124900463362U;
            aOrbiterI = RotL64((aOrbiterI * 4210414203856902329U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18082983557580381338U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15731122225678626778U;
            aOrbiterB = RotL64((aOrbiterB * 7785999919955613789U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2084336993254383330U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3600882019682875370U;
            aOrbiterA = RotL64((aOrbiterA * 2977569829649654329U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11436602278656592334U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5775886971784627864U;
            aOrbiterD = RotL64((aOrbiterD * 6765942246225582787U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 17120308925134658794U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6342299552323486695U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 5788669985396507227U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 4U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterA, 51U)) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterE, 13U));
            aWandererH = aWandererH + ((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterA, 5U));
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterF, 27U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterI, 42U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 22U) + aOrbiterB) + RotL64(aOrbiterF, 11U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterD, 21U)) + aNonceWordF) + aPhaseFWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 39U)) + aOrbiterI) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererG, 42U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordF;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21740U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 18224U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16601U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19902U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCross, 3U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 13U)) + 13924571355038625040U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 5U)) + 16328300979357156658U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 43U)) + 3947771961206012461U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 52U)) + 15428284250569311285U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 5777369485254032486U) + aNonceWordL;
            aOrbiterH = ((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 16813320300717644673U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 41U)) + 16689933050200758251U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 11U)) + 1856422419049390708U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 18214498743831925517U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 60U)) + 18278550878494094923U) + aNonceWordK;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 37U)) + 797712062039591797U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15854849439012341347U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 996882939768167773U;
            aOrbiterK = RotL64((aOrbiterK * 14936703950807908575U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3005829974130671692U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8793495343509953906U;
            aOrbiterA = RotL64((aOrbiterA * 14065479348374612031U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7710453029930631112U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9511995836117707047U;
            aOrbiterH = RotL64((aOrbiterH * 7250766204781428201U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 670902975693341744U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9045820304668279777U;
            aOrbiterJ = RotL64((aOrbiterJ * 18373074917532639027U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12417212387607119470U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12816983560669985622U;
            aOrbiterG = RotL64((aOrbiterG * 8406003970221889847U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17245432086377688540U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6806521945548502014U;
            aOrbiterI = RotL64((aOrbiterI * 11335859481858640857U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8947500746292365294U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4468060468522895852U;
            aOrbiterE = RotL64((aOrbiterE * 7022481284816599797U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9892975931958803992U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 3042599331526937836U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 3308512896171443645U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12991568221485810891U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 8551331172836260315U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 4509997595920847057U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 183547209633334407U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17275712817092769452U;
            aOrbiterC = RotL64((aOrbiterC * 15677355290000929085U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12743863879392372723U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13924571355038625040U;
            aOrbiterF = RotL64((aOrbiterF * 11966689345179279407U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterH, 39U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterE, 30U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterI, 53U)) + aNonceWordG);
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 41U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aCross, 52U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 43U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 22U)) + aNonceWordC);
            aWandererE = aWandererE + ((((RotL64(aCross, 19U) + RotL64(aOrbiterK, 35U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25098U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23062U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22969U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((aIndex + 26645U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 22U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 4751694786009671052U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 57U)) + 16362725160370844224U) + aNonceWordC;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 35U)) + 6360885380915941057U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 3U)) + 5154536007972297036U) + aPhaseFOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 43U)) + 9362540581874808253U;
            aOrbiterA = (aWandererE + RotL64(aCross, 41U)) + 13902493871525612934U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 18U)) + RotL64(aCarry, 47U)) + 10208452885367546542U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 11U)) + 3117030377279160998U) + aNonceWordG;
            aOrbiterF = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 17286247690414027870U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 47U)) + 3930314320040949141U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 54U)) + 7289525252391668404U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3434167955466809185U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17852573095128575663U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1485660158767033425U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6137259687928853253U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13992510605237574698U;
            aOrbiterA = RotL64((aOrbiterA * 15346263295995333395U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6470556523400123474U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4333255670390099293U;
            aOrbiterH = RotL64((aOrbiterH * 11089933812030082647U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 7700424876430257995U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16920736951239453071U;
            aOrbiterE = RotL64((aOrbiterE * 8920407493132380497U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 1635071690430295730U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9966700845966398620U;
            aOrbiterD = RotL64((aOrbiterD * 17210048121896546867U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9833458070123027075U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1990346556486746432U;
            aOrbiterI = RotL64((aOrbiterI * 8704943923474148699U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13339523466436517327U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5018264760406215603U;
            aOrbiterC = RotL64((aOrbiterC * 2769197961801783627U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 123427497520755346U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4535841104215792886U;
            aOrbiterF = RotL64((aOrbiterF * 1417676310539177131U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3525925567359163763U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3273741481392187986U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16116160744647235811U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6230742908784102407U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7578784912496239362U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2614448818452560369U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14669810330213234082U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4751694786009671052U;
            aOrbiterG = RotL64((aOrbiterG * 9583151676882991817U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 24U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterF, 53U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterE, 60U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 13U)) + aOrbiterB) + aNonceWordB);
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 23U)) + aNonceWordM) + aPhaseFWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 30U) + aOrbiterI) + RotL64(aOrbiterK, 35U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 21U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterI, 28U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 11U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterG, 57U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 44U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31222U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 32170U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31190U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31787U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 53U)) + 16124889768301047791U) + aNonceWordH;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 37U)) + 11912338587186717280U;
            aOrbiterF = (aWandererF + RotL64(aCross, 46U)) + 8594012868813114354U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 27U)) + 18281043566156682815U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 16853106130200942302U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 41U)) + 2611212958619673086U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 29U)) + 18039472325066855180U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 14495785571345122046U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 60U)) + RotL64(aCarry, 11U)) + 4556063793412832418U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 5U)) + 14896419970271244358U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 21U)) + 880028529183500036U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2379557167489415783U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11854373946064529806U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 150755294320438887U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1487252775956449964U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12777924204511625545U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1366019527386994789U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15998631485222477969U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8864212892296191613U;
            aOrbiterK = RotL64((aOrbiterK * 579242788050369815U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17069347835763226743U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7443008171694679791U;
            aOrbiterH = RotL64((aOrbiterH * 748894368884566607U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17334256152350782002U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8986626119086556393U;
            aOrbiterD = RotL64((aOrbiterD * 2258172145924120235U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8528180968228358674U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12702290928064582589U;
            aOrbiterG = RotL64((aOrbiterG * 15673603224146737631U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7742438100860023610U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3729687240959702198U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3756794766163746783U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 426129097367382096U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16782175452274911213U;
            aOrbiterB = RotL64((aOrbiterB * 1041477289638333659U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5942016166948841079U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5260815086125551703U;
            aOrbiterE = RotL64((aOrbiterE * 1603799103692438147U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11732742583346900772U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17182924380693084401U;
            aOrbiterC = RotL64((aOrbiterC * 14858685629471497071U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8539335803784852017U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16124889768301047791U;
            aOrbiterA = RotL64((aOrbiterA * 6607245691919237755U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 48U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterD, 13U)) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 26U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 29U));
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterC, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterF, 54U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 41U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 21U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 51U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterF, 58U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ aNonceWordM;
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

void TwistExpander_BasketBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5387U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 6952U)) & W_KEY1], 6U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1169U)) & W_KEY1], 30U) ^ RotL64(mSource[((aIndex + 3251U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 4U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 52U)) + RotL64(aCarry, 43U)) + 8402620908307642697U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 47U)) + 11347672014525086047U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 2816462912503401876U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 43U)) + 6940159795470696093U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 21U)) + 9134692490095883851U) + aPhaseCOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 4U)) + 4999455497008026526U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 39U)) + 5992451460350651332U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 13U)) + 3417087346651371924U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 3612773820086198270U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 463398077083428570U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11249391303705089012U;
            aOrbiterB = RotL64((aOrbiterB * 7106735772303292983U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17027535139825739501U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 568131384979596481U;
            aOrbiterE = RotL64((aOrbiterE * 5683451044852895957U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4793712537158004047U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 10415170179135963622U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13729564030210361415U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2391473979460065630U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4240058362680064261U;
            aOrbiterD = RotL64((aOrbiterD * 12375884373396400889U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9963957011090031698U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3325305624067445525U;
            aOrbiterK = RotL64((aOrbiterK * 3128542681461806309U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2094945647665114693U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10703615640774042674U;
            aOrbiterJ = RotL64((aOrbiterJ * 12641986098450423751U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3768738815518590289U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15021301790376706827U;
            aOrbiterH = RotL64((aOrbiterH * 14445850924223550339U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10571246886181608316U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 5130325144599151793U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3185251943547657467U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 8617523421720966373U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16574597770835250074U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1759209403428937799U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 14U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterE, 52U)) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterF, 35U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 27U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterA, 20U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 30U) + aOrbiterJ) + RotL64(aOrbiterB, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8931U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10113U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12077U)) & W_KEY1], 26U) ^ RotL64(aKeyRowReadB[((aIndex + 11603U)) & W_KEY1], 41U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 50U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 12849591986267890852U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 19U)) + 8232614804696815750U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aScatter, 58U)) + 12141567259210877281U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 23U)) + 2928641981037885644U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 980733350554783938U;
            aOrbiterA = (aWandererG + RotL64(aCross, 11U)) + 2683985177993350746U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 43U)) + 14532148403815527355U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 7736296629433884203U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 38U)) + 10428437770166310549U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18327174144859461029U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6810436935194432002U;
            aOrbiterC = RotL64((aOrbiterC * 2715987179577753597U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12606153309690753435U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17123256945895150555U;
            aOrbiterE = RotL64((aOrbiterE * 13469111258504672565U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9057777759026189541U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16478485918911194442U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11054247078884894131U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 18064460487552100483U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11477276762421684083U;
            aOrbiterJ = RotL64((aOrbiterJ * 3886501230380184395U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18318375441973295081U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13849305985380030986U;
            aOrbiterH = RotL64((aOrbiterH * 12962140243967824959U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10240409420338313641U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 18360586077779529086U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18196875422391501927U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16801797158622424257U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4950305991208513887U;
            aOrbiterD = RotL64((aOrbiterD * 4437082499761416951U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15790878572843321918U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9808781805065559728U;
            aOrbiterA = RotL64((aOrbiterA * 9394280083159162953U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11974996650410830731U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4955004489435232515U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13301966529515483085U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 44U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 26U) + RotL64(aOrbiterD, 23U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 3U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterE, 57U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 46U) + RotL64(aOrbiterA, 40U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE) + aPhaseCWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 53U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22855U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 22095U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21060U)) & W_KEY1], 38U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 24204U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCross, 14U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 26U)) + RotL64(aCarry, 37U)) + 12775735908960052604U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 11791373812080296887U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 5537362877706057303U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 11U)) + 2023912048504189380U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 47U)) + 17668828109963766893U;
            aOrbiterG = (aWandererG + RotL64(aCross, 51U)) + 558908629933941224U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 20U)) + 1479633119685446888U) + aPhaseCOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 39U)) + 15460320397843364063U) + aPhaseCOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aScatter, 43U)) + 10059749397555469054U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9987633811929693924U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10087337844580228269U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13817142288940843815U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4446204415503364254U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15106063243302192717U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9430197906134676162U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1226048679997253363U;
            aOrbiterF = RotL64((aOrbiterF * 14247538885252664127U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10611580584157624739U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 3137391249289641509U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5462682413239873181U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9327201928815412810U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7890659377013147073U;
            aOrbiterH = RotL64((aOrbiterH * 13827717178378062047U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10675114832750356941U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8804440385852327267U;
            aOrbiterG = RotL64((aOrbiterG * 8520671775587260601U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12871947817782057116U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11015991745792051390U;
            aOrbiterJ = RotL64((aOrbiterJ * 17152451500505815031U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6320437975845673731U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 702457937087191287U;
            aOrbiterE = RotL64((aOrbiterE * 17491257114676739589U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16629064896250312921U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6054107387816339103U;
            aOrbiterC = RotL64((aOrbiterC * 6983767878966747219U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 20U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 60U) + RotL64(aOrbiterH, 30U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterB, 57U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterE, 26U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 19U));
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterA, 13U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + aPhaseCWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 56U) + RotL64(aOrbiterA, 47U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29778U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((aIndex + 26311U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32645U)) & S_BLOCK1], 26U) ^ RotL64(mSource[((aIndex + 31968U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 36U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererD + RotL64(aIngress, 43U)) + 2783898056762489197U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 35U)) + 7177192902873343053U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 22U)) + 12254703232691980774U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 15446547245691219559U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 888475203006174856U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 39U)) + 3649183529366307877U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 4642631047518805167U) + aPhaseCOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aPrevious, 18U)) + 6108329730724782250U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 53U)) + 8334054653023816636U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5891895375031474350U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3176720746238477862U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1869961473768307911U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6111038696865301675U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11914998302228682704U;
            aOrbiterH = RotL64((aOrbiterH * 11738924766359642853U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17005063057791320948U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 18333780598768130670U;
            aOrbiterE = RotL64((aOrbiterE * 5416759844884107303U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 2056115016443263153U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10245512728872962677U;
            aOrbiterD = RotL64((aOrbiterD * 707106795383284903U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4810366069422162351U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3051442983125942469U;
            aOrbiterB = RotL64((aOrbiterB * 13558537578054436423U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9285068547223654308U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13067251130180968842U;
            aOrbiterJ = RotL64((aOrbiterJ * 7000687697769766605U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3203670242792002165U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1770881716916463461U;
            aOrbiterA = RotL64((aOrbiterA * 13870229847371882171U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16286823712870537410U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13067191141829694202U;
            aOrbiterK = RotL64((aOrbiterK * 15629974528467350445U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3414576315085336932U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8979691827341555245U;
            aOrbiterG = RotL64((aOrbiterG * 15971594804040295757U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterE, 47U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterA, 58U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterJ, 5U));
            aWandererD = aWandererD + ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 53U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 28U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 27U)) + aPhaseCWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_BasketBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7583U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 2630U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3705U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 5462U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 19U)) ^ (RotL64(aIngress, 34U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererB + RotL64(aScatter, 12U)) + 9751314027302668907U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 12175450995523107056U) + aPhaseDOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 21U)) + 17519694958730119552U) + aPhaseDOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 9093525527925682263U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 3713831321786810138U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10108355209191835040U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 12956307447311314768U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9198936928658626667U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1904298513945877359U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4658049993308574460U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10482422152074338611U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9826333658248851902U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12058666914724365134U;
            aOrbiterB = RotL64((aOrbiterB * 964233873188373939U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2516574707110528099U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13335308331049750235U;
            aOrbiterE = RotL64((aOrbiterE * 5880227828760598587U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8230749255538495304U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16536559486797811486U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7097036838156464969U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 54U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterK, 4U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aIngress, 58U) + aOrbiterJ) + RotL64(aOrbiterB, 37U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterB, 13U)) + aPhaseDWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterA) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12063U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((aIndex + 9985U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10156U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15833U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 5088525177670191619U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 48U)) + 9966456257813932112U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 7707646574027146307U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 75480203757681173U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 35U)) + 384659134071835163U) + aPhaseDOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3158769775373307778U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17360830943513941272U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9986023786908098621U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5317278822721604586U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1371427105215954781U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10956603063464438611U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3162710551223553423U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5332921933853550756U;
            aOrbiterE = RotL64((aOrbiterE * 11709546145149357887U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10572462410297815854U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10234389605554817892U;
            aOrbiterB = RotL64((aOrbiterB * 2130374833440291193U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13421365517991380605U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10186643614984034083U;
            aOrbiterK = RotL64((aOrbiterK * 8554471709467808453U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 39U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aIngress, 34U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 50U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 21U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererF, 20U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17643U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17849U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22901U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20975U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 14U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererA + RotL64(aPrevious, 53U)) + 16200278595895089008U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 1029614154810465897U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 7129562468705441295U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 42U)) + 14388903902433951274U;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 1013568949315967455U) + aPhaseDOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 3128823373497815651U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14525694606889470589U;
            aOrbiterI = RotL64((aOrbiterI * 12053226114431679195U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14443983602196782887U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12244220415328641190U;
            aOrbiterA = RotL64((aOrbiterA * 15052949098014803181U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10477159225338766614U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2842870123078131566U;
            aOrbiterK = RotL64((aOrbiterK * 11522265477555954071U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8621138818955849917U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5038396344400303181U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14636756322207385447U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2768613802894372496U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2027754864051410015U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2461322540050569287U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterI, 19U));
            aWandererG = aWandererG + (((RotL64(aIngress, 52U) + aOrbiterI) + RotL64(aOrbiterA, 52U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28338U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26534U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28714U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 28492U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 20U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 9023059520606551446U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 662441755115638133U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 50U)) + 16957253361196144712U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 7840955025765308605U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 3U)) + 346855809270395799U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16099139781586668343U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3706457327118322098U;
            aOrbiterB = RotL64((aOrbiterB * 7810030620470889591U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12166825885547622870U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7792658665720344200U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16305542632794270697U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7128477606152986326U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11116533962780290084U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11993485572912492297U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10443889548568288532U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4402387036946561017U;
            aOrbiterF = RotL64((aOrbiterF * 9032964741841833277U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13002706161178447654U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13929727277530310708U;
            aOrbiterG = RotL64((aOrbiterG * 7005639090871200285U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 13U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterI, 3U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 48U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterB, 35U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 21U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_BasketBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2965U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7226U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2984U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 6532U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererF + RotL64(aScatter, 23U)) + 14686411261024919129U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 50U)) + RotL64(aCarry, 21U)) + 7514582233957632005U) + aPhaseEOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 57U)) + 6520710480103365552U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 1983621978676188036U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 13U)) + 9003524602590749672U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 6428568234045228995U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 35U)) + 8656552687136446989U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16916248288415922490U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9740237548002535784U;
            aOrbiterI = RotL64((aOrbiterI * 7970729853948983849U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 907561000814618339U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 4751108900841197631U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4545395964730641957U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 167774899400732287U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11907484918310854962U;
            aOrbiterE = RotL64((aOrbiterE * 7213139491146402985U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14910318613649863924U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14882888155751455276U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11394136445442060201U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16175942562693781908U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11022373758481651102U;
            aOrbiterA = RotL64((aOrbiterA * 6836331461393816027U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12548405399045031548U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10850926364556828443U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16231561687709867431U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13391684887911141790U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14648937281264822988U;
            aOrbiterF = RotL64((aOrbiterF * 6533299316940026059U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 51U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 29U));
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 40U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterA, 13U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13851U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 13484U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11641U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11807U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCarry, 47U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererH + RotL64(aPrevious, 37U)) + 7896237440058555694U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 60U)) + 11870529476037558635U;
            aOrbiterK = (aWandererA + RotL64(aCross, 19U)) + 9158983227801569448U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 4710172270996950329U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 14634482800356647630U) + aPhaseEOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 3U)) + 8822207952170610891U) + aPhaseEOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 13755891414028982553U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4555293067488040719U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2816805148093762081U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16838149138341713943U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 2122631477965135190U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4592922416380416071U;
            aOrbiterF = RotL64((aOrbiterF * 11644507904538573165U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7102471666524164715U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 17274623547879474204U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5443572270546181789U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 938587316977094680U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18258015823797023523U;
            aOrbiterD = RotL64((aOrbiterD * 6068819567674605919U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5809987756043471595U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5083075160112581620U;
            aOrbiterG = RotL64((aOrbiterG * 3313957222154937503U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5960021727750946496U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5967477320950630150U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 330964768256424655U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6578428711689296132U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5601728218197771276U;
            aOrbiterE = RotL64((aOrbiterE * 9552559022315971847U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 40U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterK, 57U));
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 50U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterD, 19U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 27U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 24U) + aOrbiterE) + RotL64(aOrbiterK, 43U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21346U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20067U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17454U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 18302U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 11U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 19U)) + 1708250618750199233U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 5U)) + 12009147777553691142U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 8393982703399156592U) + aPhaseEOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aCross, 50U)) + RotL64(aCarry, 37U)) + 3247327098356831221U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 11U)) + 3403590155376353737U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 18197244558104735044U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 57U)) + 3096253642040701606U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8012692688785412179U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 17531946907545680745U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16510602981731506381U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17687695944270225817U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16147773866007628769U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16926442582711557877U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 18244641303026196497U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8839160526348897457U;
            aOrbiterC = RotL64((aOrbiterC * 14268021129087663397U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10599266240854068246U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2056723540756216155U;
            aOrbiterI = RotL64((aOrbiterI * 13311591601230386375U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4629354220460621284U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9505955649473204942U;
            aOrbiterG = RotL64((aOrbiterG * 17775391885312236187U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17078153810088721310U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9470436761716263000U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5431855497250357229U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3305863413630104742U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14377172434239576161U;
            aOrbiterF = RotL64((aOrbiterF * 6880176890091033423U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 60U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 13U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 57U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterF, 19U));
            aWandererE = aWandererE + ((RotL64(aIngress, 58U) + aOrbiterI) + RotL64(aOrbiterJ, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterG, 6U));
            aWandererI = aWandererI + ((((RotL64(aCross, 37U) + RotL64(aOrbiterF, 27U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28094U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25946U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32634U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 27050U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererK + RotL64(aCross, 5U)) + 10812151398716051703U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 21U)) + 18202551453336003710U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 9434410809101973752U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 50U)) + RotL64(aCarry, 23U)) + 12955829998028534045U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 11U)) + 12271740641929640181U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 14009351527014534752U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 57U)) + 4316296955679133450U) + aPhaseEOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16473324966997442872U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15735123324965019802U;
            aOrbiterC = RotL64((aOrbiterC * 5624078184997601019U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17656375090484080236U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16066325053456055298U;
            aOrbiterA = RotL64((aOrbiterA * 17912970706985130327U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 12908968778503516903U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12761433987676836197U;
            aOrbiterI = RotL64((aOrbiterI * 1023329467480907925U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12737513138040664509U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 14535795767570998392U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15560519667062222269U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14370908061811284364U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7001358781208669795U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11641248025734015835U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7298578161120090849U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10498302152357484629U;
            aOrbiterF = RotL64((aOrbiterF * 13144110412179037175U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11447343228638006767U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 18284143620422655675U;
            aOrbiterJ = RotL64((aOrbiterJ * 572862190073605651U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 12U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterG, 47U)) + aPhaseEWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 11U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 19U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 4U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterA, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_BasketBall_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4362U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 5205U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8189U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneA[((aIndex + 6625U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 38U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 15383045568644941552U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 17452811657750910067U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 36U)) + RotL64(aCarry, 41U)) + 15660117718455155603U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 3U)) + 10396441207743665753U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 47U)) + 3708971058200841442U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7000673057768598750U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9886354469011131596U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 296615166652808759U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 16018065329058043467U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5024756166109352320U;
            aOrbiterE = RotL64((aOrbiterE * 11660932185479046483U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6587818720728886652U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3652672354944162319U;
            aOrbiterA = RotL64((aOrbiterA * 10807121230791716109U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6307315649915348048U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16405347331742979258U;
            aOrbiterG = RotL64((aOrbiterG * 7183142442906743699U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5427299664054601957U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4983381733483185898U;
            aOrbiterK = RotL64((aOrbiterK * 14646556236306407673U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 11U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 38U) + RotL64(aOrbiterG, 24U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 35U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterG, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererF, 4U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12342U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 15395U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9450U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11673U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 26U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 3550722402315312207U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 16724184551669522754U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 60U)) + RotL64(aCarry, 27U)) + 981751330116773021U;
            aOrbiterA = (aWandererI + RotL64(aCross, 11U)) + 7891159229704944868U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 27U)) + 13618396711464799841U) + aPhaseFOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 5969291018449003648U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14595540413313640042U;
            aOrbiterB = RotL64((aOrbiterB * 8151104319012840963U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3287990436916111762U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12534369400200483704U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2345945228434740707U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2277312067930392274U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10026320559261334353U;
            aOrbiterJ = RotL64((aOrbiterJ * 11020464940995912637U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11258082063135659551U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1445958517675746990U;
            aOrbiterE = RotL64((aOrbiterE * 10062265337488757971U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1011298251290970844U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6487834862470043744U;
            aOrbiterA = RotL64((aOrbiterA * 15477913837027179675U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 26U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterA, 11U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterA, 52U));
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterA, 21U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21589U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 17584U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21736U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23648U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 39U)) + (RotL64(aCross, 56U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 6469584119078165548U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 36U)) + 14329756366517987910U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 12890831797059772123U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 3164503807500018990U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 53U)) + 177531431387646836U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3167421392893561015U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2813174781844753460U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9760688894575305115U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10953270419153249857U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 16911518309710356951U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13162785997686570445U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6616750447844893150U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10276741398025985982U;
            aOrbiterE = RotL64((aOrbiterE * 6824712685896987133U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6206043608461213208U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12021552904553405793U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10023362889960174909U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15283586234744144846U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5923238786775948571U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8200882393521882651U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 53U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 12U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterE, 43U));
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 4U) + aOrbiterA) + RotL64(aOrbiterG, 23U)) + aPhaseFWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26340U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 32412U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31260U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25543U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 6318740973868639425U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 5487840061430920881U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aIngress, 13U)) + 10258706763248072672U) + aPhaseFOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aPrevious, 5U)) + 18356875269730338208U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 23U)) + 12883160282903147010U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1010140474942697730U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17733939421700898293U;
            aOrbiterC = RotL64((aOrbiterC * 9233534157871885251U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13693055887924981201U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14574732452793385269U;
            aOrbiterF = RotL64((aOrbiterF * 9373765929885750185U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10832873941223609012U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8212600587135328040U;
            aOrbiterI = RotL64((aOrbiterI * 5334613996794796145U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5312744319781971178U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6173741211706546923U;
            aOrbiterE = RotL64((aOrbiterE * 12854414066390848249U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 3693249147883790810U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 18365859989736602556U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3348463719324104997U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 47U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterC, 13U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + aPhaseFWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 50U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterI, 56U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_BasketBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 4616U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 2880U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1212U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1575U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 13U) + RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererJ + RotL64(aCross, 37U)) + 2330952702412094686U) + aPhaseGOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 7820188225935060799U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 9347644591709839145U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 28U)) + RotL64(aCarry, 51U)) + 2288624878446846870U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 13U)) + 9358977729492824128U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1858511275052455039U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13715478509322292552U;
            aOrbiterK = RotL64((aOrbiterK * 15552121744869003235U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16413396625604260455U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17714322215518432705U;
            aOrbiterF = RotL64((aOrbiterF * 1904184102419934333U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16188315436202861122U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5564445841368207813U;
            aOrbiterB = RotL64((aOrbiterB * 14125834616162835983U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13717068949900594673U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14143659432287313765U;
            aOrbiterG = RotL64((aOrbiterG * 17281441046722262917U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5729546141908425670U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4297827922736712074U;
            aOrbiterA = RotL64((aOrbiterA * 13631630436759768885U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 38U) + aOrbiterF) + RotL64(aOrbiterB, 14U)) + aPhaseGWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterA, 39U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 29U)) + aOrbiterF) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11351U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 12451U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12490U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11198U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 785861751704720606U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 20U)) + 15968088718435606299U) + aPhaseGOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 1393976526590347151U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 17240750947292745884U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 47U)) + 4921576136163183137U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3334047873553153032U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15086509978458408698U;
            aOrbiterD = RotL64((aOrbiterD * 2162818176367899893U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 892391205397581998U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2965686403183767521U;
            aOrbiterA = RotL64((aOrbiterA * 709160942482770225U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14632215393655706170U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15740589515342377322U;
            aOrbiterH = RotL64((aOrbiterH * 15677716942904794913U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11131164813943086445U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6988080581278900960U;
            aOrbiterF = RotL64((aOrbiterF * 6412189142344044255U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 16021254613117657178U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6183615599897921154U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9976411093264211033U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterA, 47U)) + aPhaseGWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 38U)) + aOrbiterB) + aPhaseGWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterH, 5U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 19043U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 24305U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17840U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21496U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererD + RotL64(aScatter, 41U)) + 8988572360732005217U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 30U)) + RotL64(aCarry, 13U)) + 17889613225105985335U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 57U)) + 15563478320513948626U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 3441351228410524816U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 4425592689451435346U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12733160231627305928U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3574152157304607854U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3488682351509384035U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15167631896729808783U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15822667973915417055U;
            aOrbiterH = RotL64((aOrbiterH * 5155661648455308057U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17181685481076577637U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9979204751408873468U;
            aOrbiterI = RotL64((aOrbiterI * 8244434774754786565U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1334240485667164762U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9190066751460137016U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14585141844653660363U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15465215829109246336U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2305208282453624419U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10257861974108363283U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 40U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 12U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterA, 21U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 3U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aPhaseGWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 42U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 31364U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27557U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29128U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31516U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 6U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 1457104756581596530U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 29U)) + 6127240317844622874U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aScatter, 39U)) + 16492290056044189421U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 10963676850938416468U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 12U)) + RotL64(aCarry, 39U)) + 4872917367399752405U) + aPhaseGOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15218882377875616148U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5934166612122118251U;
            aOrbiterE = RotL64((aOrbiterE * 10365045124180379919U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 14215280930872003003U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11428034799044600979U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12162528943733976177U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5453003654321728726U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14273775120265649389U;
            aOrbiterF = RotL64((aOrbiterF * 5139018128323795309U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 328723770018440271U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13032190719588211088U;
            aOrbiterH = RotL64((aOrbiterH * 13363368478932798315U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2386881543033598494U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1649501123340887116U;
            aOrbiterD = RotL64((aOrbiterD * 11148976582360499033U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + aPhaseGWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterE, 18U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterE, 5U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_BasketBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6870U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((aIndex + 143U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2325U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 6090U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 48U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 4634399531433127141U) + aPhaseHOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 16961792729406903200U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 13U)) + 4105280732301137738U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 15692013501147331191U) + aPhaseHOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aPrevious, 58U)) + 1252216715968780587U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7958289043012473752U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6611577301818896615U;
            aOrbiterG = RotL64((aOrbiterG * 2757493607265637973U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8506226754305949140U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 3648813120449403353U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9521367946879238849U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 5195245426245535735U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 542948051600803051U;
            aOrbiterH = RotL64((aOrbiterH * 4631106308856448475U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11974253551208964789U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10596463592332655367U;
            aOrbiterI = RotL64((aOrbiterI * 10941161258815714641U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12015129484061440159U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8254944355710109060U;
            aOrbiterK = RotL64((aOrbiterK * 3233697992479357615U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 20U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterK, 46U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16126U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneC[((aIndex + 10795U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9798U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14989U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 10U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererI + RotL64(aCross, 11U)) + 6342299552323486695U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 12692748514781367538U;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 20U)) + RotL64(aCarry, 5U)) + 8202639945493229155U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 4439975701793231639U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aCross, 43U)) + 16774235182859553759U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8764155413335405667U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7167848811974967685U;
            aOrbiterB = RotL64((aOrbiterB * 1052856924757654735U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16768278912125334220U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 9090838954826296201U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5459329624017272077U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7644075729758006298U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17326182797908071215U;
            aOrbiterI = RotL64((aOrbiterI * 2408330168749256075U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16158809721888137555U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8029938783858263694U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12628072435324195483U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8716553521415553404U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7012599977009208840U;
            aOrbiterG = RotL64((aOrbiterG * 8775355876188948851U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterI, 26U)) + aPhaseHWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 13U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aIngress, 14U) + aOrbiterI) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterB, 47U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 18512U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22717U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21806U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 21249U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 52U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 24U)) + RotL64(aCarry, 53U)) + 16462052553719977502U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 51U)) + 12337064059566619581U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 15801005007094515447U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 8228706742665081656U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 11U)) + 11006723027845190869U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 18173765337829177450U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 530215083653542558U;
            aOrbiterE = RotL64((aOrbiterE * 8938680024265564887U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6608611827035564511U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 2246051826221626809U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6333352641495253539U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5228575308895381421U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 10999213210689606857U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5467601259546342925U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3773371037240485696U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8887985779436152504U;
            aOrbiterG = RotL64((aOrbiterG * 698713082830739677U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11150566414723818350U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8336366151003049546U;
            aOrbiterF = RotL64((aOrbiterF * 9033771197242493699U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (RotL64(aOrbiterD, 34U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterK, 22U));
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterG, 11U)) + aPhaseHWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterE, 3U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterD, 47U)) + aPhaseHWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 32741U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30958U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26086U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 26758U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 58U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 39U)) + 10726035965553989335U) + aPhaseHOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 967354339530195662U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aScatter, 48U)) + RotL64(aCarry, 53U)) + 10834593005478605624U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 1012888282838656933U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 57U)) + 15283530351725183253U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11724495956731703750U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4288330117317505776U;
            aOrbiterE = RotL64((aOrbiterE * 2738997410474076757U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10894778070022873473U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 15563886747621617467U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17884709931569040065U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11182488628562891937U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10420140066310588580U;
            aOrbiterH = RotL64((aOrbiterH * 13898299782819948719U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11775138062167543111U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16545391898578161683U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14588306527161321535U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1550144656312299266U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14903504853138279883U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8003033561266164387U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 30U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 4U)) + aOrbiterF) + aPhaseHWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterH, 57U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 21U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterH, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
