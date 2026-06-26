#include "TwistExpander_Tennis_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Tennis_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC133D6860AFF6003ULL + 0xD39691C6794BF7F2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBA83C0A9B9BEC227ULL + 0xE5158D2A991FF013ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x81ED160EACB95D2FULL + 0xC9474354327A106DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x87121E47F494F2EBULL + 0xD456AF2C0C98EFAFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBDC9351339F32BEFULL + 0x88F26A8AE6E3FDE7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x94EF002345FBC629ULL + 0xC705A9F3BE2198BEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA98C68961497F449ULL + 0xDFB1DD0952AAC911ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE84FCE8922EFB891ULL + 0xD5EA0D2626CC0C0FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC617B63E09348539ULL + 0x97E72A685275C9BEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9F68FA9893B9A511ULL + 0xE27DF0520AE83ACFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC35B8D01F9C2EAE3ULL + 0xD670159A0B1CA44FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCA518123E2E46FF7ULL + 0xCC8FAB05DD994964ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD6C8FC31F3EE328DULL + 0x926AE5B977F5F000ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFAA06B6CDE62D6EFULL + 0xBA32738FB1C83AE8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9311370735B73BA7ULL + 0xE7D9F96E04FBE202ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA25010D211158A2FULL + 0xB4E92842D2BF6F14ULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 396U)) & S_BLOCK1], 34U) ^ RotL64(pSnow[((aIndex + 4299U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 3859U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 3117U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 34U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aPrevious, 3U)) + 6342299552323486695U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 12692748514781367538U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 53U)) + 8202639945493229155U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aWandererB + RotL64(aCross, 14U)) + RotL64(aCarry, 47U)) + 4439975701793231639U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 5U)) + 16774235182859553759U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 29U)) + 8764155413335405667U) + aNonceWordO;
            aOrbiterH = (aWandererD + RotL64(aCross, 39U)) + 7167848811974967685U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 16768278912125334220U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aCross, 41U)) + 9090838954826296201U) + aNonceWordD;
            aOrbiterC = (aWandererC + RotL64(aScatter, 60U)) + 7644075729758006298U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 27U)) + 17326182797908071215U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 16158809721888137555U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8029938783858263694U;
            aOrbiterJ = RotL64((aOrbiterJ * 12628072435324195483U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8716553521415553404U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7012599977009208840U;
            aOrbiterE = RotL64((aOrbiterE * 8775355876188948851U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 13250558696578541499U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13705957059101025396U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16889495686487056367U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2796775206291902461U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13741676263512390669U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10455782033465595947U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1691908360612389252U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4114939415206031540U;
            aOrbiterH = RotL64((aOrbiterH * 2797401802892718297U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2374911514440738727U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12377616933668803091U;
            aOrbiterD = RotL64((aOrbiterD * 2505164835116651215U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 681094033415259645U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13841322124900463362U;
            aOrbiterF = RotL64((aOrbiterF * 4210414203856902329U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 18082983557580381338U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15731122225678626778U;
            aOrbiterB = RotL64((aOrbiterB * 7785999919955613789U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2084336993254383330U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3600882019682875370U;
            aOrbiterI = RotL64((aOrbiterI * 2977569829649654329U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11436602278656592334U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5775886971784627864U;
            aOrbiterK = RotL64((aOrbiterK * 6765942246225582787U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17120308925134658794U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6342299552323486695U;
            aOrbiterC = RotL64((aOrbiterC * 5788669985396507227U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + aNonceWordC);
            aWandererI = aWandererI + (((((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 43U)) + aNonceWordJ) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 43U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 10U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterA, 51U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 21U));
            aWandererC = aWandererC + ((RotL64(aCross, 44U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 29U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterK, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7165U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10054U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 10461U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 5825U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aScatter, 21U)) + 6467297102954816305U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 5U)) + 7921154109831114952U) + aNonceWordP;
            aOrbiterF = ((aWandererB + RotL64(aCross, 10U)) + 5701131763215638919U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aPrevious, 3U)) + 10022999076719002684U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 4367135243038982316U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 43U)) + 14445846824810383592U;
            aOrbiterA = ((((aWandererA + RotL64(aPrevious, 48U)) + RotL64(aCarry, 19U)) + 7683697954545773253U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 17517006750428030899U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 29U)) + 2052484792684025476U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 57U)) + 6279463052085808926U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 51U)) + 679280153651813684U) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2939516520188460569U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1960616434964712325U;
            aOrbiterF = RotL64((aOrbiterF * 15145998415466343039U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 12273819390719947361U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5685033154709449397U;
            aOrbiterD = RotL64((aOrbiterD * 9845666295874714959U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9314494172199500653U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 15757631834636427621U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15483543888965744529U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10878078046389399574U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3583495913766365232U;
            aOrbiterA = RotL64((aOrbiterA * 2913540984990155225U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7385544065754622301U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16839599460207922881U;
            aOrbiterE = RotL64((aOrbiterE * 240651605910592561U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13038163804940349251U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 2587538594933924000U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3091149760401278671U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13109518583364738004U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2447689055742474261U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12100180201235703193U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5752044906692668618U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6637725371036522120U;
            aOrbiterK = RotL64((aOrbiterK * 6021986525167161115U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16549229877442298618U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12825651879441561108U;
            aOrbiterH = RotL64((aOrbiterH * 9079931351967033993U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16088338999978085987U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12584648360998154782U;
            aOrbiterI = RotL64((aOrbiterI * 2109996837220975261U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 7526256599938771686U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6467297102954816305U;
            aOrbiterJ = RotL64((aOrbiterJ * 9289442676936248653U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 10U) + aOrbiterF) + RotL64(aOrbiterK, 53U)) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterA, 39U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterD, 20U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterC, 35U));
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 11U)) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 50U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 36U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererH, 6U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13237U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13913U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 11809U)) & S_BLOCK1], 14U) ^ RotL64(pSnow[((aIndex + 14892U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 29U) ^ RotL64(aIngress, 54U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aCross, 13U)) + 7960325128608297381U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 10U)) + 12773836012104052042U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 21U)) + 3173972621347773016U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 3708401356314308171U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 27U)) + 950774285720019449U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 36U)) + 4170092315705438265U;
            aOrbiterG = (aWandererA + RotL64(aCross, 39U)) + 17000449130864980747U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 8793910540062893860U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 57U)) + 520277969543516469U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 47U)) + 12762214857389827271U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 2932451184340207695U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11062179998786293839U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7919119215271524178U;
            aOrbiterH = RotL64((aOrbiterH * 9053677007180081359U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1774988449597115155U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3799792889466518953U;
            aOrbiterE = RotL64((aOrbiterE * 17512791286490623455U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1815062051307896589U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15260373951371654483U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2208604434669491625U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12867546628945676853U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7772820973895846946U;
            aOrbiterF = RotL64((aOrbiterF * 7581704643538761985U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14213957831821966834U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16561105721170419454U;
            aOrbiterD = RotL64((aOrbiterD * 2540533987337175367U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16556502948339949526U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9706742922075498974U;
            aOrbiterJ = RotL64((aOrbiterJ * 8527361328901355457U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13455756934917486016U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9107769876332723454U;
            aOrbiterC = RotL64((aOrbiterC * 1722386100852683783U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15793099079168487016U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7968278803691283365U;
            aOrbiterA = RotL64((aOrbiterA * 11644765391940099387U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15068302421261745111U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11373111908765197862U;
            aOrbiterG = RotL64((aOrbiterG * 17756438368103196771U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6362100123286229887U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 528778333872160609U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17377710146983314215U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6116442644744391285U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7960325128608297381U;
            aOrbiterK = RotL64((aOrbiterK * 17826511435509927061U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 4U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 4U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterA, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterB, 11U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 26U) + aOrbiterF) + RotL64(aOrbiterA, 58U));
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 53U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterI, 56U));
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16881U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17377U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20783U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 20668U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 18U)) + 4634399531433127141U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 16961792729406903200U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 23U)) + 4105280732301137738U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 11U)) + 15692013501147331191U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 41U)) + 1252216715968780587U) + aNonceWordK;
            aOrbiterH = (aWandererF + RotL64(aScatter, 37U)) + 7958289043012473752U;
            aOrbiterI = ((((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 6611577301818896615U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aWandererA + RotL64(aIngress, 43U)) + 8506226754305949140U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 35U)) + 3648813120449403353U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 48U)) + 5195245426245535735U;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 542948051600803051U) + aNonceWordN;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11974253551208964789U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10596463592332655367U;
            aOrbiterF = RotL64((aOrbiterF * 10941161258815714641U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12015129484061440159U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8254944355710109060U;
            aOrbiterE = RotL64((aOrbiterE * 3233697992479357615U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2754858806943915419U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5007802002906662779U;
            aOrbiterH = RotL64((aOrbiterH * 15613733948331639723U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6262190752136523216U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10528977986487821428U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 1184258264034585525U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8511097226098211854U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12091864735686692582U;
            aOrbiterG = RotL64((aOrbiterG * 6128140528141411237U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4970966265236842566U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10728884018459718341U;
            aOrbiterD = RotL64((aOrbiterD * 18205183219769602827U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13760057185629905360U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6590269178744829056U;
            aOrbiterJ = RotL64((aOrbiterJ * 14482684769712170123U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 765826377665103262U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 9364759196106579706U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 10315111163659289329U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4629303338428087146U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15107221579712215172U;
            aOrbiterC = RotL64((aOrbiterC * 14410837138199304663U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 9407987092859067074U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13589362515507116096U;
            aOrbiterA = RotL64((aOrbiterA * 4544198075069052713U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2236921538387014026U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4634399531433127141U;
            aOrbiterB = RotL64((aOrbiterB * 13132011613143486575U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 30U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterG, 34U)) + RotL64(aCarry, 37U)) + aNonceWordA) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterE, 39U)) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 53U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 10U) + aOrbiterB) + RotL64(aOrbiterK, 29U));
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 27U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterG, 43U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterI, 23U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterF, 46U));
            aWandererC = aWandererC + ((RotL64(aCross, 58U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 3U)) + aOrbiterD) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 52U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24632U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 25623U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24193U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25509U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 40U) + RotL64(aCross, 13U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aIngress, 13U)) + 2786079456995203065U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 21U)) + 7237256119153857253U) + aNonceWordD;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 39U)) + 9310834010563647604U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 26U)) + 17361734905706517877U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 23U)) + 15837111231884647451U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 37U)) + 18065431964418026445U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 3029123922999952652U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 5166926595573507837U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 35U)) + 1918425684273807598U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 11U)) + 4724551751012661440U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 56U)) + RotL64(aCarry, 19U)) + 1818014487579644390U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6670090372241084216U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8485757110007268693U;
            aOrbiterF = RotL64((aOrbiterF * 11876760095108618363U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4928130251509514742U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2528788422725346792U;
            aOrbiterA = RotL64((aOrbiterA * 1855982047967756661U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2860387120895147503U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12927802338151379368U;
            aOrbiterG = RotL64((aOrbiterG * 8876144125458603029U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 18029699867733207083U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13361836994951253312U;
            aOrbiterC = RotL64((aOrbiterC * 5349767426256597073U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11957294454794128079U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3755417922063414648U;
            aOrbiterE = RotL64((aOrbiterE * 13896364063651241401U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 18001157153447913032U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16214145724690286854U;
            aOrbiterB = RotL64((aOrbiterB * 5874139687703360515U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3860958772090975562U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12395621524459640173U;
            aOrbiterH = RotL64((aOrbiterH * 722817135977510161U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3402035664910754484U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2139099117325745602U;
            aOrbiterK = RotL64((aOrbiterK * 14008983756425796029U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7769274487425053026U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6492669707749367728U;
            aOrbiterI = RotL64((aOrbiterI * 5149771861620757839U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14963366447884375043U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 11398874662567519691U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 8221521452475029835U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 7168445485232814860U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2786079456995203065U;
            aOrbiterJ = RotL64((aOrbiterJ * 14258367164534307955U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 10U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterD, 22U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aScatter, 10U) + aOrbiterH) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterH, 60U)) + aNonceWordN) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterA, 47U));
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterI, 27U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28069U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30106U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29335U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 28273U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aIngress, 39U)) + 12122689833405846292U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 10U)) + 9640400270962766788U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 19U)) + 9141937998266739071U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 12899395770434090537U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 13457918115408031842U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 5U)) + 15134784483576000943U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 3U)) + 12540961268790055438U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aScatter, 47U)) + 6306886773092764230U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 51U)) + 13573343491337243121U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 56U)) + 8545588657348974413U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 10891410570357275120U) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2877137119767060151U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9178097682386595144U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 3524486002084427513U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15528007881855616978U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11368419529245281435U;
            aOrbiterI = RotL64((aOrbiterI * 12433207037378339309U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5932738914934356645U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5551842263864055419U;
            aOrbiterJ = RotL64((aOrbiterJ * 16093776759971522681U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3824433359595690603U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17184628855571662441U;
            aOrbiterF = RotL64((aOrbiterF * 691208053136187317U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8724462245014132623U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7481349499528092352U;
            aOrbiterH = RotL64((aOrbiterH * 8212182934509617583U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6908362960248294718U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5354057969992655314U;
            aOrbiterD = RotL64((aOrbiterD * 16586084885820679343U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11138301629323903147U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14164180536320940750U;
            aOrbiterE = RotL64((aOrbiterE * 9099767681053390287U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 709942920176922902U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17128241237359414945U;
            aOrbiterK = RotL64((aOrbiterK * 14063385518459963529U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 6760410778228957309U) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15333948259759012363U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3685416414008280787U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6929136132517755104U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 13833415487953533365U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 14860437994758579635U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16143046377679975216U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12122689833405846292U;
            aOrbiterC = RotL64((aOrbiterC * 227699085983424155U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterC, 57U));
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterB, 5U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterG, 21U)) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 37U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterF, 44U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC);
            aWandererG = aWandererG + (((((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 53U)) + aNonceWordB) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 52U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 26U) + aOrbiterB) + RotL64(aOrbiterE, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_Tennis_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x80A58BFFB0ECE47DULL + 0xCD18AB51A988E172ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x918C11A7BDC80637ULL + 0xAAC1145FF0CA66A2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA847157A53AEE4A9ULL + 0xA97A839527BD26BFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC2E1890B74B2CD6DULL + 0xDDB685DCC8A09331ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC16845D45E225481ULL + 0xCC7A4E48075E5557ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB7DBDAC58BA4982DULL + 0x91C457CA2F6331A9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8F66B1220C601927ULL + 0xC882B84C30A4C0B7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xABB7EF808EAC1143ULL + 0xD7376DDE63AA4442ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB71A3551C54F7FA5ULL + 0xE4239FD21BA9ECEEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9470BAB6AD251E6FULL + 0xA06E0CF0F331D7A9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEAA5C75D90529277ULL + 0x8891AF50C437E17DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x80C38A3EC70DFF55ULL + 0x95585FF6B612AB31ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF9054801524F9945ULL + 0xC51DF72999E1F154ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCDB9EB728F18C297ULL + 0xF46BADF72F3C32EEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD46EA79CB2943B69ULL + 0xA4BE81CF875617B3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD4F0A26DB58570F7ULL + 0x97CE7605CE8B38FAULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3158U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 6656U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7009U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1837U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 29U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aScatter, 11U)) + 15813325389431304548U;
            aOrbiterB = (aWandererF + RotL64(aCross, 50U)) + 2223874171125403602U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 23U)) + 5510483568496824130U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 43U)) + 15474152493495661876U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 16846339705130829195U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aIngress, 56U)) + RotL64(aCarry, 3U)) + 1289670576865739669U;
            aOrbiterG = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 18017354919647006944U) + aNonceWordK;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 27U)) + 8539685539928984921U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aWandererH + RotL64(aScatter, 37U)) + 3333721400836704048U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2261560416623815491U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4377786131746816567U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 9164777834392621157U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 18047393176583722719U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8184724021940434631U;
            aOrbiterF = RotL64((aOrbiterF * 9800116157750921119U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10469895939183324807U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14543391765109879223U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4817987697437667225U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5757225781746158178U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3539000495894022869U;
            aOrbiterH = RotL64((aOrbiterH * 1032298408884695925U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11288971092707065923U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2761384065186568294U;
            aOrbiterD = RotL64((aOrbiterD * 3323838837427471051U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7120580145300417101U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 6977246291769372866U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 15170353875184253779U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17625434527765525937U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3299714663631376190U;
            aOrbiterG = RotL64((aOrbiterG * 6532628892760776767U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10331889953489885250U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8550932256881727932U;
            aOrbiterB = RotL64((aOrbiterB * 13085531621192583719U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11151195711186126257U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2552002192824926483U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9754056316698523849U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 30U);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 35U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterH, 29U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 57U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterI, 6U)) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterK, 21U)) + aOrbiterC) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 14U)) + aNonceWordC) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11726U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 11174U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8589U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 12686U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 18U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererB + RotL64(aPrevious, 47U)) + 4384716820085860551U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 5U)) + 9715780315942116888U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 23U)) + 15963520052789178632U) + aNonceWordD;
            aOrbiterC = (aWandererF + RotL64(aCross, 10U)) + 14346700690686392938U;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 6005518012489966643U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aPrevious, 43U)) + 2506732930310252119U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 16782163084851775826U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 823673076571076303U) + aNonceWordM;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 52U)) + 1634084509064077736U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1288134975466877686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2998220403162908444U;
            aOrbiterH = RotL64((aOrbiterH * 4321412662318298283U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 220430672180734911U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10223923547068528867U;
            aOrbiterJ = RotL64((aOrbiterJ * 12577370238343872139U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11696469696177647608U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6545430420379636963U;
            aOrbiterE = RotL64((aOrbiterE * 8387163146257553773U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 79691451831797107U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8971444023498649419U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7148919880477390009U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5624403902454498793U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9468064161002030997U;
            aOrbiterK = RotL64((aOrbiterK * 8243560528100864595U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4619361544913629805U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12682446273369750704U;
            aOrbiterG = RotL64((aOrbiterG * 10879074713156075641U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8728730962617599223U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9099675924074253030U;
            aOrbiterC = RotL64((aOrbiterC * 5525644236954497523U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3298303921318288541U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5953276499411658358U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 10565471305001292693U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6725769507592688539U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1057277456510215817U;
            aOrbiterA = RotL64((aOrbiterA * 8269412198279297075U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 22U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 6U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterE, 51U));
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 5U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 30U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 57U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 18U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 41U));
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterA, 24U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17286U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18739U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19444U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24532U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererJ + RotL64(aIngress, 57U)) + 13296600294247799698U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 6U)) + RotL64(aCarry, 3U)) + 5818503518080877515U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 13U)) + 6735784238734173597U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 7368398209488856201U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 961734029066455638U) + aNonceWordA;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 47U)) + 797011946660892011U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aCross, 41U)) + 12841876018396622350U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 52U)) + 16213253970483895623U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 23U)) + 15186950557113470375U;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 5117930310827477341U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12265429373166094162U;
            aOrbiterB = RotL64((aOrbiterB * 1522823535151532249U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13920531346698601568U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14695405206998211456U;
            aOrbiterD = RotL64((aOrbiterD * 13950964363414164279U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7851960904825938443U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9501511171732550190U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5614164120361489613U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5663365182245722077U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9607860124321315555U;
            aOrbiterH = RotL64((aOrbiterH * 3461820361914280601U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18171052650586819280U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 3442698321538580861U) ^ aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6317525514963824829U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1491052813469258970U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3956599824067616133U;
            aOrbiterF = RotL64((aOrbiterF * 2928600779267623085U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10963841237346073453U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2303020125591252534U;
            aOrbiterC = RotL64((aOrbiterC * 9969099842343321981U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14503856057958162356U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11147548150090597694U;
            aOrbiterG = RotL64((aOrbiterG * 11856382308792700441U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9191681438318311481U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13556072770381999852U;
            aOrbiterA = RotL64((aOrbiterA * 18316231099054203683U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 50U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterB, 29U)) + aOrbiterD) + aNonceWordK);
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + RotL64(aOrbiterB, 60U)) + aOrbiterC) + aNonceWordI) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterG, 43U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 39U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 35U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterC, 6U));
            aWandererK = aWandererK + (((RotL64(aScatter, 28U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 52U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27088U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((aIndex + 31877U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26817U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31972U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 54U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 23U)) + 13350544654542863236U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aScatter, 18U)) + 12364346790125404372U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 9738750172849512764U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 3781373837635491421U;
            aOrbiterF = (aWandererK + RotL64(aCross, 43U)) + 16635020317512702337U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 52U)) + RotL64(aCarry, 19U)) + 5383653921676231276U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 47U)) + 10181959815492056493U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 57U)) + 10005510924273927017U) + aNonceWordL;
            aOrbiterA = (aWandererB + RotL64(aScatter, 13U)) + 9524687662265740565U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4259138552009771014U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8973051213213726023U;
            aOrbiterG = RotL64((aOrbiterG * 12625091476068190979U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 17602611840127337490U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8218984546932905269U;
            aOrbiterF = RotL64((aOrbiterF * 17504305273683304231U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 18102186122213487888U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2629927500298092976U;
            aOrbiterC = RotL64((aOrbiterC * 6983280164448292723U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 2491581597835795234U) + aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9506602492971620955U;
            aOrbiterH = RotL64((aOrbiterH * 9559829640915637163U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13422942713680612924U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15037354693234876601U;
            aOrbiterK = RotL64((aOrbiterK * 12692376075738621447U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12896066842192894694U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2202952306291905855U;
            aOrbiterJ = RotL64((aOrbiterJ * 6779368532763429997U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12160313482450599313U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10812986281270407756U;
            aOrbiterD = RotL64((aOrbiterD * 7786608700746771809U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12474638293190144525U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5882870951276225224U;
            aOrbiterA = RotL64((aOrbiterA * 15532427302173572457U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3782896138051179209U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10965680631059882311U;
            aOrbiterI = RotL64((aOrbiterI * 14060923998307082385U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 38U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterC, 53U)) + aOrbiterA) + aNonceWordM);
            aWandererA = aWandererA + (((((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterK, 57U)) + aNonceWordH);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterH, 42U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 19U));
            aWandererH = aWandererH + (((RotL64(aIngress, 56U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterD, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterI, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 38U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordG;
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

void TwistExpander_Tennis_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFF886C09FD327E39ULL + 0xC9A1B472251CEAC9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8C9BDDA6C6F184D1ULL + 0x9A90C3F11C636275ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x93E6920B61F7BC7DULL + 0xBF6BEA8B714F30CCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9400833DD035C583ULL + 0xB2C607C108BDD8B7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFF727F76CE15C7B3ULL + 0xD81C24A7C883BD78ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x844D242D517BCFB3ULL + 0xDCC57A0FFB36FFD1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8D158EA7AE34EC57ULL + 0x94F876B70A47ACE8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCAEEC8FA273ADBC5ULL + 0xFAF5051ABAABE2C2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA5D69F409010E0B5ULL + 0xEB731F4551B5C5ACULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD1972B0826B4723FULL + 0xFBD6DA0E7990832BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x967AD25210E0DCD1ULL + 0xBAF5392B9F743384ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x92DBD45316C7261FULL + 0xB2DC2837DDB6C5FAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBC0F8D1AE8DD20F1ULL + 0xCDB10A9F90FC0036ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9EE34AC8CF311285ULL + 0xC8DC3F3E30654A94ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD892683706903C87ULL + 0xF0A857A5183EEDA3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9FFA057EED20FACBULL + 0xC3FB69B649212F4FULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3381U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7301U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5307U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 5408U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 19U) + RotL64(aCarry, 54U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 2330952702412094686U;
            aOrbiterC = (aWandererA + RotL64(aCross, 35U)) + 7820188225935060799U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 43U)) + 9347644591709839145U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 21U)) + 2288624878446846870U;
            aOrbiterJ = ((((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 9358977729492824128U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1858511275052455039U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 13715478509322292552U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15552121744869003235U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16413396625604260455U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 17714322215518432705U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 1904184102419934333U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16188315436202861122U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 5564445841368207813U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 14125834616162835983U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13717068949900594673U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14143659432287313765U;
            aOrbiterC = RotL64((aOrbiterC * 17281441046722262917U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5729546141908425670U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4297827922736712074U;
            aOrbiterJ = RotL64((aOrbiterJ * 13631630436759768885U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterK) + aNonceWordN) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aIngress, 20U) + RotL64(aOrbiterB, 37U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordM) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 50U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 37U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13845U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11962U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9093U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((aIndex + 14658U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 40U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 18087125778766689269U) + aNonceWordD;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 13710545066503235196U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aCross, 3U)) + 1701939704736254645U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 8064093611384019909U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 50U)) + 16623332751533885431U) + aNonceWordP;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 15590129153794910109U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7413312683079107383U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9496176571314516005U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4186064478651458810U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5501191643940735954U;
            aOrbiterA = RotL64((aOrbiterA * 14254804649177125269U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 11064645242200570835U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13825922087298055833U;
            aOrbiterF = RotL64((aOrbiterF * 7529317892716108867U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5944980709887369970U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 8181136916070569646U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 395183021205661827U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15442336949157292482U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11580554435240641337U;
            aOrbiterI = RotL64((aOrbiterI * 6654637892858767739U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 30U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 27U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 35U)) + aOrbiterF) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterF, 11U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 42U) + aOrbiterF) + RotL64(aOrbiterI, 20U)) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 22U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24293U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 16617U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21086U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 17904U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 47U)) + (RotL64(aCarry, 6U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 5173905450211892891U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 20U)) + 3555542451908039957U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 43U)) + 11559884700283861559U) + aNonceWordK;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 1352524329968738673U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 8914206450420616349U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2251523378498463946U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9541575923299247038U;
            aOrbiterC = RotL64((aOrbiterC * 1066487482799638689U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1239854507907214595U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 17698101462598498934U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 2304948713665996433U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12305566971683256060U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 13804545036303215569U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 10359543704152744971U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 10239749097704329264U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4212214906286320308U;
            aOrbiterD = RotL64((aOrbiterD * 3661436621615751071U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12192418916967430783U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4475514289326450361U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17497164630368757887U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 12U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + aNonceWordL) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterA, 60U)) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aCross, 56U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29300U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30196U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29461U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 28204U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 13U) ^ RotL64(aCross, 40U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 1708250618750199233U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 12009147777553691142U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 60U)) + RotL64(aCarry, 5U)) + 8393982703399156592U;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 51U)) + 3247327098356831221U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 13U)) + 3403590155376353737U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 18197244558104735044U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3096253642040701606U;
            aOrbiterD = RotL64((aOrbiterD * 6656168712438620783U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8012692688785412179U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 17531946907545680745U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16510602981731506381U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17687695944270225817U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16147773866007628769U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 16926442582711557877U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 18244641303026196497U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8839160526348897457U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14268021129087663397U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10599266240854068246U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2056723540756216155U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13311591601230386375U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterD, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 56U) + aOrbiterJ) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD + ((((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterB, 39U)) + aNonceWordF);
            aWandererI = aWandererI + (((((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 56U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordL) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordG;
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

void TwistExpander_Tennis_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA8B954255E6F23A5ULL + 0xF1293E1926E32EA0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA4E6A88DB468EF41ULL + 0x9C595642C21ABEE2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC2F54DBDDC75C007ULL + 0xA03DB06E1F68AEF3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE61455E1BD554E01ULL + 0xC8B0AA4C16747E50ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD1C45BA4EE81FFA3ULL + 0xAF12C8AE31976B0AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE16F254DEE1258CBULL + 0xEF33B547E92FCE01ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8FA538346327C3C5ULL + 0xBAAB0D353E8980D3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xADB7E7D767232D07ULL + 0xE300502732757586ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8616D50AE0F8D765ULL + 0xF6AA01A640E82E9FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB8DD78E87AAB4729ULL + 0xEFB7DDCE17A10574ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8E51BCA6BBB9FE43ULL + 0xDD8D695A0A887600ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC8A1BA7E66E2F067ULL + 0x988E2EDE0E665F8CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC85296AC8D05AD9FULL + 0xDC814057D344C4F6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBC9BE070BB206123ULL + 0x9FF9E693A92E88C5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF6FE2E4B452AA65BULL + 0xAF4B55370F824DDEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFB6EE0BB4EFD8FFDULL + 0xFD902E6CBDC0E1C7ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4354U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 724U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7862U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2764U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 20U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 50U)) + 4848316479321533394U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 6919360256662636195U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 11U)) + 9897013582181108544U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 23U)) + 7319353809896158678U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 2848175435514849859U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 29U)) + 6967780718720437934U) + aNonceWordK;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 10143884766603388136U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8675965006150972051U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16350117755560994281U;
            aOrbiterG = RotL64((aOrbiterG * 15072308930382994425U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17976597517118423760U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1399631141355370237U;
            aOrbiterB = RotL64((aOrbiterB * 16537788276543236833U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3590613762034716792U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5134624314245932157U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13077589037975283371U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 10082236952942943654U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4015535035905433450U;
            aOrbiterE = RotL64((aOrbiterE * 4961808568701908559U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 611474103801573800U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5786708483794098001U;
            aOrbiterI = RotL64((aOrbiterI * 7694007039340089267U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5201943497363274455U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9282160506938328489U;
            aOrbiterC = RotL64((aOrbiterC * 5368182164239021367U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4932320527498940158U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11576526341731392916U;
            aOrbiterD = RotL64((aOrbiterD * 1712051774729439363U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 50U) + aOrbiterH) + RotL64(aOrbiterD, 41U)) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterI, 14U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterD, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterG, 3U)) + aNonceWordO);
            aWandererF = aWandererF + (((((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aNonceWordM) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10912U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15970U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10629U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((aIndex + 15229U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 41U)) + (RotL64(aCarry, 26U) ^ RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 11700815697312060726U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 44U)) + 11808423452327465441U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 8670503858631730886U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 23U)) + 2400061067991988544U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (((aWandererI + RotL64(aCross, 29U)) + 16163118178366229686U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 3280178595904941068U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 51U)) + 3298683600817047727U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16321624053445183574U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6730229877611375225U;
            aOrbiterA = RotL64((aOrbiterA * 2022290495153519279U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10162830636713641322U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 15646771327759599256U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 15333053762177144775U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 14841751262270544102U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9545541117228834895U;
            aOrbiterE = RotL64((aOrbiterE * 11529769874752969377U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14676615635857599982U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1231768638470558855U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2716808508509014677U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1945905595345404833U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1406171421638586846U;
            aOrbiterI = RotL64((aOrbiterI * 4577864352425476233U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1970292335806697198U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12309719390375013297U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 16540660957923687327U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5352135521358954576U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15465675376193501658U;
            aOrbiterF = RotL64((aOrbiterF * 16385761112921041387U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 44U) + aOrbiterE) + RotL64(aOrbiterK, 5U));
            aWandererI = aWandererI + ((((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + aNonceWordN);
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 60U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterF, 43U)) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 53U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordK);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16776U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17596U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22511U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21709U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 39U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererI + RotL64(aIngress, 57U)) + 6381335981879993247U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 27U)) + 15595429101600023172U) + aNonceWordM;
            aOrbiterF = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 5449234297249826461U) + aNonceWordK;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 44U)) + 11213734849329731168U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 16438473952464514248U;
            aOrbiterD = (aWandererC + RotL64(aCross, 35U)) + 7357872882115186976U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 394402075160738643U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11112941985410283532U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14955125011182736212U;
            aOrbiterF = RotL64((aOrbiterF * 10711684773326395603U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14770727009821304070U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11286366598129204910U;
            aOrbiterE = RotL64((aOrbiterE * 15884310771003021989U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7358400908565425780U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15635109923749114761U;
            aOrbiterH = RotL64((aOrbiterH * 12415152149408700329U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13826842523738623579U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1072811298828325231U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9662800288646215083U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4017334196009350776U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8812213572751410831U;
            aOrbiterI = RotL64((aOrbiterI * 12744171921566782795U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6723457786170634403U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 9785583533999417673U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7776915427605471097U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10265132640322153964U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 8435670887514808087U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2706263045620662131U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 13U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 56U) + aOrbiterA) + RotL64(aOrbiterI, 35U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 3U)) + aOrbiterB) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 53U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererI, 36U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27311U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 28705U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31231U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 30364U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aPrevious, 13U)) + 13350544654542863236U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 5U)) + 12364346790125404372U;
            aOrbiterF = ((((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 9738750172849512764U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 3781373837635491421U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 30U)) + 16635020317512702337U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 5383653921676231276U;
            aOrbiterA = (aWandererD + RotL64(aCross, 39U)) + 10181959815492056493U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10005510924273927017U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9524687662265740565U;
            aOrbiterF = RotL64((aOrbiterF * 13687380438646756931U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4259138552009771014U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8973051213213726023U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12625091476068190979U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17602611840127337490U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8218984546932905269U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 17504305273683304231U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 18102186122213487888U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2629927500298092976U;
            aOrbiterD = RotL64((aOrbiterD * 6983280164448292723U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2491581597835795234U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9506602492971620955U;
            aOrbiterE = RotL64((aOrbiterE * 9559829640915637163U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13422942713680612924U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15037354693234876601U;
            aOrbiterH = RotL64((aOrbiterH * 12692376075738621447U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12896066842192894694U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 2202952306291905855U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6779368532763429997U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 13U)) + aOrbiterF) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterF, 23U)) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 18U) + RotL64(aOrbiterG, 57U)) + aOrbiterA) + aNonceWordD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterH, 4U)) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordG;
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

void TwistExpander_Tennis_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAD98396F6231561DULL + 0xC478AF50040CD1DBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE683D74DEACDC64DULL + 0xE7E03EDD04E2881AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF6C7DEE104A28E6BULL + 0x88C6EABB3D74A9ECULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x89342110C3B050DDULL + 0xD73EA3C4692D00E7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x96A77DFDCE2570ADULL + 0x905E6000CCE2DC0DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8ADFA9D2B75CBAEBULL + 0x9E8CE4C9490675BEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8603B88E6F9A2097ULL + 0xF602439FA31DC9AEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD67040EE8A3E4489ULL + 0x9064CFF65388B1D6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE44B214B04130AA9ULL + 0xE49246D6E3090D5EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAC2ABEC22A1092D3ULL + 0x85608583182C4686ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF292C2BEB216479DULL + 0xC222CC0E3EC72494ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEB001462AFD810E9ULL + 0x9E66B7754DBCB232ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF8FC5F267DDBA931ULL + 0xA4AE8B90D2B29EBDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xABC12637E38DA50FULL + 0x9CA9D2D0CF211C13ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEAFBB741C47B45A1ULL + 0x9374A84992CE1AA4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9D2222BCF60D658DULL + 0x9403F7E5FBBAAC88ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5949U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 1116U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3409U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7551U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 52U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererE + RotL64(aCross, 51U)) + 3255291173184001106U) + aNonceWordB;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 15308468160116255528U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 18186972408589866656U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 26U)) + 4439324265978331914U;
            aOrbiterA = (aWandererI + RotL64(aCross, 19U)) + 13099263173016322486U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 13U)) + 7041561081767500660U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 6196422612687812971U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 7664260932541281413U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17802347823020441056U;
            aOrbiterC = RotL64((aOrbiterC * 2220679459017369255U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4253107484061190446U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13799496534030645312U;
            aOrbiterA = RotL64((aOrbiterA * 9167675060053848207U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 14252892847595951926U) + aNonceWordC;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5663527578664291422U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18314294235895182465U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11148755959699137661U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17036900929333594592U;
            aOrbiterB = RotL64((aOrbiterB * 16041243617369003291U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2403828181385259549U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17813580350434928194U;
            aOrbiterK = RotL64((aOrbiterK * 13666780980793857831U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5623611126885414523U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7293224381174846969U;
            aOrbiterD = RotL64((aOrbiterD * 7032561584670788117U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10602620906929686163U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 18015916257203385982U;
            aOrbiterF = RotL64((aOrbiterF * 10684090189688871993U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterB, 35U)) + aNonceWordF);
            aWandererB = aWandererB + ((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterA, 51U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterB, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterD, 58U)) + aOrbiterJ) + aNonceWordL);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 22U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14174U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 10059U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15358U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 13506U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 36U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 5906639480605353429U) + aNonceWordN;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 5293518570213287605U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 29U)) + 15383185501428521377U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 35U)) + 15364072512743978902U;
            aOrbiterI = (aWandererI + RotL64(aCross, 19U)) + 4525473357144014271U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 10400911938125603074U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 12U)) + 16417506293824627550U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2419329331753341815U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14929222427923332069U;
            aOrbiterA = RotL64((aOrbiterA * 11596261802662514979U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16771573504983922586U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 1863466450051787622U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 2585626547126027053U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12895350137096692415U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3700979086526298327U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10279730254867618193U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1977099106211282426U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6144698304096915742U;
            aOrbiterH = RotL64((aOrbiterH * 5039822990560519609U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3858895556659724975U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1283646340363435327U;
            aOrbiterI = RotL64((aOrbiterI * 11622421841377018069U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6240532051889108891U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 757364889381634634U;
            aOrbiterF = RotL64((aOrbiterF * 943852137901972945U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5272945693977418174U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6850528198786172283U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1966383079897679953U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 12U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 29U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 35U)) + aNonceWordM) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 51U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 43U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 28U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + aNonceWordB);
            aWandererC = aWandererC + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 18U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21605U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19329U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23339U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 20198U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 54U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererF + RotL64(aPrevious, 19U)) + 16651241552253078315U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 4558144676982478003U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 5U)) + 8814884320080367550U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aScatter, 38U)) + 16011579668555672117U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 4738918668759862438U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 11U)) + 12526083125540985108U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 8048723561746000552U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1082218464034639039U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8432043246965946816U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7801965585991025451U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9982080524048636852U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6720069955755215919U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1025046364205332059U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1019035028070247757U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7360619079463870467U;
            aOrbiterA = RotL64((aOrbiterA * 6623074813047915863U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 10893918488381348474U) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1390297670907738019U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11909657437658597735U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12512200589031203480U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14741471280748399540U;
            aOrbiterH = RotL64((aOrbiterH * 3012135242889901095U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8543897248359826770U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8545972622733791272U;
            aOrbiterJ = RotL64((aOrbiterJ * 11793879362775346821U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 7049384618581928664U) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14730773807906925408U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 10711566871536755073U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + aNonceWordN) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterA, 51U));
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + aNonceWordE);
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 26449U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27341U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28138U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25191U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 28U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 18319689184146942855U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 13U)) + 8041304130090501019U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 11347064191990897738U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 15242243470024447468U) + aNonceWordO;
            aOrbiterD = (aWandererB + RotL64(aCross, 57U)) + 10619749107163611105U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 35U)) + 14795614276221947128U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 4U)) + 1578095288886372393U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13593906305770501684U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 8919815528334599172U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 2033810402808238127U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 17425548324720065145U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11125018338392347335U;
            aOrbiterA = RotL64((aOrbiterA * 4377887040461528587U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3779189180734244399U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10958224663276134041U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6206963519509783781U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4317305352561612995U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4891139433808505355U;
            aOrbiterD = RotL64((aOrbiterD * 11507024985663120317U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5166074784835930965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10080890270621589202U;
            aOrbiterB = RotL64((aOrbiterB * 13170894418184288695U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4501071771615514619U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6486573807774431753U;
            aOrbiterE = RotL64((aOrbiterE * 324029625116648669U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15714881857668975753U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3506619392820235900U;
            aOrbiterF = RotL64((aOrbiterF * 5707033870161224499U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 4U) + aOrbiterF) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterE, 29U));
            aWandererI = aWandererI + (((((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterK, 12U)) + RotL64(aCarry, 51U)) + aNonceWordH) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterK, 39U)) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterD, 21U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 53U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordK;
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

void TwistExpander_Tennis_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x92ED3F03D164F135ULL + 0xCC19FAE42763F794ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC971765CD7AB3FB1ULL + 0xB8CCD9FD8002BA89ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF521A6BEB81091C9ULL + 0xAA7559B06A139D9BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB35D76CD3F6DEB81ULL + 0x91F9E631334835E1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEC5E5532BED0DDA7ULL + 0xCE3AB70275527418ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x99FA322F5386B183ULL + 0xAE64D9C50E9B845FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEA9118DDE6A56935ULL + 0x9AF6DC2EE17A66E3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x852303D3A967CA03ULL + 0xE9E045AA644B1387ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC1ACBD9D124CCFFFULL + 0xA2DC7FF5B304E10BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDCB8549C4AFFE439ULL + 0xC22EF58BFBFC3B73ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD4AE4F62A5C58443ULL + 0xC8711C436B2E1DBEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA08A7DBDC36B84BDULL + 0x9A8A698697F11FC4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8C7B6F9AE21B5FD5ULL + 0xD582EABBA892419EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB67A156D7C1B074DULL + 0x83BCDC7B7624E06BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x92DC8C1F9E6D55ABULL + 0xB10ED01528076B34ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE6E24661C645BE07ULL + 0xDFCF7361EA14083EULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6054U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4665U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1034U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4036U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 22U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 48U)) + 5960680319644404115U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 27U)) + 16050752633567034185U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 41U)) + 8447503223226854741U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 14176813813397917591U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 23U)) + 10534915376130006644U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 6866224454375302514U) + aNonceWordA;
            aOrbiterC = (aWandererI + RotL64(aIngress, 19U)) + 16506374165041008396U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 23U)) + 7167814023968794098U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 53U)) + 13870852197416596664U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 13U)) + 18064038854848993105U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 29U)) + 9869630811507771691U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 863613100452759380U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16597969741225436529U;
            aOrbiterH = RotL64((aOrbiterH * 2680793528887208903U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 6575347108051310653U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17062262265485019063U;
            aOrbiterJ = RotL64((aOrbiterJ * 7601045488473620019U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 7193399224636409133U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14146747818810433849U;
            aOrbiterG = RotL64((aOrbiterG * 5273185769989530041U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9441449106442431427U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4303295336545399503U;
            aOrbiterD = RotL64((aOrbiterD * 8829695296836242587U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12604760768543193458U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15779327512379787715U;
            aOrbiterC = RotL64((aOrbiterC * 14000905201441272597U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15553000781122708728U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17162740616060079717U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9458662233556750239U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1032374679817715156U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16413393156165548232U;
            aOrbiterA = RotL64((aOrbiterA * 549659738811935015U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14056855000013992045U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7399202019042538829U;
            aOrbiterF = RotL64((aOrbiterF * 6103508549612077695U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2218389473339103389U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 4679497280975967770U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 9228353578259815023U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7620538119914173747U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3118355627808424159U;
            aOrbiterI = RotL64((aOrbiterI * 12481319980496032783U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16787092219237931175U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5960680319644404115U;
            aOrbiterK = RotL64((aOrbiterK * 10727217147056112401U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 50U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 43U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterA, 11U));
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 26U)) + aOrbiterE) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 21U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 29U)) + aOrbiterA) + aNonceWordM);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 44U) + aOrbiterF) + RotL64(aOrbiterI, 4U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 23U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 54U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14248U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15983U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14576U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14175U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 44U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 41U)) + 4634399531433127141U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aScatter, 47U)) + 16961792729406903200U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 44U)) + 4105280732301137738U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 35U)) + 15692013501147331191U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 1252216715968780587U) + aNonceWordK;
            aOrbiterF = (aWandererK + RotL64(aCross, 51U)) + 7958289043012473752U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 12U)) + 6611577301818896615U;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 8506226754305949140U) + aNonceWordA;
            aOrbiterA = (aWandererB + RotL64(aScatter, 23U)) + 3648813120449403353U;
            aOrbiterI = (aWandererE + RotL64(aCross, 27U)) + 5195245426245535735U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 542948051600803051U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11974253551208964789U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10596463592332655367U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 10941161258815714641U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12015129484061440159U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8254944355710109060U;
            aOrbiterH = RotL64((aOrbiterH * 3233697992479357615U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2754858806943915419U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5007802002906662779U;
            aOrbiterC = RotL64((aOrbiterC * 15613733948331639723U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6262190752136523216U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10528977986487821428U;
            aOrbiterG = RotL64((aOrbiterG * 1184258264034585525U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8511097226098211854U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12091864735686692582U;
            aOrbiterA = RotL64((aOrbiterA * 6128140528141411237U), 21U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 4970966265236842566U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10728884018459718341U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18205183219769602827U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13760057185629905360U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6590269178744829056U;
            aOrbiterD = RotL64((aOrbiterD * 14482684769712170123U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 765826377665103262U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9364759196106579706U;
            aOrbiterF = RotL64((aOrbiterF * 10315111163659289329U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4629303338428087146U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15107221579712215172U;
            aOrbiterJ = RotL64((aOrbiterJ * 14410837138199304663U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9407987092859067074U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13589362515507116096U;
            aOrbiterI = RotL64((aOrbiterI * 4544198075069052713U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2236921538387014026U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4634399531433127141U;
            aOrbiterE = RotL64((aOrbiterE * 13132011613143486575U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 20U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterK) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterG, 34U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterK, 21U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 37U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 30U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18994U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 18711U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19135U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21300U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 35U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererA + RotL64(aScatter, 39U)) + 13915875634607599122U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 53U)) + 1695770381382411673U) + aNonceWordH;
            aOrbiterC = (aWandererF + RotL64(aCross, 29U)) + 3709105579778295511U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 7673376335333251804U) + aNonceWordE;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 19U)) + 8814147709738503518U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 5U)) + 13451412605350381172U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 44U)) + 6447870234069609538U) + aNonceWordN;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 13419487997946496825U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 5478309847615220345U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 57U)) + 3635184969215610049U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 60U)) + 12527903812035294828U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 1684685110885338814U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12860354576326835090U;
            aOrbiterC = RotL64((aOrbiterC * 12743745087733307255U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9081823570147481835U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14369321778210049109U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17865953349448767035U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11518132079084873250U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11893535026126957389U;
            aOrbiterH = RotL64((aOrbiterH * 15751374986135615095U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7084079180579206226U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2999676609847603277U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 14602698397511266403U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 17683445810614029153U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11576460512964896969U;
            aOrbiterA = RotL64((aOrbiterA * 5243651036457051155U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13429800604736567949U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14661785761747367546U;
            aOrbiterE = RotL64((aOrbiterE * 4765843989277333421U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12837164345582888950U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 6222666313184669392U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 17402483466567712319U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5358647039491079457U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12459911673401497180U;
            aOrbiterB = RotL64((aOrbiterB * 13605465035256188065U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3333017644772803587U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15501587702102554928U;
            aOrbiterI = RotL64((aOrbiterI * 4921693371641768339U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8492287653837766613U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3432736785678875404U;
            aOrbiterF = RotL64((aOrbiterF * 7326419883291516513U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2841486107704281869U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13915875634607599122U;
            aOrbiterJ = RotL64((aOrbiterJ * 707861617246345083U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 30U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 13U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 42U) + RotL64(aOrbiterE, 37U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterA, 30U));
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterA) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 53U));
            aWandererA = aWandererA + ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 42U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 14U) + aOrbiterH) + RotL64(aOrbiterI, 35U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 30U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32584U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 25270U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28056U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 31226U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 19U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aScatter, 53U)) + 5568146815535263910U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 48U)) + 7736084960873834666U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 3U)) + 1336413621817562093U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 5218462026934984692U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 7048890985969555935U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 13415955213864702118U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 46U)) + 5657023257021528548U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 35U)) + 14338310943137497116U;
            aOrbiterI = (aWandererD + RotL64(aCross, 11U)) + 12305161641833950473U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 51U)) + 14514226578370459131U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 5U)) + 12692904083266024340U) + aNonceWordN;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11012959130001327964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7106471380403489078U;
            aOrbiterK = RotL64((aOrbiterK * 515626559384817223U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3718101961355280891U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13364192077222322664U;
            aOrbiterD = RotL64((aOrbiterD * 1411328915372590283U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6720867800318913440U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14497243926965866546U;
            aOrbiterE = RotL64((aOrbiterE * 13595058589060114653U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5789056168233262435U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14438482587495779937U;
            aOrbiterA = RotL64((aOrbiterA * 10593535547917767263U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 313917798940179945U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15241845511889502917U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16483477103771326107U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3591957424821693032U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1559050939014453558U;
            aOrbiterI = RotL64((aOrbiterI * 17933346117866604725U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 15340590914441451383U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5538037287390050110U;
            aOrbiterB = RotL64((aOrbiterB * 4082576643144951473U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4151270491894969214U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 263593701314144898U;
            aOrbiterF = RotL64((aOrbiterF * 10372046955804512457U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9025145270653080646U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6867950904094870056U;
            aOrbiterC = RotL64((aOrbiterC * 9975247022340627751U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3183454301841252109U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3054904157641290615U;
            aOrbiterJ = RotL64((aOrbiterJ * 4092317552439599475U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1768555574434776135U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5568146815535263910U;
            aOrbiterG = RotL64((aOrbiterG * 12466957001078663927U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 24U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 12U) + aOrbiterE) + RotL64(aOrbiterG, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 48U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterI) + aWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 37U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterD, 23U));
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 13U)) + aOrbiterH) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterD, 54U)) + aOrbiterE) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterI, 21U));
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 40U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordD);
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

void TwistExpander_Tennis_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFA27AF736EDAFDAFULL + 0xFEF3B8EB905FD917ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB186D6501888D7BFULL + 0xA6F3F0D455A683DDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x86401FB888A30551ULL + 0x92E63C7DFEC3848DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA73B8B0D56891BF9ULL + 0x9104F7B833C1767EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC3EE40909FB52D8DULL + 0xD80A87BC3B7E3EA9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA708212D2A16DBF5ULL + 0xAD63ACFAF9A16190ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE4EB1F61406AC267ULL + 0xCD6F1633DC5BFAA4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC82B79C25D6BA243ULL + 0xE051EE1DB85150E3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD720B8C9AB38F46BULL + 0xA8E4EC307274C564ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD86F7EA9538A2C4DULL + 0xE5826146367419F4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFF68DD410F6C1B77ULL + 0x8E47FC59AF9187ABULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF7CED72E338C511BULL + 0xABA299E74C41107DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAB99C5CB35913145ULL + 0x8CEC32B3CC06413DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCD1E97CCFA4626C5ULL + 0xDAF7D72501E6F0AEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC7F4A3B5517C6283ULL + 0x88511BE463BAEDA0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8995D18AA9E586BFULL + 0x8178019E824E47FCULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 31U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneC[((aIndex + 4491U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2755U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((aIndex + 3307U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 4U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 29U)) + 3550722402315312207U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aScatter, 11U)) + 16724184551669522754U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 24U)) + RotL64(aCarry, 53U)) + 981751330116773021U) + aNonceWordO;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 7891159229704944868U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 47U)) + 13618396711464799841U;
            aOrbiterH = (aWandererG + RotL64(aCross, 51U)) + 5969291018449003648U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 30U)) + 14595540413313640042U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aIngress, 57U)) + 3287990436916111762U) + aNonceWordG;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 5U)) + 12534369400200483704U) + aNonceWordF;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2277312067930392274U) + aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10026320559261334353U;
            aOrbiterB = RotL64((aOrbiterB * 11020464940995912637U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11258082063135659551U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1445958517675746990U;
            aOrbiterH = RotL64((aOrbiterH * 10062265337488757971U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1011298251290970844U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6487834862470043744U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15477913837027179675U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9966279022928268335U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10285993486057704393U;
            aOrbiterI = RotL64((aOrbiterI * 15965714363201157535U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16005362468813966136U) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 223843444699390781U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 665392038954573081U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18178876294968532775U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12490136112181806806U;
            aOrbiterG = RotL64((aOrbiterG * 16380841616662993709U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8775696166557913635U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16464340319444310842U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18111632334728200721U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6296039992673546227U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7152939277656436037U;
            aOrbiterE = RotL64((aOrbiterE * 15183918431501487319U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14066791413416223271U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5026743227399908016U;
            aOrbiterF = RotL64((aOrbiterF * 5891343232759075675U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (RotL64(aOrbiterA, 18U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 19U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 36U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 13U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 38U)) + aOrbiterC) + aNonceWordL);
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 56U) + aOrbiterK) + RotL64(aOrbiterA, 53U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterC, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterA, 27U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 4U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6355U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9930U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7932U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7393U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 26U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 57U)) + 2225397913940961213U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aScatter, 44U)) + 8342544893601343643U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 11U)) + 162922186381417187U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 39U)) + 11660218373710972210U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 14909034764605802354U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 16776955237009701511U;
            aOrbiterI = (aWandererD + RotL64(aCross, 48U)) + 5834487809188925253U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 1498492772767040320U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 35U)) + 4161765458781579617U) + aNonceWordB;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10511923076962447765U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8575954471692620021U;
            aOrbiterB = RotL64((aOrbiterB * 12526744988828982731U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6536325446331340573U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1790628986900286346U;
            aOrbiterF = RotL64((aOrbiterF * 5262997114200816715U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2623814807619278590U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11676970995834706612U;
            aOrbiterI = RotL64((aOrbiterI * 10057461115132434901U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13836786354224256591U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6293096163612129260U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8977954126326217153U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4271144764978661248U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15938494256992560202U;
            aOrbiterE = RotL64((aOrbiterE * 10004841288382726739U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11038155227307702976U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12408749795071243930U;
            aOrbiterJ = RotL64((aOrbiterJ * 5527720475032868855U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1673665849053496882U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12866353361497103629U;
            aOrbiterD = RotL64((aOrbiterD * 6041125499398924871U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10673935802381580966U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8946776538955520352U;
            aOrbiterK = RotL64((aOrbiterK * 12293084177712710021U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16294935203370452805U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4697759331563852212U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 14407806317275373043U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 46U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 38U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 43U)) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + aNonceWordF);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterI, 56U)) + aNonceWordO);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 3U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 51U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 56U) + aOrbiterE) + RotL64(aOrbiterK, 23U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 22U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13648U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 16042U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12432U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 11241U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aScatter, 38U)) + 17081642665820489793U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 47U)) + 14468854040067229623U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 13U)) + 2249450222593057429U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aCross, 57U)) + 14964389079511378664U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 17003491054252360650U) + aNonceWordI;
            aOrbiterE = (((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 12710882240582032588U) + aNonceWordF;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 9887078182156755359U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 34U)) + 7665284531810584704U;
            aOrbiterD = (aWandererA + RotL64(aCross, 29U)) + 7304284015511876717U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5517927023543751734U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17704756310857362759U;
            aOrbiterG = RotL64((aOrbiterG * 15826832172923213591U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11347400363019508578U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11696395232760991243U;
            aOrbiterF = RotL64((aOrbiterF * 9725231749679442003U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10875780291242873583U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7808740614343437672U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8889516201913716283U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3145390996141902032U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16080636485642732615U;
            aOrbiterK = RotL64((aOrbiterK * 7445756373012217305U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3929263288176983844U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 18210228766683996806U;
            aOrbiterI = RotL64((aOrbiterI * 13178080076505449091U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13948962323541421431U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3037683309790156893U;
            aOrbiterE = RotL64((aOrbiterE * 13406672352222636739U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 17827265198532699474U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7270895262023504864U;
            aOrbiterH = RotL64((aOrbiterH * 13467417362477308167U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6431243064980879185U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 6680205390976259885U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10421386694108590789U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15910655919164357152U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8046213498216027383U;
            aOrbiterD = RotL64((aOrbiterD * 18061867495824063553U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 40U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 10U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 30U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + aNonceWordM) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 57U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 37U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 52U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterE, 27U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 26U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererD, 14U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16665U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17682U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19115U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20252U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 4U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aCross, 11U)) + 1364174714924216027U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 27U)) + 13561796874229506613U) + aNonceWordG;
            aOrbiterC = (aWandererH + RotL64(aScatter, 5U)) + 11845572344206238305U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 39U)) + 15762708240326773763U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 44U)) + RotL64(aCarry, 53U)) + 1157119665207900473U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aScatter, 35U)) + 6823546624372055260U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 14465564210523945121U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 10667464548080807531U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 60U)) + 13445737493224316575U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3009837893785957665U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2886920524111083752U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15308180928967762543U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10886177449328249656U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15067759884678100433U;
            aOrbiterF = RotL64((aOrbiterF * 5724566815989860041U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 18307930462682331536U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8791864377579255801U;
            aOrbiterK = RotL64((aOrbiterK * 9265158882471421767U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 805797468642992351U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5743305867058244964U;
            aOrbiterB = RotL64((aOrbiterB * 16263000753351131717U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 17102025528234481273U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 1841579177327486899U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 3841603385577825265U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2189493507896508972U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 18209567010094914374U;
            aOrbiterD = RotL64((aOrbiterD * 3737080408976852351U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6697069234216868330U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 927471474577415372U;
            aOrbiterA = RotL64((aOrbiterA * 10680760991009199309U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13155854301197725408U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1014625081915435892U;
            aOrbiterI = RotL64((aOrbiterI * 11592754232949990435U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12697209921410914931U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 11555096613655648647U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 4598821388864997089U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 23U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 56U)) + aOrbiterA) + aNonceWordC);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 19U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 48U) + aOrbiterF) + RotL64(aOrbiterK, 27U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterK, 37U)) + aNonceWordE) + aWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 14U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterK, 43U)) + aNonceWordA);
            aWandererB = aWandererB + ((RotL64(aScatter, 10U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 22U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22398U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 25699U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22443U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 23588U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 47U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 60U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererG + RotL64(aScatter, 34U)) + 701291026547470433U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 17283292650462111643U) + aNonceWordC;
            aOrbiterG = (aWandererF + RotL64(aCross, 53U)) + 9969124091931303406U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 889176772718046988U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 47U)) + 6054541844643748084U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 29U)) + 14703226235143028132U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 18U)) + 7977975878522921062U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 16894322614172266274U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 39U)) + 12160451749345900570U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10870847008043897470U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8159920947172520247U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4833194641611011805U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2440099120969517932U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2428396147731468007U;
            aOrbiterK = RotL64((aOrbiterK * 9363073341539598441U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 2213226274394673479U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 7079731443427765333U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 16918930776877030559U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 958896789550478970U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10788682955708075458U;
            aOrbiterB = RotL64((aOrbiterB * 913321215613559729U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 2003386579317564870U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8419686358774204999U;
            aOrbiterI = RotL64((aOrbiterI * 6547052526438697621U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6989167615157578904U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17636634003643824148U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11038576417283732937U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13824962118933907859U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9543912892587859646U;
            aOrbiterD = RotL64((aOrbiterD * 14736710162285997415U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15729878041027706114U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9542137475454825463U;
            aOrbiterH = RotL64((aOrbiterH * 11420547128115090491U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5327302277575009955U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2707383132257428583U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6120763309390182129U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 6U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterH, 10U)) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aScatter, 58U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 51U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 39U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterD, 60U));
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterG, 43U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 4U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27878U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 30344U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30592U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((aIndex + 29808U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 19U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 48U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererI + RotL64(aScatter, 5U)) + 9888431329297626900U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 2937735167534624403U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 29U)) + 17626022970343789617U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 23U)) + 5665660859333693743U) + aNonceWordG;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 18U)) + 1060537034632076669U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 39U)) + 743777763907175800U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 5744905970181808845U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 57U)) + 3545351394494002180U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 48U)) + RotL64(aCarry, 39U)) + 4877547088414106007U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11669378338379598445U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2961072441706158212U;
            aOrbiterB = RotL64((aOrbiterB * 2677988507090705371U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 13984945589234919765U) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1433097875470903205U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 451996840039906781U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 716415411025451152U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8542286150858297810U;
            aOrbiterH = RotL64((aOrbiterH * 9139015340823332449U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12932391786479661299U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14005503313299177013U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 802663466907819743U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9382792812676318046U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5138554251079724724U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6386016499265056247U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8522380066269546172U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11825536408101906458U;
            aOrbiterA = RotL64((aOrbiterA * 17042837108792016849U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15504062350899452495U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 1219010998820336744U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10650635772711590803U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6442717843380349632U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1047843426279085117U;
            aOrbiterD = RotL64((aOrbiterD * 4074561571072878005U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10611039527108679173U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 5092816736177358221U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14342779343820140833U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 18U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 43U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 18U) + aOrbiterF) + RotL64(aOrbiterE, 13U));
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterK, 22U)) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterA, 39U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 58U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 28U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_Tennis_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFB00942CA29300B1ULL + 0xF598E84340C82F63ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x894A96AF7DA24E23ULL + 0x916667133B6DD81BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9EC96A8DA279A6B9ULL + 0xD3852A887A6DC4C3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC4E23F95B2E34E47ULL + 0xB089FA99319A6310ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCFACCC46E39279F5ULL + 0xFC39614FE7C52F33ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8730D6BF263CE85DULL + 0xC158C661B19FE699ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD900F2A1E6B6E783ULL + 0x97956E12FC796837ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC553774F2C1AC18BULL + 0xF18275356B1D556FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB56975A4C020531FULL + 0x9970E95E2D2EC478ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD06BE101126817EFULL + 0x890EEE1F6F4DCB69ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCAD1371CD085895BULL + 0xF631E8ECAD3AC346ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDE5B01060C1D0167ULL + 0xB04F1DF5302AE392ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x89D63992DE69E893ULL + 0xB178D3D32DA46512ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCC92E6962BDF146BULL + 0x85E439896AD6E4A7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9713067052ECE87BULL + 0xBF7A1AA142278F15ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE2CB6B263DA1E3CFULL + 0x99968DFD81DC9244ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 955U)) & S_BLOCK1], 22U) ^ RotL64(aKeyRowReadA[((aIndex + 5327U)) & W_KEY1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 5206U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1753U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 54U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 3561491146322798260U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 51U)) + 7075025056181885339U) + aNonceWordB;
            aOrbiterI = ((((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 9230910887904171613U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 4119781172609908917U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 34U)) + 17155609083870983149U) + aNonceWordE;
            aOrbiterD = (aWandererC + RotL64(aIngress, 57U)) + 2423018561430181695U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 5U)) + 12957280305617615744U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 2461704174772065813U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7907123257849391997U;
            aOrbiterI = RotL64((aOrbiterI * 9416171962847312179U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7257868138318960007U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16425903703085702285U;
            aOrbiterG = RotL64((aOrbiterG * 7996935869077231999U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2990822664594079467U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5654819006718953817U;
            aOrbiterD = RotL64((aOrbiterD * 4465096036756887801U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12183676471235678779U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15026286960542123922U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17199049329995315279U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12169080607071830522U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2906296852254787499U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6754514406846040163U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3029858695410344584U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14406410317495954566U;
            aOrbiterA = RotL64((aOrbiterA * 9663780721657983421U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11048818178401163861U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13622063920319445043U;
            aOrbiterB = RotL64((aOrbiterB * 2516025554421589857U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 27U);
            aIngress = aIngress + (RotL64(aOrbiterG, 10U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 42U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + aPhaseAWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterA, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC + (((((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aNonceWordP) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordF);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6062U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 7138U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8279U)) & W_KEY1], 28U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7168U)) & W_KEY1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 50U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 13U)) + 12380376990224645149U) + aNonceWordD;
            aOrbiterH = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 18296928500297384014U) + aNonceWordP;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 57U)) + 3550626816361145100U) + aPhaseAOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 36U)) + RotL64(aCarry, 47U)) + 2667792936946706027U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 51U)) + 12020969779370926953U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 737340727886903447U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 29U)) + 1681797651799760502U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2956186342689489064U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1876852870402977177U;
            aOrbiterK = RotL64((aOrbiterK * 8875540081346621757U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6433205819353555071U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9065076854974222998U;
            aOrbiterJ = RotL64((aOrbiterJ * 5459675878087242021U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3254410578766789992U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2005081975473815576U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9947701153722014085U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15992999234834560419U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 3458344156815120948U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1668460113964608051U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 17069783053664877727U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1260234710193913099U;
            aOrbiterG = RotL64((aOrbiterG * 4561226779897414381U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3825186451876061335U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2905344294992827535U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2469896090698580795U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18141402347899180617U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8760129857609925066U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 2507999156108123047U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterJ, 29U));
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 41U)) + aOrbiterD) + RotL64(aCarry, 51U)) + aNonceWordA) + aPhaseAWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterG, 19U)) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 50U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 52U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13792U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14212U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11505U)) & W_KEY1], 38U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13516U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aCross, 35U)) + 18191288703716505885U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 57U)) + 9824014524910417136U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 11953012029254917548U) + aPhaseAOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 41U)) + 6297568011027199089U) + aNonceWordB;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 2576999400457367975U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 20U)) + 13176139160575558254U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 9978408174563621810U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 16765834875061607142U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16534507305459121344U;
            aOrbiterC = RotL64((aOrbiterC * 8943988574248229067U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3114710944346151807U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10240517868726718592U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 4645691562915606463U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10721450637990777883U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16689590768796583952U;
            aOrbiterI = RotL64((aOrbiterI * 3046344179729901637U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2427422768928450209U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 13495584061816457831U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 6670984773768885119U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7058636403765106682U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9897341853944713767U;
            aOrbiterD = RotL64((aOrbiterD * 14286816859999869231U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17749559755733386064U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12515645083926326659U;
            aOrbiterA = RotL64((aOrbiterA * 6582878478865838245U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2625692458813609962U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10596240255026143019U;
            aOrbiterK = RotL64((aOrbiterK * 11605800195771080135U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 22U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + aNonceWordC);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 35U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 14U) + aOrbiterB) + RotL64(aOrbiterA, 26U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + aPhaseAWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 13U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 47U)) + aOrbiterD) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererG, 34U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20117U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 17115U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17722U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 17751U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 52U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (aWandererC + RotL64(aScatter, 23U)) + 6381335981879993247U;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 15595429101600023172U) + aNonceWordA;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 12U)) + 5449234297249826461U) + aPhaseAOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 11213734849329731168U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 43U)) + 16438473952464514248U;
            aOrbiterF = ((((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 7357872882115186976U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 37U)) + 394402075160738643U) + aNonceWordO;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11112941985410283532U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14955125011182736212U;
            aOrbiterJ = RotL64((aOrbiterJ * 10711684773326395603U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14770727009821304070U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11286366598129204910U;
            aOrbiterF = RotL64((aOrbiterF * 15884310771003021989U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7358400908565425780U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 15635109923749114761U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 12415152149408700329U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13826842523738623579U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1072811298828325231U;
            aOrbiterI = RotL64((aOrbiterI * 9662800288646215083U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4017334196009350776U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8812213572751410831U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12744171921566782795U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6723457786170634403U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9785583533999417673U;
            aOrbiterA = RotL64((aOrbiterA * 7776915427605471097U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10265132640322153964U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8435670887514808087U;
            aOrbiterH = RotL64((aOrbiterH * 2706263045620662131U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 58U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 12U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 35U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 19U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterC, 27U)) + aNonceWordE);
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 41U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23556U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 26101U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22886U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23543U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 58U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 5U)) + 3650233661228036955U) + aNonceWordP;
            aOrbiterF = (aWandererK + RotL64(aScatter, 51U)) + 11607036400067735729U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 21U)) + 3899614406903883035U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 57U)) + 8159156925629965143U;
            aOrbiterJ = ((((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 7148903913967261270U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 28U)) + RotL64(aCarry, 51U)) + 9161665622287517848U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 2981535013474059469U) + aNonceWordM;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15812469008200319549U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14687469489893270300U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14142363399696670451U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6025209349511417063U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12964750392311112676U;
            aOrbiterD = RotL64((aOrbiterD * 12955480283032701843U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 6572355895765394340U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3542300121890027981U;
            aOrbiterA = RotL64((aOrbiterA * 11201491178181273935U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6477175684045398359U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1081388388827929314U;
            aOrbiterF = RotL64((aOrbiterF * 8752188637514143529U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13754328481584620771U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3684673342659575917U;
            aOrbiterJ = RotL64((aOrbiterJ * 6139923312873039143U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6542045150319909445U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 5352102692424060388U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7385758355501860261U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9110100774657340354U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2813273684436269057U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 10468759062594022273U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterI, 60U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            aWandererE = aWandererE + ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 13U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterD, 41U)) + aNonceWordE);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 21U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 35U)) + aNonceWordG) + aPhaseAWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererA, 36U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32726U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 28896U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32287U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 30409U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 56U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aScatter, 21U)) + 1708250618750199233U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 3U)) + 12009147777553691142U) + aPhaseAOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 10U)) + RotL64(aCarry, 5U)) + 8393982703399156592U) + aNonceWordK;
            aOrbiterD = (aWandererI + RotL64(aIngress, 57U)) + 3247327098356831221U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 37U)) + 3403590155376353737U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 37U)) + 18197244558104735044U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 3096253642040701606U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8012692688785412179U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17531946907545680745U;
            aOrbiterA = RotL64((aOrbiterA * 16510602981731506381U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17687695944270225817U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16147773866007628769U;
            aOrbiterB = RotL64((aOrbiterB * 16926442582711557877U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 18244641303026196497U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8839160526348897457U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14268021129087663397U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10599266240854068246U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2056723540756216155U;
            aOrbiterC = RotL64((aOrbiterC * 13311591601230386375U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4629354220460621284U) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 9505955649473204942U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17775391885312236187U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 17078153810088721310U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9470436761716263000U;
            aOrbiterD = RotL64((aOrbiterD * 5431855497250357229U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3305863413630104742U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14377172434239576161U;
            aOrbiterK = RotL64((aOrbiterK * 6880176890091033423U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterK, 41U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterF, 22U)) + aNonceWordO) + aPhaseAWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterG, 47U)) + aNonceWordE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterB, 5U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + aPhaseAWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordI;
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

void TwistExpander_Tennis_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA40AF104C42883CDULL + 0xC485DB94070C5182ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x96B7169C6B7AAD21ULL + 0xCFCF3FC7C4EBA2A2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8CFFB9E85552B599ULL + 0xEB9A21B04AA747CBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE86C4B48EFD5D2DDULL + 0x9D0DE53AA3EE49C4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA459AB95B59732E1ULL + 0x889F982E517BB3FBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA954C32B07B538B3ULL + 0xDEABF8ABE98CB1FCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD732FE547CFEFFC3ULL + 0xA061553AA136DE8EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC5387693BE238EB7ULL + 0xE10F439C0BF07D0FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF94E4AFF1950C097ULL + 0xA5CE01B648D8FB13ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x998268EF88466235ULL + 0xF05739B9BCD9FDDCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA32E3CFFBA4E0BE9ULL + 0x8EB3D856C5D195EFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBCEBD4B43CDA650DULL + 0xB0621D919C23BBC2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8186E93A8DCEF8D7ULL + 0xF1C3F39E712FCCFAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAD80759CE4BAFA03ULL + 0xA8CA62A394309C40ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9F166662F7BB830BULL + 0xB16CEF817FC02623ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF6576A0AC38EDDB5ULL + 0xC4939E7A0BDBBB90ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2232U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1259U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3804U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4944U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 6U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (aWandererH + RotL64(aScatter, 27U)) + 4622023259121087483U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 10253505250223501352U) + aNonceWordH;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 17133877904420462669U) + aNonceWordO;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 56U)) + 6162827793741796700U) + aPhaseBOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 41U)) + 9610986424765907615U) + aPhaseBOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11210747154264753754U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16554205219580654546U;
            aOrbiterK = RotL64((aOrbiterK * 12754735039924859911U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10352576357413766388U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 3651845783283479752U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 1011289824180799641U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18145542190463500476U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5415609566767162857U;
            aOrbiterJ = RotL64((aOrbiterJ * 6474184559323816389U), 21U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 2033734872464201570U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3507213117125813345U;
            aOrbiterH = RotL64((aOrbiterH * 5453058336688881113U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8716253393049851856U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 695984869565941856U;
            aOrbiterD = RotL64((aOrbiterD * 8377921610764044735U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 11U)) + aNonceWordP) + aPhaseBWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 51U)) + aPhaseBWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 24U) + aOrbiterI) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterD, 41U));
            aWandererH = aWandererH + ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8424U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 8896U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8799U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8476U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 19U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 57U)) + 10336802574069791273U) + aNonceWordB;
            aOrbiterE = ((((aWandererG + RotL64(aIngress, 30U)) + RotL64(aCarry, 5U)) + 169025388197058936U) + aPhaseBOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 6541354188379168846U) + aPhaseBOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 16223920526599306104U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 3U)) + 12756613707692514808U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 5082475548176484035U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4907435526952698526U;
            aOrbiterF = RotL64((aOrbiterF * 1379692095754989215U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14236627073831834337U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11502511046130497584U;
            aOrbiterK = RotL64((aOrbiterK * 3460330807286625917U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3679044835550219497U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 11254838916686736746U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 8631695922983532915U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10582608424233200966U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10449735026385340313U;
            aOrbiterE = RotL64((aOrbiterE * 7363770199734997411U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4628253464169957835U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 17664454668473204465U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4234720298731378527U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + aPhaseBWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 40U) + aOrbiterK) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 50U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterE, 37U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13101U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15671U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15422U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 12968U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 26U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = ((((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 7790166497945719700U) + aPhaseBOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aWandererK + RotL64(aCross, 18U)) + 7136208896846119188U) + aNonceWordG;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 12123156943355100886U) + aNonceWordC;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 5095546037880875199U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 35U)) + 17642705393916765992U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9918479837334416990U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4890009823843176466U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 16898633181256061239U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17652590786213674124U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 870002527644696135U;
            aOrbiterD = RotL64((aOrbiterD * 915408393979165539U), 27U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 12545429703552643682U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5310272867406182581U;
            aOrbiterC = RotL64((aOrbiterC * 10420003334833925011U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 3264719049050179440U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1967241238180278937U;
            aOrbiterJ = RotL64((aOrbiterJ * 13004319774269457957U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 773883832927040736U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12766817190261232485U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 7448864556802318431U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 6U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterG, 44U)) + aNonceWordP);
            aWandererC = aWandererC + (((((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aNonceWordH) + aPhaseBWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 29U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 52U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19232U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19331U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21487U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21705U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 3U)) + (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 24U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 966899917801652720U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 3U)) + 10996327672320748649U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 34U)) + 4188171566846621107U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 5886209243097387959U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 14940428957136728111U) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 179187285531914832U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6685351948936817752U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15533370414711696803U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 1894506461704029700U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 4182760368636977082U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 972988091869133921U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12523318028514940790U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5059306166973366892U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2857409765717296483U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5890872367917643851U) + aNonceWordJ;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17747338389865221534U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 5306740664798049267U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13906227834259884100U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7152105382899756368U;
            aOrbiterK = RotL64((aOrbiterK * 6772157117358310485U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 40U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 3U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterF, 50U)) + aNonceWordA);
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterI, 21U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 20U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22104U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25864U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25666U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22457U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 37U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 6467297102954816305U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 7921154109831114952U) + aNonceWordD;
            aOrbiterK = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 5701131763215638919U) + aPhaseBOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 38U)) + 10022999076719002684U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 3U)) + 4367135243038982316U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14445846824810383592U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 7683697954545773253U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 4832124801510084629U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 17517006750428030899U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2052484792684025476U;
            aOrbiterA = RotL64((aOrbiterA * 12463117571122469643U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6279463052085808926U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 679280153651813684U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3047031560593583881U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2939516520188460569U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1960616434964712325U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15145998415466343039U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12273819390719947361U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5685033154709449397U;
            aOrbiterJ = RotL64((aOrbiterJ * 9845666295874714959U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 58U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterF, 27U)) + aPhaseBWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterH, 54U)) + aPhaseBWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 54U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28304U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31724U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30838U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 32091U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 29U)) + 8375305456876489425U) + aPhaseBOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 5U)) + 16193562952772453047U) + aNonceWordL;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 18088652458594816223U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 56U)) + RotL64(aCarry, 41U)) + 767344788620249944U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 7705194930396368752U) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3829736891311272834U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 9881681671347640061U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14380245087931793021U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1721196560190164264U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3002652618388454213U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15289749311593032657U), 41U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 9811621464004005202U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5652598941069986530U;
            aOrbiterJ = RotL64((aOrbiterJ * 4797973356708091621U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 6250499348327316328U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16025054277615264530U;
            aOrbiterI = RotL64((aOrbiterI * 16446892258704281903U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13800298546867243172U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12256104592865905782U;
            aOrbiterG = RotL64((aOrbiterG * 16983140179497142713U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + aPhaseBWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 34U) + aOrbiterJ) + RotL64(aOrbiterB, 30U)) + RotL64(aCarry, 23U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 47U));
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 39U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterB) + aNonceWordH) + aPhaseBWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordF);
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

