#include "TwistExpander_Fencing_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Fencing_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x99CE83305A2BD57FULL + 0xC7AA764B8ECFADDAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC058709C22F8D577ULL + 0xEC64B2E9E304E651ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB65D9912E0E9AAA5ULL + 0xCD7FC63ED2AFE33AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE76B021FB0C9E21FULL + 0x84260494DA2AFFCDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9A3D7AA1F8E91345ULL + 0xDC7DB545168335EBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDEBD70E98D791C77ULL + 0xE324CEFEEC5F7687ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA8E3AC729064211BULL + 0xB28540E5FD998A2EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD05091DEC7345C87ULL + 0x90C5407B0861559DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBAA73DB74A75A907ULL + 0x9EAE713EB00284F3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB936764E152A6B57ULL + 0x8EE67BBFF861E2EAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDA78F440276442BFULL + 0xEAD694F64FF62B67ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA3FA1BF6428777CBULL + 0xF26996F62D609A09ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA594E6AA3ABF97AFULL + 0x81FEF192FB4526D4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA6DA4CE9FF429B65ULL + 0xF9C38B9F55FB8A9EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCDA5769F4988E6E7ULL + 0x9FE09422266DA764ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8921F8843C9545E5ULL + 0x88B35EFA0C42FBFAULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1240U)) & S_BLOCK1], 22U) ^ RotL64(pSnow[((aIndex + 1369U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2954U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 2011U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 36U) + RotL64(aCross, 21U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aIngress, 28U)) + 5088525177670191619U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 9966456257813932112U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 21U)) + 7707646574027146307U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 75480203757681173U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 24U)) + 384659134071835163U) + aNonceWordL;
            aOrbiterB = (aWandererF + RotL64(aIngress, 11U)) + 3158769775373307778U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 5U)) + 17360830943513941272U;
            aOrbiterA = (aWandererH + RotL64(aCross, 35U)) + 5317278822721604586U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 1371427105215954781U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aScatter, 41U)) + 3162710551223553423U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 19U)) + 5332921933853550756U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10572462410297815854U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10234389605554817892U;
            aOrbiterD = RotL64((aOrbiterD * 2130374833440291193U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 13421365517991380605U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 10186643614984034083U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 8554471709467808453U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4742438973260817120U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6081590345899008846U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7069396301823124931U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 15360092808493795340U) + aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12186413069553132646U;
            aOrbiterH = RotL64((aOrbiterH * 3815981440611914267U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16756221656224451552U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12232880965861373143U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 14196910735715726471U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10090954323470840557U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15615770271463853537U;
            aOrbiterK = RotL64((aOrbiterK * 13544181592829027283U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 556029032505658411U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13311879111583579039U;
            aOrbiterG = RotL64((aOrbiterG * 3924744868168749003U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8646360871497847336U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2064833941982069154U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10016546852137913163U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1701847261278886621U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9654208200019718374U;
            aOrbiterI = RotL64((aOrbiterI * 4398089490129603677U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14276143262844412074U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10738184916176200661U;
            aOrbiterA = RotL64((aOrbiterA * 8940267914440361883U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2966052720680305600U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5088525177670191619U;
            aOrbiterC = RotL64((aOrbiterC * 11621585388684456139U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 50U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 60U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 11U)) + aOrbiterD) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 19U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 52U) + aOrbiterK) + RotL64(aOrbiterE, 27U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 58U)) + aNonceWordF);
            aWandererJ = aWandererJ + ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterK, 43U));
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 44U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6668U)) & S_BLOCK1], 26U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10633U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 7596U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneA[((aIndex + 6986U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 22U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 17711946802293254150U;
            aOrbiterA = (aWandererE + RotL64(aCross, 58U)) + 16652362590489569378U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 39U)) + 6972810344198183097U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 51U)) + 13117100889782940546U) + aNonceWordM;
            aOrbiterC = (aWandererF + RotL64(aCross, 41U)) + 13199305696782626591U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 35U)) + 992156184392760945U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 11U)) + 13791265442074543880U;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 43U)) + 17057087245252294859U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aCross, 44U)) + RotL64(aCarry, 5U)) + 13444195995883541046U) + aNonceWordO;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 19U)) + 6723678233676059420U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 53U)) + 7913379431208430475U) + aNonceWordP;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4481887195529300665U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11892724101424384078U;
            aOrbiterB = RotL64((aOrbiterB * 3468639499716604111U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7700902083270424194U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 1888001433557140271U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8975562955027025349U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14996753906788986929U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 939004845422123765U;
            aOrbiterC = RotL64((aOrbiterC * 2507090308972292313U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11922230289291941807U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15681187459741147199U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10124947739653819101U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9119043713532718155U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8327697433992362166U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 11157657162184304567U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13630755116592440359U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 771252613886022889U;
            aOrbiterD = RotL64((aOrbiterD * 2958918915223536519U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8524239721467527770U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17732617735422435572U;
            aOrbiterJ = RotL64((aOrbiterJ * 13992947983987668631U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5265753270696005619U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14456128349522985053U;
            aOrbiterG = RotL64((aOrbiterG * 5406509991740849617U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12909993509014176457U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10113568710432654194U;
            aOrbiterE = RotL64((aOrbiterE * 6857806395910432831U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14818978163348513071U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17843349910031998923U;
            aOrbiterH = RotL64((aOrbiterH * 13608449524810499593U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12589077818524017161U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17711946802293254150U;
            aOrbiterF = RotL64((aOrbiterF * 9454569713107675231U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 5U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 44U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + aNonceWordF);
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterH, 39U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 34U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 42U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterC, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererH, 34U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13073U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 16199U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 14262U)) & S_BLOCK1], 36U) ^ RotL64(pSnow[((aIndex + 14174U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 18U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 8020711767807230555U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 5U)) + 15368693777246341570U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 18U)) + 5117523734225562401U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 37U)) + 13155269151097507808U) + aOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 9879303753623578272U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 53U)) + 1165799257173794826U) + aNonceWordH;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 3U)) + 930641942062732091U;
            aOrbiterE = (aWandererF + RotL64(aCross, 41U)) + 11330571332221123153U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 12U)) + 2862963158282518899U) + aNonceWordK;
            aOrbiterH = (((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 47U)) + 6019186399361476659U) + aNonceWordE;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 23U)) + 1924419843785161958U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12618629043591380461U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9334176504266512405U;
            aOrbiterJ = RotL64((aOrbiterJ * 18239109235362925739U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 16829692481030013551U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5604784396927022709U;
            aOrbiterF = RotL64((aOrbiterF * 2833893610883508353U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16124030106598549644U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16571659812830230677U;
            aOrbiterI = RotL64((aOrbiterI * 4668250364992383549U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15171089673591843703U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2826755560293849328U;
            aOrbiterB = RotL64((aOrbiterB * 9397017963457655287U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9976785768283589291U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11845100564714691809U;
            aOrbiterE = RotL64((aOrbiterE * 4935139932585319251U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7318560453127859950U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3039196878830506712U;
            aOrbiterH = RotL64((aOrbiterH * 3140508261330698717U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8850992055588337843U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 4219373528176869146U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 1310964742529956743U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1341474458715938799U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15937557372891732898U;
            aOrbiterD = RotL64((aOrbiterD * 11437307017920192915U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7512741986101399499U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4304636545688233645U;
            aOrbiterA = RotL64((aOrbiterA * 1948671766238131953U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11460886069492094055U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 2019818350627642126U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9802784763505584769U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3190374588085859096U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8020711767807230555U;
            aOrbiterK = RotL64((aOrbiterK * 12055760672321414929U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 56U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 24U) + aOrbiterC) + RotL64(aOrbiterF, 41U));
            aWandererK = aWandererK + ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 19U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterB, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterE, 39U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 11U)) + aOrbiterC) + aNonceWordJ);
            aWandererB = aWandererB + ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterG, 51U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterC, 46U)) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16477U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 19084U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17933U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 19802U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 38U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 5U)) + 12206125048349568300U) + aNonceWordH;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 46U)) + 5843520589343188818U) + aNonceWordB;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 43U)) + 12195046124287121687U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 39U)) + 16769779119214020640U) + aNonceWordI;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 5257603646260695833U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 19U)) + 8523523946234886745U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 51U)) + 7316024684200084096U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 37U)) + 11996978575084115207U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 11U)) + 15491711479085513628U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 6036648530996821484U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 3U)) + 926323222234121863U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2700323841295743492U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5852273765810284935U;
            aOrbiterB = RotL64((aOrbiterB * 16665696735016345215U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11697397483133538067U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 17777142964957007194U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6338967222543284999U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10892176201151170298U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11759700374509499684U;
            aOrbiterD = RotL64((aOrbiterD * 14247697264744736081U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11343756773329590643U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15785048929757652350U;
            aOrbiterE = RotL64((aOrbiterE * 17208103574389502597U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7508839228498497238U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13088508510402094665U;
            aOrbiterI = RotL64((aOrbiterI * 15730279447009669103U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16259236641717377699U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11228995722951003980U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4870092259515181323U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13775851561528617086U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3023564646900497080U;
            aOrbiterG = RotL64((aOrbiterG * 9936548213275464131U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 154952467284609583U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14239675888632174461U;
            aOrbiterC = RotL64((aOrbiterC * 1370550680736926425U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 168749514558708557U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 5070416708211422927U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13631900152346927703U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1961290602001581341U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12235345489656113478U;
            aOrbiterA = RotL64((aOrbiterA * 14403534235273302211U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2295581049708176078U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12206125048349568300U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 6008868846674396181U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 56U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterF, 21U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 37U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 44U) + aOrbiterG) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterE, 56U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterK) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 60U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aPrevious, 26U) + aOrbiterD) + RotL64(aOrbiterE, 11U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordM;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26116U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 25244U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22665U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 25602U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCross, 20U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 29U)) + 6318740973868639425U) + aNonceWordO;
            aOrbiterG = (aWandererG + RotL64(aCross, 35U)) + 5487840061430920881U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 10258706763248072672U;
            aOrbiterE = ((((aWandererB + RotL64(aScatter, 38U)) + RotL64(aCarry, 27U)) + 18356875269730338208U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aWandererK + RotL64(aIngress, 13U)) + 12883160282903147010U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 23U)) + 1010140474942697730U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 41U)) + 17733939421700898293U;
            aOrbiterC = ((((aWandererE + RotL64(aCross, 50U)) + RotL64(aCarry, 47U)) + 13693055887924981201U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 19U)) + 14574732452793385269U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 27U)) + 10832873941223609012U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 5U)) + 8212600587135328040U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5312744319781971178U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6173741211706546923U;
            aOrbiterK = RotL64((aOrbiterK * 12854414066390848249U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3693249147883790810U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 18365859989736602556U;
            aOrbiterD = RotL64((aOrbiterD * 3348463719324104997U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10645056678337549771U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1175668356822251045U;
            aOrbiterC = RotL64((aOrbiterC * 6579675292775345579U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 13556844570541823717U) + aNonceWordH;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 4790355739411849736U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 4083544011788850307U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14905575502272644116U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17047244574558476634U;
            aOrbiterJ = RotL64((aOrbiterJ * 2356386971503880047U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10161614295718414869U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13413914082651612468U;
            aOrbiterE = RotL64((aOrbiterE * 16224039093981079491U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6072693130156927774U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4333656233793103787U;
            aOrbiterF = RotL64((aOrbiterF * 9374745547133955709U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17209776289202130250U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11752001118070361543U;
            aOrbiterI = RotL64((aOrbiterI * 4416523594812872339U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15367365111105608277U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 8650687767097460704U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11430451559660578667U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 18074648514448405693U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10857586858462237581U;
            aOrbiterG = RotL64((aOrbiterG * 3722891011080095849U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17219932344278345591U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 6318740973868639425U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8846295038878812229U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterG, 46U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterK, 27U));
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterK, 5U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 42U) + aOrbiterB) + RotL64(aOrbiterD, 19U));
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 53U)) + aOrbiterA) + aNonceWordP);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterC, 37U));
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 57U));
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterD, 34U)) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 41U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29877U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30541U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30567U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32561U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aCross, 56U) + RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererI + RotL64(aIngress, 5U)) + 5131645209694953015U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 23U)) + 12070391048835379854U) + aNonceWordJ;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 2604295836242338724U;
            aOrbiterB = (aWandererC + RotL64(aCross, 48U)) + 14042039029284001596U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 39U)) + 8914654543854559327U;
            aOrbiterA = (aWandererA + RotL64(aCross, 3U)) + 2185619407969359869U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 5187406295103352574U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 27U)) + 8022832481290871217U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 43U)) + 8783061916740573472U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 58U)) + 10711028365596196301U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 43U)) + 13387065038269133571U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11187001318931801582U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 14191473173276034019U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2491253922434756431U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16207761776716426435U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9677408414452078760U;
            aOrbiterE = RotL64((aOrbiterE * 5487303383095129949U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17812460332794370649U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7736423148554132028U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15588733747232852555U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17293203944059014763U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13487243633338010243U;
            aOrbiterF = RotL64((aOrbiterF * 9468688858740539095U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 15979293016815060755U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17645215484691359547U;
            aOrbiterJ = RotL64((aOrbiterJ * 1449450767288733995U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 11635961468586927692U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10530136578329059784U;
            aOrbiterD = RotL64((aOrbiterD * 8785021493374398437U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4900370530116992731U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15952900504821599445U;
            aOrbiterC = RotL64((aOrbiterC * 5413316082800365261U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9938000151832814778U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14170277411106520726U;
            aOrbiterK = RotL64((aOrbiterK * 5058343552974910737U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14091010427448547620U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13658560822164111421U;
            aOrbiterI = RotL64((aOrbiterI * 9523184040517290629U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13954269172267844623U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3921811946419945868U;
            aOrbiterH = RotL64((aOrbiterH * 6839440867046147039U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14296483810577739898U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5131645209694953015U;
            aOrbiterB = RotL64((aOrbiterB * 10190969526209064367U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 18U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 23U)) + aOrbiterG) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterC, 28U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 42U) + aOrbiterI) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 5U));
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterD, 13U));
            aWandererG = aWandererG + (((RotL64(aCross, 36U) + aOrbiterD) + RotL64(aOrbiterE, 37U)) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 21U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterF, 40U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ aNonceWordO;
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

void TwistExpander_Fencing_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xED45F493686D2C0BULL + 0xFA4E62DA18AE43ACULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x86613F98007281F1ULL + 0xD30E906275E3260CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC6ECEF26BB33EB45ULL + 0xFA780281F07F5884ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA3A7011604F51F69ULL + 0x8259711C5E6BDF24ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFC480ADD9F75E479ULL + 0x9DCDA25FB30E04F6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD815682788E484EFULL + 0xA9DE62EAEB6F47CCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD8BDC674D837C57DULL + 0xA50A7AC12081A87EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x924A195EAC2AF6C9ULL + 0xA02270AE8D8978F7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCB4909917DC4D2DFULL + 0xF55CCCFE31CBCD22ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAF95309D6DB27A0DULL + 0xDBAC89190710F515ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFF6398D42629F7ADULL + 0xCD3C15D2DF35E477ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAAC71AA47D30CD83ULL + 0xBCFBF8DA760D42E9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE55E04EFA417FEA3ULL + 0xF61B60CD6903FCA1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCFE8AD3B69947B31ULL + 0xDFDB460C5BBAA12CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9866E942B50F6A2BULL + 0xEE62DF11E3AE8585ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD2B1DA0E304D5AE5ULL + 0xB2AEB870C49C9368ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1250U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 858U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7011U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7480U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 29U)) + (RotL64(aCross, 12U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererJ + RotL64(aCross, 6U)) + 14249093584376402677U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 53U)) + 8756965951816492264U) + aNonceWordF;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 39U)) + 11221139480258176330U) + aNonceWordD;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 17218894445564194851U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 27U)) + 8064642692524949490U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aCross, 18U)) + 5822093203710704646U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 47U)) + 3217799620158102238U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 2613757677892120843U) + aNonceWordG;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 13647481499551657237U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3545714196663685016U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9735422670576621521U;
            aOrbiterJ = RotL64((aOrbiterJ * 7276207208162697249U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3911046580637583767U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9315984027042049203U;
            aOrbiterE = RotL64((aOrbiterE * 12568550776487242469U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8926367674641729058U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11035347490524961446U;
            aOrbiterI = RotL64((aOrbiterI * 10948288997163592463U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10748158733051120339U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2467801787989056455U;
            aOrbiterG = RotL64((aOrbiterG * 12621934274702358977U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9244415080474351390U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8517784887959492079U;
            aOrbiterB = RotL64((aOrbiterB * 17022899813765884147U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8409307332803038455U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11043806021873232950U;
            aOrbiterH = RotL64((aOrbiterH * 8294888329708842989U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17512395828450251457U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16849067939795823992U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9361991804481514337U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17541946638063238056U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11430501673960586718U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 15074409630605450091U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 78307505705383302U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4834528975263832983U;
            aOrbiterF = RotL64((aOrbiterF * 17245673681686752861U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 58U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterF, 35U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 43U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 48U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterC, 29U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 52U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterA, 11U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16198U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11906U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8521U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8365U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 44U)) ^ (RotL64(aCross, 13U) ^ RotL64(aIngress, 29U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererJ + RotL64(aIngress, 4U)) + 3650233661228036955U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 11607036400067735729U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 29U)) + 3899614406903883035U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 8159156925629965143U) + aNonceWordJ;
            aOrbiterC = (aWandererK + RotL64(aCross, 23U)) + 7148903913967261270U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 34U)) + RotL64(aCarry, 13U)) + 9161665622287517848U) + aNonceWordF;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 39U)) + 2981535013474059469U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 19U)) + 15812469008200319549U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 57U)) + 14687469489893270300U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6025209349511417063U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12964750392311112676U;
            aOrbiterD = RotL64((aOrbiterD * 12955480283032701843U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6572355895765394340U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3542300121890027981U;
            aOrbiterC = RotL64((aOrbiterC * 11201491178181273935U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6477175684045398359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1081388388827929314U;
            aOrbiterE = RotL64((aOrbiterE * 8752188637514143529U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 13754328481584620771U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3684673342659575917U;
            aOrbiterB = RotL64((aOrbiterB * 6139923312873039143U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6542045150319909445U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5352102692424060388U;
            aOrbiterJ = RotL64((aOrbiterJ * 7385758355501860261U), 19U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 9110100774657340354U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 2813273684436269057U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10468759062594022273U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5860425751137403755U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 1598622981888978548U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 651816500461718345U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14710305692377606725U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16280545617802383463U;
            aOrbiterA = RotL64((aOrbiterA * 12541767206978802063U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6849565243667718750U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12152381961996750050U;
            aOrbiterI = RotL64((aOrbiterI * 11185935780063403807U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 18U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aScatter, 34U) + aOrbiterC) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterF, 11U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 24U)) + aOrbiterE) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 20U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20270U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16631U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21840U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24301U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 4U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererI + RotL64(aPrevious, 21U)) + 3105313968748067810U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 58U)) + 9977249451119627064U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 17941392803495349366U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 4279533326705471133U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 13U)) + 13983828966811580039U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 51U)) + 3983490984234810378U;
            aOrbiterE = (aWandererK + RotL64(aCross, 38U)) + 308786542215259956U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 8443607695364427037U) + aNonceWordF;
            aOrbiterG = ((aWandererF + RotL64(aCross, 47U)) + 14939626441464340668U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9350693577306121110U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 1717071159396961752U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11062480662625054525U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15911765265202100610U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14898546272333182767U;
            aOrbiterI = RotL64((aOrbiterI * 2674900543810733067U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3560903518513465868U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5367062725726860234U;
            aOrbiterC = RotL64((aOrbiterC * 8521908836601319553U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 15233321480618877327U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9288449812290126074U;
            aOrbiterB = RotL64((aOrbiterB * 6815298520404038519U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5504840529511585676U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6825598386801620046U;
            aOrbiterK = RotL64((aOrbiterK * 11666542445846250077U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6433024450721339470U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 97934156644929458U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8630530773006923215U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3260053604798744515U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16539416623243059076U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 12199577351166064503U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9814290051339038920U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13280156404507444041U;
            aOrbiterH = RotL64((aOrbiterH * 15269010043398910061U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11853942590993546833U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13207869904312989977U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15503461937625795969U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 22U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterG, 11U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 36U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 19U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterE, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterK, 41U));
            aWandererF = aWandererF + ((RotL64(aCross, 14U) + RotL64(aOrbiterC, 48U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 3U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 51U)) + aNonceWordE) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 53U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28015U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24924U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26050U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 31495U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 6U) + RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 15316464782468770057U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 60U)) + 6642872057476351588U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 27U)) + 660732654689529192U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = ((aWandererA + RotL64(aCross, 3U)) + 7235418086884000655U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 35U)) + 14784518476694580493U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 43U)) + 12222433977933449375U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 39U)) + 8573001207708329927U) + aNonceWordF;
            aOrbiterC = (((aWandererC + RotL64(aCross, 52U)) + RotL64(aCarry, 53U)) + 16035256260815013172U) + aNonceWordN;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 15767726974121910203U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17712217935322939971U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13488963456923357159U;
            aOrbiterH = RotL64((aOrbiterH * 16785285630840310405U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 10222949131965611079U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 1495561412321657209U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9706305581868526265U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 16156530750584361434U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7773792489045606309U;
            aOrbiterG = RotL64((aOrbiterG * 10730624207715601393U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11544578291333360613U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3665587867634242865U;
            aOrbiterJ = RotL64((aOrbiterJ * 4840528190844842595U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15248434984650998090U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15487979645426567581U;
            aOrbiterE = RotL64((aOrbiterE * 10868107809356766183U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6972347795052712690U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 16074994810010431338U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1262655238856775853U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16851139687900415292U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14630026837021552812U;
            aOrbiterC = RotL64((aOrbiterC * 9577900853521254603U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14236330619137368169U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17778707026111136216U;
            aOrbiterA = RotL64((aOrbiterA * 16239561893843454747U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9390961969105999083U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1174881758316573228U;
            aOrbiterK = RotL64((aOrbiterK * 6602061268277529311U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 6U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterC, 48U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterI, 57U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterD, 23U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 48U) + aOrbiterD) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 29U)) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + aNonceWordH);
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 39U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 58U) + RotL64(aOrbiterI, 27U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_Fencing_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEDFF2A857CEB0F01ULL + 0xE9AEEF49E0BB489EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF1E9C0D210F19829ULL + 0xBC4666245697C24AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x86BEB852479CE441ULL + 0xE45F3C8DC4F2A733ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFE4A3C46AF5AC827ULL + 0x8AC77D5A6D06BA04ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA29E9EC611DCCB81ULL + 0xE241E2BF3FC5E0F2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9A82E2D1C77A28B3ULL + 0xF10A451E3BA35973ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA4591CB294E8F167ULL + 0xBA9DC5AA8177410FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF568D251D9DEC9A5ULL + 0x8F5597A76FC95177ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9A6A7947FE679551ULL + 0xBDD7DE1D53758BB7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x88F37F52BC39F93FULL + 0xCAC79B6FB1A8E43EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFF9BC8BDE435332DULL + 0xCF7B68B06A52CC56ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF968C83CD5BE6D6DULL + 0x8FCABE3FC89E0ECDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE9C039D316621879ULL + 0xA737454431B6511EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x83CC5FD8ECE6905FULL + 0xC8CBB7591FAF1870ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9AFE932D74283FEBULL + 0xFDCA22557A9CFEC2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x89818168F6BF2EF5ULL + 0x8930CE3CBC40759EULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2485U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 2246U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6393U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 3180U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 8975885703279267062U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 37U)) + 8664844915562660637U) + aNonceWordP;
            aOrbiterC = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 12281774799736296726U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aScatter, 6U)) + RotL64(aCarry, 37U)) + 15347461352311329726U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 47U)) + 12967500561828907834U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5002833859280402726U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11908257536954668983U;
            aOrbiterC = RotL64((aOrbiterC * 4384790916151202785U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 17017174811949227162U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16851323125613931180U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12446990992858763577U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13469326957728686706U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5228638551056105241U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 13369947664646167255U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11945166198089308564U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16268645041872996022U;
            aOrbiterJ = RotL64((aOrbiterJ * 5391448793718370911U), 27U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 14781204627695095701U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 5365325354838101092U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8017284997946310807U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + aNonceWordB) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterC, 11U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ) + aNonceWordL);
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterH, 36U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8396U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13709U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10558U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((aIndex + 12426U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 23U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 38U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 17912271996338180948U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 34U)) + 13259276608841847058U) + aNonceWordC;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 5U)) + 16225936008657276089U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 2243058962151834071U) + aOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 10637439274127347861U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 15312219216405992627U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2393933972129878613U;
            aOrbiterG = RotL64((aOrbiterG * 13147717214387593761U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4327069337247976513U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8307656353434167837U;
            aOrbiterF = RotL64((aOrbiterF * 11386588389133096705U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17299145556933889336U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 14458100581172798164U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 16543734663677070509U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6410095654927998067U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6168964796264687686U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16218071040190475953U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3667999465041020730U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 16021552859323602007U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6427266472526362663U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 56U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 20U) + aOrbiterA) + RotL64(aOrbiterE, 10U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterE, 27U)) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 19U)) + aOrbiterF) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 35U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 53U)) + aOrbiterE) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19014U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22109U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23506U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 21767U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 56U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 13U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 19U)) + 18191288703716505885U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 4U)) + RotL64(aCarry, 43U)) + 9824014524910417136U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 57U)) + 11953012029254917548U;
            aOrbiterD = ((((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 6297568011027199089U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 2576999400457367975U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13176139160575558254U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9978408174563621810U;
            aOrbiterK = RotL64((aOrbiterK * 1399052522159751531U), 27U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 16765834875061607142U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16534507305459121344U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 8943988574248229067U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3114710944346151807U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10240517868726718592U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4645691562915606463U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10721450637990777883U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16689590768796583952U;
            aOrbiterD = RotL64((aOrbiterD * 3046344179729901637U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2427422768928450209U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13495584061816457831U;
            aOrbiterH = RotL64((aOrbiterH * 6670984773768885119U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterC, 35U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 21U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterK, 43U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aScatter, 58U) + RotL64(aOrbiterA, 4U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aNonceWordP) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterD, 57U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30828U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 31599U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30206U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28430U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 43U)) ^ (RotL64(aCross, 13U) + RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererG + RotL64(aCross, 37U)) + 15813325389431304548U) + aNonceWordM;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 56U)) + RotL64(aCarry, 41U)) + 2223874171125403602U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 5510483568496824130U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 15474152493495661876U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aScatter, 13U)) + 16846339705130829195U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1289670576865739669U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 18017354919647006944U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13103155460891498469U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8539685539928984921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3333721400836704048U;
            aOrbiterB = RotL64((aOrbiterB * 3745286323481400085U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 2261560416623815491U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 4377786131746816567U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 9164777834392621157U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 18047393176583722719U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8184724021940434631U;
            aOrbiterI = RotL64((aOrbiterI * 9800116157750921119U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10469895939183324807U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14543391765109879223U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4817987697437667225U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 41U)) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 23U)) + aOrbiterK) + aNonceWordD);
            aWandererI = aWandererI + ((((RotL64(aScatter, 50U) + aOrbiterK) + RotL64(aOrbiterC, 40U)) + RotL64(aCarry, 3U)) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordL;
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

void TwistExpander_Fencing_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD1F28F25C0B442E7ULL + 0xB6D5D0B232A52F64ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAFE35CD342A46883ULL + 0xD269198FCC53DF42ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD4F10DC5DB49A5A9ULL + 0xE9ECDFE41FF7A919ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x84270819E0A6C81DULL + 0xF10E2E5E7A7D19D4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA39F607416E283B7ULL + 0xC6043EFB4801548FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA2C6B464BBCA391DULL + 0xAFAB5BA0422AC85AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFA8287F903864A1DULL + 0xC362F10BBBF34AC8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8B8DF3D2BEFB65CDULL + 0xAAC221BA6950BCE2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x89C562A420028E39ULL + 0x93019A81207B6A8BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDDB5E7CD2A82B5B1ULL + 0xCD2CFB179BAB23ADULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB35F0F2DEA10CCAFULL + 0x80CDBDD2363B75CEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC19914A94269CC1DULL + 0xE092250F768E006BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB383390AC5F76B77ULL + 0xAB31D25442FFBB36ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA3D7E773DAD13BFBULL + 0xEF2146B5AF390636ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF44F626AFC570125ULL + 0xE9D71C421E3BA121ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC5103C1F06E42485ULL + 0xB4B6E3F46DA4675CULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5363U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 1405U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3558U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 1946U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 44U) + RotL64(aPrevious, 23U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 9133751643283278896U) + aNonceWordI;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 35U)) + 8971581804375380408U;
            aOrbiterF = (aWandererG + RotL64(aCross, 3U)) + 12559650383714566592U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 51U)) + 15753206088872859163U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aCross, 20U)) + 7640756270450762350U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 7340073357551376125U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 5270256573644196046U) + aNonceWordC;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3567367996479995928U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11939634537492733738U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5640541900117183639U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7051817732424527120U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 1730487669951837941U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 15191634337956285841U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 18009252467909454817U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2361024272031696442U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 15215151562500226027U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15902755877642960397U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12243517544704116184U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2576071074148141447U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 16846181962302186187U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 636121425116506681U;
            aOrbiterB = RotL64((aOrbiterB * 17075030673338779993U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 6887385655828217318U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3705834550934775862U;
            aOrbiterD = RotL64((aOrbiterD * 11275428284929594435U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11165142437077969438U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6426659930331618269U;
            aOrbiterC = RotL64((aOrbiterC * 17170640810530893705U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 5U)) + aOrbiterF) + aNonceWordM);
            aWandererG = aWandererG + (((RotL64(aScatter, 10U) + RotL64(aOrbiterB, 19U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 58U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 43U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterK, 29U));
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 35U)) + aOrbiterD) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13676U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 13687U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12332U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 11949U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 50U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 18302975933754610273U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 20U)) + 16736972646771456082U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 29U)) + 17389406266488137442U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 5252511566486165539U) + aNonceWordA;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 51U)) + 5730715427422747640U;
            aOrbiterJ = ((((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 6412695646456045825U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererI + RotL64(aScatter, 13U)) + 9539701605708994494U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 18355107116412945722U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11735742491750132942U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 18129835093627763685U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12363819388562658842U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5861430292304371543U;
            aOrbiterC = RotL64((aOrbiterC * 12989055611235382695U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15027487084595017708U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7012850020745791926U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 15952928839355613939U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 11904871669287886120U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11199760114477343208U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7156374911847525867U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3856004502263742700U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3705931243173921893U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10334871178498711485U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12305785390539209389U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 18057980996551978823U;
            aOrbiterJ = RotL64((aOrbiterJ * 4850564181113470859U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3229431819292153014U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2994716629242460094U;
            aOrbiterF = RotL64((aOrbiterF * 1029427328395257917U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterK, 47U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterK, 41U)) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 56U) + aOrbiterF) + RotL64(aOrbiterC, 60U));
            aWandererF = aWandererF + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 3U));
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordG;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20968U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16485U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19364U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 18386U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 22U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 13687218104610230596U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aCross, 35U)) + 6841550124960692709U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 21U)) + 17418968668458764131U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 56U)) + RotL64(aCarry, 39U)) + 8303537912696948204U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 47U)) + 12376614417285936537U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 5U)) + 14215749063579232654U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 4111736931433665347U) + aNonceWordO;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11250375934571631522U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5367367837773331275U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 7262723007545807179U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 15514089192382674434U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1475991716685034960U;
            aOrbiterC = RotL64((aOrbiterC * 17720681295551650891U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5531622777788629748U) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8363822215908303335U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17850203366840994883U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3741256932685720414U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11634667238062155772U;
            aOrbiterD = RotL64((aOrbiterD * 15925089729784547403U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 18180546911210417155U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 5123234656838556335U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 15362857462853398025U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11215734271189250284U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16863747802158398092U;
            aOrbiterE = RotL64((aOrbiterE * 1828035970246160023U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9859050606636646323U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9331300036643654675U;
            aOrbiterH = RotL64((aOrbiterH * 2502263410556166281U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterC, 11U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterC, 21U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + aNonceWordN);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29968U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32609U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30399U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 30529U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 50U)) + (RotL64(aCross, 35U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aCross, 5U)) + 1210605127156905516U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 58U)) + RotL64(aCarry, 11U)) + 11964595428173569519U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 19U)) + 16277319029916258482U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 37U)) + 12369497463101824572U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 6201248574067068202U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 51U)) + 1727477025667206661U) + aNonceWordD;
            aOrbiterJ = ((((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 1404510627789806851U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6948213591282018925U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6688865181284421478U;
            aOrbiterC = RotL64((aOrbiterC * 12619122841662247279U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3351130769402360855U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12681032488906270823U;
            aOrbiterH = RotL64((aOrbiterH * 3680893896579741263U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3591412591193726763U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 16153817571210878589U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 4165137036092246349U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3808228354421006630U) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1427373776207504205U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4534374093769595531U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 1831554180932501132U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1114853085120949215U;
            aOrbiterG = RotL64((aOrbiterG * 4264176108298812905U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2080935638828366835U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16104777999646489828U;
            aOrbiterB = RotL64((aOrbiterB * 15205199362011777473U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9782806013673440791U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3721620299829386454U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6286765834910272409U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterG, 22U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterC, 57U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterC, 29U)) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 30U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 42U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_Fencing_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDE588EB5611FBF97ULL + 0xD666BDCCC6CE3A8BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF645BC14A50227D7ULL + 0xDA34A2C12355CEA1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFD0CF3C3FD0849CBULL + 0xFEA1E2BC8A0D8AD7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF9210463938D5901ULL + 0xDF97207DB896FF3DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBAE238AF9E4E4837ULL + 0xE2DB22A83B137369ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC3F967A63AA34DFDULL + 0x9CC95C8EA83248D2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x87017CDDD660AC4BULL + 0x957A49C03692B37EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8FF60BFF092B7381ULL + 0xF5A06041FB053E21ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD094D28AF1EFE1FBULL + 0xA45082149A817E51ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB4DE6F1993F7F3EDULL + 0x8271EBA3D51C5729ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBDE35F35ED6074A5ULL + 0x9682D80CB006602EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB59B768B9DE363E1ULL + 0xB8190BD781E3913DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC4987E3BEBC2244DULL + 0xBF5E6DCC1436B746ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8786EB1CDA2505B3ULL + 0xD63E24A2B108BF8BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD1398970F7257001ULL + 0x8371A3A472ACA2D6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCCB23A37D1D2DA01ULL + 0xC74ECD601E5C68FDULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2645U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 2080U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5209U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((aIndex + 65U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 15383045568644941552U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 41U)) + 17452811657750910067U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aScatter, 11U)) + 15660117718455155603U) + aNonceWordC;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 18U)) + RotL64(aCarry, 41U)) + 10396441207743665753U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 3U)) + 3708971058200841442U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aIngress, 29U)) + 7000673057768598750U) + aNonceWordN;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 9886354469011131596U) + aNonceWordG;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16018065329058043467U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5024756166109352320U;
            aOrbiterK = RotL64((aOrbiterK * 11660932185479046483U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 6587818720728886652U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 3652672354944162319U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10807121230791716109U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6307315649915348048U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 16405347331742979258U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 7183142442906743699U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5427299664054601957U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4983381733483185898U;
            aOrbiterJ = RotL64((aOrbiterJ * 14646556236306407673U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10182995521328377487U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8694282877540593550U;
            aOrbiterI = RotL64((aOrbiterI * 14614602561910403893U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4085927978153269932U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6176195962815240877U;
            aOrbiterC = RotL64((aOrbiterC * 16792916528959579875U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6966742100601433005U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 9920952446921247521U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 1879821050131820933U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterA, 18U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterE, 35U));
            aWandererD = aWandererD + (((((RotL64(aCross, 10U) + aOrbiterI) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 57U)) + aNonceWordA) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 18U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 22U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 15720U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 13292U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10284U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15994U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCross, 27U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererB + RotL64(aCross, 41U)) + 4204560462077827182U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 3U)) + 6572370199668594039U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 12U)) + RotL64(aCarry, 35U)) + 15958999876732622825U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 35U)) + 9969349486879280377U) + aNonceWordP;
            aOrbiterI = (aWandererA + RotL64(aIngress, 21U)) + 15450238998293956181U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 9128619863683138259U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 5691270563628979565U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5901029710568933106U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 10442738941988588834U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 7386621444831603817U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3508116020325721993U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13221917083569767259U;
            aOrbiterG = RotL64((aOrbiterG * 6845108555710135357U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11627915460377128176U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 17858261365514253433U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 7535577636975884641U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4294837988806295989U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 11242915481585070249U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17540688242763829319U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 13030663829236027109U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 7451948220723185149U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5191778587712222029U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5575508866505031037U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5161096033789876794U;
            aOrbiterB = RotL64((aOrbiterB * 16843827915802461797U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3980482740649505122U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11188906150207270241U;
            aOrbiterD = RotL64((aOrbiterD * 408550837615188413U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterB, 5U));
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 53U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + aNonceWordH) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 14U) + aOrbiterB) + RotL64(aOrbiterI, 46U));
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 19U)) + aOrbiterB) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22483U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19317U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22576U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 18439U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 12311607308490066301U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 13100864684740679846U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 13697304189274329704U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 29U)) + 9047976902871216732U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 35U)) + 2147897579538537888U) + aNonceWordD;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 43U)) + 2072444829390996142U) + aNonceWordL;
            aOrbiterA = (((aWandererA + RotL64(aCross, 50U)) + 2129307836981020908U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10663145333751112064U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15019844390503785459U;
            aOrbiterE = RotL64((aOrbiterE * 7442321463110790449U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 5460865577557928142U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15806522559993224197U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8722932687972240099U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6361113778657833389U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8306013884615042570U;
            aOrbiterD = RotL64((aOrbiterD * 8234258702656728667U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4038420580499706912U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11908091484457158973U;
            aOrbiterJ = RotL64((aOrbiterJ * 3964111175645156719U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11133912466611921250U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 2469227904206936928U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2704438771198001599U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 13234017916788297295U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9061117693840451988U;
            aOrbiterI = RotL64((aOrbiterI * 3637440416741459419U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12013423690843812324U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14371779015144617412U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 3359568073302062667U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 46U) + aOrbiterE) + RotL64(aOrbiterJ, 5U));
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterA) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 19U)) + aOrbiterD) + aNonceWordB);
            aWandererI = aWandererI + ((((RotL64(aCross, 29U) + RotL64(aOrbiterI, 13U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 52U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28086U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((aIndex + 25706U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24938U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27130U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 10404808878585437255U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 10587858736301591439U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 5U)) + 1430530909801644435U) + aNonceWordA;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 43U)) + 9090938022430118902U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 35U)) + 12936604311751121235U) + aNonceWordK;
            aOrbiterG = ((((aWandererD + RotL64(aPrevious, 58U)) + RotL64(aCarry, 53U)) + 1000583006020232032U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aWandererC + RotL64(aCross, 21U)) + 12352532088997042232U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 16723410947058502564U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16614089235313154270U;
            aOrbiterB = RotL64((aOrbiterB * 11530998303573027827U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4245553025593349277U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3353146318549477494U;
            aOrbiterG = RotL64((aOrbiterG * 14246377408238318091U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5935727336135635196U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10312187090293319667U;
            aOrbiterA = RotL64((aOrbiterA * 1395964500396711899U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12192843181244744484U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 2542570124502586365U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 17222847847573534963U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3315472769469002444U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17512858811783071174U;
            aOrbiterK = RotL64((aOrbiterK * 9070400454074283765U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16633218007427888082U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2502077714838858460U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 970762420815997725U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14792910273226469214U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15739513291150783151U;
            aOrbiterF = RotL64((aOrbiterF * 11896279674116906915U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 3U)) + aOrbiterB) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + aNonceWordO) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + aNonceWordM);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterD, 19U));
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterA, 50U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordM);
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

void TwistExpander_Fencing_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB6FF6CDCA1121B2BULL + 0x950B34A348211B46ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD7DC551C3DCC2845ULL + 0xCB94269CEDF0C258ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x82C5979505CB2163ULL + 0x8763BDB992BC3BC8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAB78A7B76568898BULL + 0xDABFBBFE2E7DDC61ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9788883455052C61ULL + 0xC005A544D70D4F7FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFB073537707A7C4DULL + 0xF5D31805660D5969ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9B4C4FA4A56B0E89ULL + 0xD2F4D556137D0A3DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA62B69DF2F9E7B19ULL + 0xE53E1A95E98BF17FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x800A91B256793113ULL + 0xF391B10844AD073DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD73BE57E0A2BA503ULL + 0xA53B105DDD8C658EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB6BE394012A8F84BULL + 0xD851411146327066ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB08E18DC877C04CDULL + 0xC3BEDE7B0B17C70CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF1E560A290292559ULL + 0xE6669C2F37937A95ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD2A33A586340671FULL + 0x93029107793542E1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE9FFA2F92B381019ULL + 0x84F8E822DF10A0FDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9F00AE095275AF55ULL + 0xC453CBC855CBE51DULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7862U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 5362U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4702U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 643U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 38U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aCross, 23U)) + 6068543441070417854U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 51U)) + 2995980468193441856U) + aNonceWordL;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 27U)) + 18020277482171594003U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aWandererD + RotL64(aScatter, 21U)) + 4293807434721230702U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 36U)) + 7980599111583893156U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 39U)) + 8593141111851052016U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 47U)) + 5903487523900084325U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 15112035513447930209U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 9854037263057006439U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 34U)) + RotL64(aCarry, 5U)) + 16759760289688823193U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 5U)) + 12622628933030601390U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1264668857268123425U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16302812053619101593U;
            aOrbiterH = RotL64((aOrbiterH * 18291400055836111547U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16087995784896123610U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7970269262800468363U;
            aOrbiterF = RotL64((aOrbiterF * 14924752223305807461U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5331477046030959632U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16534913204255550893U;
            aOrbiterE = RotL64((aOrbiterE * 1013433634373673565U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 11042821902537871209U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8069677512345031660U;
            aOrbiterB = RotL64((aOrbiterB * 13622218526054132397U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5737130058129936372U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1076627182956662997U;
            aOrbiterI = RotL64((aOrbiterI * 14342191224014199929U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13911061091801078190U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15397603151098990373U;
            aOrbiterJ = RotL64((aOrbiterJ * 1802890451633592245U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15137326716738637972U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11248737008959896786U;
            aOrbiterA = RotL64((aOrbiterA * 90789374131547005U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1847847987633923657U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10560748778679145431U;
            aOrbiterK = RotL64((aOrbiterK * 2919333327817231099U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2703726238610290251U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12950671360471467310U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 7490327691501537047U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10331504168520449467U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 1541527607705280906U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14197400812600186171U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9135056476214341809U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6068543441070417854U;
            aOrbiterC = RotL64((aOrbiterC * 14102524444094948875U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 30U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterD, 11U));
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterF, 43U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterA, 28U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterI, 39U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 21U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterB, 13U)) + aNonceWordP) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 24U) + aOrbiterB) + RotL64(aOrbiterJ, 37U));
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterG, 51U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 24U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 12U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererG, 38U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordO);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12091U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9065U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14224U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9772U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 36U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 9855743441035905047U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 48U)) + 8426286937143990276U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aCross, 5U)) + 7146752367170267002U) + aNonceWordO;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 12947210066678101726U) + aNonceWordH;
            aOrbiterB = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 15902163559925328965U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 37U)) + 8506649889346449469U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 19U)) + 8226286036430263052U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 57U)) + 2703047093452420216U) + aNonceWordC;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 29U)) + 6769351326360139560U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 21U)) + 9857025533281333281U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 40U)) + 238297452132277585U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7203572312072908931U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12497027346166575632U;
            aOrbiterJ = RotL64((aOrbiterJ * 1703586436725662307U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 473851890609048879U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1664484956453886047U;
            aOrbiterH = RotL64((aOrbiterH * 8566500756326590209U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4635095143004754116U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17695676150967345793U;
            aOrbiterB = RotL64((aOrbiterB * 5780416541584439301U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15628965269863402796U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 9190117464399730235U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5586437438425999715U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17835918238346011086U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4398005402429282682U;
            aOrbiterD = RotL64((aOrbiterD * 14828737209913317463U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10902589938246551273U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15124274429081385923U;
            aOrbiterE = RotL64((aOrbiterE * 13524180348258805367U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8747233520702236018U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 5445611443463112371U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10294109295823410447U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16296005217836151910U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6468336224317602364U;
            aOrbiterC = RotL64((aOrbiterC * 7369779919748367133U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3827976387089403774U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7773383658122100111U;
            aOrbiterF = RotL64((aOrbiterF * 9784711300597525161U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 18273794621528918389U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8401424792700263455U;
            aOrbiterG = RotL64((aOrbiterG * 13003420427441089595U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11402828934846813949U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 9855743441035905047U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 7339549576423555273U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 60U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 58U) + aOrbiterD) + RotL64(aOrbiterG, 57U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 43U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 46U)) + aOrbiterH) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterI, 19U));
            aWandererC = aWandererC + ((((RotL64(aCross, 23U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterD, 10U));
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterF, 41U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterH, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19385U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19198U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19086U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24067U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 44U) ^ RotL64(aCarry, 29U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aPrevious, 29U)) + 3650233661228036955U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 44U)) + 11607036400067735729U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 39U)) + 3899614406903883035U) + aNonceWordN;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 53U)) + 8159156925629965143U) + aNonceWordB;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 7148903913967261270U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aScatter, 37U)) + 9161665622287517848U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 3U)) + 2981535013474059469U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 15812469008200319549U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 48U)) + RotL64(aCarry, 43U)) + 14687469489893270300U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 11U)) + 6025209349511417063U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 27U)) + 12964750392311112676U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6572355895765394340U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3542300121890027981U;
            aOrbiterF = RotL64((aOrbiterF * 11201491178181273935U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6477175684045398359U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1081388388827929314U;
            aOrbiterA = RotL64((aOrbiterA * 8752188637514143529U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13754328481584620771U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3684673342659575917U;
            aOrbiterD = RotL64((aOrbiterD * 6139923312873039143U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6542045150319909445U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 5352102692424060388U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7385758355501860261U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9110100774657340354U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2813273684436269057U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10468759062594022273U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5860425751137403755U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1598622981888978548U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 651816500461718345U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14710305692377606725U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16280545617802383463U;
            aOrbiterI = RotL64((aOrbiterI * 12541767206978802063U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6849565243667718750U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12152381961996750050U;
            aOrbiterG = RotL64((aOrbiterG * 11185935780063403807U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1318947876257794796U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5447559252769140391U;
            aOrbiterK = RotL64((aOrbiterK * 13683733413554766327U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2766869582494246454U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15757729967222729304U;
            aOrbiterE = RotL64((aOrbiterE * 1858683399257513171U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13063432816787882618U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3650233661228036955U;
            aOrbiterH = RotL64((aOrbiterH * 16230564672533821641U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 10U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterK, 21U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 26U) + aOrbiterI) + RotL64(aOrbiterE, 4U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterK, 37U));
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + RotL64(aOrbiterD, 23U)) + aOrbiterG) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 27U)) + aOrbiterH) + aNonceWordG);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 6U) + RotL64(aOrbiterB, 46U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterC, 39U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32139U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 26086U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29847U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 27959U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 34U) ^ RotL64(aIngress, 3U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aScatter, 27U)) + 3621877681473089725U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 4451752751536414717U;
            aOrbiterI = (aWandererC + RotL64(aCross, 60U)) + 11371625415377772117U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 11U)) + 6046792758881150619U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 47U)) + 8213166120394461682U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aIngress, 51U)) + 4343156661140422645U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 11105271483234947905U) + aNonceWordO;
            aOrbiterD = (aWandererB + RotL64(aCross, 43U)) + 348904609985341372U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 12924652822526858767U) + aNonceWordD;
            aOrbiterB = ((aWandererF + RotL64(aCross, 5U)) + 7461211697358520287U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 38U)) + 16551553555297890558U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11908056404140782995U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9147367258259948715U;
            aOrbiterI = RotL64((aOrbiterI * 10777628928376261667U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8876461054692728610U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 10546855952702525404U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10071104785895309677U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4748636139110443794U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 783046909529525098U;
            aOrbiterA = RotL64((aOrbiterA * 8969157702460927215U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16683965945838696665U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12385412690177109575U;
            aOrbiterK = RotL64((aOrbiterK * 10795062772707143187U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8210546822184469023U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 13146493623236979963U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 13199947810161148155U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13857628148804187115U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7241297989337473475U;
            aOrbiterH = RotL64((aOrbiterH * 16223448508809614229U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 773904571213804946U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7660676598236419707U;
            aOrbiterB = RotL64((aOrbiterB * 14467390638468925567U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16822672435156055469U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6514707119190640433U;
            aOrbiterG = RotL64((aOrbiterG * 7097496727567460535U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17784153215885060832U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16027189961519690419U;
            aOrbiterF = RotL64((aOrbiterF * 3248782394761733169U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 821916530432611671U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8764650990196504963U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 6269514974278082251U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5987370764866753332U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3621877681473089725U;
            aOrbiterJ = RotL64((aOrbiterJ * 14763908964222787377U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 40U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 42U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 36U) + aOrbiterD) + RotL64(aOrbiterI, 26U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + aNonceWordA) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG) + aNonceWordE);
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterC, 35U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 6U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterE, 29U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 22U) + aOrbiterJ) + RotL64(aOrbiterH, 51U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterD, 39U)) + aNonceWordG) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordG);
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

void TwistExpander_Fencing_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC6C6FBEDEBFA1531ULL + 0xBB21498A908D0246ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC8FF0EFFE1B10F8FULL + 0xF44AA8C728FC42DCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBF2FFA3BB9E27E17ULL + 0xD1DB53C20CF7B928ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8097D667A56E3947ULL + 0xDC739A66260E9824ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBFC4D8FE7ACCA03DULL + 0xA845CCDF4A05738BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFB08F083793B4429ULL + 0xE7358FEF84A5B683ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8C2800D1DC1F9193ULL + 0x83A6FCC5071DCB27ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDE3D15588E86924BULL + 0x82C7920097B87BC1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x97EFD8C4D32C0683ULL + 0xE646901A5291159DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x97F369DA7D96E1A7ULL + 0x88A71AF32D97691CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDE6B49D325F989A7ULL + 0xD7C6F47DF28D1021ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA1EE745BD9B87E4FULL + 0xA203B0AAB77B6959ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD38CA689A84EFC05ULL + 0x85E7C07FB00F7A7FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xED95DACE8A5B9525ULL + 0xD0B5D9B432DBF34CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBD6C169E18BE3B13ULL + 0xFB510C0C1681C9DBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC5DCBB8908726579ULL + 0x8B027A95C327114AULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3421U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 3333U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3305U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3343U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 10U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 43U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aScatter, 21U)) + 7632760812370906911U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 39U)) + 6007174525479723089U) + aNonceWordO;
            aOrbiterI = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 3362829642521821048U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 30U)) + 18009548556107978286U) + aNonceWordA;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 53U)) + 17880909432272697327U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 15961567935420752568U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 47U)) + 10136559064656837921U;
            aOrbiterE = (aWandererI + RotL64(aCross, 35U)) + 17622019364405410277U;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 26U)) + RotL64(aCarry, 29U)) + 6927494824421416306U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7125170407794874847U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12342273503071032250U;
            aOrbiterI = RotL64((aOrbiterI * 867417849555857179U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14997696377476124836U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14874498694181230698U;
            aOrbiterD = RotL64((aOrbiterD * 4026127545746010937U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2549397729130885686U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4217995818662767955U;
            aOrbiterE = RotL64((aOrbiterE * 5525525344485251063U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4706089044415442525U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17983900172670031015U;
            aOrbiterF = RotL64((aOrbiterF * 541552737180932879U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1904937798143929988U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 10620877287033139483U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 16711012562024287213U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15681091173163181525U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2655543246639000084U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 16686375598149755947U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2647895110857289213U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5581609212017175954U;
            aOrbiterJ = RotL64((aOrbiterJ * 15330263616699031311U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13609076329627787987U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6244266279516622070U;
            aOrbiterK = RotL64((aOrbiterK * 12488345779236971095U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5289624364508923581U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16351476803965903112U;
            aOrbiterA = RotL64((aOrbiterA * 9012522724650442597U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 39U) + RotL64(aOrbiterA, 30U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterC, 39U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 11U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterC, 43U));
            aWandererD = aWandererD + (((((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterI, 3U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 57U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterF, 47U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 6U) + aOrbiterJ) + RotL64(aOrbiterD, 20U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 48U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10413U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneD[((aIndex + 9686U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7625U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10242U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 41U)) + (RotL64(aPrevious, 10U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererB + RotL64(aCross, 52U)) + RotL64(aCarry, 41U)) + 3255291173184001106U;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 15308468160116255528U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 18186972408589866656U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 5U)) + 4439324265978331914U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 47U)) + 13099263173016322486U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 29U)) + 7041561081767500660U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 40U)) + 6196422612687812971U) + aNonceWordL;
            aOrbiterG = (aWandererH + RotL64(aCross, 23U)) + 7664260932541281413U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 35U)) + 17802347823020441056U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4253107484061190446U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13799496534030645312U;
            aOrbiterK = RotL64((aOrbiterK * 9167675060053848207U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14252892847595951926U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 5663527578664291422U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 18314294235895182465U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11148755959699137661U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17036900929333594592U;
            aOrbiterF = RotL64((aOrbiterF * 16041243617369003291U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2403828181385259549U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17813580350434928194U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13666780980793857831U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5623611126885414523U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7293224381174846969U;
            aOrbiterH = RotL64((aOrbiterH * 7032561584670788117U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 10602620906929686163U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 18015916257203385982U;
            aOrbiterA = RotL64((aOrbiterA * 10684090189688871993U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13592915735376305773U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13995866908043417505U;
            aOrbiterC = RotL64((aOrbiterC * 3802175869395887331U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8200465989447697618U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9866671660800629464U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 2138851839905326265U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11557528777230608777U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 131060617338185060U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11068705423012265209U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 14U)) + aOrbiterD) + aNonceWordF) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 51U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterG, 23U)) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterC, 41U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterF, 47U));
            aWandererI = aWandererI + (((RotL64(aCross, 30U) + RotL64(aOrbiterK, 5U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 18U)) + aOrbiterC) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterE) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 20U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15561U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 11952U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16064U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneC[((aIndex + 15709U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 27U) + RotL64(aPrevious, 42U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aPrevious, 4U)) + 2974056819475622600U;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 7345051759236356098U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 12738468816846628882U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 7694520596043297922U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 19U)) + 5530753590015084774U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 43U)) + 3776309161718383105U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 39U)) + 784780304358106404U) + aNonceWordL;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 24U)) + 8999942326995036509U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 47U)) + 5194986506064092779U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7920040007459652762U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11311997270710107937U;
            aOrbiterK = RotL64((aOrbiterK * 6227571709361790209U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5365231114813547251U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8630110234623825263U;
            aOrbiterE = RotL64((aOrbiterE * 2735881715888325759U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2358235238039571072U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 18059414891616491807U;
            aOrbiterA = RotL64((aOrbiterA * 17150786106857185467U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14526050556461782864U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6937282036603272474U;
            aOrbiterC = RotL64((aOrbiterC * 14954512365270028029U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10105832250694931310U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3884223553012098137U;
            aOrbiterJ = RotL64((aOrbiterJ * 16340956813003906195U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10385284339549648087U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1257633893341505930U;
            aOrbiterF = RotL64((aOrbiterF * 2669950791270500977U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5528890519572824318U) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15664241747527713256U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 16670884497088220497U), 19U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 14264122979415331887U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 17985061405540198036U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2729487440173395133U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1663986734997903415U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3706166884286400587U;
            aOrbiterI = RotL64((aOrbiterI * 10549736618301955745U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 26U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterC, 5U));
            aWandererC = aWandererC + ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 11U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterC, 36U)) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 41U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterK, 57U)) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterK, 47U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 52U)) + aOrbiterF) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18705U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 20922U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21512U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((aIndex + 16521U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 14U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aIngress, 41U)) + 2558105147674438050U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 47U)) + 15856662514774702561U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 13346869226246584582U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 30U)) + 7632111846116243973U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 3U)) + 2102101361626976279U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 5605968705067851563U) + aNonceWordN;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 6842483186584326681U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 57U)) + 5559797213819425064U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 24U)) + 12422313931331576759U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2751024420047872601U) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11031320239359798610U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8607639453141148025U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14366375309473793217U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11971479429768505316U;
            aOrbiterD = RotL64((aOrbiterD * 10063001532313098203U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3947595951884469542U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17882767922372770896U;
            aOrbiterC = RotL64((aOrbiterC * 3361906348965810211U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 513871456983509223U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5951677013597794294U;
            aOrbiterF = RotL64((aOrbiterF * 8508629569649935293U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 437626309049021931U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 466674061172005705U;
            aOrbiterK = RotL64((aOrbiterK * 1310502572084891157U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12362602809233133718U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10525852878882195702U;
            aOrbiterA = RotL64((aOrbiterA * 17755022180514914325U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17927000184308583095U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 566723721423470052U;
            aOrbiterE = RotL64((aOrbiterE * 17710534355278632573U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9504585484034413577U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4614306037721859929U;
            aOrbiterH = RotL64((aOrbiterH * 170807293799483539U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1463218357720031588U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 4036696102163560633U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 15389914226155130065U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 34U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 52U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 27U)) + aOrbiterE) + aNonceWordA) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 28U) + RotL64(aOrbiterF, 39U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterH, 14U));
            aWandererA = aWandererA + (((RotL64(aCross, 18U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26884U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23215U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24991U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22788U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 56U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 47U)) + 10336802574069791273U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 60U)) + 169025388197058936U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 23U)) + 6541354188379168846U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 16223920526599306104U) + aNonceWordM;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 53U)) + 12756613707692514808U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 5082475548176484035U) + aNonceWordB;
            aOrbiterG = (aWandererD + RotL64(aCross, 18U)) + 4907435526952698526U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 14236627073831834337U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aPrevious, 5U)) + 11502511046130497584U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3679044835550219497U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11254838916686736746U;
            aOrbiterC = RotL64((aOrbiterC * 8631695922983532915U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10582608424233200966U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10449735026385340313U;
            aOrbiterD = RotL64((aOrbiterD * 7363770199734997411U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4628253464169957835U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 17664454668473204465U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4234720298731378527U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3798386391743884889U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1379331161819246587U;
            aOrbiterB = RotL64((aOrbiterB * 13086160171095077295U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9816600392407327227U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16781971616348376878U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 12503867584828289879U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4807797577690520554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2492057261148595922U;
            aOrbiterH = RotL64((aOrbiterH * 9453302540675483005U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 7909676419643119585U) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 256053568910383007U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 11965085163352053161U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16179914439220412472U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3968867762761955845U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7473632378251893139U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7474832923901283742U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4736994731050735779U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9839654409121414047U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 24U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 24U)) + aOrbiterB) + aNonceWordH);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 30U) + aOrbiterC) + RotL64(aOrbiterB, 53U)) + aNonceWordL) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterD, 43U));
            aWandererC = aWandererC + ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 47U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterG, 39U)) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 30U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 35U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterG, 57U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30563U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27759U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31463U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29577U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 35U)) + (RotL64(aIngress, 22U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 5U)) + 6467297102954816305U;
            aOrbiterD = (aWandererE + RotL64(aCross, 21U)) + 7921154109831114952U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 10U)) + RotL64(aCarry, 41U)) + 5701131763215638919U) + aNonceWordL;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 10022999076719002684U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 47U)) + 4367135243038982316U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 14445846824810383592U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 41U)) + 7683697954545773253U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 60U)) + 17517006750428030899U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 51U)) + 2052484792684025476U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6279463052085808926U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 679280153651813684U;
            aOrbiterG = RotL64((aOrbiterG * 3047031560593583881U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2939516520188460569U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1960616434964712325U;
            aOrbiterK = RotL64((aOrbiterK * 15145998415466343039U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12273819390719947361U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5685033154709449397U;
            aOrbiterA = RotL64((aOrbiterA * 9845666295874714959U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9314494172199500653U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15757631834636427621U;
            aOrbiterI = RotL64((aOrbiterI * 15483543888965744529U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10878078046389399574U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3583495913766365232U;
            aOrbiterE = RotL64((aOrbiterE * 2913540984990155225U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7385544065754622301U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16839599460207922881U;
            aOrbiterJ = RotL64((aOrbiterJ * 240651605910592561U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 13038163804940349251U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2587538594933924000U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 3091149760401278671U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 13109518583364738004U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2447689055742474261U;
            aOrbiterB = RotL64((aOrbiterB * 12100180201235703193U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5752044906692668618U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6637725371036522120U;
            aOrbiterD = RotL64((aOrbiterD * 6021986525167161115U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 46U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 52U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + aNonceWordB) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 30U)) + aOrbiterC) + aNonceWordN) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterK, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterI) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 56U) + aOrbiterD) + RotL64(aOrbiterB, 11U));
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterG, 20U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 53U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 36U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_Fencing_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEE69AA4EBB6294D9ULL + 0xDEFB721A05D26ECFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDADA06392851191BULL + 0x955D98ED9178A761ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE4FDB9D0698FF533ULL + 0xA2DFB593A4844107ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA9D4A84CDE80CD55ULL + 0xE0EECA3A07758A48ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFB927D0E574D2997ULL + 0xFA0EB16C73EE60E4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFF4726132497F4F7ULL + 0xA84F9EE8281FEED2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA33C92CA27DF36D7ULL + 0xECDC3D2CEE0C2C4FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC9EAEB0D6EC1911FULL + 0x8222497A33414EF8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBD19B5289B2938B1ULL + 0xFF9831F4B3596149ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF69F5425A20492AFULL + 0xA76B3A2944862341ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA61754F38DB55F17ULL + 0xDDA78E0B95C6A22EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD3D54895D0583EC5ULL + 0xFA577E0FCA481555ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xEA70B826481F4CA5ULL + 0xB99210A174FC38BAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF2F262A0567A92DBULL + 0xBBF7CE54B64A6D44ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE7EDA2363128D061ULL + 0xFE654DF448BCAD10ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE138F2F298A92911ULL + 0x941A13AF0AE02C0FULL);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3797U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 1930U)) & W_KEY1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1467U)) & W_KEY1], 46U) ^ RotL64(mSource[((aIndex + 4113U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aScatter, 27U)) + 7722279280863371124U;
            aOrbiterE = ((((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 11584220561732385598U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 7834679350105534657U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 47U)) + 11347994382444180879U) + aPhaseAOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 40U)) + 9449903188047063431U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 6516243976652795170U;
            aOrbiterA = (aWandererI + RotL64(aCross, 13U)) + 8420815253991184777U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9081386852515170937U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14375955191735286867U;
            aOrbiterI = RotL64((aOrbiterI * 2772840314542262283U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 880757589768436072U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3349856625725164229U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 681514212582331781U), 37U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 7826309957607577207U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8057435761214313635U;
            aOrbiterF = RotL64((aOrbiterF * 4718430712767038607U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9565237500443303103U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15893066735310588501U;
            aOrbiterA = RotL64((aOrbiterA * 8457633439171452397U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3276844534476430842U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6828644383891274120U;
            aOrbiterC = RotL64((aOrbiterC * 979580351653410157U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2815676923011504251U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 5030251870850928417U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7075653570570819253U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13464083008377887034U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8994560761846897590U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9892839554658865143U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 18U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterC, 13U));
            aWandererI = aWandererI + (((((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 5U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aNonceWordB) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aIngress, 18U) + aOrbiterK) + RotL64(aOrbiterC, 43U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterF, 60U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9179U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9539U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8319U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 9915U)) & W_KEY1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 26U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aCross, 29U)) + 5573188770530340913U) + aNonceWordP;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 35U)) + 1431772230889897111U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aIngress, 43U)) + 4809192776429682319U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 39U)) + 5576603692574369341U) + aNonceWordO;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 2720143226007220386U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 5U)) + 17220328778565331629U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 9629485808442089423U) + aNonceWordF;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1136998437010390983U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11893390497814523841U;
            aOrbiterE = RotL64((aOrbiterE * 5329621622743089531U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1764986431917532370U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1741014798007010376U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 13414914086049500731U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12221368453236547044U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7694538641172350430U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 8439120733670016501U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17472344518811560603U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3308740700728172984U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15290400462887712083U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9535358833412446771U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11192312491731312451U;
            aOrbiterJ = RotL64((aOrbiterJ * 17405609148475445743U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 14850451970047190039U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11932493299452443256U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7964808728820467795U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5972619895614731870U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17174497535809891690U;
            aOrbiterF = RotL64((aOrbiterF * 15471084511364572533U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 43U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aNonceWordN) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterD, 13U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 53U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + aNonceWordH) + aPhaseAWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aCross, 18U) + aOrbiterE) + RotL64(aOrbiterI, 60U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 12U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10982U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12327U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12632U)) & W_KEY1], 44U) ^ RotL64(aKeyRowReadB[((aIndex + 14542U)) & W_KEY1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 4U) ^ RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 35U)) + 15910560457440369082U) + aPhaseAOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 17953072986407436888U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 15446940721193538669U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 4U)) + 3020785262774422009U) + aNonceWordA;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 41U)) + 7001288645424994404U) + aNonceWordP;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 13385250665458462689U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aScatter, 57U)) + 4841895644623005949U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13053476783239482065U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 641996979335975244U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3697673197256549833U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16211238020928688299U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12715448751323279480U;
            aOrbiterF = RotL64((aOrbiterF * 2116880429675303291U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 17784406727699995290U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 16626339815786580778U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 13940754474750138041U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9035070625716345139U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6085848172494001945U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10405728912339646693U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1177103851507561053U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2281901691017816407U;
            aOrbiterE = RotL64((aOrbiterE * 3142197009403602497U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9040984343694325070U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13334258224023902365U;
            aOrbiterJ = RotL64((aOrbiterJ * 4782523727707164869U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1079824790138592518U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14024082692012948652U;
            aOrbiterA = RotL64((aOrbiterA * 3219489374333737903U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 50U);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 27U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + aNonceWordC);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 19U)) + aNonceWordE) + aPhaseAWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterG, 35U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterB, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 4U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16638U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((aIndex + 16725U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18947U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 19508U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (aWandererJ + RotL64(aCross, 27U)) + 7896237440058555694U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 11870529476037558635U) + aNonceWordA;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 9158983227801569448U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 21U)) + 4710172270996950329U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 5U)) + 14634482800356647630U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 13U)) + 8822207952170610891U) + aPhaseAOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 50U)) + 13755891414028982553U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4555293067488040719U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2816805148093762081U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16838149138341713943U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2122631477965135190U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4592922416380416071U;
            aOrbiterK = RotL64((aOrbiterK * 11644507904538573165U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 7102471666524164715U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17274623547879474204U;
            aOrbiterE = RotL64((aOrbiterE * 5443572270546181789U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 938587316977094680U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 18258015823797023523U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6068819567674605919U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5809987756043471595U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5083075160112581620U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3313957222154937503U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5960021727750946496U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5967477320950630150U;
            aOrbiterD = RotL64((aOrbiterD * 330964768256424655U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6578428711689296132U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5601728218197771276U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 9552559022315971847U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterK, 11U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 21U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 51U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 29U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterG, 41U)) + aOrbiterF) + aPhaseAWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 22U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + aNonceWordM) + aPhaseAWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 26U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25761U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 23483U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24349U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22867U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 60U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 12046647397183218524U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 2760779375026461991U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 30U)) + RotL64(aCarry, 41U)) + 13735454443176855650U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 57U)) + 4370377000586647724U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 13U)) + 14566322384189969094U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 5U)) + 5056565959818422786U) + aNonceWordI;
            aOrbiterG = ((aWandererK + RotL64(aCross, 47U)) + 8795403810686579209U) + aPhaseAOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9625947666256011567U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1703669290934254701U;
            aOrbiterI = RotL64((aOrbiterI * 5763881345676123583U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6664070663184147951U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2104148316797553431U;
            aOrbiterA = RotL64((aOrbiterA * 12887842067180975983U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1197910004222596145U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9922977170060903197U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13047828062605568603U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2048376210852567829U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12568990647075931409U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9860242601194210927U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15026894775772902751U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3439447160137900629U;
            aOrbiterK = RotL64((aOrbiterK * 1813754963043785165U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6532671388552829796U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17261098369835997661U;
            aOrbiterD = RotL64((aOrbiterD * 568292591215203521U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3171300991007459947U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5935563269327662024U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 11271790283157765003U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 4U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterD, 47U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterA, 11U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 57U)) + aOrbiterG) + aNonceWordD) + aPhaseAWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 36U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + aPhaseAWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 57U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31479U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31339U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31256U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28917U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 40U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = ((((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 13583136155674166402U) + aPhaseAOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aWandererH + RotL64(aCross, 3U)) + 12830472187484919497U) + aNonceWordB;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 19U)) + 18081197909484522509U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 11U)) + 8680634051297891550U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 13939998767458656823U) + aNonceWordJ;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 1795730579103692594U) + aPhaseAOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 56U)) + 17369751719734069999U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 224769585901248068U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4133547085925268180U;
            aOrbiterA = RotL64((aOrbiterA * 2611561365156544735U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7022512056309567391U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10319484359046945495U;
            aOrbiterD = RotL64((aOrbiterD * 3400140531307001933U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10483878349412282069U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6481381149199985736U;
            aOrbiterI = RotL64((aOrbiterI * 9701719367082506253U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13721077228796934509U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9704818014314175007U;
            aOrbiterK = RotL64((aOrbiterK * 760445624027740287U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6253040047758584339U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16890211690273641226U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5622534399866057841U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6216227831265032436U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2023609047004658739U;
            aOrbiterC = RotL64((aOrbiterC * 3252332895698310147U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9201669637050388263U) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5106927540934338576U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 6368134569042291431U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 37U)) + aNonceWordH) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterB, 21U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 44U)) + aOrbiterA) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterC, 51U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_Fencing_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCA679144E8F90E79ULL + 0x9658B164EAAD2E56ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD5AE8FD2BB5DAD5DULL + 0xC3370680B25A7648ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE877E68F81ED90FDULL + 0xA8B44C4BD937B595ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x83288ACAFBD3E375ULL + 0x98B34BFBFCD64195ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD7CD3732E2E9EDCBULL + 0xCB3046044527BEBEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9954263494DA34A3ULL + 0xC301CC16A07C5AA3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD826FAE3B844406DULL + 0x8EA869F1B6AB41EDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD97CB367DC569D1BULL + 0x8B4A6E59EA2F7E04ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAEAE451F16426505ULL + 0x86D3BCDF355DB24DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC039D397E08DD6EFULL + 0xD93EDAD161752358ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB1F43F46B55C94B5ULL + 0xAC2746C540F99514ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD4861598012BACCBULL + 0xEEB531D5D098FF17ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF48967B5A2F52AD9ULL + 0xAD3C404074628951ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8388357E703E3B31ULL + 0xC75A23C3EF09E1CDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEFEE29E3C8C71E37ULL + 0xF0316286CC303963ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF25CE5F69D67D369ULL + 0xF8BBDF712A7AFC72ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 129U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2068U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3680U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 2639U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 35U) + RotL64(aPrevious, 18U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aCross, 28U)) + RotL64(aCarry, 57U)) + 6521330037475130256U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 12611880456055428940U;
            aOrbiterI = ((((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 12061611078130934708U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 3U)) + 1558112410801116984U) + aPhaseBOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 57U)) + 10509115227850160786U) + aNonceWordF;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 4045915960688792066U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1196541286513243082U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 5454309408259753479U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 15564991032722373702U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4897765238703641798U;
            aOrbiterE = RotL64((aOrbiterE * 9693901276712946763U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12327429514907752733U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6189189797708711636U;
            aOrbiterC = RotL64((aOrbiterC * 9017615866338877651U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6374267075282018852U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1888758503831341439U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 74387714918264257U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14956857689299491800U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14879361107223331957U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 9166712966729591953U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 46U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 18U) + RotL64(aOrbiterE, 19U)) + aOrbiterC) + aNonceWordB);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordH) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterH, 29U)) + aPhaseBWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterI, 44U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterB, 5U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordN);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10483U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((aIndex + 6054U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10149U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 7716U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 41U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 58U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (aWandererH + RotL64(aPrevious, 52U)) + 18319689184146942855U;
            aOrbiterJ = ((((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 8041304130090501019U) + aPhaseBOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 11347064191990897738U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 41U)) + 15242243470024447468U) + aNonceWordF;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 10619749107163611105U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14795614276221947128U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1578095288886372393U;
            aOrbiterD = RotL64((aOrbiterD * 9953192041564147241U), 47U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 13593906305770501684U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8919815528334599172U;
            aOrbiterG = RotL64((aOrbiterG * 2033810402808238127U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17425548324720065145U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 11125018338392347335U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4377887040461528587U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3779189180734244399U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10958224663276134041U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6206963519509783781U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 4317305352561612995U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4891139433808505355U;
            aOrbiterK = RotL64((aOrbiterK * 11507024985663120317U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererB = aWandererB ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + aPhaseBWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterD, 58U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 13U));
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterD, 5U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordP);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10972U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 15539U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11913U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13823U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 57U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 43U)) + 7960325128608297381U) + aPhaseBOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 4U)) + RotL64(aCarry, 3U)) + 12773836012104052042U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 29U)) + 3173972621347773016U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 3708401356314308171U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 53U)) + 950774285720019449U) + aNonceWordO;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4170092315705438265U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17000449130864980747U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7710635557693533263U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 8793910540062893860U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 520277969543516469U;
            aOrbiterH = RotL64((aOrbiterH * 4150613128885828229U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12762214857389827271U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2932451184340207695U;
            aOrbiterF = RotL64((aOrbiterF * 7513337346940091655U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11062179998786293839U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7919119215271524178U;
            aOrbiterC = RotL64((aOrbiterC * 9053677007180081359U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1774988449597115155U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3799792889466518953U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17512791286490623455U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 58U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 27U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterB, 14U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 46U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 12U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20196U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18881U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21332U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21822U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 19U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (aWandererD + RotL64(aScatter, 27U)) + 11521331427196538632U;
            aOrbiterC = ((((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 16653824187682957632U) + aPhaseBOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 11654676587350088289U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 8010313317412193584U) + aNonceWordF;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 14U)) + 1108775560502907471U) + aPhaseBOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 243952321439823521U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2324945800401240403U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 9471328582043504473U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9257554497543369657U) + aNonceWordH;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 16701314607244592540U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 8790054741039817107U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3900445848034341782U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7652316487347103658U;
            aOrbiterK = RotL64((aOrbiterK * 11480123491361589799U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14980368605272070578U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2001165460948764796U;
            aOrbiterC = RotL64((aOrbiterC * 8110980921827107649U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1911044015666991050U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 11366207111147818339U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17234439040652553865U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordL) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 56U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 21U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererK = aWandererK + ((RotL64(aIngress, 40U) + RotL64(aOrbiterI, 13U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 30U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21948U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26324U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22771U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 22019U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 14157904117287696136U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 39U)) + 7369512677371640676U) + aPhaseBOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 8411250745902073798U;
            aOrbiterE = ((((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 5002041814539710275U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 60U)) + 9538041410816283124U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5210700103927513061U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7600709399101287982U;
            aOrbiterG = RotL64((aOrbiterG * 6777896926889560889U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2366369466696580499U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5544575244203019109U;
            aOrbiterK = RotL64((aOrbiterK * 16231219246786333057U), 39U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 8710073749110329779U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15998211310115361630U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15275657696897688955U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15354357553877376422U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10657523549259276169U;
            aOrbiterH = RotL64((aOrbiterH * 13695239532898311073U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 10405750198355464768U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 3465819693133515142U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 14678343718277562799U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 34U) + aOrbiterI) + RotL64(aOrbiterH, 29U)) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 19U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + aPhaseBWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 53U)) + aNonceWordG) + aPhaseBWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterH, 39U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29343U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 32734U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28860U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 30248U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 27U) + RotL64(aCross, 14U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = (aWandererH + RotL64(aPrevious, 47U)) + 15316464782468770057U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 21U)) + 6642872057476351588U) + aNonceWordP;
            aOrbiterF = ((((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 660732654689529192U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 7235418086884000655U) + aNonceWordM;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 30U)) + RotL64(aCarry, 23U)) + 14784518476694580493U) + aPhaseBOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12222433977933449375U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8573001207708329927U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17771120145431297541U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 16035256260815013172U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15767726974121910203U;
            aOrbiterA = RotL64((aOrbiterA * 719060452537759331U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 17712217935322939971U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 13488963456923357159U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 16785285630840310405U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10222949131965611079U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1495561412321657209U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9706305581868526265U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16156530750584361434U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7773792489045606309U;
            aOrbiterH = RotL64((aOrbiterH * 10730624207715601393U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + aPhaseBWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterH, 30U)) + RotL64(aCarry, 37U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordI);
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

void TwistExpander_Fencing_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF5D6A53B36CF0927ULL + 0xB94D0C5B71768290ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD5B2D5B3A21710BFULL + 0xFC47CFB70C992BCBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9A1C46800F122B5BULL + 0xA93FF148E85A75FFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBD57BC75BDDEF725ULL + 0xA6A1DD4993692FD1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE1B50753E8880B43ULL + 0xA728B3AD49D30879ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB9DB1D42EA07FEA5ULL + 0xCB525A867C2FAC42ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF44A2DDFE8EC52A7ULL + 0xF4A7F81C29B87190ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8C48789D27D06B6BULL + 0xDA9A1E176312C1CFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE7F6C0E33212A593ULL + 0x825F7CE7853EF196ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8F5F00E2ABE2F379ULL + 0x859C60F4EB65DC00ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x964D4F7AE6DDEFE1ULL + 0xBE0C9C2CC20B8687ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCCB4A0B4758F242DULL + 0xD58284628DA1FEEEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC95D129FD095226DULL + 0xE12530F314C9B8F2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9390C0C29DEDB851ULL + 0x9FB034441AF47BC9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD62A068A9CCD1C07ULL + 0xC4461DC716812A52ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9B04D692FDFA65B9ULL + 0xFA6C71ACC6A39C84ULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4283U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 172U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 314U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 2629U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 20U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aCross, 23U)) + 15549114274303128055U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 51U)) + 16466750056388063241U) + aNonceWordF;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 30U)) + 12209449840836787142U) + aPhaseCOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 57U)) + 14551496099734294336U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 6266576428679808622U) + aNonceWordA;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 16892841575635668152U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 5U)) + 7375966221423362125U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 44U)) + RotL64(aCarry, 13U)) + 11926105302821753530U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 13U)) + 16219253791550461124U) + aNonceWordP;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7299056065319248160U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15234001484933728439U;
            aOrbiterI = RotL64((aOrbiterI * 8182244796017018911U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6615802589932632120U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5481176858895819247U;
            aOrbiterA = RotL64((aOrbiterA * 3604590158551984877U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17220507586542139380U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14137921473739415340U;
            aOrbiterB = RotL64((aOrbiterB * 10634645686035907603U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16981960446540932787U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10897565927079518588U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 418843936329303571U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2746889569299593263U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 4894117146736361379U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2656750612042673191U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 18294823016957137777U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 86828501068883383U;
            aOrbiterD = RotL64((aOrbiterD * 11432686669235402365U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6322053762209547826U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6754524552483363820U;
            aOrbiterK = RotL64((aOrbiterK * 1746163087826694641U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7306452650619361017U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 12717201204443785828U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 6121251603905574991U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10422327053543898585U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14786413282036348183U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8713024293107068275U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 46U);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 6U) + RotL64(aOrbiterF, 10U)) + aOrbiterB) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 27U)) + aOrbiterF) + aPhaseCWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterH, 23U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 35U)) + aNonceWordN);
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 53U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 52U) + aOrbiterF) + RotL64(aOrbiterH, 43U));
            aWandererK = aWandererK + ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 48U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 20U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13279U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10550U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9697U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 11211U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 3U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 26U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 37U)) + 17668251151213543491U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 23U)) + 16101602509895104517U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 9083915270773304935U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 46U)) + 12810720730318214811U) + aNonceWordF;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 19U)) + 18113428002071925621U) + aNonceWordC;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 51U)) + 1582208899354109878U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 4180688104819188154U) + aNonceWordG;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 10U)) + 8954598189262820611U) + aPhaseCOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 3U)) + 15360094153175355879U) + aPhaseCOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8383954114668216260U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15626783326234049197U;
            aOrbiterC = RotL64((aOrbiterC * 15058420415480073793U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10609978564404958066U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17656516608997517984U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4590620354119899777U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 760077259110786536U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3597338735888033063U;
            aOrbiterD = RotL64((aOrbiterD * 6548831472863517621U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 4431777844935985157U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10710423172154671296U;
            aOrbiterI = RotL64((aOrbiterI * 16267496318491473315U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10240882795242085185U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7826053487019825891U;
            aOrbiterF = RotL64((aOrbiterF * 15053729937684375907U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9418883403715727353U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11507423614799075545U;
            aOrbiterE = RotL64((aOrbiterE * 16189463984557044693U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11545217316421066655U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 617921402135485341U;
            aOrbiterA = RotL64((aOrbiterA * 8182920764965471653U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 14456933220749921009U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7990243583564535387U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5994900368027985469U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14023633125757654751U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11319146808574958827U;
            aOrbiterG = RotL64((aOrbiterG * 13676159969338309307U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 48U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 23U));
            aWandererB = aWandererB + ((RotL64(aCross, 28U) + RotL64(aOrbiterA, 53U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + aNonceWordJ) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 58U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 35U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 27U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aScatter, 12U) + aOrbiterF) + RotL64(aOrbiterC, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterE, 38U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17489U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 23739U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21721U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 17653U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 37U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 10881271196314989997U;
            aOrbiterF = (aWandererA + RotL64(aCross, 37U)) + 6406461249988567558U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 44U)) + 17255067918280095959U) + aNonceWordK;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 13U)) + 16690850682497718411U) + aPhaseCOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aIngress, 19U)) + 5576201059361086866U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 11991259685693687554U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 60U)) + 14652535244217836909U) + aPhaseCOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 1701789037170782122U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 23U)) + 953429054903473833U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12064513610469714211U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7993881398822002424U;
            aOrbiterI = RotL64((aOrbiterI * 11572884842788918377U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14421313768013320050U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 11112386845630998889U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 11771526352030371669U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17069630896535699015U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3308240081138623373U;
            aOrbiterE = RotL64((aOrbiterE * 10449509484417835159U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17615529807112933619U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 11782807146851563541U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 12992075832343669221U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 14401645829607611983U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6736397344219993532U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1667287547938175641U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6446974060524700550U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7840991992443308254U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 6891023544882740107U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10362169906019794305U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4503700997923168911U;
            aOrbiterJ = RotL64((aOrbiterJ * 15066164494038852559U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13492041134973259041U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14337899277551397976U;
            aOrbiterH = RotL64((aOrbiterH * 5966740718899290915U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 13693100781608180748U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16177545026405910052U;
            aOrbiterD = RotL64((aOrbiterD * 6019231448444020563U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 19U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterD, 53U));
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterH, 28U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + aNonceWordA);
            aWandererC = aWandererC + ((RotL64(aIngress, 52U) + aOrbiterA) + RotL64(aOrbiterK, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 39U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterD, 34U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterA) + aNonceWordJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 36U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25929U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 30824U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29101U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 31451U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 51U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 38U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aCross, 57U)) + 3199575576585871314U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 23U)) + 2533378188975571824U) + aNonceWordE;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 6819782112558312658U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 10U)) + RotL64(aCarry, 53U)) + 12690060987724798497U;
            aOrbiterK = (aWandererI + RotL64(aCross, 43U)) + 7088375139715629606U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 37U)) + 17785618677423695666U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 29U)) + 1714999280296491277U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 14U)) + 17611338506932491624U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 6475727359297421201U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2347744591204119530U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2739317903351401068U;
            aOrbiterH = RotL64((aOrbiterH * 15435029315209475631U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8663535261373274338U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8205245127823536479U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13857005110466856439U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8916510616749754516U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3944805940148512932U;
            aOrbiterJ = RotL64((aOrbiterJ * 18082271583211389701U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 14094751253118853302U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14094299829196076311U;
            aOrbiterI = RotL64((aOrbiterI * 6370012560657108493U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3940673811518673802U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3015106523254484839U;
            aOrbiterC = RotL64((aOrbiterC * 9655401190755573379U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 15404103131982599922U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1828655763233900875U;
            aOrbiterB = RotL64((aOrbiterB * 13024358077740310049U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1236981890899916502U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 18208975564570342697U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4577109989465876801U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17882273895471449661U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16196010765612713713U;
            aOrbiterE = RotL64((aOrbiterE * 15624856645134182005U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14639250100311162559U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9139027997336903273U;
            aOrbiterA = RotL64((aOrbiterA * 1853126389565574293U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 48U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 42U) + aOrbiterE) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 30U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterK, 39U));
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterF, 35U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 56U) + aOrbiterA) + RotL64(aOrbiterC, 43U));
            aWandererF = aWandererF + ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 60U)) + aOrbiterB) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_Fencing_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA57E09D4BEB08347ULL + 0xD272E6D1170390E6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDD70AB9D716AAB1FULL + 0x9C0EBC49ABCB0A43ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBFD4601076A03817ULL + 0xCB9251F4BF773DA9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE168B38F5DBC8AA1ULL + 0xAD5372F1C655B7EEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x979A1B3BFD78563FULL + 0xB7EEEE53AB3D0B80ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA7AC226F536F785BULL + 0xC85C7AE4AD5E4936ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE34AF763AB52538DULL + 0xBD380D0A0EDFB40FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB3E93825DC161A3FULL + 0xC6BE7C7BA8B85CACULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xED709B62A888A213ULL + 0xD3AC06A1F2225FC3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFDA7B6DEAAB25C83ULL + 0xD8ED20025CB1576FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBED8D70EB181FABDULL + 0x95F12214E48C420FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEE7FD3E4F417A25BULL + 0x9684B8FF4E523500ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA943CACEBD8ED041ULL + 0xC298A8303FDF6A09ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF30AB51EFC56C951ULL + 0xE7B621EA6A76DED3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9E58892C76E87E21ULL + 0xF1DCDB191D65ABC4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD662795C3312822DULL + 0xABA1461E93A39158ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 104U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1676U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2333U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 52U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aIngress, 21U)) + 2974056819475622600U) + aNonceWordF;
            aOrbiterI = (aWandererJ + RotL64(aCross, 3U)) + 7345051759236356098U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 39U)) + 12738468816846628882U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 42U)) + 7694520596043297922U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 5U)) + 5530753590015084774U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 3776309161718383105U) + aPhaseDOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 53U)) + 784780304358106404U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 58U)) + 8999942326995036509U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 5194986506064092779U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 7920040007459652762U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 51U)) + 11311997270710107937U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5365231114813547251U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8630110234623825263U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2735881715888325759U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2358235238039571072U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 18059414891616491807U;
            aOrbiterG = RotL64((aOrbiterG * 17150786106857185467U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14526050556461782864U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6937282036603272474U;
            aOrbiterA = RotL64((aOrbiterA * 14954512365270028029U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10105832250694931310U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3884223553012098137U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16340956813003906195U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10385284339549648087U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1257633893341505930U;
            aOrbiterF = RotL64((aOrbiterF * 2669950791270500977U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5528890519572824318U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15664241747527713256U;
            aOrbiterJ = RotL64((aOrbiterJ * 16670884497088220497U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14264122979415331887U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17985061405540198036U;
            aOrbiterB = RotL64((aOrbiterB * 2729487440173395133U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1663986734997903415U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3706166884286400587U;
            aOrbiterI = RotL64((aOrbiterI * 10549736618301955745U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12736963182099961466U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 95411267612114381U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8011937916302325057U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4966620136499917388U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8478316876240452401U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 13297718919105366563U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11123814701411614557U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2974056819475622600U;
            aOrbiterD = RotL64((aOrbiterD * 5913569942407618997U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 58U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 54U) + RotL64(aOrbiterG, 46U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterE, 19U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterB, 21U));
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterG, 11U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterA, 35U));
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 5U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 23U));
            aWandererD = aWandererD + ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 3U)) + aNonceWordC);
            aWandererB = aWandererB + ((((RotL64(aCross, 46U) + aOrbiterK) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 28U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8070U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 8782U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8427U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5473U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aScatter, 26U)) + 13350544654542863236U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 41U)) + 12364346790125404372U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 39U)) + 9738750172849512764U;
            aOrbiterD = (aWandererE + RotL64(aCross, 5U)) + 3781373837635491421U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 53U)) + 16635020317512702337U) + aNonceWordP;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 5383653921676231276U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 29U)) + 10181959815492056493U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aCross, 43U)) + 10005510924273927017U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 50U)) + 9524687662265740565U) + aNonceWordC;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 4259138552009771014U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 8973051213213726023U) + aNonceWordH;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17602611840127337490U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8218984546932905269U;
            aOrbiterG = RotL64((aOrbiterG * 17504305273683304231U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 18102186122213487888U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2629927500298092976U;
            aOrbiterE = RotL64((aOrbiterE * 6983280164448292723U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2491581597835795234U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9506602492971620955U;
            aOrbiterJ = RotL64((aOrbiterJ * 9559829640915637163U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13422942713680612924U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15037354693234876601U;
            aOrbiterB = RotL64((aOrbiterB * 12692376075738621447U), 21U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 12896066842192894694U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2202952306291905855U;
            aOrbiterF = RotL64((aOrbiterF * 6779368532763429997U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12160313482450599313U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 10812986281270407756U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7786608700746771809U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12474638293190144525U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 5882870951276225224U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 15532427302173572457U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3782896138051179209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10965680631059882311U;
            aOrbiterK = RotL64((aOrbiterK * 14060923998307082385U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15650420683333746952U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4110674660963676864U;
            aOrbiterC = RotL64((aOrbiterC * 11724979274890265275U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 694817156953099464U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4402927404825116007U;
            aOrbiterH = RotL64((aOrbiterH * 579586789292520113U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6849178151532923489U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13350544654542863236U;
            aOrbiterA = RotL64((aOrbiterA * 2416097748778941523U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterI, 46U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterE, 27U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterB, 23U)) + aNonceWordA);
            aWandererD = aWandererD + ((RotL64(aScatter, 18U) + aOrbiterH) + RotL64(aOrbiterF, 51U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterK, 43U)) + aPhaseDWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 34U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 10U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterG) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16339U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 15335U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14467U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14755U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 20U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererI + RotL64(aIngress, 23U)) + 3612110001869385068U;
            aOrbiterE = (aWandererK + RotL64(aCross, 51U)) + 16340824141280225936U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 44U)) + RotL64(aCarry, 53U)) + 15222338965130765231U) + aNonceWordL;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 35U)) + 6649270508107155041U) + aNonceWordK;
            aOrbiterA = (aWandererH + RotL64(aIngress, 27U)) + 768217258655426384U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 37U)) + 4481855259658861851U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aScatter, 47U)) + 18318041934562434016U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 21U)) + 4212457153804401807U;
            aOrbiterH = (aWandererC + RotL64(aCross, 13U)) + 16143621095636987628U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 2095664232866642086U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 30U)) + RotL64(aCarry, 21U)) + 4339527736737366572U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13679353177869884790U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11582168502846418236U;
            aOrbiterF = RotL64((aOrbiterF * 135539430034462861U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10451330452898542191U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12951448817640617841U;
            aOrbiterG = RotL64((aOrbiterG * 4141870904192742091U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15389161934419370747U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4754886272708253014U;
            aOrbiterE = RotL64((aOrbiterE * 16638243718191281597U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 11746389873929280688U) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12042680172517298768U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3814780289755857543U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2648103752465009244U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 451594673632597973U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 8496763663271072425U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5696534794094099710U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14609435045257077395U;
            aOrbiterB = RotL64((aOrbiterB * 14658408563237468407U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11599395126850950133U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 12699598504604446664U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14313494063098111823U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9398465148537154745U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12139736860648011256U;
            aOrbiterI = RotL64((aOrbiterI * 15257503229375247987U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5390816291244486383U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2797988892316486895U;
            aOrbiterC = RotL64((aOrbiterC * 14668138881285892065U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 18356290434261054712U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16582824574485822826U;
            aOrbiterH = RotL64((aOrbiterH * 7207935384746719969U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9858803484150150915U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3612110001869385068U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 2862887443435821143U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterB, 43U)) + aNonceWordB) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterK, 18U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterC, 35U));
            aWandererF = aWandererF + ((RotL64(aCross, 6U) + aOrbiterD) + RotL64(aOrbiterJ, 41U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 21U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 53U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterB, 58U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 29U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterG, 47U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 20795U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 17526U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17056U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 21735U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 28U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aScatter, 19U)) + 17912271996338180948U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 37U)) + 13259276608841847058U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 11U)) + 16225936008657276089U) + aNonceWordD;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 2243058962151834071U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 23U)) + 10637439274127347861U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 3U)) + 15312219216405992627U) + aNonceWordA;
            aOrbiterI = ((aWandererH + RotL64(aCross, 42U)) + 2393933972129878613U) + aNonceWordH;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 4327069337247976513U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 8307656353434167837U) + aPhaseDOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aIngress, 27U)) + 17299145556933889336U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 14U)) + 14458100581172798164U) + aPhaseDOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6410095654927998067U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6168964796264687686U;
            aOrbiterC = RotL64((aOrbiterC * 16218071040190475953U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3667999465041020730U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16021552859323602007U;
            aOrbiterB = RotL64((aOrbiterB * 6427266472526362663U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12941668202330045095U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4222032891850449934U;
            aOrbiterF = RotL64((aOrbiterF * 17292856787431308097U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 1346342592002730785U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16860611785008118820U;
            aOrbiterI = RotL64((aOrbiterI * 384963420804756607U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3193572711804730241U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5866881282680588589U;
            aOrbiterE = RotL64((aOrbiterE * 9226331800853634597U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17180332731328479126U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10222097519535882241U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9422887302872778795U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8863502179821584859U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14872318155712512999U;
            aOrbiterH = RotL64((aOrbiterH * 11830641277356873233U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16478790641892781150U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 8414944141232294781U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17443775794621154023U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13204056527590476037U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15084952142545813228U;
            aOrbiterJ = RotL64((aOrbiterJ * 17183888602469193015U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13051035678904490854U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17565188004293304987U;
            aOrbiterA = RotL64((aOrbiterA * 12785271107667631897U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 814245676602237400U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17912271996338180948U;
            aOrbiterG = RotL64((aOrbiterG * 14557769257469623169U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 56U);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterA, 39U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 19U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 56U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 5U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterB, 27U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 29U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aCross, 23U) + RotL64(aOrbiterA, 24U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterB, 37U));
            aWandererG = aWandererG + (((RotL64(aCross, 18U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterG, 53U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 44U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 26912U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26729U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24877U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 22716U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 20U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aScatter, 60U)) + 1042610313571524121U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 27U)) + 3505725321008825582U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 3U)) + 12584654563843782991U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 35U)) + 6645399144515770935U) + aNonceWordC;
            aOrbiterD = (aWandererD + RotL64(aScatter, 57U)) + 3608978423753715584U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 8089198857670370983U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 15207251813516399879U) + aNonceWordA;
            aOrbiterK = (aWandererI + RotL64(aCross, 14U)) + 9579268660105824516U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 41U)) + 16055044469473802812U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 23U)) + 583811872609805949U) + aPhaseDOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 39U)) + 7027491967970873942U) + aNonceWordJ;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18256061823189677508U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12708429127816136937U;
            aOrbiterI = RotL64((aOrbiterI * 12593886633108075321U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12169216645156306078U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12694325407567795065U;
            aOrbiterA = RotL64((aOrbiterA * 3711789483877261899U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16109994660203297503U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4234704064165718913U;
            aOrbiterK = RotL64((aOrbiterK * 730085881474787681U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14119541943554602878U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8777769004811352951U;
            aOrbiterB = RotL64((aOrbiterB * 2556957257736134223U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 15642663488392549609U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11594468530833278624U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6639306656361601143U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7365350535791499871U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5965170981970155956U;
            aOrbiterC = RotL64((aOrbiterC * 1898702752753066851U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9115232101451815522U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9433983580038990072U;
            aOrbiterH = RotL64((aOrbiterH * 1951249217843992179U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8810565477444156140U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12081286530401844859U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1991383259486140229U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7498045374283306625U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13095973566401200720U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 2657451581036351987U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 18205793828042507364U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3339020890428651569U;
            aOrbiterG = RotL64((aOrbiterG * 10195916881103252701U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16957913958369950483U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1042610313571524121U;
            aOrbiterD = RotL64((aOrbiterD * 11206619213970727629U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 26U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 44U) + RotL64(aOrbiterK, 37U)) + aOrbiterC) + aNonceWordE);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 13U)) + aOrbiterJ) + aNonceWordF) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterG, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 46U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterH) + aPhaseDWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterA, 39U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 48U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 53U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterB, 41U));
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 22U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30944U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 31260U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30518U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 27999U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCarry, 39U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererE + RotL64(aPrevious, 3U)) + 3973833383430652211U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 43U)) + 5760227042747169187U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 52U)) + 4923009065139227286U;
            aOrbiterE = ((((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 1477807307009107590U) + aPhaseDOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 5707194514329007301U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 5340439728375269724U) + aNonceWordO;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 57U)) + 17080457898946572387U;
            aOrbiterB = (aWandererK + RotL64(aCross, 34U)) + 281559150259472813U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 41U)) + 16160633048230910560U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 27U)) + 9003989610509592121U) + aPhaseDOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aPrevious, 29U)) + 10579322462808454333U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15059383289528723069U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10417647757852880956U;
            aOrbiterG = RotL64((aOrbiterG * 1457919230286043137U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 14484665027393813330U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12344463053485837974U;
            aOrbiterF = RotL64((aOrbiterF * 5762654194001525041U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5826453246659297805U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12547902286376986223U;
            aOrbiterK = RotL64((aOrbiterK * 2982850000322672789U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9637855144278126174U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2132744427444501938U;
            aOrbiterI = RotL64((aOrbiterI * 5911587798564836199U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9248933938130311231U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13274297928717090383U;
            aOrbiterB = RotL64((aOrbiterB * 2901398809555237563U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3690262236918560930U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 3626005326410800344U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13030443356669355355U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10801089744186148218U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5446653082176311031U;
            aOrbiterA = RotL64((aOrbiterA * 4594267575901248321U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3205541585889107366U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 4532327942368884436U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 16287094987689326229U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9755333481079721632U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 722154154363571049U;
            aOrbiterH = RotL64((aOrbiterH * 11002432494248958957U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8071668483354405205U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8770466248803121315U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 12780438190628717807U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1999251593502332271U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3973833383430652211U;
            aOrbiterE = RotL64((aOrbiterE * 5325244982474631559U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 56U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordF) + aPhaseDWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterH, 36U));
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 47U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterK, 39U)) + aOrbiterF) + aNonceWordM) + aPhaseDWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 24U) + aOrbiterI) + RotL64(aOrbiterH, 41U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterK, 3U));
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterE, 13U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 19U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 28U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 50U) + aOrbiterA) + RotL64(aOrbiterI, 57U));
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererH, 10U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_Fencing_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFE66649D5F64EDFFULL + 0x9AFBF81BDF964F13ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBD1F29B4A6082AEFULL + 0x93DEB6E30DEE89B9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBFE0F7FB3CF9FA2DULL + 0xEE51AA6CBC1567FEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEFD2D8C64AFAD9E9ULL + 0xE04292F2176AFDBEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x903BFBDF138E952DULL + 0x99FCB44852D3ED71ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x80854D7B20C52731ULL + 0x85CB64B2AD431EFDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD8F8D20270D79AFDULL + 0x959EF1E2079542E9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xAF3B76234A8E4CE3ULL + 0xF02F872DF69B3750ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFB44D690217AC88BULL + 0xA78117B3B101095EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC9CBCB31324E6905ULL + 0x8EF058DB672CCA11ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA9ED013ABEE79C89ULL + 0xC2E08BC45D20F332ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC7C457FE96A22CC5ULL + 0xEAA59982FB3E329DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFBAE3381544564DFULL + 0xA2FD8B6D5C2A0A45ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD7150C36C0552BF1ULL + 0x820C4BF2F009B920ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x86A5B45F2449C929ULL + 0xC4E6A7D7FC264B5DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFEC9D1A10DBE2389ULL + 0xB1BCF617E8724CABULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2566U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2409U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 571U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((aIndex + 3849U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 21U)) ^ (RotL64(aCarry, 34U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 9041099828460168106U) + aPhaseEOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aIngress, 22U)) + 12883711604096848454U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 53U)) + 17420968786226443079U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aPrevious, 39U)) + 3448213891716125104U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 11866455977445336560U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 37U)) + 4119356835384495905U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 14U)) + 2186212599698637068U) + aNonceWordH;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 6506144898969301620U) + aNonceWordO;
            aOrbiterC = (aWandererG + RotL64(aScatter, 19U)) + 12556800923644051626U;
            aOrbiterG = (aWandererB + RotL64(aCross, 29U)) + 4075551535185182945U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 47U)) + 17877694808492008749U) + aNonceWordK;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5553428900598223316U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 14362304852277160675U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11415103199856419303U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9174200302876075831U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16110739511917638547U;
            aOrbiterD = RotL64((aOrbiterD * 7004356839428657949U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10189881974519849402U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2128076632642616677U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8860453653433114929U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 18133523799074400083U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9916472958834153766U;
            aOrbiterH = RotL64((aOrbiterH * 3454601168808001733U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10274457562795569227U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14134814273275356425U;
            aOrbiterJ = RotL64((aOrbiterJ * 15912501063665343159U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6394306369514735480U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4825761192736485643U;
            aOrbiterC = RotL64((aOrbiterC * 12534544147331805643U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5672807934779206275U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3881953574159390421U;
            aOrbiterF = RotL64((aOrbiterF * 7448770570912161095U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12012232712634303203U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 14176392925893052596U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11288668529893084583U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 307148402076391033U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15380446373458263079U;
            aOrbiterB = RotL64((aOrbiterB * 15228462337097647933U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 4654312690816676129U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10818029316701301859U;
            aOrbiterA = RotL64((aOrbiterA * 16245734506125913215U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 7340370713289840635U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9041099828460168106U;
            aOrbiterG = RotL64((aOrbiterG * 1807356802142268373U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 34U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterK, 37U));
            aWandererG = aWandererG + (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 51U)) + aOrbiterB) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterI, 30U));
            aWandererH = aWandererH + ((RotL64(aCross, 34U) + RotL64(aOrbiterH, 23U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 11U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 41U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 5U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 23U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + aNonceWordL) + aPhaseEWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterF, 48U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 40U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 6040U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 9312U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10815U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9317U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCross, 37U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 15813325389431304548U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 48U)) + 2223874171125403602U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 51U)) + 5510483568496824130U;
            aOrbiterK = (aWandererH + RotL64(aCross, 23U)) + 15474152493495661876U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 41U)) + 16846339705130829195U;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 51U)) + 1289670576865739669U) + aNonceWordA;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 56U)) + 18017354919647006944U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aScatter, 13U)) + 8539685539928984921U) + aNonceWordP;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 53U)) + 3333721400836704048U) + aPhaseEOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 2261560416623815491U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 37U)) + 4377786131746816567U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 18047393176583722719U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8184724021940434631U;
            aOrbiterG = RotL64((aOrbiterG * 9800116157750921119U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10469895939183324807U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 14543391765109879223U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 4817987697437667225U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5757225781746158178U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3539000495894022869U;
            aOrbiterA = RotL64((aOrbiterA * 1032298408884695925U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11288971092707065923U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2761384065186568294U;
            aOrbiterJ = RotL64((aOrbiterJ * 3323838837427471051U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7120580145300417101U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6977246291769372866U;
            aOrbiterD = RotL64((aOrbiterD * 15170353875184253779U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17625434527765525937U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3299714663631376190U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6532628892760776767U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10331889953489885250U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8550932256881727932U;
            aOrbiterK = RotL64((aOrbiterK * 13085531621192583719U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11151195711186126257U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2552002192824926483U;
            aOrbiterC = RotL64((aOrbiterC * 9754056316698523849U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8038115194286715268U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16594489591573505305U;
            aOrbiterB = RotL64((aOrbiterB * 1241387574663818247U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13476964484361081681U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2136330439951908303U;
            aOrbiterF = RotL64((aOrbiterF * 12728359054660550527U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 231990686776499700U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15813325389431304548U;
            aOrbiterE = RotL64((aOrbiterE * 9155088985405261637U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 18U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterA, 23U)) + aNonceWordN) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 26U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterC, 41U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 11U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 47U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterF, 29U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 20U) + aOrbiterC) + RotL64(aOrbiterE, 6U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterK, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 39U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 22U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11573U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 15793U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14737U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15945U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 42U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 6521330037475130256U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 29U)) + 12611880456055428940U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 23U)) + 12061611078130934708U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 60U)) + 1558112410801116984U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 19U)) + 10509115227850160786U) + aNonceWordE;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 57U)) + 4045915960688792066U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 43U)) + 1196541286513243082U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 6U)) + 15564991032722373702U) + aNonceWordH;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 3U)) + 4897765238703641798U;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 39U)) + 12327429514907752733U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 6189189797708711636U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 6374267075282018852U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1888758503831341439U;
            aOrbiterB = RotL64((aOrbiterB * 74387714918264257U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14956857689299491800U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14879361107223331957U;
            aOrbiterE = RotL64((aOrbiterE * 9166712966729591953U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16086885494838105042U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8069724185844303923U;
            aOrbiterJ = RotL64((aOrbiterJ * 8878470736758734353U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10854345917959911439U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7078313614360332089U;
            aOrbiterH = RotL64((aOrbiterH * 9864025732292844871U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15083669236062255011U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 594879695916679116U;
            aOrbiterF = RotL64((aOrbiterF * 9852515479152735283U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6721466068234534523U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 475816724162626782U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 4799725182757588407U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 4341655358154605899U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15477254302340298586U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13961520225881974201U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10179091913200895775U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6310490897546909571U;
            aOrbiterK = RotL64((aOrbiterK * 15080621088825477613U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13462682513035460711U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16739138858084100385U;
            aOrbiterA = RotL64((aOrbiterA * 16386371811268298031U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13608837667062268989U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12902415667552110103U;
            aOrbiterI = RotL64((aOrbiterI * 16398790854093048017U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16596211634603915761U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6521330037475130256U;
            aOrbiterD = RotL64((aOrbiterD * 631958426544321145U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 22U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterD, 41U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterG, 12U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 19U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 54U)) + aOrbiterE) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aIngress, 34U) + RotL64(aOrbiterK, 23U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 27U)) + aOrbiterA) + aNonceWordP);
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterB, 21U));
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterA, 37U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20813U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 20168U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16879U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16393U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 18U) + RotL64(aCarry, 47U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 54U)) + RotL64(aCarry, 5U)) + 12583180859826261500U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 57U)) + 9067093488553721468U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 12173106198862881754U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aScatter, 29U)) + 11333491014394592654U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 51U)) + 3511883526940919554U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 41U)) + 7416810692106273044U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 39U)) + 8341174972619784110U;
            aOrbiterC = (aWandererF + RotL64(aCross, 43U)) + 2220852854836962979U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 14U)) + 8090781422229383825U) + aPhaseEOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 2338801236599102223U) + aNonceWordD;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 3U)) + 12484514711848308104U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13684861340589131816U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12796636819991873058U;
            aOrbiterB = RotL64((aOrbiterB * 5533508014234835669U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7634198650894837690U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 10240326122201201762U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 8758703497719125901U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4162814763739453934U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2766504649149048469U;
            aOrbiterI = RotL64((aOrbiterI * 16731843453895178671U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11051393030148769655U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17687055068651386665U;
            aOrbiterD = RotL64((aOrbiterD * 1042927176246229537U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3353615315436983420U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5971640796220306310U;
            aOrbiterC = RotL64((aOrbiterC * 15804313508835034807U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12299773092762384765U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7435804907797063411U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9848139805288165965U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8735783937125735699U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11903126115475835615U;
            aOrbiterJ = RotL64((aOrbiterJ * 16942088822124940265U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4427166023462475475U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6011733469446008137U;
            aOrbiterE = RotL64((aOrbiterE * 17298067225913923517U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 18341473946127677319U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5423774915753911947U;
            aOrbiterG = RotL64((aOrbiterG * 14985099502923458523U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2384393657884193014U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2650593524388493958U;
            aOrbiterH = RotL64((aOrbiterH * 892985816665547945U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 15991261431384033176U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12583180859826261500U;
            aOrbiterK = RotL64((aOrbiterK * 14394838775646875599U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterF, 58U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 13U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 51U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 53U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterK, 37U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 48U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 41U));
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + aPhaseEWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 26U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 21U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23416U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 21954U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26811U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 22479U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 19U)) + (RotL64(aCross, 38U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aScatter, 39U)) + 6771552164800695068U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 22U)) + RotL64(aCarry, 3U)) + 12131763371571322040U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 41U)) + 3326182381395522013U) + aNonceWordG;
            aOrbiterF = (aWandererC + RotL64(aCross, 57U)) + 12288775097697156383U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 51U)) + 5195948373449796741U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 11U)) + 14404044002250137144U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 39U)) + 11142382920035825426U) + aNonceWordI;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 26U)) + 2967149520256475485U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 13U)) + 1470907369577818097U) + aPhaseEOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 9231668148004163910U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 3U)) + 13078929163913892386U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9485274692075657877U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12216951187543631673U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 6571066246507310805U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6933334652581744234U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17260276102423580920U;
            aOrbiterI = RotL64((aOrbiterI * 7796879893790990605U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 387767848169714392U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8597538259308082638U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4888054690557707241U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7996708724489146033U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15357384191688149939U;
            aOrbiterG = RotL64((aOrbiterG * 9827691726832491373U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17739222908739454637U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1614322333281471170U;
            aOrbiterD = RotL64((aOrbiterD * 7063116837752240891U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 4531604274893197209U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3453280714992341288U;
            aOrbiterF = RotL64((aOrbiterF * 8390029711127907805U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 116623650872661533U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 6565636510115095988U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 9691897067492501177U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10303258439817808058U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10917642773040237611U;
            aOrbiterE = RotL64((aOrbiterE * 10232856828372963363U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2087058228468680821U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3691125545393861889U;
            aOrbiterC = RotL64((aOrbiterC * 1768745056298937903U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9240209357066002219U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7645250700232422804U;
            aOrbiterK = RotL64((aOrbiterK * 6762116797395687607U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9859862257084218280U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6771552164800695068U;
            aOrbiterB = RotL64((aOrbiterB * 11063630807191661109U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 6U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 34U) + RotL64(aOrbiterE, 6U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterG, 23U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB) + aPhaseEWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterB, 11U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterC, 50U)) + RotL64(aCarry, 41U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aIngress, 18U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterF, 41U)) + aNonceWordL);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 27U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererB, 50U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30428U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneB[((aIndex + 28893U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28426U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 28763U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 24U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aCross, 47U)) + 12380376990224645149U) + aPhaseEOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 42U)) + RotL64(aCarry, 13U)) + 18296928500297384014U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 3550626816361145100U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 23U)) + 2667792936946706027U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 57U)) + 12020969779370926953U) + aNonceWordL;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 21U)) + 737340727886903447U) + aNonceWordK;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 1681797651799760502U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 27U)) + 2956186342689489064U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 36U)) + 1876852870402977177U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 39U)) + 6433205819353555071U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 11U)) + 9065076854974222998U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3254410578766789992U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2005081975473815576U;
            aOrbiterH = RotL64((aOrbiterH * 9947701153722014085U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15992999234834560419U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3458344156815120948U;
            aOrbiterI = RotL64((aOrbiterI * 1668460113964608051U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 17069783053664877727U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1260234710193913099U;
            aOrbiterG = RotL64((aOrbiterG * 4561226779897414381U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3825186451876061335U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2905344294992827535U;
            aOrbiterK = RotL64((aOrbiterK * 2469896090698580795U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 18141402347899180617U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8760129857609925066U;
            aOrbiterJ = RotL64((aOrbiterJ * 2507999156108123047U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 594052473780678210U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13216719212966128379U;
            aOrbiterF = RotL64((aOrbiterF * 10691355329696722303U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10029948739466316169U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11912428807431992996U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 85016510811938307U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8735634019801417287U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12785916159063273545U;
            aOrbiterE = RotL64((aOrbiterE * 1161917531260663357U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 367752057919802452U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3961036242431041564U;
            aOrbiterA = RotL64((aOrbiterA * 16352646009782597315U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3858415336170090719U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14325258358254321551U;
            aOrbiterC = RotL64((aOrbiterC * 12080431158781060059U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16872184337970977180U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 12380376990224645149U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16559121155413059221U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 52U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterE, 26U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterF, 37U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterE) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterI, 11U));
            aWandererB = aWandererB + ((RotL64(aScatter, 18U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterF, 41U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 51U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordO;
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

void TwistExpander_Fencing_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB8B38384C1F8BF0BULL + 0xDF1B21E80CE394C3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA0F51A8242934097ULL + 0x87D841DCC42E4940ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB6CBCC0D754FAF2DULL + 0xDC3EF35A15EAC5DEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA1BCB0B20A85C22BULL + 0xFF60C1BE5435DBD7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8E337D1724285423ULL + 0xA0D302A3C1096E38ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x88D2E2EF195D82B9ULL + 0xC92C2322059DE1C3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9B1457B1558CEF75ULL + 0xCB93E5A60077B25AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF010CA7FD41F1873ULL + 0xB82411726B2CF4A1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE15D5E5C9853E665ULL + 0xAB906AAD5389E807ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA9F30B66D6D289BBULL + 0xC104F908DE6F2528ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDA681384DA7ACD89ULL + 0xD761390A47213120ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE5053A35E1C9F25DULL + 0x80EFECC1C1AB78A1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFA76C7B2A26AB317ULL + 0xDF2B94BA42DD6ACEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCE81F418299DFFE9ULL + 0x8C6DC4648168CED1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB5E464908C93AA2FULL + 0x919CFC4B89ACCCCBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x98E2FCC2D6E857BFULL + 0x92EAC96FA3D0FD3DULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3260U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 1158U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5296U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 5020U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 13U) ^ RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aIngress, 29U)) + 785861751704720606U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 44U)) + 15968088718435606299U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 41U)) + 1393976526590347151U;
            aOrbiterI = (aWandererE + RotL64(aCross, 57U)) + 17240750947292745884U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 35U)) + 4921576136163183137U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 11U)) + 3334047873553153032U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 15086509978458408698U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 892391205397581998U) + aPhaseFOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aCross, 51U)) + 2965686403183767521U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 5U)) + 14632215393655706170U) + aNonceWordF;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 24U)) + RotL64(aCarry, 29U)) + 15740589515342377322U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 11131164813943086445U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6988080581278900960U;
            aOrbiterE = RotL64((aOrbiterE * 6412189142344044255U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 16021254613117657178U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6183615599897921154U;
            aOrbiterD = RotL64((aOrbiterD * 9976411093264211033U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12533992547026652747U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3104325358982904219U;
            aOrbiterH = RotL64((aOrbiterH * 14977348108778147265U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3878525937957474644U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2120435259884368445U;
            aOrbiterI = RotL64((aOrbiterI * 15964718652193073177U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14928658302694194856U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9121310461310309348U;
            aOrbiterG = RotL64((aOrbiterG * 17304439784647477491U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3715693239100476493U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7336577492932262490U;
            aOrbiterC = RotL64((aOrbiterC * 11074754160002665253U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2312452827448455675U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4322756069651934618U;
            aOrbiterJ = RotL64((aOrbiterJ * 6908893297397073539U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 4962079617577705818U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5072727464750706525U;
            aOrbiterB = RotL64((aOrbiterB * 4947670001221089155U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4553791875259778686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15823770920225774233U;
            aOrbiterK = RotL64((aOrbiterK * 409663191536830375U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 9468608484284459072U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8658861660659699947U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 2933359123761406353U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 14453429515273506170U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 785861751704720606U;
            aOrbiterA = RotL64((aOrbiterA * 3544627380583668815U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 23U);
            aIngress = aIngress + (RotL64(aOrbiterC, 18U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 56U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterG, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterB, 43U)) + aPhaseFWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 34U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterA, 60U));
            aWandererG = aWandererG + (((((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 27U)) + aNonceWordM) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterD, 39U));
            aWandererE = aWandererE + ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 5U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 50U) + aOrbiterF) + RotL64(aOrbiterG, 27U)) + aNonceWordD);
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5779U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 8063U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5818U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((aIndex + 5825U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 26U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aScatter, 41U)) + 1042610313571524121U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 60U)) + 3505725321008825582U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 37U)) + 12584654563843782991U;
            aOrbiterC = (aWandererI + RotL64(aCross, 5U)) + 6645399144515770935U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 13U)) + 3608978423753715584U) + aNonceWordE;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 8089198857670370983U) + aNonceWordI;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 15207251813516399879U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 50U)) + 9579268660105824516U) + aPhaseFOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aWandererB + RotL64(aIngress, 23U)) + 16055044469473802812U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 11U)) + 583811872609805949U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 7027491967970873942U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 18256061823189677508U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12708429127816136937U;
            aOrbiterB = RotL64((aOrbiterB * 12593886633108075321U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12169216645156306078U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12694325407567795065U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 3711789483877261899U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16109994660203297503U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4234704064165718913U;
            aOrbiterJ = RotL64((aOrbiterJ * 730085881474787681U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14119541943554602878U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 8777769004811352951U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2556957257736134223U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15642663488392549609U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11594468530833278624U;
            aOrbiterE = RotL64((aOrbiterE * 6639306656361601143U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7365350535791499871U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5965170981970155956U;
            aOrbiterK = RotL64((aOrbiterK * 1898702752753066851U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9115232101451815522U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9433983580038990072U;
            aOrbiterC = RotL64((aOrbiterC * 1951249217843992179U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8810565477444156140U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12081286530401844859U;
            aOrbiterD = RotL64((aOrbiterD * 1991383259486140229U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7498045374283306625U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13095973566401200720U;
            aOrbiterF = RotL64((aOrbiterF * 2657451581036351987U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18205793828042507364U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3339020890428651569U;
            aOrbiterA = RotL64((aOrbiterA * 10195916881103252701U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 16957913958369950483U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1042610313571524121U;
            aOrbiterG = RotL64((aOrbiterG * 11206619213970727629U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 28U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 23U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterB, 50U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 12U) + RotL64(aOrbiterK, 41U)) + aOrbiterH) + aNonceWordN) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 53U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 52U) + aOrbiterA) + RotL64(aOrbiterI, 46U)) + aNonceWordK) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 39U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterH, 21U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererI, 14U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13507U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16352U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12338U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15028U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 40U)) + (RotL64(aIngress, 21U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererG + RotL64(aIngress, 27U)) + 13687218104610230596U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 46U)) + RotL64(aCarry, 5U)) + 6841550124960692709U;
            aOrbiterC = (aWandererB + RotL64(aCross, 39U)) + 17418968668458764131U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 53U)) + 8303537912696948204U;
            aOrbiterE = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 12376614417285936537U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 14215749063579232654U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 14U)) + 4111736931433665347U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 3U)) + 11250375934571631522U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 23U)) + 5367367837773331275U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 5U)) + 15514089192382674434U) + aPhaseFOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 57U)) + 1475991716685034960U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5531622777788629748U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8363822215908303335U;
            aOrbiterC = RotL64((aOrbiterC * 17850203366840994883U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3741256932685720414U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11634667238062155772U;
            aOrbiterB = RotL64((aOrbiterB * 15925089729784547403U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18180546911210417155U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5123234656838556335U;
            aOrbiterI = RotL64((aOrbiterI * 15362857462853398025U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11215734271189250284U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16863747802158398092U;
            aOrbiterE = RotL64((aOrbiterE * 1828035970246160023U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9859050606636646323U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9331300036643654675U;
            aOrbiterF = RotL64((aOrbiterF * 2502263410556166281U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15028845665427209759U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8916444839488901676U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 6646561894156038791U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8024631140949068570U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1116378858490660031U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 4247798531910227367U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5066486214537899212U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9346312092322423057U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13443190089768875191U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 11651011617027950122U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11308862427412671711U;
            aOrbiterD = RotL64((aOrbiterD * 12167147966934334703U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3850136281462840708U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13461307727665667424U;
            aOrbiterH = RotL64((aOrbiterH * 10788040812090673421U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17824744996404571928U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13687218104610230596U;
            aOrbiterJ = RotL64((aOrbiterJ * 325803029547254631U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 24U) + RotL64(aOrbiterG, 57U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterH, 29U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterF, 50U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 13U));
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 27U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + aNonceWordL);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 46U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterD, 35U));
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20624U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19330U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21290U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((aIndex + 18216U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 11U) + RotL64(aIngress, 60U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 13204735390996728477U;
            aOrbiterF = (aWandererA + RotL64(aCross, 35U)) + 851171359595647173U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 44U)) + 16745304202825290723U) + aNonceWordK;
            aOrbiterK = (aWandererI + RotL64(aIngress, 5U)) + 562392736584913979U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 27U)) + 3244267012529053918U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 17282536111067869133U) + aPhaseFOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 52U)) + 14851130066471729068U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 5256130407952363129U;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 11U)) + 2904742485828362001U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aWandererD + RotL64(aCross, 3U)) + 3723346325449225387U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 19U)) + 5344621093694027341U) + aNonceWordB;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12919263300833603026U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17989801264160996071U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15468293047311883751U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5022175042377172157U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16684822380107847758U;
            aOrbiterI = RotL64((aOrbiterI * 2834049270263837537U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2740326510600876682U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13981423865219318820U;
            aOrbiterB = RotL64((aOrbiterB * 14593082145080056441U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 231945878229848395U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14139797734944312580U;
            aOrbiterD = RotL64((aOrbiterD * 6492256080432266407U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16704102101387552373U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8506734780526852552U;
            aOrbiterC = RotL64((aOrbiterC * 4684566118627414659U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2774630043988894695U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12490034334296488127U;
            aOrbiterG = RotL64((aOrbiterG * 16765455396278233145U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 545238171291436006U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1023872898002379590U;
            aOrbiterA = RotL64((aOrbiterA * 8626333831510136515U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5065187021047872560U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10391809965648089863U;
            aOrbiterJ = RotL64((aOrbiterJ * 10912471108849550469U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5576919045471579002U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9761904001375034639U;
            aOrbiterE = RotL64((aOrbiterE * 8612901811320541361U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2001472279505185946U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11576457012366242134U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1070815118051466731U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17713147845216099336U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13204735390996728477U;
            aOrbiterK = RotL64((aOrbiterK * 10889281795183444943U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 30U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 50U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 11U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 39U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterC, 5U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 46U) + RotL64(aOrbiterJ, 18U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 21U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterC, 3U)) + aNonceWordA);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterE, 13U)) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 22U) + aOrbiterJ) + RotL64(aOrbiterF, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24553U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 22901U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25325U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 22900U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererB + RotL64(aIngress, 44U)) + RotL64(aCarry, 41U)) + 8375305456876489425U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 19U)) + 16193562952772453047U;
            aOrbiterA = (aWandererG + RotL64(aCross, 41U)) + 18088652458594816223U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 21U)) + 767344788620249944U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 23U)) + 7705194930396368752U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 51U)) + 3829736891311272834U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 48U)) + 9881681671347640061U) + aNonceWordF;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 53U)) + 1721196560190164264U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 3002652618388454213U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 11U)) + 9811621464004005202U;
            aOrbiterI = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 5652598941069986530U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6250499348327316328U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16025054277615264530U;
            aOrbiterA = RotL64((aOrbiterA * 16446892258704281903U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13800298546867243172U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12256104592865905782U;
            aOrbiterH = RotL64((aOrbiterH * 16983140179497142713U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17817225416918329229U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17738671327352776217U;
            aOrbiterG = RotL64((aOrbiterG * 393488251327705063U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6816031224188400541U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16989563985059237014U;
            aOrbiterD = RotL64((aOrbiterD * 8677884225771717797U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16891524847268207549U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 1833508573940405571U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9709196587703979539U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12729999421507068973U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6839758643521968957U;
            aOrbiterJ = RotL64((aOrbiterJ * 16350557395881283975U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8524167125469267428U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14741523560290472617U;
            aOrbiterB = RotL64((aOrbiterB * 4367850822282205897U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10983798459868424892U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 5649250846622078964U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7149612714806023987U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8587302028325090061U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17457129226030333666U;
            aOrbiterI = RotL64((aOrbiterI * 18107356450566915215U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15600113588474915690U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6595247491374683783U;
            aOrbiterK = RotL64((aOrbiterK * 1432432381540098765U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13246325856585534283U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8375305456876489425U;
            aOrbiterF = RotL64((aOrbiterF * 8331406038795786099U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (RotL64(aOrbiterH, 24U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 6U) + aOrbiterD) + RotL64(aOrbiterF, 54U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 27U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 29U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 3U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aIngress, 54U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 11U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 21U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterE, 57U)) + aNonceWordI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 41U)) + aOrbiterK) + aPhaseFWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterH, 50U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 46U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29069U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 32344U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29868U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28506U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 52U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aPrevious, 27U)) + 13053031069776604052U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 1331396630251085122U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 52U)) + 15879286043343942393U) + aNonceWordA;
            aOrbiterH = (aWandererD + RotL64(aScatter, 41U)) + 13590365633321406830U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 14569235423040242618U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 39U)) + 11397370636618371560U) + aNonceWordK;
            aOrbiterA = (aWandererA + RotL64(aIngress, 43U)) + 3455933494593971847U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 35U)) + 1307153376443784593U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 23U)) + 10688618762584786871U) + aPhaseFOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 18U)) + RotL64(aCarry, 51U)) + 17746248451153600096U) + aNonceWordC;
            aOrbiterF = (aWandererJ + RotL64(aCross, 29U)) + 8512568600755410158U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8950230550112591092U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17790968369472845496U;
            aOrbiterK = RotL64((aOrbiterK * 5104988920132008913U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12583323865381967534U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11243927099685293887U;
            aOrbiterE = RotL64((aOrbiterE * 12867003042486433971U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9690268715525781389U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7466066217365074653U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17565696765505320889U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 3673528673209875118U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14079103852360952255U;
            aOrbiterA = RotL64((aOrbiterA * 17449228863409999629U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6747836856132250630U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5027692924422297153U;
            aOrbiterC = RotL64((aOrbiterC * 2492421273167124437U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11370341866003395776U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14013204893442579282U;
            aOrbiterB = RotL64((aOrbiterB * 6602239957997240785U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3436953430697936790U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6399073534839993637U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 14186050072610021241U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7054057507823631422U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5752085719673338095U;
            aOrbiterF = RotL64((aOrbiterF * 13252660162476029593U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10628323020010327594U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5029617362660411790U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 7230663968894173433U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6816547880074551571U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6683840259024813282U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 13145224557159574541U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5952768353050729617U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13053031069776604052U;
            aOrbiterH = RotL64((aOrbiterH * 13710064584055068065U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 10U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 58U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterD, 37U)) + aOrbiterE) + aNonceWordG);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 27U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 3U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + aNonceWordL) + aPhaseFWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 13U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 60U)) + aOrbiterA) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordF);
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

void TwistExpander_Fencing_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEDF8C393E58DB8CFULL + 0xC7832F0CA517592DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9792D47C4683F71FULL + 0x97824ED3474647CCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA6ADEC5FA12BF707ULL + 0xA380BB497C76DA9CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCFCBF45DA65177FFULL + 0xF26B4C31AAAE5824ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x96363937AFA7EF0DULL + 0x918935BA6C9656D6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9621C4D93777FA37ULL + 0xBDE913B8AA1CB774ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDB352E0C51CED405ULL + 0x8752D8CED3342E17ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBD33234C7E4FD753ULL + 0xFCC711BD03B7324FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF8BAF49C3861AED3ULL + 0xB52371016BDF7165ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA61ED3C357901441ULL + 0x9F07B04182E8E617ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA402CF330DEA6BC3ULL + 0xE9E8BA7EA9593A3AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDD05A5C9BA4EEF27ULL + 0xD5283793ACC0946CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9CE7DA48F06FFC5DULL + 0xA189D882DF1BEA48ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9F9CFF735FCA3A67ULL + 0xCB3474AB267E676BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA2A919209B2C6683ULL + 0x82ABA43579D3DAE9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF0A79FFF4C052B1FULL + 0xFED66498CACF623DULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5413U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 2624U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1861U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 2519U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 60U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aPrevious, 21U)) + 10915618884692072446U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 12634922308499254909U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 60U)) + 6533934734564499389U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 37U)) + 6744203303756105181U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 57U)) + 13086782386652045658U) + aNonceWordP;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 51U)) + 5693840533331397822U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 1803663542535024611U) + aNonceWordF;
            aOrbiterC = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 3597219300593287708U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 53U)) + 1429753448204448904U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 13U)) + 17229017825587322715U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 4U)) + 1137574712801062932U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2401991077004083378U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1332473247826139292U;
            aOrbiterA = RotL64((aOrbiterA * 15029831858261506447U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 11730946340796899885U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15319163439700390962U;
            aOrbiterE = RotL64((aOrbiterE * 1349242001887975499U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4744141870145159917U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6067132201862688684U;
            aOrbiterK = RotL64((aOrbiterK * 6046100687757836027U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14991509179286371800U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4342608825699398682U;
            aOrbiterJ = RotL64((aOrbiterJ * 10240526103933275875U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3727521409410742075U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3302027219498304367U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 12153634588200479559U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6039539483340398858U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2902581519976937051U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2057584328877854239U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12332784713738947242U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13761272577223712786U;
            aOrbiterD = RotL64((aOrbiterD * 14930145045480030821U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2947946397617043735U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11107014023853644521U;
            aOrbiterF = RotL64((aOrbiterF * 15030903626191481831U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6212403196992771516U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16107261731677426470U;
            aOrbiterB = RotL64((aOrbiterB * 13764822942405295129U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8414111492161335472U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3625937496991123221U;
            aOrbiterC = RotL64((aOrbiterC * 1736741235159600739U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5466667339391480293U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10915618884692072446U;
            aOrbiterI = RotL64((aOrbiterI * 14719282928172086707U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 38U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterG, 56U));
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterB, 5U)) + aNonceWordM) + aPhaseFWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 50U) + aOrbiterI) + RotL64(aOrbiterG, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 51U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterK, 29U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + aPhaseFWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 28U) + aOrbiterD) + RotL64(aOrbiterG, 13U));
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterF, 54U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6557U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((aIndex + 6116U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10766U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 5935U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aCross, 35U)) + 9041099828460168106U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 56U)) + 12883711604096848454U) + aNonceWordO;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 53U)) + 17420968786226443079U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aPrevious, 19U)) + 3448213891716125104U;
            aOrbiterH = (aWandererK + RotL64(aCross, 3U)) + 11866455977445336560U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 4119356835384495905U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 2186212599698637068U) + aNonceWordP;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 6506144898969301620U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 44U)) + 12556800923644051626U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 11U)) + 4075551535185182945U) + aNonceWordK;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 47U)) + 17877694808492008749U) + aPhaseFOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 5553428900598223316U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14362304852277160675U;
            aOrbiterI = RotL64((aOrbiterI * 11415103199856419303U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9174200302876075831U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16110739511917638547U;
            aOrbiterF = RotL64((aOrbiterF * 7004356839428657949U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10189881974519849402U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2128076632642616677U;
            aOrbiterH = RotL64((aOrbiterH * 8860453653433114929U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 18133523799074400083U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9916472958834153766U;
            aOrbiterC = RotL64((aOrbiterC * 3454601168808001733U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10274457562795569227U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14134814273275356425U;
            aOrbiterJ = RotL64((aOrbiterJ * 15912501063665343159U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6394306369514735480U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4825761192736485643U;
            aOrbiterB = RotL64((aOrbiterB * 12534544147331805643U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5672807934779206275U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3881953574159390421U;
            aOrbiterE = RotL64((aOrbiterE * 7448770570912161095U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 12012232712634303203U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14176392925893052596U;
            aOrbiterA = RotL64((aOrbiterA * 11288668529893084583U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 307148402076391033U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 15380446373458263079U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15228462337097647933U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4654312690816676129U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10818029316701301859U;
            aOrbiterD = RotL64((aOrbiterD * 16245734506125913215U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7340370713289840635U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9041099828460168106U;
            aOrbiterK = RotL64((aOrbiterK * 1807356802142268373U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 26U);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 19U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterB, 48U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 11U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterE, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterG, 39U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 53U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 54U) + aOrbiterB) + RotL64(aOrbiterK, 14U));
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 27U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterG, 29U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13443U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15652U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13849U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 11939U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 28U)) ^ (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 3U)) + 12535417189990029950U;
            aOrbiterK = ((((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 6204401443676390273U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererE + RotL64(aCross, 51U)) + 869613505613154672U) + aNonceWordJ;
            aOrbiterE = (aWandererC + RotL64(aIngress, 21U)) + 15053590879563855802U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 56U)) + 13338989605204591428U) + aNonceWordP;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 18306470022403825392U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 11U)) + 1150696349434090218U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aScatter, 5U)) + 13549541786420596437U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 19U)) + 14302878430259588461U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 38U)) + 4660437084477165225U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 1653628537860912069U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5594199757006711631U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11008472193138708891U;
            aOrbiterB = RotL64((aOrbiterB * 13645764762027798301U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3668516817279364310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 128159531749679984U;
            aOrbiterG = RotL64((aOrbiterG * 4523246859249826987U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6378674346113979108U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11438762460659123362U;
            aOrbiterK = RotL64((aOrbiterK * 2733309638158283953U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10624263004446482910U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12546839706919241411U;
            aOrbiterA = RotL64((aOrbiterA * 11468326687628079347U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8466639576503293921U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5828694979857951504U;
            aOrbiterD = RotL64((aOrbiterD * 7835487310289634515U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16496305151014092976U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 589464613876410567U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 13190816610718051897U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4168532743415647825U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15944887793736489375U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17273403561158196717U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 11642456814106259483U) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1609897693632334867U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12912773555616819941U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14950238412766325479U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11862438528287402255U;
            aOrbiterJ = RotL64((aOrbiterJ * 7635864312080265695U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5900629306795222263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3221591991392500536U;
            aOrbiterH = RotL64((aOrbiterH * 7188525011266868855U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16938699391746264010U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12535417189990029950U;
            aOrbiterC = RotL64((aOrbiterC * 18212319484142613215U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 14U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterA, 41U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 37U)) + aOrbiterK) + aNonceWordL);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterF, 28U)) + aNonceWordO) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterI, 11U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterE, 13U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterF, 56U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 3U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 24U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19546U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 18077U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20385U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17800U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 22U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererH + RotL64(aPrevious, 47U)) + 2330952702412094686U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 37U)) + 7820188225935060799U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 41U)) + 9347644591709839145U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 27U)) + 2288624878446846870U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 14U)) + 9358977729492824128U;
            aOrbiterI = ((((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 1858511275052455039U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 21U)) + 13715478509322292552U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 3U)) + 16413396625604260455U) + aNonceWordL;
            aOrbiterG = (aWandererB + RotL64(aCross, 5U)) + 17714322215518432705U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 18U)) + RotL64(aCarry, 53U)) + 16188315436202861122U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 5564445841368207813U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13717068949900594673U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14143659432287313765U;
            aOrbiterH = RotL64((aOrbiterH * 17281441046722262917U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5729546141908425670U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4297827922736712074U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13631630436759768885U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 829520109395163673U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11547160328525174295U;
            aOrbiterI = RotL64((aOrbiterI * 4759690159673049775U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2907177944512117206U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11100346409065275671U;
            aOrbiterD = RotL64((aOrbiterD * 17927994356809011637U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1344592529249949068U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6470438516791143572U;
            aOrbiterE = RotL64((aOrbiterE * 13339390828725370475U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5217751823741520847U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5371275223586938039U;
            aOrbiterG = RotL64((aOrbiterG * 12318403075523724125U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14218103150268532919U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1367628876596800571U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13777531272321533137U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2372041991018455610U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9870744274890595581U;
            aOrbiterC = RotL64((aOrbiterC * 12093443117747395585U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 15531376915156611594U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11166549148968363252U;
            aOrbiterF = RotL64((aOrbiterF * 10024372567841218915U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8555942275137258839U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3304132937209624841U;
            aOrbiterA = RotL64((aOrbiterA * 7965093976633155809U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14825330575158830172U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2330952702412094686U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9146641978165131495U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 42U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 43U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 37U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 36U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 18U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 3U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterH, 13U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 47U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterE, 60U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterF, 21U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterC, 39U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 44U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26488U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 24112U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26317U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 23766U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 21U)) ^ (RotL64(aIngress, 42U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererG + RotL64(aCross, 18U)) + 12222235191147985484U) + aNonceWordG;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 16367317014523328414U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 3511378091284703789U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 13U)) + 15247492830966725949U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aIngress, 27U)) + 7745995913390407897U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 6463593307540108810U) + aNonceWordJ;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 41U)) + 1101669311005268630U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 3U)) + 12988052764067518580U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 35U)) + 17717179747434679772U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 39U)) + 11662190906682400416U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 30U)) + 6563014073547628748U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13099094932059419219U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16342730862261868847U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10988124108686164829U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16855346813127524624U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6570063128502306944U;
            aOrbiterJ = RotL64((aOrbiterJ * 4571570049463124831U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11328352033809240501U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11640986648833160901U;
            aOrbiterF = RotL64((aOrbiterF * 2895830492089678919U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2675226158571501666U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17700531248266458165U;
            aOrbiterA = RotL64((aOrbiterA * 2231403813970188657U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7729597396731910874U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15172374484412053756U;
            aOrbiterH = RotL64((aOrbiterH * 149009041406406517U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9178769489257842683U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9020154972097834926U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 8910504667566521429U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1317403761217790562U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17151528554929201571U;
            aOrbiterE = RotL64((aOrbiterE * 3735945655450625203U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11621882033959669977U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10289504450815075623U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13365982786836243195U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16178772981106335703U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16896130772325866910U;
            aOrbiterC = RotL64((aOrbiterC * 6993524735412868965U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9573223644675562575U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17552463713786507189U;
            aOrbiterK = RotL64((aOrbiterK * 16103431656424881779U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4801852246698369631U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12222235191147985484U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 2835204872125428065U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 54U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 42U) + aOrbiterI) + RotL64(aOrbiterC, 54U)) + aPhaseFWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterI, 11U));
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 41U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 19U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterG, 46U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 23U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 40U) + aOrbiterD) + RotL64(aOrbiterK, 21U));
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 39U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32090U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 32644U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31801U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31755U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 50U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 826930775230515406U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 5137814617363250861U) + aNonceWordJ;
            aOrbiterJ = (aWandererA + RotL64(aCross, 46U)) + 14761561947426681616U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 12773023438753662590U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 27U)) + 7331345852207096322U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 41U)) + 3899381212671247460U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 23U)) + 10072004147620068599U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 35U)) + 3424585039401897560U) + aNonceWordO;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 37U)) + 8246760141625966321U) + aPhaseFOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 54U)) + 3655992860610853290U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 11U)) + 11154618022505863898U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15629361991059709973U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10842068502278489664U;
            aOrbiterJ = RotL64((aOrbiterJ * 17223002513104960799U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5571312349016336686U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 589313823745748879U;
            aOrbiterE = RotL64((aOrbiterE * 1356685926549786027U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13633457935771935260U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12684602052812183096U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4689206269919806711U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5711307583717354204U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7181854170553728211U;
            aOrbiterK = RotL64((aOrbiterK * 9835601115561325911U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1884620014396115821U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1471516373272364262U;
            aOrbiterD = RotL64((aOrbiterD * 5126319375714848029U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 742739371092077733U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 8075893317715227838U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11208274111743259795U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8179547722249281263U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15305282712174742323U;
            aOrbiterC = RotL64((aOrbiterC * 7951986906055462929U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1430543231751281079U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14585341768267283387U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 313213844964269133U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8123889986027932297U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2081696191347150910U;
            aOrbiterA = RotL64((aOrbiterA * 4869653441012615053U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10166788886199265936U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15927074835525735601U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 6747650218540675523U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6997764816848988590U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 826930775230515406U;
            aOrbiterF = RotL64((aOrbiterF * 9943232461538279601U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 56U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 14U) + aOrbiterK) + RotL64(aOrbiterG, 53U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 39U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterK, 43U));
            aWandererA = aWandererA + ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 60U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterH, 35U)) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 21U)) + aOrbiterK) + aNonceWordM);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterE, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordN;
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

void TwistExpander_Fencing_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3107U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 4031U)) & W_KEY1], 36U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 7221U)) & W_KEY1], 10U) ^ RotL64(mSource[((aIndex + 4897U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererG + RotL64(aScatter, 24U)) + 4476099022490972343U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 16836423700375760429U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 47U)) + 8850577488928703557U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 13U)) + 7091631824560042743U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 12560498899956759494U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 42U)) + 7797973377112012161U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 5U)) + 6173820673874805794U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 19U)) + 10805025132310245348U) + aPhaseCOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 7139216143268029968U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8241544862261635722U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4735527016563596150U;
            aOrbiterB = RotL64((aOrbiterB * 6621354217673598381U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5166171126690294033U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11117641762075368393U;
            aOrbiterD = RotL64((aOrbiterD * 4980156869201219393U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6312932356458415421U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1304139291184508668U;
            aOrbiterE = RotL64((aOrbiterE * 90744653170922319U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10085025354842771067U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16745854428789531080U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1945983905747274355U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2497187958708890337U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16069701876646548995U;
            aOrbiterI = RotL64((aOrbiterI * 16606039730973709495U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17242004368025978091U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 12334315722243232121U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16528598396696346719U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8007042082518126895U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5665686359038811484U;
            aOrbiterC = RotL64((aOrbiterC * 11289316305875751813U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3913477186958600592U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 16918984318564170343U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5128293326494417281U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10227611546502931418U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7187623463085447228U;
            aOrbiterK = RotL64((aOrbiterK * 8479839369622163181U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 48U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterK, 3U));
            aWandererE = aWandererE + ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 19U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterF, 27U)) + aOrbiterA) + aPhaseCWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 60U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterK, 23U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10118U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15342U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15063U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 10982U)) & W_KEY1], 22U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 8793908991006073956U;
            aOrbiterG = (aWandererH + RotL64(aCross, 28U)) + 2932916283348441943U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 57U)) + 11069042087940968262U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 43U)) + 14369628676782894441U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 5U)) + 8602903272780978282U;
            aOrbiterB = (aWandererK + RotL64(aCross, 51U)) + 3827036107178568820U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 47U)) + 8905245209036772489U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 13331387530760017893U) + aPhaseCOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aCross, 38U)) + RotL64(aCarry, 35U)) + 9880107580289737823U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10199619040626900278U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2466307560891374281U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6295342978834217571U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13973403407981259448U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2851460278409385243U;
            aOrbiterC = RotL64((aOrbiterC * 11226902976321781743U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10365453393815690776U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2382382358987358791U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 481563628980705781U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5058198848163792422U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10500434740387593487U;
            aOrbiterI = RotL64((aOrbiterI * 5946747708776079787U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11289798395177667084U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14327152153231286666U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18155778059595245561U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8065137263811956313U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3865153574847924816U;
            aOrbiterH = RotL64((aOrbiterH * 9495741102667755161U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 18102279969722473375U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6306428427188742325U;
            aOrbiterA = RotL64((aOrbiterA * 17826782872351406167U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16953348204663693724U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11950791817032898613U;
            aOrbiterB = RotL64((aOrbiterB * 1498946055469611133U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11980823193543752994U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17845490308799454871U;
            aOrbiterG = RotL64((aOrbiterG * 16385153013485463791U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 50U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 46U) + aOrbiterB) + RotL64(aOrbiterJ, 19U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 37U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 12U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 23U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 27U)) + aPhaseCWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterF, 56U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 26U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 10U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19487U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 22952U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 17245U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 20104U)) & W_KEY1], 4U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 24U)) + 4980738603982643969U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 39U)) + 17660278413018470020U) + aPhaseCOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aIngress, 3U)) + 17598114429859543466U;
            aOrbiterF = (aWandererD + RotL64(aCross, 19U)) + 10993929335279994739U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 48U)) + 17967203122976322481U) + aPhaseCOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 1872290205549034384U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 11U)) + 16607778671782810797U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 4895226930754394376U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 14960359005982301383U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9921642352377700630U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 893281964367208693U;
            aOrbiterH = RotL64((aOrbiterH * 2345509157333444217U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8232519988397858732U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4433022122758913407U;
            aOrbiterJ = RotL64((aOrbiterJ * 834240393225479419U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12689609831247168353U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 404535388957472176U;
            aOrbiterF = RotL64((aOrbiterF * 14534020545479806593U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3349108201964013155U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4386449511297371730U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9596273264321140229U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14314587717949070586U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10923886625271054985U;
            aOrbiterB = RotL64((aOrbiterB * 7838969002623486809U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17634909585329833520U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2021301459918350372U;
            aOrbiterE = RotL64((aOrbiterE * 1388242915918642741U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5219599112498224367U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 10641339455385046206U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1022283727595400719U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5003342156562330058U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10951027475628404336U;
            aOrbiterC = RotL64((aOrbiterC * 17836928292555158461U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13040991872592235460U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11149099984302782267U;
            aOrbiterI = RotL64((aOrbiterI * 4248667283139686251U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 56U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 12U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterE, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 53U));
            aWandererC = aWandererC + ((RotL64(aIngress, 10U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterH, 27U));
            aWandererH = aWandererH + ((((RotL64(aCross, 41U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 34U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27335U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 29398U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27802U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25859U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 12U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererD + RotL64(aPrevious, 21U)) + 12380376990224645149U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 12U)) + 18296928500297384014U) + aPhaseCOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 27U)) + 3550626816361145100U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 2667792936946706027U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 12020969779370926953U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 39U)) + 737340727886903447U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 47U)) + 1681797651799760502U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 60U)) + 2956186342689489064U) + aPhaseCOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 1876852870402977177U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6433205819353555071U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9065076854974222998U;
            aOrbiterE = RotL64((aOrbiterE * 5459675878087242021U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 3254410578766789992U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2005081975473815576U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9947701153722014085U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15992999234834560419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3458344156815120948U;
            aOrbiterG = RotL64((aOrbiterG * 1668460113964608051U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17069783053664877727U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1260234710193913099U;
            aOrbiterB = RotL64((aOrbiterB * 4561226779897414381U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3825186451876061335U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2905344294992827535U;
            aOrbiterC = RotL64((aOrbiterC * 2469896090698580795U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18141402347899180617U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8760129857609925066U;
            aOrbiterD = RotL64((aOrbiterD * 2507999156108123047U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 594052473780678210U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 13216719212966128379U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10691355329696722303U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10029948739466316169U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11912428807431992996U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 85016510811938307U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8735634019801417287U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12785916159063273545U;
            aOrbiterI = RotL64((aOrbiterI * 1161917531260663357U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterI, 57U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterE, 12U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + aPhaseCWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterD, 47U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 53U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterB, 43U)) + aPhaseCWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterH, 18U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 21U);
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

void TwistExpander_Fencing_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4036U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3638U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4100U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7686U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 58U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 2617613537256538553U) + aPhaseDOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 16642868916835132715U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 10860291124337073254U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 22U)) + 6432511273906902472U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 35U)) + 7505375005848241910U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11086616004678821329U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3298830587569881951U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4304047944073454489U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9775143140064220979U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4147601326580823120U;
            aOrbiterG = RotL64((aOrbiterG * 13462244678782260871U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12245920269898100415U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8391940489176734499U;
            aOrbiterC = RotL64((aOrbiterC * 9119606167674098007U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17876893379544668477U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 18301882058180370541U;
            aOrbiterF = RotL64((aOrbiterF * 16680384667098921309U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6869225862715140102U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15404118372589259800U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5766851935950389915U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 39U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterD, 27U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 19U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 4U)) + aOrbiterG) + aPhaseDWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8575U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9628U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13582U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16122U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 27U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 44U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 12122689833405846292U) + aPhaseDOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 19U)) + 9640400270962766788U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 9141937998266739071U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 42U)) + RotL64(aCarry, 37U)) + 12899395770434090537U) + aPhaseDOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aScatter, 11U)) + 13457918115408031842U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15134784483576000943U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12540961268790055438U;
            aOrbiterD = RotL64((aOrbiterD * 3295706140418040089U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6306886773092764230U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13573343491337243121U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15893457012357368707U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8545588657348974413U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10891410570357275120U;
            aOrbiterA = RotL64((aOrbiterA * 5399310978367842841U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2877137119767060151U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9178097682386595144U;
            aOrbiterJ = RotL64((aOrbiterJ * 3524486002084427513U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 15528007881855616978U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11368419529245281435U;
            aOrbiterC = RotL64((aOrbiterC * 12433207037378339309U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 56U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterA, 60U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 46U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterD, 43U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 48U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23722U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23670U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22798U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 23806U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 29U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 42U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 11274974230580265396U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 3U)) + 16658438747342741547U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 16612986966106053844U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 42U)) + RotL64(aCarry, 11U)) + 9329502236843231290U) + aPhaseDOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aIngress, 57U)) + 14088261356708344656U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13692608802007789581U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6824473946645682398U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13619437545775237601U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2072915876348570040U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7420507753044460759U;
            aOrbiterC = RotL64((aOrbiterC * 13239288539564571257U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4677557318688502593U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15081678577055628459U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16659305295251177155U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7026792817486507482U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14871665922943969918U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 694073180313083145U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6807734532159292872U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17882797335141303280U;
            aOrbiterI = RotL64((aOrbiterI * 15439872930381050291U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 5U) + RotL64(aOrbiterK, 21U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 46U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterF, 29U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28663U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25527U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27949U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25272U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererI + RotL64(aPrevious, 11U)) + 6069475454765660321U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 56U)) + RotL64(aCarry, 13U)) + 11483704742497268068U) + aPhaseDOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aCross, 21U)) + 11055697447388986418U) + aPhaseDOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 10897095046039997004U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 4731637118230457840U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13855839187084986751U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5328208115460188239U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3800417611141123383U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12479538544291412985U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10740165998792608231U;
            aOrbiterF = RotL64((aOrbiterF * 14046827922294477379U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 6492798157284955373U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13056825957483891921U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14882112110627751751U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2068184064919194657U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5656302738780746294U;
            aOrbiterB = RotL64((aOrbiterB * 16493021179127646345U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11193756120230763294U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17306750816837208999U;
            aOrbiterC = RotL64((aOrbiterC * 7949360041241439741U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 46U) + aOrbiterC) + RotL64(aOrbiterF, 10U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 53U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 29U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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

void TwistExpander_Fencing_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2752U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 7756U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4649U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((aIndex + 7725U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 43U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 22U)) + RotL64(aCarry, 35U)) + 13880995121909552664U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 14534942818069300546U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 29U)) + 17745973100886007133U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 51U)) + 2249805580771946872U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 4460116116396439410U;
            aOrbiterD = (aWandererD + RotL64(aCross, 57U)) + 3378683994078106878U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 41U)) + 3992996501048809123U) + aPhaseEOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12057768808864451929U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 4115362079047921130U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12263015903331031345U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15297384955502206698U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17623548383481905636U;
            aOrbiterC = RotL64((aOrbiterC * 7487278217901483685U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3559213898000162417U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12311605719074507335U;
            aOrbiterD = RotL64((aOrbiterD * 3982199462062847697U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14807313864347885885U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11222085523291581822U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12580941911587215653U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 916681229436292462U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2441350114032314686U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7336079498999018067U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 7361470539894653271U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12153585147213579808U;
            aOrbiterB = RotL64((aOrbiterB * 3040327545467672961U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13566300726101613579U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14875254144748509128U;
            aOrbiterI = RotL64((aOrbiterI * 13699179902908972403U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 60U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterC, 13U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterD, 23U)) + aPhaseEWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 12U) + aOrbiterD) + RotL64(aOrbiterB, 47U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterB, 57U));
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterI, 40U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterG, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12338U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10161U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10057U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((aIndex + 9488U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 43U)) + (RotL64(aCross, 27U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aIngress, 29U)) + 5480870806135400132U;
            aOrbiterH = (aWandererG + RotL64(aCross, 19U)) + 8034874599430768743U;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 58U)) + RotL64(aCarry, 19U)) + 4006919843736863767U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 2988069748674633718U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 11U)) + 12347295651973135786U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 14152683894431568192U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 3U)) + 15765143815254196598U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10473067082331244233U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1089466925383677249U;
            aOrbiterK = RotL64((aOrbiterK * 17334888609179149753U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13215039929873682230U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3957997712247961479U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7631186240013784703U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10023907397941685546U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14593012591254614353U;
            aOrbiterG = RotL64((aOrbiterG * 17111300092082154687U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13353797968154036726U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9259966668512102858U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8326732574268308221U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10757861831070349321U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10530223113483866178U;
            aOrbiterJ = RotL64((aOrbiterJ * 11269177745265396583U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7554320926405521865U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 6978052067277966996U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18020134738536217801U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1053695861967171420U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15980734683539854451U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3208466640010555357U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 56U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 57U)) + aOrbiterK) + aPhaseEWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 47U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aCross, 5U) + RotL64(aOrbiterA, 41U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 30U));
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterK, 13U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterG, 3U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererD, 34U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23499U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 18855U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16420U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 23561U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 6U) + RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererI + RotL64(aCross, 4U)) + RotL64(aCarry, 27U)) + 11039986441331892533U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 57U)) + 6256024955965426119U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 9857443189988995666U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 11900944813380998208U) + aPhaseEOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 29U)) + 8422577734978875541U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 39U)) + 3100835100713928724U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 47U)) + 11871553509810206993U) + aPhaseEOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17614749493763417027U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3638372131856199916U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 480683274898147025U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6582275259281025770U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17016882418498941958U;
            aOrbiterJ = RotL64((aOrbiterJ * 4269869255230867823U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1747214688658984715U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9356088987044015278U;
            aOrbiterG = RotL64((aOrbiterG * 16221733545319753695U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4056238112133473456U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16013150119949532998U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12913648646318115315U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16076621211111834889U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9940824359571581765U;
            aOrbiterD = RotL64((aOrbiterD * 11624767861336495331U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15624084004784515753U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7630989544834680335U;
            aOrbiterK = RotL64((aOrbiterK * 12261063237156822067U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 18003586430673313786U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 1654118743290334161U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1153250137357176071U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 11U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 51U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 54U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterA, 29U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 3U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 40U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26948U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29782U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32042U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29182U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 10812151398716051703U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 51U)) + 18202551453336003710U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 9434410809101973752U;
            aOrbiterD = (aWandererD + RotL64(aCross, 42U)) + 12955829998028534045U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 29U)) + 12271740641929640181U) + aPhaseEOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 11U)) + 14009351527014534752U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 4316296955679133450U) + aPhaseEOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16473324966997442872U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15735123324965019802U;
            aOrbiterF = RotL64((aOrbiterF * 5624078184997601019U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17656375090484080236U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16066325053456055298U;
            aOrbiterE = RotL64((aOrbiterE * 17912970706985130327U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12908968778503516903U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12761433987676836197U;
            aOrbiterI = RotL64((aOrbiterI * 1023329467480907925U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12737513138040664509U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14535795767570998392U;
            aOrbiterB = RotL64((aOrbiterB * 15560519667062222269U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14370908061811284364U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7001358781208669795U;
            aOrbiterH = RotL64((aOrbiterH * 11641248025734015835U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7298578161120090849U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10498302152357484629U;
            aOrbiterD = RotL64((aOrbiterD * 13144110412179037175U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 11447343228638006767U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 18284143620422655675U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 572862190073605651U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 22U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 51U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterB, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterE, 43U));
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterD, 4U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterE, 11U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Fencing_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6692U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[aIndex], 46U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8168U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3329U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 35U)) + 5906639480605353429U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 5293518570213287605U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 44U)) + RotL64(aCarry, 41U)) + 15383185501428521377U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 15364072512743978902U) + aPhaseFOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 53U)) + 4525473357144014271U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10400911938125603074U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16417506293824627550U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8303380456072515611U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2419329331753341815U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 14929222427923332069U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11596261802662514979U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16771573504983922586U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1863466450051787622U;
            aOrbiterB = RotL64((aOrbiterB * 2585626547126027053U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12895350137096692415U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3700979086526298327U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10279730254867618193U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1977099106211282426U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6144698304096915742U;
            aOrbiterA = RotL64((aOrbiterA * 5039822990560519609U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 14U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterI, 27U)) + aPhaseFWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 12U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 56U) + aOrbiterD) + RotL64(aOrbiterA, 3U));
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 53U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 41U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 56U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10928U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13605U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11909U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10436U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 24U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 19U)) + 5697928251815176134U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aCross, 36U)) + RotL64(aCarry, 43U)) + 337587740689259575U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 4927686903263973950U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 3742409032569801033U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 27U)) + 1608092659172197650U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 15848744267145717509U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15300174177963339253U;
            aOrbiterH = RotL64((aOrbiterH * 5771922862677667319U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14162868453323648628U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12020167069983729869U;
            aOrbiterE = RotL64((aOrbiterE * 2071080217680099017U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16259538291658723956U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8516686212464112245U;
            aOrbiterB = RotL64((aOrbiterB * 4731296903548893627U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3722184575520553132U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 5663609293306386784U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14364218128780764749U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15265344442454471986U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3050323350098829515U;
            aOrbiterG = RotL64((aOrbiterG * 5890624677162388135U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 50U) + aOrbiterE) + RotL64(aOrbiterB, 53U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 10U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 41U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterG, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19924U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22494U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22453U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 24147U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 24U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 8988572360732005217U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 47U)) + 17889613225105985335U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 58U)) + RotL64(aCarry, 43U)) + 15563478320513948626U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 3441351228410524816U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 37U)) + 4425592689451435346U) + aPhaseFOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12733160231627305928U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3574152157304607854U;
            aOrbiterI = RotL64((aOrbiterI * 3488682351509384035U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15167631896729808783U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 15822667973915417055U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5155661648455308057U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 17181685481076577637U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 9979204751408873468U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8244434774754786565U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1334240485667164762U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9190066751460137016U;
            aOrbiterE = RotL64((aOrbiterE * 14585141844653660363U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15465215829109246336U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2305208282453624419U;
            aOrbiterF = RotL64((aOrbiterF * 10257861974108363283U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 3U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 27U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 44U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28255U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26766U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30307U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31856U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 18U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererG + RotL64(aCross, 11U)) + 3105313968748067810U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 23U)) + 9977249451119627064U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 17941392803495349366U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 4279533326705471133U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 34U)) + RotL64(aCarry, 11U)) + 13983828966811580039U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3983490984234810378U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 308786542215259956U;
            aOrbiterF = RotL64((aOrbiterF * 4366245356597769425U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8443607695364427037U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14939626441464340668U;
            aOrbiterJ = RotL64((aOrbiterJ * 16793255020331774983U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9350693577306121110U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1717071159396961752U;
            aOrbiterH = RotL64((aOrbiterH * 11062480662625054525U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15911765265202100610U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14898546272333182767U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2674900543810733067U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3560903518513465868U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5367062725726860234U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8521908836601319553U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 43U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 4U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + aPhaseFWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Fencing_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;

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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7525U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1175U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6807U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((aIndex + 7995U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCarry, 37U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererH + RotL64(aCross, 53U)) + 4384716820085860551U) + aPhaseGOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 9715780315942116888U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 6U)) + RotL64(aCarry, 39U)) + 15963520052789178632U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 29U)) + 14346700690686392938U) + aPhaseGOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 6005518012489966643U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2506732930310252119U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16782163084851775826U;
            aOrbiterC = RotL64((aOrbiterC * 1527050617428162663U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 823673076571076303U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1634084509064077736U;
            aOrbiterD = RotL64((aOrbiterD * 1128407326773234517U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1288134975466877686U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2998220403162908444U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4321412662318298283U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 220430672180734911U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10223923547068528867U;
            aOrbiterF = RotL64((aOrbiterF * 12577370238343872139U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11696469696177647608U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6545430420379636963U;
            aOrbiterB = RotL64((aOrbiterB * 8387163146257553773U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + aPhaseGWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterE, 27U));
            aWandererI = aWandererI + (((RotL64(aCross, 30U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterC, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 48U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16150U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneC[((aIndex + 16270U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11987U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 9146U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 20U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererE + RotL64(aIngress, 40U)) + RotL64(aCarry, 5U)) + 12809562813316740345U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 17084212535326321199U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 16074921689983846769U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 51U)) + 14027986153007120145U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 11U)) + 7633455951809250227U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 340989348513370174U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5307820377645020116U;
            aOrbiterI = RotL64((aOrbiterI * 8402492604131262157U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5605285015771527274U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5293500434746182790U;
            aOrbiterF = RotL64((aOrbiterF * 17674669610895537063U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7263156475892261811U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 10672879570907433005U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2506338667179450741U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16659226780900986107U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 9774892622769850665U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7487477727543183211U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10728057184108279042U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5032485856947407217U;
            aOrbiterD = RotL64((aOrbiterD * 16651577903809154285U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 18U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterD, 21U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterD, 52U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 43U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 52U) + aOrbiterH) + RotL64(aOrbiterI, 3U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 20503U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 21494U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23277U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 20020U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 13U)) + (RotL64(aCarry, 60U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 18U)) + 8506388683755208267U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 29U)) + 2179323259055019735U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 3345902531140983016U;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 17456139311481306584U) + aPhaseGOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 14587864088462311164U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13178947246650647057U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12866578138946916962U;
            aOrbiterG = RotL64((aOrbiterG * 121991325166969319U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13098524333655118173U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15451329483787541982U;
            aOrbiterD = RotL64((aOrbiterD * 13580376920467431451U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9494299579678389385U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 15581954810375490643U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13670002280188424825U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4487042505730624892U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2774455928791636186U;
            aOrbiterC = RotL64((aOrbiterC * 15847933919136777451U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 12435319582397755819U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10077180055177766823U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3924363471701748703U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 6U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterG, 43U)) + aPhaseGWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterD, 53U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterH, 18U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 32440U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30580U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31965U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((aIndex + 32614U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 9107326720193244489U) + aPhaseGOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 10868585484401664145U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 11U)) + 13637736741437846622U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 19U)) + 6130725216183918844U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 52U)) + RotL64(aCarry, 53U)) + 2063834478521338187U) + aPhaseGOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8564870627911949158U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6524015751064086390U;
            aOrbiterE = RotL64((aOrbiterE * 12055267995727104463U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9874937766875388236U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14723718409522680894U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17379140128833323431U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 13767059954741528279U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6387608251033722169U;
            aOrbiterH = RotL64((aOrbiterH * 6601902195707980693U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5391425980008431000U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11524218415655093779U;
            aOrbiterG = RotL64((aOrbiterG * 12508457981779189389U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 155510463350385905U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10554591788433641311U;
            aOrbiterB = RotL64((aOrbiterB * 5412084824127934293U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 40U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterI, 12U));
            aWandererE = aWandererE + ((((RotL64(aCross, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterE, 43U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 21U)) + aOrbiterB) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Fencing_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 1633U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 292U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7503U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4280U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 39U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererK + RotL64(aScatter, 14U)) + RotL64(aCarry, 39U)) + 4752759164691497960U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 12088872623537639782U) + aPhaseHOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aPrevious, 57U)) + 3734943577379734227U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 8854778183012444234U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 37U)) + 16948373492893967275U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7962415690046184385U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1872682375669714454U;
            aOrbiterE = RotL64((aOrbiterE * 959061892772099785U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7776801806943853566U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16665439117257230732U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6866375628213114965U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11088186766134265676U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10850237991780969350U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7547414856143095121U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6464817712131305812U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 244557182884209844U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2394270354887582889U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13261563971157415841U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2323811103717827362U;
            aOrbiterA = RotL64((aOrbiterA * 11483723582415081925U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 18U) + aOrbiterI) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 23U)) + aOrbiterA) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + aPhaseHWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 58U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 8914U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 15313U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12648U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11181U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 19U)) + 9107326720193244489U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 27U)) + 10868585484401664145U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 13637736741437846622U) + aPhaseHOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 56U)) + RotL64(aCarry, 37U)) + 6130725216183918844U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 2063834478521338187U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 8564870627911949158U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6524015751064086390U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12055267995727104463U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9874937766875388236U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14723718409522680894U;
            aOrbiterJ = RotL64((aOrbiterJ * 17379140128833323431U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13767059954741528279U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6387608251033722169U;
            aOrbiterE = RotL64((aOrbiterE * 6601902195707980693U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5391425980008431000U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11524218415655093779U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12508457981779189389U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 155510463350385905U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10554591788433641311U;
            aOrbiterI = RotL64((aOrbiterI * 5412084824127934293U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 5U));
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + aPhaseHWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 47U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 28U) + aOrbiterG) + RotL64(aOrbiterI, 56U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 23805U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23561U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24541U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20360U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 40U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererB + RotL64(aScatter, 5U)) + 2558105147674438050U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 15856662514774702561U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 47U)) + 13346869226246584582U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 7632111846116243973U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 38U)) + RotL64(aCarry, 39U)) + 2102101361626976279U) + aPhaseHOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5605968705067851563U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6842483186584326681U;
            aOrbiterE = RotL64((aOrbiterE * 11344798544990575365U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5559797213819425064U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12422313931331576759U;
            aOrbiterD = RotL64((aOrbiterD * 7399849122565913401U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2751024420047872601U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11031320239359798610U;
            aOrbiterG = RotL64((aOrbiterG * 8607639453141148025U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14366375309473793217U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11971479429768505316U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10063001532313098203U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3947595951884469542U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17882767922372770896U;
            aOrbiterC = RotL64((aOrbiterC * 3361906348965810211U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 24U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 19U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 56U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterC, 27U));
            aWandererG = aWandererG + ((((RotL64(aCross, 57U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterD, 43U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 31399U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32665U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31440U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28260U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 13U)) ^ (RotL64(aPrevious, 26U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 8866844335448071821U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 10U)) + RotL64(aCarry, 29U)) + 15159698739856430085U) + aPhaseHOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 9582805772989594633U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 37U)) + 1438538239931588373U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 57U)) + 10862044156620436139U) + aPhaseHOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13682173320058164615U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8351013291045977592U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5722336275651615473U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15777857431516633916U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16178966745333885377U;
            aOrbiterC = RotL64((aOrbiterC * 7545129923202147703U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 9031889187993001617U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6308472367425865347U;
            aOrbiterH = RotL64((aOrbiterH * 17118710301967158153U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 642109145903321046U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 9186268569255318035U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10714674348507516749U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6091345356803675860U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13218507921880873749U;
            aOrbiterJ = RotL64((aOrbiterJ * 15415157927185637717U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 56U)) + aOrbiterH) + aPhaseHWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 19U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aCross, 19U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 34U) + aOrbiterG) + RotL64(aOrbiterC, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
