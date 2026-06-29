#include "TwistExpander_Archery_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Archery_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF94C4CF570837629ULL + 0x939A47A356BD3808ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEA0A4346986AA45FULL + 0xE449185D9EB68307ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD7297DC5D2A5164FULL + 0xA96F782EDAD6C0AEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEEE56236C949E721ULL + 0xECA2DB389C4E35CCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA2B4CD9B4DA32785ULL + 0xFAC4C56BE1BDB23AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA3B528D8E3A2E51FULL + 0xED96FACE10329577ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF1DC6BC33E76DD7DULL + 0xC3438035CB9E3E07ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9591C31946617125ULL + 0xF494EAAD35B0C6D6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA02F73314B2131E5ULL + 0x91595295DE1BBB71ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCDE0E8E54E5F5EF5ULL + 0xD24D66EAB77B03BEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9D22D152568E1281ULL + 0xE3F0A6923FD2FD46ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x834A752998EFD885ULL + 0xF3D7206C85F5D048ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCF8A95B0734E3A23ULL + 0xDB78D90E07FE442FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF04629A904E66FD5ULL + 0xC5F36CA4262B23D8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x87495450B8F02651ULL + 0xABCD70AA5E8A2FB1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDCF525F38AA433AFULL + 0xCF6873FB0D1847FDULL);
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
            aIngress = RotL64(mSource[((aIndex + 3385U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1288U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 4282U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((aIndex + 85U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = ((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 53U)) + 12849591986267890852U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 29U)) + 8232614804696815750U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 12141567259210877281U) + aNonceWordM;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 41U)) + 2928641981037885644U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 21U)) + 980733350554783938U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 2683985177993350746U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 53U)) + 14532148403815527355U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 5U)) + 7736296629433884203U) + aNonceWordA;
            aOrbiterE = (aWandererG + RotL64(aScatter, 60U)) + 10428437770166310549U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 43U)) + 18327174144859461029U;
            aOrbiterD = (aWandererF + RotL64(aCross, 13U)) + 6810436935194432002U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12606153309690753435U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17123256945895150555U;
            aOrbiterH = RotL64((aOrbiterH * 13469111258504672565U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9057777759026189541U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16478485918911194442U;
            aOrbiterF = RotL64((aOrbiterF * 11054247078884894131U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18064460487552100483U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11477276762421684083U;
            aOrbiterJ = RotL64((aOrbiterJ * 3886501230380184395U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 18318375441973295081U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13849305985380030986U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 12962140243967824959U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10240409420338313641U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18360586077779529086U;
            aOrbiterG = RotL64((aOrbiterG * 18196875422391501927U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16801797158622424257U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4950305991208513887U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4437082499761416951U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15790878572843321918U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9808781805065559728U;
            aOrbiterC = RotL64((aOrbiterC * 9394280083159162953U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11974996650410830731U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4955004489435232515U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13301966529515483085U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1187569634223338864U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5351017164244226367U;
            aOrbiterA = RotL64((aOrbiterA * 14735674576470803699U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9587142385246940125U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16253850371962732943U;
            aOrbiterE = RotL64((aOrbiterE * 3408021872390904463U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14990060157351237661U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 12849591986267890852U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 2158106726261981983U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterG, 10U)) + aNonceWordI);
            aWandererD = aWandererD + ((RotL64(aCross, 56U) + aOrbiterC) + RotL64(aOrbiterK, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 3U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterG, 23U)) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterD, 44U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterG, 57U));
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 37U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 51U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 18U) + RotL64(aOrbiterB, 19U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 53U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 8207U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((aIndex + 7951U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8331U)) & S_BLOCK1], 14U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7323U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 41U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (aWandererE + RotL64(aPrevious, 47U)) + 14157904117287696136U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 54U)) + 7369512677371640676U) + aNonceWordC;
            aOrbiterF = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 8411250745902073798U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 35U)) + 5002041814539710275U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 9538041410816283124U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 41U)) + 5210700103927513061U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 7600709399101287982U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 27U)) + 2366369466696580499U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 19U)) + 5544575244203019109U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 13U)) + 8710073749110329779U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aWandererK + RotL64(aIngress, 22U)) + 15998211310115361630U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 15354357553877376422U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10657523549259276169U;
            aOrbiterF = RotL64((aOrbiterF * 13695239532898311073U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10405750198355464768U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3465819693133515142U;
            aOrbiterJ = RotL64((aOrbiterJ * 14678343718277562799U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16724189641701408630U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3484340153620198872U;
            aOrbiterB = RotL64((aOrbiterB * 17247547677520703125U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7420442404884871126U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11138445997256757636U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 11167543379937571127U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1428191560884663125U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16950093140800653985U;
            aOrbiterA = RotL64((aOrbiterA * 4423012306984814805U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 17288299075036481960U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 13793597915359681028U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9639204979982125757U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5017972942710079726U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12409957957614320964U;
            aOrbiterC = RotL64((aOrbiterC * 10273295741911545745U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12487994181992095174U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1573393166996612118U;
            aOrbiterK = RotL64((aOrbiterK * 13364311829104520751U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13227642825780350128U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7961292096150889569U;
            aOrbiterG = RotL64((aOrbiterG * 16627209081334341289U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10312485102088913337U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3177620041478410950U;
            aOrbiterI = RotL64((aOrbiterI * 15918551366833593853U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2599092792737616563U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 14157904117287696136U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14883446269291639813U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterG) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 11U)) + aOrbiterJ) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterF, 5U));
            aWandererA = aWandererA + (((RotL64(aIngress, 40U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterB, 26U)) + aNonceWordJ);
            aWandererF = aWandererF + ((((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterE, 13U));
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 28U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aIngress, 10U) + aOrbiterH) + RotL64(aOrbiterI, 47U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererA, 56U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 15229U)) & S_BLOCK1], 24U) ^ RotL64(mSource[((aIndex + 14982U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15862U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 15916U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCross, 26U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 38U)) + RotL64(aCarry, 43U)) + 16183871922837164759U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 7002058258090219055U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 5U)) + 5650868611888303705U) + aNonceWordN;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 11899839660943876690U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 12U)) + 15349649504488111111U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 43U)) + 14060149569086744970U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 41U)) + 12920917574225030112U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 57U)) + 2831994965175330135U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 27U)) + 18312543585028439192U) + aNonceWordP;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 29U)) + 11657562205118394239U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aScatter, 19U)) + 10850792819281246052U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17810371216216125323U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 7963413941144223128U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 534217972450595401U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5498715358793875584U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9256727548911651373U;
            aOrbiterA = RotL64((aOrbiterA * 10498848323914000989U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17246360111302191699U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 18309978718113983369U;
            aOrbiterK = RotL64((aOrbiterK * 18267472694666221077U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3100998994319502921U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8129301860291235970U;
            aOrbiterB = RotL64((aOrbiterB * 17847033539279176187U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1889641029473279114U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16538494307002917945U;
            aOrbiterJ = RotL64((aOrbiterJ * 8081488217920885783U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5432230549146849322U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2634437941396090817U;
            aOrbiterI = RotL64((aOrbiterI * 7612999214758935211U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16940172599174185058U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13151669140593952203U;
            aOrbiterF = RotL64((aOrbiterF * 16225319638131723487U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3995064294869931681U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 913081077665768816U;
            aOrbiterC = RotL64((aOrbiterC * 9299514648768060453U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2469001696075411481U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 2167390955194185443U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11805065572289005223U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 1574066406534010796U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8736976961589874013U;
            aOrbiterG = RotL64((aOrbiterG * 5980070607180321955U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4233621443153132083U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16183871922837164759U;
            aOrbiterD = RotL64((aOrbiterD * 4030569514959370895U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 39U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 44U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterD, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterH, 29U));
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterF, 10U)) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + aNonceWordK);
            aWandererF = aWandererF + ((((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + aNonceWordB);
            aWandererK = aWandererK + ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 56U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 37U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterB, 23U)) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 24U) + aOrbiterH) + RotL64(aOrbiterE, 5U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 43U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 18U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19808U)) & S_BLOCK1], 34U) ^ RotL64(pSnow[((aIndex + 16687U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 20016U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 19702U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21176U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 41U)) + 13650869943246163567U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 3U)) + 3435284932011770999U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aScatter, 51U)) + 12388155658186776579U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 57U)) + 2374345913955712039U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 23U)) + 6095094526980292156U) + aNonceWordF;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 4965147025852444174U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 54U)) + 3261881216269075298U;
            aOrbiterF = ((((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 4939780217097329222U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aWandererK + RotL64(aCross, 19U)) + 3019862009792676287U) + aNonceWordA;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 11U)) + 901910626217143974U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 34U)) + RotL64(aCarry, 37U)) + 3647055146712366383U) + aNonceWordO;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7731765438957392967U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13409819457393479741U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3345078200262410715U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5415832109107794258U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8876738832313114471U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 1304277600444504135U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17135570542519390359U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 2373193062766802082U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4213691513185791519U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16318403285501718552U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8456043288604687045U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 10556964529144571683U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10572534930284516528U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14616251186735204677U;
            aOrbiterI = RotL64((aOrbiterI * 2048651204265459805U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2837006243817205610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5315917323622194254U;
            aOrbiterG = RotL64((aOrbiterG * 4080522050089666599U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 12084676282761185907U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7922080344175593788U;
            aOrbiterC = RotL64((aOrbiterC * 7603522302708937379U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17620847289789547792U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12140386059533463650U;
            aOrbiterJ = RotL64((aOrbiterJ * 1443266480620969535U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4006608081473218762U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3152507055132739011U;
            aOrbiterB = RotL64((aOrbiterB * 11929522909695002321U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10845720206369283181U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16572752872386133133U;
            aOrbiterD = RotL64((aOrbiterD * 2891952650448087211U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15544908026178481075U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 13650869943246163567U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1275090431127426217U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 4U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 42U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI) + aNonceWordD);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 18U) + aOrbiterH) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 43U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 29U));
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterG) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterI, 40U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterH) + aNonceWordL) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 20U) + RotL64(aOrbiterG, 23U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterH, 53U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterC, 51U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 42U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26609U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 24570U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(pSnow[((aIndex + 22564U)) & S_BLOCK1], 36U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25332U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24194U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 27007U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 4U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = (aWandererB + RotL64(aIngress, 5U)) + 15920462086654025436U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 3U)) + 487844076858004017U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 14502883786442630566U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 42U)) + RotL64(aCarry, 47U)) + 3787107318658233674U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 11U)) + 12548777544693755491U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 47U)) + 4907309444075181683U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 21U)) + 18342396700266492072U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 39U)) + 13503051997624242670U) + aNonceWordC;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 57U)) + 17845742460521374571U) + aNonceWordO;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 8640887211877858169U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 34U)) + 5273913123709097537U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17756844173695563883U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6713055830729302951U;
            aOrbiterA = RotL64((aOrbiterA * 2832836748513174311U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5106468334224035972U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10228769728713526172U;
            aOrbiterI = RotL64((aOrbiterI * 9760310686414358435U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7687649520668883142U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7757480627354711605U;
            aOrbiterG = RotL64((aOrbiterG * 7222553727737349209U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10876291698508634557U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8149278085586014186U;
            aOrbiterH = RotL64((aOrbiterH * 8577133863470695381U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15592893988925610485U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8639028256640537165U;
            aOrbiterB = RotL64((aOrbiterB * 1880655276432963955U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 475660347892196219U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1903736092401853832U;
            aOrbiterF = RotL64((aOrbiterF * 8486318978769094799U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12463250192809450953U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7253918448601703982U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3821034106528009129U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 5171661020093804486U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11627344933828324146U;
            aOrbiterD = RotL64((aOrbiterD * 5388047063152043277U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6206801139131132815U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 9221302203943031377U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 12912049016813367241U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1798857939965423979U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5476854168685641232U;
            aOrbiterK = RotL64((aOrbiterK * 3884216989250294213U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2816659151953455230U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15920462086654025436U;
            aOrbiterC = RotL64((aOrbiterC * 17843161654734820613U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 56U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 35U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ) + aNonceWordL);
            aWandererG = aWandererG + ((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 52U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 19U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 57U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 30U) + aOrbiterE) + RotL64(aOrbiterA, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterH, 37U));
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterC, 54U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ) + aNonceWordN);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 41U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32389U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 29273U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 30715U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31078U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 30665U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 30273U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneB[((aIndex + 29982U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 44U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 11U)) + 1708250618750199233U) + aNonceWordE;
            aOrbiterC = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 12009147777553691142U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 47U)) + 8393982703399156592U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 51U)) + 3247327098356831221U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 3403590155376353737U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 6U)) + 18197244558104735044U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 3096253642040701606U;
            aOrbiterI = (aWandererD + RotL64(aCross, 29U)) + 8012692688785412179U;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 43U)) + 17531946907545680745U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aWandererJ + RotL64(aCross, 54U)) + 17687695944270225817U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 19U)) + 16147773866007628769U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18244641303026196497U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8839160526348897457U;
            aOrbiterD = RotL64((aOrbiterD * 14268021129087663397U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10599266240854068246U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2056723540756216155U;
            aOrbiterH = RotL64((aOrbiterH * 13311591601230386375U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4629354220460621284U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 9505955649473204942U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 17775391885312236187U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17078153810088721310U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9470436761716263000U;
            aOrbiterJ = RotL64((aOrbiterJ * 5431855497250357229U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3305863413630104742U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14377172434239576161U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 6880176890091033423U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 415687827894226513U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16975319836893760993U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6597144958013976445U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12707054129431596074U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8974182792497231239U;
            aOrbiterC = RotL64((aOrbiterC * 7874658957269462717U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10826131924322955095U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 4168545139712703154U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 10305904857550051705U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4539070253658625193U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3737870219498561326U;
            aOrbiterK = RotL64((aOrbiterK * 13130847633918921393U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11563084648810555040U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7410695535361901473U;
            aOrbiterF = RotL64((aOrbiterF * 7540855656023807389U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6687453696858775037U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1708250618750199233U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13104250803527718135U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 34U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterE, 43U)) + aNonceWordP);
            aWandererK = aWandererK + ((((RotL64(aCross, 14U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterA, 46U));
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 41U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aCross, 44U) + aOrbiterH) + RotL64(aOrbiterK, 39U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterI, 36U)) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 53U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 34U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Archery_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8FC04CF8FA946533ULL + 0x8C58DF1037E11490ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC0230C2118D32AFDULL + 0xCE167046147B8E5AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAE259C5EBA79066FULL + 0xBBAE2439B2FD039CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB748C5CA55E47317ULL + 0xD57AFD4B820CA913ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDBA96A89EFB74B53ULL + 0xE707AA1FBD866CF7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA5D1808475E78F61ULL + 0xFA0BF96A8D4D0087ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF8719110A2609F7BULL + 0xBB0A71B15ED0CDEAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF932FDE444A9FD93ULL + 0xCFBD9AD656DBF8E2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC702083C12593AE9ULL + 0xFA01E06284F4CC95ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBEC9D8CD908B994DULL + 0xE4DA5E2CAAA92B4AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC0725DE1299C1F13ULL + 0xC5512FD06BE9F5D3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAB7713370A8B8F27ULL + 0x8731BC96A453CC2EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD3F49B671689A675ULL + 0x98E70CE33BA86D80ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9FEA54CB46830541ULL + 0x95632C5C0AFB8151ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDE693CEBDF52762DULL + 0xBA6FD59EFA78BB6EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8F90EC76B19F8F4FULL + 0xB5D02E59B4D1BC97ULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 1285U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 4269U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2252U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((aIndex + 4015U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 57U)) + 1866656689936219099U) + aNonceWordI;
            aOrbiterJ = ((((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 2312314528139448289U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 18U)) + 3554037526469185237U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 35U)) + 405707755060974111U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aPrevious, 41U)) + 1862976326004007697U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 12992483065443288263U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 28U)) + RotL64(aCarry, 27U)) + 3793854946371595197U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 47U)) + 4244007978867369382U;
            aOrbiterF = (aWandererA + RotL64(aCross, 11U)) + 10280867500312580308U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 472563452959164242U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12041770406895816553U;
            aOrbiterG = RotL64((aOrbiterG * 17811798500132002631U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6118634015704900486U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13637107920449233307U;
            aOrbiterH = RotL64((aOrbiterH * 17712028184714868053U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16673735670669318830U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8602681273646630496U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6995213887710749241U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7683264695930369476U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9146674871199188218U;
            aOrbiterC = RotL64((aOrbiterC * 7403427067419261981U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3012935612827493084U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1259789268731661945U;
            aOrbiterF = RotL64((aOrbiterF * 2372843620327050137U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5623690455471160780U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 18355567776031865462U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9553862670107886679U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7705134893833304792U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 4435192506444773834U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 5249651218395299501U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6204683785806409075U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 17886971535016484255U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 6047216474762933535U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4430578901091376829U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 607557685798141547U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12342665567201483107U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 30U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterD, 44U)) + aOrbiterJ) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterG, 39U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 23U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 18U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterI, 5U)) + aOrbiterA) + aNonceWordL);
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 8465U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 10653U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9929U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7375U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 9325U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 50U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (((aWandererF + RotL64(aIngress, 24U)) + RotL64(aCarry, 29U)) + 4773124477323378268U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 51U)) + 16848723289435796005U) + aNonceWordJ;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 19U)) + 13846642134917107058U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 6472057872482789939U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 43U)) + 2747019500690707226U) + aNonceWordN;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 9003965289739733880U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 56U)) + 3013390651936257377U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 29U)) + 3331004709895625067U) + aNonceWordD;
            aOrbiterH = (aWandererE + RotL64(aScatter, 11U)) + 15355010435553517129U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7709870658004280052U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13568728443963926564U;
            aOrbiterA = RotL64((aOrbiterA * 6736090830113688981U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12409548853419307131U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 969183352023661537U;
            aOrbiterG = RotL64((aOrbiterG * 5549220554838837145U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 15370309834426476775U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3896803894396631184U;
            aOrbiterE = RotL64((aOrbiterE * 11018830202891911603U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10848873633291935766U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12885336509190543440U;
            aOrbiterI = RotL64((aOrbiterI * 1487357252619221365U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8252290890093788010U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9201553615601641350U;
            aOrbiterF = RotL64((aOrbiterF * 420321130559162915U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14014209645503188472U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4015071464301844550U;
            aOrbiterK = RotL64((aOrbiterK * 17444195018239904971U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16173085647514027347U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16916627014974363360U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 7699587344277490953U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1591680303404522110U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 16499606051269327916U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 814405848002794813U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6932673635509444619U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8745681160108707944U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14565255558668084787U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 51U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterF, 20U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 37U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterA, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aIngress, 22U) + RotL64(aOrbiterF, 5U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 12U)) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 14467U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 14838U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 13046U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14043U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((aIndex + 16357U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 56U)) + (RotL64(aIngress, 39U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = ((((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 13296600294247799698U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aWandererK + RotL64(aScatter, 39U)) + 5818503518080877515U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 6735784238734173597U) + aNonceWordN;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 6U)) + RotL64(aCarry, 21U)) + 7368398209488856201U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 51U)) + 961734029066455638U) + aNonceWordP;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 19U)) + 797011946660892011U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 43U)) + 12841876018396622350U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 26U)) + 16213253970483895623U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 13U)) + 15186950557113470375U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5117930310827477341U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12265429373166094162U;
            aOrbiterF = RotL64((aOrbiterF * 1522823535151532249U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13920531346698601568U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14695405206998211456U;
            aOrbiterC = RotL64((aOrbiterC * 13950964363414164279U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7851960904825938443U) + aNonceWordA;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 9501511171732550190U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 5614164120361489613U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5663365182245722077U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9607860124321315555U;
            aOrbiterK = RotL64((aOrbiterK * 3461820361914280601U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 18171052650586819280U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3442698321538580861U;
            aOrbiterE = RotL64((aOrbiterE * 6317525514963824829U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1491052813469258970U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3956599824067616133U;
            aOrbiterI = RotL64((aOrbiterI * 2928600779267623085U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10963841237346073453U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 2303020125591252534U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 9969099842343321981U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 14503856057958162356U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11147548150090597694U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11856382308792700441U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9191681438318311481U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13556072770381999852U;
            aOrbiterG = RotL64((aOrbiterG * 18316231099054203683U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 6U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 46U) + aOrbiterE) + RotL64(aOrbiterD, 19U)) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterF, 10U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 29U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterF, 51U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 40U) + RotL64(aOrbiterG, 24U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterE, 43U)) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterA, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19431U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 20397U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 19846U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17728U)) & S_BLOCK1], 26U) ^ RotL64(aFireLaneD[((aIndex + 18165U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 60U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 4259993311776766595U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aCross, 3U)) + 2857813330021126753U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 39U)) + 1345396841329442896U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 23U)) + 320992148982301024U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 58U)) + 5619109532065293074U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 10380157329426706345U) + aNonceWordO;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 12449831150625409695U) + aNonceWordB;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 11U)) + 7847096607042268396U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 34U)) + 11707184096803214678U) + aNonceWordG;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9893643746186827088U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 333687403830908774U;
            aOrbiterH = RotL64((aOrbiterH * 17911256836121454271U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13837360705077441580U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4367119682175710689U;
            aOrbiterI = RotL64((aOrbiterI * 10295744669174603401U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1193493435041306784U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15062951612027370606U;
            aOrbiterC = RotL64((aOrbiterC * 2509383510565136549U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16000173839235429105U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 15294482444605409961U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 1031800997944302665U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5720749055549773527U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17248674962996093668U;
            aOrbiterJ = RotL64((aOrbiterJ * 15730637462755795591U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16956840483882091059U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9637715107943515594U;
            aOrbiterE = RotL64((aOrbiterE * 8878362378343603463U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7147495779349862274U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7508890985889484275U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17728368447504622035U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4407738164617959366U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17027017782352660454U;
            aOrbiterD = RotL64((aOrbiterD * 417183060881259295U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3174658601748235285U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9779053567370714831U;
            aOrbiterG = RotL64((aOrbiterG * 6383245776181968033U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 30U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 18U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 48U) + aOrbiterD) + RotL64(aOrbiterF, 11U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + aNonceWordN) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 39U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 60U)) + aOrbiterF) + aNonceWordL);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 53U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 22U);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 24181U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((aIndex + 27244U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23353U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22294U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 11U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (aWandererF + RotL64(aIngress, 29U)) + 13333509828310369865U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 60U)) + 7645352517103840797U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererA + RotL64(aScatter, 51U)) + 5310766306660062655U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 5165635069832352932U) + aNonceWordL;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 11U)) + 15684141764734281849U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aWandererH + RotL64(aCross, 37U)) + 3327963374225061738U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 8625811794878848871U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 23U)) + 7598657468430485291U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 6U)) + 2881171216276746485U) + aNonceWordE;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10237691227222918101U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6419254255884834497U;
            aOrbiterD = RotL64((aOrbiterD * 3816625473642865305U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4238455444646479956U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14936613353493061492U;
            aOrbiterH = RotL64((aOrbiterH * 3544216916806292273U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 15324699725208372627U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9506640480601832011U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12819564111348390227U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3709149613660215641U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1724290199312754307U;
            aOrbiterB = RotL64((aOrbiterB * 12597580418257897965U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13191172833570139194U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3686087945377837886U;
            aOrbiterJ = RotL64((aOrbiterJ * 10883609557429936283U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10418330386245397022U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 5383531313632347245U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2987755379396160073U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 7414716553072652212U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11301761123966206201U;
            aOrbiterA = RotL64((aOrbiterA * 1546727321088592187U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8570229732236388847U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8773754460060264773U;
            aOrbiterF = RotL64((aOrbiterF * 3251360788932563495U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13636929800504199371U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5486599841558573720U;
            aOrbiterC = RotL64((aOrbiterC * 2867914211589815153U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 46U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 56U)) + aOrbiterJ) + aNonceWordK);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterG, 39U)) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 29U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 52U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterK, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 52U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 48U) + aOrbiterG) + RotL64(aOrbiterC, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 29689U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30488U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31362U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 31380U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 24U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = (aWandererF + RotL64(aPrevious, 35U)) + 3105313968748067810U;
            aOrbiterK = (aWandererG + RotL64(aCross, 23U)) + 9977249451119627064U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 17941392803495349366U) + aNonceWordG;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 44U)) + 4279533326705471133U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 13983828966811580039U) + aNonceWordA;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 5U)) + 3983490984234810378U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 308786542215259956U) + aNonceWordB;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 27U)) + 8443607695364427037U) + aNonceWordL;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 18U)) + 14939626441464340668U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9350693577306121110U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1717071159396961752U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 11062480662625054525U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 15911765265202100610U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14898546272333182767U;
            aOrbiterK = RotL64((aOrbiterK * 2674900543810733067U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3560903518513465868U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 5367062725726860234U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 8521908836601319553U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15233321480618877327U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9288449812290126074U;
            aOrbiterH = RotL64((aOrbiterH * 6815298520404038519U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5504840529511585676U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6825598386801620046U;
            aOrbiterB = RotL64((aOrbiterB * 11666542445846250077U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6433024450721339470U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 97934156644929458U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8630530773006923215U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3260053604798744515U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16539416623243059076U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 12199577351166064503U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9814290051339038920U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13280156404507444041U;
            aOrbiterJ = RotL64((aOrbiterJ * 15269010043398910061U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11853942590993546833U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13207869904312989977U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15503461937625795969U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 20U) + RotL64(aOrbiterC, 3U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 39U)) + aNonceWordJ);
            aWandererG = aWandererG + ((((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 35U)) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 13U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 58U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + aNonceWordM);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterB, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 24U) + aOrbiterK) + RotL64(aOrbiterJ, 28U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Archery_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA24D85DCDF80EE2DULL + 0xA0EE44DEEB7B56C6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x90B11BE7CC896313ULL + 0xA5305475E5E021C7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8BA4B96B580C49F7ULL + 0xA8AD73002C36B656ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBA30D4348967685BULL + 0x9BA1C137CE11F1F9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD4EF4B9E5003D785ULL + 0xB04DC2541CB859DCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x960382B95697AE91ULL + 0xDF06B3F1F91946AEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAB55E3E6376A26A5ULL + 0xA564A1C30827BF0CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8BE732BBB4117817ULL + 0xA622250939E1352CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAC0134401D84C3E9ULL + 0xFBE3C8F1DF6B3D17ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9C813E3C7141FDCDULL + 0xD909CE88C23CDDC8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xED8FB62C680E1C41ULL + 0x9170312ADEC3EEE8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFE021C7A5E517145ULL + 0x8C8DA7FB349B3DB4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA4DDD7AED0D189BFULL + 0xDAD9D5D3E53B2671ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD5ED8BB0397D3A7FULL + 0xA516D2FA85BB3FDBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x93BAFF1FE1D7EB5BULL + 0x8EC4D76076ED4FCAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDBA3001075D9FC07ULL + 0xE027B7164C2BB0BBULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5170U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((aIndex + 6709U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5438U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4135U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2764U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7344U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (aWandererK + RotL64(aPrevious, 26U)) + 2558105147674438050U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 15856662514774702561U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 13346869226246584582U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 7632111846116243973U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 53U)) + 2102101361626976279U) + aNonceWordO;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5605968705067851563U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6842483186584326681U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 11344798544990575365U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5559797213819425064U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12422313931331576759U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 7399849122565913401U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2751024420047872601U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 11031320239359798610U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 8607639453141148025U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14366375309473793217U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11971479429768505316U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 10063001532313098203U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3947595951884469542U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17882767922372770896U;
            aOrbiterC = RotL64((aOrbiterC * 3361906348965810211U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 21U) + RotL64(aOrbiterG, 40U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            aWandererK = aWandererK + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aNonceWordH) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterB, 5U)) + aOrbiterC) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10294U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 13313U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 11060U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11529U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12579U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12732U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15027U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCross, 29U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (aWandererB + RotL64(aScatter, 30U)) + 5295352595333316211U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 2341795367042042605U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 10122175780504033663U) + aNonceWordB;
            aOrbiterC = ((((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 10084612804696198554U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 3U)) + 16470424309851045971U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 656016130975227994U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15313268829659834317U;
            aOrbiterE = RotL64((aOrbiterE * 3553315008401417123U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3795220914993923394U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 14044442220988813825U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 3270650852546606835U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3804224626734584802U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7980006306010255693U;
            aOrbiterF = RotL64((aOrbiterF * 13958505239726088561U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13746830564584711549U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11852212099729274845U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2164880979318247855U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9083223471018084847U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13706723820703853346U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11361854103656219887U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 37U)) + aOrbiterK) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 12U) + RotL64(aOrbiterE, 60U)) + aOrbiterF) + aNonceWordP) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererK, 28U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23549U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((aIndex + 20711U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 20789U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 22346U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23540U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19862U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 21848U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 20U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = ((aWandererI + RotL64(aCross, 21U)) + 5131645209694953015U) + aNonceWordK;
            aOrbiterK = ((((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 12070391048835379854U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 57U)) + 2604295836242338724U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 46U)) + RotL64(aCarry, 37U)) + 14042039029284001596U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 8914654543854559327U) + aNonceWordJ;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2185619407969359869U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5187406295103352574U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10497064008152537837U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8022832481290871217U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 8783061916740573472U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 3309891377744201773U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10711028365596196301U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13387065038269133571U;
            aOrbiterJ = RotL64((aOrbiterJ * 12444578026365205255U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11187001318931801582U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14191473173276034019U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 2491253922434756431U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16207761776716426435U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9677408414452078760U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5487303383095129949U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterK, 54U));
            aWandererB = aWandererB + ((((RotL64(aCross, 27U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 11U)) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30379U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 28411U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 26332U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32107U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27005U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32244U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 29300U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 56U)) + RotL64(aCarry, 5U)) + 15910560457440369082U) + aNonceWordH;
            aOrbiterH = ((aWandererA + RotL64(aCross, 21U)) + 17953072986407436888U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 15446940721193538669U) + aNonceWordK;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 3020785262774422009U) + aNonceWordL;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 11U)) + 7001288645424994404U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13385250665458462689U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4841895644623005949U;
            aOrbiterJ = RotL64((aOrbiterJ * 3898487345974386945U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13053476783239482065U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 641996979335975244U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3697673197256549833U), 43U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 16211238020928688299U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12715448751323279480U;
            aOrbiterF = RotL64((aOrbiterF * 2116880429675303291U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 17784406727699995290U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16626339815786580778U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13940754474750138041U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9035070625716345139U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6085848172494001945U;
            aOrbiterH = RotL64((aOrbiterH * 10405728912339646693U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 36U)) + RotL64(aCarry, 57U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aCross, 4U) + aOrbiterC) + RotL64(aOrbiterF, 3U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 27U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Archery_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDBBD93120A0B4E3FULL + 0xC2C2371D12AE5ED1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE7F3E20CB2DFAB33ULL + 0xB50D533811680CDBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB1F6285A0433380FULL + 0xEF62AB55A3F4AB8EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCFC17C2A14535277ULL + 0xB13298F4A839F834ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB0730B3AE16DB659ULL + 0x9F02B98F03CA2683ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB2B297153007FC2DULL + 0x9BBD6D68AEC2D893ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAE61F945A0E84A97ULL + 0xF691A7961C356E6EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF0A5F170CD45411DULL + 0x9F0D3C6D9817DA58ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9CDF2A8D1DA067F7ULL + 0xCF169A1D84126276ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD83AF76F8DBB75FDULL + 0xE57623AD46CC86F3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD7B11284CAC39BA7ULL + 0xABFE831BB313561AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8E1D0BF57A759BC7ULL + 0xBA717E1C0736B9FDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCC4A96077A114863ULL + 0x8EC32778DA1DA859ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFB4588890EFED143ULL + 0x97DB0C65DF46E499ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBCBFDCE79224D05DULL + 0xEDF6E86B2BF92228ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8559CC1E08B06113ULL + 0x810D82CF7AA6E395ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 55U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 4032U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 705U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 577U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3556U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2694U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 39U)) ^ (RotL64(aCross, 4U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 12122689833405846292U) + aNonceWordK;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 9640400270962766788U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 9141937998266739071U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aIngress, 51U)) + 12899395770434090537U) + aNonceWordI;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 41U)) + 13457918115408031842U) + aNonceWordH;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 3U)) + 15134784483576000943U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 12U)) + 12540961268790055438U) + aNonceWordP;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6306886773092764230U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13573343491337243121U;
            aOrbiterE = RotL64((aOrbiterE * 15893457012357368707U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8545588657348974413U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10891410570357275120U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 5399310978367842841U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2877137119767060151U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 9178097682386595144U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 3524486002084427513U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15528007881855616978U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 11368419529245281435U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 12433207037378339309U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5932738914934356645U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5551842263864055419U;
            aOrbiterJ = RotL64((aOrbiterJ * 16093776759971522681U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 3824433359595690603U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17184628855571662441U;
            aOrbiterD = RotL64((aOrbiterD * 691208053136187317U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8724462245014132623U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7481349499528092352U;
            aOrbiterF = RotL64((aOrbiterF * 8212182934509617583U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterH, 21U));
            aWandererG = aWandererG + (((((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 43U)) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 34U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterD) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 26U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 38U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14257U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 10495U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9702U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneC[((aIndex + 11131U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9621U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12313U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 16345U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 14157904117287696136U) + aNonceWordM;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 52U)) + 7369512677371640676U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 3U)) + 8411250745902073798U) + aNonceWordG;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 43U)) + 5002041814539710275U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 29U)) + 9538041410816283124U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 5210700103927513061U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 7600709399101287982U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 2366369466696580499U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5544575244203019109U;
            aOrbiterD = RotL64((aOrbiterD * 16231219246786333057U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 8710073749110329779U) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15998211310115361630U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15275657696897688955U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15354357553877376422U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 10657523549259276169U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13695239532898311073U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10405750198355464768U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3465819693133515142U;
            aOrbiterE = RotL64((aOrbiterE * 14678343718277562799U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16724189641701408630U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3484340153620198872U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17247547677520703125U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7420442404884871126U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11138445997256757636U;
            aOrbiterI = RotL64((aOrbiterI * 11167543379937571127U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1428191560884663125U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16950093140800653985U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4423012306984814805U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 5U)) + aOrbiterI) + aNonceWordL);
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterF, 53U)) + aNonceWordN);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 20U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterK, 27U)) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 28U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21199U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 23020U)) & S_BLOCK1], 28U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 21075U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21737U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18326U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18719U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17551U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 34U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (aWandererA + RotL64(aPrevious, 29U)) + 12046647397183218524U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 2760779375026461991U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 22U)) + RotL64(aCarry, 47U)) + 13735454443176855650U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 4370377000586647724U) + aNonceWordH;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 35U)) + 14566322384189969094U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 51U)) + 5056565959818422786U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aWandererF + RotL64(aCross, 3U)) + 8795403810686579209U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9625947666256011567U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1703669290934254701U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5763881345676123583U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6664070663184147951U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2104148316797553431U;
            aOrbiterD = RotL64((aOrbiterD * 12887842067180975983U), 53U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 1197910004222596145U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 9922977170060903197U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13047828062605568603U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2048376210852567829U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12568990647075931409U;
            aOrbiterE = RotL64((aOrbiterE * 9860242601194210927U), 43U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 15026894775772902751U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3439447160137900629U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 1813754963043785165U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6532671388552829796U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17261098369835997661U;
            aOrbiterJ = RotL64((aOrbiterJ * 568292591215203521U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3171300991007459947U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5935563269327662024U;
            aOrbiterB = RotL64((aOrbiterB * 11271790283157765003U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 14U)) + aOrbiterJ) + aNonceWordJ);
            aWandererI = aWandererI + ((((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterD, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aScatter, 30U) + aOrbiterH) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28882U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 26681U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 31119U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28097U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31776U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26791U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 30910U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 35U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 10812151398716051703U) + aNonceWordA;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 37U)) + 18202551453336003710U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 43U)) + 9434410809101973752U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 50U)) + RotL64(aCarry, 35U)) + 12955829998028534045U) + aNonceWordI;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 13U)) + 12271740641929640181U) + aNonceWordK;
            aOrbiterD = ((aWandererG + RotL64(aCross, 29U)) + 14009351527014534752U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 4316296955679133450U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16473324966997442872U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15735123324965019802U;
            aOrbiterF = RotL64((aOrbiterF * 5624078184997601019U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 17656375090484080236U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16066325053456055298U;
            aOrbiterD = RotL64((aOrbiterD * 17912970706985130327U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 12908968778503516903U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12761433987676836197U;
            aOrbiterB = RotL64((aOrbiterB * 1023329467480907925U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12737513138040664509U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 14535795767570998392U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 15560519667062222269U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14370908061811284364U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7001358781208669795U;
            aOrbiterC = RotL64((aOrbiterC * 11641248025734015835U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7298578161120090849U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 10498302152357484629U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 13144110412179037175U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11447343228638006767U) + aNonceWordG;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 18284143620422655675U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 572862190073605651U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 43U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterI) + aNonceWordJ);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 44U) + aOrbiterC) + RotL64(aOrbiterI, 4U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 21U)) + aOrbiterH) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 13U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Archery_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD0CB7B4FD93F4135ULL + 0xDBF39243A1CB4648ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD7E46369D9162D93ULL + 0xB319236FCA0B9040ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE0E1414EDDA97D0FULL + 0xF96C46CEE7B19478ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE676E7A0709E7D0FULL + 0x95C47F67CCE16AB3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBB0741B92AD77D31ULL + 0x83B1DBE8F339CE03ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE6CCE1CF3E8B2FF1ULL + 0xD3BA969060902535ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBD3E3E44C75ABE97ULL + 0xB2F1DAC8ADA6A1A5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x83081D5D413AF73BULL + 0x851D5679E4072124ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCBDA3487C450AF97ULL + 0xE51B44EA70EBE90BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC45E4BFC728E3957ULL + 0xC29655D28759FA20ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8F689D7DB670320FULL + 0xF7233F568BE7C963ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD9431B2428A7C685ULL + 0xA27E3B529DCDAB79ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD0BB350AA9FE101FULL + 0xFD01DE1BED0940D0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCD702DD2C2388781ULL + 0xD34EDCBCD875EB87ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8B4CB645633547E5ULL + 0xAD6CF08B63EF4DFFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFD45DE56C10F0F6DULL + 0xF6CB4BD6CF69B06BULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2724U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 3108U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4867U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3257U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5334U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 50U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 21U)) + 11698283336767769359U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = ((aWandererH + RotL64(aCross, 53U)) + 13297826354831483872U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 37U)) + 15254999058287530795U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 17474166585085346567U) + aNonceWordB;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 4U)) + RotL64(aCarry, 57U)) + 15684783498452840289U) + aNonceWordL;
            aOrbiterK = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 5061229733465216486U) + aNonceWordK;
            aOrbiterA = (aWandererA + RotL64(aIngress, 27U)) + 15370981279168377944U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17966672773619554092U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 14685092893994491068U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 1627758964162892429U), 27U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 12798804186209406389U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2848444181474221574U;
            aOrbiterD = RotL64((aOrbiterD * 13730480364920876877U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8551142075919636146U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8833198159158950723U;
            aOrbiterA = RotL64((aOrbiterA * 7650289040764974737U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7351473160893666232U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14204899612487622222U;
            aOrbiterK = RotL64((aOrbiterK * 6317485031956448029U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7008985178526543258U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 13576796403863120356U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 13745839827679114077U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5769784656937900699U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14075925808204936705U;
            aOrbiterC = RotL64((aOrbiterC * 5844894088757604713U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17818667502858010896U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16016922065572683130U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7525645833898085373U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 35U)) + aNonceWordP) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterD, 41U)) + aOrbiterE) + aNonceWordO);
            aWandererE = aWandererE + (((((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 47U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterG, 28U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 6836U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((aIndex + 9236U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 9367U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9905U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7356U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9632U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 29U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = (aWandererD + RotL64(aScatter, 35U)) + 12535417189990029950U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 37U)) + 6204401443676390273U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aIngress, 19U)) + 869613505613154672U) + aNonceWordD;
            aOrbiterI = ((aWandererG + RotL64(aCross, 3U)) + 15053590879563855802U) + aNonceWordO;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 13338989605204591428U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 41U)) + 18306470022403825392U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 1150696349434090218U) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13549541786420596437U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 14302878430259588461U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 16813606782134305513U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4660437084477165225U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1653628537860912069U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 2624835201155303123U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 5594199757006711631U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11008472193138708891U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13645764762027798301U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3668516817279364310U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 128159531749679984U;
            aOrbiterD = RotL64((aOrbiterD * 4523246859249826987U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6378674346113979108U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11438762460659123362U;
            aOrbiterI = RotL64((aOrbiterI * 2733309638158283953U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10624263004446482910U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12546839706919241411U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11468326687628079347U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8466639576503293921U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 5828694979857951504U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 7835487310289634515U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 58U)) + aOrbiterC) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterG, 41U)) + aNonceWordN);
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterC, 35U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 42U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 15582U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 14826U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14208U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14974U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneA[((aIndex + 15120U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 34U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 35U)) + 13687218104610230596U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 6841550124960692709U) + aNonceWordA;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 11U)) + 17418968668458764131U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 54U)) + 8303537912696948204U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 19U)) + 12376614417285936537U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 14215749063579232654U) + aNonceWordM;
            aOrbiterH = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 4111736931433665347U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 11250375934571631522U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5367367837773331275U;
            aOrbiterC = RotL64((aOrbiterC * 7262723007545807179U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 15514089192382674434U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1475991716685034960U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17720681295551650891U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5531622777788629748U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8363822215908303335U;
            aOrbiterF = RotL64((aOrbiterF * 17850203366840994883U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3741256932685720414U) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11634667238062155772U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 15925089729784547403U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18180546911210417155U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5123234656838556335U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15362857462853398025U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11215734271189250284U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16863747802158398092U;
            aOrbiterH = RotL64((aOrbiterH * 1828035970246160023U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9859050606636646323U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9331300036643654675U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 2502263410556166281U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 29U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterB) + aNonceWordD);
            aWandererA = aWandererA + ((RotL64(aScatter, 4U) + aOrbiterJ) + RotL64(aOrbiterH, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterA, 13U));
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ);
            aWandererF = aWandererF + (((((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 60U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordI) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20747U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 20003U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18427U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21289U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21338U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 56U)) + (RotL64(aPrevious, 13U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = (aWandererA + RotL64(aCross, 11U)) + 4752759164691497960U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 53U)) + 12088872623537639782U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 60U)) + 3734943577379734227U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 35U)) + 8854778183012444234U) + aNonceWordL;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 16948373492893967275U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 7962415690046184385U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 1872682375669714454U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7776801806943853566U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16665439117257230732U;
            aOrbiterJ = RotL64((aOrbiterJ * 6866375628213114965U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 11088186766134265676U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10850237991780969350U;
            aOrbiterK = RotL64((aOrbiterK * 7547414856143095121U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6464817712131305812U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 244557182884209844U;
            aOrbiterG = RotL64((aOrbiterG * 2394270354887582889U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13261563971157415841U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2323811103717827362U;
            aOrbiterD = RotL64((aOrbiterD * 11483723582415081925U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12338803568475493422U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2811342930111104982U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5020981755203607757U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5554497011738996057U) + aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 12712169745460598698U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 1985586486150377769U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17415058661427002973U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 9430421222715343818U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 10321140659099470811U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 42U) + RotL64(aOrbiterK, 21U)) + aOrbiterG) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + aNonceWordO);
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 37U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterD, 60U));
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 11U)) + aOrbiterD) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 26U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 26437U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 23595U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25983U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((aIndex + 23213U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 26U)) + 13053031069776604052U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 19U)) + 1331396630251085122U) + aNonceWordJ;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 43U)) + 15879286043343942393U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 13590365633321406830U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 53U)) + 14569235423040242618U) + aNonceWordK;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 11397370636618371560U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 3455933494593971847U) + aNonceWordH;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1307153376443784593U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10688618762584786871U;
            aOrbiterC = RotL64((aOrbiterC * 9503823896874842411U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 17746248451153600096U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8512568600755410158U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 16648320170768234063U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8950230550112591092U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17790968369472845496U;
            aOrbiterK = RotL64((aOrbiterK * 5104988920132008913U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12583323865381967534U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11243927099685293887U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12867003042486433971U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9690268715525781389U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7466066217365074653U;
            aOrbiterE = RotL64((aOrbiterE * 17565696765505320889U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3673528673209875118U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14079103852360952255U;
            aOrbiterJ = RotL64((aOrbiterJ * 17449228863409999629U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6747836856132250630U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 5027692924422297153U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2492421273167124437U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 54U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 41U)) + aOrbiterC) + aNonceWordG);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterH, 47U)) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterI, 27U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 5U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 21U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32139U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29245U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31165U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30640U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 38U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 13U)) + 3105313968748067810U) + aNonceWordG;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 9977249451119627064U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 41U)) + 17941392803495349366U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 4279533326705471133U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 51U)) + 13983828966811580039U) + aNonceWordP;
            aOrbiterD = ((aWandererK + RotL64(aCross, 35U)) + 3983490984234810378U) + aNonceWordO;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 5U)) + 308786542215259956U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8443607695364427037U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14939626441464340668U;
            aOrbiterK = RotL64((aOrbiterK * 16793255020331774983U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9350693577306121110U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1717071159396961752U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11062480662625054525U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15911765265202100610U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14898546272333182767U;
            aOrbiterD = RotL64((aOrbiterD * 2674900543810733067U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 3560903518513465868U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5367062725726860234U;
            aOrbiterC = RotL64((aOrbiterC * 8521908836601319553U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15233321480618877327U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 9288449812290126074U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 6815298520404038519U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5504840529511585676U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6825598386801620046U;
            aOrbiterJ = RotL64((aOrbiterJ * 11666542445846250077U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6433024450721339470U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 97934156644929458U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8630530773006923215U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 12U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + aNonceWordL);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterH, 37U)) + aNonceWordA);
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 51U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterK, 4U)) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 12U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Archery_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC4B0451793415D2DULL + 0xDCF313961192FA6AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA2D0E20B1CE83B83ULL + 0xD4E9FC57AD2744AFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB7251B8209C77617ULL + 0xFFB9A53F61A78D3BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDF3C297DDE2806F3ULL + 0xA2EE2E62C65C99CFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA4BF0128F48AFCBFULL + 0x8ADAC5DB7BAF874FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB66EE0EEEE865E2DULL + 0x841E34C6B7D02077ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF1BFAA8CF1EBA1FFULL + 0xACD37FE247490032ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF07CEDC2AD8B967BULL + 0xCA2C045B64D02D84ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xED3E12A829CCEB67ULL + 0xDC24D18881B1D4C5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF04711F6D534A6B7ULL + 0x871FF8C2BB0BC340ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9A22C68BA161ED85ULL + 0xBB2519DA3DD3DF08ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDA8D721787FE4941ULL + 0xFAD99A7A7CAA018FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x80C9E70FA0B2AA5FULL + 0xD6CDCD049FE94982ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB376675A525E0A3FULL + 0xC111FF03B29A64EAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF326F1393C5AA6F1ULL + 0xB2C213125DA17161ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFE3BDA75FAC6A497ULL + 0xB87939A6CDD59124ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5069U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 8014U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7996U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5172U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 177U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6440U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 58U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 27U)) + 5576732410244514238U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 39U)) + 2833808925935929629U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 13U)) + 3670188682914544792U) + aNonceWordJ;
            aOrbiterC = (aWandererG + RotL64(aCross, 6U)) + 15759072378887814995U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 13934007231137439994U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 23U)) + 11022225696007690512U) + aNonceWordE;
            aOrbiterD = (aWandererA + RotL64(aCross, 57U)) + 16989177104453635790U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 9256930045263527091U;
            aOrbiterF = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 17788596104417068290U) + aNonceWordG;
            aOrbiterI = (aWandererI + RotL64(aScatter, 42U)) + 17044369456673337625U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 35U)) + 1310908395523250343U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 12067065689034065422U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15130844248737512262U;
            aOrbiterB = RotL64((aOrbiterB * 9409499577465934107U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14532689204495587494U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8198147292120244178U;
            aOrbiterH = RotL64((aOrbiterH * 1418356389507740991U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5485494458627163347U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10830008207150307611U;
            aOrbiterD = RotL64((aOrbiterD * 6526039534042499457U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 17770065502486618029U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6397859353395335459U;
            aOrbiterA = RotL64((aOrbiterA * 14286997752368893825U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5128700697381508319U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7103394110057060499U;
            aOrbiterF = RotL64((aOrbiterF * 5053680689949149633U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 16024401282261796979U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12818445221897253410U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11450004517784155405U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13386978409145916350U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16740821954556699503U;
            aOrbiterC = RotL64((aOrbiterC * 5376430209628515105U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 313978038530994953U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1355733685461795345U;
            aOrbiterK = RotL64((aOrbiterK * 15955927322082619735U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12590581077253956064U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2298195367575496005U;
            aOrbiterI = RotL64((aOrbiterI * 17512801361187006363U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11847450675712272468U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5914296379577670282U;
            aOrbiterJ = RotL64((aOrbiterJ * 14574813500616811367U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16901317262621287065U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5576732410244514238U;
            aOrbiterG = RotL64((aOrbiterG * 4514943876091531567U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 18U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 37U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterK, 51U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterH, 28U)) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterD, 21U));
            aWandererE = aWandererE + ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 57U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 43U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterK, 19U)) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 34U) + RotL64(aOrbiterA, 35U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 40U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16129U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 11332U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 11935U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8915U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11859U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14702U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 15535U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 43U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 23U)) + 9751314027302668907U) + aNonceWordA;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 34U)) + 12175450995523107056U) + aNonceWordH;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 19U)) + 17519694958730119552U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 27U)) + 9093525527925682263U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 3713831321786810138U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 41U)) + 10108355209191835040U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 12956307447311314768U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 13U)) + 1904298513945877359U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 29U)) + 4658049993308574460U) + aNonceWordJ;
            aOrbiterE = (aWandererK + RotL64(aCross, 57U)) + 9826333658248851902U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 46U)) + RotL64(aCarry, 51U)) + 12058666914724365134U) + aNonceWordL;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2516574707110528099U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13335308331049750235U;
            aOrbiterA = RotL64((aOrbiterA * 5880227828760598587U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8230749255538495304U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16536559486797811486U;
            aOrbiterI = RotL64((aOrbiterI * 7097036838156464969U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12387639130570188998U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8459259798142872020U;
            aOrbiterG = RotL64((aOrbiterG * 8001346480955847013U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 16083784052002800300U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1957284290736468379U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 5046501301740813065U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7349538179311335863U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16395170077006105258U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4230485452156662763U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3317652065873784068U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5517155804799120700U;
            aOrbiterB = RotL64((aOrbiterB * 9789270651974719183U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5568525912112200094U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9334250662962319598U;
            aOrbiterE = RotL64((aOrbiterE * 5034887614541768961U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5641394627075994165U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13524971148931512745U;
            aOrbiterF = RotL64((aOrbiterF * 3699457147759854357U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15124425790244392471U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7896294947517723306U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7526632360108129915U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15241686066829586263U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12099799118961857495U;
            aOrbiterJ = RotL64((aOrbiterJ * 10456171163074630861U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17529688916595727188U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9751314027302668907U;
            aOrbiterD = RotL64((aOrbiterD * 521888849578281715U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 22U) + aOrbiterA) + RotL64(aOrbiterB, 51U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterC, 23U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 10U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterD, 29U));
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + aNonceWordO);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA + ((((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 19U)) + aNonceWordB) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterD, 13U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterK, 54U)) + RotL64(aCarry, 37U)) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 57U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 54U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererH, 46U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17130U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 22023U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 19530U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 23185U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17371U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21363U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 16796U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 40U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = ((aWandererG + RotL64(aScatter, 51U)) + 13880995121909552664U) + aNonceWordO;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 37U)) + 14534942818069300546U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 23U)) + 17745973100886007133U;
            aOrbiterE = (aWandererE + RotL64(aCross, 35U)) + 2249805580771946872U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 53U)) + 4460116116396439410U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 48U)) + RotL64(aCarry, 27U)) + 3378683994078106878U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 39U)) + 3992996501048809123U) + aNonceWordP;
            aOrbiterD = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 12057768808864451929U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 19U)) + 4115362079047921130U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aScatter, 10U)) + RotL64(aCarry, 13U)) + 15297384955502206698U) + aNonceWordN;
            aOrbiterK = ((aWandererC + RotL64(aCross, 43U)) + 17623548383481905636U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3559213898000162417U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12311605719074507335U;
            aOrbiterA = RotL64((aOrbiterA * 3982199462062847697U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14807313864347885885U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11222085523291581822U;
            aOrbiterJ = RotL64((aOrbiterJ * 12580941911587215653U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 916681229436292462U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2441350114032314686U;
            aOrbiterD = RotL64((aOrbiterD * 7336079498999018067U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7361470539894653271U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12153585147213579808U;
            aOrbiterB = RotL64((aOrbiterB * 3040327545467672961U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 13566300726101613579U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14875254144748509128U;
            aOrbiterC = RotL64((aOrbiterC * 13699179902908972403U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9268158535644002904U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14144295981814993491U;
            aOrbiterH = RotL64((aOrbiterH * 12739937231684038161U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13861225650900541642U) + aNonceWordI;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 12620513474052058164U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 18141974182442267181U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14163773386433257965U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5725700029399455855U;
            aOrbiterK = RotL64((aOrbiterK * 10446930901088908809U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16644838246877860102U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6611825438224873117U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5336239588054125897U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9408958265247071226U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16980073477599191801U;
            aOrbiterG = RotL64((aOrbiterG * 7985839560318985205U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6513029242607881518U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13880995121909552664U;
            aOrbiterF = RotL64((aOrbiterF * 17463079726765044639U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 23U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 6U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 46U) + RotL64(aOrbiterK, 60U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 11U)) + aOrbiterB) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterC, 39U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterK, 41U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + aNonceWordG);
            aWandererF = aWandererF + ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 37U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 58U)) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 24773U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 24713U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 25394U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 26179U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26045U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25853U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 29382U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 37U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 3U)) + 16462052553719977502U) + aNonceWordL;
            aOrbiterF = (aWandererH + RotL64(aScatter, 11U)) + 12337064059566619581U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 41U)) + 15801005007094515447U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 58U)) + 8228706742665081656U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 19U)) + 11006723027845190869U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 18173765337829177450U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 530215083653542558U) + aNonceWordC;
            aOrbiterB = (aWandererG + RotL64(aCross, 13U)) + 6608611827035564511U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 27U)) + 2246051826221626809U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 29U)) + 5228575308895381421U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 52U)) + RotL64(aCarry, 29U)) + 10999213210689606857U) + aNonceWordJ;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3773371037240485696U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8887985779436152504U;
            aOrbiterE = RotL64((aOrbiterE * 698713082830739677U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11150566414723818350U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8336366151003049546U;
            aOrbiterC = RotL64((aOrbiterC * 9033771197242493699U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13233968794237090787U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8172558473508478819U;
            aOrbiterK = RotL64((aOrbiterK * 17837070423649268435U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 133564480283347997U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15104810248883567064U;
            aOrbiterG = RotL64((aOrbiterG * 706802420642303533U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9138629520201127075U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 13993086066341664080U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 4875046427147105077U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6547273508580516932U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9838727018769865759U;
            aOrbiterJ = RotL64((aOrbiterJ * 11395273371936839815U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11685694999526122626U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8945983172566303116U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 17791527981004597623U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17606249889617356327U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9296903152000480008U;
            aOrbiterD = RotL64((aOrbiterD * 18066622289408024413U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14248192861977167583U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5467843420970464193U;
            aOrbiterI = RotL64((aOrbiterI * 10121398470914323221U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17072313558131700643U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7932446176598954438U;
            aOrbiterF = RotL64((aOrbiterF * 11684711939539349335U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15377107166135929052U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16462052553719977502U;
            aOrbiterH = RotL64((aOrbiterH * 9057188521274832217U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 20U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 51U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 21U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterI, 53U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterE, 34U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 41U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 3U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 44U) + aOrbiterF) + RotL64(aOrbiterG, 24U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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

void TwistExpander_Archery_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBCDF2416089E9FEDULL + 0xE7AE97A651206B5CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBD5E8768CFBED07BULL + 0xF4E3D1FA1F276111ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF59E155B6B65A8D5ULL + 0xB78FFF4032397412ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCBD3051D1EF1D14DULL + 0xD997F00315B29E68ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBF0F86938010550BULL + 0x9F44CA0AF687F4CAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB42CF93FB9201311ULL + 0x8BAA700A4212471DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEE661DB0860AFB39ULL + 0xB98BCDCC98527434ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x814ACDF7BE14B6B3ULL + 0x87164C987826B625ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCD96F4D2C5C2F61DULL + 0x9F02ACE71623590FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE9380E0C210FC633ULL + 0xE7B44258D49F87DBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE399FC9F9005FA0BULL + 0xC6EE271FF102FDACULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x930262919679DEC9ULL + 0xBEE0EC6617EF2DE8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC9E76AD85978D29DULL + 0xD2BCC6D4693402F7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF299E2EEDAB4F163ULL + 0xD2A1EB0A9F678517ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC5350B5984F19E65ULL + 0xCE2DCE21D09A2154ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA154404524E43B49ULL + 0xD013E2AAF91B23B2ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6108U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 3665U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3960U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3072U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3983U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2895U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = (aWandererC + RotL64(aIngress, 53U)) + 12206125048349568300U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 5843520589343188818U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 28U)) + RotL64(aCarry, 3U)) + 12195046124287121687U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 43U)) + 16769779119214020640U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 47U)) + 5257603646260695833U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aIngress, 39U)) + 8523523946234886745U) + aNonceWordL;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 11U)) + 7316024684200084096U) + aNonceWordP;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 58U)) + RotL64(aCarry, 37U)) + 11996978575084115207U) + aNonceWordK;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 5U)) + 15491711479085513628U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6036648530996821484U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 926323222234121863U;
            aOrbiterC = RotL64((aOrbiterC * 6639661141258803779U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2700323841295743492U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 5852273765810284935U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 16665696735016345215U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11697397483133538067U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17777142964957007194U;
            aOrbiterG = RotL64((aOrbiterG * 6338967222543284999U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10892176201151170298U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11759700374509499684U;
            aOrbiterA = RotL64((aOrbiterA * 14247697264744736081U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11343756773329590643U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15785048929757652350U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 17208103574389502597U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7508839228498497238U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 13088508510402094665U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15730279447009669103U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16259236641717377699U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11228995722951003980U;
            aOrbiterH = RotL64((aOrbiterH * 4870092259515181323U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13775851561528617086U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3023564646900497080U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9936548213275464131U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 154952467284609583U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14239675888632174461U;
            aOrbiterJ = RotL64((aOrbiterJ * 1370550680736926425U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 60U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterI, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterG, 30U)) + RotL64(aCarry, 37U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterE, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterF, 23U));
            aWandererH = aWandererH + ((((RotL64(aCross, 53U) + RotL64(aOrbiterA, 47U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterI, 37U)) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aCross, 34U) + aOrbiterG) + RotL64(aOrbiterC, 10U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8194U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 16125U)) & S_BLOCK1], 14U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8752U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((aIndex + 8726U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13428U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8759U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11513U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = (((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 13333509828310369865U) + aNonceWordL;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 7645352517103840797U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 5U)) + 5310766306660062655U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 57U)) + 5165635069832352932U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aIngress, 52U)) + RotL64(aCarry, 37U)) + 15684141764734281849U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 37U)) + 3327963374225061738U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 47U)) + 8625811794878848871U;
            aOrbiterD = (aWandererC + RotL64(aCross, 27U)) + 7598657468430485291U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 22U)) + 2881171216276746485U) + aNonceWordO;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10237691227222918101U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6419254255884834497U;
            aOrbiterJ = RotL64((aOrbiterJ * 3816625473642865305U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4238455444646479956U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14936613353493061492U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 3544216916806292273U), 29U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 15324699725208372627U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9506640480601832011U;
            aOrbiterE = RotL64((aOrbiterE * 12819564111348390227U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3709149613660215641U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1724290199312754307U;
            aOrbiterB = RotL64((aOrbiterB * 12597580418257897965U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13191172833570139194U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3686087945377837886U;
            aOrbiterI = RotL64((aOrbiterI * 10883609557429936283U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10418330386245397022U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5383531313632347245U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2987755379396160073U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7414716553072652212U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11301761123966206201U;
            aOrbiterG = RotL64((aOrbiterG * 1546727321088592187U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8570229732236388847U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8773754460060264773U;
            aOrbiterK = RotL64((aOrbiterK * 3251360788932563495U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13636929800504199371U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5486599841558573720U;
            aOrbiterD = RotL64((aOrbiterD * 2867914211589815153U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 44U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 10U)) + aOrbiterG) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterD, 42U)) + aNonceWordB);
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 37U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22582U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 16873U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 16607U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20632U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17061U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21863U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20076U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 51U) + RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = (aWandererC + RotL64(aScatter, 26U)) + 4848316479321533394U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 6919360256662636195U) + aNonceWordA;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 19U)) + 9897013582181108544U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 47U)) + 7319353809896158678U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 43U)) + 2848175435514849859U) + aNonceWordF;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 3U)) + 6967780718720437934U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 10143884766603388136U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 30U)) + RotL64(aCarry, 57U)) + 8675965006150972051U) + aNonceWordD;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 51U)) + 16350117755560994281U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 17976597517118423760U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1399631141355370237U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16537788276543236833U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3590613762034716792U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5134624314245932157U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13077589037975283371U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10082236952942943654U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4015535035905433450U;
            aOrbiterD = RotL64((aOrbiterD * 4961808568701908559U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 611474103801573800U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5786708483794098001U;
            aOrbiterB = RotL64((aOrbiterB * 7694007039340089267U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5201943497363274455U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9282160506938328489U;
            aOrbiterK = RotL64((aOrbiterK * 5368182164239021367U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4932320527498940158U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11576526341731392916U;
            aOrbiterF = RotL64((aOrbiterF * 1712051774729439363U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10790691517638887125U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16280649213607464422U;
            aOrbiterJ = RotL64((aOrbiterJ * 10756733801499471873U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9553716940667712810U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11827518270964003341U;
            aOrbiterA = RotL64((aOrbiterA * 1322489827908132831U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 16777463701235809321U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3375489084588454149U;
            aOrbiterH = RotL64((aOrbiterH * 3335010977457647307U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 56U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterA, 46U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 52U) + aOrbiterD) + RotL64(aOrbiterG, 23U)) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + aNonceWordJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 53U)) + aOrbiterF) + aNonceWordM) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterF, 27U));
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 10U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aCross, 48U) + aOrbiterG) + RotL64(aOrbiterB, 37U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32741U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 32205U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 26396U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27023U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24625U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26770U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31795U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 4U)) ^ (RotL64(aCross, 29U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = (aWandererD + RotL64(aScatter, 48U)) + 12669015908335980355U;
            aOrbiterB = (aWandererH + RotL64(aCross, 53U)) + 5438715179868613192U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 19U)) + 13172104448184536460U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 27U)) + 13421421503244744803U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 57U)) + 13327113302994856582U) + aNonceWordO;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 4671768205922454413U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 5355759962838579929U) + aNonceWordM;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 10U)) + RotL64(aCarry, 13U)) + 6691720614265406851U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aPrevious, 35U)) + 7063906424700911378U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17328616394166672263U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1542940602574207068U;
            aOrbiterC = RotL64((aOrbiterC * 8981679306319627975U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7203866278803132454U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 993485696233139264U;
            aOrbiterA = RotL64((aOrbiterA * 11609009908810366447U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15659679028507488331U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 18321361454094675842U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3966860765622641843U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9633319822696783352U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3496559332232402963U;
            aOrbiterH = RotL64((aOrbiterH * 7772060229838162977U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1918349708324205526U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 7701088402761359134U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 9649485438465644795U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6006824348814439686U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 18088375375347012557U;
            aOrbiterG = RotL64((aOrbiterG * 12801082943086128385U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 12816533373478543584U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17951880253818836433U;
            aOrbiterK = RotL64((aOrbiterK * 8935839101517220201U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11311632024372748238U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9891349164779752351U;
            aOrbiterF = RotL64((aOrbiterF * 11405973752233193209U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 711130292000437038U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17818800917771709681U;
            aOrbiterB = RotL64((aOrbiterB * 10567029732245868263U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 4U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 30U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 53U)) + aOrbiterF) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 24U) + aOrbiterC) + RotL64(aOrbiterJ, 22U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 53U)) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterI, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 38U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Archery_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF48374A77EE58BBBULL + 0xAAC59AF89E06E2E5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDC8284E281BA864FULL + 0xE6BAA85819EC2D6BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8C184D99B41472CFULL + 0xD3A5D046A47CD770ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB891A7B2331B3E9BULL + 0xB4710B97B9D99590ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAAE991644C135FB1ULL + 0xDEA194232E6E53B1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x831DEAFB0C1BBFE7ULL + 0x89B084918DC6733BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC7207357FF55C189ULL + 0x9918136821B59C34ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDF8C300590A4942DULL + 0x87E7992C1DE3BDC5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBCFFDD2156778C31ULL + 0xA4D34CC17FCC77A5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCB79039E4408E9ABULL + 0xF54BA96B7CB832D2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB2020F620BF9A83FULL + 0xECFB6975BBF8CD37ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF6F7B78B5E91A94DULL + 0xC9F777CC66DCC08CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCAA0E873E3E65ECDULL + 0x9C8FE302D95C4E79ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBEE74B359A98AECBULL + 0xFEDBA471DD657879ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF09BAB81E668ED6FULL + 0x991BE981D29C449DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xECB44F74AE6108B9ULL + 0xEE6920AC96E9C80BULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2770U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 6097U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2843U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6058U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3237U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 14U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 9774364261626083532U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 18059001521926116420U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 53U)) + 10615626210406381148U) + aNonceWordK;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 3U)) + 10536484278007898620U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererK + RotL64(aCross, 60U)) + 13320663045139972700U) + aNonceWordO;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 27U)) + 17127001787268166583U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 16742574590844166551U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8347719720758228053U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 13502468705946051986U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 13822952083584784695U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3512687886188904904U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 495660316165795934U;
            aOrbiterI = RotL64((aOrbiterI * 6724596801190194913U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 5092722552034477356U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15641128019608284015U;
            aOrbiterJ = RotL64((aOrbiterJ * 3621036395703527059U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15421873776811085458U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 17978775513204574125U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 18359600395119440183U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16617179197537669849U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1931805387534012528U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3400139345857733775U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9544923119559308431U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 12930999400470173353U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 16791006919271490005U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13673733276226249890U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 2032263473309124738U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3088728329261360607U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterK, 39U));
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterI, 60U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 21U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 50U) + RotL64(aOrbiterF, 51U)) + aOrbiterH) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + aNonceWordJ) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13205U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 10815U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 11123U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11456U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15977U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15055U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11583U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (aWandererD + RotL64(aScatter, 52U)) + 8402620908307642697U;
            aOrbiterC = (aWandererF + RotL64(aCross, 13U)) + 11347672014525086047U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 5U)) + 2816462912503401876U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 6940159795470696093U) + aNonceWordI;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 41U)) + 9134692490095883851U) + aNonceWordP;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 4999455497008026526U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 5992451460350651332U) + aNonceWordG;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3417087346651371924U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3612773820086198270U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5519856345435871169U), 21U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 463398077083428570U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11249391303705089012U;
            aOrbiterJ = RotL64((aOrbiterJ * 7106735772303292983U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17027535139825739501U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 568131384979596481U;
            aOrbiterI = RotL64((aOrbiterI * 5683451044852895957U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4793712537158004047U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10415170179135963622U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13729564030210361415U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2391473979460065630U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4240058362680064261U;
            aOrbiterA = RotL64((aOrbiterA * 12375884373396400889U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9963957011090031698U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3325305624067445525U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3128542681461806309U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2094945647665114693U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10703615640774042674U;
            aOrbiterK = RotL64((aOrbiterK * 12641986098450423751U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 13U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 6U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 51U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterI, 37U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 27U)) + aOrbiterG) + aNonceWordK);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 52U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23792U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 22135U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 23857U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21720U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24130U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 19654U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20312U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 43U) ^ RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((aWandererH + RotL64(aScatter, 13U)) + 11177787645248006236U) + aNonceWordB;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 3808340254579817169U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 56U)) + RotL64(aCarry, 11U)) + 828030667598518279U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 16177835921238398371U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aScatter, 47U)) + 5518747735458708741U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aWandererA + RotL64(aCross, 29U)) + 17346319082399995165U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 3U)) + 6397156921893030937U) + aNonceWordD;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 15559381654710713582U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 940404446491415088U;
            aOrbiterE = RotL64((aOrbiterE * 16401260971303026881U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8047166032048732645U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 4688468645859470491U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14383536431614496369U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3710878044770337260U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 116343189456629220U;
            aOrbiterC = RotL64((aOrbiterC * 5637725064169289339U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 883908030159391659U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 18058691521694880482U;
            aOrbiterH = RotL64((aOrbiterH * 3132200449123497619U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17521015077103586117U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3668332225435714918U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12658899101297839881U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12229480388278883300U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16206524049491531816U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 11122340196620859805U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 5743265849441077466U) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2812293020719282236U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8903956475200417109U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aCross, 28U) + aOrbiterK) + RotL64(aOrbiterD, 60U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 19U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterI, 5U)) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 53U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 20U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31301U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 24725U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 29442U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32133U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29628U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26222U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30000U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 22U)) + (RotL64(aIngress, 35U) + RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (((aWandererA + RotL64(aScatter, 20U)) + RotL64(aCarry, 35U)) + 77518479758428414U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 53U)) + 4832061802166300011U) + aNonceWordA;
            aOrbiterK = ((aWandererI + RotL64(aCross, 43U)) + 11695291171006574112U) + aNonceWordL;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 11U)) + 7467412817843260094U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 27U)) + 17801484124471154757U) + aNonceWordI;
            aOrbiterG = ((((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 5555455638503958639U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 5669470540733721606U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3042388456327784163U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2236734925228156691U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10076582424701705531U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14459720401528685450U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4814967631216658856U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18288097536171386643U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16950679344449075945U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6262238639302011050U;
            aOrbiterI = RotL64((aOrbiterI * 9942659897425088183U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3522256359074996724U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12524717897707074242U;
            aOrbiterD = RotL64((aOrbiterD * 6787771338063891989U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13891759914865623828U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 11910250571469028666U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 12311343917878428995U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2240189915640314069U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5365912986308810837U;
            aOrbiterB = RotL64((aOrbiterB * 15133972552032469957U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9323732721344489753U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13087326560957916553U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 14659491687401151733U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererD = aWandererD + (((((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 41U)) + aNonceWordB) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK) + aNonceWordG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 14U) + aOrbiterG) + RotL64(aOrbiterD, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 4U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 37U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterK, 47U)) + aNonceWordC) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Archery_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB43F21C1503809CBULL + 0xBD52899CE9B72E0CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x926D4C07E67EBFB5ULL + 0xDA943792577BC741ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE60F85557AC6223BULL + 0xD9CAC18E270E5629ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA6B4BE7E5C12C467ULL + 0xC4302BCD19016A73ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8C30F4BE67150FEFULL + 0xEBA85DC398A06842ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBE7FCEAAD7286EEBULL + 0x82BCF12C4A145DD3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCFE77742BABAF36BULL + 0xFECCD51D5BA8671FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAD81EBB7D6EDA659ULL + 0x8FD1D9DB8044CF41ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE08830B543304C7FULL + 0xAFBA8E3D1001DEFAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x97D307556AAB3499ULL + 0x885CD05937798728ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8E71041F03BFAD15ULL + 0xB88C3CDDC57D9C2AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB4BD1EC485EC693DULL + 0xB093270E68153241ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xEA109E9A48AD7399ULL + 0x815399B5815A499CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBEAA05B8175A1C79ULL + 0xFE312ADE5F745D35ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBCAAE524481254E9ULL + 0x9D1A82286B8F439FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB05D4C65AFED1777ULL + 0xB02E8884DC36DABCULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2079U)) & W_KEY1], 52U) ^ RotL64(aKeyRowReadB[((aIndex + 2043U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1773U)) & W_KEY1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1648U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = (aWandererJ + RotL64(aIngress, 21U)) + 13174219512651137892U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 2715455762789269341U) + aPhaseEOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 1338018183235594313U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 11U)) + 16566866551729552930U) + aNonceWordG;
            aOrbiterI = (aWandererI + RotL64(aCross, 27U)) + 6901845297307236726U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 60U)) + RotL64(aCarry, 39U)) + 2476078302049201718U) + aPhaseEOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 3U)) + 15531109473927052260U) + aNonceWordC;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4087849380858572351U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5167830630098599644U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1982835131228146099U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 7275995452428627217U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14794340370010024117U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 8779497557416568379U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8509217403041662849U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2321522025240806996U;
            aOrbiterK = RotL64((aOrbiterK * 113568101672878697U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5676672952755594051U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2304681269233504384U;
            aOrbiterG = RotL64((aOrbiterG * 15731441084605554497U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8383399721062437300U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13181984036942227666U;
            aOrbiterA = RotL64((aOrbiterA * 1648761328771932069U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13602604532551684210U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 12725687663616352843U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 4684699861686199753U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5831790822416009806U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4535048543735457407U;
            aOrbiterJ = RotL64((aOrbiterJ * 12076777878870257053U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 21U)) + aOrbiterG) + aNonceWordO) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterK, 51U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterI, 13U)) + aOrbiterD) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 57U)) + aOrbiterG) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 28U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4161U)) & S_BLOCK1], 28U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5056U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5325U)) & W_KEY1], 39U) ^ RotL64(mSource[((aIndex + 4908U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 26U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (aWandererB + RotL64(aCross, 57U)) + 12380376990224645149U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 41U)) + 18296928500297384014U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 3U)) + 3550626816361145100U) + aNonceWordH;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 2667792936946706027U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 12020969779370926953U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 50U)) + 737340727886903447U) + aNonceWordF;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 1681797651799760502U) + aPhaseEOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2956186342689489064U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1876852870402977177U;
            aOrbiterG = RotL64((aOrbiterG * 8875540081346621757U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6433205819353555071U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 9065076854974222998U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5459675878087242021U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3254410578766789992U) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 2005081975473815576U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9947701153722014085U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15992999234834560419U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3458344156815120948U;
            aOrbiterH = RotL64((aOrbiterH * 1668460113964608051U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17069783053664877727U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1260234710193913099U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4561226779897414381U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3825186451876061335U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2905344294992827535U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2469896090698580795U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18141402347899180617U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8760129857609925066U;
            aOrbiterB = RotL64((aOrbiterB * 2507999156108123047U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 28U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 47U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 27U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterA, 11U));
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 21U)) + aOrbiterI) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 41U)) + aOrbiterD) + aNonceWordA);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aNonceWordC) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7638U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6130U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8115U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6516U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6971U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 36U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (((aWandererE + RotL64(aScatter, 37U)) + 9751314027302668907U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 12175450995523107056U;
            aOrbiterI = ((((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 17519694958730119552U) + aPhaseEOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 11U)) + 9093525527925682263U) + aNonceWordK;
            aOrbiterH = (aWandererH + RotL64(aCross, 3U)) + 3713831321786810138U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 58U)) + RotL64(aCarry, 51U)) + 10108355209191835040U) + aNonceWordE;
            aOrbiterK = (aWandererF + RotL64(aScatter, 51U)) + 12956307447311314768U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1904298513945877359U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4658049993308574460U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 10482422152074338611U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 9826333658248851902U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12058666914724365134U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 964233873188373939U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2516574707110528099U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 13335308331049750235U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 5880227828760598587U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8230749255538495304U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16536559486797811486U;
            aOrbiterJ = RotL64((aOrbiterJ * 7097036838156464969U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12387639130570188998U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8459259798142872020U;
            aOrbiterK = RotL64((aOrbiterK * 8001346480955847013U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 16083784052002800300U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1957284290736468379U;
            aOrbiterH = RotL64((aOrbiterH * 5046501301740813065U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7349538179311335863U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16395170077006105258U;
            aOrbiterG = RotL64((aOrbiterG * 4230485452156662763U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (RotL64(aOrbiterH, 44U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 20U) + aOrbiterK) + RotL64(aOrbiterI, 18U));
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 57U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + aPhaseEWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + aNonceWordP);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 51U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterI, 51U)) + aOrbiterD) + aNonceWordJ) + aPhaseEWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 10640U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 10855U)) & W_KEY1], 12U));
            aIngress ^= (RotL64(mSource[((aIndex + 9281U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 9855U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8579U)) & W_KEY1], 36U) ^ RotL64(aFireLaneB[((aIndex + 10233U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 60U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 6733949564325516029U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 7304098437143918796U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 51U)) + 3923949518391777800U) + aPhaseFOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 14243591003388927124U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 5U)) + 18329498724605410406U) + aPhaseFOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 19U)) + 13118172167747037249U) + aNonceWordE;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 36U)) + 5272025143849174212U) + aNonceWordD;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16075917179214318424U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15263590648674658399U;
            aOrbiterD = RotL64((aOrbiterD * 9918239923411740337U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13730046728289525921U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7703141464499623408U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 5886009900621521987U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 1382279753822135359U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2973369221699098292U;
            aOrbiterE = RotL64((aOrbiterE * 7440242040663550631U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11578274119583013219U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3419411247737896674U;
            aOrbiterH = RotL64((aOrbiterH * 17814942652262802991U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 2582783513078999303U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3959762790273529677U;
            aOrbiterJ = RotL64((aOrbiterJ * 383974377372162751U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 465795011576934604U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17880826624185821135U;
            aOrbiterF = RotL64((aOrbiterF * 4445949147592860913U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 10819659185349413173U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17298208553586835030U;
            aOrbiterI = RotL64((aOrbiterI * 1965860510614222093U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterI, 29U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 22U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterH, 5U)) + aNonceWordC);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 43U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 37U));
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 20U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 13U)) + aNonceWordM) + aPhaseFWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 48U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 12556U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 13623U)) & W_KEY1], 60U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12349U)) & W_KEY1], 29U) ^ RotL64(mSource[((aIndex + 11208U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11663U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12304U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((aIndex + 11053U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 12131317914288566437U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 40U)) + RotL64(aCarry, 11U)) + 5672805657999385496U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 3581710244233124197U) + aNonceWordN;
            aOrbiterJ = (aWandererH + RotL64(aCross, 29U)) + 15251296040538489436U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 57U)) + 11295008604679904153U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 19U)) + 2230897493419504490U) + aNonceWordP;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 3U)) + 7109600123297458999U) + aPhaseFOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13119156643107683803U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14755160867807355250U;
            aOrbiterH = RotL64((aOrbiterH * 10007087518844899239U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16829363373287496832U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 16981122946707720883U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 5394974422201576627U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8806000776958603317U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16810923047720876014U;
            aOrbiterI = RotL64((aOrbiterI * 17872735050219539145U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8129657889554436328U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8653100378491974463U;
            aOrbiterC = RotL64((aOrbiterC * 11395283153912468661U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17048985838727432415U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 10892675550889823573U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 976298937314081913U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 15960158965421254346U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12290011578634850001U;
            aOrbiterJ = RotL64((aOrbiterJ * 9280475585104357745U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16265047040311479093U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10312956912303656248U;
            aOrbiterA = RotL64((aOrbiterA * 3012584393253845131U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterA, 19U)) + aNonceWordG) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterB, 12U)) + aOrbiterA) + aNonceWordO);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 43U)) + aNonceWordB) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterB, 51U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 57U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererA, 42U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 15742U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneC[((aIndex + 16324U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16128U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14875U)) & W_KEY1], 34U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 16022U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13852U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 14764U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 8101351470141807662U) + aNonceWordF;
            aOrbiterA = ((((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 6965474099521076705U) + aPhaseFOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 6803828268885684784U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 27U)) + 13454235922950972488U) + aNonceWordJ;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 18U)) + 11678091885751244777U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 11U)) + 5307134544628507141U) + aNonceWordC;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 35U)) + 4873703518950429353U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8542156221858586039U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3993726182905296513U;
            aOrbiterI = RotL64((aOrbiterI * 11331376012938127609U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 12113047622035464386U) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1944244448665721151U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 7010050836758762003U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12914188029425467576U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2486762763475327024U;
            aOrbiterA = RotL64((aOrbiterA * 12319769994433811617U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14580191602982245481U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 12093414832400135066U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 12720286833215690663U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13623906997320021065U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9977356009806428696U;
            aOrbiterF = RotL64((aOrbiterF * 2005536391712733499U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3694954095397810851U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11453812627797091638U;
            aOrbiterH = RotL64((aOrbiterH * 13730420725113907161U), 13U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 542311345544726351U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3024285045990499484U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5153745952148205645U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 57U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 6U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17101U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 18841U)) & W_KEY1], 50U));
            aIngress ^= (RotL64(mSource[((aIndex + 17355U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17440U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18273U)) & W_KEY1], 56U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17798U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18513U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 57U)) + 13333509828310369865U) + aNonceWordA;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 7645352517103840797U) + aNonceWordJ;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 39U)) + 5310766306660062655U;
            aOrbiterF = ((((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 5165635069832352932U) + aPhaseGOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 29U)) + 15684141764734281849U) + aNonceWordN;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 5U)) + 3327963374225061738U) + aPhaseGOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 50U)) + RotL64(aCarry, 23U)) + 8625811794878848871U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7598657468430485291U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2881171216276746485U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3331350584102843605U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 10237691227222918101U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6419254255884834497U;
            aOrbiterK = RotL64((aOrbiterK * 3816625473642865305U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 4238455444646479956U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14936613353493061492U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 3544216916806292273U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15324699725208372627U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9506640480601832011U;
            aOrbiterF = RotL64((aOrbiterF * 12819564111348390227U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3709149613660215641U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 1724290199312754307U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 12597580418257897965U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13191172833570139194U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3686087945377837886U;
            aOrbiterC = RotL64((aOrbiterC * 10883609557429936283U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10418330386245397022U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 5383531313632347245U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2987755379396160073U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 30U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + aNonceWordB) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 43U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 21U)) + aOrbiterA) + aNonceWordK) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 3U)) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 30U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterC, 37U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterK, 5U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 19698U)) & S_BLOCK1], 42U) ^ RotL64(mSource[((aIndex + 20247U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19630U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20779U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21723U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19471U)) & W_KEY1], 3U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20748U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((aIndex + 19572U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 54U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = ((aWandererE + RotL64(aScatter, 47U)) + 17264605017518259932U) + aNonceWordG;
            aOrbiterK = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 15209184354580778643U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 54U)) + RotL64(aCarry, 29U)) + 3299527965014731384U) + aNonceWordI;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 13U)) + 16293096431816127821U) + aNonceWordA;
            aOrbiterF = (aWandererC + RotL64(aCross, 19U)) + 11031983436878828337U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 5U)) + 9188018632448236358U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 13420816400363406556U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2485063384097917101U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3089135816938128264U;
            aOrbiterJ = RotL64((aOrbiterJ * 8813152992957361153U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10730544971770435788U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 10431767565618874806U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 4723078464590561545U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14883796491656899074U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13465877783538483706U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14311686051108108503U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13322163435314643713U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3307316600284371955U;
            aOrbiterE = RotL64((aOrbiterE * 12337846092069506365U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4950101626975919939U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2596253994220103666U;
            aOrbiterA = RotL64((aOrbiterA * 7181706961838582889U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17961706029559914243U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10321902557977495175U;
            aOrbiterH = RotL64((aOrbiterH * 16189559888625084711U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 18146616411403012772U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8414050129421955787U;
            aOrbiterK = RotL64((aOrbiterK * 14879448948196182863U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 22U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterK, 60U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + aNonceWordK);
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 57U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterH, 53U));
            aWandererE = aWandererE + (((((RotL64(aCross, 23U) + RotL64(aOrbiterE, 37U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aNonceWordC) + aPhaseGWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 21954U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadA[((aIndex + 24154U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22545U)) & W_KEY1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 22818U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22768U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23379U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23367U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((aIndex + 24493U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 14U) ^ RotL64(aIngress, 43U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 5U)) + 13053031069776604052U) + aNonceWordH;
            aOrbiterE = (aWandererK + RotL64(aCross, 51U)) + 1331396630251085122U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 15879286043343942393U) + aNonceWordJ;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 13590365633321406830U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 14569235423040242618U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 30U)) + 11397370636618371560U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 13U)) + 3455933494593971847U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 1307153376443784593U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10688618762584786871U;
            aOrbiterG = RotL64((aOrbiterG * 9503823896874842411U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17746248451153600096U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8512568600755410158U;
            aOrbiterE = RotL64((aOrbiterE * 16648320170768234063U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8950230550112591092U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17790968369472845496U;
            aOrbiterH = RotL64((aOrbiterH * 5104988920132008913U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12583323865381967534U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 11243927099685293887U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12867003042486433971U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9690268715525781389U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7466066217365074653U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 17565696765505320889U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 3673528673209875118U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14079103852360952255U;
            aOrbiterC = RotL64((aOrbiterC * 17449228863409999629U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6747836856132250630U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5027692924422297153U;
            aOrbiterJ = RotL64((aOrbiterJ * 2492421273167124437U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + aNonceWordK);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 28U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + aNonceWordA);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterH, 54U)) + aNonceWordO) + aPhaseGWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25538U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 26689U)) & W_KEY1], 24U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26684U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 26950U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25156U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25988U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24985U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((aIndex + 26151U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 14U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 12615321415808640429U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 15712784676459931207U) + aNonceWordL;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 35U)) + 11013335427004930046U;
            aOrbiterG = (aWandererB + RotL64(aCross, 3U)) + 8298733856304768806U;
            aOrbiterE = (((aWandererG + RotL64(aIngress, 44U)) + 6207732959150824216U) + aPhaseHOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 27U)) + 9769864876127544038U) + aNonceWordK;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 10782181918651152563U) + aPhaseHOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 5790454015845620939U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15606578025386733803U;
            aOrbiterC = RotL64((aOrbiterC * 7079287329365566355U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 5522352539991175304U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5993355818572869649U;
            aOrbiterK = RotL64((aOrbiterK * 15221467311057431139U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 10864534396947622047U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12090053126235913528U;
            aOrbiterI = RotL64((aOrbiterI * 7250801471645972261U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14191181677234981396U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2258570108233924592U;
            aOrbiterE = RotL64((aOrbiterE * 8307541155393855209U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8448114811381534603U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2702389315763499817U;
            aOrbiterH = RotL64((aOrbiterH * 6710443836432274393U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17202184076718780200U) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 150549910056015002U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 195034681254956335U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4910512055808124967U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4783477997418403079U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 861977492146512865U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 12U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterK, 11U)) + aOrbiterG) + aNonceWordD) + aPhaseHWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterK, 44U)) + aNonceWordH);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 44U) + aOrbiterE) + RotL64(aOrbiterG, 37U)) + aPhaseHWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + aNonceWordJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 48U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29201U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 27631U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28639U)) & W_KEY1], 60U) ^ RotL64(aWorkLaneC[((aIndex + 29824U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27695U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27663U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29844U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((aIndex + 28718U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 27U)) + (RotL64(aCross, 54U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 12122689833405846292U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 39U)) + 9640400270962766788U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 11U)) + 9141937998266739071U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 51U)) + 12899395770434090537U) + aNonceWordE;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 13457918115408031842U) + aNonceWordO;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 58U)) + RotL64(aCarry, 37U)) + 15134784483576000943U;
            aOrbiterD = (aWandererF + RotL64(aCross, 29U)) + 12540961268790055438U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 6306886773092764230U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13573343491337243121U;
            aOrbiterE = RotL64((aOrbiterE * 15893457012357368707U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8545588657348974413U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10891410570357275120U;
            aOrbiterH = RotL64((aOrbiterH * 5399310978367842841U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2877137119767060151U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9178097682386595144U;
            aOrbiterJ = RotL64((aOrbiterJ * 3524486002084427513U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15528007881855616978U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11368419529245281435U;
            aOrbiterD = RotL64((aOrbiterD * 12433207037378339309U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5932738914934356645U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5551842263864055419U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 16093776759971522681U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3824433359595690603U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 17184628855571662441U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 691208053136187317U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 8724462245014132623U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 7481349499528092352U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8212182934509617583U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 50U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 27U)) + aOrbiterE) + aNonceWordI);
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 50U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterD, 35U)) + aNonceWordF);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordP) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 11U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterE, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32082U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31519U)) & W_KEY1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30912U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31060U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32052U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 31511U)) & W_KEY1], 47U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 56U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererK + RotL64(aScatter, 11U)) + 5131645209694953015U) + aNonceWordJ;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 19U)) + 12070391048835379854U) + aNonceWordA;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 2604295836242338724U) + aNonceWordB;
            aOrbiterD = ((aWandererA + RotL64(aCross, 29U)) + 14042039029284001596U) + aPhaseHOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 8914654543854559327U;
            aOrbiterK = (aWandererH + RotL64(aCross, 3U)) + 2185619407969359869U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 54U)) + 5187406295103352574U) + aPhaseHOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8022832481290871217U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8783061916740573472U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 3309891377744201773U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10711028365596196301U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13387065038269133571U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12444578026365205255U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11187001318931801582U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14191473173276034019U;
            aOrbiterK = RotL64((aOrbiterK * 2491253922434756431U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16207761776716426435U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9677408414452078760U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5487303383095129949U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17812460332794370649U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7736423148554132028U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 15588733747232852555U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17293203944059014763U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 13487243633338010243U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9468688858740539095U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15979293016815060755U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17645215484691359547U;
            aOrbiterJ = RotL64((aOrbiterJ * 1449450767288733995U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 46U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterB, 12U)) + RotL64(aCarry, 39U)) + aNonceWordN) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 51U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 38U) + aOrbiterF) + RotL64(aOrbiterD, 3U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + aNonceWordD);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aNonceWordM) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 20U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Archery_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA0C4310194E39DEBULL + 0x9F5EFA25040DCC4FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA60521A2D7EA6105ULL + 0xA9F48C17414AAF76ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCA9C092B3CB6507BULL + 0xC31EA242C6B85E0EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE2B290876C880EEFULL + 0xADC94F6FACCFECACULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x86F8FE9F463F7D59ULL + 0xA17814E58BB02449ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC0A0A914CB357359ULL + 0xA1A5EB43C4EDD12BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8615F90EDF939A85ULL + 0xAFFE1DE92024FE79ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDF22501471D2DD7BULL + 0xBC6C45AEA91C249FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF8BE2BD7F7C490E9ULL + 0x8255589113F78518ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x81B86FBAA1C7307FULL + 0x908E9C23388D31B7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x825C9E187EEB891BULL + 0xAFDE0F3AE83F6300ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC79B8C3790BE6791ULL + 0xFA7ED650D39A2321ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE6EEE7D53F30CC61ULL + 0x831BC426136863F2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAC853D6712048117ULL + 0xE0941EB7380BF440ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF319934CF001CC6FULL + 0xE76BF5F8FB966202ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x80D069709A786491ULL + 0xC8616C5FB428AAD5ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1190U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 766U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4618U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 184U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3736U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2860U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 20U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 53U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 37U)) + 17912271996338180948U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 13259276608841847058U) + aNonceWordE;
            aOrbiterE = ((((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 16225936008657276089U) + aPhaseAOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aWandererA + RotL64(aIngress, 19U)) + 2243058962151834071U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 48U)) + RotL64(aCarry, 11U)) + 10637439274127347861U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 15312219216405992627U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 2393933972129878613U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13147717214387593761U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4327069337247976513U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8307656353434167837U;
            aOrbiterG = RotL64((aOrbiterG * 11386588389133096705U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17299145556933889336U) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14458100581172798164U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16543734663677070509U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6410095654927998067U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 6168964796264687686U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 16218071040190475953U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3667999465041020730U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16021552859323602007U;
            aOrbiterB = RotL64((aOrbiterB * 6427266472526362663U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 18U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterB, 37U)) + aNonceWordD) + aPhaseAWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterI, 12U)) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + aPhaseAWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 51U)) + aOrbiterI) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 38U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 5478U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 10495U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6819U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8174U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8870U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6047U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10131U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 56U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = (aWandererD + RotL64(aCross, 3U)) + 17470880031634374199U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 757565846006937746U) + aNonceWordH;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 9419282475801345674U) + aNonceWordK;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 29U)) + 2014248014107898196U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 58U)) + 15113928519446490441U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 7346126964886259935U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5594123113093162359U;
            aOrbiterJ = RotL64((aOrbiterJ * 18043634828891483403U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5659237263369402005U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11565709683423969703U;
            aOrbiterF = RotL64((aOrbiterF * 16731289017588574671U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16782863743534856287U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13499100900072115907U;
            aOrbiterD = RotL64((aOrbiterD * 5567729598873214433U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11414447651044205242U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 7545993795121430538U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10758488381206257261U), 53U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 11778229237616454988U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2544793391976514665U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 4021060413798523299U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 24U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + aNonceWordC) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 35U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 60U) + RotL64(aOrbiterF, 60U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 21U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 15356U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 11029U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 16382U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13871U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 14916U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 21U)) ^ (RotL64(aCross, 54U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 8685374557928800912U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 13U)) + 3482312691892161229U;
            aOrbiterB = ((((aWandererE + RotL64(aScatter, 58U)) + RotL64(aCarry, 13U)) + 6948130297389161165U) + aPhaseAOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = ((((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 5506385663788942690U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (aWandererB + RotL64(aCross, 37U)) + 17859982009307397161U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9178488809207094043U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1835479501226057169U;
            aOrbiterB = RotL64((aOrbiterB * 5671861318767342087U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5368101733632614939U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9050459666576835422U;
            aOrbiterD = RotL64((aOrbiterD * 10351719549990259551U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9042186993119635078U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17528342580198295025U;
            aOrbiterE = RotL64((aOrbiterE * 14316671546614386775U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 6495418332558436882U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8834495762667327342U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 10783141541937645995U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 4364314196965690905U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6357485231062120459U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 289429584586504995U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 41U)) + aNonceWordC) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterC, 28U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 41U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aCross, 30U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19296U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((aIndex + 21546U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 16663U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16564U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 19136U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = (((aWandererB + RotL64(aCross, 24U)) + RotL64(aCarry, 5U)) + 13442819395490639310U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 8187292523194120936U) + aNonceWordP;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 51U)) + 11469697159823131388U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 13414083692375929653U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 35U)) + 11404010733687907517U) + aNonceWordC;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6783212827186218247U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8561131439340372614U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 7426867125542470683U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6252609642004429113U) + aNonceWordN;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 12804867444200448952U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 3114688959081972615U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2739648749603690781U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14808861217017399752U;
            aOrbiterD = RotL64((aOrbiterD * 373911885694012101U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17588866502571268888U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5882260142735642980U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7688252946143263869U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 15493099088132862949U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 5175647411532429582U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15226544495598541883U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 26U);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aScatter, 20U) + aOrbiterB) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 53U)) + aNonceWordB) + aPhaseAWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterD, 23U));
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterE, 13U)) + aNonceWordM) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 38U)) + aOrbiterC) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26743U)) & S_BLOCK1], 34U) ^ RotL64(aInvestLaneB[((aIndex + 27028U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 25855U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25477U)) & S_BLOCK1], 18U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24818U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 10U) + RotL64(aCarry, 41U)) + (RotL64(aIngress, 29U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 6973892330986118220U) + aPhaseAOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 57U)) + 9886813896272094864U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 10996306582517553173U) + aNonceWordL;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 8490648283899856223U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 46U)) + 105141713530704655U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 3114337422810562588U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 980857684690886131U;
            aOrbiterA = RotL64((aOrbiterA * 17407927633910728721U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6562042345807072665U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 15665371138706353619U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 8086237578564620623U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 18113013571374375028U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17405346422601997299U;
            aOrbiterI = RotL64((aOrbiterI * 11162604605443005253U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5130876096426182506U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1813821672299154629U;
            aOrbiterD = RotL64((aOrbiterD * 15478100342425611875U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15793814882743306728U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13925299440495476399U;
            aOrbiterH = RotL64((aOrbiterH * 12049601510660117401U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 54U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterI) + aNonceWordN) + aPhaseAWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 46U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 11U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + aNonceWordJ) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterH, 14U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32248U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 30491U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31867U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29700U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30319U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 56U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 7632760812370906911U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 10U)) + 6007174525479723089U) + aNonceWordH;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 3362829642521821048U) + aNonceWordK;
            aOrbiterB = (((aWandererC + RotL64(aCross, 43U)) + 18009548556107978286U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 17880909432272697327U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15961567935420752568U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 10136559064656837921U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 14473810261421912849U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17622019364405410277U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6927494824421416306U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2686290883767829973U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 7125170407794874847U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12342273503071032250U;
            aOrbiterB = RotL64((aOrbiterB * 867417849555857179U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14997696377476124836U) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14874498694181230698U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4026127545746010937U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2549397729130885686U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 4217995818662767955U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5525525344485251063U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aCross, 39U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aNonceWordJ) + aPhaseAWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 23U)) + aNonceWordD) + aPhaseAWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 11U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterE, 48U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Archery_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x95978F560DA376A9ULL + 0xCA1CFD72806DCDCBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA7BAF0CFB4CED4DBULL + 0xA37C3CFD32C74E97ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCB64B3E06E2A8C43ULL + 0xC664FF0F2DF424FEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE84FEFF1EC030E37ULL + 0xF978346FB7FB6198ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFE032E8BCC7355ABULL + 0xD8354B359FFE6318ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9ED48862E3DA44FBULL + 0xAED494BB5C019F82ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x837616A8998119D9ULL + 0xED5CB7DAE8A0ACA8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAEF1EFF49418935DULL + 0xDAF2EF3EA64A944AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9D3FBE8E1F7367F1ULL + 0x84D89183E9979A7FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF380011A12CBB21FULL + 0xD0F92CBDC386D94AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBDC846B86A1BD111ULL + 0x952C615859CABAEAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA2EC3FBFA217BA9DULL + 0xCF4C162817FA95BCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAE2276B51D2DEAFDULL + 0xC08EE06B964DE604ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA216C921449278E7ULL + 0xDAF81162D0CF09EBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEA177A888E31669DULL + 0xFC26DBCBF928240BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9FA55CFB8CEF8F4DULL + 0xD6608CE5E14192A1ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 114U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((aIndex + 7833U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2791U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6676U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2774U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 18U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 5U)) + 12426357877879529292U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 43U)) + 12604900366173639176U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 56U)) + RotL64(aCarry, 43U)) + 13511119007338929401U) + aNonceWordD;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 9878720081166788060U) + aNonceWordP;
            aOrbiterB = (aWandererF + RotL64(aCross, 19U)) + 15463195409806395076U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 51U)) + 6407922778852833423U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 47U)) + 7690427254160734016U) + aPhaseBOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 36U)) + 18030974031722143619U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 17983938038322737041U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16605512170117753884U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 681802273302348322U;
            aOrbiterH = RotL64((aOrbiterH * 14608920184802647123U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15550312921312083819U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17824154101711884508U;
            aOrbiterB = RotL64((aOrbiterB * 7358612830654795357U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1939207786756735430U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3132864634777826569U;
            aOrbiterA = RotL64((aOrbiterA * 13606281919426730325U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12822929773923954849U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16576106045887115660U;
            aOrbiterC = RotL64((aOrbiterC * 16370914370769903051U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2398825881649235260U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13700821892926092479U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10830623703416956043U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2439833784883391606U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15870638514107637833U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 3797380922767479287U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 9165457123134229670U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8736642509192659417U;
            aOrbiterJ = RotL64((aOrbiterJ * 16219277537523484065U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9232719746484835693U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7826680628853322541U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 12578050118133526187U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14323652326982518782U) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2254524512851399313U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4119339547645451149U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 12U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterG, 19U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 39U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterI, 56U)) + aNonceWordL) + aPhaseBWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 29U)) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 14U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15896U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 10146U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10282U)) & S_BLOCK1], 42U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8522U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15581U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10410U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12728U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 56U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 10U)) + 14823268998003220191U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 15295237288788213847U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 3U)) + 16434853402001133899U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 43U)) + 7555911304407871631U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 14977248264994834620U;
            aOrbiterD = (aWandererC + RotL64(aCross, 23U)) + 9707764144919392380U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 52U)) + RotL64(aCarry, 39U)) + 1277304385464681529U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 29U)) + 3089786220465849395U) + aPhaseBOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 19U)) + 3700503853358695085U) + aNonceWordC;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3240054112993517371U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16897532076915366859U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4120874717534309035U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18167359289798364307U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8870819278575769863U;
            aOrbiterD = RotL64((aOrbiterD * 9334066154398059075U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15363069206212330251U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14858164441499725158U;
            aOrbiterK = RotL64((aOrbiterK * 14931933411393847915U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 5357144808788707522U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2910681277417754860U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13170868582159347059U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9824408699018165151U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 368370224788793300U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 14358982366258729959U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7095398304588825115U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11418879758164313554U;
            aOrbiterI = RotL64((aOrbiterI * 5983520332639771791U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2171599720681913272U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17593730219647495033U;
            aOrbiterG = RotL64((aOrbiterG * 12926053208918563087U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17755947635188715523U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14565740605227022106U;
            aOrbiterJ = RotL64((aOrbiterJ * 15866418354612945335U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14538017880915584414U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6174566474851449123U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 179569008593475683U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 42U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterJ, 12U)) + aOrbiterD) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterK, 29U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterI, 57U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterC, 53U));
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterG, 46U)) + aNonceWordJ);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + aPhaseBWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23010U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 24265U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 22030U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 21129U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22339U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24488U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18522U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 42U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 5U)) + 7651355040951791298U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 40U)) + RotL64(aCarry, 35U)) + 13988210277931659312U) + aNonceWordK;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 9846849412579537783U) + aNonceWordI;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 12746719939495876158U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 57U)) + 11498066185182895284U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 51U)) + 11101058955193080232U) + aPhaseBOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 28U)) + 15513734459555672046U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 35U)) + 15711108675349394643U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 23U)) + 4771231759949468556U) + aNonceWordF;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11449258010811305256U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 17036938391509986723U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7411466953205347639U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6999245666776654250U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 2106819066263369528U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13005885810757743129U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12716183358903477216U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16752724547046059889U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11475905692393034141U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17623077680983093163U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 6726003022297274986U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 14709385877103232653U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2842410225096524740U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9235178377537910514U;
            aOrbiterF = RotL64((aOrbiterF * 11813751114775673845U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2619888019860844610U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 6295481948199619613U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 15429161806953951205U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9724921158061115570U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4070976180958458679U;
            aOrbiterG = RotL64((aOrbiterG * 6080566609081811453U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5864247978960125554U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7771249710071026757U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 4787660062590737657U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15006900854988166845U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2755659268987119046U;
            aOrbiterB = RotL64((aOrbiterB * 8043939381186802359U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 52U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + aNonceWordL) + aPhaseBWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterI, 42U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterI, 13U));
            aWandererI = aWandererI + ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 3U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + aNonceWordM);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 53U)) + aOrbiterB) + aPhaseBWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterB, 46U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterB, 19U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 60U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27732U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 24754U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 29990U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 30286U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28876U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32567U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 25498U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 24U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 23U)) + 9654059367478508868U) + aNonceWordJ;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 29U)) + 6473006635864677427U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aWandererE + RotL64(aCross, 40U)) + 6944184481315853243U) + aNonceWordO;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 57U)) + 4061496421939102306U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 15791809275719085463U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 14050798802646323055U) + aNonceWordC;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 51U)) + 12072905924741758266U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 47U)) + 17639076509231343896U) + aPhaseBOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 6U)) + RotL64(aCarry, 23U)) + 12195388285571234715U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 4325404419499496529U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5910567888204238382U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 11503787177122206937U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13092940059929942699U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13381962590820308761U;
            aOrbiterK = RotL64((aOrbiterK * 6345904465930943295U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15622862439323440527U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 14027151901132249793U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2273573821630510087U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4584410023907605157U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15763755180625487157U;
            aOrbiterJ = RotL64((aOrbiterJ * 6755736130607297639U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17023059745666559199U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5298529579288492971U;
            aOrbiterI = RotL64((aOrbiterI * 2483562793328357721U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2870152867331654736U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12017191100173748848U;
            aOrbiterG = RotL64((aOrbiterG * 9958191466506480519U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15899529176182436062U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 16482713846343388735U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 719465695044265601U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12943393531812774449U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9881108254540483225U;
            aOrbiterF = RotL64((aOrbiterF * 8011108108007885059U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3532054586199716750U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7142230313294797435U;
            aOrbiterC = RotL64((aOrbiterC * 14154176174768868421U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 50U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 53U)) + aOrbiterH) + aNonceWordI);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterC, 11U)) + aNonceWordA);
            aWandererF = aWandererF + ((((RotL64(aCross, 39U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + aNonceWordF) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 48U) + aOrbiterG) + RotL64(aOrbiterD, 57U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 34U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 18U)) + aOrbiterD) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 20U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Archery_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x93FFF24F5D0BC805ULL + 0xCA3C0B07ED16A282ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF8D3248B78050BD9ULL + 0xAB6503DDE88E907CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB717E210AE5F00F5ULL + 0xA7A79AF04D09CDA3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEB5C11AD0FF4594BULL + 0x920BEDCE2E244DB4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8917CA06B3FC6C01ULL + 0xD5679E028B272CB6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE7AE6A10F9890969ULL + 0xBAC517005F4A19AEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE83C5047F1D37347ULL + 0xC249C3B3BD7EFCAAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x84A1870C0C81C419ULL + 0x89E8D21B4218492FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD41259D467347199ULL + 0x859360FDFD526D5BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xCF9920D9F3B0A7A1ULL + 0x8EF2E7C02A716C32ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8C646975F06BAB71ULL + 0x9093D21D03D5B283ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCB710165D87C3F29ULL + 0xC63D1399A535A755ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9FD6EC5907FB58D9ULL + 0xE032D635873B71F5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAE9578166F9BB957ULL + 0xC6759F2BBD41FC75ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x902DF2443EBFBF3FULL + 0xF223B47D9E0A8AECULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD462425466C7D533ULL + 0xF95B9E5A1EBDA4D6ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2775U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 3249U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1565U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3760U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 372U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4491U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = ((aWandererE + RotL64(aCross, 41U)) + 2672739400294801233U) + aNonceWordP;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 57U)) + 8475624545015101850U) + aPhaseDOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 1252755112289831257U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 7938039507649183387U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 48U)) + RotL64(aCarry, 51U)) + 8167413146948861022U) + aNonceWordG;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 35U)) + 17712313989694374353U) + aNonceWordM;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 13U)) + 7637042279892596975U) + aNonceWordH;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15770412950033467341U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 3951812021898608685U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 6623127125223204737U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 8656983621098246507U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17943342344730687317U;
            aOrbiterF = RotL64((aOrbiterF * 16495519451034883813U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3087677463651608668U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16493240011924342788U;
            aOrbiterG = RotL64((aOrbiterG * 16898479041530771871U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 7750923317452683057U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 2185924841611106546U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 708072658250726381U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14676868738946722416U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6849098251696302393U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 2599806275837778069U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17817755047153606419U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9900465270314068757U;
            aOrbiterE = RotL64((aOrbiterE * 9267925873983176685U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11380000891112113701U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15930503831156546113U;
            aOrbiterJ = RotL64((aOrbiterJ * 14450535035065393845U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterF, 11U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 56U) + aOrbiterC) + RotL64(aOrbiterB, 47U)) + aNonceWordN) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterC, 38U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5462U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 8615U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 5780U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8773U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7241U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8488U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 6819U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = (aWandererI + RotL64(aIngress, 43U)) + 12849591986267890852U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 8232614804696815750U) + aNonceWordL;
            aOrbiterB = (aWandererD + RotL64(aScatter, 3U)) + 12141567259210877281U;
            aOrbiterI = ((((aWandererH + RotL64(aCross, 58U)) + RotL64(aCarry, 23U)) + 2928641981037885644U) + aPhaseDOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 980733350554783938U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 21U)) + 2683985177993350746U) + aPhaseDOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererF + RotL64(aCross, 51U)) + 14532148403815527355U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7736296629433884203U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10428437770166310549U;
            aOrbiterB = RotL64((aOrbiterB * 326634742742373401U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 18327174144859461029U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6810436935194432002U;
            aOrbiterD = RotL64((aOrbiterD * 2715987179577753597U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 12606153309690753435U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17123256945895150555U;
            aOrbiterI = RotL64((aOrbiterI * 13469111258504672565U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9057777759026189541U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 16478485918911194442U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 11054247078884894131U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 18064460487552100483U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11477276762421684083U;
            aOrbiterK = RotL64((aOrbiterK * 3886501230380184395U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 18318375441973295081U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13849305985380030986U;
            aOrbiterG = RotL64((aOrbiterG * 12962140243967824959U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10240409420338313641U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 18360586077779529086U;
            aOrbiterC = RotL64((aOrbiterC * 18196875422391501927U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 50U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 10U) + aOrbiterA) + RotL64(aOrbiterB, 48U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterG, 5U)) + aNonceWordE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 13U)) + aOrbiterB) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterG, 41U)) + aNonceWordG);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 47U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterI, 29U)) + aPhaseDWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterC, 23U)) + aPhaseDWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14260U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 11193U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 11327U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16008U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 14179U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 1364174714924216027U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 13561796874229506613U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 12U)) + 11845572344206238305U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 57U)) + 15762708240326773763U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 39U)) + 1157119665207900473U) + aNonceWordA;
            aOrbiterK = (aWandererF + RotL64(aCross, 19U)) + 6823546624372055260U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 14465564210523945121U) + aNonceWordH;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10667464548080807531U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13445737493224316575U;
            aOrbiterB = RotL64((aOrbiterB * 12137295000900795711U), 11U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 3009837893785957665U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2886920524111083752U;
            aOrbiterK = RotL64((aOrbiterK * 15308180928967762543U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10886177449328249656U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15067759884678100433U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 5724566815989860041U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18307930462682331536U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8791864377579255801U;
            aOrbiterD = RotL64((aOrbiterD * 9265158882471421767U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 805797468642992351U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5743305867058244964U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16263000753351131717U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17102025528234481273U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1841579177327486899U;
            aOrbiterA = RotL64((aOrbiterA * 3841603385577825265U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2189493507896508972U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 18209567010094914374U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3737080408976852351U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 48U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 21U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 54U) + aOrbiterK) + RotL64(aOrbiterD, 35U)) + aNonceWordF);
            aWandererH = aWandererH + ((((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 53U)) + aOrbiterF) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterK, 14U)) + aNonceWordM) + aPhaseDWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + aPhaseDWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 19907U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 19454U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17605U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21629U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18692U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (aWandererE + RotL64(aIngress, 27U)) + 8988572360732005217U;
            aOrbiterK = (aWandererA + RotL64(aCross, 3U)) + 17889613225105985335U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 35U)) + 15563478320513948626U) + aPhaseDOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 19U)) + 3441351228410524816U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 4425592689451435346U) + aNonceWordH;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 12733160231627305928U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aCross, 52U)) + RotL64(aCarry, 5U)) + 3574152157304607854U) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15167631896729808783U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15822667973915417055U;
            aOrbiterH = RotL64((aOrbiterH * 5155661648455308057U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17181685481076577637U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9979204751408873468U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 8244434774754786565U), 37U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 1334240485667164762U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9190066751460137016U;
            aOrbiterE = RotL64((aOrbiterE * 14585141844653660363U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15465215829109246336U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2305208282453624419U;
            aOrbiterB = RotL64((aOrbiterB * 10257861974108363283U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16951510027310993926U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11117938943423526901U;
            aOrbiterA = RotL64((aOrbiterA * 7805486716716924787U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12461379120662979432U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11719697049048823897U;
            aOrbiterI = RotL64((aOrbiterI * 14880996802304818757U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 6843357278142933570U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12727898578324702374U;
            aOrbiterK = RotL64((aOrbiterK * 9786435451654365097U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 44U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterA, 20U)) + RotL64(aCarry, 5U)) + aNonceWordK) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterE, 29U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterE, 41U)) + aPhaseDWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 53U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 47U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 23202U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 26791U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25565U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26418U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 23652U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 5U)) + 17074147006464019918U) + aPhaseDOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 13U)) + 10559516626129419928U) + aNonceWordN;
            aOrbiterA = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 13280363679503946221U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 21U)) + 17657115422132457413U) + aPhaseDOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 37U)) + 13325837013304973008U) + aNonceWordH;
            aOrbiterD = (aWandererI + RotL64(aCross, 58U)) + 3059707750486106037U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 4529045702503050852U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10726578475550904292U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 14832537837996659885U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 808060368961520519U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 220094417441809246U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15343130035105342194U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 7984652435043810845U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16592263353426409884U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15649290906447931918U;
            aOrbiterJ = RotL64((aOrbiterJ * 8405875177836650731U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11437410545843708269U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5859769136073011444U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1065016088086441107U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 15188064100307340341U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4367466521843260049U;
            aOrbiterI = RotL64((aOrbiterI * 15916715854192820923U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8482617283860566845U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2585745804937342972U;
            aOrbiterE = RotL64((aOrbiterE * 8267269625632139809U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 1687641344403425541U) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 13667916445979421400U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8191322670355590027U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 44U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 58U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterI, 29U)) + aNonceWordD) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordO) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 40U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29735U)) & S_BLOCK1], 46U) ^ RotL64(aInvestLaneA[((aIndex + 27491U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30142U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31970U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31062U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 3199575576585871314U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 21U)) + 2533378188975571824U) + aPhaseDOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 41U)) + 6819782112558312658U) + aPhaseDOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 12690060987724798497U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 57U)) + 7088375139715629606U) + aNonceWordA;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 35U)) + 17785618677423695666U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 28U)) + RotL64(aCarry, 51U)) + 1714999280296491277U) + aNonceWordF;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17611338506932491624U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6475727359297421201U;
            aOrbiterB = RotL64((aOrbiterB * 15133348244242438069U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2347744591204119530U) + aNonceWordB;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2739317903351401068U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15435029315209475631U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8663535261373274338U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8205245127823536479U;
            aOrbiterG = RotL64((aOrbiterG * 13857005110466856439U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8916510616749754516U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 3944805940148512932U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 18082271583211389701U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14094751253118853302U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 14094299829196076311U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6370012560657108493U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3940673811518673802U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3015106523254484839U;
            aOrbiterK = RotL64((aOrbiterK * 9655401190755573379U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15404103131982599922U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 1828655763233900875U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 13024358077740310049U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 58U)) + aNonceWordH) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 11U)) + aOrbiterI) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 37U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 47U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 52U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Archery_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB71FE69F75E7239BULL + 0xEB7DC4EF688792E7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDFC9443B71D894E7ULL + 0xD8CEF548E206917CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA01016DAF2E316FDULL + 0x89F4EA4E2FBFF7F3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF3976968C6369F73ULL + 0x9F4B30ADEC5DAD88ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x97EB668DC1025B3DULL + 0xF6A03ADD48C2C418ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDF02CED7B2ADD965ULL + 0xF603AC2790C3891BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x84C0A862DAECADD5ULL + 0xBEB8F37C2BF86E06ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA45A1BFF1AC20CE5ULL + 0xEB73CA3A843D7CECULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE9F3ACD175EFA0ABULL + 0xAF2812A4ED032B43ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD46C7148E9C59CC9ULL + 0x9518CE81E87BCB5FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE893EEE2DA38745DULL + 0xF0D9B1CFD9C3FD97ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8DA9C10FB2BB7F45ULL + 0xA97C356B176FF53BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD640801FE7863B57ULL + 0xFA3D4A0ABFE59E5FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBDA5601103956D4BULL + 0xDE63F3681A20691FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF9E00C0165456377ULL + 0xD95E5F66CBB28472ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF0F6919D1C545491ULL + 0x98D43E566F873EA6ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 1307U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneB[((aIndex + 4562U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 196U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4963U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 5290U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4199U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 57U)) ^ (RotL64(aCarry, 44U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 3U)) + 380024772508948442U) + aNonceWordM;
            aOrbiterH = ((aWandererF + RotL64(aCross, 43U)) + 7649029098162567210U) + aNonceWordO;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 58U)) + 5329304598870421851U) + aNonceWordB;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 12306118665045151326U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 960751560457324256U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 19U)) + 3244070254386191876U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 37U)) + 15733408571609521746U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 22U)) + 17623448932647018544U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 8787759896149035829U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 53U)) + 14741681792348288162U) + aNonceWordH;
            aOrbiterI = ((aWandererD + RotL64(aCross, 27U)) + 8801731213568307302U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9872248187499779222U) + aNonceWordL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15407371518644528235U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 1245102406469471673U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4242060317152943062U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9942784962409917541U;
            aOrbiterJ = RotL64((aOrbiterJ * 888649755587764533U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 7296348796484458631U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15061417216070157797U;
            aOrbiterG = RotL64((aOrbiterG * 10349554676953256231U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3233185810644297433U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9241229457641024287U;
            aOrbiterB = RotL64((aOrbiterB * 2728237515724597517U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8464051359381554575U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3307872165699029375U;
            aOrbiterE = RotL64((aOrbiterE * 4859663401033023433U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5482617843966711997U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4442149210462943872U;
            aOrbiterC = RotL64((aOrbiterC * 8979352218576515647U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10591636597580147381U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14925122230279312217U;
            aOrbiterK = RotL64((aOrbiterK * 15038171961638724013U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9772367878232735350U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15800661165607190092U;
            aOrbiterH = RotL64((aOrbiterH * 10493976952980533589U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1571665862499272194U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3162847040693387901U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2747235335326991399U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4868791925868749848U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13134549226315884613U;
            aOrbiterF = RotL64((aOrbiterF * 3551955270718495869U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7830447320021657240U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 380024772508948442U;
            aOrbiterA = RotL64((aOrbiterA * 5143324968958616357U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (RotL64(aOrbiterA, 26U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 5U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 26U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 23U)) + aPhaseEWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 19U)) + aOrbiterB) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterH, 34U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 3U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 21U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterC, 39U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8310U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((aIndex + 5928U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8598U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((aIndex + 10186U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9313U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6898U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5958U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 34U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 37U)) + 15726877954695761686U) + aNonceWordE;
            aOrbiterH = (aWandererK + RotL64(aScatter, 46U)) + 14187652171881943587U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 53U)) + 8420423151313882782U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 14942322692433259283U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 13U)) + 7272331475919796255U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 5U)) + 154504365041805840U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 17475491222554948786U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 19U)) + 5759181483165339605U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 58U)) + 5993060214499322845U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 10901786237875941844U) + aNonceWordD;
            aOrbiterD = (aWandererH + RotL64(aScatter, 41U)) + 17135786595614068473U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5208202073886811165U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6821452921018900631U;
            aOrbiterF = RotL64((aOrbiterF * 13119330055184115669U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13348064837402206969U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8967943922403445136U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 300168481725373093U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8130283784171430891U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6351113882502502876U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 15960622823993072903U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6894708729226455769U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 12065058511247133944U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 5432601727436935831U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17138279326229372741U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12987698199066890628U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12665716655177320977U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13688833537574196675U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4211971980434000618U;
            aOrbiterI = RotL64((aOrbiterI * 1374411763361518851U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10376917117582537592U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4807742522197923516U;
            aOrbiterD = RotL64((aOrbiterD * 15257251453302090961U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18038296468177121243U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6879666349379745258U;
            aOrbiterB = RotL64((aOrbiterB * 15819475269715810555U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5193656664432659624U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 680899397323387963U;
            aOrbiterE = RotL64((aOrbiterE * 9857476056194621321U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1851929589073547860U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13093101559415170218U;
            aOrbiterJ = RotL64((aOrbiterJ * 13950928576652143737U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13695333301427028607U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 15726877954695761686U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 960063676226172027U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterG, 48U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterK, 51U)) + aOrbiterG) + aNonceWordM);
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterB, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterH) + aNonceWordJ);
            aWandererH = aWandererH + ((((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterF, 37U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 27U));
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 34U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterA, 11U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 53U)) + aOrbiterB) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15677U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 15000U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12027U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13123U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13716U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 43U)) ^ (RotL64(aCross, 57U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = ((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 41U)) + 5697928251815176134U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 27U)) + 337587740689259575U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 53U)) + 4927686903263973950U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 58U)) + 3742409032569801033U;
            aOrbiterB = (aWandererA + RotL64(aCross, 37U)) + 1608092659172197650U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 3U)) + 15848744267145717509U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 15300174177963339253U) + aNonceWordP;
            aOrbiterD = (aWandererE + RotL64(aIngress, 43U)) + 14162868453323648628U;
            aOrbiterA = (aWandererD + RotL64(aCross, 60U)) + 12020167069983729869U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 13U)) + 16259538291658723956U) + aNonceWordG;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 8516686212464112245U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3722184575520553132U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5663609293306386784U;
            aOrbiterG = RotL64((aOrbiterG * 14364218128780764749U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15265344442454471986U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3050323350098829515U;
            aOrbiterC = RotL64((aOrbiterC * 5890624677162388135U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 1093356813820599238U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15167726103772238440U;
            aOrbiterI = RotL64((aOrbiterI * 5719466863561311069U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15170797965325981472U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17826286701992981628U;
            aOrbiterH = RotL64((aOrbiterH * 11186808881726573677U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14710892030473425181U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 397194787697553904U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 14368930300818752833U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1273724124862533034U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13018397560392545616U;
            aOrbiterJ = RotL64((aOrbiterJ * 4644812473262395329U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9638716186445643730U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7255587739807843785U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6055682981584011189U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9272350563697399628U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1040729335295009339U;
            aOrbiterA = RotL64((aOrbiterA * 17825687660830291443U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12128124729613601747U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2285238815562202219U;
            aOrbiterK = RotL64((aOrbiterK * 15398840993074390573U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6339113298619163493U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5911895708485037040U;
            aOrbiterD = RotL64((aOrbiterD * 3271006139923200439U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 7601399508218901328U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5697928251815176134U;
            aOrbiterB = RotL64((aOrbiterB * 8184257916861355735U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 30U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 10U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 21U)) + aOrbiterF) + aPhaseEWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 39U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aCross, 40U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 5U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterG, 3U));
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterB, 18U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterE, 51U));
            aWandererC = aWandererC + ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterK, 43U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterC, 23U)) + aNonceWordE);
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterC, 35U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererE, 12U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17664U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneA[((aIndex + 19607U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16400U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21343U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16800U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 14U)) + (RotL64(aIngress, 41U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (aWandererH + RotL64(aCross, 57U)) + 77518479758428414U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 27U)) + 4832061802166300011U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 23U)) + 11695291171006574112U) + aPhaseEOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aWandererC + RotL64(aIngress, 47U)) + 7467412817843260094U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 30U)) + RotL64(aCarry, 5U)) + 17801484124471154757U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 5555455638503958639U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 37U)) + 5669470540733721606U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 39U)) + 3042388456327784163U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 13U)) + 2236734925228156691U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 19U)) + 14459720401528685450U) + aNonceWordE;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 42U)) + RotL64(aCarry, 57U)) + 4814967631216658856U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16950679344449075945U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6262238639302011050U;
            aOrbiterC = RotL64((aOrbiterC * 9942659897425088183U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3522256359074996724U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12524717897707074242U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 6787771338063891989U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13891759914865623828U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11910250571469028666U;
            aOrbiterB = RotL64((aOrbiterB * 12311343917878428995U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2240189915640314069U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5365912986308810837U;
            aOrbiterF = RotL64((aOrbiterF * 15133972552032469957U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9323732721344489753U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13087326560957916553U;
            aOrbiterG = RotL64((aOrbiterG * 14659491687401151733U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16398238057564892809U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 11517870519285159224U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1501848878469712681U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7758285512254776734U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17475149091906684720U;
            aOrbiterJ = RotL64((aOrbiterJ * 6015816725428299273U), 39U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 2051631493975035243U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11684740065349595315U;
            aOrbiterH = RotL64((aOrbiterH * 10918975496337269197U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10575473798991451167U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8267005776169272822U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13166868678285963961U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6249698995716039231U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13808085811784323978U;
            aOrbiterA = RotL64((aOrbiterA * 3897731011582061983U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2739364646624876985U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 77518479758428414U;
            aOrbiterI = RotL64((aOrbiterI * 6977724811175035551U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 23U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 60U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 51U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 53U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + aNonceWordI);
            aWandererF = aWandererF + ((((RotL64(aCross, 57U) + RotL64(aOrbiterH, 30U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordM);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 43U)) + aOrbiterH) + aNonceWordC) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 4U) + aOrbiterF) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterG, 57U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 6U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24629U)) & S_BLOCK1], 24U) ^ RotL64(aSnowLaneB[((aIndex + 23901U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25392U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22616U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 23680U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aCross, 47U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 19U)) + 13174219512651137892U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 2715455762789269341U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 51U)) + 1338018183235594313U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aIngress, 40U)) + 16566866551729552930U) + aNonceWordL;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 29U)) + 6901845297307236726U) + aPhaseEOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 2476078302049201718U;
            aOrbiterC = (aWandererC + RotL64(aCross, 27U)) + 15531109473927052260U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 11U)) + 4087849380858572351U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 43U)) + 5167830630098599644U) + aNonceWordH;
            aOrbiterG = (aWandererK + RotL64(aIngress, 37U)) + 7275995452428627217U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 13U)) + 14794340370010024117U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8509217403041662849U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2321522025240806996U;
            aOrbiterI = RotL64((aOrbiterI * 113568101672878697U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5676672952755594051U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2304681269233504384U;
            aOrbiterK = RotL64((aOrbiterK * 15731441084605554497U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8383399721062437300U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13181984036942227666U;
            aOrbiterH = RotL64((aOrbiterH * 1648761328771932069U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13602604532551684210U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12725687663616352843U;
            aOrbiterE = RotL64((aOrbiterE * 4684699861686199753U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5831790822416009806U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4535048543735457407U;
            aOrbiterC = RotL64((aOrbiterC * 12076777878870257053U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10617608605149381858U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5244225377862618630U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 15307177251167023999U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 18229989093139888456U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 9728120630096192811U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 16052574428163231023U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1312233443099767304U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8043115602160128619U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9365756845731616963U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4679339316686216023U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 211799535650113758U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 1478368466990144107U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 13307123762743628190U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7093673238704478497U;
            aOrbiterA = RotL64((aOrbiterA * 13273906568866802561U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16396459072175632290U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13174219512651137892U;
            aOrbiterD = RotL64((aOrbiterD * 7581008806810219369U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterH, 36U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterK, 41U));
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + aNonceWordP);
            aWandererG = aWandererG ^ (((RotL64(aCross, 54U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterA, 57U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterE, 23U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 44U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererA, 50U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29312U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 27488U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 31355U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32627U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneB[((aIndex + 28160U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 14U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 701291026547470433U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 20U)) + RotL64(aCarry, 35U)) + 17283292650462111643U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 57U)) + 9969124091931303406U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 889176772718046988U) + aNonceWordD;
            aOrbiterA = (aWandererH + RotL64(aScatter, 39U)) + 6054541844643748084U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 37U)) + 14703226235143028132U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 11U)) + 7977975878522921062U) + aNonceWordK;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 47U)) + 16894322614172266274U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 34U)) + 12160451749345900570U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 29U)) + 10870847008043897470U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aCross, 5U)) + 8159920947172520247U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2440099120969517932U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2428396147731468007U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 9363073341539598441U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2213226274394673479U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 7079731443427765333U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16918930776877030559U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 958896789550478970U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 10788682955708075458U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 913321215613559729U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2003386579317564870U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8419686358774204999U;
            aOrbiterC = RotL64((aOrbiterC * 6547052526438697621U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6989167615157578904U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17636634003643824148U;
            aOrbiterI = RotL64((aOrbiterI * 11038576417283732937U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13824962118933907859U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9543912892587859646U;
            aOrbiterE = RotL64((aOrbiterE * 14736710162285997415U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15729878041027706114U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9542137475454825463U;
            aOrbiterJ = RotL64((aOrbiterJ * 11420547128115090491U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5327302277575009955U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2707383132257428583U;
            aOrbiterG = RotL64((aOrbiterG * 6120763309390182129U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9008601903853562620U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11050463189491777908U;
            aOrbiterF = RotL64((aOrbiterF * 9178386878636430553U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14683684132116778056U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5390271065690907120U;
            aOrbiterK = RotL64((aOrbiterK * 17903005409098232619U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5183407290520277451U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 701291026547470433U;
            aOrbiterH = RotL64((aOrbiterH * 16329261100139524239U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 40U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 57U)) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterK, 51U));
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterF, 48U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 37U)) + aOrbiterG) + aNonceWordE) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterA, 3U));
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 6U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterA, 43U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterA, 27U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterA, 39U)) + aOrbiterG) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Archery_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9E511DAB7EB20AA3ULL + 0x862F0A0A532FEE64ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x93FF5065204437BDULL + 0xE9949F621DA597DDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x829CC70EE38C4F15ULL + 0xC34E1711D3B2E6B1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEE824D868DF84E7FULL + 0xBBC5FC732647CC57ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB0DB5E23C8794DEDULL + 0x80B247A24EEBA9EBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF36BCB388504D763ULL + 0xCF6C874F424B7BCAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA3F52AB6FD7D46A5ULL + 0xC34FA5D9183B3279ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x96459B885E2380EDULL + 0xBD11E0476C8A0546ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8D3269F9E26E37A7ULL + 0xB9B35A8660693970ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF6D90E27ACC80D3FULL + 0x84CA773AE2959831ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA4533FD3CBF5748BULL + 0xD65D47A2A3EE95C7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9C8228732B1093DFULL + 0x97150D869DD487BBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF3394C4190CFF70DULL + 0xAE9BE7EF317EAC8CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE5C866A4EF73AA43ULL + 0xA90EC5699801DFC3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB8469BBA2CB50C27ULL + 0xE29BC46DE289233DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDD5FF15721D50E9FULL + 0x9169CA7C0B2532F3ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4639U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 3752U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4433U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2533U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4940U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 270U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 10404808878585437255U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 48U)) + RotL64(aCarry, 39U)) + 10587858736301591439U;
            aOrbiterB = (aWandererA + RotL64(aCross, 5U)) + 1430530909801644435U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 39U)) + 9090938022430118902U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 19U)) + 12936604311751121235U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 43U)) + 1000583006020232032U;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 11U)) + 12352532088997042232U) + aPhaseFOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 34U)) + RotL64(aCarry, 53U)) + 16723410947058502564U) + aNonceWordN;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 23U)) + 16614089235313154270U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4245553025593349277U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3353146318549477494U;
            aOrbiterB = RotL64((aOrbiterB * 14246377408238318091U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5935727336135635196U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10312187090293319667U;
            aOrbiterI = RotL64((aOrbiterI * 1395964500396711899U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12192843181244744484U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 2542570124502586365U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17222847847573534963U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3315472769469002444U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17512858811783071174U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 9070400454074283765U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16633218007427888082U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2502077714838858460U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 970762420815997725U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14792910273226469214U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15739513291150783151U;
            aOrbiterG = RotL64((aOrbiterG * 11896279674116906915U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2192903544350345992U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 844428341223009295U;
            aOrbiterE = RotL64((aOrbiterE * 4768368713974002539U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2998511458298901402U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7790789639864783373U;
            aOrbiterA = RotL64((aOrbiterA * 9173097618440495497U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4540735375055164995U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13700342877362633034U;
            aOrbiterC = RotL64((aOrbiterC * 14730797752841670505U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 30U);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 53U)) + aNonceWordD) + aPhaseFWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 24U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aCross, 12U) + RotL64(aOrbiterE, 19U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 43U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterK, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + aNonceWordJ);
            aWandererH = aWandererH + ((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 21U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 58U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 56U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6839U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 8284U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6282U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((aIndex + 10622U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10098U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10839U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8076U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 48U) ^ RotL64(aCross, 5U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (((aWandererI + RotL64(aIngress, 39U)) + 4751694786009671052U) + aPhaseFOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aWandererA + RotL64(aCross, 19U)) + 16362725160370844224U) + aNonceWordN;
            aOrbiterI = (aWandererF + RotL64(aScatter, 35U)) + 6360885380915941057U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 5U)) + 5154536007972297036U) + aNonceWordJ;
            aOrbiterH = ((aWandererC + RotL64(aCross, 24U)) + RotL64(aCarry, 47U)) + 9362540581874808253U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 47U)) + 13902493871525612934U;
            aOrbiterG = ((((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 10208452885367546542U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 3117030377279160998U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 58U)) + 17286247690414027870U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3930314320040949141U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7289525252391668404U;
            aOrbiterI = RotL64((aOrbiterI * 15452162299105112187U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3434167955466809185U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17852573095128575663U;
            aOrbiterH = RotL64((aOrbiterH * 1485660158767033425U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6137259687928853253U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 13992510605237574698U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15346263295995333395U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6470556523400123474U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4333255670390099293U;
            aOrbiterB = RotL64((aOrbiterB * 11089933812030082647U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 7700424876430257995U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16920736951239453071U;
            aOrbiterC = RotL64((aOrbiterC * 8920407493132380497U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1635071690430295730U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 9966700845966398620U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17210048121896546867U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9833458070123027075U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1990346556486746432U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 8704943923474148699U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13339523466436517327U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5018264760406215603U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2769197961801783627U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 123427497520755346U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4535841104215792886U;
            aOrbiterG = RotL64((aOrbiterG * 1417676310539177131U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 6U) + aOrbiterC) + RotL64(aOrbiterF, 51U)) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterC, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 34U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterE, 3U));
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 21U)) + aOrbiterD) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 26U) + aOrbiterI) + RotL64(aOrbiterH, 10U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 43U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterC, 27U)) + aNonceWordM) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererA, 26U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11494U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 15409U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 16096U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11795U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14285U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 10U) + RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = ((aWandererH + RotL64(aIngress, 39U)) + 16451272412693907816U) + aNonceWordO;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 5U)) + 10099485419723255462U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 29U)) + 17668900099534923192U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 14U)) + 5497093724143181753U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 53U)) + 10354044773550071706U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 12728258851198019099U) + aPhaseFOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 4144050505314242618U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 14133805325480076530U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 60U)) + 308863673210602899U) + aNonceWordM;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11741180130160569753U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12926863156769180448U;
            aOrbiterE = RotL64((aOrbiterE * 9726030996091054939U), 39U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 211920854786494259U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13234608842479411078U;
            aOrbiterC = RotL64((aOrbiterC * 2556747209733759467U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9164711974854618892U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6667377062281954219U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 2603737166987437649U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4559040002406721850U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1749875480850675109U;
            aOrbiterG = RotL64((aOrbiterG * 15822640067349481089U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9555365165561936366U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 18289733999504213574U;
            aOrbiterK = RotL64((aOrbiterK * 14156217554673229429U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 8727162691639622461U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 291406782452963706U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8413500075082350243U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8294911802626492257U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15853578397277298548U;
            aOrbiterI = RotL64((aOrbiterI * 13256191781365357747U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11535146194939658681U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2177540476748375661U;
            aOrbiterJ = RotL64((aOrbiterJ * 15791341922007841029U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2705306323728084136U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17617871830709148043U;
            aOrbiterH = RotL64((aOrbiterH * 3449981219502809255U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 34U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 14U) + RotL64(aOrbiterK, 10U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 47U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 19U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aScatter, 10U) + aOrbiterC) + RotL64(aOrbiterB, 35U)) + aNonceWordC) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 60U)) + aOrbiterC) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 53U));
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19540U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneA[((aIndex + 21797U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17542U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21684U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17514U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 56U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererA + RotL64(aScatter, 42U)) + 10805654776556844351U) + aPhaseFOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aPrevious, 37U)) + 582794182442795335U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 2858343650974681068U;
            aOrbiterC = (aWandererE + RotL64(aCross, 51U)) + 8189584049022064284U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 46U)) + 1565100751996962893U) + aNonceWordO;
            aOrbiterK = (aWandererD + RotL64(aIngress, 11U)) + 8062028016947611891U;
            aOrbiterG = ((((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 8280504280578451745U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 11326869194491655350U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 23U)) + 1671695656567777163U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2349843105293943452U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13015545152052004254U;
            aOrbiterB = RotL64((aOrbiterB * 1316662811685429983U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16703354404749291869U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8713231044374305801U;
            aOrbiterJ = RotL64((aOrbiterJ * 9242480982197688625U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11118401674497783533U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14857556493734710364U;
            aOrbiterC = RotL64((aOrbiterC * 3452566050389715195U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12953419670951660965U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12666121730825089017U;
            aOrbiterA = RotL64((aOrbiterA * 14049925256934142519U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11075249639473053423U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9374217688244187867U;
            aOrbiterI = RotL64((aOrbiterI * 5261156325627117877U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17608340953291367867U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13159437499327086340U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4882100944453534805U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4304700511322366815U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10172544755256706767U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4013006212154771797U), 5U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 17340067939877432472U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14130447570008179105U;
            aOrbiterK = RotL64((aOrbiterK * 8178075071208718915U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2652532710498072378U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10384945384238518296U;
            aOrbiterD = RotL64((aOrbiterD * 17137694272394304045U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 44U) + RotL64(aOrbiterK, 47U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + aPhaseFWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 12U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 58U) + aOrbiterI) + RotL64(aOrbiterJ, 41U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterA, 34U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterA) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23113U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneB[((aIndex + 25616U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 25765U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26511U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 23100U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 14U)) + 5131645209694953015U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 12070391048835379854U;
            aOrbiterG = (aWandererG + RotL64(aCross, 27U)) + 2604295836242338724U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 21U)) + 14042039029284001596U) + aPhaseFOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 47U)) + 8914654543854559327U) + aNonceWordK;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 2185619407969359869U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 35U)) + 5187406295103352574U) + aNonceWordA;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 37U)) + 8022832481290871217U) + aPhaseFOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aCross, 41U)) + 8783061916740573472U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10711028365596196301U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13387065038269133571U;
            aOrbiterG = RotL64((aOrbiterG * 12444578026365205255U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11187001318931801582U) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 14191473173276034019U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2491253922434756431U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16207761776716426435U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9677408414452078760U;
            aOrbiterB = RotL64((aOrbiterB * 5487303383095129949U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17812460332794370649U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7736423148554132028U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15588733747232852555U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17293203944059014763U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13487243633338010243U;
            aOrbiterE = RotL64((aOrbiterE * 9468688858740539095U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15979293016815060755U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17645215484691359547U;
            aOrbiterK = RotL64((aOrbiterK * 1449450767288733995U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11635961468586927692U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10530136578329059784U;
            aOrbiterA = RotL64((aOrbiterA * 8785021493374398437U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4900370530116992731U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15952900504821599445U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 5413316082800365261U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9938000151832814778U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14170277411106520726U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5058343552974910737U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 22U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 10U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aIngress, 14U) + aOrbiterB) + RotL64(aOrbiterK, 47U)) + aPhaseFWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 51U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 58U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aScatter, 48U) + RotL64(aOrbiterK, 35U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 39U)) + aOrbiterH) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 29U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 51U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31282U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 29440U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 27537U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29759U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 29681U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 60U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 19U)) + 14157904117287696136U) + aPhaseFOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aScatter, 51U)) + 7369512677371640676U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 36U)) + RotL64(aCarry, 5U)) + 8411250745902073798U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 3U)) + 5002041814539710275U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 9538041410816283124U) + aNonceWordG;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 27U)) + 5210700103927513061U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 7600709399101287982U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 14U)) + 2366369466696580499U;
            aOrbiterH = (aWandererG + RotL64(aCross, 43U)) + 5544575244203019109U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8710073749110329779U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15998211310115361630U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15275657696897688955U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15354357553877376422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10657523549259276169U;
            aOrbiterK = RotL64((aOrbiterK * 13695239532898311073U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 10405750198355464768U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3465819693133515142U;
            aOrbiterD = RotL64((aOrbiterD * 14678343718277562799U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16724189641701408630U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3484340153620198872U;
            aOrbiterC = RotL64((aOrbiterC * 17247547677520703125U), 27U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 7420442404884871126U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11138445997256757636U;
            aOrbiterF = RotL64((aOrbiterF * 11167543379937571127U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 1428191560884663125U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16950093140800653985U;
            aOrbiterE = RotL64((aOrbiterE * 4423012306984814805U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17288299075036481960U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13793597915359681028U;
            aOrbiterA = RotL64((aOrbiterA * 9639204979982125757U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5017972942710079726U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12409957957614320964U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10273295741911545745U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12487994181992095174U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1573393166996612118U;
            aOrbiterB = RotL64((aOrbiterB * 13364311829104520751U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 30U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 10U) + RotL64(aOrbiterC, 6U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterF) + aNonceWordE) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterC, 29U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterK, 39U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterE, 43U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 60U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterC, 51U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 5U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Archery_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE93361759843C2F5ULL + 0x90955058A8F08545ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x84D3DF8D7D6167C7ULL + 0xA90E724615E5737CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9456E3CD0B6F081BULL + 0xB392E17858294355ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x98F548B4719771FDULL + 0xD57049C3C7066357ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x87D9AFE4A016D669ULL + 0xF72068CA4654E83BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD01CD2DD96973E2DULL + 0xFD624E9701C75982ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9C181F149BB086E7ULL + 0x81F185D2DCE557FBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD2A2768141BF71D3ULL + 0xA99878725219D0BEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x867FE69B459D65E7ULL + 0xE8509BAB96C75FDBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB428594547AFE461ULL + 0xC0246E4E8C89364DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEDBBA998A109A661ULL + 0xE9B579A7BEC291AFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x882AEFBD82069C19ULL + 0xBB2885A7A48F4FC4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9DF81289E1411003ULL + 0x94CB1A51109C4A46ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCF21B89288E62243ULL + 0xBBC8BC5DB30A04CBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE9EB7A688BF780A3ULL + 0x8722F6539EC87B45ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE8A9BA284B4B4D5FULL + 0xFE0CA69BFE7078E2ULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 1345U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((aIndex + 5378U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3670U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 4588U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 5U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3060U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 38U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 5171470532667965920U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 19U)) + 750549462358682403U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 58U)) + 3325689257577120525U) + aNonceWordH;
            aOrbiterC = ((aWandererE + RotL64(aCross, 41U)) + 18031575461559790826U) + aNonceWordM;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 13874739537012288677U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 27U)) + 4250029868785016865U) + aNonceWordE;
            aOrbiterE = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 8211158803112611161U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1083939790236786027U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 3446525462376962464U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 13603702473750888213U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6973817815000417325U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15230876489676945543U;
            aOrbiterI = RotL64((aOrbiterI * 7737039082964537651U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9359727659738755880U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8775170107816327654U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6910680458261008653U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11958941755525038545U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16966819714283167348U;
            aOrbiterC = RotL64((aOrbiterC * 16363457661846050749U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14556087985619763243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17915047508377045221U;
            aOrbiterE = RotL64((aOrbiterE * 6727635453185130109U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8578745677485367222U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7002181668717618866U;
            aOrbiterH = RotL64((aOrbiterH * 12329703532414955235U), 37U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 3569939503066735457U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2956247934282522184U;
            aOrbiterG = RotL64((aOrbiterG * 9946650822131152531U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 40U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterE, 19U)) + aNonceWordP) + aPhaseHWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 13U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 6U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 12U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aNonceWordG);
            aWandererI = aWandererI + (((((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 53U)) + aNonceWordO) + aPhaseHWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9478U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneC[((aIndex + 9172U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 7646U)) & S_BLOCK1], 48U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9982U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 7881U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 7254U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10407U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 56U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (aWandererJ + RotL64(aScatter, 11U)) + 8604208734152026945U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 51U)) + 1374329953253889829U) + aNonceWordF;
            aOrbiterA = (aWandererC + RotL64(aIngress, 58U)) + 5779278910548228339U;
            aOrbiterH = ((((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 17670451230882805140U) + aPhaseHOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 8193848740764866860U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 15801168428145650104U) + aNonceWordL;
            aOrbiterG = ((aWandererB + RotL64(aCross, 29U)) + 2584718176087499066U) + aPhaseHOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14950366247822737997U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9779293225265670135U;
            aOrbiterA = RotL64((aOrbiterA * 11625969538497982117U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8688968319288372383U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 13665723186950342601U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 292035540396910837U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9395428688359973510U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2152719218018108418U;
            aOrbiterF = RotL64((aOrbiterF * 15271961483518392671U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1350324137411377992U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8729317951386057921U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6008790836417785083U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6317310451893678411U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10175620379041384281U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 14079679617394330781U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 1203082119358827708U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 523869107818193101U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4629501113595689157U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4028324959540432983U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15447631947468213912U;
            aOrbiterH = RotL64((aOrbiterH * 6037306615787729185U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 50U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterG, 13U)) + aNonceWordH);
            aWandererG = aWandererG + ((((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 54U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 44U) + aOrbiterD) + RotL64(aOrbiterA, 35U)) + aNonceWordG) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 23U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15108U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneA[((aIndex + 14285U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16100U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14108U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneC[((aIndex + 16286U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 4U)) + (RotL64(aIngress, 21U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (aWandererH + RotL64(aCross, 53U)) + 4773124477323378268U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 16848723289435796005U) + aPhaseHOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aScatter, 5U)) + 13846642134917107058U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 29U)) + 6472057872482789939U) + aNonceWordK;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 40U)) + 2747019500690707226U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 9003965289739733880U) + aNonceWordG;
            aOrbiterB = (((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 3013390651936257377U) + aNonceWordB;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 3331004709895625067U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15355010435553517129U;
            aOrbiterA = RotL64((aOrbiterA * 8322759117004876831U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7709870658004280052U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13568728443963926564U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 6736090830113688981U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12409548853419307131U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 969183352023661537U;
            aOrbiterD = RotL64((aOrbiterD * 5549220554838837145U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 15370309834426476775U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3896803894396631184U;
            aOrbiterH = RotL64((aOrbiterH * 11018830202891911603U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10848873633291935766U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12885336509190543440U;
            aOrbiterK = RotL64((aOrbiterK * 1487357252619221365U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8252290890093788010U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9201553615601641350U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 420321130559162915U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14014209645503188472U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 4015071464301844550U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 17444195018239904971U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterB, 29U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 13U)) + aOrbiterB) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 54U)) + aOrbiterA) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18669U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((aIndex + 17634U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 20080U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21702U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 19074U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 35U)) + (RotL64(aPrevious, 21U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = (aWandererE + RotL64(aIngress, 3U)) + 12027839670755583592U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 58U)) + 15380130703509859843U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 11U)) + 4590907433867798074U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 1754574023602519724U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 9832756659564903767U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 5035088494491470403U) + aNonceWordE;
            aOrbiterG = (aWandererC + RotL64(aCross, 19U)) + 14199170923323644638U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 8325619421264440438U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 969534320779067977U;
            aOrbiterE = RotL64((aOrbiterE * 17767548306355264705U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 270575869402913847U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13344806516599578910U;
            aOrbiterA = RotL64((aOrbiterA * 10193544126281901579U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15143147951139409101U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14425582489214169238U;
            aOrbiterJ = RotL64((aOrbiterJ * 16893787086337916355U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13951127523239064584U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 14177925225918293579U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13079514031864998485U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8258920744278218901U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7408161179397242453U;
            aOrbiterC = RotL64((aOrbiterC * 975737128100519169U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8581481606764773468U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10078416198417433133U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1102721083915858247U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18299772198826189580U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18304668908084397946U;
            aOrbiterG = RotL64((aOrbiterG * 10589455451200578687U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 19U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + aNonceWordL) + aPhaseHWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + aNonceWordO) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 30U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 12U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterE) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25347U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 25151U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 23452U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23806U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22166U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 21U)) ^ (RotL64(aIngress, 6U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = (aWandererC + RotL64(aPrevious, 11U)) + 3561491146322798260U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 18U)) + 7075025056181885339U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 9230910887904171613U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 4119781172609908917U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 3U)) + 17155609083870983149U) + aNonceWordI;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 29U)) + 2423018561430181695U) + aNonceWordC;
            aOrbiterH = ((((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 12957280305617615744U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 2461704174772065813U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7907123257849391997U;
            aOrbiterK = RotL64((aOrbiterK * 9416171962847312179U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 7257868138318960007U) + aNonceWordM;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 16425903703085702285U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 7996935869077231999U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2990822664594079467U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5654819006718953817U;
            aOrbiterJ = RotL64((aOrbiterJ * 4465096036756887801U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 12183676471235678779U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15026286960542123922U;
            aOrbiterB = RotL64((aOrbiterB * 17199049329995315279U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12169080607071830522U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2906296852254787499U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6754514406846040163U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3029858695410344584U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14406410317495954566U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 9663780721657983421U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11048818178401163861U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13622063920319445043U;
            aOrbiterF = RotL64((aOrbiterF * 2516025554421589857U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 14U)) + aOrbiterK) + aPhaseHWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 39U));
            aWandererE = aWandererE + (((((RotL64(aCross, 57U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + aNonceWordD) + aPhaseHWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 18U) + aOrbiterH) + RotL64(aOrbiterK, 57U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28444U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 27323U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27448U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28892U)) & S_BLOCK1], 48U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 28635U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererG + RotL64(aCross, 21U)) + 6654158889644956636U) + aNonceWordF;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 4U)) + RotL64(aCarry, 37U)) + 9045779659363991870U;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 3888897662136993491U) + aNonceWordM;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 6882016842864459345U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 35U)) + 15601891715956172291U) + aNonceWordL;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 51U)) + 5176811598629335350U) + aNonceWordI;
            aOrbiterF = ((aWandererH + RotL64(aCross, 27U)) + 12519945150889074325U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4552583214397603278U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 14225482701804864688U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8526052833180466359U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5485298070606280363U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11237713257388094289U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11032429223099413011U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 14340345895626142788U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16275167270553643347U;
            aOrbiterB = RotL64((aOrbiterB * 7308578867128951199U), 41U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 14041860597556520250U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1436068974197066343U;
            aOrbiterA = RotL64((aOrbiterA * 3938460345031496843U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11483155566419547004U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4608508534724289325U;
            aOrbiterD = RotL64((aOrbiterD * 13461385011638899485U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2389196334288832895U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 4062682330273866602U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 8787682133271101901U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5655656046585592034U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7977947821249746880U;
            aOrbiterC = RotL64((aOrbiterC * 10082104644185964787U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 12U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterA, 37U)) + aNonceWordJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 60U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Archery_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 451U)) & W_KEY1], 44U) ^ RotL64(aKeyRowReadB[((aIndex + 84U)) & W_KEY1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 161U)) & W_KEY1], 14U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2358U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 43U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererB + RotL64(aCross, 58U)) + 2571116506511057880U) + aPhaseAOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 13112435411509707292U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 19U)) + 10403251762787357256U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 5U)) + 8461951095541400405U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 47U)) + 9890793478557463815U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 28U)) + RotL64(aCarry, 19U)) + 3030229465991783707U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 7273848154043719247U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 10681774862516028276U;
            aOrbiterK = (aWandererG + RotL64(aCross, 51U)) + 7105082755586853104U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6588579345319551129U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 14616333550242386092U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2934574715879306337U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15439666290229654921U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3360304356760164799U;
            aOrbiterH = RotL64((aOrbiterH * 5164191920584106237U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14438730801970761889U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14515616787452085729U;
            aOrbiterI = RotL64((aOrbiterI * 2041601927968559821U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4167853822635132419U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8950982233003320239U;
            aOrbiterF = RotL64((aOrbiterF * 887144270884244907U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12391327853728029953U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7100871010552394421U;
            aOrbiterK = RotL64((aOrbiterK * 16552349374101955967U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15381697462381887944U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6801677551341079401U;
            aOrbiterB = RotL64((aOrbiterB * 13325954438427340703U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 947011315719204867U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6356920162398333481U;
            aOrbiterJ = RotL64((aOrbiterJ * 5566721941682667419U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8910262020598577378U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8778455415977526457U;
            aOrbiterG = RotL64((aOrbiterG * 4092470497616637283U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5585696961453127223U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9670655481681494412U;
            aOrbiterC = RotL64((aOrbiterC * 7863197168965036383U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + aPhaseAWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 51U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aCross, 14U) + aOrbiterJ) + RotL64(aOrbiterC, 46U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterK, 27U));
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterC, 41U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 26U) + RotL64(aOrbiterJ, 60U)) + aOrbiterG) + aPhaseAWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 5006U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadA[((aIndex + 4048U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4261U)) & W_KEY1], 5U) ^ RotL64(mSource[((aIndex + 3701U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 37U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererG + RotL64(aPrevious, 12U)) + 5697928251815176134U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 27U)) + 337587740689259575U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 4927686903263973950U) + aPhaseAOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 3U)) + 3742409032569801033U) + aPhaseAOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 34U)) + 1608092659172197650U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 47U)) + 15848744267145717509U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 21U)) + 15300174177963339253U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 14162868453323648628U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 12020167069983729869U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16259538291658723956U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8516686212464112245U;
            aOrbiterI = RotL64((aOrbiterI * 4731296903548893627U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3722184575520553132U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 5663609293306386784U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14364218128780764749U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15265344442454471986U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3050323350098829515U;
            aOrbiterB = RotL64((aOrbiterB * 5890624677162388135U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1093356813820599238U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 15167726103772238440U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5719466863561311069U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15170797965325981472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17826286701992981628U;
            aOrbiterF = RotL64((aOrbiterF * 11186808881726573677U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14710892030473425181U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 397194787697553904U;
            aOrbiterC = RotL64((aOrbiterC * 14368930300818752833U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1273724124862533034U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13018397560392545616U;
            aOrbiterE = RotL64((aOrbiterE * 4644812473262395329U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9638716186445643730U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7255587739807843785U;
            aOrbiterD = RotL64((aOrbiterD * 6055682981584011189U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9272350563697399628U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1040729335295009339U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17825687660830291443U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 26U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterC, 51U));
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterK, 35U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 52U) + RotL64(aOrbiterC, 44U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + aPhaseAWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + aPhaseAWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 57U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 6U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 36U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 5849U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 5945U)) & W_KEY1], 26U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8080U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5948U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6884U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 34U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererA + RotL64(aPrevious, 35U)) + 3199575576585871314U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 23U)) + 2533378188975571824U) + aPhaseAOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 54U)) + 6819782112558312658U) + aPhaseAOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aIngress, 43U)) + 12690060987724798497U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 7088375139715629606U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 17785618677423695666U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 1714999280296491277U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 58U)) + 17611338506932491624U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 13U)) + 6475727359297421201U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2347744591204119530U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2739317903351401068U;
            aOrbiterE = RotL64((aOrbiterE * 15435029315209475631U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8663535261373274338U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8205245127823536479U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13857005110466856439U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8916510616749754516U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3944805940148512932U;
            aOrbiterG = RotL64((aOrbiterG * 18082271583211389701U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14094751253118853302U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14094299829196076311U;
            aOrbiterC = RotL64((aOrbiterC * 6370012560657108493U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3940673811518673802U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3015106523254484839U;
            aOrbiterH = RotL64((aOrbiterH * 9655401190755573379U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 15404103131982599922U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1828655763233900875U;
            aOrbiterB = RotL64((aOrbiterB * 13024358077740310049U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1236981890899916502U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 18208975564570342697U;
            aOrbiterA = RotL64((aOrbiterA * 4577109989465876801U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17882273895471449661U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16196010765612713713U;
            aOrbiterJ = RotL64((aOrbiterJ * 15624856645134182005U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14639250100311162559U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9139027997336903273U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1853126389565574293U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 37U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 10U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aScatter, 24U) + aOrbiterJ) + RotL64(aOrbiterH, 5U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterG, 24U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterF) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 10645U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 10904U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(mSource[((aIndex + 10871U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((aIndex + 10681U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10655U)) & W_KEY1], 10U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 9106U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCarry, 34U)) ^ (RotL64(aCross, 21U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererG + RotL64(aScatter, 27U)) + 11700815697312060726U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 11U)) + 11808423452327465441U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 60U)) + 8670503858631730886U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 2400061067991988544U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 16163118178366229686U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 51U)) + 3280178595904941068U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 3298683600817047727U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 47U)) + 16321624053445183574U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 38U)) + 6730229877611375225U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10162830636713641322U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15646771327759599256U;
            aOrbiterF = RotL64((aOrbiterF * 15333053762177144775U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14841751262270544102U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9545541117228834895U;
            aOrbiterC = RotL64((aOrbiterC * 11529769874752969377U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14676615635857599982U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1231768638470558855U;
            aOrbiterA = RotL64((aOrbiterA * 2716808508509014677U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 1945905595345404833U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1406171421638586846U;
            aOrbiterI = RotL64((aOrbiterI * 4577864352425476233U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1970292335806697198U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12309719390375013297U;
            aOrbiterH = RotL64((aOrbiterH * 16540660957923687327U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5352135521358954576U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15465675376193501658U;
            aOrbiterK = RotL64((aOrbiterK * 16385761112921041387U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2842123638916600369U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3544764287036748668U;
            aOrbiterD = RotL64((aOrbiterD * 3360772950777850115U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6038297172906492282U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10249342332287140970U;
            aOrbiterJ = RotL64((aOrbiterJ * 16701083081566042277U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1662076777040529446U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1949705569959740274U;
            aOrbiterB = RotL64((aOrbiterB * 11340691546658994529U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 6U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 28U)) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 38U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 21U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterC, 34U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 53U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11252U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 11541U)) & W_KEY1], 52U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12498U)) & W_KEY1], 21U) ^ RotL64(mSource[((aIndex + 11705U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11753U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11146U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12055U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 42U)) + (RotL64(aIngress, 29U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 10U)) + RotL64(aCarry, 39U)) + 12809562813316740345U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 19U)) + 17084212535326321199U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 57U)) + 16074921689983846769U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 43U)) + 14027986153007120145U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 14U)) + RotL64(aCarry, 47U)) + 7633455951809250227U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 37U)) + 340989348513370174U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 23U)) + 5307820377645020116U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 5605285015771527274U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 3U)) + 5293500434746182790U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7263156475892261811U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10672879570907433005U;
            aOrbiterB = RotL64((aOrbiterB * 2506338667179450741U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16659226780900986107U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9774892622769850665U;
            aOrbiterI = RotL64((aOrbiterI * 7487477727543183211U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10728057184108279042U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5032485856947407217U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16651577903809154285U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14642241075374862345U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8386481273395203518U;
            aOrbiterD = RotL64((aOrbiterD * 11649977733867003445U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2874153265304098104U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11519900149177261000U;
            aOrbiterG = RotL64((aOrbiterG * 2010158758971864505U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8885690878540115768U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4482143389870987714U;
            aOrbiterK = RotL64((aOrbiterK * 7105332459437434281U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17469068567801886615U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5121422018622394837U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14823827133212643467U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3130788210672745618U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6139244627510113216U;
            aOrbiterC = RotL64((aOrbiterC * 2640754184921507389U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10488511756324474710U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1760223670304953696U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4007062295003769311U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 46U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterG, 41U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterD, 14U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterI, 19U));
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterC, 37U)) + aPhaseBWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 48U) + aOrbiterG) + RotL64(aOrbiterC, 60U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 53U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 42U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 16163U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneC[((aIndex + 13702U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16093U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14972U)) & W_KEY1], 39U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14887U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16124U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14270U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererC + RotL64(aScatter, 13U)) + 12690502671561165478U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 17519943923428102801U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aIngress, 38U)) + RotL64(aCarry, 21U)) + 10705515807975331385U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 47U)) + 16586447272278538179U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 57U)) + 8006560996840971798U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 43U)) + 12928600185788857701U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 5U)) + 14240723153798267172U) + aPhaseBOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 8636219177994872072U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 30U)) + 7586790235186467512U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1103807034179512424U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7547526530239498693U;
            aOrbiterF = RotL64((aOrbiterF * 3360295583636013509U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8380239679344786397U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5690809173787433519U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5354724308093372953U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8390902801141804609U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3507306189192059486U;
            aOrbiterJ = RotL64((aOrbiterJ * 18336280496510253103U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6190745292098482871U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8065418693975056902U;
            aOrbiterK = RotL64((aOrbiterK * 6414621418430102589U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12111755051718111803U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7605877769709909297U;
            aOrbiterD = RotL64((aOrbiterD * 17525248694315944599U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5969794501112646237U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5127559299360591476U;
            aOrbiterE = RotL64((aOrbiterE * 4521563633438853069U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10593847754747739786U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4401750688524310121U;
            aOrbiterG = RotL64((aOrbiterG * 14265829318976633707U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6927893132508779499U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4874009978647014479U;
            aOrbiterC = RotL64((aOrbiterC * 13340466017023540755U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13146693487138744677U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3298472134223595298U;
            aOrbiterB = RotL64((aOrbiterB * 2145005258008477281U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 18U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterE, 30U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 57U));
            aWandererD = aWandererD + ((RotL64(aCross, 54U) + RotL64(aOrbiterB, 53U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterK, 12U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterK, 37U));
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterK, 47U)) + aPhaseBWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 34U) + aOrbiterB) + RotL64(aOrbiterD, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17524U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 18202U)) & W_KEY1], 4U));
            aIngress ^= (RotL64(mSource[((aIndex + 18267U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17182U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16453U)) & W_KEY1], 44U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17463U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17373U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 23U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (((aWandererG + RotL64(aScatter, 18U)) + RotL64(aCarry, 35U)) + 13650869943246163567U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 27U)) + 3435284932011770999U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 12388155658186776579U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 57U)) + 2374345913955712039U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 11U)) + 6095094526980292156U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 5U)) + 4965147025852444174U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 51U)) + 3261881216269075298U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 34U)) + 4939780217097329222U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 3019862009792676287U) + aPhaseCOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 901910626217143974U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3647055146712366383U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1792602402476450009U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7731765438957392967U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13409819457393479741U;
            aOrbiterF = RotL64((aOrbiterF * 3345078200262410715U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5415832109107794258U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8876738832313114471U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1304277600444504135U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17135570542519390359U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2373193062766802082U;
            aOrbiterC = RotL64((aOrbiterC * 4213691513185791519U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16318403285501718552U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8456043288604687045U;
            aOrbiterH = RotL64((aOrbiterH * 10556964529144571683U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10572534930284516528U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14616251186735204677U;
            aOrbiterE = RotL64((aOrbiterE * 2048651204265459805U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2837006243817205610U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5315917323622194254U;
            aOrbiterJ = RotL64((aOrbiterJ * 4080522050089666599U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12084676282761185907U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7922080344175593788U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7603522302708937379U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17620847289789547792U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12140386059533463650U;
            aOrbiterA = RotL64((aOrbiterA * 1443266480620969535U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 54U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aIngress, 42U) + RotL64(aOrbiterG, 47U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 30U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterG) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterH, 39U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 12U) + RotL64(aOrbiterE, 24U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aPhaseCWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20346U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 19487U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 20170U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneA[((aIndex + 21448U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20917U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21209U)) & W_KEY1], 19U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21835U)) & S_BLOCK1], 6U) ^ RotL64(aFireLaneB[((aIndex + 21427U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 23U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 5088525177670191619U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 39U)) + 9966456257813932112U;
            aOrbiterF = (aWandererB + RotL64(aCross, 35U)) + 7707646574027146307U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 30U)) + 75480203757681173U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 19U)) + 384659134071835163U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 3158769775373307778U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 5U)) + 17360830943513941272U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 52U)) + RotL64(aCarry, 35U)) + 5317278822721604586U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 13U)) + 1371427105215954781U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3162710551223553423U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5332921933853550756U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11709546145149357887U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10572462410297815854U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10234389605554817892U;
            aOrbiterB = RotL64((aOrbiterB * 2130374833440291193U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13421365517991380605U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 10186643614984034083U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8554471709467808453U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4742438973260817120U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6081590345899008846U;
            aOrbiterI = RotL64((aOrbiterI * 7069396301823124931U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15360092808493795340U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12186413069553132646U;
            aOrbiterJ = RotL64((aOrbiterJ * 3815981440611914267U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16756221656224451552U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12232880965861373143U;
            aOrbiterG = RotL64((aOrbiterG * 14196910735715726471U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10090954323470840557U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 15615770271463853537U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13544181592829027283U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 556029032505658411U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13311879111583579039U;
            aOrbiterK = RotL64((aOrbiterK * 3924744868168749003U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8646360871497847336U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2064833941982069154U;
            aOrbiterA = RotL64((aOrbiterA * 10016546852137913163U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 6U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 10U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 52U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aPhaseCWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 21U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 4U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 47U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 14U) + aOrbiterA) + RotL64(aOrbiterI, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23555U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 23937U)) & W_KEY1], 34U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22492U)) & W_KEY1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 22956U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23314U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22906U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24271U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((aIndex + 22564U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 48U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 9446153639709651566U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 38U)) + 10550762260670758167U) + aPhaseCOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aPrevious, 27U)) + 7062634922142578383U;
            aOrbiterG = (aWandererE + RotL64(aCross, 51U)) + 9178499097812764515U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 6887103379773525538U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 6239750312052010257U;
            aOrbiterC = (aWandererA + RotL64(aCross, 23U)) + 17645022614523287959U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 3U)) + 3639618183259408272U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 58U)) + 3131737117548745095U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7253994382396406554U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15217993711938379561U;
            aOrbiterD = RotL64((aOrbiterD * 17853313384747259923U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12594152227603630033U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11250170200489647869U;
            aOrbiterF = RotL64((aOrbiterF * 546800378327864723U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12936942656624279424U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10990736056052106149U;
            aOrbiterK = RotL64((aOrbiterK * 7123916809953459187U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12787293075893090465U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17154990205620778151U;
            aOrbiterG = RotL64((aOrbiterG * 10031369940028159521U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1270827262969060301U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17337623431665013136U;
            aOrbiterI = RotL64((aOrbiterI * 1517262088236356107U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 830330490987911853U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6828309232554560547U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9742464176986145819U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11470087853413986203U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10470148870747884420U;
            aOrbiterJ = RotL64((aOrbiterJ * 6766079738799967443U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 18315536891901859637U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 12264670822285914271U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5841574505408674119U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10931842095884524879U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11134871340959676257U;
            aOrbiterB = RotL64((aOrbiterB * 11714837622285605745U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 46U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterK, 60U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 18U) + aOrbiterI) + RotL64(aOrbiterG, 27U));
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 35U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 39U)) + aOrbiterF) + aPhaseCWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 56U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 23U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24787U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 24991U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 27208U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27172U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25872U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25442U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27148U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneD[((aIndex + 26013U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 20U) + RotL64(aCross, 3U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 17936518874386450467U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 28U)) + 13722737841589910344U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 5U)) + 11774969167948715796U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 3640101505680493777U;
            aOrbiterC = (aWandererE + RotL64(aCross, 13U)) + 1369495382725650822U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 46U)) + 11827310354654653345U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 186037671377175394U) + aPhaseDOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 37U)) + 11428829344234627340U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 41U)) + 2275016369870029068U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15471646673734798328U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12172082573115640145U;
            aOrbiterK = RotL64((aOrbiterK * 9629417882787847753U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6626736341348283154U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12220614992483863623U;
            aOrbiterC = RotL64((aOrbiterC * 8137086205714097487U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13157102324253760215U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4143587482368093601U;
            aOrbiterH = RotL64((aOrbiterH * 5060677690991506895U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11007575246013796426U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11721585930088637162U;
            aOrbiterF = RotL64((aOrbiterF * 15009627907125738519U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5720789204450196217U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3094696226821431648U;
            aOrbiterD = RotL64((aOrbiterD * 4412033981712165541U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 14675830108100986773U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9444071495289719645U;
            aOrbiterI = RotL64((aOrbiterI * 10983136361953366557U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5106753847015199956U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7585421898593510010U;
            aOrbiterA = RotL64((aOrbiterA * 140996914192351011U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 11746948407655524690U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16336323220286344483U;
            aOrbiterE = RotL64((aOrbiterE * 6590417628835864497U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8030445186765781136U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 276034088015165891U;
            aOrbiterB = RotL64((aOrbiterB * 7626025612710225099U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 18U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 56U) + aOrbiterK) + RotL64(aOrbiterD, 39U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 29U)) + aOrbiterK) + aPhaseDWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 19U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterF, 24U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 35U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 47U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            aWandererD = aWandererD + (((RotL64(aScatter, 30U) + RotL64(aOrbiterE, 56U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterF, 43U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29893U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 28966U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27338U)) & W_KEY1], 24U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27526U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28996U)) & W_KEY1], 60U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29629U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29683U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 28222U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererG + RotL64(aPrevious, 43U)) + 8604208734152026945U;
            aOrbiterE = (aWandererH + RotL64(aCross, 11U)) + 1374329953253889829U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 5779278910548228339U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 24U)) + 17670451230882805140U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 37U)) + 8193848740764866860U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 57U)) + 15801168428145650104U) + aPhaseDOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 2584718176087499066U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 14950366247822737997U;
            aOrbiterC = (aWandererA + RotL64(aCross, 48U)) + 9779293225265670135U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8688968319288372383U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13665723186950342601U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 292035540396910837U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9395428688359973510U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2152719218018108418U;
            aOrbiterA = RotL64((aOrbiterA * 15271961483518392671U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1350324137411377992U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8729317951386057921U;
            aOrbiterH = RotL64((aOrbiterH * 6008790836417785083U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 6317310451893678411U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10175620379041384281U;
            aOrbiterG = RotL64((aOrbiterG * 14079679617394330781U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1203082119358827708U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 523869107818193101U;
            aOrbiterJ = RotL64((aOrbiterJ * 4629501113595689157U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4028324959540432983U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15447631947468213912U;
            aOrbiterI = RotL64((aOrbiterI * 6037306615787729185U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14225888694733041031U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11925000696281947629U;
            aOrbiterE = RotL64((aOrbiterE * 4337022940520411253U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15015531024930608745U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16752579225076943550U;
            aOrbiterC = RotL64((aOrbiterC * 15551083683579981439U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2432733494869267901U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10103430321388601485U;
            aOrbiterK = RotL64((aOrbiterK * 18372919379972432569U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterG, 14U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 42U) + RotL64(aOrbiterH, 21U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 53U)) + aOrbiterE) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterF, 13U));
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 37U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 29U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 4U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32630U)) & S_BLOCK1], 40U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31546U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31118U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32226U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32483U)) & S_BLOCK1], 24U) ^ RotL64(aKeyRowReadB[((aIndex + 32610U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererH + RotL64(aIngress, 60U)) + 1087148170018530502U;
            aOrbiterE = (aWandererI + RotL64(aCross, 47U)) + 15530846874509311414U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 27U)) + 16987358651515511212U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 53U)) + 12504143181007924259U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 393322117322732418U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 13U)) + 14325937299241887166U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 9395262907017475742U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 42U)) + RotL64(aCarry, 23U)) + 13658510441418344769U) + aPhaseDOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 3U)) + 6410754322737005336U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9257290738538818434U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7489828960857692286U;
            aOrbiterJ = RotL64((aOrbiterJ * 16519674788777989043U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4118778591214588387U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16619215231168796563U;
            aOrbiterA = RotL64((aOrbiterA * 14876884956536265157U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11326283811003573430U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 1865401866017614604U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8378326058282460073U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 670150121105733604U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1499331510641068749U;
            aOrbiterF = RotL64((aOrbiterF * 16623742535540383107U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1116410848560838532U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2696841341036281779U;
            aOrbiterH = RotL64((aOrbiterH * 9598953298074904869U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5487352391229549881U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12008243050943342979U;
            aOrbiterK = RotL64((aOrbiterK * 9087261224804582459U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 552859665927882960U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8426942688524814473U;
            aOrbiterC = RotL64((aOrbiterC * 10916963622695549105U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1613287981244830815U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15592897923468694288U;
            aOrbiterD = RotL64((aOrbiterD * 6600750586743893303U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7629853970631002676U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13778028957247561272U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4063798788229605659U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 10U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 28U) + aOrbiterD) + RotL64(aOrbiterK, 23U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterE, 12U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterG, 5U));
            aWandererH = aWandererH + ((RotL64(aIngress, 24U) + aOrbiterK) + RotL64(aOrbiterJ, 39U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 60U)) + aOrbiterG) + aPhaseDWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 29U);
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

void TwistExpander_Archery_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6033U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 1704U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1828U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7722U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3984U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6064U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 4U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aCross, 35U)) + 12311607308490066301U) + aPhaseEOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 13100864684740679846U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 19U)) + 13697304189274329704U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 11U)) + 9047976902871216732U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 60U)) + 2147897579538537888U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 2072444829390996142U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 2129307836981020908U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10663145333751112064U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15019844390503785459U;
            aOrbiterK = RotL64((aOrbiterK * 7442321463110790449U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5460865577557928142U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15806522559993224197U;
            aOrbiterF = RotL64((aOrbiterF * 8722932687972240099U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6361113778657833389U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8306013884615042570U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8234258702656728667U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4038420580499706912U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11908091484457158973U;
            aOrbiterB = RotL64((aOrbiterB * 3964111175645156719U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11133912466611921250U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2469227904206936928U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2704438771198001599U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 13234017916788297295U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 9061117693840451988U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3637440416741459419U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12013423690843812324U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14371779015144617412U;
            aOrbiterE = RotL64((aOrbiterE * 3359568073302062667U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 13U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 21U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 29U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 42U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 22U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 9058U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 13653U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 13050U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8448U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15586U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8710U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8933U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 42U)) + (RotL64(aPrevious, 57U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aCross, 19U)) + 11039986441331892533U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 58U)) + RotL64(aCarry, 27U)) + 6256024955965426119U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 5U)) + 9857443189988995666U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 39U)) + 11900944813380998208U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 8422577734978875541U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 27U)) + 3100835100713928724U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 11871553509810206993U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17614749493763417027U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3638372131856199916U;
            aOrbiterJ = RotL64((aOrbiterJ * 480683274898147025U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6582275259281025770U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17016882418498941958U;
            aOrbiterE = RotL64((aOrbiterE * 4269869255230867823U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1747214688658984715U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 9356088987044015278U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16221733545319753695U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4056238112133473456U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16013150119949532998U;
            aOrbiterD = RotL64((aOrbiterD * 12913648646318115315U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16076621211111834889U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 9940824359571581765U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11624767861336495331U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15624084004784515753U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7630989544834680335U;
            aOrbiterK = RotL64((aOrbiterK * 12261063237156822067U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 18003586430673313786U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1654118743290334161U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1153250137357176071U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterH, 35U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 57U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 12U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 41U)) + aOrbiterI) + aPhaseEWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24128U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 22545U)) & S_BLOCK1], 54U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 21135U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 19323U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24221U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24418U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 21712U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 4U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererH + RotL64(aScatter, 58U)) + RotL64(aCarry, 27U)) + 12583180859826261500U) + aPhaseEOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 43U)) + 9067093488553721468U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 12173106198862881754U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 3U)) + 11333491014394592654U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 11U)) + 3511883526940919554U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 7416810692106273044U;
            aOrbiterE = (aWandererA + RotL64(aCross, 19U)) + 8341174972619784110U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2220852854836962979U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 8090781422229383825U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 578293950675644397U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2338801236599102223U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12484514711848308104U;
            aOrbiterH = RotL64((aOrbiterH * 10364216764253366067U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13684861340589131816U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12796636819991873058U;
            aOrbiterK = RotL64((aOrbiterK * 5533508014234835669U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7634198650894837690U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10240326122201201762U;
            aOrbiterB = RotL64((aOrbiterB * 8758703497719125901U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4162814763739453934U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2766504649149048469U;
            aOrbiterI = RotL64((aOrbiterI * 16731843453895178671U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11051393030148769655U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17687055068651386665U;
            aOrbiterC = RotL64((aOrbiterC * 1042927176246229537U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3353615315436983420U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5971640796220306310U;
            aOrbiterE = RotL64((aOrbiterE * 15804313508835034807U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterC, 41U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 3U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterC, 53U)) + aPhaseEWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 34U)) + aPhaseEWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29674U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 28364U)) & S_BLOCK1], 10U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 29425U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 26870U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26939U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32555U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 25997U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 42U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aIngress, 11U)) + 9888431329297626900U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 18U)) + 2937735167534624403U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 17626022970343789617U) + aPhaseEOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 5665660859333693743U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 1060537034632076669U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 43U)) + 743777763907175800U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 51U)) + 5744905970181808845U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3545351394494002180U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4877547088414106007U;
            aOrbiterG = RotL64((aOrbiterG * 5416792889338547109U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11669378338379598445U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2961072441706158212U;
            aOrbiterH = RotL64((aOrbiterH * 2677988507090705371U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13984945589234919765U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1433097875470903205U;
            aOrbiterF = RotL64((aOrbiterF * 451996840039906781U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 716415411025451152U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8542286150858297810U;
            aOrbiterE = RotL64((aOrbiterE * 9139015340823332449U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12932391786479661299U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14005503313299177013U;
            aOrbiterK = RotL64((aOrbiterK * 802663466907819743U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9382792812676318046U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5138554251079724724U;
            aOrbiterC = RotL64((aOrbiterC * 6386016499265056247U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8522380066269546172U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11825536408101906458U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17042837108792016849U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 48U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterG, 5U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 19U)) + aOrbiterH) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 28U));
            aWandererD = aWandererD + ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Archery_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7502U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 1423U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1293U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2613U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 911U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1469U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCross, 42U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 39U)) + 10805654776556844351U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 5U)) + 582794182442795335U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 2858343650974681068U;
            aOrbiterG = (aWandererB + RotL64(aCross, 23U)) + 8189584049022064284U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 14U)) + RotL64(aCarry, 23U)) + 1565100751996962893U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 51U)) + 8062028016947611891U;
            aOrbiterA = (aWandererA + RotL64(aCross, 41U)) + 8280504280578451745U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 19U)) + 11326869194491655350U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 27U)) + 1671695656567777163U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 3U)) + 2349843105293943452U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 37U)) + 13015545152052004254U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16703354404749291869U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8713231044374305801U;
            aOrbiterC = RotL64((aOrbiterC * 9242480982197688625U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11118401674497783533U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14857556493734710364U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3452566050389715195U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12953419670951660965U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12666121730825089017U;
            aOrbiterE = RotL64((aOrbiterE * 14049925256934142519U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 11075249639473053423U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9374217688244187867U;
            aOrbiterF = RotL64((aOrbiterF * 5261156325627117877U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17608340953291367867U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13159437499327086340U;
            aOrbiterK = RotL64((aOrbiterK * 4882100944453534805U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4304700511322366815U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10172544755256706767U;
            aOrbiterH = RotL64((aOrbiterH * 4013006212154771797U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17340067939877432472U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 14130447570008179105U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8178075071208718915U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2652532710498072378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10384945384238518296U;
            aOrbiterG = RotL64((aOrbiterG * 17137694272394304045U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15292159041119433363U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12103644911645285108U;
            aOrbiterA = RotL64((aOrbiterA * 4565615406415614103U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16307525158627275744U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3786908390177579447U;
            aOrbiterD = RotL64((aOrbiterD * 6592585847755318801U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13595883419843505634U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10805654776556844351U;
            aOrbiterJ = RotL64((aOrbiterJ * 10956465099104915639U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 53U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 56U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 23U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterE, 13U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 36U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterH, 11U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 14U) + aOrbiterI) + RotL64(aOrbiterE, 47U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12989U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 11755U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 15886U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8625U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9662U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14320U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15272U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 51U)) + (RotL64(aCarry, 18U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererD + RotL64(aScatter, 37U)) + 7722279280863371124U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 11584220561732385598U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 47U)) + 7834679350105534657U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aCross, 27U)) + 11347994382444180879U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 60U)) + 9449903188047063431U;
            aOrbiterH = (aWandererA + RotL64(aCross, 41U)) + 6516243976652795170U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 8420815253991184777U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 29U)) + 9081386852515170937U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 34U)) + 14375955191735286867U;
            aOrbiterC = (aWandererK + RotL64(aCross, 51U)) + 880757589768436072U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 3349856625725164229U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7826309957607577207U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8057435761214313635U;
            aOrbiterI = RotL64((aOrbiterI * 4718430712767038607U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9565237500443303103U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15893066735310588501U;
            aOrbiterD = RotL64((aOrbiterD * 8457633439171452397U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3276844534476430842U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6828644383891274120U;
            aOrbiterB = RotL64((aOrbiterB * 979580351653410157U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2815676923011504251U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5030251870850928417U;
            aOrbiterK = RotL64((aOrbiterK * 7075653570570819253U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13464083008377887034U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8994560761846897590U;
            aOrbiterA = RotL64((aOrbiterA * 9892839554658865143U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8398813387154468736U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8136429428340910892U;
            aOrbiterF = RotL64((aOrbiterF * 3348811490733577295U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 418587250696862341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4111667833838312094U;
            aOrbiterE = RotL64((aOrbiterE * 860949442143849147U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6075478294190926371U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2208124955874142264U;
            aOrbiterH = RotL64((aOrbiterH * 15741988616251072075U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4726538724576443010U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6524078248882840425U;
            aOrbiterC = RotL64((aOrbiterC * 9784875566721689069U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14521003220464811621U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 16916247868211621303U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1911638054294853877U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 18207293125461843123U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7722279280863371124U;
            aOrbiterJ = RotL64((aOrbiterJ * 14303108475807941791U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 22U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterJ, 58U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterD, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 29U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 23U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterF, 34U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 39U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 13U));
            aWandererD = aWandererD + ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterA, 11U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 56U) + aOrbiterB) + RotL64(aOrbiterK, 53U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 41U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 21U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18325U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 18000U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 17695U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23661U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21015U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20049U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24159U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 21U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 37U)) + 6467297102954816305U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 27U)) + 7921154109831114952U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 19U)) + 5701131763215638919U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 29U)) + 10022999076719002684U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 54U)) + 4367135243038982316U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 14445846824810383592U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 5U)) + 7683697954545773253U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 17517006750428030899U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 52U)) + 2052484792684025476U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 37U)) + 6279463052085808926U;
            aOrbiterF = (aWandererI + RotL64(aCross, 3U)) + 679280153651813684U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2939516520188460569U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1960616434964712325U;
            aOrbiterI = RotL64((aOrbiterI * 15145998415466343039U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12273819390719947361U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5685033154709449397U;
            aOrbiterC = RotL64((aOrbiterC * 9845666295874714959U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 9314494172199500653U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15757631834636427621U;
            aOrbiterD = RotL64((aOrbiterD * 15483543888965744529U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10878078046389399574U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3583495913766365232U;
            aOrbiterJ = RotL64((aOrbiterJ * 2913540984990155225U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7385544065754622301U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16839599460207922881U;
            aOrbiterE = RotL64((aOrbiterE * 240651605910592561U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13038163804940349251U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2587538594933924000U;
            aOrbiterB = RotL64((aOrbiterB * 3091149760401278671U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13109518583364738004U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2447689055742474261U;
            aOrbiterA = RotL64((aOrbiterA * 12100180201235703193U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5752044906692668618U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 6637725371036522120U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6021986525167161115U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16549229877442298618U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12825651879441561108U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9079931351967033993U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16088338999978085987U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12584648360998154782U;
            aOrbiterK = RotL64((aOrbiterK * 2109996837220975261U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7526256599938771686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6467297102954816305U;
            aOrbiterH = RotL64((aOrbiterH * 9289442676936248653U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 58U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 43U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterC, 12U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterB, 53U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 23U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 21U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterA, 35U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterE, 38U)) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 34U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25583U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 25144U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 26008U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28293U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31355U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27939U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 31440U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 10U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 48U)) + RotL64(aCarry, 57U)) + 5960680319644404115U) + aPhaseFOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 43U)) + 16050752633567034185U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 19U)) + 8447503223226854741U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 14176813813397917591U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 3U)) + 10534915376130006644U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 6866224454375302514U;
            aOrbiterG = (aWandererA + RotL64(aCross, 37U)) + 16506374165041008396U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 27U)) + 7167814023968794098U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 23U)) + 13870852197416596664U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 40U)) + 18064038854848993105U) + aPhaseFOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aCross, 21U)) + 9869630811507771691U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 863613100452759380U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16597969741225436529U;
            aOrbiterF = RotL64((aOrbiterF * 2680793528887208903U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6575347108051310653U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17062262265485019063U;
            aOrbiterE = RotL64((aOrbiterE * 7601045488473620019U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7193399224636409133U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14146747818810433849U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5273185769989530041U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9441449106442431427U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 4303295336545399503U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8829695296836242587U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12604760768543193458U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15779327512379787715U;
            aOrbiterH = RotL64((aOrbiterH * 14000905201441272597U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15553000781122708728U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17162740616060079717U;
            aOrbiterJ = RotL64((aOrbiterJ * 9458662233556750239U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1032374679817715156U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16413393156165548232U;
            aOrbiterD = RotL64((aOrbiterD * 549659738811935015U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14056855000013992045U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 7399202019042538829U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6103508549612077695U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2218389473339103389U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4679497280975967770U;
            aOrbiterA = RotL64((aOrbiterA * 9228353578259815023U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7620538119914173747U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3118355627808424159U;
            aOrbiterC = RotL64((aOrbiterC * 12481319980496032783U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16787092219237931175U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5960680319644404115U;
            aOrbiterK = RotL64((aOrbiterK * 10727217147056112401U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 56U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 10U) + aOrbiterH) + RotL64(aOrbiterF, 11U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 58U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 39U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterE, 26U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 56U) + RotL64(aOrbiterH, 29U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            aWandererD = aWandererD + ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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

void TwistExpander_Archery_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
        // ingress from: aWorkLaneA, aWorkLaneB, aWorkLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aWorkLaneB, aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneB backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8007U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 8044U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6970U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5353U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6320U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 3910U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 35U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 20U)) + RotL64(aCarry, 13U)) + 4980738603982643969U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 17660278413018470020U) + aPhaseGOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aIngress, 57U)) + 17598114429859543466U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 10993929335279994739U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 29U)) + 17967203122976322481U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1872290205549034384U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16607778671782810797U;
            aOrbiterB = RotL64((aOrbiterB * 340054507611349681U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4895226930754394376U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 14960359005982301383U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8546231310054433721U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9921642352377700630U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 893281964367208693U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2345509157333444217U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8232519988397858732U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4433022122758913407U;
            aOrbiterK = RotL64((aOrbiterK * 834240393225479419U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12689609831247168353U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 404535388957472176U;
            aOrbiterE = RotL64((aOrbiterE * 14534020545479806593U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 24U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterF, 41U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterI, 57U)) + aPhaseGWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterE, 30U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15689U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((aIndex + 15684U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 15039U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13491U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14656U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 16126U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 18U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 4204560462077827182U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 6572370199668594039U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 13U)) + 15958999876732622825U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 9969349486879280377U) + aPhaseGOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 36U)) + 15450238998293956181U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9128619863683138259U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 5691270563628979565U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2170424734274640859U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5901029710568933106U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 10442738941988588834U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7386621444831603817U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3508116020325721993U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13221917083569767259U;
            aOrbiterB = RotL64((aOrbiterB * 6845108555710135357U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11627915460377128176U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17858261365514253433U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7535577636975884641U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4294837988806295989U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11242915481585070249U;
            aOrbiterK = RotL64((aOrbiterK * 17540688242763829319U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 22U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterK, 35U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterB, 43U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterK) + aPhaseGWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 22U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22513U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 19204U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 20991U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22131U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22400U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 19803U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aIngress, 48U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererE + RotL64(aIngress, 53U)) + 16651241552253078315U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 14U)) + RotL64(aCarry, 23U)) + 4558144676982478003U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 8814884320080367550U) + aPhaseGOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aScatter, 3U)) + 16011579668555672117U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 4738918668759862438U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12526083125540985108U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8048723561746000552U;
            aOrbiterB = RotL64((aOrbiterB * 11914807994597963481U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1082218464034639039U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8432043246965946816U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7801965585991025451U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9982080524048636852U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6720069955755215919U;
            aOrbiterJ = RotL64((aOrbiterJ * 1025046364205332059U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1019035028070247757U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7360619079463870467U;
            aOrbiterK = RotL64((aOrbiterK * 6623074813047915863U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10893918488381348474U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1390297670907738019U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11909657437658597735U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 4U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 13U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 5U)) + aOrbiterK) + aPhaseGWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 58U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterB, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27638U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 30039U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 25006U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32556U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31544U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 25134U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 29U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 8767379393098711499U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 54U)) + 7168159491580816433U) + aPhaseGOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 29U)) + 9879279829061883406U) + aPhaseGOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 10537167136053399303U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 2839070018069188936U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13844278063968429732U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11278946626186474646U;
            aOrbiterE = RotL64((aOrbiterE * 6601953972456332355U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11798425216660557799U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7618446090703335192U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7168757300685156779U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 695423597006983660U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14344728202803488813U;
            aOrbiterA = RotL64((aOrbiterA * 5168825904902285909U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11656100506575697086U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10384358779985773937U;
            aOrbiterG = RotL64((aOrbiterG * 247494692039140973U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17585001605131977341U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9964478171465522911U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13484044854790175315U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterG, 51U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterF, 21U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 46U) + RotL64(aOrbiterD, 30U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterA, 5U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
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

void TwistExpander_Archery_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1696U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 1851U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3030U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7938U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2259U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 385U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 28U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererB + RotL64(aCross, 43U)) + 12849591986267890852U) + aPhaseHOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 8232614804696815750U) + aPhaseHOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aScatter, 5U)) + 12141567259210877281U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 21U)) + 2928641981037885644U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 980733350554783938U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2683985177993350746U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14532148403815527355U;
            aOrbiterD = RotL64((aOrbiterD * 15985362037094864225U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 7736296629433884203U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 10428437770166310549U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 326634742742373401U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 18327174144859461029U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6810436935194432002U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2715987179577753597U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12606153309690753435U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17123256945895150555U;
            aOrbiterE = RotL64((aOrbiterE * 13469111258504672565U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9057777759026189541U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16478485918911194442U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11054247078884894131U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 54U) + aOrbiterE) + RotL64(aOrbiterJ, 52U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 41U));
            aWandererB = aWandererB + ((((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterF, 5U)) + aPhaseHWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11400U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 13599U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 15319U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13194U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10994U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16215U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 15045917390223766480U) + aPhaseHOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aCross, 57U)) + 10763054007033668758U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 35U)) + 13190170142593666607U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 9657025731441167065U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 12U)) + RotL64(aCarry, 43U)) + 11433367178975954211U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17904920143996810366U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3244383020512113283U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 552521443123433353U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6538815775171139091U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7195368312757976343U;
            aOrbiterG = RotL64((aOrbiterG * 10515679176134176565U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18134430713910279374U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6571776588427107976U;
            aOrbiterD = RotL64((aOrbiterD * 11916502085252589161U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11830778129647517758U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9793702760907767365U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4096246227968677179U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2287235876793192036U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8951959188326141794U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9968356718110753845U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 40U)) + aOrbiterB) + aPhaseHWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterE, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17868U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((aIndex + 24540U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 19996U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21882U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18583U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21059U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 3448371607470865612U) + aPhaseHOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 3743742913651580573U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 13069491287948807280U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 28U)) + 16872779275586545632U) + aPhaseHOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 41U)) + 17945792656755062795U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 18199747196793731853U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15953311878379809513U;
            aOrbiterB = RotL64((aOrbiterB * 5476802169152352897U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 941268763494588338U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10090221530365796809U;
            aOrbiterI = RotL64((aOrbiterI * 14035236086292997613U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8335698093307607001U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6147498804734306100U;
            aOrbiterJ = RotL64((aOrbiterJ * 6904444049941211327U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5980246079567570090U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4152167624425912978U;
            aOrbiterH = RotL64((aOrbiterH * 10019421651535123573U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14990418790239735916U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3418668387496597219U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12814077238529863119U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 19U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 27U)) + aPhaseHWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterH, 48U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererB, 58U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25848U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 30554U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 32408U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25757U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26136U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 24734U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererG + RotL64(aIngress, 43U)) + 13880995121909552664U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 52U)) + RotL64(aCarry, 37U)) + 14534942818069300546U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aScatter, 21U)) + 17745973100886007133U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 2249805580771946872U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 4460116116396439410U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3378683994078106878U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3992996501048809123U;
            aOrbiterE = RotL64((aOrbiterE * 13273544260537223797U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12057768808864451929U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4115362079047921130U;
            aOrbiterB = RotL64((aOrbiterB * 12263015903331031345U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 15297384955502206698U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17623548383481905636U;
            aOrbiterD = RotL64((aOrbiterD * 7487278217901483685U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3559213898000162417U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12311605719074507335U;
            aOrbiterG = RotL64((aOrbiterG * 3982199462062847697U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14807313864347885885U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11222085523291581822U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12580941911587215653U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 28U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 43U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterC, 35U)) + aPhaseHWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterE, 18U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 51U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
