#include "TwistExpander_Rugby_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Rugby_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF78BCFECE29E6827ULL + 0x82F3CEC659434E91ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC9AFFF6AD6D99C91ULL + 0xFAFC05CD1515F17BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC42F00D2326BDD11ULL + 0xB88E83A9B99F02B1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFF5E97652730C70BULL + 0xBB8E3667099F4DFAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x81479EA02693B1BBULL + 0x862504B19FE236F9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCE63895DD37E7E13ULL + 0xFD634D34BCFFE879ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCD5D0F254F4E2D39ULL + 0xEC1E01E532346931ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x99514D57E3DDE463ULL + 0xD4E6AD00874F9DBCULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordG, 48U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 85U)) & S_BLOCK1], 19U) ^ RotL64(mSnow[((aIndex + 817U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 58U) ^ RotL64(aNonceWordC, 47U)) ^ RotL64(aNonceWordH, 37U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 908U)) & S_BLOCK1], 5U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 3964U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 9041099828460168106U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 39U)) + 12883711604096848454U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 27U)) + 17420968786226443079U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 50U)) + RotL64(aCarry, 37U)) + 3448213891716125104U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 13U)) + 11866455977445336560U) + RotL64(aNonceWordG, 51U);
            aOrbiterC = (aWandererD + RotL64(aScatter, 41U)) + 4119356835384495905U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 53U)) + 2186212599698637068U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 3U)) + 6506144898969301620U) + RotL64(aNonceWordE, 15U);
            aOrbiterH = (aWandererJ + RotL64(aCross, 23U)) + 12556800923644051626U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 56U)) + 4075551535185182945U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 17877694808492008749U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5553428900598223316U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14362304852277160675U;
            aOrbiterG = RotL64((aOrbiterG * 11415103199856419303U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 9174200302876075831U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16110739511917638547U;
            aOrbiterC = RotL64((aOrbiterC * 7004356839428657949U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10189881974519849402U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2128076632642616677U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8860453653433114929U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 18133523799074400083U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 9916472958834153766U) ^ RotL64(aNonceWordB, 40U);
            aOrbiterA = RotL64((aOrbiterA * 3454601168808001733U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10274457562795569227U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14134814273275356425U;
            aOrbiterI = RotL64((aOrbiterI * 15912501063665343159U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6394306369514735480U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4825761192736485643U;
            aOrbiterH = RotL64((aOrbiterH * 12534544147331805643U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5672807934779206275U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3881953574159390421U;
            aOrbiterE = RotL64((aOrbiterE * 7448770570912161095U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12012232712634303203U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14176392925893052596U;
            aOrbiterJ = RotL64((aOrbiterJ * 11288668529893084583U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 307148402076391033U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15380446373458263079U;
            aOrbiterF = RotL64((aOrbiterF * 15228462337097647933U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4654312690816676129U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10818029316701301859U;
            aOrbiterB = RotL64((aOrbiterB * 16245734506125913215U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 7340370713289840635U) + RotL64(aNonceWordF, 13U);
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9041099828460168106U;
            aOrbiterD = RotL64((aOrbiterD * 1807356802142268373U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 60U);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 56U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 44U) + aOrbiterH) + RotL64(aOrbiterD, 44U));
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 5U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 37U)) + aOrbiterC) + RotL64(aNonceWordC, 9U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 57U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 19U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 20U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordA, 61U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 50U)) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 53U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 47U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 24U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordF, 21U)) ^ RotL64(aNonceWordE, 43U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 10806U)) & S_BLOCK1], 11U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 5698U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordC, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5711U)) & S_BLOCK1], 10U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10477U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 10U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererI + RotL64(aIngress, 48U)) + 9855743441035905047U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 19U)) + 8426286937143990276U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 13U)) + 7146752367170267002U;
            aOrbiterB = (aWandererH + RotL64(aCross, 21U)) + 12947210066678101726U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 15902163559925328965U) + RotL64(aNonceWordH, 13U);
            aOrbiterF = (((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 21U)) + 8506649889346449469U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 13U)) + 8226286036430263052U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 53U)) + 2703047093452420216U) + RotL64(aNonceWordG, 34U);
            aOrbiterK = (aWandererJ + RotL64(aScatter, 51U)) + 6769351326360139560U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 35U)) + 9857025533281333281U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 27U)) + 238297452132277585U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7203572312072908931U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12497027346166575632U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1703586436725662307U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 473851890609048879U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1664484956453886047U;
            aOrbiterH = RotL64((aOrbiterH * 8566500756326590209U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4635095143004754116U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17695676150967345793U;
            aOrbiterJ = RotL64((aOrbiterJ * 5780416541584439301U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 15628965269863402796U) + RotL64(aNonceWordA, 31U);
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9190117464399730235U;
            aOrbiterD = RotL64((aOrbiterD * 5586437438425999715U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17835918238346011086U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4398005402429282682U;
            aOrbiterK = RotL64((aOrbiterK * 14828737209913317463U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 10902589938246551273U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15124274429081385923U;
            aOrbiterC = RotL64((aOrbiterC * 13524180348258805367U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8747233520702236018U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 5445611443463112371U) ^ RotL64(aNonceWordE, 3U);
            aOrbiterB = RotL64((aOrbiterB * 10294109295823410447U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 16296005217836151910U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6468336224317602364U;
            aOrbiterF = RotL64((aOrbiterF * 7369779919748367133U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3827976387089403774U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7773383658122100111U;
            aOrbiterG = RotL64((aOrbiterG * 9784711300597525161U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 18273794621528918389U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8401424792700263455U;
            aOrbiterE = RotL64((aOrbiterE * 13003420427441089595U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11402828934846813949U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9855743441035905047U;
            aOrbiterI = RotL64((aOrbiterI * 7339549576423555273U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterF, 23U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 57U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 44U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aIngress, 20U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + RotL64(aNonceWordB, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterD, 35U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterE, 11U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterJ, 13U));
            aWandererG = aWandererG + ((RotL64(aCross, 22U) + aOrbiterC) + RotL64(aOrbiterA, 19U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterH, 28U)) + RotL64(aNonceWordD, 17U)) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordH, 35U)) ^ RotL64(aNonceWordA, 3U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 16041U)) & S_BLOCK1], 54U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 15147U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordD, 53U)) ^ RotL64(aNonceWordE, 4U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15359U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15669U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 20U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 58U)) + RotL64(aCarry, 53U)) + 11177787645248006236U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 23U)) + 3808340254579817169U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aIngress, 47U)) + 828030667598518279U) + RotL64(aNonceWordF, 5U);
            aOrbiterD = (aWandererI + RotL64(aScatter, 5U)) + 16177835921238398371U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 19U)) + 5518747735458708741U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 39U)) + 17346319082399995165U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 52U)) + 6397156921893030937U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 15559381654710713582U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 940404446491415088U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 43U)) + 8047166032048732645U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 21U)) + 4688468645859470491U) + RotL64(aNonceWordA, 52U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3710878044770337260U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 116343189456629220U) ^ RotL64(aNonceWordC, 7U);
            aOrbiterG = RotL64((aOrbiterG * 5637725064169289339U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 883908030159391659U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 18058691521694880482U;
            aOrbiterI = RotL64((aOrbiterI * 3132200449123497619U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17521015077103586117U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 3668332225435714918U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12658899101297839881U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12229480388278883300U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16206524049491531816U;
            aOrbiterJ = RotL64((aOrbiterJ * 11122340196620859805U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5743265849441077466U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2812293020719282236U;
            aOrbiterE = RotL64((aOrbiterE * 8903956475200417109U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 13718364781538837074U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 861529717259766236U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17019744777211266685U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4862687502126693872U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7722024283321020761U;
            aOrbiterC = RotL64((aOrbiterC * 18086944039541060829U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8205803118233399853U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 15130160926615050422U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1454552751453996765U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 667469191899263617U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18048970185163843471U;
            aOrbiterH = RotL64((aOrbiterH * 1800698970568737425U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 508102841337488721U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3803840516662727630U;
            aOrbiterF = RotL64((aOrbiterF * 8477778555284121637U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 17055028117762299436U) + RotL64(aNonceWordB, 55U);
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11177787645248006236U;
            aOrbiterA = RotL64((aOrbiterA * 12457019014051206805U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterG, 41U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterH, 35U)) + RotL64(aNonceWordE, 15U));
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 21U)) + RotL64(aNonceWordG, 25U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterI, 57U));
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 60U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 37U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterF, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 54U) + aOrbiterK) + RotL64(aOrbiterD, 30U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 22U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 21U) ^ RotL64(aNonceWordH, 58U)) ^ RotL64(aNonceWordB, 39U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 19686U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 21585U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordG, 11U)) ^ RotL64(aNonceWordF, 54U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19030U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 20058U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aPrevious, 35U)) + 380024772508948442U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 57U)) + 7649029098162567210U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 12U)) + 5329304598870421851U) + RotL64(aNonceWordG, 34U);
            aOrbiterF = (aWandererI + RotL64(aIngress, 27U)) + 12306118665045151326U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 53U)) + 960751560457324256U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 3244070254386191876U) + RotL64(aNonceWordA, 59U);
            aOrbiterH = ((aWandererC + RotL64(aCross, 47U)) + 15733408571609521746U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 17623448932647018544U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aCross, 22U)) + 8787759896149035829U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 43U)) + 14741681792348288162U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 8801731213568307302U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9872248187499779222U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15407371518644528235U;
            aOrbiterA = RotL64((aOrbiterA * 1245102406469471673U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4242060317152943062U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9942784962409917541U) ^ RotL64(aNonceWordF, 43U);
            aOrbiterD = RotL64((aOrbiterD * 888649755587764533U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7296348796484458631U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 15061417216070157797U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) ^ RotL64(aNonceWordH, 27U);
            aOrbiterC = RotL64((aOrbiterC * 10349554676953256231U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3233185810644297433U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9241229457641024287U;
            aOrbiterH = RotL64((aOrbiterH * 2728237515724597517U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8464051359381554575U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3307872165699029375U;
            aOrbiterB = RotL64((aOrbiterB * 4859663401033023433U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5482617843966711997U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4442149210462943872U;
            aOrbiterG = RotL64((aOrbiterG * 8979352218576515647U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10591636597580147381U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14925122230279312217U;
            aOrbiterI = RotL64((aOrbiterI * 15038171961638724013U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9772367878232735350U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15800661165607190092U;
            aOrbiterE = RotL64((aOrbiterE * 10493976952980533589U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1571665862499272194U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3162847040693387901U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2747235335326991399U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4868791925868749848U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13134549226315884613U;
            aOrbiterJ = RotL64((aOrbiterJ * 3551955270718495869U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7830447320021657240U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 380024772508948442U;
            aOrbiterF = RotL64((aOrbiterF * 5143324968958616357U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 40U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 51U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 6U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 27U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterE, 37U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterD) + RotL64(aNonceWordD, 57U));
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterG, 21U));
            aWandererG = aWandererG + ((RotL64(aCross, 26U) + RotL64(aOrbiterK, 19U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterB, 39U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterK, 44U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordC, 53U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 6U) ^ RotL64(aNonceWordD, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 25590U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 25985U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23014U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 26975U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 20U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 43U)) + 701291026547470433U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 37U)) + 17283292650462111643U) + RotL64(aNonceWordA, 46U);
            aOrbiterK = (aWandererH + RotL64(aCross, 28U)) + 9969124091931303406U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 5U)) + 889176772718046988U) + RotL64(aNonceWordD, 29U);
            aOrbiterA = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 6054541844643748084U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 53U)) + 14703226235143028132U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 39U)) + 7977975878522921062U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 30U)) + 16894322614172266274U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 12160451749345900570U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 10870847008043897470U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 57U)) + 8159920947172520247U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2440099120969517932U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2428396147731468007U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9363073341539598441U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2213226274394673479U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7079731443427765333U;
            aOrbiterC = RotL64((aOrbiterC * 16918930776877030559U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 958896789550478970U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10788682955708075458U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 913321215613559729U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2003386579317564870U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8419686358774204999U;
            aOrbiterI = RotL64((aOrbiterI * 6547052526438697621U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6989167615157578904U) + RotL64(aNonceWordC, 7U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17636634003643824148U;
            aOrbiterJ = RotL64((aOrbiterJ * 11038576417283732937U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13824962118933907859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9543912892587859646U;
            aOrbiterG = RotL64((aOrbiterG * 14736710162285997415U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15729878041027706114U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9542137475454825463U;
            aOrbiterF = RotL64((aOrbiterF * 11420547128115090491U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5327302277575009955U) + RotL64(aNonceWordH, 49U);
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2707383132257428583U;
            aOrbiterB = RotL64((aOrbiterB * 6120763309390182129U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9008601903853562620U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11050463189491777908U;
            aOrbiterH = RotL64((aOrbiterH * 9178386878636430553U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14683684132116778056U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5390271065690907120U;
            aOrbiterD = RotL64((aOrbiterD * 17903005409098232619U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5183407290520277451U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 701291026547470433U;
            aOrbiterA = RotL64((aOrbiterA * 16329261100139524239U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 50U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 26U) + aOrbiterJ) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterF, 37U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterA) + RotL64(aNonceWordE, 9U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 26U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aCross, 46U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + RotL64(aNonceWordG, 13U));
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterK, 43U));
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 29U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 21U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterK, 39U)) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 22U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordF, 48U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 28890U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 27588U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28567U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31686U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aIngress, 41U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aCross, 43U)) + 8604208734152026945U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 53U)) + 1374329953253889829U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 34U)) + RotL64(aCarry, 3U)) + 5779278910548228339U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 19U)) + 17670451230882805140U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 37U)) + 8193848740764866860U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 23U)) + 15801168428145650104U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 57U)) + 2584718176087499066U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 47U)) + 14950366247822737997U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 9779293225265670135U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 14U)) + 8688968319288372383U) + RotL64(aNonceWordH, 55U);
            aOrbiterC = (((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 13665723186950342601U) + RotL64(aNonceWordC, 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9395428688359973510U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2152719218018108418U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15271961483518392671U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1350324137411377992U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8729317951386057921U;
            aOrbiterG = RotL64((aOrbiterG * 6008790836417785083U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6317310451893678411U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10175620379041384281U;
            aOrbiterH = RotL64((aOrbiterH * 14079679617394330781U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1203082119358827708U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 523869107818193101U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4629501113595689157U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4028324959540432983U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15447631947468213912U;
            aOrbiterJ = RotL64((aOrbiterJ * 6037306615787729185U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14225888694733041031U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 11925000696281947629U) ^ RotL64(aNonceWordG, 51U);
            aOrbiterI = RotL64((aOrbiterI * 4337022940520411253U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15015531024930608745U) + RotL64(aNonceWordF, 31U);
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16752579225076943550U;
            aOrbiterA = RotL64((aOrbiterA * 15551083683579981439U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2432733494869267901U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10103430321388601485U;
            aOrbiterC = RotL64((aOrbiterC * 18372919379972432569U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15943360147468638325U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9782703760233558733U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 685056980418243879U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18345087852012669037U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8897505040792027675U;
            aOrbiterD = RotL64((aOrbiterD * 14333687539092412967U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 7402581293947129667U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8604208734152026945U;
            aOrbiterB = RotL64((aOrbiterB * 9965525485538037673U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + RotL64(aNonceWordE, 6U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 37U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 50U) + aOrbiterE) + RotL64(aOrbiterK, 24U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 41U)) + aOrbiterB) + RotL64(aNonceWordD, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterD, 39U));
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 27U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 21U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterF, 46U)) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Rugby_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFE1D3EA7855ECE6BULL + 0xA0A3FA37D5845AC5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA98D17CDA08F7A69ULL + 0xF0C806CAC973AB94ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC0ADABD90B92603FULL + 0xBF44CA7DC158956DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB45286BEDE756425ULL + 0xB45301AB54B2113DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB2A1FDA4DDA06D5BULL + 0x90DD4CF06A6E504AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB7CDE58DFCE63E8BULL + 0xFCDE6FF08E3A3EE4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEF760BAA7120D871ULL + 0xACA899732A4E6EBAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFDF4F29F31412487ULL + 0xE5D993C3DCB57D92ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 46U) ^ RotL64(aNonceWordC, 23U)) ^ RotL64(aNonceWordF, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7359U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2828U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordB, 57U)) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1829U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2502U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 12U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aCross, 3U)) + 6521330037475130256U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 23U)) + 12611880456055428940U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 19U)) + 12061611078130934708U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordB, 23U);
            aOrbiterA = (aWandererD + RotL64(aPrevious, 58U)) + 1558112410801116984U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 10509115227850160786U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 11U)) + 4045915960688792066U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 1196541286513243082U;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 15564991032722373702U) + RotL64(aNonceWordA, 55U);
            aOrbiterB = (aWandererE + RotL64(aScatter, 50U)) + 4897765238703641798U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12327429514907752733U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6189189797708711636U;
            aOrbiterF = RotL64((aOrbiterF * 9017615866338877651U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6374267075282018852U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1888758503831341439U;
            aOrbiterD = RotL64((aOrbiterD * 74387714918264257U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14956857689299491800U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 14879361107223331957U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9166712966729591953U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16086885494838105042U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8069724185844303923U;
            aOrbiterB = RotL64((aOrbiterB * 8878470736758734353U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10854345917959911439U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7078313614360332089U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9864025732292844871U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15083669236062255011U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 594879695916679116U;
            aOrbiterA = RotL64((aOrbiterA * 9852515479152735283U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6721466068234534523U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 475816724162626782U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4799725182757588407U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4341655358154605899U) + RotL64(aNonceWordC, 19U);
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15477254302340298586U;
            aOrbiterE = RotL64((aOrbiterE * 13961520225881974201U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10179091913200895775U) + RotL64(aNonceWordE, 40U);
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6310490897546909571U;
            aOrbiterK = RotL64((aOrbiterK * 15080621088825477613U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 28U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + RotL64(aNonceWordD, 25U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 54U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 28U) + aOrbiterD) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 47U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aScatter, 42U) + RotL64(aOrbiterA, 27U)) + aOrbiterK) + RotL64(aNonceWordH, 49U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterK, 58U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14411U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10817U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 19U) ^ RotL64(aNonceWordE, 58U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12800U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 8350U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 20U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 1210605127156905516U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 4U)) + 11964595428173569519U;
            aOrbiterG = (aWandererA + RotL64(aCross, 43U)) + 16277319029916258482U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 12369497463101824572U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 29U)) + 6201248574067068202U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 48U)) + 1727477025667206661U) + RotL64(aNonceWordG, 31U);
            aOrbiterD = ((aWandererC + RotL64(aIngress, 35U)) + 1404510627789806851U) + RotL64(aNonceWordH, 29U);
            aOrbiterK = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 6948213591282018925U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aScatter, 53U)) + 6688865181284421478U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3351130769402360855U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 12681032488906270823U) ^ RotL64(aNonceWordA, 39U);
            aOrbiterG = RotL64((aOrbiterG * 3680893896579741263U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 3591412591193726763U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16153817571210878589U;
            aOrbiterH = RotL64((aOrbiterH * 4165137036092246349U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3808228354421006630U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1427373776207504205U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4534374093769595531U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1831554180932501132U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1114853085120949215U;
            aOrbiterK = RotL64((aOrbiterK * 4264176108298812905U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 2080935638828366835U) + RotL64(aNonceWordB, 59U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16104777999646489828U;
            aOrbiterJ = RotL64((aOrbiterJ * 15205199362011777473U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9782806013673440791U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3721620299829386454U;
            aOrbiterB = RotL64((aOrbiterB * 6286765834910272409U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4013706412064296527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5751022780695158579U;
            aOrbiterC = RotL64((aOrbiterC * 13766736471646116397U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17684546333240329338U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 1106947111128020920U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3158839453318658951U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11564229705849500598U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1585817314460274286U;
            aOrbiterE = RotL64((aOrbiterE * 12687162159791577431U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 6U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 60U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterK, 21U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterJ, 51U)) + RotL64(aNonceWordD, 4U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 41U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterH, 37U)) + RotL64(aNonceWordF, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterG, 5U));
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 46U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 28U) ^ RotL64(aNonceWordB, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19474U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 21864U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordC, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18035U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((aIndex + 16615U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 40U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 10U)) + RotL64(aCarry, 37U)) + 5568146815535263910U) + RotL64(aNonceWordB, 49U);
            aOrbiterE = (aWandererF + RotL64(aCross, 57U)) + 7736084960873834666U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 1336413621817562093U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 19U)) + 5218462026934984692U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 5U)) + 7048890985969555935U) + RotL64(aNonceWordE, 13U);
            aOrbiterG = (aWandererH + RotL64(aScatter, 43U)) + 13415955213864702118U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 34U)) + 5657023257021528548U;
            aOrbiterK = (aWandererA + RotL64(aCross, 39U)) + 14338310943137497116U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 12305161641833950473U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14514226578370459131U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12692904083266024340U;
            aOrbiterA = RotL64((aOrbiterA * 14800805065279908839U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11012959130001327964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7106471380403489078U;
            aOrbiterB = RotL64((aOrbiterB * 515626559384817223U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3718101961355280891U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13364192077222322664U;
            aOrbiterC = RotL64((aOrbiterC * 1411328915372590283U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6720867800318913440U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14497243926965866546U) ^ RotL64(aNonceWordF, 45U);
            aOrbiterE = RotL64((aOrbiterE * 13595058589060114653U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5789056168233262435U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 14438482587495779937U) ^ RotL64(aNonceWordH, 11U);
            aOrbiterI = RotL64((aOrbiterI * 10593535547917767263U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 313917798940179945U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15241845511889502917U;
            aOrbiterG = RotL64((aOrbiterG * 16483477103771326107U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3591957424821693032U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1559050939014453558U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17933346117866604725U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15340590914441451383U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5538037287390050110U;
            aOrbiterK = RotL64((aOrbiterK * 4082576643144951473U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4151270491894969214U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 263593701314144898U;
            aOrbiterF = RotL64((aOrbiterF * 10372046955804512457U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 26U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 54U)) + aOrbiterD) + RotL64(aNonceWordG, 53U));
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 50U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + RotL64(aNonceWordA, 54U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 52U) + aOrbiterF) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 28U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordH, 35U)) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27579U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25595U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordE, 29U)) ^ RotL64(aNonceWordB, 14U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25999U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 28884U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 52U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aIngress, 47U)) + 14624277139785904404U) + RotL64(aNonceWordH, 50U);
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 18U)) + 6966977309498165611U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 205536824352530761U) + RotL64(aNonceWordA, 29U);
            aOrbiterH = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 16629575265808255692U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 596881340147972746U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 27U)) + 11944412799107412650U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 22U)) + 4615021315668210206U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 5U)) + 8497630055977606216U;
            aOrbiterD = (aWandererG + RotL64(aCross, 57U)) + 11131601107309336885U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5935883479805510099U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15629346719765798174U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8535523790685945275U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 5279128339113651273U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16778365912440331821U) ^ RotL64(aNonceWordD, 49U);
            aOrbiterK = RotL64((aOrbiterK * 705421028266789241U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16003052937645491524U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6723226158737614764U;
            aOrbiterB = RotL64((aOrbiterB * 16690657664909260573U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9785784358981219543U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10055457337292292710U;
            aOrbiterI = RotL64((aOrbiterI * 17919129940751761111U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11779163108592974175U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1177999477942202687U;
            aOrbiterH = RotL64((aOrbiterH * 13475069421684114643U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9190694445141492214U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15605342360346353457U;
            aOrbiterA = RotL64((aOrbiterA * 14547769706392595647U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14877565450677523492U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 1074095623308025684U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ RotL64(aNonceWordB, 17U);
            aOrbiterF = RotL64((aOrbiterF * 7884068939436891093U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12803174154216941583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8813356463693637033U;
            aOrbiterD = RotL64((aOrbiterD * 4898237214617563167U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6063909634038581414U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 15112191502834052566U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6780741782103553485U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 46U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 13U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterF, 19U)) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 3U)) + aOrbiterK) + RotL64(aNonceWordE, 47U));
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 14U) + RotL64(aOrbiterA, 30U)) + aOrbiterB) + RotL64(aNonceWordG, 45U)) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 4U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 14U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Rugby_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC77D6A1FE9A5CBEFULL + 0xB0CCD1D48435F021ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF63EFCB20DA1D4D1ULL + 0xE927BA89F3CAE708ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE263EECC292ED32FULL + 0x9AECBC1A7583D33FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8EB79279A02C2DA3ULL + 0xCE55E52D395E301FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE880EB8E102DD56DULL + 0xD7F76E938B9D57F2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8F0179B8436DBC37ULL + 0x941B59856564C2E4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF9D2601498B4B2BFULL + 0xB4A09D394A171FD1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE81062247FB4D759ULL + 0xA480122C27E83DC7ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordC, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5057U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5962U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 20U) ^ RotL64(aNonceWordF, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4328U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 7253U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 56U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 57U)) + 15316464782468770057U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 47U)) + 6642872057476351588U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 660732654689529192U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 4U)) + RotL64(aCarry, 51U)) + 7235418086884000655U) + RotL64(aNonceWordH, 19U);
            aOrbiterG = (((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 14784518476694580493U) + RotL64(aNonceWordF, 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12222433977933449375U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8573001207708329927U;
            aOrbiterI = RotL64((aOrbiterI * 17771120145431297541U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16035256260815013172U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 15767726974121910203U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 719060452537759331U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17712217935322939971U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13488963456923357159U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16785285630840310405U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10222949131965611079U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1495561412321657209U;
            aOrbiterD = RotL64((aOrbiterD * 9706305581868526265U), 5U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 16156530750584361434U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + RotL64(aNonceWordG, 50U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7773792489045606309U) ^ RotL64(aNonceWordB, 13U);
            aOrbiterG = RotL64((aOrbiterG * 10730624207715601393U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterG, 11U));
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 37U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 54U)) + aOrbiterI) + RotL64(aNonceWordE, 47U)) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 12U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ) + RotL64(aNonceWordA, 37U)) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 22U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 53U) ^ RotL64(aNonceWordB, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11739U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((aIndex + 14202U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 39U) ^ RotL64(aNonceWordC, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11452U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12468U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 38U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 15045917390223766480U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 10763054007033668758U) + RotL64(aNonceWordG, 59U);
            aOrbiterG = (((aWandererK + RotL64(aCross, 24U)) + RotL64(aCarry, 3U)) + 13190170142593666607U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 37U)) + 9657025731441167065U) + RotL64(aNonceWordE, 55U);
            aOrbiterC = ((aWandererB + RotL64(aScatter, 57U)) + 11433367178975954211U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17904920143996810366U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3244383020512113283U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 552521443123433353U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 6538815775171139091U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7195368312757976343U;
            aOrbiterC = RotL64((aOrbiterC * 10515679176134176565U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 18134430713910279374U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 6571776588427107976U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1]) ^ RotL64(aNonceWordF, 51U);
            aOrbiterI = RotL64((aOrbiterI * 11916502085252589161U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11830778129647517758U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9793702760907767365U;
            aOrbiterH = RotL64((aOrbiterH * 4096246227968677179U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2287235876793192036U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8951959188326141794U) ^ RotL64(aNonceWordA, 27U);
            aOrbiterA = RotL64((aOrbiterA * 9968356718110753845U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 53U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterH, 4U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordB, 50U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 43U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 23U)) + aOrbiterC) + RotL64(aNonceWordH, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordE, 20U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21615U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24470U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 41U) ^ RotL64(aNonceWordH, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22470U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 18385U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aCross, 3U)) + 3621877681473089725U) + RotL64(aNonceWordH, 38U);
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 24U)) + RotL64(aCarry, 3U)) + 4451752751536414717U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 11371625415377772117U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 41U)) + 6046792758881150619U) + RotL64(aNonceWordB, 53U);
            aOrbiterJ = ((aWandererC + RotL64(aCross, 47U)) + 8213166120394461682U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4343156661140422645U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11105271483234947905U) ^ RotL64(aNonceWordG, 17U);
            aOrbiterC = RotL64((aOrbiterC * 853531080115819287U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 348904609985341372U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12924652822526858767U;
            aOrbiterK = RotL64((aOrbiterK * 2801892489296408735U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7461211697358520287U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16551553555297890558U;
            aOrbiterG = RotL64((aOrbiterG * 16432952324635746293U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11908056404140782995U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 9147367258259948715U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10777628928376261667U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 8876461054692728610U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordA, 61U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10546855952702525404U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10071104785895309677U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 53U)) + aOrbiterC) + RotL64(aNonceWordD, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 30U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC);
            aWandererF = aWandererF + (((((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordF, 59U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterC, 13U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 36U) ^ RotL64(aNonceWordG, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26654U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 25727U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordD, 11U)) ^ RotL64(aNonceWordE, 26U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28040U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((aIndex + 29265U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 22U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((((aWandererI + RotL64(aPrevious, 46U)) + RotL64(aCarry, 13U)) + 12632404972795375757U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1]) + RotL64(aNonceWordA, 59U);
            aOrbiterF = (((aWandererA + RotL64(aIngress, 57U)) + 5351879979055988456U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + RotL64(aNonceWordC, 41U);
            aOrbiterB = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 3597737727467443413U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 2830846754917852318U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 37U)) + 17311925960294518018U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2083584640523695383U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15049343611387010158U;
            aOrbiterB = RotL64((aOrbiterB * 5567816356477420399U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6443050378205811147U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6021965178697344070U;
            aOrbiterD = RotL64((aOrbiterD * 6054064448935006741U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5080289878758029976U) + RotL64(aNonceWordF, 57U);
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 576927745306972983U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) ^ RotL64(aNonceWordE, 7U);
            aOrbiterA = RotL64((aOrbiterA * 16008958833683246115U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4728489691382690859U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6184355840165758855U;
            aOrbiterF = RotL64((aOrbiterF * 1515043910404156423U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11220539885798595450U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11091438724966718214U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8225347114759391961U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 14U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterF, 28U)) + RotL64(aNonceWordB, 14U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterA, 3U)) + RotL64(aNonceWordH, 9U));
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterI, 19U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
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

void TwistExpander_Rugby_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD57CA5FA5BEB91D9ULL + 0xDAC07BD225E2DB66ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB92A50CDB441ABB1ULL + 0x94D16FEAED9130E4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE2071BA434F53BBBULL + 0xC7AEF24F373B3BC4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFC762F15EDB66E5BULL + 0xD4027AACE969A358ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB7FB28FF99F0370DULL + 0x90D05A852F801E99ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE98CAA6F9D80A2A5ULL + 0x84744ED8F139AD1DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB1ED723926302A3DULL + 0xE52F3A7668415D66ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA45E0F4769204DDFULL + 0xB0660EB9C98AD140ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 19U) ^ RotL64(aNonceWordD, 11U)) ^ RotL64(aNonceWordH, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6526U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneC[((aIndex + 3093U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 60U) ^ RotL64(aNonceWordC, 21U)) ^ RotL64(aNonceWordF, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2291U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 6807U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 10336802574069791273U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 18U)) + RotL64(aCarry, 53U)) + 169025388197058936U;
            aOrbiterG = ((((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 6541354188379168846U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordC, 35U);
            aOrbiterA = ((aWandererD + RotL64(aCross, 57U)) + 16223920526599306104U) + RotL64(aNonceWordB, 15U);
            aOrbiterI = (aWandererG + RotL64(aPrevious, 3U)) + 12756613707692514808U;
            aOrbiterF = (aWandererF + RotL64(aCross, 47U)) + 5082475548176484035U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 29U)) + 4907435526952698526U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14236627073831834337U) + RotL64(aNonceWordE, 25U);
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11502511046130497584U;
            aOrbiterG = RotL64((aOrbiterG * 3460330807286625917U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3679044835550219497U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11254838916686736746U;
            aOrbiterI = RotL64((aOrbiterI * 8631695922983532915U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10582608424233200966U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10449735026385340313U;
            aOrbiterF = RotL64((aOrbiterF * 7363770199734997411U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4628253464169957835U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17664454668473204465U;
            aOrbiterB = RotL64((aOrbiterB * 4234720298731378527U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3798386391743884889U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 1379331161819246587U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13086160171095077295U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 9816600392407327227U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordH, 23U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16781971616348376878U;
            aOrbiterA = RotL64((aOrbiterA * 12503867584828289879U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4807797577690520554U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2492057261148595922U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9453302540675483005U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 27U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 42U) + RotL64(aOrbiterG, 13U)) + aOrbiterA) + RotL64(aNonceWordA, 28U));
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 56U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 37U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 43U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 19U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordG, 27U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordD, 27U)) ^ RotL64(aNonceWordA, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12803U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 11723U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordG, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9050U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((aIndex + 11388U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 38U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 9855743441035905047U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 13U)) + 8426286937143990276U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordF, 39U);
            aOrbiterI = (aWandererB + RotL64(aIngress, 46U)) + 7146752367170267002U;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 12947210066678101726U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 15902163559925328965U) + RotL64(aNonceWordB, 24U);
            aOrbiterH = (aWandererD + RotL64(aScatter, 29U)) + 8506649889346449469U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 23U)) + 8226286036430263052U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2703047093452420216U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6769351326360139560U;
            aOrbiterI = RotL64((aOrbiterI * 5318104980014706265U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9857025533281333281U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 238297452132277585U;
            aOrbiterJ = RotL64((aOrbiterJ * 12974709749856065985U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 7203572312072908931U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordH, 23U);
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12497027346166575632U;
            aOrbiterC = RotL64((aOrbiterC * 1703586436725662307U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 473851890609048879U) + RotL64(aNonceWordA, 37U);
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1664484956453886047U;
            aOrbiterK = RotL64((aOrbiterK * 8566500756326590209U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4635095143004754116U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17695676150967345793U;
            aOrbiterD = RotL64((aOrbiterD * 5780416541584439301U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15628965269863402796U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9190117464399730235U;
            aOrbiterH = RotL64((aOrbiterH * 5586437438425999715U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17835918238346011086U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4398005402429282682U;
            aOrbiterF = RotL64((aOrbiterF * 14828737209913317463U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 54U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + RotL64(aNonceWordE, 21U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 21U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 28U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 53U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterD, 35U)) + RotL64(aNonceWordC, 51U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterD, 41U)) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 36U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 58U) ^ RotL64(aNonceWordH, 27U)) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19236U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 23470U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordA, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21318U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 19792U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 16802219662864902427U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 14332033461409490629U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 28U)) + 8781794298640286845U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 37U)) + 8459933908074937264U;
            aOrbiterA = (aWandererE + RotL64(aCross, 57U)) + 1883580287986004426U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 17500258188004626118U) + RotL64(aNonceWordF, 51U);
            aOrbiterD = ((aWandererD + RotL64(aScatter, 19U)) + 7934811305150872870U) + RotL64(aNonceWordH, 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6380363892361098905U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12623079132626676910U;
            aOrbiterK = RotL64((aOrbiterK * 12406671746344127399U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10455208121949202703U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8805532707916767629U;
            aOrbiterE = RotL64((aOrbiterE * 666082374369701881U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9161544391400377699U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3501434325829663268U;
            aOrbiterC = RotL64((aOrbiterC * 7933545151293799637U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 651783304096081996U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 441505031509930622U;
            aOrbiterB = RotL64((aOrbiterB * 8045355432310956143U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1771159983581326424U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15227946417377695989U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1563141188972797601U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4153717524193279095U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4404521756523902829U;
            aOrbiterI = RotL64((aOrbiterI * 1410342912973206203U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6231945075461813285U) + RotL64(aNonceWordA, 43U);
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 3864780227164426690U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) ^ RotL64(aNonceWordB, 47U);
            aOrbiterD = RotL64((aOrbiterD * 18031353247480673617U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 4U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterB, 53U));
            aWandererA = aWandererA + (((RotL64(aIngress, 28U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + RotL64(aNonceWordG, 26U));
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 37U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterB, 43U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + RotL64(aNonceWordD, 37U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordB, 19U)) ^ RotL64(aNonceWordH, 38U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32181U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29185U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 56U) ^ RotL64(aNonceWordG, 29U)) ^ RotL64(aNonceWordD, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28942U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25132U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 43U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aScatter, 41U)) + 11698283336767769359U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 57U)) + 13297826354831483872U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 15254999058287530795U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 12U)) + 17474166585085346567U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 15684783498452840289U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 5061229733465216486U) + RotL64(aNonceWordD, 35U);
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 3U)) + 15370981279168377944U) + RotL64(aNonceWordH, 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17966672773619554092U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 14685092893994491068U) ^ RotL64(aNonceWordF, 20U);
            aOrbiterD = RotL64((aOrbiterD * 1627758964162892429U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12798804186209406389U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2848444181474221574U;
            aOrbiterF = RotL64((aOrbiterF * 13730480364920876877U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8551142075919636146U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8833198159158950723U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7650289040764974737U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 7351473160893666232U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14204899612487622222U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6317485031956448029U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 7008985178526543258U) + RotL64(aNonceWordC, 43U);
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13576796403863120356U;
            aOrbiterC = RotL64((aOrbiterC * 13745839827679114077U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5769784656937900699U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14075925808204936705U;
            aOrbiterI = RotL64((aOrbiterI * 5844894088757604713U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17818667502858010896U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16016922065572683130U;
            aOrbiterH = RotL64((aOrbiterH * 7525645833898085373U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterD, 6U));
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterK, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordE, 39U)) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 35U)) + aOrbiterC) + RotL64(aNonceWordG, 13U));
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterK, 27U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterA, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 28U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
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

void TwistExpander_Rugby_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9C8ACA04462B104BULL + 0x80D76EED50B4E2EBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC25B63B1A903156DULL + 0xDA7F69FEDBF42331ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFC6178F2BE34EA2DULL + 0xB8D3C9BBC181E2DEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCF272E532BF1AFBBULL + 0xE1691CB82E132A95ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCE3D295109996937ULL + 0xF301F5396628AC71ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD37CDCC460A5B785ULL + 0xFF3B8C52EF25762FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEDFC24DE20F1F009ULL + 0xA7D03EACDF06AB60ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x878127950067563FULL + 0xF553765ACBD06E7EULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordE, 43U)) ^ RotL64(aNonceWordH, 22U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1120U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 986U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordB, 52U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1861U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 6512U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 19U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aCross, 53U)) + 6069475454765660321U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 11483704742497268068U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 35U)) + 11055697447388986418U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 10897095046039997004U;
            aOrbiterJ = ((((aWandererB + RotL64(aCross, 60U)) + RotL64(aCarry, 57U)) + 4731637118230457840U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordA, 11U);
            aOrbiterD = ((aWandererC + RotL64(aIngress, 27U)) + 13855839187084986751U) + RotL64(aNonceWordF, 9U);
            aOrbiterH = (aWandererF + RotL64(aScatter, 5U)) + 5328208115460188239U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12479538544291412985U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10740165998792608231U;
            aOrbiterB = RotL64((aOrbiterB * 14046827922294477379U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6492798157284955373U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13056825957483891921U;
            aOrbiterJ = RotL64((aOrbiterJ * 14882112110627751751U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 2068184064919194657U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordG, 59U);
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5656302738780746294U;
            aOrbiterD = RotL64((aOrbiterD * 16493021179127646345U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11193756120230763294U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17306750816837208999U) ^ RotL64(aNonceWordB, 50U);
            aOrbiterH = RotL64((aOrbiterH * 7949360041241439741U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12952818800389361804U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15380412293642628312U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2914662289178925547U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 7706090204767242996U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 14598802276412649570U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4821408736292041399U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17819762117328075515U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6481384240915075101U;
            aOrbiterF = RotL64((aOrbiterF * 4836701121865783029U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 29U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aPrevious, 12U) + aOrbiterB) + RotL64(aOrbiterH, 12U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK) + RotL64(aNonceWordD, 43U));
            aWandererC = aWandererC + (((((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + RotL64(aNonceWordC, 15U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterF, 3U));
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 35U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 51U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 13U) ^ RotL64(aNonceWordF, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11925U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13644U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 26U) ^ RotL64(aNonceWordA, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11581U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9497U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 51U)) + (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aCross, 51U)) + 13687218104610230596U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 6841550124960692709U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 58U)) + 17418968668458764131U) + RotL64(aNonceWordF, 47U);
            aOrbiterA = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 8303537912696948204U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 37U)) + 12376614417285936537U) + RotL64(aNonceWordG, 39U);
            aOrbiterH = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 14215749063579232654U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 27U)) + 4111736931433665347U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11250375934571631522U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5367367837773331275U;
            aOrbiterG = RotL64((aOrbiterG * 7262723007545807179U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15514089192382674434U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1475991716685034960U;
            aOrbiterD = RotL64((aOrbiterD * 17720681295551650891U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5531622777788629748U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8363822215908303335U;
            aOrbiterA = RotL64((aOrbiterA * 17850203366840994883U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3741256932685720414U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11634667238062155772U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15925089729784547403U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 18180546911210417155U) + RotL64(aNonceWordB, 3U);
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5123234656838556335U;
            aOrbiterC = RotL64((aOrbiterC * 15362857462853398025U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 11215734271189250284U) + RotL64(aNonceWordH, 11U);
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16863747802158398092U;
            aOrbiterH = RotL64((aOrbiterH * 1828035970246160023U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9859050606636646323U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9331300036643654675U;
            aOrbiterE = RotL64((aOrbiterE * 2502263410556166281U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterA, 43U)) + RotL64(aNonceWordA, 30U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 60U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 58U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 27U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 51U)) + aOrbiterD) + RotL64(aNonceWordD, 57U));
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 22U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordC, 21U)) ^ RotL64(aNonceWordE, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17821U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16827U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 39U) ^ RotL64(aNonceWordF, 23U)) ^ RotL64(aNonceWordD, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20846U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 19188U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 3U)) + (RotL64(aPrevious, 24U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 3U)) + 7960325128608297381U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 58U)) + 12773836012104052042U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 3173972621347773016U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 3708401356314308171U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 950774285720019449U) + RotL64(aNonceWordC, 23U);
            aOrbiterC = ((aWandererB + RotL64(aScatter, 35U)) + 4170092315705438265U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aIngress, 19U)) + 17000449130864980747U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordD, 15U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8793910540062893860U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 520277969543516469U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4150613128885828229U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12762214857389827271U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2932451184340207695U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7513337346940091655U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11062179998786293839U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7919119215271524178U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9053677007180081359U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1774988449597115155U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3799792889466518953U;
            aOrbiterH = RotL64((aOrbiterH * 17512791286490623455U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1815062051307896589U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 15260373951371654483U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1]) ^ RotL64(aNonceWordE, 47U);
            aOrbiterK = RotL64((aOrbiterK * 2208604434669491625U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12867546628945676853U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 7772820973895846946U) ^ RotL64(aNonceWordG, 61U);
            aOrbiterC = RotL64((aOrbiterC * 7581704643538761985U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14213957831821966834U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16561105721170419454U;
            aOrbiterA = RotL64((aOrbiterA * 2540533987337175367U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 20U)) + aOrbiterJ) + RotL64(aNonceWordB, 25U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterK, 35U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 42U) + aOrbiterA) + RotL64(aOrbiterC, 13U)) + RotL64(aNonceWordA, 24U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterD, 27U));
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordB, 58U)) ^ RotL64(aNonceWordH, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27875U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25362U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 28U) ^ RotL64(aNonceWordD, 19U)) ^ RotL64(aNonceWordG, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30135U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 30511U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 11U)) + (RotL64(aIngress, 38U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 3U)) + 8402620908307642697U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 11U)) + 11347672014525086047U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 27U)) + 2816462912503401876U;
            aOrbiterG = (aWandererF + RotL64(aCross, 56U)) + 6940159795470696093U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 13U)) + 9134692490095883851U) + RotL64(aNonceWordE, 29U);
            aOrbiterE = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 4999455497008026526U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 5992451460350651332U) + RotL64(aNonceWordD, 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 3417087346651371924U) + RotL64(aNonceWordF, 49U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3612773820086198270U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5519856345435871169U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 463398077083428570U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 11249391303705089012U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) ^ RotL64(aNonceWordB, 11U);
            aOrbiterE = RotL64((aOrbiterE * 7106735772303292983U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17027535139825739501U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 568131384979596481U;
            aOrbiterB = RotL64((aOrbiterB * 5683451044852895957U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4793712537158004047U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10415170179135963622U;
            aOrbiterF = RotL64((aOrbiterF * 13729564030210361415U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2391473979460065630U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4240058362680064261U;
            aOrbiterA = RotL64((aOrbiterA * 12375884373396400889U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9963957011090031698U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3325305624067445525U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3128542681461806309U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2094945647665114693U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10703615640774042674U;
            aOrbiterJ = RotL64((aOrbiterJ * 12641986098450423751U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 4U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterE, 19U)) + RotL64(aNonceWordA, 7U)) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 51U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 58U)) + aOrbiterB) + RotL64(aNonceWordH, 12U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 29U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Rugby_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBE26D33348437EB5ULL + 0x95F7F67839D049F5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFEDFC5B7A3E87227ULL + 0x9245E3FDC64C9130ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDB6ABB3B1839E8EDULL + 0x81219F6D37D921FBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF9916F8982EE31D9ULL + 0xA514DAF020E6A8B4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8F1FAB949FDCB881ULL + 0xA5ACC33965843104ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8F66D5977B57CB45ULL + 0xAD9873FB7AB3F863ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFD3ABB9045440AABULL + 0xE0055AF354EAE379ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCA7BAF1B017901C3ULL + 0x9CAD45BC7FBDC389ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 58U) ^ RotL64(aNonceWordA, 47U)) ^ RotL64(aNonceWordF, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5860U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2813U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordH, 41U)) ^ RotL64(aNonceWordB, 60U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1557U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4537U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 44U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aCross, 19U)) + 8506388683755208267U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 23U)) + 2179323259055019735U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordB, 5U);
            aOrbiterG = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 3345902531140983016U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 4U)) + 17456139311481306584U) + RotL64(aNonceWordC, 35U);
            aOrbiterA = (aWandererC + RotL64(aPrevious, 53U)) + 14587864088462311164U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 41U)) + 13178947246650647057U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 11U)) + 12866578138946916962U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 13U)) + 13098524333655118173U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 15451329483787541982U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 48U)) + RotL64(aCarry, 43U)) + 9494299579678389385U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 43U)) + 15581954810375490643U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 4487042505730624892U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 2774455928791636186U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15847933919136777451U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12435319582397755819U) + RotL64(aNonceWordE, 20U);
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10077180055177766823U;
            aOrbiterK = RotL64((aOrbiterK * 3924363471701748703U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10391963896910956455U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6149237416725301794U;
            aOrbiterC = RotL64((aOrbiterC * 10115917698918612823U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15673402771629639978U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14729117178956592426U;
            aOrbiterE = RotL64((aOrbiterE * 9070464269215820531U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14492001279368870240U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6278248084483259952U;
            aOrbiterH = RotL64((aOrbiterH * 16731228350971263873U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15727518866499740411U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8652631010810965473U;
            aOrbiterF = RotL64((aOrbiterF * 9508484121620912715U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 13660890300188313775U) + RotL64(aNonceWordD, 23U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14699253534935936300U;
            aOrbiterJ = RotL64((aOrbiterJ * 3978135617259934869U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1621689916308271346U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5651399428852950385U;
            aOrbiterD = RotL64((aOrbiterD * 12220143634120124133U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9833573729127477238U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11171647423058940388U;
            aOrbiterA = RotL64((aOrbiterA * 9692915620701425697U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10346908196429120039U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11972183669378621435U;
            aOrbiterB = RotL64((aOrbiterB * 12364429258926549335U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11063215816236490488U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8506388683755208267U;
            aOrbiterI = RotL64((aOrbiterI * 11514304191652750181U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 60U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + RotL64(aNonceWordF, 61U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 5U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 36U) + RotL64(aOrbiterA, 37U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterE, 53U)) + RotL64(aNonceWordA, 15U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 42U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterG, 19U));
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 21U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 34U) + aOrbiterI) + RotL64(aOrbiterD, 35U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 13U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterF, 50U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordH, 21U)) ^ RotL64(aNonceWordB, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15919U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 12425U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordE, 20U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8844U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15963U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 4U)) + (RotL64(aCross, 51U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererC + RotL64(aIngress, 10U)) + 16922357079016918108U) + RotL64(aNonceWordA, 27U);
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 11771749797137599131U) + RotL64(aNonceWordF, 37U);
            aOrbiterB = (((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 4635668433708036077U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aCross, 21U)) + 15827952719230577008U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 57U)) + 1495675306110023086U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 43U)) + 7294835466949728365U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 34U)) + 179122461212041978U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 53U)) + 545981421632236251U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 15338259639814630535U;
            aOrbiterK = (aWandererD + RotL64(aCross, 29U)) + 12924313840290895215U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 5U)) + 17846785921286020610U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5721472794107057875U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16359630793856870319U;
            aOrbiterB = RotL64((aOrbiterB * 14186771515526698907U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10614102110239037308U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16421992251278236531U;
            aOrbiterF = RotL64((aOrbiterF * 2561232904676068089U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8668149834861244963U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12699331834360948734U) ^ RotL64(aNonceWordG, 49U);
            aOrbiterD = RotL64((aOrbiterD * 2249360824172616357U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4470693178142950471U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 526000656022724741U;
            aOrbiterE = RotL64((aOrbiterE * 16688501462334673493U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6880246132270094141U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7126466778855297013U;
            aOrbiterC = RotL64((aOrbiterC * 5692237926830293205U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6436404501390442054U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 1213633065612242699U) ^ RotL64(aNonceWordE, 21U);
            aOrbiterA = RotL64((aOrbiterA * 17604454985534439259U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8186529105901185854U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10607460957358250935U;
            aOrbiterG = RotL64((aOrbiterG * 17172191011625677861U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9743278964993305169U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14007577681873418075U;
            aOrbiterH = RotL64((aOrbiterH * 4231122580398039133U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11636165671710638530U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9334375905020670988U;
            aOrbiterI = RotL64((aOrbiterI * 8801600439900803907U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4261340110915336428U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12336921031446129288U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2306768964600968743U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2029125959974424325U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 16922357079016918108U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8718484611517064455U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 6U) + aOrbiterI) + RotL64(aOrbiterE, 19U)) + RotL64(aNonceWordC, 54U));
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 50U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterC, 53U)) + RotL64(aNonceWordD, 53U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + RotL64(aOrbiterI, 21U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 39U)) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterK, 34U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterE, 11U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterE, 27U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterB, 43U));
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterF, 37U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 22U) ^ RotL64(aNonceWordA, 3U)) ^ RotL64(aNonceWordF, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23187U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18359U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 27U) ^ RotL64(aNonceWordC, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20635U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20240U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 38U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 3612110001869385068U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 60U)) + RotL64(aCarry, 43U)) + 16340824141280225936U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 29U)) + 15222338965130765231U) + RotL64(aNonceWordF, 3U);
            aOrbiterB = ((aWandererG + RotL64(aScatter, 37U)) + 6649270508107155041U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 41U)) + 768217258655426384U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aCross, 24U)) + 4481855259658861851U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 35U)) + 18318041934562434016U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 21U)) + 4212457153804401807U) + RotL64(aNonceWordH, 27U);
            aOrbiterF = (aWandererB + RotL64(aScatter, 27U)) + 16143621095636987628U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 2095664232866642086U;
            aOrbiterC = (aWandererH + RotL64(aCross, 5U)) + 4339527736737366572U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13679353177869884790U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11582168502846418236U;
            aOrbiterA = RotL64((aOrbiterA * 135539430034462861U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10451330452898542191U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12951448817640617841U;
            aOrbiterK = RotL64((aOrbiterK * 4141870904192742091U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15389161934419370747U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4754886272708253014U;
            aOrbiterI = RotL64((aOrbiterI * 16638243718191281597U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 11746389873929280688U) + RotL64(aNonceWordC, 58U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12042680172517298768U;
            aOrbiterJ = RotL64((aOrbiterJ * 3814780289755857543U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2648103752465009244U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 451594673632597973U;
            aOrbiterH = RotL64((aOrbiterH * 8496763663271072425U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5696534794094099710U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 14609435045257077395U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14658408563237468407U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11599395126850950133U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12699598504604446664U;
            aOrbiterE = RotL64((aOrbiterE * 14313494063098111823U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9398465148537154745U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12139736860648011256U;
            aOrbiterB = RotL64((aOrbiterB * 15257503229375247987U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5390816291244486383U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 2797988892316486895U) ^ RotL64(aNonceWordE, 23U);
            aOrbiterG = RotL64((aOrbiterG * 14668138881285892065U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18356290434261054712U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16582824574485822826U;
            aOrbiterF = RotL64((aOrbiterF * 7207935384746719969U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9858803484150150915U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3612110001869385068U;
            aOrbiterC = RotL64((aOrbiterC * 2862887443435821143U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterF, 37U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 30U)) + aOrbiterF) + RotL64(aNonceWordD, 15U)) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterK, 11U)) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterC, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 35U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 6U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 43U));
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 21U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aIngress, 46U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterI, 51U)) + RotL64(aNonceWordA, 55U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 47U) ^ RotL64(aNonceWordH, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27832U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 31292U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordB, 47U)) ^ RotL64(aNonceWordG, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28212U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 28904U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 52U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aIngress, 51U)) + 5295352595333316211U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 36U)) + 2341795367042042605U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 57U)) + 10122175780504033663U;
            aOrbiterA = (aWandererA + RotL64(aCross, 23U)) + 10084612804696198554U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 16470424309851045971U) + RotL64(aNonceWordD, 9U);
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 656016130975227994U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 4U)) + RotL64(aCarry, 19U)) + 15313268829659834317U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 47U)) + 3795220914993923394U) + RotL64(aNonceWordE, 22U);
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 41U)) + 14044442220988813825U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aCross, 43U)) + 3804224626734584802U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 21U)) + 7980006306010255693U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13746830564584711549U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11852212099729274845U;
            aOrbiterJ = RotL64((aOrbiterJ * 2164880979318247855U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 9083223471018084847U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13706723820703853346U;
            aOrbiterH = RotL64((aOrbiterH * 11361854103656219887U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1713819986642275223U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1382000168233902914U;
            aOrbiterC = RotL64((aOrbiterC * 3894160765130198157U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4540474625764565485U) + RotL64(aNonceWordG, 37U);
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1756168174375757220U;
            aOrbiterD = RotL64((aOrbiterD * 12739160208010092017U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1409297070183609309U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6082750101445444357U;
            aOrbiterK = RotL64((aOrbiterK * 17438740230251860935U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1113239890859479202U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10932192439503964363U;
            aOrbiterI = RotL64((aOrbiterI * 5915660289913324281U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3732595033748508428U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5117760372351117286U;
            aOrbiterB = RotL64((aOrbiterB * 2671510075176315761U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7399968659654088641U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14835608167871904147U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8312521710415756159U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7851355416751467648U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 262169565276199916U;
            aOrbiterF = RotL64((aOrbiterF * 11801419425408657509U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1771847554312299305U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15588805765521695222U;
            aOrbiterG = RotL64((aOrbiterG * 8541206691371972017U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6162696602553964144U) + RotL64(aNonceWordF, 43U);
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5295352595333316211U;
            aOrbiterA = RotL64((aOrbiterA * 8368226841948931873U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 21U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ) + RotL64(aNonceWordC, 49U));
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 3U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterG, 60U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterG, 57U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 10U) + aOrbiterC) + RotL64(aOrbiterG, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 52U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterD, 35U)) + RotL64(aNonceWordB, 51U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Rugby_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC7979BD69E6E8833ULL + 0xD01563E272B5E020ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x936379330D92F403ULL + 0x872E01E7F20CD221ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x928968A8ED8B900DULL + 0xE98CBF6CA7521B67ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEB5FF289F30830A9ULL + 0xE7274C8D2A7EE0DBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC164578B66030927ULL + 0xA51B33A24599C1D4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCD2510FBBE0D1447ULL + 0xABF05FC03E45F922ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC5E33D522EF3A0D5ULL + 0x8363322BB3FF8EBFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x82B88B282C7E503BULL + 0x96292A939B8BE5F7ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordD, 24U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1005U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4695U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordA, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 171U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 4488U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 6U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 1142447269198373880U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordE, 31U);
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 10581460640040336191U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 34U)) + RotL64(aCarry, 29U)) + 14703062773878202900U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 57U)) + 15737525756286914746U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 53U)) + 16178774478273186999U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 5U)) + 2514897053906809160U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 47U)) + 13702496607592508464U) + RotL64(aNonceWordF, 55U);
            aOrbiterE = (aWandererE + RotL64(aCross, 21U)) + 18030885275418337965U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 28U)) + 5241783876161655984U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2807052676283587925U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8022804576763271327U) ^ RotL64(aNonceWordC, 45U);
            aOrbiterH = RotL64((aOrbiterH * 11727096043219370577U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15597099852232205860U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1538435607932096400U;
            aOrbiterF = RotL64((aOrbiterF * 7900752511710516981U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11147868774413615365U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9325213746830411568U;
            aOrbiterE = RotL64((aOrbiterE * 561819005818948769U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13792300423550555634U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3134856508983945719U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4271845067763664863U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8654966018053784882U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 8937113935476779267U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7386875687217705855U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4135676350355234788U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 11407912615743682678U) ^ RotL64(aNonceWordB, 50U);
            aOrbiterG = RotL64((aOrbiterG * 2773506587480714695U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10966950663872392059U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6686634993700944582U;
            aOrbiterK = RotL64((aOrbiterK * 2509459942163678241U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14154407529749257990U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 18054640398549782388U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7830759861389060149U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14623473030642960240U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1857945571104460086U;
            aOrbiterI = RotL64((aOrbiterI * 18039903315045620079U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterH, 18U));
            aWandererE = aWandererE + (((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 23U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 53U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterF, 13U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 28U) + aOrbiterE) + RotL64(aOrbiterG, 35U)) + RotL64(aNonceWordA, 7U)) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + RotL64(aNonceWordD, 11U));
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 48U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererC, 40U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordE, 53U)) ^ RotL64(aNonceWordC, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10189U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7010U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 4U) ^ RotL64(aNonceWordA, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8085U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8653U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 1457104756581596530U;
            aOrbiterA = (aWandererI + RotL64(aCross, 13U)) + 6127240317844622874U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 5U)) + 16492290056044189421U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 10963676850938416468U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 42U)) + 4872917367399752405U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 53U)) + 15218882377875616148U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 5934166612122118251U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 23U)) + 14215280930872003003U) + RotL64(aNonceWordA, 21U);
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 34U)) + 11428034799044600979U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordD, 59U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5453003654321728726U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14273775120265649389U;
            aOrbiterJ = RotL64((aOrbiterJ * 5139018128323795309U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 328723770018440271U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13032190719588211088U;
            aOrbiterI = RotL64((aOrbiterI * 13363368478932798315U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2386881543033598494U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1649501123340887116U;
            aOrbiterD = RotL64((aOrbiterD * 11148976582360499033U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16462401546754210583U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1510579201823042227U;
            aOrbiterK = RotL64((aOrbiterK * 16287912400104043275U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6889066000014251983U) + RotL64(aNonceWordG, 41U);
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11324594596597724357U;
            aOrbiterB = RotL64((aOrbiterB * 15344987814648586023U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12237796033168436537U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17306069670330000343U;
            aOrbiterG = RotL64((aOrbiterG * 3167451351403385259U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14197284538008811658U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 4754134852883071927U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3484427259538998699U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17201907781639753736U) + RotL64(aNonceWordE, 40U);
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8318419319239859855U;
            aOrbiterF = RotL64((aOrbiterF * 10320390501983802091U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16012488623961565780U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 15583721012865354925U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10656414363201743961U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 18U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 18U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ) + RotL64(aNonceWordH, 17U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 19U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 56U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 13U)) + aOrbiterF) + RotL64(aNonceWordF, 43U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterG, 41U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 14U) + aOrbiterI) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterI, 34U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordD, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11333U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 12747U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordB, 3U)) ^ RotL64(aNonceWordE, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12805U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11857U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 13U)) + (RotL64(aIngress, 40U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aIngress, 12U)) + 2168513956284366370U) + RotL64(aNonceWordA, 61U);
            aOrbiterA = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 10290361969974613111U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 29U)) + 15673836275828498050U) + RotL64(aNonceWordG, 17U);
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 16600540024145812236U;
            aOrbiterI = (aWandererH + RotL64(aCross, 47U)) + 9428052101528111892U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 36U)) + RotL64(aCarry, 13U)) + 12763657928312763377U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 41U)) + 10751286982008662485U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 57U)) + 1708230173038057979U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 3U)) + 4011389705422783816U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11704428328093077714U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2055336619674699284U;
            aOrbiterD = RotL64((aOrbiterD * 6374289210096410907U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1870865272102705804U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 3574214263751923179U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13132083406834413563U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 984611970726966186U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15207945449947643672U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9539470161576639981U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 4181398506373973169U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15222345431506025949U;
            aOrbiterA = RotL64((aOrbiterA * 6925143692628659467U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15023513452326240962U) + RotL64(aNonceWordD, 36U);
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14965669361708810699U;
            aOrbiterI = RotL64((aOrbiterI * 587008860996713147U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7985755518735406360U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 225592097619240187U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2313509354133400439U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3659537916566939383U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17043668033610689611U;
            aOrbiterJ = RotL64((aOrbiterJ * 10797634709118100773U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10217321522161675848U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8013663869536146842U;
            aOrbiterE = RotL64((aOrbiterE * 2293233079384777175U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13762445330867496042U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2692400019659269106U) ^ RotL64(aNonceWordF, 3U);
            aOrbiterC = RotL64((aOrbiterC * 167704184292219399U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 14U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 36U) + aOrbiterH) + RotL64(aOrbiterK, 53U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 5U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterJ, 27U));
            aWandererB = aWandererB + ((RotL64(aCross, 48U) + RotL64(aOrbiterH, 35U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterE, 21U)) + RotL64(aNonceWordC, 13U));
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 43U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterE, 48U)) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordB, 15U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 4U) ^ RotL64(aNonceWordD, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17737U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 17756U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordB, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16431U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneD[((aIndex + 19184U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 12U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 47U)) + 7651355040951791298U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 18U)) + 13988210277931659312U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 51U)) + 9846849412579537783U) + RotL64(aNonceWordD, 31U);
            aOrbiterI = (aWandererK + RotL64(aIngress, 3U)) + 12746719939495876158U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 11498066185182895284U) + RotL64(aNonceWordF, 53U);
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 40U)) + RotL64(aCarry, 41U)) + 11101058955193080232U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 15513734459555672046U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 11U)) + 15711108675349394643U;
            aOrbiterA = (aWandererH + RotL64(aCross, 23U)) + 4771231759949468556U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11449258010811305256U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 17036938391509986723U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7411466953205347639U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6999245666776654250U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2106819066263369528U;
            aOrbiterH = RotL64((aOrbiterH * 13005885810757743129U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12716183358903477216U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16752724547046059889U;
            aOrbiterB = RotL64((aOrbiterB * 11475905692393034141U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 17623077680983093163U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6726003022297274986U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14709385877103232653U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 2842410225096524740U) + RotL64(aNonceWordE, 3U);
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9235178377537910514U;
            aOrbiterI = RotL64((aOrbiterI * 11813751114775673845U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2619888019860844610U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6295481948199619613U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15429161806953951205U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9724921158061115570U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4070976180958458679U;
            aOrbiterD = RotL64((aOrbiterD * 6080566609081811453U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5864247978960125554U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7771249710071026757U;
            aOrbiterA = RotL64((aOrbiterA * 4787660062590737657U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15006900854988166845U) + RotL64(aNonceWordA, 59U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2755659268987119046U;
            aOrbiterJ = RotL64((aOrbiterJ * 8043939381186802359U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (RotL64(aOrbiterB, 10U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 52U)) + aOrbiterE) + RotL64(aNonceWordC, 23U));
            aWandererF = aWandererF + ((RotL64(aScatter, 10U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + RotL64(aCarry, 43U)) + RotL64(aNonceWordH, 20U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterK, 35U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterB, 6U)) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 6U) ^ RotL64(aNonceWordA, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22008U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26677U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 48U) ^ RotL64(aNonceWordF, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25496U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 25729U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aPrevious, 18U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aScatter, 58U)) + 4384716820085860551U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 51U)) + 9715780315942116888U) + RotL64(aNonceWordE, 34U);
            aOrbiterI = (aWandererF + RotL64(aIngress, 47U)) + 15963520052789178632U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 14346700690686392938U) + RotL64(aNonceWordD, 61U);
            aOrbiterA = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 6005518012489966643U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 29U)) + 2506732930310252119U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 16782163084851775826U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 42U)) + 823673076571076303U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 13U)) + 1634084509064077736U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 1288134975466877686U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 2998220403162908444U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) ^ RotL64(aNonceWordA, 59U);
            aOrbiterI = RotL64((aOrbiterI * 4321412662318298283U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 220430672180734911U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10223923547068528867U;
            aOrbiterC = RotL64((aOrbiterC * 12577370238343872139U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 11696469696177647608U) + RotL64(aNonceWordB, 17U);
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6545430420379636963U;
            aOrbiterK = RotL64((aOrbiterK * 8387163146257553773U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 79691451831797107U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8971444023498649419U;
            aOrbiterG = RotL64((aOrbiterG * 7148919880477390009U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5624403902454498793U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9468064161002030997U;
            aOrbiterF = RotL64((aOrbiterF * 8243560528100864595U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4619361544913629805U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12682446273369750704U;
            aOrbiterH = RotL64((aOrbiterH * 10879074713156075641U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8728730962617599223U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9099675924074253030U;
            aOrbiterE = RotL64((aOrbiterE * 5525644236954497523U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 3298303921318288541U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5953276499411658358U;
            aOrbiterD = RotL64((aOrbiterD * 10565471305001292693U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6725769507592688539U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1057277456510215817U;
            aOrbiterA = RotL64((aOrbiterA * 8269412198279297075U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 44U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterC, 57U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 48U)) + aOrbiterG) + RotL64(aCarry, 57U)) + RotL64(aNonceWordH, 45U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 50U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + RotL64(aNonceWordC, 11U));
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterK, 53U));
            aWandererF = aWandererF + ((((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterH, 5U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterA, 21U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 26U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 39U) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32401U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 30917U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 28U) ^ RotL64(aNonceWordD, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31718U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30161U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 56U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererC + RotL64(aPrevious, 34U)) + 16802219662864902427U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 14332033461409490629U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 51U)) + 8781794298640286845U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 8459933908074937264U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 3U)) + 1883580287986004426U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 23U)) + 17500258188004626118U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 57U)) + 7934811305150872870U) + RotL64(aNonceWordE, 60U);
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 44U)) + RotL64(aCarry, 53U)) + 6380363892361098905U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 19U)) + 12623079132626676910U) + RotL64(aNonceWordG, 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10455208121949202703U) + RotL64(aNonceWordF, 3U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8805532707916767629U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 666082374369701881U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9161544391400377699U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3501434325829663268U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7933545151293799637U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 651783304096081996U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 441505031509930622U;
            aOrbiterG = RotL64((aOrbiterG * 8045355432310956143U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1771159983581326424U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15227946417377695989U;
            aOrbiterD = RotL64((aOrbiterD * 1563141188972797601U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4153717524193279095U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4404521756523902829U;
            aOrbiterJ = RotL64((aOrbiterJ * 1410342912973206203U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6231945075461813285U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3864780227164426690U;
            aOrbiterC = RotL64((aOrbiterC * 18031353247480673617U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1509699687948576558U) + RotL64(aNonceWordB, 39U);
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17316114302489411191U;
            aOrbiterB = RotL64((aOrbiterB * 15490661284980281585U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2250572827340157410U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6403966113144372915U;
            aOrbiterA = RotL64((aOrbiterA * 726441947009132383U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2329903609147403156U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2486330017319455238U;
            aOrbiterF = RotL64((aOrbiterF * 17427461345935191757U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 58U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 10U) + aOrbiterD) + RotL64(aOrbiterK, 60U));
            aWandererE = aWandererE + ((((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordA, 27U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 51U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 43U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 39U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterF, 56U));
            aWandererD = aWandererD + (((RotL64(aScatter, 24U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + RotL64(aNonceWordH, 55U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 47U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Rugby_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBB2A60D88A092CB3ULL + 0xE0D636CE414E3BC6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDB81894D1E4C3973ULL + 0x857E7003961E3F42ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE4BA9F765F29CC8FULL + 0xE94B30F373545E67ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x91749D7AF4474035ULL + 0xF738647B73A47999ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB790D83BEE379065ULL + 0xA04E0012C9C5CA9FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA867821F3D30ACBBULL + 0xA053AED4670BF0D2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEA0C53E2E0FDF1A1ULL + 0xCFD1EF5C1082244BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE5E31B6079996FF5ULL + 0xEA1A8D73013072F9ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordF, 47U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3406U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 3804U)) & W_KEY1], 22U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordA, 57U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 2114U)) & W_KEY1], 12U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4970U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 27U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aCross, 21U)) + 10336802574069791273U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 47U)) + 169025388197058936U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 29U)) + 6541354188379168846U) + aPhaseAOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 53U)) + 16223920526599306104U) + RotL64(aNonceWordE, 40U);
            aOrbiterG = ((((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 57U)) + 12756613707692514808U) + aPhaseAOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordC, 41U);
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 5082475548176484035U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 4907435526952698526U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14236627073831834337U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11502511046130497584U;
            aOrbiterA = RotL64((aOrbiterA * 3460330807286625917U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3679044835550219497U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11254838916686736746U) ^ RotL64(aNonceWordF, 59U);
            aOrbiterG = RotL64((aOrbiterG * 8631695922983532915U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 10582608424233200966U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10449735026385340313U;
            aOrbiterB = RotL64((aOrbiterB * 7363770199734997411U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4628253464169957835U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 17664454668473204465U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4234720298731378527U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3798386391743884889U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 1379331161819246587U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) ^ RotL64(aNonceWordH, 17U);
            aOrbiterD = RotL64((aOrbiterD * 13086160171095077295U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9816600392407327227U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16781971616348376878U;
            aOrbiterC = RotL64((aOrbiterC * 12503867584828289879U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4807797577690520554U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2492057261148595922U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9453302540675483005U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 4U) + aOrbiterD) + RotL64(aOrbiterG, 29U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 50U)) + aOrbiterK) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 37U)) + RotL64(aNonceWordG, 39U));
            aWandererA = aWandererA + ((((RotL64(aCross, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterB) + RotL64(aCarry, 23U)) + RotL64(aNonceWordB, 55U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 37U) ^ RotL64(aNonceWordA, 12U)) ^ RotL64(aNonceWordH, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10457U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7593U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordD, 43U)) ^ RotL64(aNonceWordF, 4U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 10770U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 9500U)) & W_KEY1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 43U) + RotL64(aPrevious, 28U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (((aWandererE + RotL64(aCross, 19U)) + 3550722402315312207U) + aPhaseAOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordE, 29U);
            aOrbiterA = (((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 16724184551669522754U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 43U)) + 981751330116773021U) + RotL64(aNonceWordG, 42U);
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 12U)) + 7891159229704944868U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 13618396711464799841U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 5969291018449003648U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 57U)) + 14595540413313640042U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3287990436916111762U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12534369400200483704U) ^ RotL64(aNonceWordD, 47U);
            aOrbiterF = RotL64((aOrbiterF * 2345945228434740707U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2277312067930392274U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10026320559261334353U;
            aOrbiterC = RotL64((aOrbiterC * 11020464940995912637U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11258082063135659551U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1445958517675746990U;
            aOrbiterG = RotL64((aOrbiterG * 10062265337488757971U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 1011298251290970844U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6487834862470043744U;
            aOrbiterA = RotL64((aOrbiterA * 15477913837027179675U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9966279022928268335U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10285993486057704393U;
            aOrbiterH = RotL64((aOrbiterH * 15965714363201157535U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16005362468813966136U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 223843444699390781U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 665392038954573081U), 43U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 18178876294968532775U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordF, 27U);
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12490136112181806806U;
            aOrbiterI = RotL64((aOrbiterI * 16380841616662993709U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 51U)) + aOrbiterG) + aPhaseAWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterA, 5U));
            aWandererH = aWandererH + (((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + RotL64(aNonceWordB, 51U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterE, 20U)) + aPhaseAWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + RotL64(aNonceWordH, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordG, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15384U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 14485U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 47U) ^ RotL64(aNonceWordB, 11U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12259U)) & W_KEY1], 26U) ^ RotL64(aKeyRowReadB[((aIndex + 10928U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 54U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 35U)) + 6654158889644956636U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 41U)) + 9045779659363991870U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 27U)) + 3888897662136993491U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 6882016842864459345U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 15601891715956172291U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 6U)) + RotL64(aCarry, 35U)) + 5176811598629335350U) + RotL64(aNonceWordH, 35U);
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 13U)) + 12519945150889074325U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordE, 45U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4552583214397603278U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 14225482701804864688U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8526052833180466359U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5485298070606280363U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 11237713257388094289U) ^ RotL64(aNonceWordC, 55U);
            aOrbiterB = RotL64((aOrbiterB * 11032429223099413011U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14340345895626142788U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16275167270553643347U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7308578867128951199U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14041860597556520250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1436068974197066343U;
            aOrbiterG = RotL64((aOrbiterG * 3938460345031496843U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11483155566419547004U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4608508534724289325U;
            aOrbiterD = RotL64((aOrbiterD * 13461385011638899485U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2389196334288832895U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4062682330273866602U;
            aOrbiterH = RotL64((aOrbiterH * 8787682133271101901U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5655656046585592034U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 7977947821249746880U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) ^ RotL64(aNonceWordA, 5U);
            aOrbiterA = RotL64((aOrbiterA * 10082104644185964787U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 20U)) + aOrbiterG) + RotL64(aNonceWordF, 14U));
            aWandererC = aWandererC + ((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 39U)) + aOrbiterH) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + RotL64(aCarry, 41U)) + RotL64(aNonceWordG, 41U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterB, 3U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 13U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterI, 27U)) + aPhaseAWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 47U) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18235U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19497U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 6U) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18392U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 19452U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aPrevious, 19U)) ^ (RotL64(aCross, 47U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 17912271996338180948U;
            aOrbiterH = (((aWandererH + RotL64(aCross, 12U)) + RotL64(aCarry, 29U)) + 13259276608841847058U) + aPhaseAOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 16225936008657276089U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 21U)) + 2243058962151834071U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordC, 27U);
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 41U)) + 10637439274127347861U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 51U)) + 15312219216405992627U) + RotL64(aNonceWordG, 39U);
            aOrbiterA = (aWandererI + RotL64(aIngress, 57U)) + 2393933972129878613U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4327069337247976513U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8307656353434167837U) ^ RotL64(aNonceWordE, 11U);
            aOrbiterJ = RotL64((aOrbiterJ * 11386588389133096705U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17299145556933889336U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 14458100581172798164U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16543734663677070509U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6410095654927998067U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 6168964796264687686U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) ^ RotL64(aNonceWordB, 43U);
            aOrbiterH = RotL64((aOrbiterH * 16218071040190475953U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3667999465041020730U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16021552859323602007U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6427266472526362663U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12941668202330045095U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4222032891850449934U;
            aOrbiterG = RotL64((aOrbiterG * 17292856787431308097U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1346342592002730785U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16860611785008118820U;
            aOrbiterC = RotL64((aOrbiterC * 384963420804756607U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3193572711804730241U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5866881282680588589U;
            aOrbiterA = RotL64((aOrbiterA * 9226331800853634597U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 37U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + aPhaseAWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterD, 57U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 44U) + aOrbiterD) + RotL64(aOrbiterG, 20U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordF, 15U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ) + RotL64(aNonceWordH, 28U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 36U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 4U) ^ RotL64(aNonceWordB, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22636U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22043U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 37U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25385U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22557U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 8375305456876489425U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 57U)) + 16193562952772453047U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 37U)) + 18088652458594816223U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 4U)) + 767344788620249944U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 19U)) + 7705194930396368752U) + aPhaseAOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 3829736891311272834U) + aPhaseAOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordA, 21U);
            aOrbiterC = (((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 9881681671347640061U) + RotL64(aNonceWordH, 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 1721196560190164264U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3002652618388454213U;
            aOrbiterF = RotL64((aOrbiterF * 15289749311593032657U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9811621464004005202U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5652598941069986530U;
            aOrbiterD = RotL64((aOrbiterD * 4797973356708091621U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 6250499348327316328U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordD, 14U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 16025054277615264530U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16446892258704281903U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13800298546867243172U) + RotL64(aNonceWordF, 17U);
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12256104592865905782U;
            aOrbiterK = RotL64((aOrbiterK * 16983140179497142713U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17817225416918329229U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17738671327352776217U;
            aOrbiterE = RotL64((aOrbiterE * 393488251327705063U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6816031224188400541U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16989563985059237014U;
            aOrbiterB = RotL64((aOrbiterB * 8677884225771717797U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16891524847268207549U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1833508573940405571U;
            aOrbiterC = RotL64((aOrbiterC * 9709196587703979539U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 28U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 13U)) + aOrbiterK) + aPhaseAWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterD, 60U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + RotL64(aNonceWordB, 29U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordG, 3U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 51U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 18U) + RotL64(aOrbiterF, 3U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 19U) ^ RotL64(aNonceWordG, 48U)) ^ RotL64(aNonceWordC, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31307U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 30748U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 24U) ^ RotL64(aNonceWordF, 51U)) ^ RotL64(aNonceWordB, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30949U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28836U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 11177787645248006236U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 22U)) + RotL64(aCarry, 21U)) + 3808340254579817169U) + RotL64(aNonceWordG, 25U);
            aOrbiterK = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 828030667598518279U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 51U)) + 16177835921238398371U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 29U)) + 5518747735458708741U) + aPhaseAOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 35U)) + 17346319082399995165U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 3U)) + 6397156921893030937U) + RotL64(aNonceWordH, 31U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15559381654710713582U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 940404446491415088U;
            aOrbiterK = RotL64((aOrbiterK * 16401260971303026881U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8047166032048732645U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4688468645859470491U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14383536431614496369U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 3710878044770337260U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordB, 49U);
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 116343189456629220U;
            aOrbiterF = RotL64((aOrbiterF * 5637725064169289339U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 883908030159391659U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 18058691521694880482U;
            aOrbiterD = RotL64((aOrbiterD * 3132200449123497619U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17521015077103586117U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3668332225435714918U;
            aOrbiterI = RotL64((aOrbiterI * 12658899101297839881U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12229480388278883300U) + RotL64(aNonceWordD, 7U);
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16206524049491531816U;
            aOrbiterC = RotL64((aOrbiterC * 11122340196620859805U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5743265849441077466U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2812293020719282236U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8903956475200417109U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 50U) + RotL64(aOrbiterC, 29U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 41U)) + aPhaseAWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 22U)) + aOrbiterH) + RotL64(aNonceWordA, 56U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 53U)) + aOrbiterI) + RotL64(aNonceWordF, 29U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 5U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Rugby_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF7BAA5D3903B8521ULL + 0xBD3441B3D8339B32ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEB84D1918A5E79ADULL + 0xB5CB4D16ACF85E07ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD93ECAE0C3FDE11DULL + 0xF6F0AEA0A0460D18ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCB9C6A4B3B6FA885ULL + 0xF8E84324DC68BC7CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x842D3365CDCE8571ULL + 0xFD19656C8B046D90ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF7195FFF431C87BDULL + 0xF9503463D5702B63ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA613A216E1B15031ULL + 0xBFEC1BD7363A0577ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBCFBDD3C7FE0DB8BULL + 0xF9F0125A5C5D8FFBULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordA, 14U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4429U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 4770U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordF, 57U)) ^ RotL64(aNonceWordC, 36U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2797U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3216U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 54U)) + (RotL64(aCarry, 13U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 5088525177670191619U) + RotL64(aNonceWordC, 31U);
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 57U)) + 9966456257813932112U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordD, 3U);
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 7707646574027146307U;
            aOrbiterE = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 75480203757681173U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 38U)) + 384659134071835163U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3158769775373307778U) + RotL64(aNonceWordG, 42U);
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17360830943513941272U;
            aOrbiterC = RotL64((aOrbiterC * 9986023786908098621U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5317278822721604586U) + RotL64(aNonceWordH, 49U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1371427105215954781U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10956603063464438611U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3162710551223553423U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5332921933853550756U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11709546145149357887U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 10572462410297815854U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10234389605554817892U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2130374833440291193U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13421365517991380605U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10186643614984034083U;
            aOrbiterD = RotL64((aOrbiterD * 8554471709467808453U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + RotL64(aNonceWordA, 19U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 39U)) + aOrbiterC) + RotL64(aNonceWordB, 53U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 37U) ^ RotL64(aNonceWordA, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10588U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 7014U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 36U) ^ RotL64(aNonceWordF, 27U)) ^ RotL64(aNonceWordD, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8906U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5873U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 18U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 13296600294247799698U) + RotL64(aNonceWordF, 36U);
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 54U)) + RotL64(aCarry, 35U)) + 5818503518080877515U) + RotL64(aNonceWordA, 53U);
            aOrbiterG = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 47U)) + 6735784238734173597U) + aPhaseBOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 11U)) + 7368398209488856201U) + aPhaseBOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 19U)) + 961734029066455638U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 797011946660892011U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 12841876018396622350U) ^ RotL64(aNonceWordH, 23U);
            aOrbiterG = RotL64((aOrbiterG * 14056540056414153277U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16213253970483895623U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15186950557113470375U;
            aOrbiterF = RotL64((aOrbiterF * 4647470430467908107U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5117930310827477341U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12265429373166094162U;
            aOrbiterB = RotL64((aOrbiterB * 1522823535151532249U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 13920531346698601568U) + RotL64(aNonceWordE, 5U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 14695405206998211456U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13950964363414164279U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7851960904825938443U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9501511171732550190U;
            aOrbiterE = RotL64((aOrbiterE * 5614164120361489613U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 52U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordB, 61U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 48U));
            aWandererE = aWandererE + ((((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 24U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 37U)) + aOrbiterF) + RotL64(aNonceWordC, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordF, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11067U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14171U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 10U) ^ RotL64(aNonceWordE, 47U)) ^ RotL64(aNonceWordH, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15606U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13646U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 34U) ^ RotL64(aCarry, 19U)) + (RotL64(aIngress, 51U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = ((aWandererJ + RotL64(aCross, 43U)) + 10915618884692072446U) + aPhaseBOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 12634922308499254909U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 14U)) + RotL64(aCarry, 23U)) + 6533934734564499389U) + RotL64(aNonceWordG, 43U);
            aOrbiterC = ((((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 6744203303756105181U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordC, 7U);
            aOrbiterI = (aWandererC + RotL64(aCross, 23U)) + 13086782386652045658U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5693840533331397822U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1803663542535024611U;
            aOrbiterG = RotL64((aOrbiterG * 8511046986156781857U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3597219300593287708U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1429753448204448904U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10927459251773273143U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17229017825587322715U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 1137574712801062932U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3645832160939819415U), 37U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 2401991077004083378U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordD, 22U);
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1332473247826139292U;
            aOrbiterC = RotL64((aOrbiterC * 15029831858261506447U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11730946340796899885U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15319163439700390962U) ^ RotL64(aNonceWordF, 37U);
            aOrbiterI = RotL64((aOrbiterI * 1349242001887975499U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 19U)) + aOrbiterI) + RotL64(aCarry, 23U)) + RotL64(aNonceWordB, 57U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + aPhaseBWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterE, 52U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordA, 9U)) + aPhaseBWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterI, 29U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterB, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 48U) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20252U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20513U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordC, 5U)) ^ RotL64(aNonceWordA, 42U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18116U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17321U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 29U)) + (RotL64(aCarry, 54U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (((aWandererA + RotL64(aCross, 52U)) + RotL64(aCarry, 19U)) + 2617613537256538553U) + aPhaseBOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aIngress, 39U)) + 16642868916835132715U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordH, 47U);
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 10860291124337073254U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 6432511273906902472U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 13U)) + 7505375005848241910U) + RotL64(aNonceWordB, 21U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 11086616004678821329U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordF, 57U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3298830587569881951U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4304047944073454489U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 9775143140064220979U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4147601326580823120U;
            aOrbiterK = RotL64((aOrbiterK * 13462244678782260871U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12245920269898100415U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8391940489176734499U;
            aOrbiterI = RotL64((aOrbiterI * 9119606167674098007U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17876893379544668477U) + RotL64(aNonceWordE, 58U);
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 18301882058180370541U;
            aOrbiterC = RotL64((aOrbiterC * 16680384667098921309U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6869225862715140102U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 15404118372589259800U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5766851935950389915U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 56U)) + aOrbiterF) + RotL64(aNonceWordD, 29U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterI, 21U)) + RotL64(aNonceWordC, 15U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 6U) + RotL64(aOrbiterK, 5U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 37U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordD, 14U)) ^ RotL64(aNonceWordG, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23978U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 23327U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordE, 10U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26136U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 24436U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 14U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 13U)) + 17470880031634374199U) + aPhaseBOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 757565846006937746U;
            aOrbiterA = ((((aWandererC + RotL64(aIngress, 56U)) + RotL64(aCarry, 53U)) + 9419282475801345674U) + aPhaseBOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1]) + RotL64(aNonceWordE, 55U);
            aOrbiterI = (aWandererK + RotL64(aScatter, 41U)) + 2014248014107898196U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 15113928519446490441U) + RotL64(aNonceWordC, 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7346126964886259935U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5594123113093162359U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18043634828891483403U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5659237263369402005U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11565709683423969703U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16731289017588574671U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16782863743534856287U) + RotL64(aNonceWordF, 25U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13499100900072115907U;
            aOrbiterH = RotL64((aOrbiterH * 5567729598873214433U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11414447651044205242U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7545993795121430538U) ^ RotL64(aNonceWordH, 31U);
            aOrbiterB = RotL64((aOrbiterB * 10758488381206257261U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11778229237616454988U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2544793391976514665U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4021060413798523299U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterA, 19U)) + aPhaseBWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 3U)) + aOrbiterK) + RotL64(aCarry, 5U)) + RotL64(aNonceWordB, 43U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterB, 44U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterB, 53U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterA, 35U)) + RotL64(aNonceWordD, 54U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordE, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28100U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 27716U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordD, 27U)) ^ RotL64(aNonceWordF, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28531U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29368U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 22U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererB + RotL64(aIngress, 13U)) + 9023059520606551446U) + RotL64(aNonceWordC, 39U);
            aOrbiterB = (((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 662441755115638133U) + aPhaseBOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 16957253361196144712U) + RotL64(aNonceWordH, 34U);
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 57U)) + 7840955025765308605U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 21U)) + 346855809270395799U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 16099139781586668343U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordG, 47U);
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 3706457327118322098U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) ^ RotL64(aNonceWordB, 51U);
            aOrbiterG = RotL64((aOrbiterG * 7810030620470889591U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12166825885547622870U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7792658665720344200U;
            aOrbiterB = RotL64((aOrbiterB * 16305542632794270697U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7128477606152986326U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11116533962780290084U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11993485572912492297U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10443889548568288532U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4402387036946561017U;
            aOrbiterI = RotL64((aOrbiterI * 9032964741841833277U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13002706161178447654U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 13929727277530310708U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7005639090871200285U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 28U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterI, 43U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 36U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterI, 54U));
            aWandererG = aWandererG + ((((RotL64(aCross, 11U) + RotL64(aOrbiterE, 35U)) + aOrbiterB) + RotL64(aCarry, 35U)) + RotL64(aNonceWordA, 45U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterB, 27U)) + RotL64(aNonceWordD, 55U)) + aPhaseBWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Rugby_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x94FFD3C83DB00FE7ULL + 0xDD1105678CB20A81ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA23489A4D7F479B5ULL + 0xB58941D2231065D0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDB055A29F33706E5ULL + 0xBA508E293339AE18ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD08988F37C6281B1ULL + 0xDA1E9BA635E69A0FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBF44ED9A6BC1C9F9ULL + 0xE62CC2830519AF8BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA5C9610E668DC737ULL + 0xFFB1EC2FF7415E0EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCC81A1474C88CBA1ULL + 0xF6527B30AEFEEB63ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF54633D0C015251FULL + 0xFFB85F50FAB02A9EULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordF, 27U)) ^ RotL64(aNonceWordC, 46U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7495U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 3346U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 56U) ^ RotL64(aNonceWordA, 5U)) ^ RotL64(aNonceWordB, 39U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2405U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 5046U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 40U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 7075016829833562104U;
            aOrbiterG = (aWandererC + RotL64(aCross, 35U)) + 8783765886115517036U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 42U)) + RotL64(aCarry, 11U)) + 2996723892384565829U) + RotL64(aNonceWordA, 13U);
            aOrbiterH = (aWandererA + RotL64(aIngress, 5U)) + 9494134707342189476U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 5052642981395679904U) + aPhaseCOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 47U)) + 8766787055127962238U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 11U)) + 4467211954388738079U) + RotL64(aNonceWordG, 15U);
            aOrbiterD = (aWandererB + RotL64(aScatter, 53U)) + 8030255604633658608U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 20U)) + 16962408063455702251U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3768222186567699076U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 14930990410207899871U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10930005786146268241U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14179761938395502502U) + RotL64(aNonceWordD, 27U);
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1879084742719898108U;
            aOrbiterK = RotL64((aOrbiterK * 16783034788172670121U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5535012408925981515U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12792553516710295939U;
            aOrbiterD = RotL64((aOrbiterD * 8577530993755159329U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 8979253163346099252U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordB, 50U);
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5559189896063990740U;
            aOrbiterC = RotL64((aOrbiterC * 8832485423727331621U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13937564337299044079U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2393376759689394948U;
            aOrbiterJ = RotL64((aOrbiterJ * 2352815657830413941U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 12647519563697356479U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10946871249960389549U;
            aOrbiterH = RotL64((aOrbiterH * 6272580371881237173U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13376798695582123147U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10958115913599631271U;
            aOrbiterA = RotL64((aOrbiterA * 18233981473003345217U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4283914227806672773U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 910842005516235816U;
            aOrbiterG = RotL64((aOrbiterG * 6722229871617873429U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1509644316619370324U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 165987596716078174U;
            aOrbiterF = RotL64((aOrbiterF * 13600064054240185123U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 50U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterC, 10U)) + RotL64(aNonceWordE, 51U));
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterK, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 48U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 19U));
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 14U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterA, 5U)) + RotL64(aNonceWordC, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 10U) + aOrbiterH) + RotL64(aOrbiterF, 57U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordG, 29U)) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14099U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 12123U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 47U) ^ RotL64(aNonceWordB, 4U)) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13919U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11679U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 27U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = (((aWandererA + RotL64(aCross, 60U)) + 12029393034357490020U) + aPhaseCOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordC, 27U);
            aOrbiterA = (aWandererF + RotL64(aScatter, 29U)) + 4526754731580694987U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 19U)) + 17060419646421271853U) + aPhaseCOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 4128488893837059683U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 23U)) + 12706894827547160110U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 12506324593645825056U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 10U)) + 12581344490649250025U) + RotL64(aNonceWordB, 9U);
            aOrbiterK = (aWandererG + RotL64(aPrevious, 39U)) + 14357032418199130132U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 15341977701796331249U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7086602307544733241U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12398300065276832486U;
            aOrbiterE = RotL64((aOrbiterE * 18157408831225635333U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2499745046076601988U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7249361592814001829U;
            aOrbiterJ = RotL64((aOrbiterJ * 14597139848072319685U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3254456186337366437U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3472973415969046680U;
            aOrbiterB = RotL64((aOrbiterB * 14583566953969168353U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7905718972111691591U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15941413652144021522U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3473779492962783565U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10583964125960308762U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13659925272340853715U;
            aOrbiterC = RotL64((aOrbiterC * 16708294803316630743U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9487054537489454887U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13287757570441887517U;
            aOrbiterF = RotL64((aOrbiterF * 17351439045329892107U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15279245465808571942U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 12424999114621745879U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2274918760256527137U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13915392738892970475U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13797668053788805126U) ^ RotL64(aNonceWordG, 30U);
            aOrbiterD = RotL64((aOrbiterD * 13752161103680525317U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14344766585550401077U) + RotL64(aNonceWordE, 41U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 13727554194373146727U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17164450431362670223U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 28U);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 12U) + aOrbiterC) + RotL64(aOrbiterH, 41U)) + RotL64(aNonceWordD, 39U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 54U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterK, 37U)) + RotL64(aNonceWordF, 23U));
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 29U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 58U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterF, 21U)) + aPhaseCWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordG, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24083U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 18679U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordC, 19U)) ^ RotL64(aNonceWordD, 4U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20780U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 16498U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 30U) ^ RotL64(aIngress, 43U)) + (RotL64(aPrevious, 57U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aCross, 53U)) + 2177539223979303669U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 28U)) + 3962004686551521471U) + RotL64(aNonceWordD, 35U);
            aOrbiterI = (aWandererC + RotL64(aPrevious, 3U)) + 8457602312617147662U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 47U)) + 18011802451816510632U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 9046101759168876832U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 18U)) + RotL64(aCarry, 11U)) + 11135620637431969597U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 57U)) + 15913029940697999701U) + aPhaseCOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aScatter, 23U)) + 16304193109948135982U;
            aOrbiterJ = ((((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 13208892298820080981U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordG, 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4182377898949419225U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13970137023071326151U) ^ RotL64(aNonceWordA, 37U);
            aOrbiterI = RotL64((aOrbiterI * 9075061559681739865U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 8402396284835248583U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8859190834060657829U;
            aOrbiterD = RotL64((aOrbiterD * 13552418608113716117U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9760005337757990392U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14108277760135744897U;
            aOrbiterH = RotL64((aOrbiterH * 4474681104256093885U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 12226316121949012350U) + RotL64(aNonceWordB, 56U);
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3456392186754113960U;
            aOrbiterB = RotL64((aOrbiterB * 8704729827929941215U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5004087958637038973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7176881295123125567U;
            aOrbiterC = RotL64((aOrbiterC * 15272157962928021009U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10889800478505074438U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13728832441482547824U;
            aOrbiterF = RotL64((aOrbiterF * 17588477761978646139U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 17345665880706866772U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 301139993853297566U;
            aOrbiterA = RotL64((aOrbiterA * 5812445396758354505U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2061389844760610160U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13631862266139238355U;
            aOrbiterG = RotL64((aOrbiterG * 143613352104722701U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10767186080827509622U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4893486019456886013U;
            aOrbiterJ = RotL64((aOrbiterJ * 5194746459545610901U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 60U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 24U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 28U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + aPhaseCWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 11U)) + aOrbiterD) + RotL64(aNonceWordE, 17U));
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + RotL64(aNonceWordH, 31U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 53U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 60U) + RotL64(aOrbiterA, 46U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordE, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25810U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32140U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 20U) ^ RotL64(aNonceWordB, 53U)) ^ RotL64(aNonceWordA, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25841U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31960U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 20U) + RotL64(aIngress, 35U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 13053031069776604052U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 19U)) + 1331396630251085122U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 42U)) + 15879286043343942393U) + RotL64(aNonceWordG, 61U);
            aOrbiterH = ((aWandererK + RotL64(aIngress, 23U)) + 13590365633321406830U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 13U)) + 14569235423040242618U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 27U)) + 11397370636618371560U) + aPhaseCOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aScatter, 46U)) + RotL64(aCarry, 57U)) + 3455933494593971847U) + RotL64(aNonceWordH, 47U);
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 53U)) + 1307153376443784593U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 10688618762584786871U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17746248451153600096U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8512568600755410158U;
            aOrbiterI = RotL64((aOrbiterI * 16648320170768234063U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8950230550112591092U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17790968369472845496U;
            aOrbiterB = RotL64((aOrbiterB * 5104988920132008913U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12583323865381967534U) + RotL64(aNonceWordD, 24U);
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11243927099685293887U;
            aOrbiterA = RotL64((aOrbiterA * 12867003042486433971U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9690268715525781389U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7466066217365074653U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17565696765505320889U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3673528673209875118U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14079103852360952255U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17449228863409999629U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6747836856132250630U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 5027692924422297153U) ^ RotL64(aNonceWordE, 5U);
            aOrbiterK = RotL64((aOrbiterK * 2492421273167124437U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11370341866003395776U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14013204893442579282U;
            aOrbiterE = RotL64((aOrbiterE * 6602239957997240785U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3436953430697936790U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6399073534839993637U;
            aOrbiterF = RotL64((aOrbiterF * 14186050072610021241U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7054057507823631422U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5752085719673338095U;
            aOrbiterC = RotL64((aOrbiterC * 13252660162476029593U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 34U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterH, 19U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 60U)) + aOrbiterE) + aPhaseCWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterC, 35U)) + RotL64(aNonceWordC, 9U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ) + RotL64(aNonceWordF, 51U));
            aWandererD = aWandererD + ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterC, 5U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 42U) + aOrbiterJ) + RotL64(aOrbiterE, 41U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterB, 54U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Rugby_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x944D68EE1E4E3953ULL + 0xA7D18B8EF074F306ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD8030BD54102E29BULL + 0xEFE3EFABA7CADBB5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x94CC57D9CF96D48BULL + 0xE8AFE05EE0AD242CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9A703D74A976699FULL + 0xDDA068EC4F902B11ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFE58E69D1ED29F39ULL + 0xED6C5194640410BBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA4B6EA665E25C62DULL + 0xA4DEC0CD2CBAB11EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x80417A95FBF5B371ULL + 0x98D6D4D8095CEF52ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA9717C1FC7687699ULL + 0xF4009671C8EDE648ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4620U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2350U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordD, 14U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1554U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1149U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aCross, 21U)) + 15920462086654025436U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 487844076858004017U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 52U)) + 14502883786442630566U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 23U)) + 3787107318658233674U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 12548777544693755491U) + aPhaseDOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 57U)) + 4907309444075181683U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 39U)) + 18342396700266492072U;
            aOrbiterD = (aWandererK + RotL64(aCross, 27U)) + 13503051997624242670U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 10U)) + 17845742460521374571U) + RotL64(aNonceWordB, 53U);
            aOrbiterI = (aWandererH + RotL64(aCross, 29U)) + 8640887211877858169U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 5273913123709097537U) + RotL64(aNonceWordC, 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17756844173695563883U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6713055830729302951U;
            aOrbiterC = RotL64((aOrbiterC * 2832836748513174311U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5106468334224035972U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10228769728713526172U;
            aOrbiterJ = RotL64((aOrbiterJ * 9760310686414358435U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7687649520668883142U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7757480627354711605U) ^ RotL64(aNonceWordH, 30U);
            aOrbiterF = RotL64((aOrbiterF * 7222553727737349209U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 10876291698508634557U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8149278085586014186U;
            aOrbiterA = RotL64((aOrbiterA * 8577133863470695381U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15592893988925610485U) + RotL64(aNonceWordA, 5U);
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8639028256640537165U;
            aOrbiterG = RotL64((aOrbiterG * 1880655276432963955U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 475660347892196219U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1903736092401853832U;
            aOrbiterE = RotL64((aOrbiterE * 8486318978769094799U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12463250192809450953U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7253918448601703982U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3821034106528009129U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5171661020093804486U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11627344933828324146U;
            aOrbiterK = RotL64((aOrbiterK * 5388047063152043277U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6206801139131132815U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9221302203943031377U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12912049016813367241U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1798857939965423979U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5476854168685641232U;
            aOrbiterD = RotL64((aOrbiterD * 3884216989250294213U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2816659151953455230U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15920462086654025436U;
            aOrbiterI = RotL64((aOrbiterI * 17843161654734820613U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 26U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterB, 27U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterC) + RotL64(aNonceWordG, 41U)) + aPhaseDWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterF, 38U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + RotL64(aNonceWordE, 23U));
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterI, 35U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterA, 58U));
            aWandererK = aWandererK + (((RotL64(aScatter, 30U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 21U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordH, 58U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10537U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 9108U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordE, 38U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8947U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9155U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 50U) + RotL64(aIngress, 37U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererI + RotL64(aIngress, 13U)) + 18144572925667544139U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 5659758077574059728U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 6343330616999166392U;
            aOrbiterK = (aWandererC + RotL64(aCross, 19U)) + 17754639838410839447U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 58U)) + 9451843819849581729U) + aPhaseDOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 7957854457197462212U) + RotL64(aNonceWordF, 17U);
            aOrbiterA = (aWandererJ + RotL64(aScatter, 3U)) + 1461994799722205010U;
            aOrbiterD = (aWandererA + RotL64(aCross, 47U)) + 18002214276252170177U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 60U)) + 14689869073147027164U) + aPhaseDOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 37U)) + 3978104368003440293U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 41U)) + 8512135845221335386U) + RotL64(aNonceWordB, 56U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1477533446382953439U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2166717790929947990U;
            aOrbiterG = RotL64((aOrbiterG * 6538884492418324461U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8082437060686606995U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4363687722464700362U;
            aOrbiterI = RotL64((aOrbiterI * 7199165810993478887U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15782763348014924206U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8572509150015960728U;
            aOrbiterJ = RotL64((aOrbiterJ * 3340528604891897779U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12248271773316742521U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9602078627638561949U;
            aOrbiterA = RotL64((aOrbiterA * 1860631869877427405U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17244849374768558859U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1030743048280579012U;
            aOrbiterE = RotL64((aOrbiterE * 10858949914285817051U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17722342363541914280U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15667504059789880034U;
            aOrbiterH = RotL64((aOrbiterH * 15872269872168533709U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 12645332941998550794U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordC, 15U);
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9938135244509986497U;
            aOrbiterK = RotL64((aOrbiterK * 16548185968987392957U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4024609904162105979U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6732064218696157303U;
            aOrbiterF = RotL64((aOrbiterF * 3815409766145891393U), 35U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 14314117137220703583U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordG, 47U);
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15244765904057473814U;
            aOrbiterD = RotL64((aOrbiterD * 4034571710808047959U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17441241682018169245U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11958974379114644873U;
            aOrbiterB = RotL64((aOrbiterB * 11315689206845170303U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 8310839846793796473U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18144572925667544139U;
            aOrbiterC = RotL64((aOrbiterC * 11668203295511168011U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 36U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + aPhaseDWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 11U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterJ, 27U)) + RotL64(aNonceWordA, 3U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 23U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 30U) + aOrbiterK) + RotL64(aOrbiterI, 53U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 36U)) + aOrbiterC) + RotL64(aCarry, 53U)) + RotL64(aNonceWordD, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterH, 13U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterB, 51U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterI, 18U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 41U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererF, 30U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordH, 60U)) ^ RotL64(aNonceWordD, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11149U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 14811U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordA, 51U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11170U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 16132U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCross, 13U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererD + RotL64(aScatter, 21U)) + 3550722402315312207U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 16724184551669522754U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 35U)) + 981751330116773021U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aPrevious, 24U)) + 7891159229704944868U;
            aOrbiterC = (aWandererA + RotL64(aCross, 51U)) + 13618396711464799841U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 39U)) + 5969291018449003648U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 41U)) + 14595540413313640042U) + RotL64(aNonceWordC, 9U);
            aOrbiterB = (aWandererK + RotL64(aScatter, 43U)) + 3287990436916111762U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 53U)) + 12534369400200483704U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 2277312067930392274U;
            aOrbiterJ = ((((aWandererF + RotL64(aScatter, 12U)) + RotL64(aCarry, 27U)) + 10026320559261334353U) + aPhaseDOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordF, 25U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11258082063135659551U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1445958517675746990U;
            aOrbiterK = RotL64((aOrbiterK * 10062265337488757971U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1011298251290970844U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6487834862470043744U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15477913837027179675U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9966279022928268335U) + RotL64(aNonceWordD, 49U);
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10285993486057704393U;
            aOrbiterI = RotL64((aOrbiterI * 15965714363201157535U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16005362468813966136U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 223843444699390781U;
            aOrbiterC = RotL64((aOrbiterC * 665392038954573081U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 18178876294968532775U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12490136112181806806U;
            aOrbiterB = RotL64((aOrbiterB * 16380841616662993709U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8775696166557913635U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16464340319444310842U;
            aOrbiterF = RotL64((aOrbiterF * 18111632334728200721U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6296039992673546227U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7152939277656436037U;
            aOrbiterG = RotL64((aOrbiterG * 15183918431501487319U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14066791413416223271U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5026743227399908016U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5891343232759075675U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12923870516588764609U) + RotL64(aNonceWordG, 17U);
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2509970166609982397U;
            aOrbiterE = RotL64((aOrbiterE * 10708677957633925007U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15155802288437422950U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15615656627428205711U;
            aOrbiterA = RotL64((aOrbiterA * 6199439196177598589U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17233751123865498186U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3550722402315312207U;
            aOrbiterJ = RotL64((aOrbiterJ * 2247546626523919155U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 30U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 27U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aCross, 4U) + aOrbiterE) + RotL64(aOrbiterB, 24U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 13U)) + aOrbiterA) + RotL64(aNonceWordB, 37U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 21U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + RotL64(aNonceWordA, 28U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 50U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 37U));
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterI, 35U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterK, 39U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordF, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 20686U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21476U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 21U) ^ RotL64(aNonceWordG, 6U)) ^ RotL64(aNonceWordB, 41U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18071U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18938U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 40U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aScatter, 53U)) + 9751314027302668907U;
            aOrbiterB = (aWandererF + RotL64(aCross, 21U)) + 12175450995523107056U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 17519694958730119552U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 9093525527925682263U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 13U)) + 3713831321786810138U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 60U)) + 10108355209191835040U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 47U)) + 12956307447311314768U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordE, 21U);
            aOrbiterK = ((aWandererB + RotL64(aCross, 11U)) + 1904298513945877359U) + RotL64(aNonceWordD, 17U);
            aOrbiterA = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 4658049993308574460U) + aPhaseDOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 57U)) + 9826333658248851902U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 18U)) + 12058666914724365134U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2516574707110528099U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13335308331049750235U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5880227828760598587U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8230749255538495304U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16536559486797811486U;
            aOrbiterI = RotL64((aOrbiterI * 7097036838156464969U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12387639130570188998U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8459259798142872020U;
            aOrbiterF = RotL64((aOrbiterF * 8001346480955847013U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16083784052002800300U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1957284290736468379U;
            aOrbiterE = RotL64((aOrbiterE * 5046501301740813065U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7349538179311335863U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16395170077006105258U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4230485452156662763U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3317652065873784068U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5517155804799120700U) ^ RotL64(aNonceWordG, 48U);
            aOrbiterA = RotL64((aOrbiterA * 9789270651974719183U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5568525912112200094U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9334250662962319598U) ^ RotL64(aNonceWordC, 9U);
            aOrbiterG = RotL64((aOrbiterG * 5034887614541768961U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5641394627075994165U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13524971148931512745U;
            aOrbiterD = RotL64((aOrbiterD * 3699457147759854357U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15124425790244392471U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7896294947517723306U;
            aOrbiterC = RotL64((aOrbiterC * 7526632360108129915U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15241686066829586263U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 12099799118961857495U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10456171163074630861U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17529688916595727188U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9751314027302668907U;
            aOrbiterJ = RotL64((aOrbiterJ * 521888849578281715U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 42U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterK, 41U)) + RotL64(aNonceWordA, 35U)) + aPhaseDWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterH, 29U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 3U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterB, 27U));
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 39U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 47U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 60U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 53U)) + aOrbiterB) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + RotL64(aNonceWordH, 5U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterE, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordD, 42U)) ^ RotL64(aNonceWordE, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23352U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 26966U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordG, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25463U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneA[((aIndex + 22272U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 56U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 23U)) + 10038936806177516123U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 1773168435195292638U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 30U)) + 10655711161526628072U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 14422295664639740437U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 39U)) + 4125228715513159576U) + RotL64(aNonceWordA, 55U);
            aOrbiterG = (aWandererC + RotL64(aIngress, 11U)) + 3670449653158650845U;
            aOrbiterB = (aWandererG + RotL64(aCross, 3U)) + 17553727567180813057U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 5111401772713882743U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 53U)) + 7688573124662314413U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aScatter, 18U)) + 9438375825507814395U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 5U)) + 14177477039902118886U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + RotL64(aNonceWordE, 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 16329942595859623928U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3990536794006836672U;
            aOrbiterC = RotL64((aOrbiterC * 579024714339065373U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5072881436583180756U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16789727877867289997U;
            aOrbiterG = RotL64((aOrbiterG * 8766246302636197905U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17313956922306689438U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11530878396329822041U;
            aOrbiterD = RotL64((aOrbiterD * 11356860047841383129U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3612616532321160196U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4172189825359187763U;
            aOrbiterE = RotL64((aOrbiterE * 12938945495299393177U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8677279703778052804U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 1912172980909479362U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10053289257955474143U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1460085850227494500U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12116763868122868147U;
            aOrbiterJ = RotL64((aOrbiterJ * 6076945628020280957U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17571840610366424432U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15581362592611080868U;
            aOrbiterB = RotL64((aOrbiterB * 1129054058044872003U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14434700039977611666U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4534294602623329152U;
            aOrbiterH = RotL64((aOrbiterH * 5860911553425182045U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 865998255725903702U) + RotL64(aNonceWordB, 57U);
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16407778704555344108U;
            aOrbiterA = RotL64((aOrbiterA * 15571344643129797977U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1948990288894429805U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 18218556219056835250U) ^ RotL64(aNonceWordC, 18U);
            aOrbiterK = RotL64((aOrbiterK * 16574160087642377293U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1309229265173143398U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10038936806177516123U;
            aOrbiterF = RotL64((aOrbiterF * 12954594462760207923U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 30U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterA, 53U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 10U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 19U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterI, 37U)) + aOrbiterC) + RotL64(aNonceWordH, 17U));
            aWandererB = aWandererB + ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 29U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 5U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterH, 24U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 48U) + aOrbiterC) + RotL64(aOrbiterG, 57U)) + RotL64(aNonceWordF, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordG, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31218U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30828U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordE, 21U)) ^ RotL64(aNonceWordB, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31226U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30603U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 17912271996338180948U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 54U)) + 13259276608841847058U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 37U)) + 16225936008657276089U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 11U)) + 2243058962151834071U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 13U)) + 10637439274127347861U) + RotL64(aNonceWordD, 17U);
            aOrbiterC = (aWandererF + RotL64(aPrevious, 56U)) + 15312219216405992627U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 41U)) + 2393933972129878613U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 21U)) + 4327069337247976513U) + aPhaseDOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 5U)) + 8307656353434167837U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 17299145556933889336U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 14458100581172798164U) + RotL64(aNonceWordE, 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6410095654927998067U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6168964796264687686U;
            aOrbiterB = RotL64((aOrbiterB * 16218071040190475953U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3667999465041020730U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16021552859323602007U;
            aOrbiterA = RotL64((aOrbiterA * 6427266472526362663U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12941668202330045095U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4222032891850449934U;
            aOrbiterC = RotL64((aOrbiterC * 17292856787431308097U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1346342592002730785U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 16860611785008118820U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) ^ RotL64(aNonceWordF, 35U);
            aOrbiterK = RotL64((aOrbiterK * 384963420804756607U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3193572711804730241U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 5866881282680588589U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9226331800853634597U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17180332731328479126U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 10222097519535882241U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9422887302872778795U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8863502179821584859U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14872318155712512999U;
            aOrbiterH = RotL64((aOrbiterH * 11830641277356873233U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16478790641892781150U) + RotL64(aNonceWordB, 13U);
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8414944141232294781U;
            aOrbiterE = RotL64((aOrbiterE * 17443775794621154023U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13204056527590476037U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15084952142545813228U;
            aOrbiterF = RotL64((aOrbiterF * 17183888602469193015U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13051035678904490854U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17565188004293304987U;
            aOrbiterJ = RotL64((aOrbiterJ * 12785271107667631897U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 814245676602237400U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17912271996338180948U;
            aOrbiterI = RotL64((aOrbiterI * 14557769257469623169U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 34U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 47U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 40U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + RotL64(aNonceWordC, 44U));
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 40U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 5U)) + aPhaseDWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 51U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 23U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aIngress, 44U) + RotL64(aOrbiterA, 29U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 20U)) + aOrbiterE) + RotL64(aNonceWordA, 45U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 27U)) + aOrbiterG) + aPhaseDWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 42U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Rugby_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBAD3F280B4D95A93ULL + 0xE7895731DF188D5DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xED90E3E21D79ADADULL + 0x934B1636908F8E2AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD5F140945CD41E05ULL + 0xC5CF2308CCB10FE7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE6006330E88732A3ULL + 0x9D1153C9ADFD0347ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9BDF09436FE6CF03ULL + 0xBE83636FE72673C0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD3731F443A06AA01ULL + 0xAC23EDB42593528DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9072B6C119EB7AD1ULL + 0xA5F118A55095DD56ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE8E00D8632FDCAEFULL + 0xF72EFFADCB634160ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordB, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5461U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 664U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordF, 43U)) ^ RotL64(aNonceWordG, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1993U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 4567U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 4U) + RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererE + RotL64(aIngress, 26U)) + RotL64(aCarry, 43U)) + 13915875634607599122U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 3U)) + 1695770381382411673U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 51U)) + 3709105579778295511U;
            aOrbiterH = (aWandererB + RotL64(aCross, 43U)) + 7673376335333251804U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 8814147709738503518U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 19U)) + 13451412605350381172U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 6447870234069609538U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 48U)) + 13419487997946496825U) + RotL64(aNonceWordB, 45U);
            aOrbiterI = (aWandererG + RotL64(aCross, 29U)) + 5478309847615220345U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 57U)) + 3635184969215610049U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordE, 41U);
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 53U)) + 12527903812035294828U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1684685110885338814U) + RotL64(aNonceWordH, 27U);
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12860354576326835090U;
            aOrbiterC = RotL64((aOrbiterC * 12743745087733307255U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9081823570147481835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14369321778210049109U;
            aOrbiterD = RotL64((aOrbiterD * 17865953349448767035U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 11518132079084873250U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11893535026126957389U;
            aOrbiterG = RotL64((aOrbiterG * 15751374986135615095U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7084079180579206226U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2999676609847603277U;
            aOrbiterH = RotL64((aOrbiterH * 14602698397511266403U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17683445810614029153U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11576460512964896969U) ^ RotL64(aNonceWordG, 38U);
            aOrbiterJ = RotL64((aOrbiterJ * 5243651036457051155U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13429800604736567949U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14661785761747367546U;
            aOrbiterI = RotL64((aOrbiterI * 4765843989277333421U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12837164345582888950U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6222666313184669392U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17402483466567712319U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5358647039491079457U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12459911673401497180U;
            aOrbiterB = RotL64((aOrbiterB * 13605465035256188065U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3333017644772803587U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15501587702102554928U;
            aOrbiterA = RotL64((aOrbiterA * 4921693371641768339U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8492287653837766613U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3432736785678875404U;
            aOrbiterF = RotL64((aOrbiterF * 7326419883291516513U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2841486107704281869U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13915875634607599122U;
            aOrbiterE = RotL64((aOrbiterE * 707861617246345083U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 26U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 11U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aCross, 40U) + RotL64(aOrbiterA, 24U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + RotL64(aNonceWordF, 49U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI) + RotL64(aCarry, 35U)) + RotL64(aNonceWordA, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 47U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterF, 22U)) + aPhaseEWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 51U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aPrevious, 52U) + RotL64(aOrbiterG, 39U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterH, 41U));
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordH, 48U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 5683U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 6122U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordC, 51U)) ^ RotL64(aNonceWordE, 24U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6540U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9999U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 24U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 3248574644570178787U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 19U)) + 4506961512959200024U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 37U)) + 8423739774540738590U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 39U)) + 6593975869641735337U) + RotL64(aNonceWordD, 39U);
            aOrbiterK = (aWandererC + RotL64(aIngress, 56U)) + 16441716090557369103U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 3U)) + 7936601450453207914U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 47U)) + 13333752583560167065U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 35U)) + 8013703284795432973U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordF, 12U);
            aOrbiterG = (aWandererE + RotL64(aScatter, 13U)) + 2349852779887439236U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 10U)) + RotL64(aCarry, 41U)) + 5318539364763284138U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 11450957608502944376U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9058992558327552687U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 632095686920230926U;
            aOrbiterH = RotL64((aOrbiterH * 12460364388358520799U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14734218428913777098U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16344357661370784442U;
            aOrbiterA = RotL64((aOrbiterA * 15049472842002138369U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 2981145363531184308U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14176472085175714494U;
            aOrbiterK = RotL64((aOrbiterK * 2584623327412130939U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11198457590069700889U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 952584436750426828U) ^ RotL64(aNonceWordB, 11U);
            aOrbiterJ = RotL64((aOrbiterJ * 1165713888651280355U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4311591763498985972U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16194341833989936369U;
            aOrbiterG = RotL64((aOrbiterG * 9997934560195932575U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7560794022401107431U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10683789740265711603U;
            aOrbiterE = RotL64((aOrbiterE * 15637823045351977883U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11614366395125937178U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10750771385100564416U;
            aOrbiterC = RotL64((aOrbiterC * 4987921274272444283U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2934697034132204529U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4646873794658020363U;
            aOrbiterB = RotL64((aOrbiterB * 10555456865641580175U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7913681837683568905U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17603563535330106340U;
            aOrbiterF = RotL64((aOrbiterF * 17882943067522319671U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15375641415139193079U) + RotL64(aNonceWordH, 9U);
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17059712718085411887U;
            aOrbiterI = RotL64((aOrbiterI * 13722089235751208215U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14022558453716067200U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3248574644570178787U;
            aOrbiterD = RotL64((aOrbiterD * 15249135451439374621U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 42U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + aPhaseEWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordG, 55U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 21U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 34U)) + RotL64(aNonceWordA, 31U)) + aPhaseEWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 57U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aScatter, 44U) + aOrbiterC) + RotL64(aOrbiterI, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC + ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 13U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 50U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 37U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 39U) ^ RotL64(aNonceWordB, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11514U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 12370U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 37U) ^ RotL64(aNonceWordA, 26U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12035U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 11758U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 56U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = (aWandererJ + RotL64(aCross, 21U)) + 15726877954695761686U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 6U)) + RotL64(aCarry, 47U)) + 14187652171881943587U) + RotL64(aNonceWordC, 61U);
            aOrbiterJ = (aWandererD + RotL64(aIngress, 35U)) + 8420423151313882782U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 3U)) + 14942322692433259283U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 23U)) + 7272331475919796255U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 13U)) + 154504365041805840U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 17475491222554948786U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 5759181483165339605U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 57U)) + 5993060214499322845U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (((aWandererF + RotL64(aScatter, 46U)) + 10901786237875941844U) + aPhaseEOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordD, 59U);
            aOrbiterA = (aWandererI + RotL64(aIngress, 41U)) + 17135786595614068473U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5208202073886811165U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6821452921018900631U;
            aOrbiterJ = RotL64((aOrbiterJ * 13119330055184115669U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13348064837402206969U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8967943922403445136U;
            aOrbiterB = RotL64((aOrbiterB * 300168481725373093U), 37U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 8130283784171430891U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordF, 13U);
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6351113882502502876U;
            aOrbiterI = RotL64((aOrbiterI * 15960622823993072903U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6894708729226455769U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12065058511247133944U;
            aOrbiterD = RotL64((aOrbiterD * 5432601727436935831U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17138279326229372741U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12987698199066890628U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12665716655177320977U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13688833537574196675U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4211971980434000618U;
            aOrbiterK = RotL64((aOrbiterK * 1374411763361518851U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10376917117582537592U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4807742522197923516U;
            aOrbiterE = RotL64((aOrbiterE * 15257251453302090961U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18038296468177121243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6879666349379745258U;
            aOrbiterC = RotL64((aOrbiterC * 15819475269715810555U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5193656664432659624U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 680899397323387963U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) ^ RotL64(aNonceWordG, 35U);
            aOrbiterF = RotL64((aOrbiterF * 9857476056194621321U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1851929589073547860U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13093101559415170218U;
            aOrbiterG = RotL64((aOrbiterG * 13950928576652143737U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13695333301427028607U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15726877954695761686U;
            aOrbiterA = RotL64((aOrbiterA * 960063676226172027U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 46U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 30U) + aOrbiterA) + RotL64(aOrbiterD, 5U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 58U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 19U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + RotL64(aNonceWordH, 55U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 41U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterD, 43U));
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 36U)) + aOrbiterD) + RotL64(aNonceWordB, 56U)) + aPhaseEWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 51U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 12U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 56U) ^ RotL64(aNonceWordA, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16470U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19714U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 4U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordF, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16730U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18350U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 14U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 11998579547770778580U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 43U)) + 8409465187298704610U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordD, 44U);
            aOrbiterB = (aWandererJ + RotL64(aCross, 3U)) + 3470222286110333500U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 22U)) + 5704486785203069994U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 11U)) + 10334944660253279633U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 47U)) + 7626852700722567477U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 14631310754943209743U) + RotL64(aNonceWordE, 5U);
            aOrbiterI = (aWandererG + RotL64(aPrevious, 24U)) + 807160297237854120U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 37U)) + 5624154783624196107U) + aPhaseEOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 39U)) + 4971444394698940423U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 6340057638461027062U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9003019862787819481U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13632057463595873033U;
            aOrbiterB = RotL64((aOrbiterB * 12575202147280216765U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12766104026871797746U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4062118445824915939U;
            aOrbiterJ = RotL64((aOrbiterJ * 13130770039048080701U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5258212525426469978U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9956946981015983939U;
            aOrbiterF = RotL64((aOrbiterF * 8106382657040497669U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10837606223056473999U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13292864885504191134U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4445739587553669471U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 166087925900318658U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6786842221885441388U;
            aOrbiterI = RotL64((aOrbiterI * 4411147600413147773U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16888086378070246404U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5240855484445974002U;
            aOrbiterG = RotL64((aOrbiterG * 402652898573422271U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6874866669211571608U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 732890824978127460U;
            aOrbiterD = RotL64((aOrbiterD * 3776365957702257453U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5541380495707308058U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17947326584411475765U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10920952349981652899U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15060679340045767910U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1675974028461383576U;
            aOrbiterE = RotL64((aOrbiterE * 15127962310365242819U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 226889112033170368U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 4290719734244011388U) ^ RotL64(aNonceWordC, 11U);
            aOrbiterH = RotL64((aOrbiterH * 6453598182035414143U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7712233480730639084U) + RotL64(aNonceWordG, 45U);
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11998579547770778580U;
            aOrbiterK = RotL64((aOrbiterK * 11599893373156816375U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 48U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 30U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 27U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 10U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 51U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 41U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 53U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterB, 44U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + RotL64(aNonceWordA, 7U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + RotL64(aNonceWordH, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 26U) ^ RotL64(aNonceWordC, 13U)) ^ RotL64(aNonceWordH, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 27165U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25972U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 56U) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24682U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 26887U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 40U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aScatter, 5U)) + 5173905450211892891U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 26U)) + 3555542451908039957U) + RotL64(aNonceWordD, 47U);
            aOrbiterI = (aWandererJ + RotL64(aCross, 47U)) + 11559884700283861559U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 43U)) + 1352524329968738673U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 8914206450420616349U) + aPhaseEOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 2251523378498463946U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 9541575923299247038U) + RotL64(aNonceWordG, 31U);
            aOrbiterD = (aWandererG + RotL64(aPrevious, 19U)) + 1239854507907214595U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 29U)) + 17698101462598498934U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 3U)) + 12305566971683256060U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 24U)) + 13804545036303215569U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10239749097704329264U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4212214906286320308U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3661436621615751071U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12192418916967430783U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4475514289326450361U;
            aOrbiterA = RotL64((aOrbiterA * 17497164630368757887U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17376102613298827459U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 18129393209955439341U;
            aOrbiterD = RotL64((aOrbiterD * 6404089025014118979U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4014763724300253568U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17325007199676828814U;
            aOrbiterG = RotL64((aOrbiterG * 1420888274815627083U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15480474849292388685U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14357924730184375449U;
            aOrbiterJ = RotL64((aOrbiterJ * 16723492259068034209U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4335731868597970070U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8296023680394303015U;
            aOrbiterK = RotL64((aOrbiterK * 14027415401430120543U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2807312426993262800U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 15510369660839648501U) ^ RotL64(aNonceWordB, 55U);
            aOrbiterH = RotL64((aOrbiterH * 18207954408298333959U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12597844696606519907U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7231012798553551535U;
            aOrbiterB = RotL64((aOrbiterB * 2841306785994479299U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 849663631945232360U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4002310581470781194U) ^ RotL64(aNonceWordE, 15U);
            aOrbiterE = RotL64((aOrbiterE * 2148877014350721479U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16067735571435654555U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4607980694199923842U;
            aOrbiterC = RotL64((aOrbiterC * 10401780756830017477U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5346879191913449715U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5173905450211892891U;
            aOrbiterF = RotL64((aOrbiterF * 15360571827429301833U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 46U) + aOrbiterA) + RotL64(aOrbiterJ, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 10U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 13U)) + aOrbiterC) + RotL64(aNonceWordA, 46U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 51U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterE, 39U)) + RotL64(aNonceWordC, 27U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterH, 27U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 37U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 3U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterB, 54U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 19U)) + aOrbiterF) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 36U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordE, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29853U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((aIndex + 31815U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 44U) ^ RotL64(aNonceWordH, 21U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29752U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29401U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 23U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 77518479758428414U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 34U)) + 4832061802166300011U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 27U)) + 11695291171006574112U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 57U)) + 7467412817843260094U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 17801484124471154757U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 37U)) + 5555455638503958639U) + RotL64(aNonceWordD, 53U);
            aOrbiterB = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 5669470540733721606U) + RotL64(aNonceWordG, 55U);
            aOrbiterJ = (aWandererF + RotL64(aCross, 39U)) + 3042388456327784163U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 44U)) + 2236734925228156691U;
            aOrbiterF = (aWandererA + RotL64(aCross, 11U)) + 14459720401528685450U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 41U)) + 4814967631216658856U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16950679344449075945U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6262238639302011050U;
            aOrbiterA = RotL64((aOrbiterA * 9942659897425088183U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3522256359074996724U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12524717897707074242U;
            aOrbiterG = RotL64((aOrbiterG * 6787771338063891989U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13891759914865623828U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11910250571469028666U;
            aOrbiterD = RotL64((aOrbiterD * 12311343917878428995U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2240189915640314069U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5365912986308810837U;
            aOrbiterB = RotL64((aOrbiterB * 15133972552032469957U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9323732721344489753U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13087326560957916553U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14659491687401151733U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16398238057564892809U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11517870519285159224U;
            aOrbiterI = RotL64((aOrbiterI * 1501848878469712681U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 7758285512254776734U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17475149091906684720U;
            aOrbiterF = RotL64((aOrbiterF * 6015816725428299273U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2051631493975035243U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11684740065349595315U) ^ RotL64(aNonceWordB, 16U);
            aOrbiterH = RotL64((aOrbiterH * 10918975496337269197U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10575473798991451167U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8267005776169272822U) ^ RotL64(aNonceWordF, 37U);
            aOrbiterK = RotL64((aOrbiterK * 13166868678285963961U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6249698995716039231U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13808085811784323978U;
            aOrbiterC = RotL64((aOrbiterC * 3897731011582061983U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2739364646624876985U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 77518479758428414U;
            aOrbiterE = RotL64((aOrbiterE * 6977724811175035551U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 38U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 47U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 58U) + aOrbiterJ) + RotL64(aOrbiterE, 13U));
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterG, 27U)) + RotL64(aNonceWordA, 27U));
            aWandererG = aWandererG + ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 23U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 44U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 37U)) + aOrbiterC) + RotL64(aCarry, 35U)) + RotL64(aNonceWordE, 7U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 41U)) + aOrbiterK) + aPhaseEWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterC, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Rugby_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC3605FEE3FA6EDDDULL + 0x81252018610B3BDBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC72CACB08798EF7BULL + 0x9980303CF8F5C482ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xACE76B5FEA4FD41DULL + 0x9D6A7E9427A6A06FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD8886EE008B3E6C1ULL + 0xFA5D7AA9A080A4F5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x879B7904B9929D43ULL + 0x92F6B5590E4A7260ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEB531355F79028D7ULL + 0x886A8038FC3CD5C8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEE0919968212C223ULL + 0xD3906808532D0838ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA59FCA94889BA473ULL + 0x8F41FC67ECADF5D6ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 47U) ^ RotL64(aNonceWordF, 36U)) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 584U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 4150U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordA, 51U)) ^ RotL64(aNonceWordB, 60U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1010U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4636U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 28U)) ^ (RotL64(aCarry, 43U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aCross, 46U)) + RotL64(aCarry, 23U)) + 10915618884692072446U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 37U)) + 12634922308499254909U) + aPhaseFOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 21U)) + 6533934734564499389U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aScatter, 53U)) + 6744203303756105181U) + RotL64(aNonceWordD, 47U);
            aOrbiterF = (aWandererI + RotL64(aIngress, 35U)) + 13086782386652045658U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 23U)) + 5693840533331397822U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 1803663542535024611U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 56U)) + 3597219300593287708U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 41U)) + 1429753448204448904U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 39U)) + 17229017825587322715U) + RotL64(aNonceWordH, 13U);
            aOrbiterA = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 1137574712801062932U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2401991077004083378U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 1332473247826139292U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15029831858261506447U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 11730946340796899885U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15319163439700390962U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1349242001887975499U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4744141870145159917U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6067132201862688684U;
            aOrbiterD = RotL64((aOrbiterD * 6046100687757836027U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14991509179286371800U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 4342608825699398682U) ^ RotL64(aNonceWordE, 49U);
            aOrbiterH = RotL64((aOrbiterH * 10240526103933275875U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3727521409410742075U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3302027219498304367U;
            aOrbiterE = RotL64((aOrbiterE * 12153634588200479559U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6039539483340398858U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2902581519976937051U;
            aOrbiterJ = RotL64((aOrbiterJ * 2057584328877854239U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12332784713738947242U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13761272577223712786U;
            aOrbiterA = RotL64((aOrbiterA * 14930145045480030821U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 2947946397617043735U) + RotL64(aNonceWordF, 28U);
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11107014023853644521U;
            aOrbiterB = RotL64((aOrbiterB * 15030903626191481831U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6212403196992771516U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16107261731677426470U;
            aOrbiterF = RotL64((aOrbiterF * 13764822942405295129U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8414111492161335472U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3625937496991123221U;
            aOrbiterI = RotL64((aOrbiterI * 1736741235159600739U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5466667339391480293U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10915618884692072446U;
            aOrbiterG = RotL64((aOrbiterG * 14719282928172086707U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 42U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterG, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterI, 50U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 13U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + RotL64(aNonceWordA, 35U));
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 29U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 37U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterA, 60U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterK) + RotL64(aNonceWordG, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordG, 35U)) ^ RotL64(aNonceWordA, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8760U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneD[((aIndex + 7108U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7245U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((aIndex + 8650U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 18U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aCross, 60U)) + 18180797995100240808U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 41U)) + 6585906608223552885U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 13U)) + 14088708930575939855U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 11U)) + 468974153311516044U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 54U)) + RotL64(aCarry, 35U)) + 12481951025619894110U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 3U)) + 17227987923860711763U) + RotL64(aNonceWordB, 23U);
            aOrbiterH = (aWandererC + RotL64(aPrevious, 51U)) + 4373962756657477139U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 2077576476565420951U;
            aOrbiterI = (aWandererK + RotL64(aCross, 57U)) + 17435011300234663764U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 5U)) + 4118039398293246896U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordH, 35U);
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 13724716599855216683U) + aPhaseFOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12391461204689596339U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9900605191533799627U;
            aOrbiterD = RotL64((aOrbiterD * 13553565332531046301U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 972946858824366125U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17247681919694541215U;
            aOrbiterG = RotL64((aOrbiterG * 2974639094630445643U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15442851427306771601U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7303586227288294037U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15406402525021428799U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12650358753454105119U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1483710933373510492U;
            aOrbiterH = RotL64((aOrbiterH * 6531763256577221891U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 18065810162229740788U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11311677121338794007U;
            aOrbiterI = RotL64((aOrbiterI * 15116367961682119467U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2355285311890287611U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 1287783821903407734U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8054011680932255985U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9282654686791135654U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15488608017745542551U;
            aOrbiterE = RotL64((aOrbiterE * 7858866274035085123U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13296835576073421802U) + RotL64(aNonceWordE, 29U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7127700236018338741U) ^ RotL64(aNonceWordC, 31U);
            aOrbiterK = RotL64((aOrbiterK * 11246173563106014149U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1365928843264598789U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7777790578813003657U;
            aOrbiterB = RotL64((aOrbiterB * 10121688100505628161U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2104270617375082523U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13363764449819651164U;
            aOrbiterF = RotL64((aOrbiterF * 2685452132715528975U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 2008038686059197988U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 18180797995100240808U;
            aOrbiterA = RotL64((aOrbiterA * 8978998151475372047U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 54U);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 56U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 48U) + aOrbiterB) + RotL64(aOrbiterD, 27U)) + RotL64(aNonceWordF, 10U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterF, 39U)) + RotL64(aNonceWordD, 7U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 36U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 41U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterK, 3U));
            aWandererG = aWandererG + ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 23U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 51U));
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 20U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 46U) + aOrbiterC) + RotL64(aOrbiterJ, 43U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 13U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 11U) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15224U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 13613U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 27U) ^ RotL64(aNonceWordH, 5U)) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14173U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 15140U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 29U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aPrevious, 21U)) + 1210605127156905516U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 37U)) + 11964595428173569519U;
            aOrbiterA = (aWandererB + RotL64(aCross, 30U)) + 16277319029916258482U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 12369497463101824572U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 6201248574067068202U) + RotL64(aNonceWordF, 27U);
            aOrbiterF = ((aWandererJ + RotL64(aCross, 39U)) + 1727477025667206661U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aIngress, 47U)) + 1404510627789806851U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 23U)) + 6948213591282018925U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 43U)) + 6688865181284421478U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 12U)) + 3351130769402360855U) + RotL64(aNonceWordD, 5U);
            aOrbiterD = (((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 35U)) + 12681032488906270823U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3591412591193726763U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16153817571210878589U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4165137036092246349U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3808228354421006630U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1427373776207504205U;
            aOrbiterF = RotL64((aOrbiterF * 4534374093769595531U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1831554180932501132U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1114853085120949215U;
            aOrbiterJ = RotL64((aOrbiterJ * 4264176108298812905U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2080935638828366835U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16104777999646489828U;
            aOrbiterB = RotL64((aOrbiterB * 15205199362011777473U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9782806013673440791U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3721620299829386454U;
            aOrbiterH = RotL64((aOrbiterH * 6286765834910272409U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4013706412064296527U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5751022780695158579U;
            aOrbiterE = RotL64((aOrbiterE * 13766736471646116397U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17684546333240329338U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1106947111128020920U;
            aOrbiterI = RotL64((aOrbiterI * 3158839453318658951U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11564229705849500598U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1585817314460274286U;
            aOrbiterK = RotL64((aOrbiterK * 12687162159791577431U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13549147977354138518U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 5148731385622182707U) ^ RotL64(aNonceWordB, 49U);
            aOrbiterG = RotL64((aOrbiterG * 11016443961557395981U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17048442399822433365U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13772472534194030098U) ^ RotL64(aNonceWordC, 61U);
            aOrbiterC = RotL64((aOrbiterC * 13155895389652826889U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9982971300679888388U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1210605127156905516U;
            aOrbiterD = RotL64((aOrbiterD * 9183351854400012949U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 46U) + aOrbiterF) + RotL64(aOrbiterI, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterI, 52U));
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterI, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterD, 57U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterE, 39U));
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + RotL64(aOrbiterG, 48U)) + aOrbiterF) + RotL64(aNonceWordA, 8U)) + aPhaseFWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterF, 37U)) + RotL64(aNonceWordE, 31U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterA, 23U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 19U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 21U)) + aOrbiterH) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererI, 60U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 34U) ^ RotL64(aNonceWordD, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20418U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16660U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18393U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 17196U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 38U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 34U)) + 2672739400294801233U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 8475624545015101850U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 13U)) + 1252755112289831257U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 47U)) + 7938039507649183387U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 57U)) + 8167413146948861022U) + RotL64(aNonceWordH, 5U);
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 54U)) + RotL64(aCarry, 47U)) + 17712313989694374353U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 7637042279892596975U) + RotL64(aNonceWordB, 31U);
            aOrbiterH = (aWandererK + RotL64(aCross, 3U)) + 15770412950033467341U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 21U)) + 3951812021898608685U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 43U)) + 8656983621098246507U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 39U)) + 17943342344730687317U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3087677463651608668U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16493240011924342788U;
            aOrbiterG = RotL64((aOrbiterG * 16898479041530771871U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 7750923317452683057U) + RotL64(aNonceWordE, 22U);
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2185924841611106546U;
            aOrbiterD = RotL64((aOrbiterD * 708072658250726381U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14676868738946722416U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6849098251696302393U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2599806275837778069U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17817755047153606419U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9900465270314068757U;
            aOrbiterK = RotL64((aOrbiterK * 9267925873983176685U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11380000891112113701U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15930503831156546113U;
            aOrbiterH = RotL64((aOrbiterH * 14450535035065393845U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5439183530402949780U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3731802052051181843U;
            aOrbiterF = RotL64((aOrbiterF * 7739775058947333169U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14432344583247783600U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16192098795467501636U;
            aOrbiterI = RotL64((aOrbiterI * 6285466374319549047U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1523272672673940290U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7462092373525113574U) ^ RotL64(aNonceWordC, 25U);
            aOrbiterC = RotL64((aOrbiterC * 15067751170235540679U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4612539457663050732U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7959404391235752875U;
            aOrbiterJ = RotL64((aOrbiterJ * 137834571274065007U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11853468935131763944U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3575434598998149168U;
            aOrbiterB = RotL64((aOrbiterB * 16971321675425065041U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6135993440654291404U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2672739400294801233U;
            aOrbiterE = RotL64((aOrbiterE * 12891757276825641567U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 52U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 47U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 57U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 24U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterI, 13U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 19U)) + aOrbiterB) + aPhaseFWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 53U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 22U)) + aOrbiterB) + RotL64(aNonceWordA, 21U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterH, 51U)) + aOrbiterC) + RotL64(aNonceWordF, 15U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordC, 56U)) ^ RotL64(aNonceWordG, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24419U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 21972U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordD, 43U)) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23140U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 24875U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aIngress, 39U)) + 6973892330986118220U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 20U)) + 9886813896272094864U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 10996306582517553173U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 57U)) + 8490648283899856223U) + RotL64(aNonceWordC, 57U);
            aOrbiterA = (aWandererB + RotL64(aScatter, 43U)) + 105141713530704655U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 37U)) + 3114337422810562588U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 980857684690886131U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 29U)) + 6562042345807072665U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 51U)) + 15665371138706353619U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 6U)) + 18113013571374375028U) + RotL64(aNonceWordD, 29U);
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 17405346422601997299U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5130876096426182506U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1813821672299154629U;
            aOrbiterC = RotL64((aOrbiterC * 15478100342425611875U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15793814882743306728U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 13925299440495476399U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12049601510660117401U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9924458846049579438U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7810034662781768090U;
            aOrbiterK = RotL64((aOrbiterK * 10310594595026622513U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12812586478656872854U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5709576448057435237U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9101555233909853025U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7839807649914541516U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4717944526755429647U;
            aOrbiterE = RotL64((aOrbiterE * 8515229146471335721U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3933911971504256022U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4814079680865379831U;
            aOrbiterH = RotL64((aOrbiterH * 15100740696230557391U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 18352577312212175569U) + RotL64(aNonceWordF, 6U);
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9670612998448920742U;
            aOrbiterI = RotL64((aOrbiterI * 5743579439303300553U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 72737302703035726U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10032869372369626210U;
            aOrbiterB = RotL64((aOrbiterB * 7449905669249993731U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2669999453643982386U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2016129534922291383U;
            aOrbiterJ = RotL64((aOrbiterJ * 11730911201750754301U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5108689262300895422U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3753457479225942895U;
            aOrbiterG = RotL64((aOrbiterG * 11503304711866175497U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 859776381005289485U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordG, 49U);
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6973892330986118220U;
            aOrbiterA = RotL64((aOrbiterA * 12337041087475258221U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 14U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 56U) + aOrbiterI) + RotL64(aOrbiterF, 24U)) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterA, 37U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 39U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterA, 57U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 51U)) + aOrbiterB) + RotL64(aNonceWordH, 25U));
            aWandererI = aWandererI + ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 22U)) + aOrbiterG) + RotL64(aNonceWordB, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterD, 35U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 37U) ^ RotL64(aNonceWordA, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29970U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 28021U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordG, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32651U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30091U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 37U)) + (RotL64(aCross, 52U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aPrevious, 35U)) + 479672811032092393U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 43U)) + 18061121631394564425U) + RotL64(aNonceWordE, 24U);
            aOrbiterF = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 14237400452740566065U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 6723123812257706134U) + aPhaseFOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 4247997188026499248U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 29U)) + 1939107415066134869U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 58U)) + 3912640123546395979U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 53U)) + 8295478436553964298U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 41U)) + 3218960600711526885U) + aPhaseFOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 23U)) + 5874096203353388890U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 48U)) + 10294536533673023358U) + RotL64(aNonceWordA, 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11268561953904130747U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16693201256788898423U;
            aOrbiterF = RotL64((aOrbiterF * 16291987237693567209U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7550969634681894654U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9501647424602245869U;
            aOrbiterI = RotL64((aOrbiterI * 11265865222096866605U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8881869255994319423U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16770136406906800016U;
            aOrbiterD = RotL64((aOrbiterD * 1782039587385512923U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16185384746435761363U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13841034186650721627U;
            aOrbiterG = RotL64((aOrbiterG * 12000155593277035447U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 15229062695864608309U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3576122704615303733U;
            aOrbiterH = RotL64((aOrbiterH * 2433987493885779279U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13898167174453181224U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12878032061609524049U;
            aOrbiterA = RotL64((aOrbiterA * 18104665741338251495U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12719156051299028649U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8640980843376950769U;
            aOrbiterE = RotL64((aOrbiterE * 10242616778390983333U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12133332160916004365U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8743563985229104484U;
            aOrbiterB = RotL64((aOrbiterB * 4575129690615054691U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7362223873479167793U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4230720394788635807U;
            aOrbiterC = RotL64((aOrbiterC * 3658720603716856293U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5095842824285329272U) + RotL64(aNonceWordF, 53U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7483469517256234638U) ^ RotL64(aNonceWordC, 15U);
            aOrbiterJ = RotL64((aOrbiterJ * 9782114499878763883U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17426017004856399653U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 479672811032092393U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14921028515589317919U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (RotL64(aOrbiterH, 38U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterC, 37U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 34U) + aOrbiterA) + RotL64(aOrbiterH, 21U));
            aWandererJ = aWandererJ + (((((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordB, 41U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterG, 50U));
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 39U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + RotL64(aNonceWordH, 11U));
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 53U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterJ, 43U));
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 26U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Rugby_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF3EC85438B1BEC77ULL + 0x8F1830A21F4F1AF4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC28DA31E4C352BB7ULL + 0x8104511DBCE3F2B4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB794BB9695FD43B7ULL + 0xB31E19189AF63350ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9BA3B75A8FC6798BULL + 0xC21FE07B8F6B16C5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBD7151508F834F61ULL + 0xE5EB16CB0D530329ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAF6C9E0CC0B48DC3ULL + 0xC6D18A8DC1824E93ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA1259F2490657E6BULL + 0xDB2A1F282725C9A6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB8AF5DFC86837D41ULL + 0x88EE38C667F969CAULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordE, 44U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4578U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 5107U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 4U) ^ RotL64(aNonceWordB, 27U)) ^ RotL64(aNonceWordG, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 727U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 1710U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aIngress, 57U)) + 3339283916456813609U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 60U)) + 11339086426180649584U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 13U)) + 16819191669329316585U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aScatter, 39U)) + 8361916937762630725U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 35U)) + 18031328374429899857U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 18261756894092897276U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 21U)) + 4250319792907645666U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 5U)) + 1492411503643460886U) + RotL64(aNonceWordB, 59U);
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 42U)) + RotL64(aCarry, 5U)) + 17369549067879344180U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 19U)) + 7301713524358676722U;
            aOrbiterA = ((((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 2985193736033012535U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordD, 61U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 14086975808140927408U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 46U);
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10390516547834639800U;
            aOrbiterI = RotL64((aOrbiterI * 11441293212275890819U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 18205555540941493267U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16967799565443938873U) ^ RotL64(aNonceWordE, 35U);
            aOrbiterK = RotL64((aOrbiterK * 3009081009044782443U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9209505304067579944U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3522631966146762306U;
            aOrbiterF = RotL64((aOrbiterF * 3441982898533162599U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8811497120829041188U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14707301680850257294U;
            aOrbiterB = RotL64((aOrbiterB * 11383709499376464085U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10080595991787801029U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6822892187784299166U;
            aOrbiterD = RotL64((aOrbiterD * 7417016898027778287U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1981637172055758689U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 16463077485583119324U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2876782050665869121U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8383837717361569465U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2788511294985017326U;
            aOrbiterA = RotL64((aOrbiterA * 2809163242875130677U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3529607472855930041U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8850940802020173766U;
            aOrbiterG = RotL64((aOrbiterG * 7821450253655655943U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7469160295100147267U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16973986572163482061U;
            aOrbiterE = RotL64((aOrbiterE * 15660743778376905023U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12371372942863279718U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12098525148034303633U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11234127652230231751U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5138683482859889480U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3339283916456813609U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10975353228235695455U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 34U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE) + RotL64(aNonceWordC, 45U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 26U) + aOrbiterB) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterJ, 13U));
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 6U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterH, 39U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + RotL64(aNonceWordF, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterG, 29U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 60U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterC, 41U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 12U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 11U) ^ RotL64(aNonceWordF, 39U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5652U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9664U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 40U) ^ RotL64(aNonceWordH, 11U)) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10259U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6587U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 22U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 51U)) + 12615321415808640429U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 29U)) + 15712784676459931207U;
            aOrbiterA = (aWandererI + RotL64(aCross, 23U)) + 11013335427004930046U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 8298733856304768806U) + aPhaseFOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 56U)) + RotL64(aCarry, 51U)) + 6207732959150824216U) + RotL64(aNonceWordB, 31U);
            aOrbiterH = ((aWandererC + RotL64(aIngress, 5U)) + 9769864876127544038U) + aPhaseFOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 39U)) + 10782181918651152563U) + RotL64(aNonceWordC, 19U);
            aOrbiterD = (aWandererE + RotL64(aCross, 35U)) + 5790454015845620939U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 47U)) + 15606578025386733803U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 26U)) + RotL64(aCarry, 5U)) + 5522352539991175304U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 13U)) + 5993355818572869649U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10864534396947622047U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 12090053126235913528U) ^ RotL64(aNonceWordH, 30U);
            aOrbiterA = RotL64((aOrbiterA * 7250801471645972261U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14191181677234981396U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2258570108233924592U;
            aOrbiterE = RotL64((aOrbiterE * 8307541155393855209U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8448114811381534603U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2702389315763499817U;
            aOrbiterC = RotL64((aOrbiterC * 6710443836432274393U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17202184076718780200U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 150549910056015002U;
            aOrbiterF = RotL64((aOrbiterF * 195034681254956335U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4910512055808124967U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4783477997418403079U;
            aOrbiterK = RotL64((aOrbiterK * 861977492146512865U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13842899106208709771U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7930112618036681468U;
            aOrbiterJ = RotL64((aOrbiterJ * 8609551859830858419U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 8790107242863198659U) + RotL64(aNonceWordA, 5U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6882768826643279144U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13745521454063360763U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12136498871759890015U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8120456314755584336U;
            aOrbiterH = RotL64((aOrbiterH * 1830725195528043575U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14425711740351183016U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15907406009196323049U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8599371693260686839U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4878521420367891861U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 1184672056055028939U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5963961755367831967U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10126736568567000180U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12615321415808640429U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11663715449073755137U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 4U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 39U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 53U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterG, 18U));
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 18U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + RotL64(aCarry, 35U)) + RotL64(aNonceWordD, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 6U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 23U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 56U) + aOrbiterI) + RotL64(aOrbiterK, 51U)) + RotL64(aNonceWordF, 49U)) + aPhaseFWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordG, 47U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13695U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15060U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordD, 53U)) ^ RotL64(aNonceWordC, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11989U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneC[((aIndex + 11881U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aIngress, 54U)) + 12380376990224645149U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 51U)) + 18296928500297384014U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 41U)) + 3550626816361145100U) + RotL64(aNonceWordC, 49U);
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 35U)) + 2667792936946706027U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 12020969779370926953U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 737340727886903447U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 30U)) + RotL64(aCarry, 39U)) + 1681797651799760502U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 5U)) + 2956186342689489064U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 39U)) + 1876852870402977177U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 37U)) + 6433205819353555071U) + RotL64(aNonceWordH, 55U);
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 43U)) + 9065076854974222998U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3254410578766789992U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2005081975473815576U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9947701153722014085U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15992999234834560419U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3458344156815120948U;
            aOrbiterE = RotL64((aOrbiterE * 1668460113964608051U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17069783053664877727U) + RotL64(aNonceWordB, 39U);
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1260234710193913099U;
            aOrbiterB = RotL64((aOrbiterB * 4561226779897414381U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3825186451876061335U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2905344294992827535U;
            aOrbiterI = RotL64((aOrbiterI * 2469896090698580795U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18141402347899180617U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8760129857609925066U;
            aOrbiterA = RotL64((aOrbiterA * 2507999156108123047U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 594052473780678210U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13216719212966128379U;
            aOrbiterK = RotL64((aOrbiterK * 10691355329696722303U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10029948739466316169U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11912428807431992996U;
            aOrbiterF = RotL64((aOrbiterF * 85016510811938307U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8735634019801417287U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12785916159063273545U;
            aOrbiterG = RotL64((aOrbiterG * 1161917531260663357U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 367752057919802452U) + RotL64(aNonceWordE, 36U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3961036242431041564U;
            aOrbiterH = RotL64((aOrbiterH * 16352646009782597315U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3858415336170090719U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14325258358254321551U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12080431158781060059U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16872184337970977180U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12380376990224645149U;
            aOrbiterC = RotL64((aOrbiterC * 16559121155413059221U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 48U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 19U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterA, 42U));
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aCross, 21U) + RotL64(aOrbiterH, 39U)) + aOrbiterD) + RotL64(aCarry, 53U)) + RotL64(aNonceWordF, 9U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 53U)) + aOrbiterB) + aPhaseFWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterA, 47U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterC, 27U)) + aOrbiterD) + RotL64(aNonceWordD, 31U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterD, 44U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 52U) ^ RotL64(aNonceWordA, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16428U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18759U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordH, 23U)) ^ RotL64(aNonceWordG, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20810U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20364U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 27U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 19U)) + 9751314027302668907U) + RotL64(aNonceWordF, 7U);
            aOrbiterB = (aWandererA + RotL64(aScatter, 4U)) + 12175450995523107056U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 17519694958730119552U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 9093525527925682263U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 39U)) + 3713831321786810138U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 27U)) + 10108355209191835040U) + RotL64(aNonceWordE, 17U);
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 12956307447311314768U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 47U)) + 1904298513945877359U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aScatter, 23U)) + 4658049993308574460U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 41U)) + 9826333658248851902U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aCross, 14U)) + 12058666914724365134U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 2516574707110528099U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13335308331049750235U;
            aOrbiterH = RotL64((aOrbiterH * 5880227828760598587U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8230749255538495304U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16536559486797811486U;
            aOrbiterI = RotL64((aOrbiterI * 7097036838156464969U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12387639130570188998U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8459259798142872020U;
            aOrbiterD = RotL64((aOrbiterD * 8001346480955847013U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16083784052002800300U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 1957284290736468379U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) ^ RotL64(aNonceWordD, 13U);
            aOrbiterJ = RotL64((aOrbiterJ * 5046501301740813065U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7349538179311335863U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16395170077006105258U;
            aOrbiterG = RotL64((aOrbiterG * 4230485452156662763U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3317652065873784068U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 5517155804799120700U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9789270651974719183U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5568525912112200094U) + RotL64(aNonceWordG, 45U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9334250662962319598U;
            aOrbiterK = RotL64((aOrbiterK * 5034887614541768961U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5641394627075994165U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13524971148931512745U;
            aOrbiterA = RotL64((aOrbiterA * 3699457147759854357U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15124425790244392471U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7896294947517723306U;
            aOrbiterE = RotL64((aOrbiterE * 7526632360108129915U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15241686066829586263U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12099799118961857495U;
            aOrbiterB = RotL64((aOrbiterB * 10456171163074630861U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17529688916595727188U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9751314027302668907U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 521888849578281715U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 10U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 56U) + RotL64(aOrbiterI, 51U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 6U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 11U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 23U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aCross, 18U) + aOrbiterB) + RotL64(aOrbiterK, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 57U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 41U)) + aOrbiterF) + RotL64(aCarry, 19U)) + RotL64(aNonceWordH, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterI, 26U));
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterJ, 43U)) + aPhaseFWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterA) + RotL64(aNonceWordC, 40U)) + aPhaseFWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 60U) ^ RotL64(aNonceWordC, 35U)) ^ RotL64(aNonceWordB, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25048U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 22626U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 20U) ^ RotL64(aNonceWordE, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26326U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 26622U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aCross, 35U)) + 9888431329297626900U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 41U)) + 2937735167534624403U) + RotL64(aNonceWordE, 23U);
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 17626022970343789617U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 26U)) + 5665660859333693743U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 21U)) + 1060537034632076669U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 743777763907175800U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 5744905970181808845U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 51U)) + 3545351394494002180U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aCross, 57U)) + 4877547088414106007U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 39U)) + 11669378338379598445U) + aPhaseFOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 48U)) + 2961072441706158212U) + RotL64(aNonceWordB, 25U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13984945589234919765U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1433097875470903205U;
            aOrbiterB = RotL64((aOrbiterB * 451996840039906781U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 716415411025451152U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8542286150858297810U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9139015340823332449U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12932391786479661299U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14005503313299177013U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 802663466907819743U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9382792812676318046U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5138554251079724724U;
            aOrbiterC = RotL64((aOrbiterC * 6386016499265056247U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8522380066269546172U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11825536408101906458U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17042837108792016849U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15504062350899452495U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1219010998820336744U;
            aOrbiterD = RotL64((aOrbiterD * 10650635772711590803U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6442717843380349632U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1047843426279085117U;
            aOrbiterA = RotL64((aOrbiterA * 4074561571072878005U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10611039527108679173U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5092816736177358221U) ^ RotL64(aNonceWordD, 61U);
            aOrbiterE = RotL64((aOrbiterE * 14342779343820140833U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12327496881352988530U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6405703847824845457U) ^ RotL64(aNonceWordC, 36U);
            aOrbiterF = RotL64((aOrbiterF * 12094143526751620113U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8906613392335197542U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5962698890029858689U;
            aOrbiterK = RotL64((aOrbiterK * 9136193803330500489U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2610083915800734277U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9888431329297626900U;
            aOrbiterG = RotL64((aOrbiterG * 3794133356691218671U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (RotL64(aOrbiterF, 4U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 21U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 44U) + aOrbiterF) + RotL64(aOrbiterC, 13U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 18U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 57U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 41U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 23U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aIngress, 24U) + aOrbiterG) + RotL64(aOrbiterA, 47U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 43U)) + aOrbiterF) + RotL64(aNonceWordF, 5U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 30U)) + aOrbiterC) + RotL64(aNonceWordA, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterA, 37U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 50U) ^ RotL64(aNonceWordE, 37U)) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30632U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 28277U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordG, 36U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31388U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 31165U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererD + RotL64(aPrevious, 51U)) + 18087125778766689269U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 39U)) + 13710545066503235196U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 5U)) + 1701939704736254645U) + RotL64(aNonceWordH, 3U);
            aOrbiterH = ((aWandererA + RotL64(aScatter, 34U)) + RotL64(aCarry, 29U)) + 8064093611384019909U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 47U)) + 16623332751533885431U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 53U)) + 15590129153794910109U) + RotL64(aNonceWordF, 11U);
            aOrbiterI = ((aWandererE + RotL64(aScatter, 21U)) + 7413312683079107383U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 4186064478651458810U;
            aOrbiterC = (aWandererC + RotL64(aCross, 3U)) + 5501191643940735954U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 11064645242200570835U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 24U)) + 13825922087298055833U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5944980709887369970U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8181136916070569646U;
            aOrbiterF = RotL64((aOrbiterF * 395183021205661827U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15442336949157292482U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11580554435240641337U;
            aOrbiterG = RotL64((aOrbiterG * 6654637892858767739U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 11240018128174598322U) + RotL64(aNonceWordA, 61U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2027565596050777471U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18048186560314431815U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16425887196883725233U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16828683527588834095U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17746289103235902485U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9923829146479008804U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6669171007279929454U;
            aOrbiterD = RotL64((aOrbiterD * 681823450939955099U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3902430046523165149U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6739998149289590041U;
            aOrbiterC = RotL64((aOrbiterC * 2675037435528416821U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 16014401255534234075U) + RotL64(aNonceWordE, 16U);
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14741857638680634564U;
            aOrbiterE = RotL64((aOrbiterE * 8723611021403369393U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5064807861673260054U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 968747317273200299U;
            aOrbiterJ = RotL64((aOrbiterJ * 14122304002722582329U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5282686212362051427U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6902253563196129760U;
            aOrbiterK = RotL64((aOrbiterK * 7682808024658992049U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4995580401402368332U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14949762584793646470U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3539183342072953803U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2378815735788107402U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18087125778766689269U;
            aOrbiterH = RotL64((aOrbiterH * 16799380528404446281U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 58U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 43U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 41U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 34U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aCross, 42U) + aOrbiterK) + RotL64(aOrbiterC, 3U));
            aWandererK = aWandererK + (((((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA) + RotL64(aCarry, 11U)) + RotL64(aNonceWordB, 7U)) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 19U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterD, 6U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterE, 21U)) + RotL64(aNonceWordG, 9U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 50U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Rugby_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5059U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5102U)) & W_KEY1], 12U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 241U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 669U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererC + RotL64(aScatter, 29U)) + 15316464782468770057U;
            aOrbiterE = (aWandererD + RotL64(aCross, 52U)) + 6642872057476351588U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 660732654689529192U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 3U)) + 7235418086884000655U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 35U)) + 14784518476694580493U;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 12222433977933449375U) + aPhaseCOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 8573001207708329927U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 18U)) + 16035256260815013172U) + aPhaseCOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 11U)) + 15767726974121910203U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17712217935322939971U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 13488963456923357159U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16785285630840310405U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10222949131965611079U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1495561412321657209U;
            aOrbiterJ = RotL64((aOrbiterJ * 9706305581868526265U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16156530750584361434U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7773792489045606309U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10730624207715601393U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11544578291333360613U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3665587867634242865U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4840528190844842595U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15248434984650998090U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15487979645426567581U;
            aOrbiterC = RotL64((aOrbiterC * 10868107809356766183U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6972347795052712690U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16074994810010431338U;
            aOrbiterA = RotL64((aOrbiterA * 1262655238856775853U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16851139687900415292U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14630026837021552812U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9577900853521254603U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14236330619137368169U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17778707026111136216U;
            aOrbiterE = RotL64((aOrbiterE * 16239561893843454747U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9390961969105999083U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1174881758316573228U;
            aOrbiterB = RotL64((aOrbiterB * 6602061268277529311U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 43U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterB, 35U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterD, 20U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterH, 5U)) + aPhaseCWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterC, 39U));
            aWandererD = aWandererD + ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 13U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 4U) + aOrbiterE) + RotL64(aOrbiterK, 26U));
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10623U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 14502U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8435U)) & W_KEY1], 58U) ^ RotL64(aKeyRowReadB[((aIndex + 15703U)) & W_KEY1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 439898681482066326U;
            aOrbiterH = (aWandererF + RotL64(aCross, 11U)) + 17362083676671776094U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 30U)) + 6418499837265155024U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 17262244253027454972U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 19U)) + 2382066162993139503U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aIngress, 3U)) + 14345808395587174135U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 34U)) + 7534743166385552851U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 53U)) + 16994453324688523966U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 7079553728544045092U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3562822704508440641U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13990892681975857821U;
            aOrbiterI = RotL64((aOrbiterI * 8352929306654078795U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1796728922368577238U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6605161260520067178U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8147537646591674091U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13994083795942328918U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6144523182899107711U;
            aOrbiterJ = RotL64((aOrbiterJ * 4153879991344611283U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12247462325297436642U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1065809332002012789U;
            aOrbiterG = RotL64((aOrbiterG * 5496601177032953251U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10147919864511540753U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17138553441127273354U;
            aOrbiterF = RotL64((aOrbiterF * 5773875596275267871U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2653924016109573974U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6254416952351699582U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12756861659704947257U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 813046408080197079U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9624466135414123483U;
            aOrbiterD = RotL64((aOrbiterD * 6960320253124395015U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 972586705850825744U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 155283774901960223U;
            aOrbiterB = RotL64((aOrbiterB * 9928051687724257041U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 18200100644751360406U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1168426822045686004U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5867027156069481313U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterC, 11U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 14U) + aOrbiterB) + RotL64(aOrbiterG, 23U)) + aPhaseCWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterI, 18U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterG, 47U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 51U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 35U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 4U)) + aOrbiterE) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19037U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 21762U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 18747U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 20574U)) & W_KEY1], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 44U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererG + RotL64(aIngress, 29U)) + 6916817163240024692U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 6U)) + RotL64(aCarry, 53U)) + 14554930751292077817U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 47U)) + 1098305064484336101U) + aPhaseCOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 57U)) + 12192821172420471527U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 35U)) + 2435134991707318845U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 1896745368738512624U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 1114996424222923873U;
            aOrbiterG = (aWandererD + RotL64(aCross, 53U)) + 9839135798371512656U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 14U)) + 8037967239603177043U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15185468738487237432U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4912098316394854543U;
            aOrbiterA = RotL64((aOrbiterA * 3072785550384399929U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13142688607850380888U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4507379759608945839U;
            aOrbiterK = RotL64((aOrbiterK * 2989332387754215967U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7299006009652289342U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5390655277207053627U;
            aOrbiterI = RotL64((aOrbiterI * 10973744708856143715U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6744737023577785725U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15539737698867067285U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4686092035261336911U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13329866734681377952U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13284937458969166257U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3965985432462699445U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 8695002088915702168U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3858059421620839286U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9559783727301092937U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6609163873243179836U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9416165620556710540U;
            aOrbiterE = RotL64((aOrbiterE * 240385043740268229U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1578449067529000433U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14309000104419489303U;
            aOrbiterG = RotL64((aOrbiterG * 7599078306153684729U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15785180680737461320U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10099222679918382021U;
            aOrbiterH = RotL64((aOrbiterH * 2012232597046182581U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 48U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 44U) + RotL64(aOrbiterH, 34U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 29U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterF, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 53U)) + aOrbiterE) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 60U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterI, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 10U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32072U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32384U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32073U)) & S_BLOCK1], 44U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25720U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 22U) ^ RotL64(aCross, 39U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aIngress, 36U)) + RotL64(aCarry, 37U)) + 9041099828460168106U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 12883711604096848454U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 27U)) + 17420968786226443079U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 3448213891716125104U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 53U)) + 11866455977445336560U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 19U)) + 4119356835384495905U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 47U)) + 2186212599698637068U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 11U)) + 6506144898969301620U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 6U)) + 12556800923644051626U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4075551535185182945U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17877694808492008749U;
            aOrbiterG = RotL64((aOrbiterG * 901315308379887473U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5553428900598223316U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14362304852277160675U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11415103199856419303U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9174200302876075831U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16110739511917638547U;
            aOrbiterF = RotL64((aOrbiterF * 7004356839428657949U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10189881974519849402U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2128076632642616677U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8860453653433114929U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18133523799074400083U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9916472958834153766U;
            aOrbiterI = RotL64((aOrbiterI * 3454601168808001733U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10274457562795569227U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14134814273275356425U;
            aOrbiterH = RotL64((aOrbiterH * 15912501063665343159U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6394306369514735480U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4825761192736485643U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12534544147331805643U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5672807934779206275U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3881953574159390421U;
            aOrbiterD = RotL64((aOrbiterD * 7448770570912161095U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12012232712634303203U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14176392925893052596U;
            aOrbiterA = RotL64((aOrbiterA * 11288668529893084583U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 56U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterB, 40U)) + RotL64(aCarry, 43U)) + aPhaseCWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 46U) + aOrbiterG) + RotL64(aOrbiterC, 11U));
            aWandererG = aWandererG + ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 51U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 42U) + aOrbiterA) + RotL64(aOrbiterH, 60U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 47U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererD, 54U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Rugby_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5028U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 3562U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 649U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7140U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 39U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 10805654776556844351U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 3U)) + 582794182442795335U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 26U)) + RotL64(aCarry, 39U)) + 2858343650974681068U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 8189584049022064284U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 11U)) + 1565100751996962893U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8062028016947611891U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8280504280578451745U;
            aOrbiterE = RotL64((aOrbiterE * 5212851648135050483U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11326869194491655350U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1671695656567777163U;
            aOrbiterA = RotL64((aOrbiterA * 7511554500524257921U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2349843105293943452U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13015545152052004254U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1316662811685429983U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16703354404749291869U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8713231044374305801U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9242480982197688625U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11118401674497783533U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14857556493734710364U;
            aOrbiterH = RotL64((aOrbiterH * 3452566050389715195U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 39U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 51U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterK, 23U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterA, 13U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13055U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 14739U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9927U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((aIndex + 8479U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 39U)) + (RotL64(aPrevious, 58U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 6243113109470883144U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 27U)) + 3891552123999605832U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 36U)) + RotL64(aCarry, 13U)) + 8758797898587019128U) + aPhaseDOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aIngress, 51U)) + 1005891374086408851U;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 3713426782180050764U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 18358143862391573534U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17504394029693712404U;
            aOrbiterI = RotL64((aOrbiterI * 3391716204095092531U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5312729289027417014U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2560873623431186029U;
            aOrbiterG = RotL64((aOrbiterG * 16843728573219210173U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16309322822806704211U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 10195513918020652600U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14569219741824123715U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2552116263258744287U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7732784879810980089U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15041929399477790999U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16499127570665381507U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10890036715535519036U;
            aOrbiterK = RotL64((aOrbiterK * 9065115450010475187U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterH, 57U)) + aPhaseDWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 34U) + aOrbiterJ) + RotL64(aOrbiterH, 30U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 60U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17361U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 23584U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18104U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23139U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 12U)) + 1952750591494698524U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 37U)) + 4488270851303332830U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 2738763375328927635U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 6728843649480454340U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 10490717875258865358U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1429288737812910205U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2761375016998907636U;
            aOrbiterC = RotL64((aOrbiterC * 16589197409983023283U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1088988605204499835U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6829840407300289709U;
            aOrbiterF = RotL64((aOrbiterF * 13101432880030791787U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9267240337867690471U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8120113021183975703U;
            aOrbiterB = RotL64((aOrbiterB * 14296504593187173107U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1340980511302566784U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11874452169979878835U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8638486178860092537U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1872314794140971426U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6013952618696225751U;
            aOrbiterA = RotL64((aOrbiterA * 7994863587373565715U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 20U) + aOrbiterA) + RotL64(aOrbiterJ, 57U));
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterC, 30U));
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + aPhaseDWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32212U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30474U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26147U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 25584U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 28U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 6163290588946759209U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 7342672468560105447U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 11574563167017282321U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 57U)) + 2254820206194758964U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 28U)) + 1469783447473099498U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14174828900676165088U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16277954291890598132U;
            aOrbiterG = RotL64((aOrbiterG * 4608888834164373691U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14845750668693136766U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 150099699692047766U;
            aOrbiterA = RotL64((aOrbiterA * 7644895634421086357U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1200784917165131703U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9469982764806754302U;
            aOrbiterJ = RotL64((aOrbiterJ * 17851969334511301943U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10956702761701710182U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7915506894975487807U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8874108311712727983U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17335794183733623213U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 557028996286989506U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3993359298602424281U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 18U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 13U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 22U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 26U) + aOrbiterE) + RotL64(aOrbiterA, 47U)) + aPhaseDWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 3U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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

void TwistExpander_Rugby_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7993U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((aIndex + 2721U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8171U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 6576U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 30U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aIngress, 13U)) + 3973833383430652211U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 39U)) + 5760227042747169187U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 53U)) + 4923009065139227286U) + aPhaseEOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 1477807307009107590U) + aPhaseEOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aIngress, 46U)) + RotL64(aCarry, 29U)) + 5707194514329007301U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 5340439728375269724U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 3U)) + 17080457898946572387U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 281559150259472813U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16160633048230910560U;
            aOrbiterF = RotL64((aOrbiterF * 16883442583309073785U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9003989610509592121U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10579322462808454333U;
            aOrbiterD = RotL64((aOrbiterD * 100832431598087235U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15059383289528723069U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10417647757852880956U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1457919230286043137U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14484665027393813330U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12344463053485837974U;
            aOrbiterE = RotL64((aOrbiterE * 5762654194001525041U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5826453246659297805U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12547902286376986223U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2982850000322672789U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9637855144278126174U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2132744427444501938U;
            aOrbiterB = RotL64((aOrbiterB * 5911587798564836199U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9248933938130311231U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13274297928717090383U;
            aOrbiterC = RotL64((aOrbiterC * 2901398809555237563U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterD, 19U));
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 40U) + RotL64(aOrbiterB, 43U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 50U)) + aPhaseEWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterB, 29U)) + aPhaseEWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14438U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((aIndex + 15116U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12383U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 11493U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 56U)) ^ (RotL64(aCarry, 11U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 13U)) + 10038936806177516123U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 1773168435195292638U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 47U)) + 10655711161526628072U) + aPhaseEOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 14422295664639740437U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 6U)) + 4125228715513159576U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aCross, 29U)) + 3670449653158650845U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 17553727567180813057U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5111401772713882743U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7688573124662314413U;
            aOrbiterG = RotL64((aOrbiterG * 10846442063022821393U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9438375825507814395U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14177477039902118886U;
            aOrbiterH = RotL64((aOrbiterH * 6467406626985022537U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16329942595859623928U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3990536794006836672U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 579024714339065373U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5072881436583180756U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16789727877867289997U;
            aOrbiterF = RotL64((aOrbiterF * 8766246302636197905U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17313956922306689438U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 11530878396329822041U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11356860047841383129U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3612616532321160196U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4172189825359187763U;
            aOrbiterD = RotL64((aOrbiterD * 12938945495299393177U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8677279703778052804U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1912172980909479362U;
            aOrbiterB = RotL64((aOrbiterB * 10053289257955474143U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterG, 57U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterA, 42U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 50U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 19U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 51U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 4U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18817U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22082U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18285U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 24227U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 28U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 13854738573712660276U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 16835460633412286294U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aCross, 4U)) + RotL64(aCarry, 11U)) + 6785859293758091931U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 57U)) + 126317283127992659U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 51U)) + 7568963536291415413U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 13U)) + 12294016745653004819U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 19U)) + 18269588932920281147U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5872406424994751026U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7764434758831474129U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3772146788188420071U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 4804168969415573371U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 959601763507651280U;
            aOrbiterD = RotL64((aOrbiterD * 4647396592804833217U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9257644462479293048U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14332699366894494579U;
            aOrbiterC = RotL64((aOrbiterC * 8829304078930625541U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10487012596470786004U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 612729229562321440U;
            aOrbiterJ = RotL64((aOrbiterJ * 11380387280507726003U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 7845523921295625315U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12742115479740024747U;
            aOrbiterH = RotL64((aOrbiterH * 15578543510683986421U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10294667720904610944U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14369711143154904567U;
            aOrbiterA = RotL64((aOrbiterA * 13753005602288309379U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10918344717497681894U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 18136794828308636957U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17899418637978002409U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 11U)) + aOrbiterC) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 37U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25678U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31775U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25557U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31965U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 43U)) ^ (RotL64(aPrevious, 30U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererF + RotL64(aIngress, 13U)) + 16189787374324972735U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 22U)) + RotL64(aCarry, 19U)) + 17563763730956242224U) + aPhaseEOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 10572803498593789385U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 7713105232072974166U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 57U)) + 10760839534772718139U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 39U)) + 13397069448391230253U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 29U)) + 4569255679998375682U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9888769350817876949U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11351796060878856300U;
            aOrbiterH = RotL64((aOrbiterH * 13356749147334008399U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 18153775071965707204U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1282846411145853435U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12294455920906257823U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16457743979262460660U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 173493260775251032U;
            aOrbiterI = RotL64((aOrbiterI * 4935807229040883505U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3927345926316409630U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5158769729850853623U;
            aOrbiterB = RotL64((aOrbiterB * 2446452358663812945U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12331351600010165154U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3940794200348684050U;
            aOrbiterJ = RotL64((aOrbiterJ * 13248997263062075043U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11248514843822945425U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1391497323278226522U;
            aOrbiterG = RotL64((aOrbiterG * 8376841806072565005U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13265623528678787307U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2802033745265647317U;
            aOrbiterF = RotL64((aOrbiterF * 3437626962562016147U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 12U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 39U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 50U) + RotL64(aOrbiterI, 29U)) + aOrbiterB) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterG, 5U));
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 23U)) + aOrbiterB) + aPhaseEWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterI, 54U));
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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

void TwistExpander_Rugby_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5950U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6475U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5557U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 7950U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 29U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 4476099022490972343U) + aPhaseFOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aIngress, 28U)) + 16836423700375760429U) + aPhaseFOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 57U)) + 8850577488928703557U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 7091631824560042743U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 12560498899956759494U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7797973377112012161U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 6173820673874805794U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15741300047917486527U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10805025132310245348U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7139216143268029968U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8349754682635765573U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8241544862261635722U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 4735527016563596150U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6621354217673598381U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5166171126690294033U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11117641762075368393U;
            aOrbiterF = RotL64((aOrbiterF * 4980156869201219393U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6312932356458415421U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1304139291184508668U;
            aOrbiterC = RotL64((aOrbiterC * 90744653170922319U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterE, 37U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + RotL64(aOrbiterF, 3U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 46U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 57U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15051U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 11359U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9135U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 14188U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aIngress, 21U)) ^ (RotL64(aCross, 43U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 13960289014350612206U;
            aOrbiterK = (aWandererH + RotL64(aCross, 10U)) + 3483331015269589730U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 6873299241002444518U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 3562094007125534229U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 35U)) + 11422367439932782705U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 532453428514259816U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17810941465810193088U;
            aOrbiterE = RotL64((aOrbiterE * 2830829128884590275U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 11869759058631106331U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8837581071876177566U;
            aOrbiterD = RotL64((aOrbiterD * 15329827515970522213U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17185378327053837778U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7578253375676981500U;
            aOrbiterG = RotL64((aOrbiterG * 13371647568758721729U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17112646434432814442U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14949096407295697881U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14770977858283051753U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4259590620758467836U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 6534899413644542303U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7987609419215568661U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 30U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterH, 53U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterH, 5U)) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 43U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterG, 24U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 54U) + RotL64(aOrbiterG, 13U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22090U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16578U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20175U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23210U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 38U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererK + RotL64(aPrevious, 11U)) + 4970414922752555648U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 43U)) + 9462756592787669327U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 3948790686662213095U;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 14542857212241578311U) + aPhaseFOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 23U)) + 3387479009827029547U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1411421370057797877U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16894451466895681236U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13825974818858676215U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12727136462290223542U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4625389198191960525U;
            aOrbiterF = RotL64((aOrbiterF * 5726474430977810191U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3471881403786164913U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6433115856048534831U;
            aOrbiterB = RotL64((aOrbiterB * 9363233870194144053U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9825592965466157982U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 1553125767261293088U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 411535191177308781U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9951616357109647617U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11231080382787286889U;
            aOrbiterK = RotL64((aOrbiterK * 14024961994986659187U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 13U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 54U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aCross, 50U) + RotL64(aOrbiterK, 23U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27339U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 31587U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32548U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 28459U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 3650233661228036955U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 11607036400067735729U) + aPhaseFOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 41U)) + 3899614406903883035U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 8159156925629965143U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 12U)) + 7148903913967261270U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9161665622287517848U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2981535013474059469U;
            aOrbiterG = RotL64((aOrbiterG * 4434815231517266013U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 15812469008200319549U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 14687469489893270300U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14142363399696670451U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6025209349511417063U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 12964750392311112676U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12955480283032701843U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6572355895765394340U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3542300121890027981U;
            aOrbiterC = RotL64((aOrbiterC * 11201491178181273935U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6477175684045398359U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1081388388827929314U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8752188637514143529U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 6U) + aOrbiterH) + RotL64(aOrbiterC, 54U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 23U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterA, 41U)) + aPhaseFWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Rugby_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 2648U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4778U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3509U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6536U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 37U)) + (RotL64(aCarry, 5U) + RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 8975885703279267062U) + aPhaseGOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 8664844915562660637U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 51U)) + 12281774799736296726U;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 15347461352311329726U) + aPhaseGOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 42U)) + 12967500561828907834U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5002833859280402726U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11908257536954668983U;
            aOrbiterC = RotL64((aOrbiterC * 4384790916151202785U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17017174811949227162U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 16851323125613931180U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12446990992858763577U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13469326957728686706U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5228638551056105241U;
            aOrbiterH = RotL64((aOrbiterH * 13369947664646167255U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11945166198089308564U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16268645041872996022U;
            aOrbiterE = RotL64((aOrbiterE * 5391448793718370911U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 14781204627695095701U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5365325354838101092U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8017284997946310807U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 54U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 27U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 10U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterC, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16074U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15064U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10940U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12653U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 43U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 6U)) + RotL64(aCarry, 35U)) + 13854738573712660276U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 16835460633412286294U) + aPhaseGOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 29U)) + 6785859293758091931U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 47U)) + 126317283127992659U) + aPhaseGOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 7568963536291415413U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12294016745653004819U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 18269588932920281147U;
            aOrbiterF = RotL64((aOrbiterF * 9031152619272892317U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5872406424994751026U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 7764434758831474129U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3772146788188420071U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4804168969415573371U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 959601763507651280U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4647396592804833217U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9257644462479293048U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14332699366894494579U;
            aOrbiterD = RotL64((aOrbiterD * 8829304078930625541U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10487012596470786004U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 612729229562321440U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11380387280507726003U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 41U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + aPhaseGWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterD, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 26U) + aOrbiterA) + RotL64(aOrbiterK, 35U));
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterB, 52U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 19967U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20018U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18185U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 18447U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 34U)) + RotL64(aCarry, 19U)) + 16651241552253078315U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 23U)) + 4558144676982478003U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 8814884320080367550U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 16011579668555672117U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 5U)) + 4738918668759862438U) + aPhaseGOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12526083125540985108U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8048723561746000552U;
            aOrbiterI = RotL64((aOrbiterI * 11914807994597963481U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 1082218464034639039U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8432043246965946816U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7801965585991025451U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9982080524048636852U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6720069955755215919U;
            aOrbiterA = RotL64((aOrbiterA * 1025046364205332059U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1019035028070247757U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 7360619079463870467U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6623074813047915863U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10893918488381348474U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1390297670907738019U;
            aOrbiterC = RotL64((aOrbiterC * 11909657437658597735U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterH) + aPhaseGWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA) + aPhaseGWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 26U) + aOrbiterI) + RotL64(aOrbiterH, 20U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 27375U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25276U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25214U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 28520U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 54U)) ^ (RotL64(aIngress, 35U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 4U)) + RotL64(aCarry, 35U)) + 3255291173184001106U) + aPhaseGOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 15308468160116255528U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 37U)) + 18186972408589866656U) + aPhaseGOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 4439324265978331914U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 57U)) + 13099263173016322486U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7041561081767500660U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6196422612687812971U;
            aOrbiterI = RotL64((aOrbiterI * 13359900204297781063U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7664260932541281413U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 17802347823020441056U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2220679459017369255U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 4253107484061190446U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 13799496534030645312U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9167675060053848207U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14252892847595951926U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5663527578664291422U;
            aOrbiterE = RotL64((aOrbiterE * 18314294235895182465U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11148755959699137661U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17036900929333594592U;
            aOrbiterH = RotL64((aOrbiterH * 16041243617369003291U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 39U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 30U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterE, 47U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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

void TwistExpander_Rugby_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 2866U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 5958U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3395U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 6812U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 43U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 11U)) + 4179952823252098240U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 3745613452332101749U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 52U)) + 2955689793395307176U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 5639060180251322019U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 7901969163853586463U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2242166787816318119U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5239936443960750064U;
            aOrbiterB = RotL64((aOrbiterB * 2752853245379816327U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13939136954732185558U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17058884136712717463U;
            aOrbiterC = RotL64((aOrbiterC * 7222348891215482977U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 18148618660054585941U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 7022023484530327814U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 650100011311048589U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7722084537340095637U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11764151879690934182U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12264384877711365655U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16412785901758144708U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 9666718667728274824U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10865799822751771795U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 47U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 50U) + aOrbiterH) + RotL64(aOrbiterA, 28U)) + aPhaseHWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13415U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 9651U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11675U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 12939U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aIngress, 24U)) + RotL64(aCarry, 43U)) + 3105313968748067810U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 9977249451119627064U) + aPhaseHOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 17941392803495349366U;
            aOrbiterH = (aWandererD + RotL64(aCross, 3U)) + 4279533326705471133U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 57U)) + 13983828966811580039U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3983490984234810378U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 308786542215259956U;
            aOrbiterI = RotL64((aOrbiterI * 4366245356597769425U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8443607695364427037U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14939626441464340668U;
            aOrbiterA = RotL64((aOrbiterA * 16793255020331774983U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9350693577306121110U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1717071159396961752U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11062480662625054525U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15911765265202100610U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14898546272333182767U;
            aOrbiterJ = RotL64((aOrbiterJ * 2674900543810733067U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3560903518513465868U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5367062725726860234U;
            aOrbiterH = RotL64((aOrbiterH * 8521908836601319553U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 48U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterH) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererD, 4U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 17409U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 24274U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16582U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 22337U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 10U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererG + RotL64(aCross, 23U)) + 14249093584376402677U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 50U)) + 8756965951816492264U) + aPhaseHOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 11221139480258176330U) + aPhaseHOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 17218894445564194851U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 8064642692524949490U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 5822093203710704646U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3217799620158102238U;
            aOrbiterA = RotL64((aOrbiterA * 2806328682494910635U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2613757677892120843U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13647481499551657237U;
            aOrbiterJ = RotL64((aOrbiterJ * 5517563514031899891U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3545714196663685016U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 9735422670576621521U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7276207208162697249U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3911046580637583767U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9315984027042049203U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12568550776487242469U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8926367674641729058U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11035347490524961446U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10948288997163592463U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 24U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 46U) + aOrbiterA) + RotL64(aOrbiterC, 39U));
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterE, 4U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterB, 51U));
            aWandererE = aWandererE + (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 30513U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25118U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30814U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((aIndex + 30310U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 52U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 17936518874386450467U) + aPhaseHOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 52U)) + RotL64(aCarry, 57U)) + 13722737841589910344U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 3U)) + 11774969167948715796U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 3640101505680493777U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 37U)) + 1369495382725650822U) + aPhaseHOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11827310354654653345U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 186037671377175394U;
            aOrbiterC = RotL64((aOrbiterC * 829791264853993897U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11428829344234627340U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2275016369870029068U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14936799202145280833U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15471646673734798328U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12172082573115640145U;
            aOrbiterH = RotL64((aOrbiterH * 9629417882787847753U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6626736341348283154U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12220614992483863623U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8137086205714097487U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13157102324253760215U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 4143587482368093601U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5060677690991506895U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterK, 35U));
            aWandererF = aWandererF + ((((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterG, 24U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + aPhaseHWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