void TwistExpander_Tennis_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEB2A46F904E4BC23ULL + 0xA6ADADCEE427DB42ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB7DE05016F7529E7ULL + 0xF6DF7F9D2A62A547ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB86A508C4D25261BULL + 0xD56CFE3D3A87D071ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x828B2892E87BA451ULL + 0x820B92DFC8FE0AB1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE217E6562FBDB02BULL + 0xAC35306A0EB65AD8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9366853E655D9DDDULL + 0x8106EA992C0FD44DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDA9589F27B5266C7ULL + 0x9B9CDF5601E1A2FDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC569A51A850E6177ULL + 0x89C9A87B887C577CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x924845B407DA4EF7ULL + 0xFDF01919A6C38561ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8FD18A5F885B1031ULL + 0xDA591934E2E2E5ECULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDFBAF16F3BDEDF95ULL + 0xF3373E4324C4D915ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8C5ED1F88DEBC3EDULL + 0xCDFC60BEAD1F0939ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB1C1B070FE863689ULL + 0xEAAF4CAD6BB4A204ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA7A21599DEC5545BULL + 0xD396DF8F380A857AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEE07D605D5A30B07ULL + 0xD1B9C1A830C6DA99ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB5C5F6A31FE2FA8DULL + 0xA7441403C04070C2ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3879U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 5012U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5739U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1074U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 48U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (((aWandererD + RotL64(aScatter, 10U)) + RotL64(aCarry, 19U)) + 5960680319644404115U) + aNonceWordI;
            aOrbiterD = (aWandererA + RotL64(aIngress, 39U)) + 16050752633567034185U;
            aOrbiterI = (aWandererH + RotL64(aCross, 19U)) + 8447503223226854741U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 5U)) + 14176813813397917591U;
            aOrbiterA = ((((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 10534915376130006644U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 6866224454375302514U) + aNonceWordJ;
            aOrbiterK = (aWandererJ + RotL64(aCross, 14U)) + 16506374165041008396U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 47U)) + 7167814023968794098U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 27U)) + 13870852197416596664U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 18064038854848993105U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9869630811507771691U;
            aOrbiterI = RotL64((aOrbiterI * 13723164383800461387U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 863613100452759380U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 16597969741225436529U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 2680793528887208903U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6575347108051310653U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17062262265485019063U;
            aOrbiterC = RotL64((aOrbiterC * 7601045488473620019U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 7193399224636409133U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14146747818810433849U;
            aOrbiterF = RotL64((aOrbiterF * 5273185769989530041U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9441449106442431427U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4303295336545399503U;
            aOrbiterH = RotL64((aOrbiterH * 8829695296836242587U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12604760768543193458U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15779327512379787715U;
            aOrbiterB = RotL64((aOrbiterB * 14000905201441272597U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15553000781122708728U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17162740616060079717U;
            aOrbiterK = RotL64((aOrbiterK * 9458662233556750239U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1032374679817715156U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 16413393156165548232U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 549659738811935015U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14056855000013992045U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7399202019042538829U;
            aOrbiterA = RotL64((aOrbiterA * 6103508549612077695U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 48U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 27U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterB, 41U));
            aWandererF = aWandererF + ((RotL64(aScatter, 36U) + aOrbiterD) + RotL64(aOrbiterA, 36U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterI, 51U));
            aWandererA = aWandererA + (((((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordO) + aPhaseCWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 46U)) + aOrbiterK) + aPhaseCWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordJ);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12611U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 10217U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14156U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 12071U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 3U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aCross, 53U)) + 7960325128608297381U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 12773836012104052042U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 46U)) + 3173972621347773016U) + aNonceWordE;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 3708401356314308171U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 950774285720019449U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 37U)) + 4170092315705438265U) + aNonceWordF;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 4U)) + 17000449130864980747U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 11U)) + 8793910540062893860U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 29U)) + 520277969543516469U) + aNonceWordP;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12762214857389827271U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2932451184340207695U;
            aOrbiterF = RotL64((aOrbiterF * 7513337346940091655U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11062179998786293839U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7919119215271524178U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9053677007180081359U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 1774988449597115155U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3799792889466518953U;
            aOrbiterA = RotL64((aOrbiterA * 17512791286490623455U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1815062051307896589U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15260373951371654483U;
            aOrbiterB = RotL64((aOrbiterB * 2208604434669491625U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12867546628945676853U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7772820973895846946U;
            aOrbiterD = RotL64((aOrbiterD * 7581704643538761985U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14213957831821966834U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16561105721170419454U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 2540533987337175367U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16556502948339949526U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9706742922075498974U;
            aOrbiterI = RotL64((aOrbiterI * 8527361328901355457U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13455756934917486016U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 9107769876332723454U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1722386100852683783U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15793099079168487016U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7968278803691283365U;
            aOrbiterC = RotL64((aOrbiterC * 11644765391940099387U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 34U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 48U) + aOrbiterE) + RotL64(aOrbiterK, 52U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 3U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 13U)) + aOrbiterF) + aPhaseCWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 35U)) + aOrbiterI) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 47U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 39U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterC, 60U));
            aWandererA = aWandererA + (((((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 39U)) + aNonceWordC) + aPhaseCWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 23U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordC);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21443U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 20932U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20158U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneC[((aIndex + 21009U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aScatter, 3U)) + 17470880031634374199U;
            aOrbiterI = (aWandererA + RotL64(aCross, 13U)) + 757565846006937746U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 34U)) + 9419282475801345674U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 2014248014107898196U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 43U)) + 15113928519446490441U) + aPhaseCOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 47U)) + 7346126964886259935U) + aNonceWordO;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 39U)) + 5594123113093162359U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 54U)) + RotL64(aCarry, 19U)) + 5659237263369402005U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 11565709683423969703U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16782863743534856287U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13499100900072115907U;
            aOrbiterA = RotL64((aOrbiterA * 5567729598873214433U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11414447651044205242U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7545993795121430538U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10758488381206257261U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11778229237616454988U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2544793391976514665U;
            aOrbiterF = RotL64((aOrbiterF * 4021060413798523299U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9972156716619459164U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17651030383827445664U;
            aOrbiterI = RotL64((aOrbiterI * 6742914240706775487U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17439147296849134543U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10021926927948343656U;
            aOrbiterH = RotL64((aOrbiterH * 18139540407315440909U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9309867875882669289U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14951424455944346337U;
            aOrbiterB = RotL64((aOrbiterB * 10569523948169951309U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2166343974068770659U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11386993629011562026U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 3091639433512536097U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5747849744680120960U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4019290369160113026U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5567515306039646735U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3820540009554769592U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8210747198363020939U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16215133106542452509U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 26U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 47U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 60U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + aNonceWordG);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterK, 21U)) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aScatter, 30U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 39U)) + aOrbiterG) + aPhaseCWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 26U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordB);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31912U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32555U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27193U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29585U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 51U)) + (RotL64(aCarry, 23U) + RotL64(aPrevious, 6U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aCross, 48U)) + 12692813903177772178U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 7112496446691277899U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 2112247138290568813U) + aNonceWordD;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 3699421080882855947U;
            aOrbiterC = (aWandererB + RotL64(aCross, 39U)) + 13761832028354380922U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 13U)) + 9243822514887600214U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 19U)) + 6863833516853046129U) + aNonceWordM;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 29U)) + 8863897995943098018U) + aPhaseCOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aIngress, 60U)) + 13346785686701467520U) + aPhaseCOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15309543066305531619U) + aNonceWordN;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17515530938817919111U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 16625193986319048245U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 760493237816424254U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7282586354117620860U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 2327153408185290635U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4129706068526969105U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7020175432730888755U;
            aOrbiterD = RotL64((aOrbiterD * 10095158356907592239U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9102258982216515596U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10822031305361453690U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2036205056490578491U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12571477440964330246U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8436347026653095199U;
            aOrbiterJ = RotL64((aOrbiterJ * 17930734781213681573U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14214789872073941940U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 12915911919403385001U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13161681603528031511U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15443240166233851298U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7311369180113240915U;
            aOrbiterK = RotL64((aOrbiterK * 13339195007946889423U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12976516224995960015U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7823308381434556721U;
            aOrbiterF = RotL64((aOrbiterF * 502385172763861451U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4829417661664149137U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16306394751966719700U;
            aOrbiterH = RotL64((aOrbiterH * 5294376579588592157U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (RotL64(aOrbiterH, 12U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 48U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 30U) + RotL64(aOrbiterH, 11U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 35U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterH, 39U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterC, 23U));
            aWandererA = aWandererA + ((((RotL64(aCross, 18U) + aOrbiterK) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 44U)) + aOrbiterJ) + aNonceWordI) + aPhaseCWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordH);
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

void TwistExpander_Tennis_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDBC955992D22E7A7ULL + 0xB87AD236D76D650AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE5BD1536DB8BBD61ULL + 0xE1E3ABA22B3E5663ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE7FC631D083BB5E1ULL + 0xA2A871599B009CC6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE790DBD2A5F32797ULL + 0xC112ED528041187BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8232A85D4C928FB7ULL + 0xA0D17D985BB5CD15ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF5F4EE08DA7F46F9ULL + 0xB40907C8BCB721ACULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFBE1CA118EF8ADE7ULL + 0xFF4EA60AB16ECEA6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x80A68FB7A1D18F3FULL + 0xFC24EAC2F7D35508ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDB1470EFA92E7A79ULL + 0xFAF991EE6204FAA1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF473C61D54D2CD3FULL + 0x9BFEF9A533EDF74FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9787F4071FE82255ULL + 0xD2F614FF1424E80DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE178FBA47BCF1F53ULL + 0xBEFF2224BE69E2D6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB62E41481A7989C1ULL + 0xA67817BA23913394ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x919129D47A18D35FULL + 0x8A4C07682661CE98ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC8B46B0892B50E89ULL + 0xC4E6CE0067585E7FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD72638436CC944EFULL + 0x92B22DB8EE17E665ULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4129U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 2830U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1743U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3405U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aPrevious, 27U)) + 380024772508948442U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 50U)) + 7649029098162567210U) + aNonceWordI;
            aOrbiterK = (aWandererH + RotL64(aCross, 43U)) + 5329304598870421851U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 3U)) + 12306118665045151326U) + aNonceWordE;
            aOrbiterF = (((aWandererG + RotL64(aCross, 19U)) + 960751560457324256U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 14U)) + RotL64(aCarry, 11U)) + 3244070254386191876U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 21U)) + 15733408571609521746U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 47U)) + 17623448932647018544U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 23U)) + 8787759896149035829U;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 14741681792348288162U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 5U)) + 8801731213568307302U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9872248187499779222U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15407371518644528235U;
            aOrbiterK = RotL64((aOrbiterK * 1245102406469471673U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4242060317152943062U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9942784962409917541U;
            aOrbiterA = RotL64((aOrbiterA * 888649755587764533U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 7296348796484458631U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 15061417216070157797U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10349554676953256231U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3233185810644297433U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9241229457641024287U;
            aOrbiterB = RotL64((aOrbiterB * 2728237515724597517U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8464051359381554575U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3307872165699029375U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4859663401033023433U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5482617843966711997U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4442149210462943872U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8979352218576515647U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10591636597580147381U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14925122230279312217U;
            aOrbiterE = RotL64((aOrbiterE * 15038171961638724013U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9772367878232735350U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15800661165607190092U;
            aOrbiterH = RotL64((aOrbiterH * 10493976952980533589U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1571665862499272194U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3162847040693387901U;
            aOrbiterF = RotL64((aOrbiterF * 2747235335326991399U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4868791925868749848U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13134549226315884613U;
            aOrbiterD = RotL64((aOrbiterD * 3551955270718495869U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7830447320021657240U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 380024772508948442U;
            aOrbiterJ = RotL64((aOrbiterJ * 5143324968958616357U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 20U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 13U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 51U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aIngress, 6U) + RotL64(aOrbiterE, 36U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 47U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterK, 21U));
            aWandererB = aWandererB + ((RotL64(aScatter, 22U) + RotL64(aOrbiterB, 41U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterC, 26U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 43U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterG, 23U)) + aPhaseDWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordC;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8528U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 8798U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10180U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 10555U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 34U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 9914837590440975587U) + aNonceWordA;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 35U)) + 6706125076401958051U;
            aOrbiterI = (aWandererE + RotL64(aCross, 3U)) + 16570817772679258409U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 44U)) + RotL64(aCarry, 47U)) + 6843705658115186948U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 51U)) + 16099930446791572351U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 57U)) + 5420550009556030459U) + aPhaseDOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 47U)) + 5729549069420177477U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 37U)) + 15590601126188675834U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 39U)) + 13044027390998620029U) + aNonceWordI;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 20U)) + 11068338135659636772U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 6584988841809544332U) + aNonceWordF;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8516813219883915404U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 10647314042912492785U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15559481057047148785U), 37U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 201691689889605304U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15512161798401184003U;
            aOrbiterJ = RotL64((aOrbiterJ * 11473219183982564709U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3883760518944464145U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13861805129175491145U;
            aOrbiterF = RotL64((aOrbiterF * 17194438894492581181U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12019138626550801486U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13030350224959652248U;
            aOrbiterD = RotL64((aOrbiterD * 11724200983306280107U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2643807255422544248U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4127143302485631794U;
            aOrbiterA = RotL64((aOrbiterA * 5441038881111578487U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14602951930809633069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4555737199162278494U;
            aOrbiterE = RotL64((aOrbiterE * 12415825635220991865U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6343143902997169834U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10404783711336491985U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6235474458879439079U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7406959231434835393U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6684368109277850196U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 8760360417572331159U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4835889355927954728U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7917682889852676712U;
            aOrbiterK = RotL64((aOrbiterK * 9045350756570117327U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10268055422944417055U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5563744562922937643U;
            aOrbiterC = RotL64((aOrbiterC * 12442484191329795173U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17244672945880141679U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 9914837590440975587U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12269340309792850489U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 48U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterD, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterE, 29U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + aNonceWordH);
            aWandererK = aWandererK + ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 26U)) + aOrbiterF) + aPhaseDWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterB, 39U));
            aWandererI = aWandererI + ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 41U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 58U)) + aOrbiterF) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterA, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 22U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15012U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13684U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14682U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11716U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 43U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererF + RotL64(aIngress, 14U)) + 5131645209694953015U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 29U)) + 12070391048835379854U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 2604295836242338724U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 14042039029284001596U) + aNonceWordE;
            aOrbiterI = (aWandererE + RotL64(aIngress, 19U)) + 8914654543854559327U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 47U)) + 2185619407969359869U) + aNonceWordF;
            aOrbiterC = ((aWandererI + RotL64(aCross, 41U)) + 5187406295103352574U) + aNonceWordP;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 8022832481290871217U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 24U)) + 8783061916740573472U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 53U)) + 10711028365596196301U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 37U)) + 13387065038269133571U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11187001318931801582U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14191473173276034019U;
            aOrbiterA = RotL64((aOrbiterA * 2491253922434756431U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16207761776716426435U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9677408414452078760U;
            aOrbiterK = RotL64((aOrbiterK * 5487303383095129949U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17812460332794370649U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7736423148554132028U;
            aOrbiterD = RotL64((aOrbiterD * 15588733747232852555U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17293203944059014763U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 13487243633338010243U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 9468688858740539095U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15979293016815060755U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17645215484691359547U;
            aOrbiterB = RotL64((aOrbiterB * 1449450767288733995U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11635961468586927692U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10530136578329059784U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8785021493374398437U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4900370530116992731U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15952900504821599445U;
            aOrbiterH = RotL64((aOrbiterH * 5413316082800365261U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 9938000151832814778U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14170277411106520726U;
            aOrbiterE = RotL64((aOrbiterE * 5058343552974910737U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14091010427448547620U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13658560822164111421U;
            aOrbiterC = RotL64((aOrbiterC * 9523184040517290629U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13954269172267844623U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3921811946419945868U;
            aOrbiterF = RotL64((aOrbiterF * 6839440867046147039U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14296483810577739898U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5131645209694953015U;
            aOrbiterJ = RotL64((aOrbiterJ * 10190969526209064367U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 18U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 36U));
            aWandererH = aWandererH + ((((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 19U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 34U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterD, 51U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterB, 28U));
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 53U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 44U) + aOrbiterA) + RotL64(aOrbiterC, 11U)) + aPhaseDWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 20352U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 18689U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16696U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21050U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 20U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aCross, 24U)) + 479672811032092393U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 43U)) + 18061121631394564425U) + aNonceWordD;
            aOrbiterB = (aWandererB + RotL64(aIngress, 29U)) + 14237400452740566065U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 5U)) + 6723123812257706134U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 56U)) + RotL64(aCarry, 21U)) + 4247997188026499248U) + aNonceWordA;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 3U)) + 1939107415066134869U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 3912640123546395979U) + aPhaseDOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aPrevious, 51U)) + 8295478436553964298U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 27U)) + 3218960600711526885U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 19U)) + 5874096203353388890U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 10294536533673023358U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11268561953904130747U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16693201256788898423U;
            aOrbiterB = RotL64((aOrbiterB * 16291987237693567209U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7550969634681894654U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9501647424602245869U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 11265865222096866605U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8881869255994319423U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16770136406906800016U;
            aOrbiterH = RotL64((aOrbiterH * 1782039587385512923U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16185384746435761363U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13841034186650721627U;
            aOrbiterJ = RotL64((aOrbiterJ * 12000155593277035447U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15229062695864608309U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3576122704615303733U;
            aOrbiterE = RotL64((aOrbiterE * 2433987493885779279U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13898167174453181224U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 12878032061609524049U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18104665741338251495U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12719156051299028649U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8640980843376950769U;
            aOrbiterD = RotL64((aOrbiterD * 10242616778390983333U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12133332160916004365U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8743563985229104484U;
            aOrbiterA = RotL64((aOrbiterA * 4575129690615054691U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7362223873479167793U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4230720394788635807U;
            aOrbiterF = RotL64((aOrbiterF * 3658720603716856293U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5095842824285329272U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7483469517256234638U;
            aOrbiterI = RotL64((aOrbiterI * 9782114499878763883U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17426017004856399653U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 479672811032092393U;
            aOrbiterC = RotL64((aOrbiterC * 14921028515589317919U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 18U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterC, 21U)) + aNonceWordK) + aPhaseDWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 30U) + aOrbiterF) + RotL64(aOrbiterB, 60U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 51U)) + aOrbiterD) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 37U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterE, 47U));
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + aPhaseDWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererD = aWandererD + (((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterD, 14U));
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23067U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 25540U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23825U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 25227U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aIngress, 18U)) + 6318740973868639425U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 51U)) + 5487840061430920881U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 21U)) + 10258706763248072672U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 53U)) + 18356875269730338208U) + aNonceWordN;
            aOrbiterI = ((((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 12883160282903147010U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aWandererI + RotL64(aScatter, 11U)) + 1010140474942697730U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 17733939421700898293U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 3U)) + 13693055887924981201U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 28U)) + 14574732452793385269U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 10832873941223609012U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 37U)) + 8212600587135328040U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5312744319781971178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6173741211706546923U;
            aOrbiterD = RotL64((aOrbiterD * 12854414066390848249U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3693249147883790810U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 18365859989736602556U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3348463719324104997U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10645056678337549771U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1175668356822251045U;
            aOrbiterK = RotL64((aOrbiterK * 6579675292775345579U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13556844570541823717U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4790355739411849736U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4083544011788850307U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14905575502272644116U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17047244574558476634U;
            aOrbiterE = RotL64((aOrbiterE * 2356386971503880047U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 10161614295718414869U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13413914082651612468U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16224039093981079491U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6072693130156927774U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4333656233793103787U;
            aOrbiterF = RotL64((aOrbiterF * 9374745547133955709U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17209776289202130250U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11752001118070361543U;
            aOrbiterH = RotL64((aOrbiterH * 4416523594812872339U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15367365111105608277U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8650687767097460704U;
            aOrbiterG = RotL64((aOrbiterG * 11430451559660578667U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 18074648514448405693U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10857586858462237581U;
            aOrbiterB = RotL64((aOrbiterB * 3722891011080095849U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17219932344278345591U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6318740973868639425U;
            aOrbiterI = RotL64((aOrbiterI * 8846295038878812229U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (RotL64(aOrbiterD, 58U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 36U)) + aOrbiterI) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterG, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 5U)) + aOrbiterB) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 27U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterC, 51U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterI, 23U)) + aNonceWordL);
            aWandererA = aWandererA + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterF, 39U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterH, 20U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29527U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 31520U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29406U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30520U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCross, 19U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (aWandererC + RotL64(aScatter, 41U)) + 5295352595333316211U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 47U)) + 2341795367042042605U) + aPhaseDOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 10122175780504033663U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 57U)) + 10084612804696198554U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 29U)) + 16470424309851045971U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 27U)) + 656016130975227994U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 38U)) + 15313268829659834317U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 23U)) + 3795220914993923394U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 14044442220988813825U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 53U)) + 3804224626734584802U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 6U)) + RotL64(aCarry, 11U)) + 7980006306010255693U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13746830564584711549U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11852212099729274845U;
            aOrbiterK = RotL64((aOrbiterK * 2164880979318247855U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9083223471018084847U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13706723820703853346U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11361854103656219887U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1713819986642275223U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1382000168233902914U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 3894160765130198157U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4540474625764565485U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1756168174375757220U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12739160208010092017U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1409297070183609309U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6082750101445444357U;
            aOrbiterB = RotL64((aOrbiterB * 17438740230251860935U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1113239890859479202U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10932192439503964363U;
            aOrbiterI = RotL64((aOrbiterI * 5915660289913324281U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3732595033748508428U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 5117760372351117286U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2671510075176315761U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7399968659654088641U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14835608167871904147U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 8312521710415756159U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7851355416751467648U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 262169565276199916U;
            aOrbiterA = RotL64((aOrbiterA * 11801419425408657509U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1771847554312299305U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15588805765521695222U;
            aOrbiterG = RotL64((aOrbiterG * 8541206691371972017U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6162696602553964144U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5295352595333316211U;
            aOrbiterH = RotL64((aOrbiterH * 8368226841948931873U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 50U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 10U) + aOrbiterB) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterE, 21U));
            aWandererC = aWandererC + ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 57U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterH, 44U));
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterA, 11U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 54U) + aOrbiterC) + RotL64(aOrbiterD, 41U)) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + aPhaseDWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 24U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + aPhaseDWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 13U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordA);
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

void TwistExpander_Tennis_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB1E13BC70C0C1FFFULL + 0xA830A931C6B7D9BBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB721DC68FFD6FFF5ULL + 0x9CBC863DEBF53C86ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB78A39F020A1B783ULL + 0xD28B38EDC7481B2DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD06348A6327ACEDBULL + 0xB20791656AA9614FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x873868A783DAA425ULL + 0xF12061F14C1C43C4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8452BE2B3CC5E897ULL + 0xE43BCE83F9849A29ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA1E30139DFF76F79ULL + 0x8B4353B0136E0A4EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x81854EE6DDA62513ULL + 0xF2A12112D2ACD5D2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE24120AC604298A7ULL + 0xC6D9C90636B54CC7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xEB4ACAAAB7C99C1DULL + 0xA12886FC1DD83359ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9EC2491F0FB66B79ULL + 0xA90197247CAF09A7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x86B92BC910A3BDC3ULL + 0xF3FB14CB5D8F92C5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB863D8632F555231ULL + 0x8E69630AF4A400BFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB2E9C51FEA1EE2DBULL + 0x9AB28D33B65B2576ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF190EE89E68D7D5BULL + 0xF1907D0271FB32D4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x84EB3B7A008B97FDULL + 0x93FD30E95FDDC097ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4458U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 2951U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2014U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 764U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 56U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aIngress, 10U)) + 13650869943246163567U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 3435284932011770999U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 13U)) + 12388155658186776579U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 39U)) + 2374345913955712039U) + aNonceWordK;
            aOrbiterF = ((aWandererA + RotL64(aCross, 30U)) + 6095094526980292156U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 53U)) + 4965147025852444174U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 3U)) + 3261881216269075298U) + aNonceWordH;
            aOrbiterK = (aWandererC + RotL64(aScatter, 23U)) + 4939780217097329222U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 3019862009792676287U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 901910626217143974U) + aPhaseEOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aIngress, 35U)) + 3647055146712366383U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7731765438957392967U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13409819457393479741U;
            aOrbiterJ = RotL64((aOrbiterJ * 3345078200262410715U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5415832109107794258U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8876738832313114471U;
            aOrbiterH = RotL64((aOrbiterH * 1304277600444504135U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17135570542519390359U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2373193062766802082U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4213691513185791519U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 16318403285501718552U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8456043288604687045U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10556964529144571683U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10572534930284516528U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14616251186735204677U;
            aOrbiterB = RotL64((aOrbiterB * 2048651204265459805U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2837006243817205610U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5315917323622194254U;
            aOrbiterA = RotL64((aOrbiterA * 4080522050089666599U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12084676282761185907U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7922080344175593788U;
            aOrbiterG = RotL64((aOrbiterG * 7603522302708937379U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17620847289789547792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12140386059533463650U;
            aOrbiterD = RotL64((aOrbiterD * 1443266480620969535U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4006608081473218762U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3152507055132739011U;
            aOrbiterF = RotL64((aOrbiterF * 11929522909695002321U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10845720206369283181U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16572752872386133133U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 2891952650448087211U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15544908026178481075U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13650869943246163567U;
            aOrbiterI = RotL64((aOrbiterI * 1275090431127426217U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 30U);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 52U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aCross, 4U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterH, 5U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterC, 37U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 43U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 19U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterK, 56U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 13U));
            aWandererH = aWandererH + ((RotL64(aCross, 26U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6639U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7326U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10796U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 9545U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 26U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aCross, 53U)) + 15383045568644941552U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 46U)) + 17452811657750910067U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 15660117718455155603U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 35U)) + 10396441207743665753U) + aNonceWordI;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 13U)) + 3708971058200841442U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 43U)) + 7000673057768598750U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aPrevious, 37U)) + 9886354469011131596U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 57U)) + 16018065329058043467U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 5024756166109352320U) + aNonceWordK;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 18U)) + 6587818720728886652U) + aNonceWordC;
            aOrbiterE = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 3652672354944162319U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6307315649915348048U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16405347331742979258U;
            aOrbiterK = RotL64((aOrbiterK * 7183142442906743699U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5427299664054601957U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4983381733483185898U;
            aOrbiterA = RotL64((aOrbiterA * 14646556236306407673U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10182995521328377487U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8694282877540593550U;
            aOrbiterI = RotL64((aOrbiterI * 14614602561910403893U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4085927978153269932U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6176195962815240877U;
            aOrbiterB = RotL64((aOrbiterB * 16792916528959579875U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6966742100601433005U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9920952446921247521U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1879821050131820933U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11958734477518336014U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2058335903640404380U;
            aOrbiterD = RotL64((aOrbiterD * 6986170159285417789U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 77366119537297816U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12072894199692855000U;
            aOrbiterH = RotL64((aOrbiterH * 9083781120514635987U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11874297832446385377U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13715562531763053196U;
            aOrbiterJ = RotL64((aOrbiterJ * 12822488258322963187U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 13664465415354326653U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10365386643010882315U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3687934567254955761U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2003863843075564853U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8864134110143237364U;
            aOrbiterG = RotL64((aOrbiterG * 4586162015675320985U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8055736412403126985U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15383045568644941552U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5175405553995854715U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 24U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 6U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aIngress, 14U) + aOrbiterH) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 35U)) + aOrbiterF) + aNonceWordO);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 23U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 60U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterF, 29U)) + aPhaseEWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 27U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererE = aWandererE + (((RotL64(aScatter, 30U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 37U)) + aOrbiterK) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16069U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11616U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15916U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((aIndex + 11073U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 10U)) + 10805654776556844351U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 5U)) + 582794182442795335U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 2858343650974681068U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 47U)) + 8189584049022064284U) + aPhaseEOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 3U)) + 1565100751996962893U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 8062028016947611891U) + aNonceWordN;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 8280504280578451745U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 13U)) + 11326869194491655350U) + aNonceWordI;
            aOrbiterG = (aWandererH + RotL64(aIngress, 54U)) + 1671695656567777163U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 23U)) + 2349843105293943452U;
            aOrbiterI = (aWandererK + RotL64(aCross, 37U)) + 13015545152052004254U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16703354404749291869U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8713231044374305801U;
            aOrbiterB = RotL64((aOrbiterB * 9242480982197688625U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11118401674497783533U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14857556493734710364U;
            aOrbiterC = RotL64((aOrbiterC * 3452566050389715195U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12953419670951660965U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12666121730825089017U;
            aOrbiterF = RotL64((aOrbiterF * 14049925256934142519U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11075249639473053423U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9374217688244187867U;
            aOrbiterE = RotL64((aOrbiterE * 5261156325627117877U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17608340953291367867U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13159437499327086340U;
            aOrbiterJ = RotL64((aOrbiterJ * 4882100944453534805U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4304700511322366815U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10172544755256706767U;
            aOrbiterH = RotL64((aOrbiterH * 4013006212154771797U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 17340067939877432472U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14130447570008179105U;
            aOrbiterK = RotL64((aOrbiterK * 8178075071208718915U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2652532710498072378U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 10384945384238518296U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 17137694272394304045U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15292159041119433363U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12103644911645285108U;
            aOrbiterD = RotL64((aOrbiterD * 4565615406415614103U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16307525158627275744U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3786908390177579447U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6592585847755318801U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13595883419843505634U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 10805654776556844351U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 10956465099104915639U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterK, 35U));
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 56U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterA, 27U)) + aNonceWordC);
            aWandererC = aWandererC + ((RotL64(aPrevious, 26U) + aOrbiterB) + RotL64(aOrbiterC, 51U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterA, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 5U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 14U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + aPhaseEWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16971U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18296U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21258U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((aIndex + 18698U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 22U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (((aWandererI + RotL64(aCross, 14U)) + RotL64(aCarry, 57U)) + 3238389262925516513U) + aNonceWordM;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 21U)) + 12381787182611386995U) + aNonceWordD;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 7883885539305181549U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 3U)) + 1185413044597727092U;
            aOrbiterI = (aWandererC + RotL64(aCross, 29U)) + 15219353497204773135U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 35U)) + 7533774715626734082U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 2599930450937763464U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 57U)) + 16074720663961214284U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 11U)) + 15483613196360051221U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 26U)) + 9396557867081376268U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 53U)) + 9668459976852660245U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9037269914643207212U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16936742640861088240U;
            aOrbiterE = RotL64((aOrbiterE * 1040172193161012227U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16481274825758546398U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 481851372837611166U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2225030139210599207U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13608921517203544108U) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16930740723286214636U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2605108503821980865U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 902242902582149908U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1510861213079342977U;
            aOrbiterA = RotL64((aOrbiterA * 3309753895727400707U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7116243600304980310U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6631412278359709602U;
            aOrbiterF = RotL64((aOrbiterF * 11452627691392637463U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9246698682265275165U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8594373032014031450U;
            aOrbiterJ = RotL64((aOrbiterJ * 2550138341089957033U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15912837963877821048U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11404583513022627609U;
            aOrbiterD = RotL64((aOrbiterD * 17715204726760125357U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17295214920690244319U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18315664494984189344U;
            aOrbiterG = RotL64((aOrbiterG * 17398893532076312945U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2474825506593695564U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4400473621592150441U;
            aOrbiterK = RotL64((aOrbiterK * 7098832854166953839U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15270166373215060119U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4331232225067306139U;
            aOrbiterC = RotL64((aOrbiterC * 2299883590703870703U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2176207815544347316U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3238389262925516513U;
            aOrbiterB = RotL64((aOrbiterB * 13104597690682251231U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 36U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterH, 11U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterC, 27U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterG, 21U)) + aNonceWordG) + aPhaseEWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterA, 52U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 19U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 3U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterK, 41U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterE, 60U)) + aNonceWordP);
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 10U) + RotL64(aOrbiterD, 37U)) + aOrbiterG) + aNonceWordB) + aPhaseEWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24569U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((aIndex + 25833U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25949U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 25374U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 43U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aIngress, 37U)) + 3448371607470865612U) + aNonceWordH;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 3743742913651580573U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 12U)) + 13069491287948807280U;
            aOrbiterI = (aWandererF + RotL64(aCross, 5U)) + 16872779275586545632U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 21U)) + 17945792656755062795U) + aNonceWordC;
            aOrbiterG = (aWandererC + RotL64(aIngress, 47U)) + 18199747196793731853U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 27U)) + 15953311878379809513U;
            aOrbiterK = (aWandererI + RotL64(aCross, 3U)) + 941268763494588338U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 41U)) + 10090221530365796809U) + aPhaseEOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aCross, 34U)) + RotL64(aCarry, 35U)) + 8335698093307607001U) + aPhaseEOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 6147498804734306100U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5980246079567570090U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4152167624425912978U;
            aOrbiterF = RotL64((aOrbiterF * 10019421651535123573U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14990418790239735916U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3418668387496597219U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12814077238529863119U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4206650904177199425U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3905470780938996069U;
            aOrbiterK = RotL64((aOrbiterK * 16030122739273137005U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9968672788233080924U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 602258075661864866U;
            aOrbiterB = RotL64((aOrbiterB * 2615726693066300065U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17751667243048041383U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2414054413585296027U;
            aOrbiterD = RotL64((aOrbiterD * 1049512574773201893U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6523322402744047752U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6729901917767398779U;
            aOrbiterI = RotL64((aOrbiterI * 8039939871405367139U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11460169185076814539U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7559640379553110573U;
            aOrbiterH = RotL64((aOrbiterH * 9864654321914036135U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17271150091827475028U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3541809324556914646U;
            aOrbiterE = RotL64((aOrbiterE * 12655168871428868639U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10332471447306597185U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12580133010006951091U;
            aOrbiterA = RotL64((aOrbiterA * 1159183486084705865U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17333553613777910945U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14179392055698682109U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17675559451285279251U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3996830751779338356U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3448371607470865612U;
            aOrbiterC = RotL64((aOrbiterC * 5375529914102609947U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 46U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 19U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + aNonceWordF);
            aWandererI = aWandererI + ((RotL64(aPrevious, 26U) + RotL64(aOrbiterI, 24U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 11U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 41U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 60U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28212U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29774U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31495U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30924U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 28U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aIngress, 39U)) + 17225673071833726819U;
            aOrbiterK = (aWandererE + RotL64(aCross, 23U)) + 10301458382103627331U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 50U)) + 3960233050857362414U) + aNonceWordN;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 47U)) + 17768665685046605837U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 29U)) + 14471018461213959767U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 19U)) + 10730597892721340453U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 37U)) + 14863394003122760542U) + aNonceWordO;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 9948587274816688296U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 3573569431435100993U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 21U)) + 8153670675740450590U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 26U)) + RotL64(aCarry, 19U)) + 16438856577722561424U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15765587867581925041U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1082039522061775213U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17023740047246402641U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4202521649260798876U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15877659681260461141U;
            aOrbiterJ = RotL64((aOrbiterJ * 11369910758551088173U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2551560426129646123U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3005102326163906320U;
            aOrbiterB = RotL64((aOrbiterB * 4241583192662435107U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1675501058857208089U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12774812270956702043U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 5488437008504905105U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1044886020922563597U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 4857445127457225171U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 13223560654459705259U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11548725551787560962U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2434677823189765161U;
            aOrbiterI = RotL64((aOrbiterI * 4283026044563670969U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9606875320524736294U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13732615866277657704U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 3905528919281629775U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13921743663803299567U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13350829301153929899U;
            aOrbiterH = RotL64((aOrbiterH * 11858642286713079795U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9473349030551400156U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7446792050826434742U;
            aOrbiterA = RotL64((aOrbiterA * 6619682184124713031U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17970527747978977453U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2326714817603921480U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14581676978186226887U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7875511075130474136U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17225673071833726819U;
            aOrbiterF = RotL64((aOrbiterF * 1196024136909896027U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 30U)) + aOrbiterJ) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterF, 39U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 60U)) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterB, 11U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterG, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 19U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 20U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_Tennis_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB474180BAB94C673ULL + 0xA12CC269281CE12FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF903CF161AB933B5ULL + 0x9FC1561C1625F1B8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA5D123DF08B0D639ULL + 0xFB459875A6062E73ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x81F3EF075036945BULL + 0x8C3B0E24FDEA09DBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBDB6C39CB591AFA1ULL + 0xDCB204A5427B8443ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x98CE03562F180515ULL + 0xE892CAFF85F6BBEDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x94E78BCD162E1C55ULL + 0xA7409A030B9ADBC1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE87F933B6621F20BULL + 0xA7B39A24ED5C5A69ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8E84E53D03D047E9ULL + 0xC335F766BF357348ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x83DE9BCB765AD609ULL + 0xE294D91A01592B66ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA4165CB08CDFE8C3ULL + 0xFBA8F1308B1C54D3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF17922E35ACF86DBULL + 0xDBAC43482FB0A36DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA08230C7577E0F93ULL + 0x89ADE3656170AD44ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA9E419D33E011B0DULL + 0xE595741FD364D08FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE2DF3A7711F50559ULL + 0xE8BA45566B46629CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9397B830AFF458FFULL + 0xAEF9CCA7AC08598CULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4366U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4401U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2037U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1806U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 13U)) + (RotL64(aCross, 60U) + RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aPrevious, 5U)) + 1866656689936219099U;
            aOrbiterK = (((aWandererA + RotL64(aCross, 38U)) + RotL64(aCarry, 29U)) + 2312314528139448289U) + aPhaseFOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 27U)) + 3554037526469185237U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 43U)) + 405707755060974111U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 47U)) + 1862976326004007697U) + aNonceWordG;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 11U)) + 12992483065443288263U) + aNonceWordI;
            aOrbiterI = (aWandererD + RotL64(aCross, 40U)) + 3793854946371595197U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 4244007978867369382U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 10280867500312580308U;
            aOrbiterC = (aWandererI + RotL64(aCross, 3U)) + 472563452959164242U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 19U)) + 12041770406895816553U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6118634015704900486U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13637107920449233307U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17712028184714868053U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16673735670669318830U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8602681273646630496U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 6995213887710749241U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7683264695930369476U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9146674871199188218U;
            aOrbiterE = RotL64((aOrbiterE * 7403427067419261981U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3012935612827493084U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1259789268731661945U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2372843620327050137U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5623690455471160780U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 18355567776031865462U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9553862670107886679U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7705134893833304792U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4435192506444773834U;
            aOrbiterA = RotL64((aOrbiterA * 5249651218395299501U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6204683785806409075U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17886971535016484255U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6047216474762933535U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4430578901091376829U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 607557685798141547U;
            aOrbiterK = RotL64((aOrbiterK * 12342665567201483107U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 18258994761911545002U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 634391404805006992U;
            aOrbiterF = RotL64((aOrbiterF * 5761143438450180463U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8528044138264666860U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3867692060293315964U;
            aOrbiterB = RotL64((aOrbiterB * 8285164562893231087U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8333438209201978886U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1866656689936219099U;
            aOrbiterC = RotL64((aOrbiterC * 3935928308329865425U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 18U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterA, 27U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterF, 41U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 48U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 41U)) + aNonceWordH) + aPhaseFWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterB, 34U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 51U));
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aScatter, 46U) + RotL64(aOrbiterC, 38U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5697U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10331U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6551U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7948U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 54U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 15726877954695761686U) + aNonceWordH;
            aOrbiterI = (aWandererG + RotL64(aIngress, 18U)) + 14187652171881943587U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 27U)) + 8420423151313882782U) + aNonceWordB;
            aOrbiterK = ((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 14942322692433259283U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 41U)) + 7272331475919796255U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 154504365041805840U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 6U)) + 17475491222554948786U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 21U)) + 5759181483165339605U) + aPhaseFOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 37U)) + 5993060214499322845U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 13U)) + 10901786237875941844U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 57U)) + 17135786595614068473U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 5208202073886811165U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6821452921018900631U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 13119330055184115669U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13348064837402206969U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8967943922403445136U;
            aOrbiterI = RotL64((aOrbiterI * 300168481725373093U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8130283784171430891U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6351113882502502876U;
            aOrbiterA = RotL64((aOrbiterA * 15960622823993072903U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6894708729226455769U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12065058511247133944U;
            aOrbiterJ = RotL64((aOrbiterJ * 5432601727436935831U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17138279326229372741U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12987698199066890628U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12665716655177320977U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13688833537574196675U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4211971980434000618U;
            aOrbiterF = RotL64((aOrbiterF * 1374411763361518851U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10376917117582537592U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4807742522197923516U;
            aOrbiterK = RotL64((aOrbiterK * 15257251453302090961U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18038296468177121243U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6879666349379745258U;
            aOrbiterG = RotL64((aOrbiterG * 15819475269715810555U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 5193656664432659624U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 680899397323387963U;
            aOrbiterB = RotL64((aOrbiterB * 9857476056194621321U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1851929589073547860U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13093101559415170218U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13950928576652143737U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13695333301427028607U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15726877954695761686U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 960063676226172027U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (RotL64(aOrbiterH, 48U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 18U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 5U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterH, 51U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 18U) + aOrbiterC) + RotL64(aOrbiterJ, 23U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 11U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 13U)) + aOrbiterF) + aNonceWordL);
            aWandererB = aWandererB + ((RotL64(aCross, 52U) + RotL64(aOrbiterG, 36U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 47U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15894U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13115U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15607U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 11053U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 24U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aScatter, 5U)) + 8101351470141807662U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 6965474099521076705U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 6803828268885684784U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 56U)) + 13454235922950972488U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 13U)) + 11678091885751244777U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 51U)) + 5307134544628507141U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 47U)) + 4873703518950429353U) + aNonceWordD;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 53U)) + 8542156221858586039U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 27U)) + 3993726182905296513U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 19U)) + 12113047622035464386U) + aPhaseFOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 11U)) + 1944244448665721151U) + aNonceWordF;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12914188029425467576U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 2486762763475327024U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 12319769994433811617U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14580191602982245481U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12093414832400135066U;
            aOrbiterH = RotL64((aOrbiterH * 12720286833215690663U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13623906997320021065U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9977356009806428696U;
            aOrbiterB = RotL64((aOrbiterB * 2005536391712733499U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3694954095397810851U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11453812627797091638U;
            aOrbiterD = RotL64((aOrbiterD * 13730420725113907161U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 542311345544726351U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3024285045990499484U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 5153745952148205645U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15397664082460849530U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10716856680110815056U;
            aOrbiterK = RotL64((aOrbiterK * 13947203772929252823U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 833342121331428547U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1111339940097269219U;
            aOrbiterJ = RotL64((aOrbiterJ * 17991642769781175473U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9312963978841402871U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8225496710723213204U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 894499195498817065U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7947419530949269753U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5028446114139808517U;
            aOrbiterG = RotL64((aOrbiterG * 5593084899736787263U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9818957208200746975U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17549192719666647522U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4705007748877441833U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16389708540378477737U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8101351470141807662U;
            aOrbiterC = RotL64((aOrbiterC * 9858235486537441981U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 44U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 51U) + RotL64(aOrbiterB, 43U)) + aOrbiterD) + aNonceWordK) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 54U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 27U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterI, 13U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterI, 57U));
            aWandererF = aWandererF + ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 51U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 37U)) + aOrbiterF) + aNonceWordC);
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterB, 19U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 10U) + aOrbiterH) + RotL64(aOrbiterE, 10U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + aNonceWordJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererF, 56U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20401U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16405U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16993U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20627U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 54U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aPrevious, 6U)) + 1297415699043177788U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 41U)) + 17583786534509260153U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 643197858925708798U;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 5062653766915694874U) + aNonceWordH;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 11U)) + 7034273638367180511U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aCross, 37U)) + 2026909726972916996U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 30U)) + 2785690475553211646U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 3U)) + 2910341716302991892U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 2834181605200829791U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 43U)) + 13323052600571281928U) + aPhaseFOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 27U)) + 10434901530315760460U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 247903955625194782U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5196515747387257163U;
            aOrbiterD = RotL64((aOrbiterD * 1799024689023272275U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7196305682377987476U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14777739876892587484U;
            aOrbiterK = RotL64((aOrbiterK * 95220583948241581U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10609060796540136671U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8386027207212484155U;
            aOrbiterF = RotL64((aOrbiterF * 4855610536246556893U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 729659744301903424U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2350564261412606157U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16713856782349084977U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16611987556673864177U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1525195188708550503U;
            aOrbiterH = RotL64((aOrbiterH * 10045858602151004553U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 4654808490980989596U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8189569777087686263U;
            aOrbiterC = RotL64((aOrbiterC * 17278657566389299577U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 10932857495004451792U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1833880112534916813U;
            aOrbiterG = RotL64((aOrbiterG * 8004341577533825681U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13100236350175516423U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2773759534195186313U;
            aOrbiterA = RotL64((aOrbiterA * 3194954066097323161U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13963126688973399221U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1464529855671190406U;
            aOrbiterI = RotL64((aOrbiterI * 6129954747502059213U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9489842625026216815U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17806120432918490594U;
            aOrbiterE = RotL64((aOrbiterE * 349307975773661379U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13833297268854563081U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1297415699043177788U;
            aOrbiterB = RotL64((aOrbiterB * 4818542043777342249U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 20U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aScatter, 14U) + aOrbiterG) + RotL64(aOrbiterE, 10U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterD, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 13U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 53U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aNonceWordM);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterC, 37U)) + aNonceWordD);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 28U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 54U) + RotL64(aOrbiterE, 51U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25262U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 25382U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23191U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 24188U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 29U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 56U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 57U)) + 964165145848253292U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 10645976767204934746U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 47U)) + 8241612229349212650U) + aNonceWordE;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 27U)) + 4159196033256913347U) + aPhaseFOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aCross, 60U)) + 7194795864620233507U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 21U)) + 7638928444536778384U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 11819105916503968109U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 29U)) + 18052213302858186237U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aWandererH + RotL64(aScatter, 23U)) + 8663575313970041570U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 6U)) + 16644136720439299786U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 16930316530442679864U) + aNonceWordK;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 16251107616988250593U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7171986193609401665U;
            aOrbiterC = RotL64((aOrbiterC * 3543709971414550087U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17885046834432626644U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7757069274715713557U;
            aOrbiterH = RotL64((aOrbiterH * 15766885299397923879U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 2212805322061155615U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6368539134638838822U;
            aOrbiterK = RotL64((aOrbiterK * 13383744883433594259U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5264326094252925613U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6126345334815012938U;
            aOrbiterA = RotL64((aOrbiterA * 17180934809764905307U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13826731214018407061U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6621261811613643620U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2823596473596114171U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5964406317285863781U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2167324450276308078U;
            aOrbiterG = RotL64((aOrbiterG * 1098346374733634905U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16740710162977859724U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8236083581048717923U;
            aOrbiterD = RotL64((aOrbiterD * 4364887787000704039U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13967473987446124012U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5136051802217149813U;
            aOrbiterI = RotL64((aOrbiterI * 13997246005108872883U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5842999397215390366U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8621394946580065499U;
            aOrbiterJ = RotL64((aOrbiterJ * 11658023035736362355U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 18086875424872976900U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7429246355923896047U;
            aOrbiterE = RotL64((aOrbiterE * 5077079237334961761U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 18123753993386959014U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 964165145848253292U;
            aOrbiterB = RotL64((aOrbiterB * 3178072569980307307U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 14U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 39U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 48U)) + aOrbiterE) + aNonceWordD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 48U) + aOrbiterA) + RotL64(aOrbiterF, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 29U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 43U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aIngress, 20U) + aOrbiterD) + RotL64(aOrbiterH, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 34U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 27U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterK, 23U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererH, 36U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27952U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 28524U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29806U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31185U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 26U) + RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 13880995121909552664U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 53U)) + 14534942818069300546U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 41U)) + 17745973100886007133U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 44U)) + 2249805580771946872U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 23U)) + 4460116116396439410U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 29U)) + 3378683994078106878U) + aNonceWordG;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 3992996501048809123U) + aNonceWordE;
            aOrbiterG = (((aWandererK + RotL64(aCross, 37U)) + 12057768808864451929U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 4115362079047921130U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 35U)) + 15297384955502206698U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 60U)) + 17623548383481905636U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 3559213898000162417U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12311605719074507335U;
            aOrbiterD = RotL64((aOrbiterD * 3982199462062847697U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14807313864347885885U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11222085523291581822U;
            aOrbiterE = RotL64((aOrbiterE * 12580941911587215653U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 916681229436292462U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2441350114032314686U;
            aOrbiterH = RotL64((aOrbiterH * 7336079498999018067U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7361470539894653271U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12153585147213579808U;
            aOrbiterA = RotL64((aOrbiterA * 3040327545467672961U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13566300726101613579U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 14875254144748509128U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 13699179902908972403U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9268158535644002904U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 14144295981814993491U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12739937231684038161U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13861225650900541642U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12620513474052058164U;
            aOrbiterI = RotL64((aOrbiterI * 18141974182442267181U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14163773386433257965U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5725700029399455855U;
            aOrbiterC = RotL64((aOrbiterC * 10446930901088908809U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 16644838246877860102U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 6611825438224873117U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5336239588054125897U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9408958265247071226U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16980073477599191801U;
            aOrbiterB = RotL64((aOrbiterB * 7985839560318985205U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6513029242607881518U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13880995121909552664U;
            aOrbiterJ = RotL64((aOrbiterJ * 17463079726765044639U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 24U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterG, 27U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 43U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 46U) + aOrbiterE) + RotL64(aOrbiterC, 47U)) + aNonceWordA) + aPhaseFWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterI, 29U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 37U)) + aNonceWordC);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterB, 13U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 40U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 11U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aScatter, 58U) + RotL64(aOrbiterE, 3U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 60U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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

void TwistExpander_Tennis_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD0AB70410613A4EBULL + 0xAF388C2AEC92AC56ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x867B6176A8E58447ULL + 0x87AF1AA247F67A17ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF6732CA5DCB83231ULL + 0xECF4093D4BC4B7C0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF1CA0F9E0DD039C1ULL + 0xAC768130ECDBBEF6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x80EB37289FD05003ULL + 0x86DD13FE5257F818ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC4AFD641764AEDCDULL + 0xB0A19995D9D3017AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8915BFAEB213AA45ULL + 0xF3B6724BDE9BA6BCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCFE5C196C4DD621FULL + 0x84873F2761D0AC26ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC0DCF7963B590DFBULL + 0x89A33D6DC3CCE1C3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9CFF6A3FFF393557ULL + 0xDDECFDBF5B810D01ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xED1FF26093A3616FULL + 0xF2EBABC3A714CE48ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE6E59EB63917EE63ULL + 0xEDCF2FB9E2FD12C1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBE2CBFFF27B2D583ULL + 0xE1E5F4D8BC20EE2EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDA7140E59C5CC65DULL + 0x92897B59A8DBB130ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC50515622AFF55FDULL + 0x817C3DB910D03524ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB3D7E5706658D0EDULL + 0xEF9B90837D88D3FAULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 976U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 794U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3095U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 283U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 12U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererJ + RotL64(aIngress, 5U)) + 14499676118633326000U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 56U)) + 17191273593018552288U) + aNonceWordF;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 4085176294948097737U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 21U)) + 11112671474158908186U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 51U)) + 8745787969012266485U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 19U)) + 18074049663777707948U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 27U)) + 2543758649719164688U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 40U)) + 4659584749412700523U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 974639159259871273U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 21U)) + 9211220687971081987U) + aNonceWordL;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 11U)) + 8567024626862182714U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5803002132294840900U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11968489432878148467U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4501441062617123165U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9470807228394903442U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1692347973120388469U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 17433393164156231575U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16510815732690193145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 755159406833096510U;
            aOrbiterA = RotL64((aOrbiterA * 14091736464659561165U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1518824876475937620U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 701225390867330446U;
            aOrbiterD = RotL64((aOrbiterD * 12264618860580199927U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8425976693733003889U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7182176375442410367U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8860605703761731859U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4546566785167467924U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2593340999038753749U;
            aOrbiterK = RotL64((aOrbiterK * 10152461487764567563U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9756331608356622299U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5511625814747641978U;
            aOrbiterJ = RotL64((aOrbiterJ * 4806076157539829529U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8694400787420160733U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12648969491371382682U;
            aOrbiterG = RotL64((aOrbiterG * 5346585704222643759U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15261238546696118531U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14236129054778329471U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11789581469516267749U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16251500056378064213U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 790320176607605195U;
            aOrbiterF = RotL64((aOrbiterF * 15706130623435648555U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17114773669444878655U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14499676118633326000U;
            aOrbiterI = RotL64((aOrbiterI * 8095707555083587081U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 12U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterB, 37U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterK, 18U)) + aPhaseFWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterK, 53U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterA, 21U)) + aPhaseFWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 50U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 57U));
            aWandererD = aWandererD + ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterG, 13U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 24U) + aOrbiterH) + RotL64(aOrbiterA, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9927U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7165U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6484U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 5487U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 60U)) + (RotL64(aCarry, 29U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererB + RotL64(aIngress, 39U)) + 3917730204724097072U;
            aOrbiterB = (aWandererG + RotL64(aCross, 44U)) + 1874642340716212824U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 41U)) + 6900165757434854160U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 35U)) + 12750946097023807161U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 6563216048479513594U;
            aOrbiterF = (aWandererH + RotL64(aCross, 57U)) + 14960240191349450795U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 16306180275951788289U) + aNonceWordE;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 6502066618271045547U) + aNonceWordB;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 29U)) + 6219852857850888738U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 23U)) + 2272931312452845850U) + aPhaseFOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 6U)) + 3028929882263199463U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6067393030073568112U) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 10094809900437037258U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18095564940730322769U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5962414178157074575U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15755563045799129417U;
            aOrbiterB = RotL64((aOrbiterB * 3692603590609922031U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6321455513889880590U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1197435601998121700U;
            aOrbiterD = RotL64((aOrbiterD * 17693996266260557625U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12496949381666299968U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6357070235648527030U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2931486644220862433U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8423760160877540210U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8090246492554850768U;
            aOrbiterC = RotL64((aOrbiterC * 2949407491181921633U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11436635942985063755U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17086363141014359856U;
            aOrbiterK = RotL64((aOrbiterK * 10504127577318206801U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10734017887545474935U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 375515325165740779U;
            aOrbiterH = RotL64((aOrbiterH * 9980486695448151709U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5217148491945389821U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14696058217023530058U;
            aOrbiterF = RotL64((aOrbiterF * 11026674782236654799U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11869055287836412650U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16951500118659983436U;
            aOrbiterI = RotL64((aOrbiterI * 4304372681583055077U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7866300390953569803U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 18017335943787362993U;
            aOrbiterA = RotL64((aOrbiterA * 15683049583437004889U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2477944286851267725U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3917730204724097072U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6617615984203047419U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 39U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterJ, 27U));
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterE, 35U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterD, 41U));
            aWandererG = aWandererG + (((((RotL64(aCross, 35U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aNonceWordA) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterC, 6U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 53U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 51U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterH, 44U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererH, 42U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14463U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15510U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12202U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneC[((aIndex + 14301U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 6U) + RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererI + RotL64(aIngress, 43U)) + 4752759164691497960U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 14U)) + 12088872623537639782U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 19U)) + 3734943577379734227U) + aNonceWordO;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 39U)) + 8854778183012444234U) + aNonceWordI;
            aOrbiterK = (aWandererE + RotL64(aScatter, 3U)) + 16948373492893967275U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 7962415690046184385U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 1872682375669714454U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 53U)) + 7776801806943853566U) + aPhaseFOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aScatter, 48U)) + 16665439117257230732U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 11088186766134265676U) + aPhaseFOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 41U)) + 10850237991780969350U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6464817712131305812U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 244557182884209844U;
            aOrbiterE = RotL64((aOrbiterE * 2394270354887582889U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13261563971157415841U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2323811103717827362U;
            aOrbiterI = RotL64((aOrbiterI * 11483723582415081925U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 12338803568475493422U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2811342930111104982U;
            aOrbiterG = RotL64((aOrbiterG * 5020981755203607757U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5554497011738996057U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 12712169745460598698U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1985586486150377769U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17415058661427002973U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9430421222715343818U;
            aOrbiterH = RotL64((aOrbiterH * 10321140659099470811U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3926618548181233180U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6172453297026957838U;
            aOrbiterD = RotL64((aOrbiterD * 1161551082037835233U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8633288765997226004U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17270881130844274342U;
            aOrbiterC = RotL64((aOrbiterC * 8888559940161770791U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12232950994807835262U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15352600312956742750U;
            aOrbiterB = RotL64((aOrbiterB * 6140396356904933003U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5614120002595447983U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1920822446545182835U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17049182594382482085U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 625576652179261739U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2362773059031414585U;
            aOrbiterA = RotL64((aOrbiterA * 17049048587829564949U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16749690978107177915U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4752759164691497960U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8442185754037031199U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 18U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 34U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 5U));
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterA, 22U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterD, 47U));
            aWandererF = aWandererF + (((RotL64(aScatter, 4U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterI, 19U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + aNonceWordP) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterG, 11U)) + aNonceWordM) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 24U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterA, 53U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterI, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16865U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17130U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19300U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17253U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 10U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 23U)) + 11698283336767769359U) + aNonceWordN;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 39U)) + 13297826354831483872U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 37U)) + 15254999058287530795U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aScatter, 58U)) + 17474166585085346567U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 41U)) + 15684783498452840289U) + aPhaseFOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 5061229733465216486U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 29U)) + 15370981279168377944U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 13U)) + 17966672773619554092U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 51U)) + 14685092893994491068U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 12798804186209406389U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 46U)) + RotL64(aCarry, 51U)) + 2848444181474221574U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 8551142075919636146U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8833198159158950723U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7650289040764974737U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7351473160893666232U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14204899612487622222U;
            aOrbiterH = RotL64((aOrbiterH * 6317485031956448029U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7008985178526543258U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13576796403863120356U;
            aOrbiterE = RotL64((aOrbiterE * 13745839827679114077U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5769784656937900699U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14075925808204936705U;
            aOrbiterA = RotL64((aOrbiterA * 5844894088757604713U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17818667502858010896U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16016922065572683130U;
            aOrbiterK = RotL64((aOrbiterK * 7525645833898085373U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1582458237855075977U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10830440354527138227U;
            aOrbiterB = RotL64((aOrbiterB * 10499386926982228251U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10653964151654643772U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 11218475491129483859U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 3338108067044357141U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9863649760189649255U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13790281439048354358U;
            aOrbiterG = RotL64((aOrbiterG * 4682098083538482849U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14846954923718136337U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 522207783972623813U;
            aOrbiterJ = RotL64((aOrbiterJ * 14299798934454852811U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 426829715716262697U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7482977730216354509U;
            aOrbiterI = RotL64((aOrbiterI * 6317437989422015173U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10736099808538972990U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11698283336767769359U;
            aOrbiterD = RotL64((aOrbiterD * 17230175904095995929U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 26U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterA, 50U));
            aWandererC = aWandererC + ((RotL64(aCross, 14U) + RotL64(aOrbiterH, 13U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterF, 21U));
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 34U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterG, 38U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25730U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 22260U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24886U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21896U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aCross, 27U)) + 3561491146322798260U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 19U)) + 7075025056181885339U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 40U)) + 9230910887904171613U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 4119781172609908917U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 43U)) + 17155609083870983149U;
            aOrbiterA = (aWandererC + RotL64(aCross, 3U)) + 2423018561430181695U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 6U)) + 12957280305617615744U) + aPhaseFOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 2461704174772065813U;
            aOrbiterB = (aWandererI + RotL64(aCross, 53U)) + 7907123257849391997U;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 7257868138318960007U) + aNonceWordC;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 47U)) + 16425903703085702285U) + aPhaseFOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2990822664594079467U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 5654819006718953817U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4465096036756887801U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12183676471235678779U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15026286960542123922U;
            aOrbiterA = RotL64((aOrbiterA * 17199049329995315279U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12169080607071830522U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2906296852254787499U;
            aOrbiterJ = RotL64((aOrbiterJ * 6754514406846040163U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3029858695410344584U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14406410317495954566U;
            aOrbiterH = RotL64((aOrbiterH * 9663780721657983421U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11048818178401163861U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13622063920319445043U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2516025554421589857U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2642646089141233277U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12761571777929273548U;
            aOrbiterE = RotL64((aOrbiterE * 5518252696078700127U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7753802695131502382U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 8510425459525030222U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12412361423636026483U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13522645164493316722U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1437430302489702713U;
            aOrbiterB = RotL64((aOrbiterB * 14019316635365783545U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14745189473423751499U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16968328257002103715U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 17915588590593471981U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5001838243344386314U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13506188720092630563U;
            aOrbiterG = RotL64((aOrbiterG * 7010027510838271877U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16902624500530747723U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3561491146322798260U;
            aOrbiterF = RotL64((aOrbiterF * 95761172090277669U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 26U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterA, 13U));
            aWandererC = aWandererC + ((RotL64(aScatter, 54U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterI, 37U));
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 60U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterC, 23U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 39U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterK, 40U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 21U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32052U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29865U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29256U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30604U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 18U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (((aWandererF + RotL64(aScatter, 14U)) + RotL64(aCarry, 57U)) + 77518479758428414U) + aNonceWordN;
            aOrbiterH = ((((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 4832061802166300011U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 21U)) + 11695291171006574112U;
            aOrbiterI = (aWandererB + RotL64(aCross, 3U)) + 7467412817843260094U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 18U)) + 17801484124471154757U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 47U)) + 5555455638503958639U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 57U)) + 5669470540733721606U) + aNonceWordI;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 3042388456327784163U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 27U)) + 2236734925228156691U) + aPhaseFOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 29U)) + 14459720401528685450U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 5U)) + 4814967631216658856U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16950679344449075945U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 6262238639302011050U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 9942659897425088183U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3522256359074996724U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 12524717897707074242U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6787771338063891989U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13891759914865623828U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11910250571469028666U;
            aOrbiterK = RotL64((aOrbiterK * 12311343917878428995U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2240189915640314069U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5365912986308810837U;
            aOrbiterG = RotL64((aOrbiterG * 15133972552032469957U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9323732721344489753U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13087326560957916553U;
            aOrbiterJ = RotL64((aOrbiterJ * 14659491687401151733U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16398238057564892809U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11517870519285159224U;
            aOrbiterE = RotL64((aOrbiterE * 1501848878469712681U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7758285512254776734U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17475149091906684720U;
            aOrbiterD = RotL64((aOrbiterD * 6015816725428299273U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2051631493975035243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11684740065349595315U;
            aOrbiterC = RotL64((aOrbiterC * 10918975496337269197U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10575473798991451167U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8267005776169272822U;
            aOrbiterB = RotL64((aOrbiterB * 13166868678285963961U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6249698995716039231U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 13808085811784323978U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3897731011582061983U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2739364646624876985U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 77518479758428414U;
            aOrbiterI = RotL64((aOrbiterI * 6977724811175035551U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 6U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 37U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            aWandererI = aWandererI + (((RotL64(aIngress, 46U) + RotL64(aOrbiterA, 23U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterB, 51U));
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 39U));
            aWandererD = aWandererD + (((((RotL64(aCross, 41U) + RotL64(aOrbiterC, 46U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aNonceWordM) + aPhaseFWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 35U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterG, 29U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterG, 53U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordF);
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

void TwistExpander_Tennis_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4123U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadA[((aIndex + 6858U)) & W_KEY1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 6603U)) & W_KEY1], 34U) ^ RotL64(mSource[((aIndex + 2435U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 15549114274303128055U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 16466750056388063241U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 23U)) + 12209449840836787142U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 58U)) + 14551496099734294336U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 13U)) + 6266576428679808622U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 16892841575635668152U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 5U)) + 7375966221423362125U;
            aOrbiterE = (aWandererG + RotL64(aCross, 28U)) + 11926105302821753530U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 37U)) + 16219253791550461124U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7299056065319248160U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15234001484933728439U;
            aOrbiterB = RotL64((aOrbiterB * 8182244796017018911U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6615802589932632120U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5481176858895819247U;
            aOrbiterC = RotL64((aOrbiterC * 3604590158551984877U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17220507586542139380U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14137921473739415340U;
            aOrbiterE = RotL64((aOrbiterE * 10634645686035907603U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16981960446540932787U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 10897565927079518588U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 418843936329303571U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 2746889569299593263U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4894117146736361379U;
            aOrbiterA = RotL64((aOrbiterA * 2656750612042673191U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18294823016957137777U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 86828501068883383U;
            aOrbiterI = RotL64((aOrbiterI * 11432686669235402365U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6322053762209547826U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 6754524552483363820U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1746163087826694641U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7306452650619361017U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12717201204443785828U;
            aOrbiterJ = RotL64((aOrbiterJ * 6121251603905574991U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10422327053543898585U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14786413282036348183U;
            aOrbiterF = RotL64((aOrbiterF * 8713024293107068275U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 52U) + aOrbiterF) + RotL64(aOrbiterA, 23U));
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 51U)) + aPhaseCWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterA, 58U));
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 13U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterF, 34U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterA, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererI, 10U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13249U)) & S_BLOCK1], 10U) ^ RotL64(mSource[((aIndex + 10733U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15549U)) & W_KEY1], 58U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16122U)) & W_KEY1], 27U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 50U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 37U)) + 8793908991006073956U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 23U)) + 2932916283348441943U) + aPhaseCOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 11069042087940968262U;
            aOrbiterC = (aWandererE + RotL64(aCross, 53U)) + 14369628676782894441U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 42U)) + RotL64(aCarry, 13U)) + 8602903272780978282U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 29U)) + 3827036107178568820U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 8905245209036772489U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 3U)) + 13331387530760017893U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 18U)) + 9880107580289737823U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10199619040626900278U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2466307560891374281U;
            aOrbiterH = RotL64((aOrbiterH * 6295342978834217571U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13973403407981259448U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 2851460278409385243U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11226902976321781743U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10365453393815690776U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2382382358987358791U;
            aOrbiterD = RotL64((aOrbiterD * 481563628980705781U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5058198848163792422U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 10500434740387593487U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5946747708776079787U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 11289798395177667084U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14327152153231286666U;
            aOrbiterK = RotL64((aOrbiterK * 18155778059595245561U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8065137263811956313U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3865153574847924816U;
            aOrbiterG = RotL64((aOrbiterG * 9495741102667755161U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18102279969722473375U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6306428427188742325U;
            aOrbiterC = RotL64((aOrbiterC * 17826782872351406167U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16953348204663693724U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11950791817032898613U;
            aOrbiterA = RotL64((aOrbiterA * 1498946055469611133U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11980823193543752994U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17845490308799454871U;
            aOrbiterB = RotL64((aOrbiterB * 16385153013485463791U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 24U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 41U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aCross, 22U) + aOrbiterC) + RotL64(aOrbiterD, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterK, 29U));
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aPhaseCWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterK, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 39U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17298U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18327U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21000U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16575U)) & W_KEY1], 28U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 23U)) ^ (RotL64(aIngress, 56U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererC + RotL64(aIngress, 23U)) + 11998579547770778580U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 35U)) + 8409465187298704610U) + aPhaseCOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 14U)) + RotL64(aCarry, 3U)) + 3470222286110333500U;
            aOrbiterA = (aWandererG + RotL64(aCross, 39U)) + 5704486785203069994U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 10334944660253279633U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 53U)) + 7626852700722567477U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 14631310754943209743U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 18U)) + 807160297237854120U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 3U)) + 5624154783624196107U) + aPhaseCOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4971444394698940423U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6340057638461027062U;
            aOrbiterG = RotL64((aOrbiterG * 12027586111086798629U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9003019862787819481U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13632057463595873033U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12575202147280216765U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12766104026871797746U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4062118445824915939U;
            aOrbiterA = RotL64((aOrbiterA * 13130770039048080701U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5258212525426469978U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9956946981015983939U;
            aOrbiterC = RotL64((aOrbiterC * 8106382657040497669U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10837606223056473999U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13292864885504191134U;
            aOrbiterI = RotL64((aOrbiterI * 4445739587553669471U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 166087925900318658U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6786842221885441388U;
            aOrbiterJ = RotL64((aOrbiterJ * 4411147600413147773U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16888086378070246404U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5240855484445974002U;
            aOrbiterF = RotL64((aOrbiterF * 402652898573422271U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6874866669211571608U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 732890824978127460U;
            aOrbiterK = RotL64((aOrbiterK * 3776365957702257453U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5541380495707308058U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17947326584411475765U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10920952349981652899U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 10U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 50U) + RotL64(aOrbiterA, 46U)) + aOrbiterI) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 13U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterI, 41U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 27U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterB, 53U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 20U)) + aOrbiterF) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30509U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29940U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28710U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29069U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 58U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 9435962834163239322U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 39U)) + 10524704356081318973U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 7403401305665208680U) + aPhaseCOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 24U)) + RotL64(aCarry, 35U)) + 7525414805023556493U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 53U)) + 1116686470029070951U;
            aOrbiterE = (aWandererI + RotL64(aCross, 5U)) + 13257612299137802420U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 43U)) + 9181543003986598283U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 19U)) + 9739384852307501107U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 34U)) + 11308402900229016057U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14935167593705272337U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 7171824007631943535U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4839974427616194289U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8068411284829563567U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12350207458513447578U;
            aOrbiterA = RotL64((aOrbiterA * 813973258659041895U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 17039236343991574134U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 18291683592714999632U;
            aOrbiterI = RotL64((aOrbiterI * 7771718817924840713U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6239616841884430968U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10604527977569876774U;
            aOrbiterD = RotL64((aOrbiterD * 6972820410084939637U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1707724300671717658U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3802268808625297647U;
            aOrbiterG = RotL64((aOrbiterG * 11296811630387191563U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9423064323799920219U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 242153923313096551U;
            aOrbiterE = RotL64((aOrbiterE * 12117679073775630197U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 945801070951928277U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13094814302414492064U;
            aOrbiterK = RotL64((aOrbiterK * 14638176479878969775U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7572219725951040117U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 16494986983782503428U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2739189408707408171U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10949497978229234856U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11219643352002119905U;
            aOrbiterJ = RotL64((aOrbiterJ * 16900635614259262873U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 54U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 24U) + aOrbiterJ) + RotL64(aOrbiterB, 43U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + aPhaseCWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 12U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterE, 39U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 51U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterK, 35U));
            aWandererC = aWandererC + (((RotL64(aIngress, 20U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 3U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Tennis_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7756U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((aIndex + 931U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3956U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7809U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 15910560457440369082U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 17953072986407436888U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 3U)) + 15446940721193538669U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 3020785262774422009U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aIngress, 48U)) + 7001288645424994404U) + aPhaseDOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13385250665458462689U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4841895644623005949U;
            aOrbiterK = RotL64((aOrbiterK * 3898487345974386945U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 13053476783239482065U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 641996979335975244U;
            aOrbiterC = RotL64((aOrbiterC * 3697673197256549833U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16211238020928688299U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12715448751323279480U;
            aOrbiterH = RotL64((aOrbiterH * 2116880429675303291U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17784406727699995290U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16626339815786580778U;
            aOrbiterF = RotL64((aOrbiterF * 13940754474750138041U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9035070625716345139U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6085848172494001945U;
            aOrbiterI = RotL64((aOrbiterI * 10405728912339646693U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 24U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 3U)) + aOrbiterK) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterI, 21U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 30U)) + aOrbiterC) + aPhaseDWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10994U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13269U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13598U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9461U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 4752759164691497960U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 21U)) + 12088872623537639782U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 43U)) + 3734943577379734227U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 8854778183012444234U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 4U)) + RotL64(aCarry, 11U)) + 16948373492893967275U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7962415690046184385U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1872682375669714454U;
            aOrbiterI = RotL64((aOrbiterI * 959061892772099785U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7776801806943853566U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16665439117257230732U;
            aOrbiterH = RotL64((aOrbiterH * 6866375628213114965U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11088186766134265676U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10850237991780969350U;
            aOrbiterK = RotL64((aOrbiterK * 7547414856143095121U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6464817712131305812U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 244557182884209844U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2394270354887582889U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13261563971157415841U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2323811103717827362U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11483723582415081925U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 42U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterD, 53U)) + aOrbiterI) + aPhaseDWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 12U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24434U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18162U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18368U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 18890U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 3238389262925516513U) + aPhaseDOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 12381787182611386995U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 43U)) + 7883885539305181549U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 12U)) + RotL64(aCarry, 51U)) + 1185413044597727092U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 35U)) + 15219353497204773135U) + aPhaseDOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7533774715626734082U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2599930450937763464U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13207380361960949159U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 16074720663961214284U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15483613196360051221U;
            aOrbiterH = RotL64((aOrbiterH * 11717479088020532861U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9396557867081376268U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9668459976852660245U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11748505665890567063U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9037269914643207212U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16936742640861088240U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1040172193161012227U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16481274825758546398U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 481851372837611166U;
            aOrbiterE = RotL64((aOrbiterE * 2225030139210599207U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterD, 35U));
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 52U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 44U) + aOrbiterE) + RotL64(aOrbiterJ, 11U)) + aPhaseDWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererE, 48U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28173U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((aIndex + 32425U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30013U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25372U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 47U)) + 8020711767807230555U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 53U)) + 15368693777246341570U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 5117523734225562401U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 6U)) + RotL64(aCarry, 35U)) + 13155269151097507808U) + aPhaseDOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 29U)) + 9879303753623578272U) + aPhaseDOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1165799257173794826U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 930641942062732091U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17151944851548731159U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11330571332221123153U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2862963158282518899U;
            aOrbiterH = RotL64((aOrbiterH * 13782195862525974199U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6019186399361476659U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1924419843785161958U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9485557122500346869U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12618629043591380461U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9334176504266512405U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18239109235362925739U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16829692481030013551U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5604784396927022709U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2833893610883508353U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 6U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 50U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Tennis_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 672U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7497U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 829U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7165U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 20U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 27U)) + 15188686795415908074U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 17310049041983079779U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 8246925977992441471U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aPrevious, 60U)) + 8644260919918112781U;
            aOrbiterG = (aWandererC + RotL64(aCross, 35U)) + 13401663736874819483U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 7940358935238314973U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 43U)) + 13278990328548007839U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11346868298353840706U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2374077904806833579U;
            aOrbiterI = RotL64((aOrbiterI * 1765686942154321425U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6978903378645019166U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11951633297870965212U;
            aOrbiterG = RotL64((aOrbiterG * 12778236598654492185U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17398460995357409673U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1215437945597836770U;
            aOrbiterK = RotL64((aOrbiterK * 9322970054123481621U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1878751468043972239U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5343002808239712390U;
            aOrbiterC = RotL64((aOrbiterC * 11878640995447558811U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9884918450053276861U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15894599082080422550U;
            aOrbiterB = RotL64((aOrbiterB * 8359936745539546131U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13917339232771145459U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 18101134009493720683U;
            aOrbiterD = RotL64((aOrbiterD * 15835859435306756387U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3830086372356903769U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15894394599564584010U;
            aOrbiterJ = RotL64((aOrbiterJ * 9513921913446609263U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 13U));
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 29U));
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 50U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 52U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14969U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10831U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10424U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 9773U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 29U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererB + RotL64(aPrevious, 20U)) + 5041131702736607991U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 9295010428212681446U) + aPhaseEOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aIngress, 51U)) + 6235875895358766017U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 2622227802531866918U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 3888894734834524972U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 3U)) + 241682012014701753U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aScatter, 39U)) + 15758000422451568079U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2061944548396976912U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8177144990755754531U;
            aOrbiterH = RotL64((aOrbiterH * 12702392689484397947U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 554978075608818497U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 250408260560714933U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1295379390497107727U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8700027645880997552U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10026130047465480902U;
            aOrbiterA = RotL64((aOrbiterA * 12417270861933696623U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9785843014096326696U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9998582683258411251U;
            aOrbiterB = RotL64((aOrbiterB * 7197956237569462269U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13817734599383455151U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6647207154174092691U;
            aOrbiterC = RotL64((aOrbiterC * 1578528131687283531U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4957715980509035719U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4994885315786213197U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5676683798126497011U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5072908311783966503U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5535039946192891515U;
            aOrbiterD = RotL64((aOrbiterD * 2989412783482309753U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 13U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterF, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 26U));
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18292U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 18669U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16949U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 23693U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 42U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aIngress, 3U)) + 2330952702412094686U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 7820188225935060799U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 35U)) + 9347644591709839145U) + aPhaseEOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 2288624878446846870U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 9358977729492824128U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 42U)) + 1858511275052455039U;
            aOrbiterE = (aWandererG + RotL64(aCross, 27U)) + 13715478509322292552U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16413396625604260455U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17714322215518432705U;
            aOrbiterG = RotL64((aOrbiterG * 1904184102419934333U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16188315436202861122U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5564445841368207813U;
            aOrbiterI = RotL64((aOrbiterI * 14125834616162835983U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13717068949900594673U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14143659432287313765U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17281441046722262917U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5729546141908425670U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4297827922736712074U;
            aOrbiterC = RotL64((aOrbiterC * 13631630436759768885U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 829520109395163673U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 11547160328525174295U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4759690159673049775U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2907177944512117206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11100346409065275671U;
            aOrbiterF = RotL64((aOrbiterF * 17927994356809011637U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 1344592529249949068U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6470438516791143572U;
            aOrbiterE = RotL64((aOrbiterE * 13339390828725370475U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterF, 19U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 26U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28791U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24609U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26848U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 30890U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 6521330037475130256U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 12611880456055428940U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 5U)) + 12061611078130934708U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 43U)) + 1558112410801116984U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 10509115227850160786U) + aPhaseEOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 28U)) + 4045915960688792066U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 57U)) + 1196541286513243082U) + aPhaseEOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15564991032722373702U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4897765238703641798U;
            aOrbiterB = RotL64((aOrbiterB * 9693901276712946763U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12327429514907752733U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6189189797708711636U;
            aOrbiterA = RotL64((aOrbiterA * 9017615866338877651U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6374267075282018852U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1888758503831341439U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 74387714918264257U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14956857689299491800U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14879361107223331957U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9166712966729591953U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16086885494838105042U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8069724185844303923U;
            aOrbiterF = RotL64((aOrbiterF * 8878470736758734353U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10854345917959911439U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 7078313614360332089U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9864025732292844871U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15083669236062255011U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 594879695916679116U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9852515479152735283U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterB, 50U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 27U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 5U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterA, 11U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 43U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Tennis_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5264U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5147U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1344U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4080U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 47U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererA + RotL64(aCross, 57U)) + 8402620908307642697U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 11347672014525086047U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 51U)) + 2816462912503401876U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 6940159795470696093U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 26U)) + 9134692490095883851U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4999455497008026526U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5992451460350651332U;
            aOrbiterD = RotL64((aOrbiterD * 12796550245322491401U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3417087346651371924U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3612773820086198270U;
            aOrbiterB = RotL64((aOrbiterB * 5519856345435871169U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 463398077083428570U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11249391303705089012U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7106735772303292983U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17027535139825739501U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 568131384979596481U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5683451044852895957U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4793712537158004047U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10415170179135963622U;
            aOrbiterF = RotL64((aOrbiterF * 13729564030210361415U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterG, 6U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 56U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterB, 19U)) + aPhaseFWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 27U)) + aOrbiterB) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 28U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8618U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15953U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16211U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((aIndex + 8318U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 4384716820085860551U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 9715780315942116888U;
            aOrbiterK = (aWandererB + RotL64(aCross, 11U)) + 15963520052789178632U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 20U)) + RotL64(aCarry, 53U)) + 14346700690686392938U) + aPhaseFOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 41U)) + 6005518012489966643U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2506732930310252119U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16782163084851775826U;
            aOrbiterK = RotL64((aOrbiterK * 1527050617428162663U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 823673076571076303U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1634084509064077736U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1128407326773234517U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1288134975466877686U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2998220403162908444U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4321412662318298283U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 220430672180734911U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 10223923547068528867U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12577370238343872139U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11696469696177647608U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6545430420379636963U;
            aOrbiterC = RotL64((aOrbiterC * 8387163146257553773U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 52U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterK, 27U));
            aWandererA = aWandererA + (((RotL64(aScatter, 30U) + RotL64(aOrbiterE, 50U)) + aOrbiterC) + aPhaseFWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19164U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 22773U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18084U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 21450U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererD + RotL64(aIngress, 56U)) + RotL64(aCarry, 19U)) + 5480870806135400132U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 3U)) + 8034874599430768743U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 4006919843736863767U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 2988069748674633718U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 21U)) + 12347295651973135786U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14152683894431568192U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15765143815254196598U;
            aOrbiterE = RotL64((aOrbiterE * 8948877544291035189U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10473067082331244233U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1089466925383677249U;
            aOrbiterB = RotL64((aOrbiterB * 17334888609179149753U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13215039929873682230U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3957997712247961479U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7631186240013784703U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10023907397941685546U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14593012591254614353U;
            aOrbiterI = RotL64((aOrbiterI * 17111300092082154687U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13353797968154036726U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9259966668512102858U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8326732574268308221U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 56U) + aOrbiterK) + RotL64(aOrbiterI, 48U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterA, 37U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31480U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 27307U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26747U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 31100U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 53U)) + 2786079456995203065U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 22U)) + RotL64(aCarry, 27U)) + 7237256119153857253U) + aPhaseFOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 9310834010563647604U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 17361734905706517877U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 43U)) + 15837111231884647451U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 18065431964418026445U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3029123922999952652U;
            aOrbiterF = RotL64((aOrbiterF * 16309219658285890145U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5166926595573507837U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1918425684273807598U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16616641579714896719U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4724551751012661440U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1818014487579644390U;
            aOrbiterK = RotL64((aOrbiterK * 14904092108647864911U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6670090372241084216U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8485757110007268693U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11876760095108618363U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4928130251509514742U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 2528788422725346792U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1855982047967756661U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 46U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 41U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterK, 14U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 26U) + aOrbiterJ) + RotL64(aOrbiterK, 5U));
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 57U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Tennis_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5461U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 3271U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 76U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((aIndex + 5884U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 52U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 38U)) + RotL64(aCarry, 51U)) + 9023059520606551446U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 57U)) + 662441755115638133U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 16957253361196144712U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 7840955025765308605U) + aPhaseGOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aScatter, 21U)) + 346855809270395799U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16099139781586668343U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3706457327118322098U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7810030620470889591U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12166825885547622870U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7792658665720344200U;
            aOrbiterB = RotL64((aOrbiterB * 16305542632794270697U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7128477606152986326U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11116533962780290084U;
            aOrbiterJ = RotL64((aOrbiterJ * 11993485572912492297U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10443889548568288532U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4402387036946561017U;
            aOrbiterA = RotL64((aOrbiterA * 9032964741841833277U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13002706161178447654U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 13929727277530310708U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7005639090871200285U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + aPhaseGWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 10U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 29U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 20U) + aOrbiterB) + RotL64(aOrbiterF, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12944U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12598U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8697U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((aIndex + 14837U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 28U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 2168513956284366370U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 10290361969974613111U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 22U)) + RotL64(aCarry, 41U)) + 15673836275828498050U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 43U)) + 16600540024145812236U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 5U)) + 9428052101528111892U) + aPhaseGOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12763657928312763377U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10751286982008662485U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6169084301655877217U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1708230173038057979U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 4011389705422783816U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11692237130784795961U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11704428328093077714U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2055336619674699284U;
            aOrbiterI = RotL64((aOrbiterI * 6374289210096410907U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 1870865272102705804U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3574214263751923179U;
            aOrbiterA = RotL64((aOrbiterA * 13132083406834413563U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 984611970726966186U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15207945449947643672U;
            aOrbiterD = RotL64((aOrbiterD * 9539470161576639981U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterG, 12U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterA, 37U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 3U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + aPhaseGWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 22947U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 21164U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21419U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 21735U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 4U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 36U)) + 9888431329297626900U) + aPhaseGOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 2937735167534624403U) + aPhaseGOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 17626022970343789617U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 5665660859333693743U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 5U)) + 1060537034632076669U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 743777763907175800U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5744905970181808845U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17426701505806885785U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3545351394494002180U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4877547088414106007U;
            aOrbiterF = RotL64((aOrbiterF * 5416792889338547109U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11669378338379598445U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2961072441706158212U;
            aOrbiterC = RotL64((aOrbiterC * 2677988507090705371U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 13984945589234919765U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1433097875470903205U;
            aOrbiterG = RotL64((aOrbiterG * 451996840039906781U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 716415411025451152U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8542286150858297810U;
            aOrbiterA = RotL64((aOrbiterA * 9139015340823332449U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterC, 39U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 38U) + aOrbiterB) + RotL64(aOrbiterF, 19U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 48U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterA, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 34U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 28761U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31993U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30150U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29685U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 40U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererF + RotL64(aCross, 43U)) + 7270044678408187242U) + aPhaseGOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 10192278965379756766U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 17568666746676060748U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 34U)) + RotL64(aCarry, 11U)) + 14312927531124963037U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 21U)) + 9825825726152087706U) + aPhaseGOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9696778570255265896U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17657841352013417228U;
            aOrbiterG = RotL64((aOrbiterG * 17562220176018833833U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16207815085909628439U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 1752979206374514227U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14182667540650694199U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10456310689643905854U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16127830548663742550U;
            aOrbiterD = RotL64((aOrbiterD * 4355938404839045417U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2940917376003930842U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7353596864777649953U;
            aOrbiterJ = RotL64((aOrbiterJ * 7499468723171042005U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12725092740446150705U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5791296650856037010U;
            aOrbiterE = RotL64((aOrbiterE * 760379251950502133U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 58U)) + aPhaseGWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 29U)) + aOrbiterI) + aPhaseGWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterI, 47U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Tennis_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 5876U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 2430U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3609U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 2480U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 40U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 9107326720193244489U) + aPhaseHOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 56U)) + 10868585484401664145U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 13637736741437846622U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 19U)) + 6130725216183918844U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 2063834478521338187U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8564870627911949158U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6524015751064086390U;
            aOrbiterJ = RotL64((aOrbiterJ * 12055267995727104463U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9874937766875388236U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14723718409522680894U;
            aOrbiterC = RotL64((aOrbiterC * 17379140128833323431U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13767059954741528279U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6387608251033722169U;
            aOrbiterH = RotL64((aOrbiterH * 6601902195707980693U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5391425980008431000U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11524218415655093779U;
            aOrbiterB = RotL64((aOrbiterB * 12508457981779189389U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 155510463350385905U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10554591788433641311U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5412084824127934293U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 14U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterH, 39U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 20U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 23U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterC, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererI, 58U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13012U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15709U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11218U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 15156U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 43U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 14249093584376402677U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 8756965951816492264U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 29U)) + 11221139480258176330U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 17218894445564194851U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aIngress, 60U)) + 8064642692524949490U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5822093203710704646U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3217799620158102238U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2806328682494910635U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2613757677892120843U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13647481499551657237U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5517563514031899891U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3545714196663685016U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9735422670576621521U;
            aOrbiterA = RotL64((aOrbiterA * 7276207208162697249U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3911046580637583767U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9315984027042049203U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12568550776487242469U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8926367674641729058U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11035347490524961446U;
            aOrbiterD = RotL64((aOrbiterD * 10948288997163592463U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 20U)) + aOrbiterH) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 12U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 20913U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 23417U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23961U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 23668U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 44U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aCross, 48U)) + RotL64(aCarry, 19U)) + 9471546960258473684U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 18050235435948942244U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 3005107102671544641U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 57U)) + 17898396434573801850U) + aPhaseHOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 13U)) + 15071602525497771648U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5780119462702672108U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13301326224151025687U;
            aOrbiterB = RotL64((aOrbiterB * 2868878978993219351U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 18129323022260575961U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1199228670638790709U;
            aOrbiterI = RotL64((aOrbiterI * 1780426336211781025U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 1839199978088021020U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4999517042246790165U;
            aOrbiterG = RotL64((aOrbiterG * 4585813675677234577U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8788607633376516299U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15143903839930468749U;
            aOrbiterH = RotL64((aOrbiterH * 12735914889325422675U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16674732686428431869U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15908873150953195581U;
            aOrbiterK = RotL64((aOrbiterK * 18049755517524334107U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 29U)) + aOrbiterH) + aPhaseHWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 5U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 42U) + aOrbiterI) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 25946U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 25867U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26634U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneC[((aIndex + 25815U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 36U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 1393781663398437180U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 17414594746688585273U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 3U)) + 2823888497053071250U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 48U)) + RotL64(aCarry, 19U)) + 17032631958617884859U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 23U)) + 15222697630461125019U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15737414920751551780U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1357196111055783001U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8225423829221938165U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5315122321649251691U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7893744655508595974U;
            aOrbiterC = RotL64((aOrbiterC * 17863000246694319149U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16721939414324611738U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3444375866323610848U;
            aOrbiterI = RotL64((aOrbiterI * 10874157227815775661U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1825716513674511632U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 15582066843912467318U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12765146555943757373U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 15673590949193923915U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13887365046280406413U;
            aOrbiterJ = RotL64((aOrbiterJ * 3169061375011420121U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 36U) + aOrbiterB) + RotL64(aOrbiterC, 21U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 34U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 47U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + aPhaseHWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
