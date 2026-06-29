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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD6C5E7A8254CC7D7ULL + 0x99825D702D67E531ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBDC9EA8B7DD976E3ULL + 0xEA97072873797C35ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBEC7402429CDDD67ULL + 0xC3118E374AD85441ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAC01A02BD9EFDA6DULL + 0x91C216FF64C96200ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA752EB07FAEF6273ULL + 0x96BDABA6BE32E9B8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x940588928E770F97ULL + 0xFA74220D4BA3B90FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEF335281A24D5369ULL + 0xBAE8336A8982E503ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAE07794C01E701C9ULL + 0x9CD23A7034940849ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC1C368EBD183F279ULL + 0xD52D70417CB9B161ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xAF94A14E1CBE7911ULL + 0xEF71B4F50D0F1055ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB97F05D38EEE4935ULL + 0xBB766EED7B87DA8CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFDA7EE305C2BCA11ULL + 0xAC54075E49AB1073ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD98BFB16491D6807ULL + 0x94685A5C047D5C86ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xECE06AF895D8D119ULL + 0xC5D9BFB9AC96D4F6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB27A770C33ACC525ULL + 0xD679CE4AC46A7CC7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9AD03D5E1133141DULL + 0xB5B8A99EBEBDDF63ULL);
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
            aIngress = RotL64(mSource[((aIndex + 3111U)) & S_BLOCK1], 56U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 657U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 736U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5186U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 18U)) ^ (RotL64(aCross, 51U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = (aWandererK + RotL64(aPrevious, 35U)) + 9471546960258473684U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 23U)) + 18050235435948942244U) + aOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 3005107102671544641U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 46U)) + RotL64(aCarry, 27U)) + 17898396434573801850U) + aNonceWordP;
            aOrbiterC = (aWandererF + RotL64(aIngress, 11U)) + 15071602525497771648U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 3U)) + 5780119462702672108U) + aNonceWordL;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 13301326224151025687U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 29U)) + 18129323022260575961U;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 39U)) + 1199228670638790709U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aWandererH + RotL64(aScatter, 52U)) + 1839199978088021020U;
            aOrbiterB = (aWandererG + RotL64(aCross, 43U)) + 4999517042246790165U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 8788607633376516299U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15143903839930468749U;
            aOrbiterD = RotL64((aOrbiterD * 12735914889325422675U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 16674732686428431869U) + aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15908873150953195581U;
            aOrbiterC = RotL64((aOrbiterC * 18049755517524334107U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11204775359756474667U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2525984309543939465U;
            aOrbiterG = RotL64((aOrbiterG * 3988529812023791571U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4566345170476825512U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14876612901557406267U;
            aOrbiterH = RotL64((aOrbiterH * 9047956948845135339U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14926290877038883931U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 12710203178186614846U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 14841163494801662515U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7315094513967387996U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11050116830482816766U;
            aOrbiterI = RotL64((aOrbiterI * 3702999495721152019U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4505368486032503953U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17905748055257551092U;
            aOrbiterF = RotL64((aOrbiterF * 14775870175093453197U), 27U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 5728886950801376350U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17998141690182325170U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 16008599930125391379U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4325978018819134558U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13526905108565989379U;
            aOrbiterB = RotL64((aOrbiterB * 14121321495714166291U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10597169665474269506U) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7500801022830471869U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3702717219742363777U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17063616328548689935U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9471546960258473684U;
            aOrbiterK = RotL64((aOrbiterK * 3029748230803396737U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + aNonceWordD);
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 35U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterE, 10U)) + aOrbiterD) + aNonceWordC);
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 13U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 5U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aCross, 23U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 57U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aIngress, 14U) + aOrbiterC) + RotL64(aOrbiterE, 23U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterA, 50U)) + aNonceWordB) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 10872U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((aIndex + 10734U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7283U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((aIndex + 10473U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 37U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 13915875634607599122U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 51U)) + 1695770381382411673U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 30U)) + 3709105579778295511U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 27U)) + 7673376335333251804U) + aNonceWordJ;
            aOrbiterF = (aWandererI + RotL64(aCross, 13U)) + 8814147709738503518U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 23U)) + 13451412605350381172U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 5U)) + 6447870234069609538U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 40U)) + RotL64(aCarry, 39U)) + 13419487997946496825U) + aNonceWordO;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 5478309847615220345U;
            aOrbiterE = (aWandererE + RotL64(aCross, 21U)) + 3635184969215610049U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 53U)) + 12527903812035294828U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1684685110885338814U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12860354576326835090U;
            aOrbiterJ = RotL64((aOrbiterJ * 12743745087733307255U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9081823570147481835U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14369321778210049109U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 17865953349448767035U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11518132079084873250U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11893535026126957389U;
            aOrbiterD = RotL64((aOrbiterD * 15751374986135615095U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7084079180579206226U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2999676609847603277U;
            aOrbiterH = RotL64((aOrbiterH * 14602698397511266403U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17683445810614029153U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11576460512964896969U;
            aOrbiterC = RotL64((aOrbiterC * 5243651036457051155U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13429800604736567949U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14661785761747367546U;
            aOrbiterK = RotL64((aOrbiterK * 4765843989277333421U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12837164345582888950U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6222666313184669392U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 17402483466567712319U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5358647039491079457U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12459911673401497180U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13605465035256188065U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3333017644772803587U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 15501587702102554928U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 4921693371641768339U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8492287653837766613U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 3432736785678875404U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 7326419883291516513U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2841486107704281869U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13915875634607599122U;
            aOrbiterA = RotL64((aOrbiterA * 707861617246345083U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 30U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 38U) + RotL64(aOrbiterB, 21U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 41U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 60U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 13U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterK, 51U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterG);
            aWandererE = aWandererE + (((((RotL64(aCross, 43U) + RotL64(aOrbiterF, 46U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aNonceWordP) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 53U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 22U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 14737U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15397U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14099U)) & S_BLOCK1], 52U) ^ RotL64(pSnow[((aIndex + 14842U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 36U)) ^ (RotL64(aCross, 19U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (aWandererH + RotL64(aPrevious, 53U)) + 18191288703716505885U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 13U)) + 9824014524910417136U) + aNonceWordF;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 3U)) + 11953012029254917548U) + aNonceWordD;
            aOrbiterC = (((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 39U)) + 6297568011027199089U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 2576999400457367975U) + aNonceWordC;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 47U)) + 13176139160575558254U;
            aOrbiterD = (aWandererB + RotL64(aCross, 19U)) + 9978408174563621810U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 35U)) + 16765834875061607142U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 16534507305459121344U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 58U)) + 3114710944346151807U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 43U)) + 10240517868726718592U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10721450637990777883U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16689590768796583952U;
            aOrbiterJ = RotL64((aOrbiterJ * 3046344179729901637U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2427422768928450209U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13495584061816457831U;
            aOrbiterA = RotL64((aOrbiterA * 6670984773768885119U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7058636403765106682U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9897341853944713767U;
            aOrbiterF = RotL64((aOrbiterF * 14286816859999869231U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17749559755733386064U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12515645083926326659U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6582878478865838245U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2625692458813609962U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10596240255026143019U;
            aOrbiterH = RotL64((aOrbiterH * 11605800195771080135U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12374290338067865540U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1507386663796330249U;
            aOrbiterC = RotL64((aOrbiterC * 1210241080424446087U), 39U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 9288099549484146726U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15159312464747000702U;
            aOrbiterI = RotL64((aOrbiterI * 500055502081347757U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14998608679505446229U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17625038109437732009U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 14785862243019841689U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10543192232885637211U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10330547522729618042U;
            aOrbiterB = RotL64((aOrbiterB * 7635903835474874057U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5753298214283941201U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15943436872588208065U;
            aOrbiterE = RotL64((aOrbiterE * 17704547766822075741U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5757218926946874970U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 18191288703716505885U;
            aOrbiterD = RotL64((aOrbiterD * 2644970408001409575U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 28U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 52U) + aOrbiterF) + RotL64(aOrbiterI, 14U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 53U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 41U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 39U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 26U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 20U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterG, 51U)) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterC, 5U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17058U)) & S_BLOCK1], 28U) ^ RotL64(pSnow[((aIndex + 19910U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 21623U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 19596U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21590U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 37U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (aWandererE + RotL64(aIngress, 53U)) + 3339283916456813609U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 37U)) + 11339086426180649584U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 18U)) + 16819191669329316585U) + aNonceWordL;
            aOrbiterC = (aWandererD + RotL64(aScatter, 5U)) + 8361916937762630725U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 18031328374429899857U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 3U)) + 18261756894092897276U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 4250319792907645666U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 51U)) + 1492411503643460886U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 26U)) + 17369549067879344180U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 41U)) + 7301713524358676722U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 2985193736033012535U) + aNonceWordI;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 14086975808140927408U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10390516547834639800U;
            aOrbiterD = RotL64((aOrbiterD * 11441293212275890819U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18205555540941493267U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16967799565443938873U;
            aOrbiterA = RotL64((aOrbiterA * 3009081009044782443U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9209505304067579944U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 3522631966146762306U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 3441982898533162599U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8811497120829041188U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14707301680850257294U;
            aOrbiterC = RotL64((aOrbiterC * 11383709499376464085U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10080595991787801029U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6822892187784299166U;
            aOrbiterI = RotL64((aOrbiterI * 7417016898027778287U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1981637172055758689U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16463077485583119324U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2876782050665869121U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8383837717361569465U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2788511294985017326U;
            aOrbiterH = RotL64((aOrbiterH * 2809163242875130677U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 3529607472855930041U) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8850940802020173766U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7821450253655655943U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7469160295100147267U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16973986572163482061U;
            aOrbiterK = RotL64((aOrbiterK * 15660743778376905023U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12371372942863279718U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12098525148034303633U;
            aOrbiterJ = RotL64((aOrbiterJ * 11234127652230231751U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5138683482859889480U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3339283916456813609U;
            aOrbiterB = RotL64((aOrbiterB * 10975353228235695455U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 14U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 3U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 21U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 34U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 41U)) + aOrbiterK) + aNonceWordG);
            aWandererI = aWandererI + ((((RotL64(aScatter, 28U) + aOrbiterA) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterD, 13U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterK, 39U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 6U) + aOrbiterE) + RotL64(aOrbiterB, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterG, 53U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 18U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 52U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24445U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((aIndex + 27293U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(pSnow[((aIndex + 26872U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneA[((aIndex + 25284U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27294U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24208U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 50U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = (aWandererJ + RotL64(aCross, 43U)) + 17668251151213543491U;
            aOrbiterB = ((((aWandererH + RotL64(aIngress, 50U)) + RotL64(aCarry, 43U)) + 16101602509895104517U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 47U)) + 9083915270773304935U) + aNonceWordL;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 12810720730318214811U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 19U)) + 18113428002071925621U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 41U)) + 1582208899354109878U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 57U)) + 4180688104819188154U) + aNonceWordN;
            aOrbiterH = (aWandererE + RotL64(aScatter, 3U)) + 8954598189262820611U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 23U)) + 15360094153175355879U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 13U)) + 8383954114668216260U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 52U)) + RotL64(aCarry, 35U)) + 15626783326234049197U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10609978564404958066U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17656516608997517984U;
            aOrbiterA = RotL64((aOrbiterA * 4590620354119899777U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 760077259110786536U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 3597338735888033063U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 6548831472863517621U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4431777844935985157U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10710423172154671296U;
            aOrbiterE = RotL64((aOrbiterE * 16267496318491473315U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10240882795242085185U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7826053487019825891U;
            aOrbiterC = RotL64((aOrbiterC * 15053729937684375907U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9418883403715727353U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11507423614799075545U;
            aOrbiterG = RotL64((aOrbiterG * 16189463984557044693U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11545217316421066655U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 617921402135485341U;
            aOrbiterJ = RotL64((aOrbiterJ * 8182920764965471653U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14456933220749921009U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7990243583564535387U;
            aOrbiterI = RotL64((aOrbiterI * 5994900368027985469U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14023633125757654751U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11319146808574958827U;
            aOrbiterF = RotL64((aOrbiterF * 13676159969338309307U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14161653180846538446U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17993503892528842342U;
            aOrbiterH = RotL64((aOrbiterH * 12184170842617942651U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10449311783872638478U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17210495321003036773U;
            aOrbiterD = RotL64((aOrbiterD * 17591257107603354151U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14586515403314763393U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 17668251151213543491U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9367185933291003363U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + aNonceWordH);
            aWandererF = aWandererF + ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + aNonceWordB) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterD, 20U)) + aNonceWordA) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 54U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterK, 27U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterK, 41U)) + aNonceWordD);
            aWandererE = aWandererE + ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 44U) + RotL64(aOrbiterD, 48U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28572U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 28325U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 32111U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27434U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27381U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 27776U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneB[((aIndex + 30782U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 36U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (aWandererC + RotL64(aPrevious, 53U)) + 4068921616130916949U;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 12077715273915151726U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aScatter, 19U)) + 16047546802670596833U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 26U)) + 9690277462716999763U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 13U)) + 14484814700447992628U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 17089267243053958210U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 21U)) + 9138746214446211147U) + aNonceWordI;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 47U)) + 10181001536979097045U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 41U)) + 6657458969093373191U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 24U)) + RotL64(aCarry, 37U)) + 7515983477876590988U) + aNonceWordF;
            aOrbiterD = (aWandererE + RotL64(aCross, 37U)) + 3039935555863947600U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16209389224740851136U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 725253312098083182U;
            aOrbiterC = RotL64((aOrbiterC * 17535989492095522597U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 13307041115748941383U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7159572004825238263U;
            aOrbiterJ = RotL64((aOrbiterJ * 4855009895002398449U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12027236743251643820U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8717826175991286553U;
            aOrbiterA = RotL64((aOrbiterA * 1175614802543098451U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4769096034227659937U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11201226563992939616U;
            aOrbiterE = RotL64((aOrbiterE * 15595355978388159931U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17295978531215563256U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 11850923890626719833U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3854851059897397075U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14139441565288097706U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 988684899382304485U;
            aOrbiterD = RotL64((aOrbiterD * 11929090869999700891U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6159251276942253175U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4849529993914550651U;
            aOrbiterH = RotL64((aOrbiterH * 18240712676783671317U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6679745455842119497U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15838404437552215214U;
            aOrbiterF = RotL64((aOrbiterF * 17357853511591350887U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15853153471104458948U) + aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12542164757451566994U;
            aOrbiterK = RotL64((aOrbiterK * 12163611303899312043U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14304233464055838869U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4037999346933039765U;
            aOrbiterI = RotL64((aOrbiterI * 564236202758328407U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3582312827630995454U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4068921616130916949U;
            aOrbiterB = RotL64((aOrbiterB * 1527829107415867363U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 21U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 58U) + aOrbiterK) + RotL64(aOrbiterE, 37U)) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 10U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterA, 5U)) + aNonceWordM) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + aNonceWordE);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 23U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 3U)) + aOrbiterK) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 18U) + aOrbiterB) + RotL64(aOrbiterF, 44U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE533AE266E544175ULL + 0x818F5FD9AB0C0084ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBD8720175D74E92BULL + 0xD800BB8F57780C02ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA6DD0AB35F24E8B9ULL + 0xD2BA5C02F603B9A0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEAA32BC28281D745ULL + 0xEA1908911ECA1076ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9A810E725D065E39ULL + 0xEAF882F13E6B597EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE8E5D9E335B43FAFULL + 0x84413341F70633A8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD455DEE245F8C689ULL + 0x9D60F998B7338011ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE4B2A85EB890C113ULL + 0xC65AE2D7C7C1D67CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA6304A0B9B09D4C1ULL + 0xACEA99C44A49B4D2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDDD5E4E0869A99EDULL + 0x900E637CE7CF7ADEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD12DD2631FC96ECFULL + 0x97F79D8EE45CC43FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB10A791E0115D601ULL + 0xE855AF463A7EDC68ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x865142C0EB1C45B5ULL + 0xAFB38E18F3CA6753ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB8298197A3C25F11ULL + 0x9B2D19F215F50814ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA7ADE38E142875F1ULL + 0x98379FDE3B5C0701ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFD9DD1D86091518DULL + 0xA1033EF7EEF2BB02ULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 537U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 1388U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1632U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 5212U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((((aWandererK + RotL64(aCross, 56U)) + RotL64(aCarry, 47U)) + 8685374557928800912U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 23U)) + 3482312691892161229U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 6948130297389161165U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 5U)) + 5506385663788942690U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 29U)) + 17859982009307397161U) + aNonceWordJ;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 35U)) + 9178488809207094043U;
            aOrbiterG = (aWandererE + RotL64(aCross, 19U)) + 1835479501226057169U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 5368101733632614939U;
            aOrbiterB = (aWandererD + RotL64(aCross, 60U)) + 9050459666576835422U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9042186993119635078U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17528342580198295025U;
            aOrbiterJ = RotL64((aOrbiterJ * 14316671546614386775U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6495418332558436882U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8834495762667327342U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10783141541937645995U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4364314196965690905U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 6357485231062120459U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 289429584586504995U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3321488322626415347U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10817330671781848737U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15875919466358823335U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17974092279281611763U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2871472057292789157U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16104199340711015181U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 15187929795092006849U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13482063681546475923U;
            aOrbiterE = RotL64((aOrbiterE * 14466266308157364963U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 6232152545071397380U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17488906002621373262U;
            aOrbiterG = RotL64((aOrbiterG * 4719340606442742577U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12444819880507588549U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13808941689757772497U;
            aOrbiterB = RotL64((aOrbiterB * 6541360905282412317U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8049361354387692374U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7137831335606542401U;
            aOrbiterK = RotL64((aOrbiterK * 11022231291507235007U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 18U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + aNonceWordF);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterB, 10U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 5U)) + aOrbiterI) + aNonceWordP);
            aWandererG = aWandererG + ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterC, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 39U)) + aOrbiterE);
            aWandererH = aWandererH + (((((RotL64(aScatter, 46U) + aOrbiterK) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 43U)) + aNonceWordO) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 28U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9913U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 6804U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8920U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5801U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6584U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 42U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (aWandererD + RotL64(aIngress, 19U)) + 2177539223979303669U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 26U)) + 3962004686551521471U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aCross, 43U)) + 8457602312617147662U) + aNonceWordK;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 11U)) + 18011802451816510632U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 9046101759168876832U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 60U)) + 11135620637431969597U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 15913029940697999701U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 16304193109948135982U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 47U)) + 13208892298820080981U) + aNonceWordA;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4182377898949419225U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13970137023071326151U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9075061559681739865U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8402396284835248583U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8859190834060657829U;
            aOrbiterB = RotL64((aOrbiterB * 13552418608113716117U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 9760005337757990392U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14108277760135744897U;
            aOrbiterA = RotL64((aOrbiterA * 4474681104256093885U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12226316121949012350U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3456392186754113960U;
            aOrbiterF = RotL64((aOrbiterF * 8704729827929941215U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5004087958637038973U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7176881295123125567U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15272157962928021009U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10889800478505074438U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13728832441482547824U;
            aOrbiterK = RotL64((aOrbiterK * 17588477761978646139U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17345665880706866772U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 301139993853297566U;
            aOrbiterI = RotL64((aOrbiterI * 5812445396758354505U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2061389844760610160U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 13631862266139238355U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 143613352104722701U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10767186080827509622U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4893486019456886013U;
            aOrbiterH = RotL64((aOrbiterH * 5194746459545610901U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 40U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 28U) + RotL64(aOrbiterF, 53U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 36U)) + aOrbiterD) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterI, 3U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 42U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 23U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 40U) + RotL64(aOrbiterH, 11U)) + aOrbiterI) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 13621U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 12377U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 12543U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15039U)) & S_BLOCK1], 42U) ^ RotL64(aFireLaneC[((aIndex + 11040U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 47U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 4U)) + RotL64(aCarry, 19U)) + 4970414922752555648U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 11U)) + 9462756592787669327U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aIngress, 47U)) + 3948790686662213095U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 57U)) + 14542857212241578311U) + aNonceWordA;
            aOrbiterI = (((aWandererA + RotL64(aCross, 38U)) + RotL64(aCarry, 27U)) + 3387479009827029547U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 1411421370057797877U) + aNonceWordF;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 21U)) + 16894451466895681236U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 53U)) + 12727136462290223542U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 29U)) + 4625389198191960525U) + aNonceWordL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3471881403786164913U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6433115856048534831U;
            aOrbiterH = RotL64((aOrbiterH * 9363233870194144053U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9825592965466157982U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1553125767261293088U;
            aOrbiterJ = RotL64((aOrbiterJ * 411535191177308781U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9951616357109647617U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11231080382787286889U;
            aOrbiterG = RotL64((aOrbiterG * 14024961994986659187U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13419663264017317947U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 4835055642466215566U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 17898065852351759171U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14558747666410946768U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13120938960926874504U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5681766019285559739U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11910501376797343986U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15074100100781785300U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 228976960937473851U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12415377930578091821U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14882039078390681802U;
            aOrbiterI = RotL64((aOrbiterI * 13855446647753150713U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 8094338361713756895U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5478280604704108822U;
            aOrbiterF = RotL64((aOrbiterF * 18062931724700600993U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6977017654546871841U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4131602217285988962U;
            aOrbiterC = RotL64((aOrbiterC * 11865422227883712419U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterB, 11U)) + aNonceWordD);
            aWandererG = aWandererG + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 46U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterF, 41U));
            aWandererA = aWandererA + ((RotL64(aCross, 26U) + aOrbiterC) + RotL64(aOrbiterF, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterG, 29U));
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 57U)) + aOrbiterE) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 34U) + RotL64(aOrbiterH, 34U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterC, 3U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21374U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 19560U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19734U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20904U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((aIndex + 21717U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 51U)) + (RotL64(aCarry, 4U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 43U)) + 17936518874386450467U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 19U)) + 13722737841589910344U) + aNonceWordB;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 11774969167948715796U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 56U)) + RotL64(aCarry, 47U)) + 3640101505680493777U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 13U)) + 1369495382725650822U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aPrevious, 35U)) + 11827310354654653345U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 3U)) + 186037671377175394U) + aNonceWordA;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 52U)) + 11428829344234627340U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aPrevious, 47U)) + 2275016369870029068U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15471646673734798328U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12172082573115640145U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 9629417882787847753U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6626736341348283154U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12220614992483863623U;
            aOrbiterJ = RotL64((aOrbiterJ * 8137086205714097487U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13157102324253760215U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4143587482368093601U;
            aOrbiterG = RotL64((aOrbiterG * 5060677690991506895U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11007575246013796426U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11721585930088637162U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 15009627907125738519U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5720789204450196217U) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3094696226821431648U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4412033981712165541U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14675830108100986773U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9444071495289719645U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10983136361953366557U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5106753847015199956U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7585421898593510010U;
            aOrbiterI = RotL64((aOrbiterI * 140996914192351011U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11746948407655524690U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16336323220286344483U;
            aOrbiterH = RotL64((aOrbiterH * 6590417628835864497U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8030445186765781136U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 276034088015165891U;
            aOrbiterD = RotL64((aOrbiterD * 7626025612710225099U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 58U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 12U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 14U) + aOrbiterC) + RotL64(aOrbiterB, 21U));
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterC) + aNonceWordI) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterC, 5U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterG, 58U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterH, 39U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 26749U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24114U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24063U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25986U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 42U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (aWandererD + RotL64(aPrevious, 47U)) + 2786079456995203065U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 7237256119153857253U) + aNonceWordO;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 58U)) + RotL64(aCarry, 39U)) + 9310834010563647604U) + aNonceWordB;
            aOrbiterF = ((((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 17361734905706517877U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aWandererK + RotL64(aIngress, 29U)) + 15837111231884647451U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 51U)) + 18065431964418026445U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 23U)) + 3029123922999952652U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 37U)) + 5166926595573507837U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 14U)) + 1918425684273807598U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4724551751012661440U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 1818014487579644390U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 14904092108647864911U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6670090372241084216U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8485757110007268693U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11876760095108618363U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4928130251509514742U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2528788422725346792U;
            aOrbiterJ = RotL64((aOrbiterJ * 1855982047967756661U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2860387120895147503U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12927802338151379368U;
            aOrbiterK = RotL64((aOrbiterK * 8876144125458603029U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 18029699867733207083U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13361836994951253312U;
            aOrbiterC = RotL64((aOrbiterC * 5349767426256597073U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11957294454794128079U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3755417922063414648U;
            aOrbiterD = RotL64((aOrbiterD * 13896364063651241401U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 18001157153447913032U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16214145724690286854U;
            aOrbiterF = RotL64((aOrbiterF * 5874139687703360515U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3860958772090975562U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12395621524459640173U;
            aOrbiterE = RotL64((aOrbiterE * 722817135977510161U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3402035664910754484U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2139099117325745602U;
            aOrbiterA = RotL64((aOrbiterA * 14008983756425796029U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 40U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 4U) + aOrbiterE) + RotL64(aOrbiterK, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterE, 30U)) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterK, 13U)) + aNonceWordP) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 3U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 18U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ) + aNonceWordD);
            aWandererE = aWandererE + ((RotL64(aPrevious, 28U) + RotL64(aOrbiterA, 23U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 32446U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28822U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29381U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31606U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = (((aWandererF + RotL64(aIngress, 18U)) + RotL64(aCarry, 57U)) + 17074147006464019918U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aScatter, 43U)) + 10559516626129419928U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 57U)) + 13280363679503946221U) + aNonceWordI;
            aOrbiterF = ((aWandererE + RotL64(aCross, 5U)) + 17657115422132457413U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aPrevious, 27U)) + 13325837013304973008U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 53U)) + 3059707750486106037U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 47U)) + 4529045702503050852U) + aNonceWordH;
            aOrbiterG = (((aWandererB + RotL64(aCross, 22U)) + RotL64(aCarry, 39U)) + 10726578475550904292U) + aNonceWordL;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 14832537837996659885U) + aNonceWordP;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 220094417441809246U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15343130035105342194U;
            aOrbiterD = RotL64((aOrbiterD * 7984652435043810845U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 16592263353426409884U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15649290906447931918U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8405875177836650731U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11437410545843708269U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5859769136073011444U;
            aOrbiterF = RotL64((aOrbiterF * 1065016088086441107U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15188064100307340341U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4367466521843260049U;
            aOrbiterJ = RotL64((aOrbiterJ * 15916715854192820923U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8482617283860566845U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2585745804937342972U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 8267269625632139809U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1687641344403425541U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13667916445979421400U;
            aOrbiterB = RotL64((aOrbiterB * 8191322670355590027U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7684258716388029228U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14764266202380443369U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1746254773647650741U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12685190466981675661U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9958374400222383893U;
            aOrbiterH = RotL64((aOrbiterH * 12696606920219838929U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 1352584794098160330U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16057453941015251708U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 6051546505117202495U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 4U) + RotL64(aOrbiterC, 60U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 27U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 53U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 39U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + aNonceWordM);
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterA, 18U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterE, 23U)) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterB) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9117462825A6321BULL + 0xE51D9094DEC6FDD5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBFAB76F97CAD5D33ULL + 0xDCA4ACB1631A985AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB3E13E3426B223EBULL + 0xF7AF159E4F9EC495ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC5D434AFA3141037ULL + 0x92256662D169796AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x873245883776F9EDULL + 0x976960C222E9E2DFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x878FB660CA46B149ULL + 0xA2E13C444AF29684ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEC6D9CB6CB50C9CBULL + 0xCE6AFBE47FBD8BEBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE8F25AB96182983DULL + 0xBB5D28308EAC4382ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAB527B23C7EB0515ULL + 0x951A5871F6C40081ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF5E219F830689F83ULL + 0xCE990C74D1AAF8D3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDE877B9F5B3B364FULL + 0xCD48BA079368573DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCF0A2F61A4702341ULL + 0xE77E57445978AC02ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBF66BD4AF7FFF653ULL + 0xB5BC637E3009CCF3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB6081E8532DDB67FULL + 0xCBD9BB0376F9E4F1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDADF0E51A4FF9197ULL + 0xCE0C882EAA9DBA48ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x83E83DCE06A9A525ULL + 0x9E22F734908CA8EEULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6096U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 3187U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 6421U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7317U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6989U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3543U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 27U)) + (RotL64(aCarry, 44U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = ((aWandererD + RotL64(aScatter, 41U)) + 3561491146322798260U) + aNonceWordB;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 58U)) + 7075025056181885339U;
            aOrbiterF = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 9230910887904171613U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 4119781172609908917U) + aNonceWordE;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 17155609083870983149U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2423018561430181695U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12957280305617615744U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 17696410107705645631U), 5U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 2461704174772065813U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7907123257849391997U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9416171962847312179U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7257868138318960007U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16425903703085702285U;
            aOrbiterJ = RotL64((aOrbiterJ * 7996935869077231999U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2990822664594079467U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5654819006718953817U;
            aOrbiterB = RotL64((aOrbiterB * 4465096036756887801U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12183676471235678779U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15026286960542123922U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17199049329995315279U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 11U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 52U) + RotL64(aOrbiterE, 60U)) + aOrbiterF) + aNonceWordH);
            aWandererA = aWandererA + ((((RotL64(aCross, 39U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 19U)) + aNonceWordA);
            aWandererK = aWandererK + (((((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 57U)) + aNonceWordN) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 56U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12196U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 10951U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 15944U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9665U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16299U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15930U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13442U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aIngress, 11U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = ((aWandererK + RotL64(aIngress, 48U)) + RotL64(aCarry, 43U)) + 15910560457440369082U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 17953072986407436888U) + aNonceWordH;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 3U)) + 15446940721193538669U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 3020785262774422009U) + aNonceWordN;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 57U)) + 7001288645424994404U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13385250665458462689U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4841895644623005949U;
            aOrbiterB = RotL64((aOrbiterB * 3898487345974386945U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13053476783239482065U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 641996979335975244U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 3697673197256549833U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16211238020928688299U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12715448751323279480U;
            aOrbiterD = RotL64((aOrbiterD * 2116880429675303291U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17784406727699995290U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16626339815786580778U;
            aOrbiterI = RotL64((aOrbiterI * 13940754474750138041U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 9035070625716345139U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6085848172494001945U;
            aOrbiterC = RotL64((aOrbiterC * 10405728912339646693U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 29U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterD, 48U)) + RotL64(aCarry, 5U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + aNonceWordK);
            aWandererH = aWandererH + (((((RotL64(aIngress, 22U) + aOrbiterD) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 51U)) + aNonceWordL) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterI, 37U)) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19281U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 16947U)) & S_BLOCK1], 44U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 17294U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 24096U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18906U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16526U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22979U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 23U)) + 5573188770530340913U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 1431772230889897111U) + aNonceWordJ;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 29U)) + 4809192776429682319U) + aNonceWordN;
            aOrbiterG = (((aWandererI + RotL64(aCross, 11U)) + 5576603692574369341U) + aOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 2720143226007220386U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17220328778565331629U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9629485808442089423U;
            aOrbiterC = RotL64((aOrbiterC * 18349580416082045015U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1136998437010390983U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11893390497814523841U;
            aOrbiterK = RotL64((aOrbiterK * 5329621622743089531U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1764986431917532370U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1741014798007010376U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13414914086049500731U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 12221368453236547044U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7694538641172350430U;
            aOrbiterH = RotL64((aOrbiterH * 8439120733670016501U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17472344518811560603U) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3308740700728172984U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 15290400462887712083U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 58U)) + aOrbiterK) + aNonceWordP);
            aWandererD = aWandererD + (((((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 53U)) + aNonceWordC) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 21U)) + aOrbiterG) + aNonceWordG) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 58U) + RotL64(aOrbiterA, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28721U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 27056U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 30090U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneC[((aIndex + 29278U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28911U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28764U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 29573U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 48U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (aWandererD + RotL64(aPrevious, 39U)) + 3650233661228036955U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 14U)) + RotL64(aCarry, 11U)) + 11607036400067735729U;
            aOrbiterH = ((((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 3899614406903883035U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 57U)) + 8159156925629965143U) + aNonceWordK;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 7148903913967261270U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9161665622287517848U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2981535013474059469U;
            aOrbiterH = RotL64((aOrbiterH * 4434815231517266013U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15812469008200319549U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14687469489893270300U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14142363399696670451U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 6025209349511417063U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 12964750392311112676U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 12955480283032701843U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6572355895765394340U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3542300121890027981U;
            aOrbiterA = RotL64((aOrbiterA * 11201491178181273935U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6477175684045398359U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1081388388827929314U;
            aOrbiterB = RotL64((aOrbiterB * 8752188637514143529U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 11U)) + aOrbiterH) + aNonceWordC);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 29U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 60U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aScatter, 50U) + RotL64(aOrbiterB, 51U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aNonceWordG) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterK, 37U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE7F4D239FABDE0C1ULL + 0x9F5EC919ABF0D811ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA0BFA298581E1213ULL + 0x870837F80A45258FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x90B15A9B5410E84FULL + 0xBBCACA78FD0DB3DBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC2712672D0EAE33FULL + 0xDF96EDD599F0DD2AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x93E3DFFADF150905ULL + 0xA291E30171360752ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE1E1B3E640B2D057ULL + 0xB23601C09CE00A67ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF8B7443B28F9BF9FULL + 0xEE139E96A64DC91BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFDEAD22D29167CF1ULL + 0xEFFDAFC27F3B9C4AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC06CC20834662D59ULL + 0xF4FA6472E930D3C7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB5DF10C34956A38BULL + 0xB18D0F573287933CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA702156D90B2B5FFULL + 0x808F745D597D99AEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCF48115A46D2221DULL + 0xDA58AA9E3E7885A4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x988F883F59EA1F15ULL + 0xED120B85FEF40061ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAF1B8326EA68F055ULL + 0xDC052211C513CD06ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC85AC8B90464EF05ULL + 0xC32C7E96FFCAFCF2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBDEAF31ADB87C643ULL + 0x84A890D0C9D17C87ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7778U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 1457U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7212U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6312U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3867U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 7371U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 54U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 58U)) + RotL64(aCarry, 3U)) + 2225397913940961213U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 11U)) + 8342544893601343643U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aPrevious, 43U)) + 162922186381417187U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 11660218373710972210U) + aNonceWordD;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 14909034764605802354U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 29U)) + 16776955237009701511U) + aNonceWordO;
            aOrbiterB = (aWandererC + RotL64(aScatter, 19U)) + 5834487809188925253U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1498492772767040320U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4161765458781579617U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15535994410289065281U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10511923076962447765U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8575954471692620021U;
            aOrbiterJ = RotL64((aOrbiterJ * 12526744988828982731U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6536325446331340573U) + aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1790628986900286346U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 5262997114200816715U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2623814807619278590U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11676970995834706612U;
            aOrbiterC = RotL64((aOrbiterC * 10057461115132434901U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13836786354224256591U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6293096163612129260U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 8977954126326217153U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4271144764978661248U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15938494256992560202U;
            aOrbiterA = RotL64((aOrbiterA * 10004841288382726739U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11038155227307702976U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12408749795071243930U;
            aOrbiterB = RotL64((aOrbiterB * 5527720475032868855U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 4U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 22U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterE, 51U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterE, 43U)) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 3U)) + aOrbiterE) + aNonceWordM);
            aWandererE = aWandererE + ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13900U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 10117U)) & S_BLOCK1], 10U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 11810U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12432U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16046U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15613U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15753U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 5U)) ^ (RotL64(aIngress, 43U) + RotL64(aCarry, 30U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 23U)) + 13296600294247799698U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 35U)) + 5818503518080877515U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aIngress, 13U)) + 6735784238734173597U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 47U)) + 7368398209488856201U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 35U)) + 961734029066455638U) + aNonceWordI;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 797011946660892011U) + aNonceWordN;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 4U)) + RotL64(aCarry, 19U)) + 12841876018396622350U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 16213253970483895623U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15186950557113470375U;
            aOrbiterI = RotL64((aOrbiterI * 4647470430467908107U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5117930310827477341U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12265429373166094162U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 1522823535151532249U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13920531346698601568U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14695405206998211456U;
            aOrbiterF = RotL64((aOrbiterF * 13950964363414164279U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7851960904825938443U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 9501511171732550190U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5614164120361489613U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5663365182245722077U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9607860124321315555U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3461820361914280601U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18171052650586819280U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3442698321538580861U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 6317525514963824829U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1491052813469258970U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3956599824067616133U;
            aOrbiterD = RotL64((aOrbiterD * 2928600779267623085U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterF, 28U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + aNonceWordG);
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 47U)) + aOrbiterA) + aNonceWordD);
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterC, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21362U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 17081U)) & S_BLOCK1], 44U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 17189U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 19374U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22646U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19474U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 17939U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 54U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 16016931609704150191U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 29U)) + 14511433515861302636U) + aNonceWordJ;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 11691237442613269593U;
            aOrbiterF = (aWandererC + RotL64(aCross, 35U)) + 16383220587320484649U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 57U)) + 14293015313458219868U) + aNonceWordC;
            aOrbiterK = (((aWandererG + RotL64(aCross, 48U)) + RotL64(aCarry, 5U)) + 4407695248205526670U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 5U)) + 1158323195324398372U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6577683409653864555U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 171080079472863843U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 3063978974927752653U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5766333425872228205U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16173508656917582960U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12187968015372936695U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11781450063402219202U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 13033139686637576694U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 4331137994135472025U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4006310759400926020U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13156817947481574467U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 563189239835001483U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12791290558893516411U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 989729955679243234U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 8757228712495095017U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 838379839663022790U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2830743864262313606U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10173947177104802797U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2146646527331684652U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4629168181742174906U;
            aOrbiterA = RotL64((aOrbiterA * 9046124907945045131U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 27U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterF, 42U)) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterI, 57U)) + aNonceWordB);
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 51U)) + aOrbiterA) + aNonceWordD) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterD, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30428U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 27530U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 28165U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 30230U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29183U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25760U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 29605U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 44U) ^ RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = ((aWandererI + RotL64(aCross, 3U)) + 16922357079016918108U) + aNonceWordA;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 11771749797137599131U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 4635668433708036077U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 51U)) + 15827952719230577008U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((aWandererG + RotL64(aCross, 43U)) + 1495675306110023086U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 27U)) + 7294835466949728365U) + aNonceWordH;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 18U)) + RotL64(aCarry, 57U)) + 179122461212041978U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 545981421632236251U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 15338259639814630535U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 14895421566334357871U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12924313840290895215U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17846785921286020610U;
            aOrbiterA = RotL64((aOrbiterA * 18309347016029917133U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5721472794107057875U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16359630793856870319U;
            aOrbiterG = RotL64((aOrbiterG * 14186771515526698907U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10614102110239037308U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16421992251278236531U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2561232904676068089U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8668149834861244963U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 12699331834360948734U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 2249360824172616357U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4470693178142950471U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 526000656022724741U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16688501462334673493U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6880246132270094141U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7126466778855297013U;
            aOrbiterE = RotL64((aOrbiterE * 5692237926830293205U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterE, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 27U)) + aOrbiterB) + aNonceWordE);
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 53U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 12U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterC, 41U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 20U) + aOrbiterD) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 36U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBCAD0CBE87794679ULL + 0xA8A0DBCCDD02FB75ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB87694534C6F6941ULL + 0xC627BC4C4B07F6EAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC47100D091F9E3BDULL + 0xC84DB5F17AD9A4F8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9C49D9F58E9E4387ULL + 0x94FAFEA69FEAE54AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8198ED8CFC57AE17ULL + 0xA0E1F281B4C574F6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x80FA85535A1C00FBULL + 0xA3BB4708BE06D164ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x865288E58D5857F5ULL + 0x8411B65712DC5654ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC6621BE76C18DDB9ULL + 0xE12E762BB8979035ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD7C19F1311434683ULL + 0x945D25734BEB311AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBE478813570876E9ULL + 0xD6401E44B2C1915BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBED9D8A26B3205FDULL + 0xEEDE2E294C2A18C4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE0530A8EFB453A71ULL + 0xBBA462BA9D5493E9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBC61FB2DFAE7B66FULL + 0xA956961A85808315ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD2EB88608BC524CDULL + 0xA8A084ECFD99E704ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE73C08243C0CEB9FULL + 0xD8FF2915B722D899ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFAA3691D1D580FC3ULL + 0xF93C289999AEF117ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4698U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 411U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 2558U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1609U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((aIndex + 1506U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 12U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererA + RotL64(aCross, 35U)) + 17225673071833726819U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 13U)) + 10301458382103627331U) + aNonceWordA;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 43U)) + 3960233050857362414U;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 11U)) + 17768665685046605837U) + aNonceWordK;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 14471018461213959767U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 5U)) + 10730597892721340453U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 19U)) + 14863394003122760542U) + aNonceWordB;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9948587274816688296U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3573569431435100993U;
            aOrbiterC = RotL64((aOrbiterC * 2303922230056523077U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8153670675740450590U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16438856577722561424U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4689247488336908827U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15765587867581925041U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1082039522061775213U;
            aOrbiterJ = RotL64((aOrbiterJ * 17023740047246402641U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4202521649260798876U) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15877659681260461141U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11369910758551088173U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2551560426129646123U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3005102326163906320U;
            aOrbiterH = RotL64((aOrbiterH * 4241583192662435107U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1675501058857208089U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12774812270956702043U;
            aOrbiterE = RotL64((aOrbiterE * 5488437008504905105U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1044886020922563597U) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4857445127457225171U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13223560654459705259U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 36U) + aOrbiterE) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 37U)) + aOrbiterD) + aNonceWordE);
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 29U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterH, 29U)) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 44U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 28U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 5865U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 7609U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8224U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5866U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5902U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 8157U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 13687218104610230596U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 53U)) + 6841550124960692709U) + aNonceWordE;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 17418968668458764131U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 47U)) + 8303537912696948204U) + aNonceWordK;
            aOrbiterF = ((aWandererG + RotL64(aCross, 23U)) + 12376614417285936537U) + aNonceWordD;
            aOrbiterA = (aWandererI + RotL64(aScatter, 29U)) + 14215749063579232654U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 53U)) + 4111736931433665347U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11250375934571631522U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5367367837773331275U;
            aOrbiterD = RotL64((aOrbiterD * 7262723007545807179U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15514089192382674434U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 1475991716685034960U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 17720681295551650891U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 5531622777788629748U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8363822215908303335U;
            aOrbiterB = RotL64((aOrbiterB * 17850203366840994883U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3741256932685720414U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11634667238062155772U;
            aOrbiterK = RotL64((aOrbiterK * 15925089729784547403U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 18180546911210417155U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5123234656838556335U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15362857462853398025U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11215734271189250284U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16863747802158398092U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1828035970246160023U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9859050606636646323U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9331300036643654675U;
            aOrbiterH = RotL64((aOrbiterH * 2502263410556166281U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 4U) + aOrbiterH) + RotL64(aOrbiterF, 41U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + aNonceWordN);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterK, 12U)) + aNonceWordH) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + aNonceWordI);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 51U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 21U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 15276U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 15471U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 13967U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15653U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneA[((aIndex + 13704U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 23U)) + (RotL64(aCarry, 3U) + RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 8375305456876489425U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 11U)) + 16193562952772453047U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 18088652458594816223U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 27U)) + 767344788620249944U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 47U)) + 7705194930396368752U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 41U)) + 3829736891311272834U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aIngress, 34U)) + RotL64(aCarry, 51U)) + 9881681671347640061U) + aNonceWordN;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1721196560190164264U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3002652618388454213U;
            aOrbiterF = RotL64((aOrbiterF * 15289749311593032657U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9811621464004005202U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5652598941069986530U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4797973356708091621U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 6250499348327316328U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16025054277615264530U;
            aOrbiterG = RotL64((aOrbiterG * 16446892258704281903U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13800298546867243172U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 12256104592865905782U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 16983140179497142713U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17817225416918329229U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 17738671327352776217U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 393488251327705063U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6816031224188400541U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16989563985059237014U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8677884225771717797U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16891524847268207549U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1833508573940405571U;
            aOrbiterD = RotL64((aOrbiterD * 9709196587703979539U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 50U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 23U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 60U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF) + aNonceWordD);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + aNonceWordM) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20560U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 19245U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20670U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19185U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16384U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 12U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = (((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 2330952702412094686U) + aNonceWordE;
            aOrbiterI = ((aWandererG + RotL64(aCross, 19U)) + 7820188225935060799U) + aNonceWordM;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 9347644591709839145U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 47U)) + 2288624878446846870U) + aNonceWordH;
            aOrbiterA = (aWandererH + RotL64(aScatter, 12U)) + 9358977729492824128U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 29U)) + 1858511275052455039U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 13715478509322292552U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16413396625604260455U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 17714322215518432705U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 1904184102419934333U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 16188315436202861122U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5564445841368207813U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14125834616162835983U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13717068949900594673U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14143659432287313765U;
            aOrbiterE = RotL64((aOrbiterE * 17281441046722262917U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 5729546141908425670U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4297827922736712074U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13631630436759768885U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 829520109395163673U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 11547160328525174295U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4759690159673049775U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2907177944512117206U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 11100346409065275671U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 17927994356809011637U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1344592529249949068U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6470438516791143572U;
            aOrbiterA = RotL64((aOrbiterA * 13339390828725370475U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 20U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterE, 20U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 5U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 35U)) + aOrbiterE) + aNonceWordN) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 28U) + RotL64(aOrbiterI, 11U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterB, 27U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 25236U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((aIndex + 24134U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24802U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 25398U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 5U)) + 439898681482066326U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 35U)) + 17362083676671776094U) + aNonceWordO;
            aOrbiterF = ((aWandererA + RotL64(aCross, 11U)) + 6418499837265155024U) + aNonceWordG;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 48U)) + RotL64(aCarry, 13U)) + 17262244253027454972U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aPrevious, 41U)) + 2382066162993139503U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 14345808395587174135U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 7534743166385552851U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16994453324688523966U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7079553728544045092U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 10104892188895367489U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3562822704508440641U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13990892681975857821U;
            aOrbiterA = RotL64((aOrbiterA * 8352929306654078795U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1796728922368577238U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 6605161260520067178U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8147537646591674091U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 13994083795942328918U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6144523182899107711U;
            aOrbiterI = RotL64((aOrbiterI * 4153879991344611283U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12247462325297436642U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1065809332002012789U;
            aOrbiterE = RotL64((aOrbiterE * 5496601177032953251U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 10147919864511540753U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17138553441127273354U;
            aOrbiterC = RotL64((aOrbiterC * 5773875596275267871U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 2653924016109573974U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 6254416952351699582U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 12756861659704947257U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 50U) + aOrbiterC) + RotL64(aOrbiterE, 29U)) + aNonceWordL);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterG, 46U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterA, 23U)) + aNonceWordP);
            aWandererC = aWandererC + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + aNonceWordH) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 28U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30052U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30981U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31350U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30124U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 56U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 5295352595333316211U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 57U)) + 2341795367042042605U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 37U)) + 10122175780504033663U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 30U)) + RotL64(aCarry, 21U)) + 10084612804696198554U) + aNonceWordE;
            aOrbiterB = (aWandererB + RotL64(aIngress, 23U)) + 16470424309851045971U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 13U)) + 656016130975227994U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 15313268829659834317U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3795220914993923394U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14044442220988813825U;
            aOrbiterJ = RotL64((aOrbiterJ * 3270650852546606835U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3804224626734584802U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 7980006306010255693U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 13958505239726088561U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 13746830564584711549U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11852212099729274845U;
            aOrbiterA = RotL64((aOrbiterA * 2164880979318247855U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9083223471018084847U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13706723820703853346U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11361854103656219887U), 29U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 1713819986642275223U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1382000168233902914U;
            aOrbiterI = RotL64((aOrbiterI * 3894160765130198157U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4540474625764565485U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 1756168174375757220U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12739160208010092017U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1409297070183609309U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6082750101445444357U;
            aOrbiterC = RotL64((aOrbiterC * 17438740230251860935U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 51U)) + aNonceWordH) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + aNonceWordD) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 13U)) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterD, 43U)) + aNonceWordJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 48U) + RotL64(aOrbiterD, 50U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 23U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterC, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA4DAC94DFB846707ULL + 0xD010F4145BC649D7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x99DA87A50A35C74BULL + 0xA1B0C09A1A09C1ECULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8D76098F44BF9ED9ULL + 0xB92BA0009C0D2184ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCE1439ED7095E14FULL + 0xCF1A2333AA822AD9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x92B13110BE8109BBULL + 0xD3DF7A30E2867B4FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x928E5F0A162BD6D3ULL + 0xA0FEA825D90B9E58ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x90D2848D616E972DULL + 0xF71C3B692E9E19E5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFF3104F231F7AE93ULL + 0x85E445F1D2633917ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA30F563730842CFFULL + 0xAE199ACB39CC75AAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x98F7869A9594387DULL + 0xE1E4C6AEBB2983C5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEE20448F45B451ADULL + 0xBFDB271168997ED2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBAA479A495E2979DULL + 0x81989C28EFF25CD1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE92F407F15D4E731ULL + 0xD3F995B938306EE4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC97C9D8AF1F347FDULL + 0xE819978C73059B44ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDDE8DC790B1B7093ULL + 0xFE561E65DB1A138DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCCCB196168A7ED6FULL + 0x9FA79E6D931437ADULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4958U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 2572U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3926U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5006U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8049U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 7898U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 29U) ^ RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (aWandererE + RotL64(aScatter, 23U)) + 1898718075389870739U;
            aOrbiterE = (aWandererD + RotL64(aCross, 34U)) + 5631794889237247403U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 18219714659484524607U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 39U)) + 15419581386225732921U) + aNonceWordK;
            aOrbiterH = ((((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 9125575431710198210U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererG + RotL64(aIngress, 36U)) + 12205871520544965505U;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 7617534300497343422U) + aNonceWordH;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 47U)) + 18017579105368135814U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 27U)) + 10693882161946020042U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 11U)) + 11669615701700895306U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 19U)) + 11045110212889232165U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18019107802806469913U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12315940560472528716U;
            aOrbiterC = RotL64((aOrbiterC * 4505122470351404065U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4899009736070044310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17412253404253730364U;
            aOrbiterH = RotL64((aOrbiterH * 10791901166391946485U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4826286251927854181U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4523455921321845084U;
            aOrbiterE = RotL64((aOrbiterE * 14534103906736598099U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4132514462154182215U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 7164745605985109269U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14107325508977225261U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6297434295807635654U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8813887638672996646U;
            aOrbiterJ = RotL64((aOrbiterJ * 17495632530773158201U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 11086381278955626084U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5660733992573928887U;
            aOrbiterF = RotL64((aOrbiterF * 11248164458720777889U), 21U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 14851044686208609882U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12707776386060264479U;
            aOrbiterI = RotL64((aOrbiterI * 4470919091467313071U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11508023384209716657U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11752973809740920034U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 10212754472298834769U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16746821150860017820U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9659421716296641396U;
            aOrbiterK = RotL64((aOrbiterK * 7530071874978553673U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3192309064305104593U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11409078048681398061U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14991409124701807765U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 315359495275427324U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1898718075389870739U;
            aOrbiterG = RotL64((aOrbiterG * 13126661894614781343U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 36U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 13U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 30U) + aOrbiterJ) + RotL64(aOrbiterA, 11U));
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 53U)) + aOrbiterH) + aNonceWordM) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 42U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterK, 23U));
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 40U)) + aOrbiterE) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 22U) + aOrbiterG) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10499U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 14842U)) & S_BLOCK1], 46U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9312U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 15138U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10633U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10402U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11841U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aIngress, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 17470880031634374199U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 50U)) + RotL64(aCarry, 37U)) + 757565846006937746U) + aNonceWordE;
            aOrbiterI = (aWandererK + RotL64(aScatter, 11U)) + 9419282475801345674U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 21U)) + 2014248014107898196U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 23U)) + 15113928519446490441U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 35U)) + 7346126964886259935U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 5594123113093162359U;
            aOrbiterG = (aWandererD + RotL64(aCross, 43U)) + 5659237263369402005U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 40U)) + 11565709683423969703U) + aNonceWordH;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 19U)) + 16782863743534856287U) + aNonceWordL;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 3U)) + 13499100900072115907U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11414447651044205242U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7545993795121430538U;
            aOrbiterI = RotL64((aOrbiterI * 10758488381206257261U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11778229237616454988U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2544793391976514665U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4021060413798523299U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9972156716619459164U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17651030383827445664U;
            aOrbiterC = RotL64((aOrbiterC * 6742914240706775487U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 17439147296849134543U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10021926927948343656U;
            aOrbiterH = RotL64((aOrbiterH * 18139540407315440909U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9309867875882669289U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14951424455944346337U;
            aOrbiterD = RotL64((aOrbiterD * 10569523948169951309U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2166343974068770659U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11386993629011562026U;
            aOrbiterB = RotL64((aOrbiterB * 3091639433512536097U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5747849744680120960U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 4019290369160113026U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 5567515306039646735U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3820540009554769592U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8210747198363020939U;
            aOrbiterA = RotL64((aOrbiterA * 16215133106542452509U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3006494852696036003U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2736305345451919450U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11993452696344358247U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6148431711118275178U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6986633012691940738U;
            aOrbiterJ = RotL64((aOrbiterJ * 15672039482523804893U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7837859154831245165U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17470880031634374199U;
            aOrbiterG = RotL64((aOrbiterG * 2153299273348512243U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 42U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 38U)) + aOrbiterE);
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 51U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 48U) + aOrbiterA) + RotL64(aOrbiterJ, 5U));
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterC, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterE, 3U));
            aWandererC = aWandererC + ((((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 23U)) + aOrbiterH) + aNonceWordI);
            aWandererJ = aWandererJ + ((RotL64(aCross, 60U) + RotL64(aOrbiterF, 30U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterC, 27U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 53U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18660U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 19427U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 20330U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 21808U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20927U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20000U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21859U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 47U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 1557680213571812384U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 34U)) + RotL64(aCarry, 47U)) + 7387349725778021121U) + aNonceWordG;
            aOrbiterA = (aWandererI + RotL64(aScatter, 5U)) + 15379264067601586976U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 3730195724576043708U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aScatter, 43U)) + 9637070085323827066U) + aNonceWordI;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 47U)) + 1170865717363676184U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 53U)) + 2750833653175252030U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 57U)) + 15118992811225568305U) + aNonceWordF;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 60U)) + 4974092922102988451U;
            aOrbiterB = (aWandererD + RotL64(aCross, 19U)) + 10625719096296719514U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 23U)) + 855167122475471865U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11322911068958340262U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4334591909425429835U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10059025861172038183U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 14263701737208936392U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 678723206735649084U;
            aOrbiterF = RotL64((aOrbiterF * 10823239851733632227U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 15652053114252065230U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1705225940224061401U;
            aOrbiterC = RotL64((aOrbiterC * 3626023093533713579U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6826394665732900206U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11902946775066981141U;
            aOrbiterE = RotL64((aOrbiterE * 18300629262162694137U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9802212958998591310U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14001358545610206524U;
            aOrbiterB = RotL64((aOrbiterB * 13172645840788327099U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 4299184726135884309U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7288757011999872416U;
            aOrbiterK = RotL64((aOrbiterK * 16806027820468277393U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 233801262480580205U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14208660347238680268U;
            aOrbiterD = RotL64((aOrbiterD * 6299693448313154603U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9217797359740446104U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 18165073197136050838U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11677479094709512887U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9101905235436427482U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2884224555227870272U;
            aOrbiterG = RotL64((aOrbiterG * 12085235281782370391U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13118509728421714433U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1385390888603164704U;
            aOrbiterH = RotL64((aOrbiterH * 6927424835779289199U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9621084561183039538U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1557680213571812384U;
            aOrbiterI = RotL64((aOrbiterI * 3202327770291862207U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 53U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 50U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 3U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 19U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 54U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterK, 21U));
            aWandererI = aWandererI + ((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 41U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 21U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 35U)) + aOrbiterD);
            aWandererB = aWandererB + (((((RotL64(aIngress, 40U) + aOrbiterA) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 53U)) + aNonceWordA) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterK, 29U)) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29922U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((aIndex + 31540U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 32084U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27741U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29419U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29894U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 31419U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 40U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = ((aWandererB + RotL64(aScatter, 43U)) + 14499676118633326000U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aIngress, 24U)) + 17191273593018552288U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 5U)) + 4085176294948097737U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 11112671474158908186U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 8745787969012266485U;
            aOrbiterA = (aWandererG + RotL64(aCross, 19U)) + 18074049663777707948U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 29U)) + 2543758649719164688U) + aNonceWordK;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 21U)) + 4659584749412700523U;
            aOrbiterC = ((((aWandererE + RotL64(aPrevious, 50U)) + RotL64(aCarry, 11U)) + 974639159259871273U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (aWandererA + RotL64(aCross, 53U)) + 9211220687971081987U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 35U)) + 8567024626862182714U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5803002132294840900U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11968489432878148467U;
            aOrbiterI = RotL64((aOrbiterI * 4501441062617123165U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9470807228394903442U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1692347973120388469U;
            aOrbiterA = RotL64((aOrbiterA * 17433393164156231575U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 16510815732690193145U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 755159406833096510U;
            aOrbiterG = RotL64((aOrbiterG * 14091736464659561165U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 1518824876475937620U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 701225390867330446U;
            aOrbiterC = RotL64((aOrbiterC * 12264618860580199927U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8425976693733003889U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7182176375442410367U;
            aOrbiterF = RotL64((aOrbiterF * 8860605703761731859U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4546566785167467924U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2593340999038753749U;
            aOrbiterH = RotL64((aOrbiterH * 10152461487764567563U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9756331608356622299U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5511625814747641978U;
            aOrbiterB = RotL64((aOrbiterB * 4806076157539829529U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8694400787420160733U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12648969491371382682U;
            aOrbiterD = RotL64((aOrbiterD * 5346585704222643759U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15261238546696118531U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14236129054778329471U;
            aOrbiterJ = RotL64((aOrbiterJ * 11789581469516267749U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16251500056378064213U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 790320176607605195U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15706130623435648555U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 17114773669444878655U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14499676118633326000U;
            aOrbiterK = RotL64((aOrbiterK * 8095707555083587081U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 54U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 18U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aCross, 51U) + RotL64(aOrbiterE, 13U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterE, 11U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 3U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 46U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aNonceWordH) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterG, 5U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 21U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterI, 37U)) + aNonceWordN) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterI, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBE30D16128948B4DULL + 0xE5BBD959C13BD2DFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBAC27049F57CF409ULL + 0xFA2F4C92D822002AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE63F87776CB30567ULL + 0xC85BD1DD802DFD6DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8721FAEAF567403FULL + 0x9929EC7FFCB8D15FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8C173970B7CFBDCBULL + 0xB0C2DFA6623A2482ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFA1ECB1C076E6CEFULL + 0x9C18FEDDFB99F050ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x91F9EEF59C0D9867ULL + 0xEEC5D38E9E87550DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD335A05E0B6723EBULL + 0x88C62478B9F5057EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE52529DECD58DD73ULL + 0x9CD73303F7D20DDCULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB3169F63E731841DULL + 0xC3E71579E57BCEDFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCB3F2C0421437CADULL + 0xF7D02948CB83EF38ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF060B80FFCB4AE83ULL + 0x8C5CED09BFB374A8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFD19EF5B441DA2B3ULL + 0xA0CEF32E2B436852ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBF726832CA485839ULL + 0x806FA126A9BE9046ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xAD6E71DD20AB793FULL + 0x99D7472187640068ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD6A7E226D5326747ULL + 0xCD8D74400F4370CDULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7260U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 2619U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2522U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7953U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4660U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5241U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 37U)) ^ (RotL64(aCarry, 50U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 11450949896247900941U) + aNonceWordG;
            aOrbiterF = (aWandererD + RotL64(aIngress, 18U)) + 3905542253538116335U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 37U)) + 9529740545977785305U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 43U)) + 1856876631533143492U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 47U)) + 84253466320181686U;
            aOrbiterK = (aWandererI + RotL64(aCross, 57U)) + 12577480918745432444U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 53U)) + 5625703170397704029U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 4U)) + RotL64(aCarry, 41U)) + 694608607323629282U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 3993981243536262204U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4119215953484892051U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8785040118556157146U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17113521266125471625U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16234403619456882890U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10398727475672860610U;
            aOrbiterI = RotL64((aOrbiterI * 5086871400049644715U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 18327987141759096769U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2645964788056875452U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8778681366114628045U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2859452497983106129U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7196557924940881076U;
            aOrbiterC = RotL64((aOrbiterC * 14415389907490256711U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 930127943984174668U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15673596916054795749U;
            aOrbiterK = RotL64((aOrbiterK * 7505660488733199479U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16673140529110941163U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2258448294877833760U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1821550319748977445U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6870209259643931219U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12749790107942194104U;
            aOrbiterE = RotL64((aOrbiterE * 4871407285968611725U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17131374134617173866U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6426448390733751612U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 12490559588384058417U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15592826434339731146U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14182944418026376183U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 7218860482893476233U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 12U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 5U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 23U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 39U)) + aOrbiterH) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterG, 34U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 29U)) + aNonceWordP);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + aNonceWordD);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterK, 30U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9171U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((aIndex + 15265U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13480U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10528U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11030U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9773U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 15458U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 38U) + RotL64(aPrevious, 51U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 18U)) + 12669015908335980355U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 27U)) + 5438715179868613192U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 13172104448184536460U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 23U)) + 13421421503244744803U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 13327113302994856582U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 37U)) + 4671768205922454413U) + aNonceWordD;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 43U)) + 5355759962838579929U) + aNonceWordC;
            aOrbiterF = (aWandererB + RotL64(aCross, 54U)) + 6691720614265406851U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 7063906424700911378U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17328616394166672263U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 1542940602574207068U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8981679306319627975U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7203866278803132454U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 993485696233139264U;
            aOrbiterG = RotL64((aOrbiterG * 11609009908810366447U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15659679028507488331U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 18321361454094675842U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 3966860765622641843U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9633319822696783352U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3496559332232402963U;
            aOrbiterK = RotL64((aOrbiterK * 7772060229838162977U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1918349708324205526U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7701088402761359134U;
            aOrbiterA = RotL64((aOrbiterA * 9649485438465644795U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6006824348814439686U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 18088375375347012557U;
            aOrbiterF = RotL64((aOrbiterF * 12801082943086128385U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12816533373478543584U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 17951880253818836433U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8935839101517220201U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11311632024372748238U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 9891349164779752351U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11405973752233193209U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 711130292000437038U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17818800917771709681U;
            aOrbiterC = RotL64((aOrbiterC * 10567029732245868263U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 24U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 41U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterI, 24U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 51U)) + aOrbiterF) + aNonceWordE);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterD, 37U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 12U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 58U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 24U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18551U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 23674U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 18815U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 16668U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17615U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21995U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17155U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 29U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (aWandererH + RotL64(aCross, 56U)) + 1557680213571812384U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 7387349725778021121U) + aNonceWordN;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 15379264067601586976U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 29U)) + 3730195724576043708U) + aNonceWordG;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 38U)) + 9637070085323827066U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 43U)) + 1170865717363676184U) + aNonceWordO;
            aOrbiterC = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 2750833653175252030U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 23U)) + 15118992811225568305U) + aNonceWordE;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 19U)) + 4974092922102988451U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10625719096296719514U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 855167122475471865U;
            aOrbiterA = RotL64((aOrbiterA * 7441090331293158773U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11322911068958340262U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4334591909425429835U;
            aOrbiterD = RotL64((aOrbiterD * 10059025861172038183U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 14263701737208936392U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 678723206735649084U;
            aOrbiterC = RotL64((aOrbiterC * 10823239851733632227U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15652053114252065230U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1705225940224061401U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 3626023093533713579U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 6826394665732900206U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11902946775066981141U;
            aOrbiterF = RotL64((aOrbiterF * 18300629262162694137U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9802212958998591310U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14001358545610206524U;
            aOrbiterE = RotL64((aOrbiterE * 13172645840788327099U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4299184726135884309U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7288757011999872416U;
            aOrbiterK = RotL64((aOrbiterK * 16806027820468277393U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 233801262480580205U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 14208660347238680268U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 6299693448313154603U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9217797359740446104U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 18165073197136050838U;
            aOrbiterH = RotL64((aOrbiterH * 11677479094709512887U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 28U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 39U)) + aNonceWordI);
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterD, 19U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterK, 52U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterG, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + aNonceWordA) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32551U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 26712U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27658U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29916U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32592U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26195U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27800U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 36U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 13915875634607599122U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 1695770381382411673U) + aNonceWordH;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 20U)) + RotL64(aCarry, 11U)) + 3709105579778295511U) + aNonceWordK;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 53U)) + 7673376335333251804U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 29U)) + 8814147709738503518U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 43U)) + 13451412605350381172U) + aNonceWordD;
            aOrbiterH = (aWandererH + RotL64(aCross, 39U)) + 6447870234069609538U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 6U)) + 13419487997946496825U) + aNonceWordO;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 35U)) + 5478309847615220345U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3635184969215610049U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12527903812035294828U;
            aOrbiterB = RotL64((aOrbiterB * 12540800512035534967U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1684685110885338814U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12860354576326835090U;
            aOrbiterA = RotL64((aOrbiterA * 12743745087733307255U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9081823570147481835U) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14369321778210049109U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17865953349448767035U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11518132079084873250U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11893535026126957389U;
            aOrbiterC = RotL64((aOrbiterC * 15751374986135615095U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7084079180579206226U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 2999676609847603277U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 14602698397511266403U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17683445810614029153U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11576460512964896969U;
            aOrbiterD = RotL64((aOrbiterD * 5243651036457051155U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13429800604736567949U) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14661785761747367546U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4765843989277333421U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12837164345582888950U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6222666313184669392U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17402483466567712319U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5358647039491079457U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12459911673401497180U;
            aOrbiterI = RotL64((aOrbiterI * 13605465035256188065U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 26U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 24U) + aOrbiterA) + RotL64(aOrbiterB, 48U)) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 27U));
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterI, 6U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 51U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterK, 23U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 57U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF5AA520109BFE9FFULL + 0xDF6A20D88CFA91D3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDCBDA3D47F253A27ULL + 0xCF6F42DFA613558FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF12E6E37C13C0027ULL + 0xAE36F4C3C4898DDFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC2E51D8D5337B911ULL + 0xF3B3DA8A277D1BD7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA1D3B353185752E1ULL + 0xFC2A49BF29253F4AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF6BE9F289DCFE127ULL + 0x9A0EF7B744FF2B6BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE77D39A993B63CB9ULL + 0xE63659E484253CAFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB3F244F4C76DFFDDULL + 0xBF83256C83DE13E9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9961505D131DA807ULL + 0xEB10D9B98A815EEFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCF770CE699E6FB6DULL + 0xCEBBCDAB62A826BCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF92C452EC318A4EBULL + 0xBCC23B06B2541947ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDD7FDA76141B8911ULL + 0xBDB154259F402F36ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE61A2D46076FCFA9ULL + 0x813E5D4F3C424407ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA24D14B2835D14C9ULL + 0xDF107A1ECAB9DB77ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCF334FE8D5363717ULL + 0x84080CEB555A8421ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBE1B830DB30E8F1BULL + 0xBD043E4598F35BD5ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2353U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 1122U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4846U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7423U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1911U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6722U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 54U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (((aWandererK + RotL64(aIngress, 20U)) + RotL64(aCarry, 53U)) + 13296600294247799698U) + aNonceWordP;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 5818503518080877515U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 37U)) + 6735784238734173597U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 7368398209488856201U) + aNonceWordG;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 29U)) + 961734029066455638U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 47U)) + 797011946660892011U) + aNonceWordK;
            aOrbiterF = (aWandererI + RotL64(aScatter, 5U)) + 12841876018396622350U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16213253970483895623U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15186950557113470375U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 4647470430467908107U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5117930310827477341U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 12265429373166094162U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 1522823535151532249U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13920531346698601568U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14695405206998211456U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13950964363414164279U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7851960904825938443U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9501511171732550190U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5614164120361489613U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5663365182245722077U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9607860124321315555U;
            aOrbiterC = RotL64((aOrbiterC * 3461820361914280601U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 18171052650586819280U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3442698321538580861U;
            aOrbiterG = RotL64((aOrbiterG * 6317525514963824829U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1491052813469258970U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 3956599824067616133U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2928600779267623085U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 35U)) + aNonceWordI) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 39U)) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 56U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 58U) + aOrbiterG) + RotL64(aOrbiterB, 27U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11752U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 11521U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 8686U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((aIndex + 8756U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11549U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9873U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 13919U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = ((aWandererB + RotL64(aCross, 41U)) + 11480359716598965890U) + aNonceWordB;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 60U)) + RotL64(aCarry, 47U)) + 15431182525482873419U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 11U)) + 11360504974812776707U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 35U)) + 9292576416573382769U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 53U)) + 1549257414531028975U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 5347769463033129317U;
            aOrbiterH = ((((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 17019199177478377234U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16558106007323125094U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3976182233825939422U;
            aOrbiterF = RotL64((aOrbiterF * 4392162052317572289U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2889047161195954395U) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2241831345026962605U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 5757458560979927857U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12850802412140579294U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13541744735436450160U;
            aOrbiterH = RotL64((aOrbiterH * 906089290000537439U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2085863085516538212U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2969034221711544086U;
            aOrbiterJ = RotL64((aOrbiterJ * 7768528124408400403U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6482666944512391472U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 16969153556875844613U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9483462388353216219U), 19U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 5161314086757363678U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7150282484670673211U;
            aOrbiterD = RotL64((aOrbiterD * 8522427002337918663U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5465304381272305847U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2344610773390354017U;
            aOrbiterC = RotL64((aOrbiterC * 17010258514288089191U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 44U) + aOrbiterJ) + RotL64(aOrbiterH, 3U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 12U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 5U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18727U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 20485U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 20351U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 17564U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18990U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21928U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 18616U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 39U) + RotL64(aCross, 14U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 19U)) + 16124889768301047791U) + aNonceWordP;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 11912338587186717280U;
            aOrbiterD = ((((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 8594012868813114354U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aWandererC + RotL64(aCross, 29U)) + 18281043566156682815U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aIngress, 3U)) + 16853106130200942302U) + aNonceWordA;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 10U)) + 2611212958619673086U) + aNonceWordK;
            aOrbiterG = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 18039472325066855180U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14495785571345122046U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4556063793412832418U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 13166927543135467627U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 14896419970271244358U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 880028529183500036U;
            aOrbiterK = RotL64((aOrbiterK * 14228281807461251361U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2379557167489415783U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11854373946064529806U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 150755294320438887U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1487252775956449964U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12777924204511625545U;
            aOrbiterF = RotL64((aOrbiterF * 1366019527386994789U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 15998631485222477969U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8864212892296191613U;
            aOrbiterH = RotL64((aOrbiterH * 579242788050369815U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 17069347835763226743U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7443008171694679791U;
            aOrbiterG = RotL64((aOrbiterG * 748894368884566607U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 17334256152350782002U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8986626119086556393U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 2258172145924120235U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterA, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterF, 13U));
            aWandererB = aWandererB + ((((RotL64(aCross, 28U) + RotL64(aOrbiterH, 19U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + aNonceWordI) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterG, 56U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32127U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 27841U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 30337U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 32343U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28882U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27576U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28108U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 13U)) + (RotL64(aIngress, 44U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 12535417189990029950U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 50U)) + RotL64(aCarry, 57U)) + 6204401443676390273U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 27U)) + 869613505613154672U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 15053590879563855802U) + aNonceWordL;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 35U)) + 13338989605204591428U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 3U)) + 18306470022403825392U;
            aOrbiterH = (aWandererG + RotL64(aCross, 19U)) + 1150696349434090218U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13549541786420596437U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14302878430259588461U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16813606782134305513U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4660437084477165225U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 1653628537860912069U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2624835201155303123U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 5594199757006711631U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11008472193138708891U;
            aOrbiterC = RotL64((aOrbiterC * 13645764762027798301U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3668516817279364310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 128159531749679984U;
            aOrbiterH = RotL64((aOrbiterH * 4523246859249826987U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 6378674346113979108U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11438762460659123362U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2733309638158283953U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10624263004446482910U) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 12546839706919241411U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 11468326687628079347U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8466639576503293921U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5828694979857951504U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7835487310289634515U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 43U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + aNonceWordE) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterE, 12U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterC, 53U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD626CBCBC56183AFULL + 0x8218D9D62DF29009ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x868036673D2FFCFFULL + 0xAA8E76476D20BF00ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE6EC2A9192C889ABULL + 0xEEF504D7817DF669ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9E60C6472A196977ULL + 0xA67528C13F315AB1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC79FBE279CD9DC47ULL + 0xFDE0582B706A9FBEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x99C78619B04D11B7ULL + 0xF476448469376CDDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x85C9D51F6EF5997DULL + 0x9BB4BFF5FB692B72ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x81DD9EBE87B2FDD1ULL + 0xE8A04107A6E0F223ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFBEC03DBD8A9EBB5ULL + 0x8C1DC5FEA2828F0BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFF3A551BB1D01805ULL + 0xD32525092CB8FAB0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8A322FDD31B56C99ULL + 0x9FA73B37FB262985ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8D584BE3F417AF3BULL + 0xE861E5412533FC0AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDE15613C6EF72491ULL + 0xAD22BC22727A8D42ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA06018526C128DD7ULL + 0xC415C36A3962EE29ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x84E880A59538B2ABULL + 0xCDF9CDEEAD7AED08ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8569379E42C99111ULL + 0xF52A150B677B2F5CULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 16U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[((aIndex + 436U)) & W_KEY1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1476U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2270U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 2330952702412094686U) + aNonceWordO;
            aOrbiterC = (aWandererE + RotL64(aScatter, 53U)) + 7820188225935060799U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 44U)) + 9347644591709839145U) + aNonceWordH;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 27U)) + 2288624878446846870U) + aNonceWordB;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 9358977729492824128U) + aPhaseEOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 5U)) + 1858511275052455039U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 13715478509322292552U) + aPhaseEOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16413396625604260455U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 17714322215518432705U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 1904184102419934333U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 16188315436202861122U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5564445841368207813U;
            aOrbiterH = RotL64((aOrbiterH * 14125834616162835983U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13717068949900594673U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 14143659432287313765U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17281441046722262917U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5729546141908425670U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4297827922736712074U;
            aOrbiterA = RotL64((aOrbiterA * 13631630436759768885U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 829520109395163673U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11547160328525174295U;
            aOrbiterF = RotL64((aOrbiterF * 4759690159673049775U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2907177944512117206U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11100346409065275671U;
            aOrbiterI = RotL64((aOrbiterI * 17927994356809011637U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1344592529249949068U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6470438516791143572U;
            aOrbiterE = RotL64((aOrbiterE * 13339390828725370475U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 50U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterI, 21U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterF, 51U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 60U)) + aOrbiterF) + aNonceWordJ) + aPhaseEWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 13U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterH, 41U)) + aNonceWordN) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3751U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 4632U)) & W_KEY1], 18U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3665U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3756U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aPrevious, 37U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 13481227414590594621U) + aNonceWordH;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 17425964381118918026U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aScatter, 19U)) + 4792004356135956581U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 47U)) + 11926849936000639098U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 27U)) + 990697329347742142U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 39U)) + 9307721505373076588U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 3U)) + 17605732738841908719U) + aNonceWordA;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13110764518634187439U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17970109897810645911U;
            aOrbiterJ = RotL64((aOrbiterJ * 10395095143998920213U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10273133817644703654U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11239046688920468137U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5197802934333553327U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8355821483275763145U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 15522151127786049345U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 4844278537850520413U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5381663179722418112U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 9551368011768104906U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14202470972121732997U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 16264476585232221270U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7721417776432288282U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10267770327791051869U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 339418090653475277U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3247926250495935511U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16824669543765729097U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3390560045236418590U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3894024951542543635U;
            aOrbiterC = RotL64((aOrbiterC * 10599637790900418767U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 44U)) + aNonceWordP);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ) + aNonceWordJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterA, 11U)) + aPhaseEWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterH, 51U)) + aNonceWordL);
            aWandererB = aWandererB + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 19U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 27U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 6694U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadB[((aIndex + 7763U)) & W_KEY1], 26U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6184U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5949U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6164U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 26U)) ^ (RotL64(aCross, 53U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = (aWandererE + RotL64(aPrevious, 53U)) + 9914837590440975587U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 6706125076401958051U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 47U)) + 16570817772679258409U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 3U)) + 6843705658115186948U) + aNonceWordJ;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 16099930446791572351U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 60U)) + 5420550009556030459U) + aPhaseEOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 5729549069420177477U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15590601126188675834U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 13044027390998620029U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16845199115313444123U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 11068338135659636772U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6584988841809544332U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1683336180438945439U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8516813219883915404U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10647314042912492785U;
            aOrbiterB = RotL64((aOrbiterB * 15559481057047148785U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 201691689889605304U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15512161798401184003U;
            aOrbiterE = RotL64((aOrbiterE * 11473219183982564709U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 3883760518944464145U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13861805129175491145U;
            aOrbiterC = RotL64((aOrbiterC * 17194438894492581181U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12019138626550801486U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13030350224959652248U;
            aOrbiterF = RotL64((aOrbiterF * 11724200983306280107U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 2643807255422544248U) + aNonceWordG;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 4127143302485631794U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 5441038881111578487U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 41U)) + aOrbiterB) + aNonceWordD);
            aWandererB = aWandererB + ((((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 35U)) + aNonceWordE);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 60U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterE, 21U)) + aOrbiterC) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + aNonceWordB);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 5U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9086U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadB[((aIndex + 10606U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(mSource[((aIndex + 8981U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneA[((aIndex + 9215U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8892U)) & W_KEY1], 4U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8830U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 48U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererF + RotL64(aIngress, 51U)) + 13350544654542863236U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 12364346790125404372U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 9738750172849512764U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 3781373837635491421U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 58U)) + 16635020317512702337U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 37U)) + 5383653921676231276U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 3U)) + 10181959815492056493U) + aNonceWordO;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10005510924273927017U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9524687662265740565U;
            aOrbiterA = RotL64((aOrbiterA * 13687380438646756931U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4259138552009771014U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8973051213213726023U;
            aOrbiterJ = RotL64((aOrbiterJ * 12625091476068190979U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17602611840127337490U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8218984546932905269U;
            aOrbiterC = RotL64((aOrbiterC * 17504305273683304231U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 18102186122213487888U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2629927500298092976U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 6983280164448292723U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 2491581597835795234U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 9506602492971620955U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 9559829640915637163U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13422942713680612924U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15037354693234876601U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12692376075738621447U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12896066842192894694U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2202952306291905855U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6779368532763429997U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 36U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 3U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterF, 36U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterG, 21U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterB, 43U));
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 10955U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 11428U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13420U)) & W_KEY1], 21U) ^ RotL64(mSource[((aIndex + 11635U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13129U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13178U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((aIndex + 12800U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = (((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 2783898056762489197U) + aNonceWordM;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 7177192902873343053U) + aNonceWordI;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 12254703232691980774U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 5U)) + 15446547245691219559U) + aNonceWordN;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 47U)) + 888475203006174856U) + aNonceWordF;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 53U)) + 3649183529366307877U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 28U)) + 4642631047518805167U) + aPhaseFOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 6108329730724782250U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8334054653023816636U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9352516059501924393U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5891895375031474350U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3176720746238477862U;
            aOrbiterC = RotL64((aOrbiterC * 1869961473768307911U), 51U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 6111038696865301675U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11914998302228682704U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11738924766359642853U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17005063057791320948U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 18333780598768130670U;
            aOrbiterF = RotL64((aOrbiterF * 5416759844884107303U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2056115016443263153U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10245512728872962677U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 707106795383284903U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4810366069422162351U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3051442983125942469U;
            aOrbiterA = RotL64((aOrbiterA * 13558537578054436423U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9285068547223654308U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13067251130180968842U;
            aOrbiterI = RotL64((aOrbiterI * 7000687697769766605U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 37U) + RotL64(aOrbiterE, 29U)) + aOrbiterI) + aNonceWordC) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 37U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 29U)) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC) + aNonceWordG);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterA, 5U)) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 13700U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneC[((aIndex + 15825U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15096U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14746U)) & W_KEY1], 5U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14420U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14311U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 13874U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 4U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 48U)) + 7270044678408187242U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 10192278965379756766U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 41U)) + 17568666746676060748U) + aNonceWordA;
            aOrbiterB = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 14312927531124963037U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 57U)) + 9825825726152087706U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 9696778570255265896U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 35U)) + 17657841352013417228U) + aNonceWordI;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16207815085909628439U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1752979206374514227U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 14182667540650694199U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10456310689643905854U) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 16127830548663742550U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 4355938404839045417U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 2940917376003930842U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7353596864777649953U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7499468723171042005U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12725092740446150705U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5791296650856037010U;
            aOrbiterB = RotL64((aOrbiterB * 760379251950502133U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1200130368046206150U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16689604428598558547U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13815324235939996623U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14359561591103730856U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3975025843599045263U;
            aOrbiterA = RotL64((aOrbiterA * 5025047888533298617U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14017901732955607601U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10431526786489555196U;
            aOrbiterD = RotL64((aOrbiterD * 10181915874476132407U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 13U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 54U)) + aOrbiterB) + aNonceWordJ);
            aWandererE = aWandererE + ((RotL64(aCross, 12U) + RotL64(aOrbiterA, 29U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterF, 39U));
            aWandererF = aWandererF + ((((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aNonceWordL) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18279U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 17535U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(mSource[((aIndex + 19021U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((aIndex + 16614U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16939U)) & W_KEY1], 11U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17918U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 17362U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 37U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((aWandererD + RotL64(aCross, 29U)) + 898812731947995389U) + aNonceWordC;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 8677347622525527167U) + aPhaseGOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 770321564027567654U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 11020474858081526395U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 54U)) + 17289793580414993470U) + aPhaseGOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 11U)) + 10111912559295118444U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 5U)) + 8083622125544542011U) + aNonceWordO;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7149858558922988240U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5919683821379905699U;
            aOrbiterE = RotL64((aOrbiterE * 16705119888884231567U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6860902846079238714U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15083517836867542075U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 4686657139237578325U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14852868368708376381U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9860233289028878323U;
            aOrbiterK = RotL64((aOrbiterK * 13418143547952204667U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 772406119079116272U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 7971141501337627589U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 10168120622976358617U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8478568022896691911U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 4027604850785607101U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 4826627523578901467U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 17199331557841535430U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7515957656979776361U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5468950152869656599U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17138249294921502391U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16236812863923234668U;
            aOrbiterH = RotL64((aOrbiterH * 2925542836624164807U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 29U)) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 51U)) + aOrbiterD) + aNonceWordA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 50U) + RotL64(aOrbiterH, 19U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 40U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + aPhaseGWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterK) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 21208U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 19149U)) & S_BLOCK1], 52U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 20639U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20028U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20371U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20885U)) & W_KEY1], 34U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21835U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((aIndex + 19934U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 29U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (aWandererH + RotL64(aScatter, 29U)) + 7893287783892523139U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 54U)) + RotL64(aCarry, 41U)) + 10257331997383491153U) + aNonceWordG;
            aOrbiterJ = ((((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 14562226733652231753U) + aPhaseGOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 14320342577110737851U) + aNonceWordD;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 19U)) + 9816717579822880756U) + aPhaseGOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aPrevious, 5U)) + 9558926960095881953U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 41U)) + 9230371862654338324U) + aNonceWordI;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6414274291252913420U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13868546184398350849U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 1547986864837497409U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16940736952569949038U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2866957764814864371U;
            aOrbiterK = RotL64((aOrbiterK * 3554702178644797003U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7916721976073979724U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 1602444214978842275U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 11072503711308122385U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 9529061385251008037U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8402775110887376588U;
            aOrbiterI = RotL64((aOrbiterI * 13980225144628227381U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15003592180290390713U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14195681406520825751U;
            aOrbiterF = RotL64((aOrbiterF * 11455000833788877217U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3263577002367714202U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12019422062655581928U;
            aOrbiterD = RotL64((aOrbiterD * 5002313835338447799U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8508638054582582917U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6536618106353552880U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6233964121117511885U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 3U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 41U)) + aOrbiterD) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + aNonceWordH);
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterF, 20U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterC, 53U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 22958U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadA[((aIndex + 22286U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23256U)) & W_KEY1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22086U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22045U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24153U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23621U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 23510U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 19U)) + 4476099022490972343U) + aNonceWordG;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 37U)) + 16836423700375760429U;
            aOrbiterB = (aWandererC + RotL64(aCross, 11U)) + 8850577488928703557U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 51U)) + 7091631824560042743U;
            aOrbiterC = ((((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 12560498899956759494U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 28U)) + 7797973377112012161U) + aPhaseGOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 6173820673874805794U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10805025132310245348U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7139216143268029968U;
            aOrbiterB = RotL64((aOrbiterB * 8349754682635765573U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8241544862261635722U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4735527016563596150U;
            aOrbiterK = RotL64((aOrbiterK * 6621354217673598381U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5166171126690294033U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11117641762075368393U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4980156869201219393U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 6312932356458415421U) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1304139291184508668U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 90744653170922319U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10085025354842771067U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 16745854428789531080U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 1945983905747274355U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2497187958708890337U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16069701876646548995U;
            aOrbiterG = RotL64((aOrbiterG * 16606039730973709495U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17242004368025978091U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12334315722243232121U;
            aOrbiterC = RotL64((aOrbiterC * 16528598396696346719U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 58U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + aNonceWordF);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 51U)) + aOrbiterB) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 37U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 12U)) + aOrbiterC) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24588U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 25205U)) & W_KEY1], 28U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25593U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 25783U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26514U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25930U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25890U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24764U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 54U)) + (RotL64(aPrevious, 21U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (aWandererC + RotL64(aIngress, 57U)) + 5568146815535263910U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 37U)) + 7736084960873834666U) + aNonceWordI;
            aOrbiterB = (aWandererI + RotL64(aCross, 13U)) + 1336413621817562093U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 5218462026934984692U) + aPhaseHOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 7048890985969555935U) + aPhaseHOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 6U)) + 13415955213864702118U) + aNonceWordP;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 5657023257021528548U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14338310943137497116U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12305161641833950473U;
            aOrbiterB = RotL64((aOrbiterB * 11949964304435964395U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 14514226578370459131U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12692904083266024340U;
            aOrbiterK = RotL64((aOrbiterK * 14800805065279908839U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11012959130001327964U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7106471380403489078U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 515626559384817223U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3718101961355280891U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13364192077222322664U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1411328915372590283U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6720867800318913440U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14497243926965866546U;
            aOrbiterG = RotL64((aOrbiterG * 13595058589060114653U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5789056168233262435U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 14438482587495779937U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 10593535547917767263U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 313917798940179945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15241845511889502917U;
            aOrbiterJ = RotL64((aOrbiterJ * 16483477103771326107U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterG, 28U)) + aNonceWordM) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + RotL64(aOrbiterF, 5U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 42U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 11U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterK, 19U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29663U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 29622U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28319U)) & W_KEY1], 42U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28162U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28477U)) & W_KEY1], 38U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28666U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29700U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 29131U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (((aWandererH + RotL64(aIngress, 19U)) + 252059974543142812U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererD + RotL64(aCross, 5U)) + 11690823093681457368U) + aNonceWordJ;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 13282189752890971123U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 27U)) + 9507416294305708435U;
            aOrbiterD = ((((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 14053038174390776539U) + aPhaseHOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 14605253312318725009U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 58U)) + 18138286582677863671U) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8530091235978489988U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14381731677571170073U;
            aOrbiterB = RotL64((aOrbiterB * 11675896999665768253U), 29U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 13316413456378978456U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3910529530149320706U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16000139333493588429U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6302070286831566901U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12324134652758551396U;
            aOrbiterC = RotL64((aOrbiterC * 17136438281540250165U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4773478557638475048U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4031153435446078944U;
            aOrbiterF = RotL64((aOrbiterF * 3876928995240982769U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3114794895962903899U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 3552936509969106796U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 16823186892738820299U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5828754613946145627U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 17985241114076114558U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 1986669631395606833U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11319331046368072261U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6104267020171882160U;
            aOrbiterE = RotL64((aOrbiterE * 12525117969211576177U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 21U);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterB, 27U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 43U)) + aOrbiterC) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterF, 13U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterB, 34U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterD, 53U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 43U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + aNonceWordM) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31539U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32029U)) & W_KEY1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31327U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32197U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31892U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadB[((aIndex + 32124U)) & W_KEY1], 23U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 51U)) + (RotL64(aIngress, 18U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 35U)) + 15383045568644941552U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 51U)) + 17452811657750910067U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aWandererD + RotL64(aIngress, 11U)) + 15660117718455155603U;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 10396441207743665753U) + aNonceWordO;
            aOrbiterI = (((aWandererG + RotL64(aCross, 23U)) + 3708971058200841442U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 35U)) + 7000673057768598750U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 9886354469011131596U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16018065329058043467U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5024756166109352320U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11660932185479046483U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6587818720728886652U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3652672354944162319U;
            aOrbiterI = RotL64((aOrbiterI * 10807121230791716109U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6307315649915348048U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16405347331742979258U;
            aOrbiterD = RotL64((aOrbiterD * 7183142442906743699U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5427299664054601957U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4983381733483185898U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14646556236306407673U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10182995521328377487U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 8694282877540593550U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 14614602561910403893U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 4085927978153269932U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6176195962815240877U;
            aOrbiterH = RotL64((aOrbiterH * 16792916528959579875U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6966742100601433005U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9920952446921247521U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 1879821050131820933U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterE, 44U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 3U)) + aOrbiterC) + aPhaseHWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 13U)) + aNonceWordB) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 11U)) + aOrbiterI) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBE92326271AAC3F7ULL + 0xB75508F65A7E9FFCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAA16863786575845ULL + 0x9BCCDF42E3371F98ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8F376F14C78B77FBULL + 0x8474DAC95B939BA4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8B73D3058233AE79ULL + 0xBFEDFAAECCFD858CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFD592CBFE912D9A9ULL + 0xEBC30A43B7E48833ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x92C997AEFCFEC7F9ULL + 0xC78F7562C78EA1C4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBC35068AE97EC407ULL + 0xADF776D25D54704FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEB018C584AE0D35DULL + 0x84AA48B6E34751ACULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9BA9EE09C63928BDULL + 0xF097C945DA556325ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA501AF7D1B835EA7ULL + 0xB0C621DEBE9EC19BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF6EF40269EB59E0DULL + 0x9053382D32D472C5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x96D4CD4AE8BC313FULL + 0x8EA5F4658734D840ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC5329DFCCA736F1DULL + 0xD44227F4FDBB10BBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD3AFA9EDA914A1BBULL + 0x960B13CFE5662CA2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE727B20A97DEED33ULL + 0xC7BABA18124425D4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9AB90DDA3E24CEFFULL + 0x9EB846A353E4C103ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2336U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 4U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3812U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2016U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 332U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 136U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 58U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 11998579547770778580U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 43U)) + 8409465187298704610U) + aNonceWordK;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 3470222286110333500U;
            aOrbiterD = ((((aWandererA + RotL64(aIngress, 14U)) + RotL64(aCarry, 11U)) + 5704486785203069994U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aWandererD + RotL64(aScatter, 3U)) + 10334944660253279633U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 7626852700722567477U) + aNonceWordL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 14631310754943209743U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1958866541508493967U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 807160297237854120U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5624154783624196107U;
            aOrbiterI = RotL64((aOrbiterI * 2404066593958052159U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 4971444394698940423U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 6340057638461027062U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 12027586111086798629U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9003019862787819481U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13632057463595873033U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12575202147280216765U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12766104026871797746U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4062118445824915939U;
            aOrbiterG = RotL64((aOrbiterG * 13130770039048080701U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 34U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 51U) + RotL64(aOrbiterI, 28U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 5U)) + aOrbiterH) + aPhaseAWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 27U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 5543U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 9724U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9303U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneC[((aIndex + 7020U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8693U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8220U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6013U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aIngress, 13U)) + (RotL64(aPrevious, 47U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((((aWandererH + RotL64(aCross, 30U)) + RotL64(aCarry, 29U)) + 9080426856729228705U) + aPhaseAOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 47U)) + 7851218321653539276U) + aNonceWordD;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 7023344692919298036U) + aNonceWordL;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 9772846154227440734U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 39U)) + 12008298632429608431U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 12201090455849562875U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9498721803411445471U;
            aOrbiterC = RotL64((aOrbiterC * 6511810500788451775U), 43U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 351203764023093632U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 4966360430644539250U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10138518378274592739U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9194167899071345693U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4922477697284269116U;
            aOrbiterG = RotL64((aOrbiterG * 8444814161720407881U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15742625291642356429U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 7528703106518431730U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 11530049278751507567U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15279053574704935317U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2425839793660355555U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11486964816849830667U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aPrevious, 44U) + aOrbiterF) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 3U)) + aNonceWordK) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 57U)) + aOrbiterA) + aNonceWordE);
            aWandererA = aWandererA + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 37U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterF, 14U)) + aPhaseAWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 14313U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 12909U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 12072U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14390U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14610U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 14U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 39U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = ((aWandererJ + RotL64(aCross, 23U)) + 1087148170018530502U) + aNonceWordB;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 15530846874509311414U) + aNonceWordE;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 16987358651515511212U) + aPhaseAOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 12504143181007924259U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aWandererB + RotL64(aCross, 12U)) + 393322117322732418U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14325937299241887166U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 9395262907017475742U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3442643798173589117U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13658510441418344769U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 6410754322737005336U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6932217611373076391U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9257290738538818434U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 7489828960857692286U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 16519674788777989043U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 4118778591214588387U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16619215231168796563U;
            aOrbiterI = RotL64((aOrbiterI * 14876884956536265157U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11326283811003573430U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1865401866017614604U;
            aOrbiterC = RotL64((aOrbiterC * 8378326058282460073U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 34U);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 30U) + aOrbiterF) + RotL64(aOrbiterB, 11U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 35U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 44U)) + aOrbiterD) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterI, 35U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21583U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneA[((aIndex + 18377U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 20217U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20521U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17770U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 27U)) ^ (RotL64(aCarry, 40U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererH + RotL64(aCross, 40U)) + 3973833383430652211U) + aNonceWordL;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 23U)) + 5760227042747169187U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 4923009065139227286U) + aPhaseAOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 1477807307009107590U) + aNonceWordE;
            aOrbiterA = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 5707194514329007301U) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5340439728375269724U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17080457898946572387U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 17719588880215414933U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 281559150259472813U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 16160633048230910560U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 16883442583309073785U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9003989610509592121U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10579322462808454333U;
            aOrbiterD = RotL64((aOrbiterD * 100832431598087235U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15059383289528723069U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10417647757852880956U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1457919230286043137U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14484665027393813330U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12344463053485837974U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 5762654194001525041U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 26U) + RotL64(aOrbiterE, 23U)) + aOrbiterH) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 41U)) + aNonceWordF) + aPhaseAWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterA, 56U)) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21913U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneB[((aIndex + 25138U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 27074U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26173U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23092U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 35U)) + (RotL64(aPrevious, 47U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 52U)) + RotL64(aCarry, 19U)) + 13278949403988203974U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 19U)) + 9213599924054673756U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 1255746482932381798U) + aPhaseAOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 11575321997144516122U) + aNonceWordJ;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 43U)) + 15881587525529432437U) + aNonceWordF;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9846195809864862707U) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 12319815691858217670U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14271546305640811091U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16322617427294439587U) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16332130810525887437U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 7588076439690559343U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4920951156015336794U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16767126455124552329U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4440352337076842603U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12553595911087945223U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1437522202135436142U;
            aOrbiterD = RotL64((aOrbiterD * 2001992794165550905U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12313100454852227143U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2761983020631055729U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 3874839760378039509U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + aNonceWordM) + aPhaseAWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterK);
            aWandererH = aWandererH + (((((RotL64(aCross, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordG) + aPhaseAWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aIngress, 28U) + aOrbiterD) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 39U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30190U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 31783U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 27553U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28249U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27352U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 17019646486641172469U) + aNonceWordI;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 12276141179299971572U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 11U)) + 3617241694029841555U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 48U)) + RotL64(aCarry, 5U)) + 6967963401259371737U) + aPhaseAOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 27U)) + 6340709284279891017U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 456065368903896482U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 17686765719908116203U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 4451942512173336609U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1322045955429785736U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5163772703302372887U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3193272189179082313U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13268431135020363252U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 6538789950366849332U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 5352960308459065837U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10390344544314544893U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5087084271300584267U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 15149302947570776165U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13423071121590981727U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 18324443012024134729U;
            aOrbiterK = RotL64((aOrbiterK * 15814349432207734533U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 52U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 21U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordF) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 4U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + aNonceWordH) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 58U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 47U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA9D6033C98EE34D9ULL + 0xBB4123F897FA4430ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8B41DE529FFCF765ULL + 0x87F859BE99CDBEF9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x811D3B119EF4CD81ULL + 0xE412612CE597F21CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8A76277A202CFC2FULL + 0xC7CDF13CC0121DA6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDC78E37250ABD765ULL + 0xF3A4771BEAFB4D8AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x95ACADFEE06E5D03ULL + 0xA467A382109D93F0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x945B7E3B01A9C1B7ULL + 0x899D3FED94428B0FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCB5D2B4FE549D6BDULL + 0xD33D74E70783FB7FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF3DE0E82EC27F0ABULL + 0x8E3AB719E8D1365AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBF887BA8512A38B3ULL + 0xECF10888D442BE18ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF1840F0503462081ULL + 0xA2959345F77D0320ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDB505F76E691F43BULL + 0xF3D27946867D8C08ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF251BD78E5C853D7ULL + 0xF087BF42F085D549ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA7132C4DA7D36F0FULL + 0xD2BE8DA56378FECFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD322495368A0CE87ULL + 0xC1767FE2B32B0B06ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAA73BD45B3602EB9ULL + 0xFB2C9C6E850831FFULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5228U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 561U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3066U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3712U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1450U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6867U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 52U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 30U)) + 18180797995100240808U) + aNonceWordO;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 35U)) + 6585906608223552885U) + aPhaseBOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 14088708930575939855U) + aNonceWordG;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 47U)) + 468974153311516044U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 39U)) + 12481951025619894110U) + aNonceWordK;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 17227987923860711763U;
            aOrbiterB = (aWandererC + RotL64(aCross, 24U)) + 4373962756657477139U;
            aOrbiterJ = ((((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 2077576476565420951U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aWandererJ + RotL64(aCross, 5U)) + 17435011300234663764U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4118039398293246896U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13724716599855216683U;
            aOrbiterF = RotL64((aOrbiterF * 17556333902751079677U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12391461204689596339U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9900605191533799627U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13553565332531046301U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 972946858824366125U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 17247681919694541215U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 2974639094630445643U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15442851427306771601U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7303586227288294037U;
            aOrbiterG = RotL64((aOrbiterG * 15406402525021428799U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 12650358753454105119U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1483710933373510492U;
            aOrbiterJ = RotL64((aOrbiterJ * 6531763256577221891U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 18065810162229740788U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11311677121338794007U;
            aOrbiterI = RotL64((aOrbiterI * 15116367961682119467U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2355285311890287611U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1287783821903407734U;
            aOrbiterH = RotL64((aOrbiterH * 8054011680932255985U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9282654686791135654U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15488608017745542551U;
            aOrbiterD = RotL64((aOrbiterD * 7858866274035085123U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13296835576073421802U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7127700236018338741U;
            aOrbiterE = RotL64((aOrbiterE * 11246173563106014149U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterD, 23U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterD, 10U)) + aOrbiterG) + aNonceWordB) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterI, 47U));
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 39U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 29U)) + aOrbiterF) + aNonceWordA);
            aWandererC = aWandererC + ((RotL64(aIngress, 24U) + aOrbiterE) + RotL64(aOrbiterJ, 56U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10660U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((aIndex + 16058U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 11522U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 8495U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11064U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9808U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12399U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererC + RotL64(aIngress, 13U)) + 6381335981879993247U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 15595429101600023172U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 58U)) + RotL64(aCarry, 51U)) + 5449234297249826461U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 11213734849329731168U) + aNonceWordO;
            aOrbiterI = (aWandererD + RotL64(aCross, 19U)) + 16438473952464514248U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 47U)) + 7357872882115186976U) + aNonceWordC;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 24U)) + 394402075160738643U) + aNonceWordI;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 5U)) + 11112941985410283532U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 35U)) + 14955125011182736212U) + aNonceWordF;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14770727009821304070U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11286366598129204910U;
            aOrbiterH = RotL64((aOrbiterH * 15884310771003021989U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 7358400908565425780U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15635109923749114761U;
            aOrbiterI = RotL64((aOrbiterI * 12415152149408700329U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13826842523738623579U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1072811298828325231U;
            aOrbiterG = RotL64((aOrbiterG * 9662800288646215083U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4017334196009350776U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8812213572751410831U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12744171921566782795U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6723457786170634403U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9785583533999417673U;
            aOrbiterC = RotL64((aOrbiterC * 7776915427605471097U), 51U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 10265132640322153964U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8435670887514808087U;
            aOrbiterA = RotL64((aOrbiterA * 2706263045620662131U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4303823386961718326U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4214384238167491037U;
            aOrbiterF = RotL64((aOrbiterF * 8490707334221154005U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8740835037840799136U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5988815405391206280U;
            aOrbiterE = RotL64((aOrbiterE * 17838555472135715929U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15539461383052981747U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3743772525784217714U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 6352086797545969187U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 38U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterF, 23U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterD, 48U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterI, 53U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + aPhaseBWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aCross, 10U) + aOrbiterF) + RotL64(aOrbiterC, 12U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterE, 5U)) + aNonceWordJ) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20244U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 19342U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 18018U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20704U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16898U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18739U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 19162U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 44U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (aWandererI + RotL64(aScatter, 47U)) + 16016931609704150191U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 14511433515861302636U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 57U)) + 11691237442613269593U) + aNonceWordI;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 52U)) + 16383220587320484649U) + aPhaseBOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 14293015313458219868U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 4407695248205526670U) + aNonceWordD;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 39U)) + 1158323195324398372U) + aPhaseBOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aWandererE + RotL64(aCross, 22U)) + 6577683409653864555U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 5U)) + 171080079472863843U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5766333425872228205U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16173508656917582960U;
            aOrbiterB = RotL64((aOrbiterB * 12187968015372936695U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11781450063402219202U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13033139686637576694U;
            aOrbiterK = RotL64((aOrbiterK * 4331137994135472025U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4006310759400926020U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13156817947481574467U;
            aOrbiterA = RotL64((aOrbiterA * 563189239835001483U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 12791290558893516411U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 989729955679243234U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 8757228712495095017U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 838379839663022790U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2830743864262313606U;
            aOrbiterJ = RotL64((aOrbiterJ * 10173947177104802797U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2146646527331684652U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4629168181742174906U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9046124907945045131U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1150129989168501777U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 619659995945229440U;
            aOrbiterD = RotL64((aOrbiterD * 13734821008174603409U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8120315647582116952U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13754584116324996165U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12295486140772079747U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6084566798869999580U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5731665119233722504U;
            aOrbiterI = RotL64((aOrbiterI * 5921510209025133639U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 47U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterG, 6U)) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ) + aNonceWordJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterB, 42U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28640U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 30571U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27429U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 27041U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31175U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24802U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29448U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 26U) + RotL64(aCarry, 57U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 12131317914288566437U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aIngress, 57U)) + 5672805657999385496U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 47U)) + 3581710244233124197U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 41U)) + 15251296040538489436U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 36U)) + 11295008604679904153U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 2230897493419504490U) + aNonceWordE;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 19U)) + 7109600123297458999U;
            aOrbiterI = ((((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 13119156643107683803U) + aPhaseBOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aWandererD + RotL64(aCross, 52U)) + 14755160867807355250U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16829363373287496832U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16981122946707720883U;
            aOrbiterJ = RotL64((aOrbiterJ * 5394974422201576627U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8806000776958603317U) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16810923047720876014U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17872735050219539145U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8129657889554436328U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8653100378491974463U;
            aOrbiterD = RotL64((aOrbiterD * 11395283153912468661U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17048985838727432415U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10892675550889823573U;
            aOrbiterI = RotL64((aOrbiterI * 976298937314081913U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15960158965421254346U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12290011578634850001U;
            aOrbiterA = RotL64((aOrbiterA * 9280475585104357745U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 16265047040311479093U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10312956912303656248U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3012584393253845131U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 16706890352221352779U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10630955894218491929U;
            aOrbiterE = RotL64((aOrbiterE * 12675937483456206355U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4009352551041162434U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 3043810773683888556U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4328135390387997315U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1398071019814944785U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16689766557488135301U;
            aOrbiterC = RotL64((aOrbiterC * 8403881916549404871U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 6U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 4U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 52U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 13U)) + aOrbiterA) + aNonceWordK) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 20U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 56U) + RotL64(aOrbiterD, 43U)) + aOrbiterG) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCB8071C76D8C4993ULL + 0xE6575EA3710916A6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAA3FE20C22DE225DULL + 0xB2E6753CB906E830ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB7AF09733BEF07C9ULL + 0x9DF6B3F49BF5D588ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEF311E1DED782C27ULL + 0xE4A784599644EBF0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF6F4272B09DE26F3ULL + 0x9A57306B753ECA69ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE7077BB1580A0F35ULL + 0x86ED8A5DD6B021A2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x91BFBB62A5F6FBDBULL + 0xE59FDBB94D006B71ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF3025E97A39ED32DULL + 0xC0F1F7160DAB29C4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x84FF9E71408ACB4DULL + 0x8CEBFACF098E08D5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDF5AD80FFE786A59ULL + 0xEB27D1C30B0DF096ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB9EE9BDCF5F1081DULL + 0x853B0BEC89C3AF17ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA7202E5B2EA996EBULL + 0xD56F02D1214B441EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x81B639C0B78009B7ULL + 0x81E4BD5DCDC96C65ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA5B464814E66FA19ULL + 0xE5481975E8FFF294ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAF1AC6021FAA1055ULL + 0x8E671C2E3DFC2639ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8F1DCF9F16D034BBULL + 0xE5D51B9A7072336EULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 772U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 15U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3702U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4769U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2970U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1894U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 56U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 35U)) + 17470880031634374199U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 757565846006937746U) + aNonceWordE;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 48U)) + RotL64(aCarry, 23U)) + 9419282475801345674U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 11U)) + 2014248014107898196U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 15113928519446490441U) + aNonceWordF;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 41U)) + 7346126964886259935U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 5U)) + 5594123113093162359U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5659237263369402005U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11565709683423969703U;
            aOrbiterH = RotL64((aOrbiterH * 16731289017588574671U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16782863743534856287U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13499100900072115907U;
            aOrbiterK = RotL64((aOrbiterK * 5567729598873214433U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 11414447651044205242U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7545993795121430538U;
            aOrbiterJ = RotL64((aOrbiterJ * 10758488381206257261U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11778229237616454988U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2544793391976514665U;
            aOrbiterC = RotL64((aOrbiterC * 4021060413798523299U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9972156716619459164U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17651030383827445664U;
            aOrbiterI = RotL64((aOrbiterI * 6742914240706775487U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17439147296849134543U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10021926927948343656U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18139540407315440909U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9309867875882669289U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14951424455944346337U;
            aOrbiterD = RotL64((aOrbiterD * 10569523948169951309U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 11U)) + aOrbiterG) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterG, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aPrevious, 20U) + aOrbiterH) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 41U)) + aNonceWordC) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 46U)) + aNonceWordB);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 39U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterD, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 48U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5523U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 9127U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6904U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 7972U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5893U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10268U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5722U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((aWandererC + RotL64(aCross, 47U)) + 14499676118633326000U) + aPhaseDOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 41U)) + 17191273593018552288U) + aNonceWordI;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 11U)) + 4085176294948097737U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 21U)) + 11112671474158908186U) + aNonceWordH;
            aOrbiterH = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 8745787969012266485U;
            aOrbiterC = ((((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 18074049663777707948U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 5U)) + 2543758649719164688U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4659584749412700523U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 974639159259871273U;
            aOrbiterJ = RotL64((aOrbiterJ * 17918719351847605523U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9211220687971081987U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8567024626862182714U;
            aOrbiterH = RotL64((aOrbiterH * 7755874089832496393U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5803002132294840900U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11968489432878148467U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4501441062617123165U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9470807228394903442U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1692347973120388469U;
            aOrbiterF = RotL64((aOrbiterF * 17433393164156231575U), 21U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 16510815732690193145U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 755159406833096510U;
            aOrbiterC = RotL64((aOrbiterC * 14091736464659561165U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1518824876475937620U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 701225390867330446U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 12264618860580199927U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8425976693733003889U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7182176375442410367U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 8860605703761731859U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 46U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 53U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 39U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 60U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aCross, 44U) + RotL64(aOrbiterE, 21U)) + aOrbiterH) + aPhaseDWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterC, 27U)) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 38U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14125U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 13941U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13487U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12107U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11268U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 38U)) ^ (RotL64(aCross, 3U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((aWandererB + RotL64(aIngress, 47U)) + 17074147006464019918U) + aNonceWordM;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 35U)) + 10559516626129419928U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 13280363679503946221U;
            aOrbiterE = (aWandererA + RotL64(aCross, 41U)) + 17657115422132457413U;
            aOrbiterC = ((((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 13325837013304973008U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((((aWandererD + RotL64(aIngress, 60U)) + RotL64(aCarry, 5U)) + 3059707750486106037U) + aPhaseDOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aWandererI + RotL64(aCross, 19U)) + 4529045702503050852U) + aNonceWordD;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10726578475550904292U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 14832537837996659885U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 808060368961520519U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 220094417441809246U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15343130035105342194U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7984652435043810845U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 16592263353426409884U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15649290906447931918U;
            aOrbiterB = RotL64((aOrbiterB * 8405875177836650731U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11437410545843708269U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5859769136073011444U;
            aOrbiterA = RotL64((aOrbiterA * 1065016088086441107U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15188064100307340341U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4367466521843260049U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15916715854192820923U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8482617283860566845U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2585745804937342972U;
            aOrbiterD = RotL64((aOrbiterD * 8267269625632139809U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1687641344403425541U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13667916445979421400U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 8191322670355590027U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 52U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterB, 60U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterD, 29U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 13U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterD, 5U)) + aPhaseDWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 53U)) + aOrbiterC) + aNonceWordI) + aPhaseDWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 6U) + aOrbiterF) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 20U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 17928U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 18437U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19912U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17383U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((aIndex + 21820U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 23U)) + 2974056819475622600U) + aNonceWordE;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 14U)) + RotL64(aCarry, 23U)) + 7345051759236356098U) + aPhaseDOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aCross, 41U)) + 12738468816846628882U) + aNonceWordI;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 7694520596043297922U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 5U)) + 5530753590015084774U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 29U)) + 3776309161718383105U) + aNonceWordD;
            aOrbiterB = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 784780304358106404U) + aNonceWordO;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8999942326995036509U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5194986506064092779U;
            aOrbiterI = RotL64((aOrbiterI * 15070787038006135963U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7920040007459652762U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11311997270710107937U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 6227571709361790209U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5365231114813547251U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8630110234623825263U;
            aOrbiterB = RotL64((aOrbiterB * 2735881715888325759U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2358235238039571072U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 18059414891616491807U;
            aOrbiterJ = RotL64((aOrbiterJ * 17150786106857185467U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14526050556461782864U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6937282036603272474U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14954512365270028029U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10105832250694931310U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3884223553012098137U;
            aOrbiterC = RotL64((aOrbiterC * 16340956813003906195U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10385284339549648087U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1257633893341505930U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2669950791270500977U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterI, 13U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterH, 39U)) + aNonceWordH) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 29U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 4U) + aOrbiterC) + RotL64(aOrbiterJ, 47U)) + aNonceWordB);
            aWandererI = aWandererI + (((((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 54U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordP) + aPhaseDWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 26161U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 24090U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 25535U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25112U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25204U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 4739486756133131180U) + aPhaseDOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 43U)) + 16089707555501328184U) + aNonceWordL;
            aOrbiterF = (aWandererH + RotL64(aCross, 19U)) + 15310047330238536453U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 13U)) + 7901411596386834955U) + aPhaseDOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 4357555491060982163U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 37U)) + 15667085602825720102U) + aNonceWordM;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 4U)) + RotL64(aCarry, 53U)) + 8520635334382269253U) + aNonceWordK;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1772509779231068315U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15336170957886025677U;
            aOrbiterF = RotL64((aOrbiterF * 10996880551392077399U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 8628770833489469980U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15469234024247246228U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 8905266995119987947U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10796430900884288328U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10660110397012853289U;
            aOrbiterH = RotL64((aOrbiterH * 9140007610912037461U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 11202284258711214794U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17509491802893182994U;
            aOrbiterC = RotL64((aOrbiterC * 9329107599972703671U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16212572740740103554U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 2190030203761579226U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 3101886685668871045U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12014337082293041909U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3733531010807001506U;
            aOrbiterD = RotL64((aOrbiterD * 5797362244066062299U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7100994963061975529U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17837541162838600258U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8745987361678166553U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterA, 41U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterF, 53U));
            aWandererA = aWandererA + ((((RotL64(aCross, 29U) + RotL64(aOrbiterF, 60U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + aNonceWordC);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 27U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterK, 35U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 30475U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneA[((aIndex + 28248U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 30828U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30468U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31924U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 20U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 1042610313571524121U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 3505725321008825582U) + aNonceWordI;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 12584654563843782991U;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 5U)) + 6645399144515770935U) + aPhaseDOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aWandererJ + RotL64(aCross, 27U)) + 3608978423753715584U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 57U)) + 8089198857670370983U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 36U)) + 15207251813516399879U) + aPhaseDOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9579268660105824516U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16055044469473802812U;
            aOrbiterI = RotL64((aOrbiterI * 2269649280637188723U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 583811872609805949U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7027491967970873942U;
            aOrbiterH = RotL64((aOrbiterH * 12686754713465826139U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 18256061823189677508U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12708429127816136937U;
            aOrbiterG = RotL64((aOrbiterG * 12593886633108075321U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12169216645156306078U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12694325407567795065U;
            aOrbiterB = RotL64((aOrbiterB * 3711789483877261899U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16109994660203297503U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4234704064165718913U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 730085881474787681U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 14119541943554602878U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8777769004811352951U;
            aOrbiterD = RotL64((aOrbiterD * 2556957257736134223U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15642663488392549609U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11594468530833278624U;
            aOrbiterK = RotL64((aOrbiterK * 6639306656361601143U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + aPhaseDWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterG, 57U));
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterB, 37U)) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aIngress, 28U) + aOrbiterB) + RotL64(aOrbiterI, 6U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB113325DCA3B4205ULL + 0xE231F61C67939671ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCFEFCBE7DA9DA8E9ULL + 0xDC8BAC21976CDEE4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD9D519223BE57B27ULL + 0xA1FA02587ABE41CFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD0D7C0E5889FB857ULL + 0xED2871E9BF66BE84ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE6BEED49A00AE703ULL + 0xCFFEC6A16AF905AEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBC1EA7374DEC0D31ULL + 0xEE55273B3C9E1DCDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE20F3AA2749AA6FBULL + 0x8BAA28E412C67399ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBB86DACAC0763E91ULL + 0xB3C74750F30CDE68ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE326F886CAB44425ULL + 0xBF5DE692664CA7FDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x801090CF5BF1F5B3ULL + 0x9FC042020F368CBEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE94CF3335D80C8F9ULL + 0x8B05FF7BF5B96EC2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC27B86188901C4B5ULL + 0xDB4A7A58C8098C29ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC3485234B675E537ULL + 0xEE41F7AFEA34EE08ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x90472B8686C8E8A3ULL + 0x8298AD2304350434ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB95FA0D293FF1AFFULL + 0x91D1F8318B5C5CB5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE26FAC74466F9E37ULL + 0xF58814AB3B9F0236ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 5428U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneB[((aIndex + 3008U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2045U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2768U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 1118U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2007U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = ((aWandererD + RotL64(aScatter, 41U)) + 16424657151168221875U) + aNonceWordG;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 23U)) + 17150123681886380361U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 11U)) + 16041993588694572757U;
            aOrbiterI = (aWandererB + RotL64(aCross, 37U)) + 9871185846434828537U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 18U)) + RotL64(aCarry, 21U)) + 11227236398354430757U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 43U)) + 5399325217402192631U) + aNonceWordE;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 13U)) + 9248828789282890454U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 9041370494203701062U) + aPhaseEOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aWandererE + RotL64(aScatter, 35U)) + 14944424084524970764U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 5481938174456671041U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 50U)) + 14783648629543752715U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12355573914530445723U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9863991559011968318U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8495251211794343179U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16149688605937250965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 106041828692026825U;
            aOrbiterB = RotL64((aOrbiterB * 12199934305374582599U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8076098639554567792U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11155119311895580013U;
            aOrbiterD = RotL64((aOrbiterD * 1495180896564818647U), 57U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 6847612160595917702U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16094377920388017367U;
            aOrbiterA = RotL64((aOrbiterA * 4875801863643206333U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13584719866672696684U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13446209321646234607U;
            aOrbiterI = RotL64((aOrbiterI * 9945349065094781529U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15829806645369560988U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12573767256739062550U;
            aOrbiterG = RotL64((aOrbiterG * 5649504278826069077U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3850030870300393809U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11857593987748189858U;
            aOrbiterH = RotL64((aOrbiterH * 15942863910931814193U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5505918410521728373U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 12949653497121247860U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 90944913639560027U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2448323375614082955U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4386059032042654583U;
            aOrbiterF = RotL64((aOrbiterF * 11730132905525317201U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 108129028178045299U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 18292666533864994149U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 2599590507178673531U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10771402979550786312U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16424657151168221875U;
            aOrbiterE = RotL64((aOrbiterE * 6255743082177474607U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterC, 56U)) + aOrbiterE) + aNonceWordA);
            aWandererF = aWandererF + ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterH, 27U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 56U) + aOrbiterG) + RotL64(aOrbiterI, 34U));
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterI, 43U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterD, 51U)) + aNonceWordB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterC, 21U));
            aWandererB = aWandererB + ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 5U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 50U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6634U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneC[((aIndex + 8800U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8783U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10815U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5905U)) & S_BLOCK1], 12U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6978U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9834U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 22U)) + (RotL64(aCross, 3U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (aWandererE + RotL64(aIngress, 13U)) + 12262991801139086177U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 60U)) + 7963038771924890197U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 41U)) + 15540520327933568896U) + aNonceWordI;
            aOrbiterH = (aWandererA + RotL64(aCross, 39U)) + 8745565892055020722U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 16619329199683755286U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 19U)) + 10865705026433867260U) + aNonceWordH;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 2743368697984518059U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 3U)) + 5556006271515473135U) + aPhaseEOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 24U)) + 5355833281353498588U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 8313616108963479829U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 57U)) + 16657121016801866434U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16532226425013000833U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 5800465874932467232U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5966395771690704577U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17882948163883121328U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15029375310296563175U;
            aOrbiterB = RotL64((aOrbiterB * 17021415832288477713U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10170682648007918739U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 11829089574189398773U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15755874363488568849U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1746524867389196322U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 10217423427886742775U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9166162099575333519U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1338457710729082656U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1319981417675542556U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 9518448254565489715U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3985281993069194761U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7281264481139915593U;
            aOrbiterH = RotL64((aOrbiterH * 13498446162967276739U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17394503335338855566U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1430703546991948227U;
            aOrbiterF = RotL64((aOrbiterF * 1623206122475721175U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 472559435062214929U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8065899137826178995U;
            aOrbiterJ = RotL64((aOrbiterJ * 13287499768933229539U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3377996409668333322U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10456089146891981998U;
            aOrbiterC = RotL64((aOrbiterC * 12037044781049717633U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5246784368779537905U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8518987022368391332U;
            aOrbiterA = RotL64((aOrbiterA * 4046763804695058779U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7791883487780325967U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12262991801139086177U;
            aOrbiterD = RotL64((aOrbiterD * 3409890579914160747U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 56U) + aOrbiterH) + RotL64(aOrbiterK, 58U));
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 35U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 51U));
            aWandererD = aWandererD + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 13U));
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 54U)) + aOrbiterA) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 41U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterD, 21U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererB, 20U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 58U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15906U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((aIndex + 14202U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15076U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14867U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13845U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 22U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 14823268998003220191U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 41U)) + 15295237288788213847U) + aNonceWordJ;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 16434853402001133899U;
            aOrbiterE = (aWandererB + RotL64(aCross, 56U)) + 7555911304407871631U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 19U)) + 14977248264994834620U;
            aOrbiterA = (aWandererH + RotL64(aCross, 35U)) + 9707764144919392380U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 29U)) + 1277304385464681529U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aScatter, 53U)) + 3089786220465849395U;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 10U)) + RotL64(aCarry, 23U)) + 3700503853358695085U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 39U)) + 3240054112993517371U) + aNonceWordP;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 23U)) + 16897532076915366859U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 18167359289798364307U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8870819278575769863U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9334066154398059075U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15363069206212330251U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14858164441499725158U;
            aOrbiterC = RotL64((aOrbiterC * 14931933411393847915U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5357144808788707522U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2910681277417754860U;
            aOrbiterH = RotL64((aOrbiterH * 13170868582159347059U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9824408699018165151U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 368370224788793300U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14358982366258729959U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7095398304588825115U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11418879758164313554U;
            aOrbiterF = RotL64((aOrbiterF * 5983520332639771791U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2171599720681913272U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17593730219647495033U;
            aOrbiterA = RotL64((aOrbiterA * 12926053208918563087U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 17755947635188715523U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14565740605227022106U;
            aOrbiterI = RotL64((aOrbiterI * 15866418354612945335U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14538017880915584414U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6174566474851449123U;
            aOrbiterE = RotL64((aOrbiterE * 179569008593475683U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3806438394748643441U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13737114463856719285U;
            aOrbiterG = RotL64((aOrbiterG * 13439346068497710151U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3698379331577470045U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1097081284062708554U;
            aOrbiterK = RotL64((aOrbiterK * 3498627643013255777U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 215117138867597766U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14823268998003220191U;
            aOrbiterJ = RotL64((aOrbiterJ * 12131828437975771377U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 6U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterA, 39U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 42U) + RotL64(aOrbiterH, 11U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 27U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterB, 57U)) + aNonceWordI);
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 54U)) + aNonceWordF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterC, 35U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterF, 41U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + aPhaseEWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 6U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 36U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererH, 14U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16457U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneA[((aIndex + 17768U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21733U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17881U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneD[((aIndex + 17923U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = (aWandererH + RotL64(aIngress, 41U)) + 2617613537256538553U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 56U)) + 16642868916835132715U) + aPhaseEOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 10860291124337073254U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 3U)) + 6432511273906902472U) + aNonceWordO;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 29U)) + 7505375005848241910U) + aNonceWordP;
            aOrbiterF = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 11086616004678821329U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 3298830587569881951U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 43U)) + 9775143140064220979U) + aNonceWordD;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 53U)) + 4147601326580823120U) + aNonceWordK;
            aOrbiterA = (aWandererA + RotL64(aCross, 51U)) + 12245920269898100415U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 6U)) + 8391940489176734499U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17876893379544668477U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 18301882058180370541U;
            aOrbiterJ = RotL64((aOrbiterJ * 16680384667098921309U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6869225862715140102U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 15404118372589259800U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 5766851935950389915U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17757381020518233814U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17677969146092374455U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3469432916562405063U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 15783378556632870114U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 5792858258663697864U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12008981883482080427U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11737803388202260296U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16001927091970715330U;
            aOrbiterF = RotL64((aOrbiterF * 3062030309852922061U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1749586939123286632U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6169421068855905938U;
            aOrbiterH = RotL64((aOrbiterH * 12374789910763348695U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10073586820719728062U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17744171227198661555U;
            aOrbiterE = RotL64((aOrbiterE * 10658375268803957647U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1149819647337612792U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7725598665625892006U;
            aOrbiterI = RotL64((aOrbiterI * 15097586655234391559U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13930096050550704122U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3632241034947389647U;
            aOrbiterA = RotL64((aOrbiterA * 8442222389196610427U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 17933893495867517142U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7888594392078082482U;
            aOrbiterC = RotL64((aOrbiterC * 9809847720610861237U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10805303827043372168U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2617613537256538553U;
            aOrbiterD = RotL64((aOrbiterD * 3940471942234248791U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 12U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 20U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 54U)) + aOrbiterE) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 41U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterH, 51U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterD, 57U));
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 26U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterK, 13U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 18U) + aOrbiterE) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererB, 44U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27033U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((aIndex + 21845U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22846U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24070U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneA[((aIndex + 24175U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 4752759164691497960U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 12088872623537639782U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 41U)) + 3734943577379734227U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 47U)) + 8854778183012444234U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 21U)) + 16948373492893967275U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 10U)) + 7962415690046184385U;
            aOrbiterF = (aWandererB + RotL64(aCross, 19U)) + 1872682375669714454U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 7776801806943853566U) + aNonceWordA;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 51U)) + 16665439117257230732U) + aPhaseEOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 3U)) + 11088186766134265676U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 56U)) + 10850237991780969350U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6464817712131305812U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 244557182884209844U;
            aOrbiterC = RotL64((aOrbiterC * 2394270354887582889U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13261563971157415841U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2323811103717827362U;
            aOrbiterB = RotL64((aOrbiterB * 11483723582415081925U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12338803568475493422U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2811342930111104982U;
            aOrbiterG = RotL64((aOrbiterG * 5020981755203607757U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5554497011738996057U) + aNonceWordK;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 12712169745460598698U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 1985586486150377769U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 17415058661427002973U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 9430421222715343818U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 10321140659099470811U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3926618548181233180U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6172453297026957838U;
            aOrbiterF = RotL64((aOrbiterF * 1161551082037835233U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 8633288765997226004U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17270881130844274342U;
            aOrbiterK = RotL64((aOrbiterK * 8888559940161770791U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12232950994807835262U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15352600312956742750U;
            aOrbiterJ = RotL64((aOrbiterJ * 6140396356904933003U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5614120002595447983U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1920822446545182835U;
            aOrbiterH = RotL64((aOrbiterH * 17049182594382482085U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 625576652179261739U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2362773059031414585U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17049048587829564949U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16749690978107177915U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4752759164691497960U;
            aOrbiterA = RotL64((aOrbiterA * 8442185754037031199U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 10U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterH, 5U)) + aPhaseEWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 44U)) + aOrbiterD) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 27U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 21U)) + aOrbiterA) + aNonceWordP);
            aWandererI = aWandererI + ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterA, 35U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterC, 60U));
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 39U)) + aOrbiterA) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 10U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28599U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 28352U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 29631U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31954U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneB[((aIndex + 28594U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 18U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (aWandererH + RotL64(aIngress, 11U)) + 12122689833405846292U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 9640400270962766788U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 21U)) + 9141937998266739071U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 54U)) + RotL64(aCarry, 19U)) + 12899395770434090537U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 43U)) + 13457918115408031842U) + aNonceWordB;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 41U)) + 15134784483576000943U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 27U)) + 12540961268790055438U) + aNonceWordC;
            aOrbiterG = (aWandererG + RotL64(aIngress, 23U)) + 6306886773092764230U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 29U)) + 13573343491337243121U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 13U)) + 8545588657348974413U) + aNonceWordO;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 6U)) + 10891410570357275120U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2877137119767060151U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9178097682386595144U;
            aOrbiterE = RotL64((aOrbiterE * 3524486002084427513U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15528007881855616978U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 11368419529245281435U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12433207037378339309U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5932738914934356645U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5551842263864055419U;
            aOrbiterA = RotL64((aOrbiterA * 16093776759971522681U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3824433359595690603U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17184628855571662441U;
            aOrbiterC = RotL64((aOrbiterC * 691208053136187317U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8724462245014132623U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7481349499528092352U;
            aOrbiterB = RotL64((aOrbiterB * 8212182934509617583U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6908362960248294718U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5354057969992655314U;
            aOrbiterH = RotL64((aOrbiterH * 16586084885820679343U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11138301629323903147U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14164180536320940750U;
            aOrbiterK = RotL64((aOrbiterK * 9099767681053390287U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 709942920176922902U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17128241237359414945U;
            aOrbiterI = RotL64((aOrbiterI * 14063385518459963529U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6760410778228957309U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15333948259759012363U;
            aOrbiterD = RotL64((aOrbiterD * 3685416414008280787U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6929136132517755104U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13833415487953533365U;
            aOrbiterF = RotL64((aOrbiterF * 14860437994758579635U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 16143046377679975216U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12122689833405846292U;
            aOrbiterG = RotL64((aOrbiterG * 227699085983424155U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 44U) + aOrbiterF) + RotL64(aOrbiterH, 43U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 47U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 40U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 27U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterC, 53U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 51U)) + aOrbiterH) + aNonceWordE);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterA, 20U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterK, 35U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 36U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF704E9638AEE7509ULL + 0x9AD794CC235D7CA2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD77A4E75FF8A2699ULL + 0xCED3AAAC33F49037ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFDB0374EEA57743FULL + 0x987D5D3C2F53DDC3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8B0E561B20A2F073ULL + 0x828FC1FA7DC111BDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAD3BAA7ED819CF15ULL + 0x8E0FC84A14EE22C8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCB915B0626A1B0A7ULL + 0x8C613C162D6C249CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF3F8E2C8B906CAB3ULL + 0xBD48542984538A02ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBC823D6D5684A7AFULL + 0x943F5E79435A7D41ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF38398EFD13018C1ULL + 0xD4D7AE728B0E0D6CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDB879FC3BF7CFCC7ULL + 0xD7D7E4281C647513ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9257A677C12E7207ULL + 0x8B9AA94D73473129ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBF00F2C22B95E991ULL + 0xFAAAE36FC1F7B61EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF50463E56F02B2C5ULL + 0xD13DC9544B301067ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF72BD3F60D80096FULL + 0xAA47CDDCE0523D4FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x88058F68D5539AF1ULL + 0x8DC96DFC22B0E259ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x91BED2895B3B7429ULL + 0xD4405AEA11417E44ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4136U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 4286U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5032U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1192U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1007U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1679U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 29U) ^ RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = (((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 9855743441035905047U) + aNonceWordI;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 10U)) + RotL64(aCarry, 35U)) + 8426286937143990276U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 19U)) + 7146752367170267002U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aPrevious, 51U)) + 12947210066678101726U;
            aOrbiterE = (aWandererG + RotL64(aCross, 41U)) + 15902163559925328965U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 8506649889346449469U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 28U)) + 8226286036430263052U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aWandererC + RotL64(aIngress, 37U)) + 2703047093452420216U;
            aOrbiterI = (aWandererK + RotL64(aCross, 3U)) + 6769351326360139560U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9857025533281333281U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 238297452132277585U;
            aOrbiterF = RotL64((aOrbiterF * 12974709749856065985U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7203572312072908931U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12497027346166575632U;
            aOrbiterE = RotL64((aOrbiterE * 1703586436725662307U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 473851890609048879U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1664484956453886047U;
            aOrbiterD = RotL64((aOrbiterD * 8566500756326590209U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4635095143004754116U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17695676150967345793U;
            aOrbiterK = RotL64((aOrbiterK * 5780416541584439301U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15628965269863402796U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9190117464399730235U;
            aOrbiterB = RotL64((aOrbiterB * 5586437438425999715U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 17835918238346011086U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 4398005402429282682U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14828737209913317463U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10902589938246551273U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15124274429081385923U;
            aOrbiterI = RotL64((aOrbiterI * 13524180348258805367U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8747233520702236018U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5445611443463112371U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10294109295823410447U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16296005217836151910U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6468336224317602364U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 7369779919748367133U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterD, 48U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 5U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterI, 52U));
            aWandererE = aWandererE + ((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 23U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aCross, 19U) + RotL64(aOrbiterG, 35U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterH, 58U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterI, 43U)) + aNonceWordO);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterK, 13U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8710U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 6058U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6335U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8651U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6340U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9679U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 6602U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 15045917390223766480U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 23U)) + 10763054007033668758U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 19U)) + 13190170142593666607U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 39U)) + 9657025731441167065U) + aNonceWordF;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 10U)) + RotL64(aCarry, 47U)) + 11433367178975954211U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 17904920143996810366U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 57U)) + 3244383020512113283U) + aNonceWordC;
            aOrbiterC = (aWandererJ + RotL64(aCross, 27U)) + 6538815775171139091U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 50U)) + 7195368312757976343U) + aNonceWordL;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 18134430713910279374U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6571776588427107976U;
            aOrbiterH = RotL64((aOrbiterH * 11916502085252589161U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11830778129647517758U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9793702760907767365U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 4096246227968677179U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2287235876793192036U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8951959188326141794U;
            aOrbiterK = RotL64((aOrbiterK * 9968356718110753845U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7583061790273240157U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 3571364625022806085U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 6238360922735480669U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13869345563551689212U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 277480328952975002U;
            aOrbiterF = RotL64((aOrbiterF * 1057564597096163085U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4983735092494677578U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9490022869381030928U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12926352917961703123U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7928039573014765566U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6504190875809407084U;
            aOrbiterA = RotL64((aOrbiterA * 14648214826494826711U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2787985600176307413U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16308785053443116826U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17867565986311256691U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12788128335006767824U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1187040019537798339U;
            aOrbiterJ = RotL64((aOrbiterJ * 10834905007658184183U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 18U) + aOrbiterD) + RotL64(aOrbiterC, 35U));
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 11U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 58U)) + aOrbiterH) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterF, 5U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 56U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterK, 52U)) + aOrbiterJ) + aNonceWordE) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterC, 19U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12685U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 15491U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12365U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15536U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12926U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (aWandererA + RotL64(aScatter, 5U)) + 12535417189990029950U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 19U)) + 6204401443676390273U) + aNonceWordD;
            aOrbiterE = ((aWandererB + RotL64(aCross, 46U)) + 869613505613154672U) + aNonceWordE;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 15053590879563855802U) + aNonceWordI;
            aOrbiterH = ((((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 13338989605204591428U) + aPhaseFOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((aWandererC + RotL64(aCross, 27U)) + 18306470022403825392U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aIngress, 23U)) + 1150696349434090218U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 34U)) + RotL64(aCarry, 23U)) + 13549541786420596437U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 53U)) + 14302878430259588461U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4660437084477165225U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1653628537860912069U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 2624835201155303123U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5594199757006711631U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11008472193138708891U;
            aOrbiterF = RotL64((aOrbiterF * 13645764762027798301U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3668516817279364310U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 128159531749679984U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4523246859249826987U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6378674346113979108U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11438762460659123362U;
            aOrbiterA = RotL64((aOrbiterA * 2733309638158283953U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10624263004446482910U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12546839706919241411U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11468326687628079347U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8466639576503293921U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5828694979857951504U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 7835487310289634515U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16496305151014092976U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 589464613876410567U;
            aOrbiterJ = RotL64((aOrbiterJ * 13190816610718051897U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 4168532743415647825U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15944887793736489375U;
            aOrbiterH = RotL64((aOrbiterH * 17273403561158196717U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11642456814106259483U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1609897693632334867U;
            aOrbiterK = RotL64((aOrbiterK * 12912773555616819941U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 48U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 19U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 26U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterI, 35U));
            aWandererK = aWandererK + (((((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 43U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordG) + aPhaseFWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterE, 3U));
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterK, 30U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17232U)) & S_BLOCK1], 54U) ^ RotL64(aSnowLaneA[((aIndex + 19261U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19610U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17120U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17204U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 10U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 10404808878585437255U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 27U)) + 10587858736301591439U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 60U)) + 1430530909801644435U) + aNonceWordH;
            aOrbiterK = (aWandererB + RotL64(aIngress, 53U)) + 9090938022430118902U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 37U)) + 12936604311751121235U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 1000583006020232032U;
            aOrbiterI = ((((aWandererI + RotL64(aScatter, 20U)) + RotL64(aCarry, 5U)) + 12352532088997042232U) + aPhaseFOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 47U)) + 16723410947058502564U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 43U)) + 16614089235313154270U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4245553025593349277U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3353146318549477494U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 14246377408238318091U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5935727336135635196U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10312187090293319667U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1395964500396711899U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12192843181244744484U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2542570124502586365U;
            aOrbiterI = RotL64((aOrbiterI * 17222847847573534963U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3315472769469002444U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17512858811783071174U;
            aOrbiterB = RotL64((aOrbiterB * 9070400454074283765U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16633218007427888082U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2502077714838858460U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 970762420815997725U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14792910273226469214U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15739513291150783151U;
            aOrbiterH = RotL64((aOrbiterH * 11896279674116906915U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 2192903544350345992U) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 844428341223009295U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4768368713974002539U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 2998511458298901402U) + aNonceWordL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7790789639864783373U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9173097618440495497U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4540735375055164995U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13700342877362633034U;
            aOrbiterG = RotL64((aOrbiterG * 14730797752841670505U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 40U) + RotL64(aOrbiterI, 22U)) + aOrbiterE) + aNonceWordG);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 27U)) + aOrbiterB) + aNonceWordM) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterD, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterK, 37U));
            aWandererI = aWandererI + (((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterG, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25622U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneB[((aIndex + 22445U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22873U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24781U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((aIndex + 23193U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 43U)) + 2330952702412094686U) + aNonceWordB;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 39U)) + 7820188225935060799U) + aPhaseFOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 19U)) + 9347644591709839145U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 26U)) + RotL64(aCarry, 47U)) + 2288624878446846870U) + aNonceWordG;
            aOrbiterK = (aWandererG + RotL64(aCross, 11U)) + 9358977729492824128U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 47U)) + 1858511275052455039U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 13715478509322292552U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 4U)) + 16413396625604260455U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 21U)) + 17714322215518432705U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16188315436202861122U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 5564445841368207813U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 14125834616162835983U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13717068949900594673U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14143659432287313765U;
            aOrbiterG = RotL64((aOrbiterG * 17281441046722262917U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5729546141908425670U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4297827922736712074U;
            aOrbiterB = RotL64((aOrbiterB * 13631630436759768885U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 829520109395163673U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 11547160328525174295U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 4759690159673049775U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2907177944512117206U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11100346409065275671U;
            aOrbiterH = RotL64((aOrbiterH * 17927994356809011637U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 1344592529249949068U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6470438516791143572U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13339390828725370475U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5217751823741520847U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5371275223586938039U;
            aOrbiterI = RotL64((aOrbiterI * 12318403075523724125U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14218103150268532919U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1367628876596800571U;
            aOrbiterE = RotL64((aOrbiterE * 13777531272321533137U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2372041991018455610U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 9870744274890595581U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 12093443117747395585U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 10U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 27U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 52U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 52U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + aNonceWordE) + aPhaseFWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 23U));
            aWandererF = aWandererF + (((RotL64(aIngress, 42U) + aOrbiterH) + RotL64(aOrbiterJ, 41U)) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterI, 56U));
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterB, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 6U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31971U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 30240U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 30585U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28463U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneB[((aIndex + 30528U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 47U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererH + RotL64(aIngress, 28U)) + 5131645209694953015U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 12070391048835379854U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 2604295836242338724U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 14042039029284001596U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 48U)) + 8914654543854559327U) + aNonceWordH;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 13U)) + 2185619407969359869U) + aNonceWordC;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 23U)) + 5187406295103352574U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 57U)) + 8022832481290871217U) + aNonceWordE;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 43U)) + 8783061916740573472U) + aNonceWordL;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10711028365596196301U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 13387065038269133571U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12444578026365205255U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11187001318931801582U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14191473173276034019U;
            aOrbiterH = RotL64((aOrbiterH * 2491253922434756431U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16207761776716426435U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9677408414452078760U;
            aOrbiterJ = RotL64((aOrbiterJ * 5487303383095129949U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17812460332794370649U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7736423148554132028U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 15588733747232852555U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17293203944059014763U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13487243633338010243U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9468688858740539095U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15979293016815060755U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17645215484691359547U;
            aOrbiterK = RotL64((aOrbiterK * 1449450767288733995U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11635961468586927692U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10530136578329059784U;
            aOrbiterA = RotL64((aOrbiterA * 8785021493374398437U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4900370530116992731U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15952900504821599445U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 5413316082800365261U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9938000151832814778U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14170277411106520726U;
            aOrbiterD = RotL64((aOrbiterD * 5058343552974910737U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 42U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 48U) + aOrbiterI) + RotL64(aOrbiterH, 35U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterJ, 58U));
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 5U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterA, 39U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 14U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 23U)) + aOrbiterG) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 56U) + RotL64(aOrbiterD, 53U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8D037447BD1E8D6BULL + 0xF4191DFDB04452A6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x884EFCA391A33DABULL + 0xAC814A33A0114BFDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9E09AFC2FD8CE9CBULL + 0xB5CCA4A2DDD7FA82ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCF34A1437586DC2DULL + 0xEEB12A926ECEFA45ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA96625CADD6E7AE3ULL + 0xDD60E12020EFB24CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD938F6368628FA83ULL + 0xFAF420B9897C1197ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB5463B77D61F76D9ULL + 0xBD3D7C1C50B7F3B4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF9CF1A1A7BD044D7ULL + 0xF930AC7077CF5F29ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDD09D6D5C63C596FULL + 0xE2F55EE7502698FAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE9A69862D161A4D7ULL + 0x985CCBAE21208E1BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA937E5D4F13231BDULL + 0xAA14D0479D7BB6DBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF6786F87CF0F1AF3ULL + 0xA582D2D5811631B6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB5F1F99A03362DC7ULL + 0x8BFD86E962814960ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE4E82F3D96782F07ULL + 0xC05A13B8CCC08C8EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE07CB4704C4B8421ULL + 0xD0058FB0B79B3F89ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE0FB423EE784F5C7ULL + 0xDAE81AD123F69B28ULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 512U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((aIndex + 2901U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5257U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 4621U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 4818U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2687U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 28U) + RotL64(aCarry, 3U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 27U)) + 6069475454765660321U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 37U)) + 11483704742497268068U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 3U)) + 11055697447388986418U) + aPhaseHOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 48U)) + RotL64(aCarry, 5U)) + 10897095046039997004U) + aNonceWordG;
            aOrbiterH = ((((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 4731637118230457840U) + aPhaseHOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 13855839187084986751U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 19U)) + 5328208115460188239U) + aNonceWordE;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 12479538544291412985U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10740165998792608231U;
            aOrbiterG = RotL64((aOrbiterG * 14046827922294477379U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6492798157284955373U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13056825957483891921U;
            aOrbiterH = RotL64((aOrbiterH * 14882112110627751751U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2068184064919194657U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5656302738780746294U;
            aOrbiterE = RotL64((aOrbiterE * 16493021179127646345U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11193756120230763294U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17306750816837208999U;
            aOrbiterF = RotL64((aOrbiterF * 7949360041241439741U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12952818800389361804U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15380412293642628312U;
            aOrbiterJ = RotL64((aOrbiterJ * 2914662289178925547U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 7706090204767242996U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14598802276412649570U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4821408736292041399U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 17819762117328075515U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6481384240915075101U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4836701121865783029U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + aNonceWordP) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 28U) + aOrbiterG) + RotL64(aOrbiterF, 53U));
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 3U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + aNonceWordK) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 26U)) + aOrbiterA) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7916U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 6900U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10431U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneC[((aIndex + 7990U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 10115U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 6570U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9148U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 35U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 29U)) + 18319689184146942855U) + aPhaseHOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 8041304130090501019U) + aPhaseHOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 11347064191990897738U) + aNonceWordF;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 11U)) + 15242243470024447468U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 10619749107163611105U) + aNonceWordB;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 37U)) + 14795614276221947128U;
            aOrbiterG = (aWandererE + RotL64(aCross, 58U)) + 1578095288886372393U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13593906305770501684U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8919815528334599172U;
            aOrbiterE = RotL64((aOrbiterE * 2033810402808238127U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17425548324720065145U) + aNonceWordN;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11125018338392347335U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4377887040461528587U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3779189180734244399U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10958224663276134041U;
            aOrbiterD = RotL64((aOrbiterD * 6206963519509783781U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4317305352561612995U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4891139433808505355U;
            aOrbiterG = RotL64((aOrbiterG * 11507024985663120317U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5166074784835930965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10080890270621589202U;
            aOrbiterB = RotL64((aOrbiterB * 13170894418184288695U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4501071771615514619U) + aNonceWordA;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 6486573807774431753U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 324029625116648669U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15714881857668975753U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3506619392820235900U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5707033870161224499U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterE, 39U)) + aNonceWordO);
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 21U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 50U) + aOrbiterE) + RotL64(aOrbiterD, 27U)) + aPhaseHWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterB, 14U)) + aOrbiterG) + aNonceWordL) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterG, 53U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14263U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 13387U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11385U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13006U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneC[((aIndex + 14309U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = ((aWandererB + RotL64(aCross, 57U)) + 8506388683755208267U) + aPhaseHOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aIngress, 51U)) + 2179323259055019735U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 23U)) + 3345902531140983016U;
            aOrbiterH = ((((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 17456139311481306584U) + aPhaseHOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 14587864088462311164U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 13178947246650647057U) + aNonceWordN;
            aOrbiterE = (aWandererK + RotL64(aIngress, 4U)) + 12866578138946916962U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13098524333655118173U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15451329483787541982U;
            aOrbiterK = RotL64((aOrbiterK * 13580376920467431451U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9494299579678389385U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15581954810375490643U;
            aOrbiterI = RotL64((aOrbiterI * 13670002280188424825U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4487042505730624892U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2774455928791636186U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15847933919136777451U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12435319582397755819U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10077180055177766823U;
            aOrbiterD = RotL64((aOrbiterD * 3924363471701748703U), 13U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 10391963896910956455U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6149237416725301794U;
            aOrbiterG = RotL64((aOrbiterG * 10115917698918612823U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15673402771629639978U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 14729117178956592426U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 9070464269215820531U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14492001279368870240U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6278248084483259952U;
            aOrbiterE = RotL64((aOrbiterE * 16731228350971263873U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 60U);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 51U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterH) + aNonceWordK);
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + aNonceWordB);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + aPhaseHWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterA, 36U));
            aWandererK = aWandererK + (((RotL64(aCross, 4U) + aOrbiterK) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18103U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 19426U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18710U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18881U)) & S_BLOCK1], 6U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17269U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 50U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 19U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 16922357079016918108U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 24U)) + RotL64(aCarry, 29U)) + 11771749797137599131U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 4635668433708036077U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 35U)) + 15827952719230577008U) + aNonceWordO;
            aOrbiterD = (aWandererK + RotL64(aScatter, 5U)) + 1495675306110023086U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 53U)) + 7294835466949728365U) + aNonceWordG;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 13U)) + 179122461212041978U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 545981421632236251U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 15338259639814630535U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 14895421566334357871U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12924313840290895215U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17846785921286020610U;
            aOrbiterJ = RotL64((aOrbiterJ * 18309347016029917133U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5721472794107057875U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16359630793856870319U;
            aOrbiterD = RotL64((aOrbiterD * 14186771515526698907U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10614102110239037308U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 16421992251278236531U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2561232904676068089U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8668149834861244963U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12699331834360948734U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 2249360824172616357U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4470693178142950471U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 526000656022724741U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16688501462334673493U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6880246132270094141U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7126466778855297013U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5692237926830293205U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterD, 42U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 21U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterH, 29U)) + aNonceWordJ);
            aWandererF = aWandererF + ((((RotL64(aScatter, 12U) + aOrbiterJ) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH) + aPhaseHWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 4U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26154U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 23291U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 25561U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23030U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 23277U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 18U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = ((aWandererI + RotL64(aIngress, 4U)) + 14624277139785904404U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 6966977309498165611U) + aPhaseHOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 205536824352530761U) + aNonceWordP;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 16629575265808255692U) + aNonceWordN;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 53U)) + 596881340147972746U) + aNonceWordM;
            aOrbiterD = (aWandererC + RotL64(aCross, 13U)) + 11944412799107412650U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 21U)) + 4615021315668210206U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8497630055977606216U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11131601107309336885U;
            aOrbiterJ = RotL64((aOrbiterJ * 18028349768453554935U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5935883479805510099U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15629346719765798174U;
            aOrbiterE = RotL64((aOrbiterE * 8535523790685945275U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5279128339113651273U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 16778365912440331821U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 705421028266789241U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16003052937645491524U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6723226158737614764U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16690657664909260573U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9785784358981219543U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 10055457337292292710U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 17919129940751761111U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11779163108592974175U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 1177999477942202687U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 13475069421684114643U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9190694445141492214U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15605342360346353457U;
            aOrbiterC = RotL64((aOrbiterC * 14547769706392595647U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 21U));
            aWandererI = aWandererI + ((((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterB);
            aWandererD = aWandererD + (((((RotL64(aScatter, 56U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordD) + aPhaseHWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterA, 37U)) + aNonceWordJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 50U)) + aOrbiterA) + aNonceWordI) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 20U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31448U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((aIndex + 30073U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 28702U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30471U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((aIndex + 27830U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 34U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 53U)) + 1898718075389870739U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 20U)) + 5631794889237247403U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 18219714659484524607U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 15419581386225732921U) + aPhaseHOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 13U)) + 9125575431710198210U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 12205871520544965505U) + aNonceWordC;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 41U)) + 7617534300497343422U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18017579105368135814U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10693882161946020042U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 2326507900303932855U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11669615701700895306U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11045110212889232165U;
            aOrbiterF = RotL64((aOrbiterF * 5965171269273719849U), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 18019107802806469913U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12315940560472528716U;
            aOrbiterI = RotL64((aOrbiterI * 4505122470351404065U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4899009736070044310U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17412253404253730364U;
            aOrbiterH = RotL64((aOrbiterH * 10791901166391946485U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 4826286251927854181U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4523455921321845084U;
            aOrbiterK = RotL64((aOrbiterK * 14534103906736598099U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4132514462154182215U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7164745605985109269U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 14107325508977225261U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6297434295807635654U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8813887638672996646U;
            aOrbiterJ = RotL64((aOrbiterJ * 17495632530773158201U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 44U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 19U)) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aCross, 60U) + RotL64(aOrbiterF, 58U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH) + aNonceWordI);
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterB, 39U)) + aPhaseHWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + RotL64(aWandererI, 58U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 196U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 1504U)) & W_KEY1], 50U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2424U)) & W_KEY1], 24U) ^ RotL64(mSource[((aIndex + 1273U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 44U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 3973833383430652211U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 5760227042747169187U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 4923009065139227286U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 51U)) + 1477807307009107590U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 28U)) + 5707194514329007301U) + aPhaseAOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aPrevious, 41U)) + 5340439728375269724U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 11U)) + 17080457898946572387U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 47U)) + 281559150259472813U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 56U)) + 16160633048230910560U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9003989610509592121U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10579322462808454333U;
            aOrbiterD = RotL64((aOrbiterD * 100832431598087235U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15059383289528723069U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10417647757852880956U;
            aOrbiterF = RotL64((aOrbiterF * 1457919230286043137U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14484665027393813330U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12344463053485837974U;
            aOrbiterH = RotL64((aOrbiterH * 5762654194001525041U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5826453246659297805U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12547902286376986223U;
            aOrbiterC = RotL64((aOrbiterC * 2982850000322672789U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9637855144278126174U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2132744427444501938U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5911587798564836199U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9248933938130311231U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13274297928717090383U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2901398809555237563U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3690262236918560930U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3626005326410800344U;
            aOrbiterB = RotL64((aOrbiterB * 13030443356669355355U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10801089744186148218U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5446653082176311031U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4594267575901248321U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3205541585889107366U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4532327942368884436U;
            aOrbiterK = RotL64((aOrbiterK * 16287094987689326229U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 58U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterD, 48U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterE, 27U));
            aWandererK = aWandererK + (((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterA, 5U)) + aPhaseAWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterB, 53U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3467U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3845U)) & W_KEY1], 48U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3486U)) & W_KEY1], 48U) ^ RotL64(mSource[((aIndex + 5393U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererD + RotL64(aScatter, 13U)) + 14214886793361825363U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 46U)) + 17267959031078766320U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 51U)) + 16436067429484887644U;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 9885951769332633820U) + aPhaseAOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 35U)) + 12971711341813893304U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 26U)) + RotL64(aCarry, 19U)) + 199970353398450154U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 41U)) + 1237341696444162094U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 21U)) + 7991128854417613360U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 5U)) + 14809029847149045833U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 2559509556915775947U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14336829730147834160U;
            aOrbiterD = RotL64((aOrbiterD * 15103242520064900873U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8853631886733610440U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13346159398673246914U;
            aOrbiterB = RotL64((aOrbiterB * 13660497151446983393U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12121095718571872976U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16239781125815589804U;
            aOrbiterK = RotL64((aOrbiterK * 5157009090454962231U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9051377033794324106U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13805815136723461780U;
            aOrbiterJ = RotL64((aOrbiterJ * 571129481747181357U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14849157800322754413U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 18116651528452542634U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3638480428016835537U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4105057226952948599U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5911714320560994391U;
            aOrbiterC = RotL64((aOrbiterC * 1796514171654961389U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4439149331729987587U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10278532228230163632U;
            aOrbiterE = RotL64((aOrbiterE * 17428224919864716517U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2342456582668741750U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2360578572554664800U;
            aOrbiterH = RotL64((aOrbiterH * 1108428466956691925U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12132934875391401246U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17213278726790245812U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11904899990681410419U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 46U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterK, 53U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterC, 23U));
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 6U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aCross, 58U) + aOrbiterI) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 11U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 10U) + aOrbiterJ) + RotL64(aOrbiterD, 48U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 5939U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6834U)) & W_KEY1], 60U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7390U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7681U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6428U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 18U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererI + RotL64(aScatter, 3U)) + 3248574644570178787U;
            aOrbiterA = (aWandererK + RotL64(aCross, 29U)) + 4506961512959200024U;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 8423739774540738590U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 42U)) + RotL64(aCarry, 35U)) + 6593975869641735337U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 57U)) + 16441716090557369103U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 53U)) + 7936601450453207914U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 11U)) + 13333752583560167065U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 8013703284795432973U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 48U)) + 2349852779887439236U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5318539364763284138U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11450957608502944376U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1957880366707810635U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9058992558327552687U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 632095686920230926U;
            aOrbiterE = RotL64((aOrbiterE * 12460364388358520799U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14734218428913777098U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16344357661370784442U;
            aOrbiterK = RotL64((aOrbiterK * 15049472842002138369U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2981145363531184308U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14176472085175714494U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2584623327412130939U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11198457590069700889U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 952584436750426828U;
            aOrbiterH = RotL64((aOrbiterH * 1165713888651280355U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4311591763498985972U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16194341833989936369U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9997934560195932575U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7560794022401107431U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10683789740265711603U;
            aOrbiterJ = RotL64((aOrbiterJ * 15637823045351977883U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11614366395125937178U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10750771385100564416U;
            aOrbiterC = RotL64((aOrbiterC * 4987921274272444283U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2934697034132204529U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4646873794658020363U;
            aOrbiterD = RotL64((aOrbiterD * 10555456865641580175U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 60U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 43U)) + aOrbiterK) + aPhaseAWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 34U) + aOrbiterH) + RotL64(aOrbiterA, 56U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterC, 35U));
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 50U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aPrevious, 24U) + aOrbiterB) + RotL64(aOrbiterH, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9288U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 10198U)) & W_KEY1], 42U));
            aIngress ^= (RotL64(mSource[((aIndex + 10543U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8225U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9756U)) & W_KEY1], 12U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 9994U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 27U)) ^ (RotL64(aCarry, 40U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererG + RotL64(aIngress, 6U)) + 7960325128608297381U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 51U)) + 12773836012104052042U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 47U)) + 3173972621347773016U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aPrevious, 23U)) + 3708401356314308171U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 950774285720019449U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 37U)) + 4170092315705438265U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 17000449130864980747U;
            aOrbiterI = (aWandererE + RotL64(aCross, 60U)) + 8793910540062893860U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 41U)) + 520277969543516469U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12762214857389827271U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2932451184340207695U;
            aOrbiterJ = RotL64((aOrbiterJ * 7513337346940091655U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11062179998786293839U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7919119215271524178U;
            aOrbiterF = RotL64((aOrbiterF * 9053677007180081359U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1774988449597115155U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3799792889466518953U;
            aOrbiterK = RotL64((aOrbiterK * 17512791286490623455U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1815062051307896589U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15260373951371654483U;
            aOrbiterH = RotL64((aOrbiterH * 2208604434669491625U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12867546628945676853U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7772820973895846946U;
            aOrbiterB = RotL64((aOrbiterB * 7581704643538761985U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14213957831821966834U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16561105721170419454U;
            aOrbiterI = RotL64((aOrbiterI * 2540533987337175367U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16556502948339949526U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9706742922075498974U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8527361328901355457U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13455756934917486016U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 9107769876332723454U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1722386100852683783U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15793099079168487016U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7968278803691283365U;
            aOrbiterA = RotL64((aOrbiterA * 11644765391940099387U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 36U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterF, 34U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 18U) + aOrbiterK) + RotL64(aOrbiterJ, 43U));
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterB, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + aPhaseBWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 58U) + aOrbiterI) + RotL64(aOrbiterA, 19U));
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterB, 53U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 57U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 14U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererG, 22U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11809U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 13570U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12158U)) & W_KEY1], 51U) ^ RotL64(mSource[((aIndex + 12009U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13149U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11173U)) & S_BLOCK1], 34U) ^ RotL64(aFireLaneC[((aIndex + 13176U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererK + RotL64(aCross, 56U)) + 13880995121909552664U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 14534942818069300546U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 29U)) + 17745973100886007133U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 2249805580771946872U) + aPhaseBOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 4460116116396439410U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 51U)) + 3378683994078106878U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 18U)) + 3992996501048809123U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aPrevious, 41U)) + 12057768808864451929U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 37U)) + 4115362079047921130U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15297384955502206698U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17623548383481905636U;
            aOrbiterG = RotL64((aOrbiterG * 7487278217901483685U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3559213898000162417U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12311605719074507335U;
            aOrbiterI = RotL64((aOrbiterI * 3982199462062847697U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14807313864347885885U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11222085523291581822U;
            aOrbiterH = RotL64((aOrbiterH * 12580941911587215653U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 916681229436292462U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2441350114032314686U;
            aOrbiterC = RotL64((aOrbiterC * 7336079498999018067U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7361470539894653271U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12153585147213579808U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3040327545467672961U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 13566300726101613579U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14875254144748509128U;
            aOrbiterE = RotL64((aOrbiterE * 13699179902908972403U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9268158535644002904U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14144295981814993491U;
            aOrbiterA = RotL64((aOrbiterA * 12739937231684038161U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13861225650900541642U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12620513474052058164U;
            aOrbiterK = RotL64((aOrbiterK * 18141974182442267181U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14163773386433257965U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5725700029399455855U;
            aOrbiterD = RotL64((aOrbiterD * 10446930901088908809U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 10U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterF, 18U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 53U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterK, 11U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 27U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 23U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterI, 5U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 40U)) + aOrbiterG) + aPhaseBWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 14274U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneC[((aIndex + 15884U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15557U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16047U)) & W_KEY1], 37U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15851U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15478U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14519U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 18U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererJ + RotL64(aScatter, 39U)) + 12690502671561165478U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 17519943923428102801U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 10705515807975331385U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 34U)) + 16586447272278538179U;
            aOrbiterC = (aWandererG + RotL64(aCross, 3U)) + 8006560996840971798U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 51U)) + 12928600185788857701U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 11U)) + 14240723153798267172U) + aPhaseBOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 47U)) + 8636219177994872072U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 26U)) + RotL64(aCarry, 43U)) + 7586790235186467512U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1103807034179512424U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7547526530239498693U;
            aOrbiterH = RotL64((aOrbiterH * 3360295583636013509U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8380239679344786397U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5690809173787433519U;
            aOrbiterF = RotL64((aOrbiterF * 5354724308093372953U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8390902801141804609U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3507306189192059486U;
            aOrbiterD = RotL64((aOrbiterD * 18336280496510253103U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6190745292098482871U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8065418693975056902U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6414621418430102589U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12111755051718111803U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7605877769709909297U;
            aOrbiterE = RotL64((aOrbiterE * 17525248694315944599U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5969794501112646237U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5127559299360591476U;
            aOrbiterA = RotL64((aOrbiterA * 4521563633438853069U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10593847754747739786U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4401750688524310121U;
            aOrbiterK = RotL64((aOrbiterK * 14265829318976633707U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6927893132508779499U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 4874009978647014479U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13340466017023540755U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 13146693487138744677U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3298472134223595298U;
            aOrbiterC = RotL64((aOrbiterC * 2145005258008477281U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 30U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterD, 58U));
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterF, 35U)) + aPhaseBWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterG, 47U));
            aWandererD = aWandererD + ((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 53U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 12U)) + aOrbiterB) + aPhaseBWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17063U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 16849U)) & W_KEY1], 12U));
            aIngress ^= (RotL64(mSource[((aIndex + 18107U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((aIndex + 17885U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18672U)) & W_KEY1], 57U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 19027U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 16865U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererK + RotL64(aCross, 56U)) + RotL64(aCarry, 35U)) + 2617613537256538553U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aIngress, 13U)) + 16642868916835132715U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 10860291124337073254U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 3U)) + 6432511273906902472U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 19U)) + 7505375005848241910U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 23U)) + 11086616004678821329U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 43U)) + 3298830587569881951U;
            aOrbiterC = (aWandererE + RotL64(aCross, 27U)) + 9775143140064220979U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 19U)) + 4147601326580823120U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12245920269898100415U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8391940489176734499U;
            aOrbiterI = RotL64((aOrbiterI * 9119606167674098007U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17876893379544668477U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 18301882058180370541U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16680384667098921309U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6869225862715140102U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15404118372589259800U;
            aOrbiterH = RotL64((aOrbiterH * 5766851935950389915U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17757381020518233814U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17677969146092374455U;
            aOrbiterC = RotL64((aOrbiterC * 3469432916562405063U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15783378556632870114U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 5792858258663697864U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12008981883482080427U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11737803388202260296U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16001927091970715330U;
            aOrbiterB = RotL64((aOrbiterB * 3062030309852922061U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1749586939123286632U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6169421068855905938U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12374789910763348695U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10073586820719728062U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17744171227198661555U;
            aOrbiterK = RotL64((aOrbiterK * 10658375268803957647U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1149819647337612792U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7725598665625892006U;
            aOrbiterJ = RotL64((aOrbiterJ * 15097586655234391559U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 26U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 14U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterC) + aPhaseCWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 51U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterC, 39U));
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 21U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 43U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aCross, 30U) + RotL64(aOrbiterI, 60U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererI, 26U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20144U)) & S_BLOCK1], 4U) ^ RotL64(mSource[((aIndex + 20411U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19118U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((aIndex + 19492U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20176U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21392U)) & W_KEY1], 46U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20277U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 20417U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererC + RotL64(aIngress, 5U)) + 13333509828310369865U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 7645352517103840797U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 41U)) + 5310766306660062655U) + aPhaseCOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 5165635069832352932U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 19U)) + 15684141764734281849U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 29U)) + 3327963374225061738U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 23U)) + 8625811794878848871U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 41U)) + 7598657468430485291U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 12U)) + 2881171216276746485U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10237691227222918101U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6419254255884834497U;
            aOrbiterB = RotL64((aOrbiterB * 3816625473642865305U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4238455444646479956U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14936613353493061492U;
            aOrbiterA = RotL64((aOrbiterA * 3544216916806292273U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15324699725208372627U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9506640480601832011U;
            aOrbiterD = RotL64((aOrbiterD * 12819564111348390227U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3709149613660215641U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1724290199312754307U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12597580418257897965U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13191172833570139194U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3686087945377837886U;
            aOrbiterJ = RotL64((aOrbiterJ * 10883609557429936283U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10418330386245397022U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5383531313632347245U;
            aOrbiterI = RotL64((aOrbiterI * 2987755379396160073U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7414716553072652212U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11301761123966206201U;
            aOrbiterH = RotL64((aOrbiterH * 1546727321088592187U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8570229732236388847U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8773754460060264773U;
            aOrbiterK = RotL64((aOrbiterK * 3251360788932563495U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13636929800504199371U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5486599841558573720U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2867914211589815153U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 14U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 36U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aCross, 48U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterC, 57U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + aPhaseCWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterB, 41U));
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 12U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 52U) + aOrbiterD) + RotL64(aOrbiterE, 53U)) + aPhaseCWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterA, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 41U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23109U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadA[((aIndex + 23105U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22274U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22951U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23791U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22906U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23359U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24253U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 44U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererI + RotL64(aPrevious, 42U)) + 13960289014350612206U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 3U)) + 3483331015269589730U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 35U)) + 6873299241002444518U) + aPhaseCOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 37U)) + 3562094007125534229U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 11422367439932782705U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 57U)) + 532453428514259816U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 28U)) + RotL64(aCarry, 23U)) + 17810941465810193088U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 11U)) + 11869759058631106331U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 19U)) + 8837581071876177566U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17185378327053837778U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7578253375676981500U;
            aOrbiterD = RotL64((aOrbiterD * 13371647568758721729U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17112646434432814442U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14949096407295697881U;
            aOrbiterH = RotL64((aOrbiterH * 14770977858283051753U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4259590620758467836U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6534899413644542303U;
            aOrbiterA = RotL64((aOrbiterA * 7987609419215568661U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2637407498893694243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15819295597921425711U;
            aOrbiterE = RotL64((aOrbiterE * 5202015597375051399U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6373559542002699718U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11694562937392022505U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9311557972331218597U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3308736483775453062U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12749929710650475901U;
            aOrbiterI = RotL64((aOrbiterI * 248428400724560945U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1569528215675579656U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1044077933631689572U;
            aOrbiterF = RotL64((aOrbiterF * 6443796233912755143U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8393422728124537471U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2002732612516530754U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13702146823622364279U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13469191942843147943U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7633171368709520560U;
            aOrbiterC = RotL64((aOrbiterC * 9713514012478203047U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterG, 4U)) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterC, 53U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterE, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 43U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 29U)) + aOrbiterD) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 34U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 14U) + aOrbiterI) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 39U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterG, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25484U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadA[((aIndex + 27024U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25823U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26222U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24890U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27197U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26775U)) & S_BLOCK1], 36U) ^ RotL64(aFireLaneD[((aIndex + 26304U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 39U)) + 14499676118633326000U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 43U)) + 17191273593018552288U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 48U)) + 4085176294948097737U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 29U)) + 11112671474158908186U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 8745787969012266485U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 18074049663777707948U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 23U)) + 2543758649719164688U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 13U)) + 4659584749412700523U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 54U)) + RotL64(aCarry, 43U)) + 974639159259871273U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9211220687971081987U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8567024626862182714U;
            aOrbiterC = RotL64((aOrbiterC * 7755874089832496393U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5803002132294840900U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11968489432878148467U;
            aOrbiterK = RotL64((aOrbiterK * 4501441062617123165U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9470807228394903442U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1692347973120388469U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17433393164156231575U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16510815732690193145U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 755159406833096510U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14091736464659561165U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1518824876475937620U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 701225390867330446U;
            aOrbiterH = RotL64((aOrbiterH * 12264618860580199927U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8425976693733003889U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7182176375442410367U;
            aOrbiterF = RotL64((aOrbiterF * 8860605703761731859U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4546566785167467924U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2593340999038753749U;
            aOrbiterB = RotL64((aOrbiterB * 10152461487764567563U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9756331608356622299U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5511625814747641978U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4806076157539829529U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8694400787420160733U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12648969491371382682U;
            aOrbiterI = RotL64((aOrbiterI * 5346585704222643759U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 14U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 26U)) + aOrbiterK) + aPhaseDWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 34U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 47U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 43U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterC, 13U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterI, 6U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27618U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 29016U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27419U)) & W_KEY1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 28989U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28791U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28201U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29010U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29910U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 35U)) + (RotL64(aCross, 19U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 2177539223979303669U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 3962004686551521471U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 14U)) + 8457602312617147662U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 57U)) + 18011802451816510632U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 47U)) + 9046101759168876832U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 39U)) + 11135620637431969597U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 51U)) + 15913029940697999701U) + aPhaseDOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 29U)) + 16304193109948135982U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 6U)) + RotL64(aCarry, 35U)) + 13208892298820080981U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4182377898949419225U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13970137023071326151U;
            aOrbiterG = RotL64((aOrbiterG * 9075061559681739865U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8402396284835248583U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8859190834060657829U;
            aOrbiterC = RotL64((aOrbiterC * 13552418608113716117U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9760005337757990392U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14108277760135744897U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4474681104256093885U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12226316121949012350U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3456392186754113960U;
            aOrbiterE = RotL64((aOrbiterE * 8704729827929941215U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5004087958637038973U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7176881295123125567U;
            aOrbiterK = RotL64((aOrbiterK * 15272157962928021009U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10889800478505074438U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13728832441482547824U;
            aOrbiterI = RotL64((aOrbiterI * 17588477761978646139U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17345665880706866772U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 301139993853297566U;
            aOrbiterD = RotL64((aOrbiterD * 5812445396758354505U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2061389844760610160U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13631862266139238355U;
            aOrbiterF = RotL64((aOrbiterF * 143613352104722701U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10767186080827509622U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4893486019456886013U;
            aOrbiterA = RotL64((aOrbiterA * 5194746459545610901U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterG, 4U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 51U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterI, 21U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterK, 35U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 10U) + aOrbiterA) + RotL64(aOrbiterF, 39U));
            aWandererE = aWandererE + ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterE, 10U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterB, 47U)) + aPhaseDWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31912U)) & S_BLOCK1], 24U) ^ RotL64(aKeyRowReadA[((aIndex + 31456U)) & W_KEY1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32282U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31951U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31959U)) & S_BLOCK1], 12U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31943U)) & W_KEY1], 53U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererI + RotL64(aIngress, 42U)) + 17470880031634374199U;
            aOrbiterA = (aWandererG + RotL64(aCross, 35U)) + 757565846006937746U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 11U)) + 9419282475801345674U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 47U)) + 2014248014107898196U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aIngress, 53U)) + 15113928519446490441U) + aPhaseDOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 30U)) + RotL64(aCarry, 39U)) + 7346126964886259935U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 5594123113093162359U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 5659237263369402005U;
            aOrbiterH = (aWandererB + RotL64(aCross, 19U)) + 11565709683423969703U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16782863743534856287U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13499100900072115907U;
            aOrbiterK = RotL64((aOrbiterK * 5567729598873214433U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11414447651044205242U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7545993795121430538U;
            aOrbiterC = RotL64((aOrbiterC * 10758488381206257261U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11778229237616454988U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2544793391976514665U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4021060413798523299U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9972156716619459164U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17651030383827445664U;
            aOrbiterF = RotL64((aOrbiterF * 6742914240706775487U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17439147296849134543U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10021926927948343656U;
            aOrbiterB = RotL64((aOrbiterB * 18139540407315440909U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9309867875882669289U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14951424455944346337U;
            aOrbiterG = RotL64((aOrbiterG * 10569523948169951309U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2166343974068770659U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11386993629011562026U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3091639433512536097U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5747849744680120960U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4019290369160113026U;
            aOrbiterD = RotL64((aOrbiterD * 5567515306039646735U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3820540009554769592U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8210747198363020939U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16215133106542452509U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterE, 58U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 19U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterH, 4U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 27U)) + aOrbiterG) + aPhaseDWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterB, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterE, 13U));
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterG, 46U));
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 37U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 22U) + aOrbiterE) + RotL64(aOrbiterF, 57U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 40U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 51U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4164U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 6044U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5515U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7139U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3236U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6543U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 28U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 12583180859826261500U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 3U)) + 9067093488553721468U) + aPhaseEOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aIngress, 53U)) + 12173106198862881754U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 60U)) + 11333491014394592654U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 3511883526940919554U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 47U)) + 7416810692106273044U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 8341174972619784110U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2220852854836962979U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8090781422229383825U;
            aOrbiterJ = RotL64((aOrbiterJ * 578293950675644397U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2338801236599102223U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12484514711848308104U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10364216764253366067U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13684861340589131816U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12796636819991873058U;
            aOrbiterF = RotL64((aOrbiterF * 5533508014234835669U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7634198650894837690U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 10240326122201201762U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8758703497719125901U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4162814763739453934U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2766504649149048469U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16731843453895178671U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11051393030148769655U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17687055068651386665U;
            aOrbiterB = RotL64((aOrbiterB * 1042927176246229537U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3353615315436983420U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5971640796220306310U;
            aOrbiterH = RotL64((aOrbiterH * 15804313508835034807U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 5U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 41U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterJ, 57U)) + aPhaseEWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 27U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterH, 18U)) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 13283U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 10019U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 14967U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneC[((aIndex + 9567U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10086U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13862U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15957U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 41U)) + (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererE + RotL64(aPrevious, 35U)) + 12426357877879529292U;
            aOrbiterK = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 12604900366173639176U) + aPhaseEOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 13511119007338929401U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 9878720081166788060U) + aPhaseEOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 13U)) + 15463195409806395076U;
            aOrbiterF = (aWandererC + RotL64(aCross, 51U)) + 6407922778852833423U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 26U)) + 7690427254160734016U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18030974031722143619U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17983938038322737041U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12479365337221685413U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16605512170117753884U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 681802273302348322U;
            aOrbiterB = RotL64((aOrbiterB * 14608920184802647123U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15550312921312083819U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17824154101711884508U;
            aOrbiterE = RotL64((aOrbiterE * 7358612830654795357U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1939207786756735430U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3132864634777826569U;
            aOrbiterK = RotL64((aOrbiterK * 13606281919426730325U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12822929773923954849U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16576106045887115660U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16370914370769903051U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2398825881649235260U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13700821892926092479U;
            aOrbiterF = RotL64((aOrbiterF * 10830623703416956043U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2439833784883391606U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15870638514107637833U;
            aOrbiterD = RotL64((aOrbiterD * 3797380922767479287U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterJ, 60U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 4U) + aOrbiterB) + RotL64(aOrbiterH, 37U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 46U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23809U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 22700U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 18985U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23488U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24282U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18698U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23038U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererA + RotL64(aIngress, 56U)) + 13714409587461539863U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 19U)) + 14101156723903265839U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 7063754562895369001U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 12320578575245519386U) + aPhaseEOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 11744826789631008424U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 47U)) + 8744816505096675597U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 35U)) + 10405435520084528645U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1463157688070683543U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12379603577919617703U;
            aOrbiterK = RotL64((aOrbiterK * 14858901470015109311U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1343439118031348146U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16118850268070235540U;
            aOrbiterA = RotL64((aOrbiterA * 11184386483735388257U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14116264435819277136U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 5251698273012432109U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1495818611622063967U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14806408656041403829U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11569345414052398227U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9913158908301414861U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17063874769147888574U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 9927420478679581917U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9042782809534196563U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 2550285599827162167U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17801534123304996448U;
            aOrbiterD = RotL64((aOrbiterD * 2160836889363614721U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6456685241021762041U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17064208177372969289U;
            aOrbiterE = RotL64((aOrbiterE * 13726627607233302493U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 19U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 51U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 3U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterF, 58U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterE, 29U)) + aPhaseEWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterB, 13U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 37U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31537U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 31624U)) & S_BLOCK1], 26U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 28494U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32572U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31067U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24749U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 29529U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererG + RotL64(aIngress, 19U)) + 13350544654542863236U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 12364346790125404372U) + aPhaseEOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 3U)) + 9738750172849512764U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 57U)) + 3781373837635491421U;
            aOrbiterH = (aWandererF + RotL64(aCross, 51U)) + 16635020317512702337U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 5383653921676231276U) + aPhaseEOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 44U)) + RotL64(aCarry, 51U)) + 10181959815492056493U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10005510924273927017U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9524687662265740565U;
            aOrbiterB = RotL64((aOrbiterB * 13687380438646756931U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4259138552009771014U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8973051213213726023U;
            aOrbiterE = RotL64((aOrbiterE * 12625091476068190979U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 17602611840127337490U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8218984546932905269U;
            aOrbiterC = RotL64((aOrbiterC * 17504305273683304231U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 18102186122213487888U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2629927500298092976U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6983280164448292723U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2491581597835795234U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9506602492971620955U;
            aOrbiterH = RotL64((aOrbiterH * 9559829640915637163U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13422942713680612924U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15037354693234876601U;
            aOrbiterK = RotL64((aOrbiterK * 12692376075738621447U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12896066842192894694U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2202952306291905855U;
            aOrbiterJ = RotL64((aOrbiterJ * 6779368532763429997U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 13U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 53U));
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterE, 30U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + aPhaseEWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterC, 21U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 50U) + RotL64(aOrbiterC, 39U)) + aOrbiterF) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3387U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((aIndex + 7538U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6616U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1415U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4639U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3977U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCross, 37U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererI + RotL64(aScatter, 57U)) + 1087148170018530502U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 10U)) + 15530846874509311414U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 41U)) + 16987358651515511212U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 12504143181007924259U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 39U)) + 393322117322732418U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 14325937299241887166U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 43U)) + 9395262907017475742U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 37U)) + 13658510441418344769U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 35U)) + 6410754322737005336U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 30U)) + 9257290738538818434U) + aPhaseFOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 7489828960857692286U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4118778591214588387U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16619215231168796563U;
            aOrbiterI = RotL64((aOrbiterI * 14876884956536265157U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11326283811003573430U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1865401866017614604U;
            aOrbiterC = RotL64((aOrbiterC * 8378326058282460073U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 670150121105733604U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1499331510641068749U;
            aOrbiterK = RotL64((aOrbiterK * 16623742535540383107U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1116410848560838532U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2696841341036281779U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9598953298074904869U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5487352391229549881U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 12008243050943342979U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9087261224804582459U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 552859665927882960U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8426942688524814473U;
            aOrbiterD = RotL64((aOrbiterD * 10916963622695549105U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1613287981244830815U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15592897923468694288U;
            aOrbiterA = RotL64((aOrbiterA * 6600750586743893303U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7629853970631002676U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13778028957247561272U;
            aOrbiterF = RotL64((aOrbiterF * 4063798788229605659U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2932956928094332652U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14855524972646900872U;
            aOrbiterG = RotL64((aOrbiterG * 9546042275547649745U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11071597794692793784U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6327727700942234552U;
            aOrbiterH = RotL64((aOrbiterH * 15301120263944789797U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5147576281502110428U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1087148170018530502U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18045084130531645749U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 5U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterF, 27U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 22U) + aOrbiterI) + RotL64(aOrbiterC, 48U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 23U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterC, 35U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 56U) + aOrbiterK) + RotL64(aOrbiterE, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 13U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterK, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 51U));
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 54U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14403U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((aIndex + 12999U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 14252U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14961U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13401U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15247U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8521U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 58U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 16183871922837164759U;
            aOrbiterA = (aWandererA + RotL64(aCross, 13U)) + 7002058258090219055U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 6U)) + 5650868611888303705U) + aPhaseFOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aScatter, 47U)) + 11899839660943876690U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 39U)) + 15349649504488111111U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 14060149569086744970U;
            aOrbiterF = (aWandererK + RotL64(aCross, 56U)) + 12920917574225030112U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 11U)) + 2831994965175330135U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 19U)) + 18312543585028439192U;
            aOrbiterE = (aWandererG + RotL64(aCross, 43U)) + 11657562205118394239U;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 41U)) + 10850792819281246052U) + aPhaseFOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17810371216216125323U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7963413941144223128U;
            aOrbiterI = RotL64((aOrbiterI * 534217972450595401U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5498715358793875584U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9256727548911651373U;
            aOrbiterG = RotL64((aOrbiterG * 10498848323914000989U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17246360111302191699U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 18309978718113983369U;
            aOrbiterF = RotL64((aOrbiterF * 18267472694666221077U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3100998994319502921U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8129301860291235970U;
            aOrbiterD = RotL64((aOrbiterD * 17847033539279176187U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1889641029473279114U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16538494307002917945U;
            aOrbiterA = RotL64((aOrbiterA * 8081488217920885783U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5432230549146849322U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2634437941396090817U;
            aOrbiterJ = RotL64((aOrbiterJ * 7612999214758935211U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16940172599174185058U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13151669140593952203U;
            aOrbiterC = RotL64((aOrbiterC * 16225319638131723487U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 3995064294869931681U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 913081077665768816U;
            aOrbiterB = RotL64((aOrbiterB * 9299514648768060453U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 2469001696075411481U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2167390955194185443U;
            aOrbiterK = RotL64((aOrbiterK * 11805065572289005223U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1574066406534010796U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8736976961589874013U;
            aOrbiterH = RotL64((aOrbiterH * 5980070607180321955U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4233621443153132083U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16183871922837164759U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4030569514959370895U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 58U) + aOrbiterE) + RotL64(aOrbiterA, 52U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 41U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 26U) + aOrbiterI) + RotL64(aOrbiterH, 5U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 11U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 43U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterD, 20U)) + aPhaseFWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterK, 3U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 42U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18793U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 23833U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 17792U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22978U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21272U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18187U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 18005U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererG + RotL64(aScatter, 57U)) + 16462052553719977502U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 21U)) + 12337064059566619581U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 51U)) + 15801005007094515447U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 38U)) + 8228706742665081656U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 11006723027845190869U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 18173765337829177450U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 11U)) + 530215083653542558U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 40U)) + RotL64(aCarry, 27U)) + 6608611827035564511U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 5U)) + 2246051826221626809U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 47U)) + 5228575308895381421U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 35U)) + 10999213210689606857U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3773371037240485696U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8887985779436152504U;
            aOrbiterK = RotL64((aOrbiterK * 698713082830739677U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11150566414723818350U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8336366151003049546U;
            aOrbiterF = RotL64((aOrbiterF * 9033771197242493699U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13233968794237090787U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8172558473508478819U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17837070423649268435U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 133564480283347997U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15104810248883567064U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 706802420642303533U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9138629520201127075U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13993086066341664080U;
            aOrbiterI = RotL64((aOrbiterI * 4875046427147105077U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6547273508580516932U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9838727018769865759U;
            aOrbiterA = RotL64((aOrbiterA * 11395273371936839815U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 11685694999526122626U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8945983172566303116U;
            aOrbiterG = RotL64((aOrbiterG * 17791527981004597623U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17606249889617356327U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9296903152000480008U;
            aOrbiterE = RotL64((aOrbiterE * 18066622289408024413U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14248192861977167583U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5467843420970464193U;
            aOrbiterJ = RotL64((aOrbiterJ * 10121398470914323221U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17072313558131700643U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7932446176598954438U;
            aOrbiterD = RotL64((aOrbiterD * 11684711939539349335U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15377107166135929052U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16462052553719977502U;
            aOrbiterB = RotL64((aOrbiterB * 9057188521274832217U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 46U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterG, 51U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterE, 26U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 57U));
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 37U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterF, 18U));
            aWandererB = aWandererB + (((RotL64(aScatter, 44U) + RotL64(aOrbiterH, 29U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 41U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32297U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 29871U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 31079U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 31374U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26259U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31357U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 32478U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 3U)) + 3238389262925516513U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 54U)) + 12381787182611386995U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 7883885539305181549U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 1185413044597727092U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 27U)) + 15219353497204773135U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 47U)) + 7533774715626734082U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 29U)) + 2599930450937763464U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 13U)) + 16074720663961214284U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 20U)) + RotL64(aCarry, 39U)) + 15483613196360051221U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 9396557867081376268U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 57U)) + 9668459976852660245U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9037269914643207212U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16936742640861088240U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1040172193161012227U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16481274825758546398U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 481851372837611166U;
            aOrbiterG = RotL64((aOrbiterG * 2225030139210599207U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13608921517203544108U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16930740723286214636U;
            aOrbiterE = RotL64((aOrbiterE * 2605108503821980865U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 902242902582149908U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1510861213079342977U;
            aOrbiterH = RotL64((aOrbiterH * 3309753895727400707U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7116243600304980310U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6631412278359709602U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11452627691392637463U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9246698682265275165U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8594373032014031450U;
            aOrbiterK = RotL64((aOrbiterK * 2550138341089957033U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15912837963877821048U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11404583513022627609U;
            aOrbiterF = RotL64((aOrbiterF * 17715204726760125357U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17295214920690244319U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 18315664494984189344U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17398893532076312945U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2474825506593695564U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4400473621592150441U;
            aOrbiterA = RotL64((aOrbiterA * 7098832854166953839U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15270166373215060119U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4331232225067306139U;
            aOrbiterC = RotL64((aOrbiterC * 2299883590703870703U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2176207815544347316U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3238389262925516513U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13104597690682251231U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 30U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterF, 14U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 35U));
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 23U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterB, 48U));
            aWandererF = aWandererF + (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 39U)) + aOrbiterG) + aPhaseFWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 27U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 53U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aIngress, 26U) + RotL64(aOrbiterD, 21U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3260U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 5810U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 5327U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 380U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3015U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 615U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 6U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererC + RotL64(aCross, 46U)) + RotL64(aCarry, 39U)) + 7790166497945719700U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 7136208896846119188U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 12123156943355100886U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aIngress, 23U)) + 5095546037880875199U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 5U)) + 17642705393916765992U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9918479837334416990U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4890009823843176466U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16898633181256061239U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17652590786213674124U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 870002527644696135U;
            aOrbiterH = RotL64((aOrbiterH * 915408393979165539U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12545429703552643682U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5310272867406182581U;
            aOrbiterJ = RotL64((aOrbiterJ * 10420003334833925011U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3264719049050179440U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1967241238180278937U;
            aOrbiterD = RotL64((aOrbiterD * 13004319774269457957U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 773883832927040736U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12766817190261232485U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7448864556802318431U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + aPhaseGWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterH, 56U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15419U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((aIndex + 16384U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13478U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10116U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15056U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 15410U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 13U)) + (RotL64(aCarry, 47U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 8975885703279267062U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 8664844915562660637U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 60U)) + 12281774799736296726U) + aPhaseGOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 15347461352311329726U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 11U)) + 12967500561828907834U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5002833859280402726U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11908257536954668983U;
            aOrbiterJ = RotL64((aOrbiterJ * 4384790916151202785U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17017174811949227162U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16851323125613931180U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12446990992858763577U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13469326957728686706U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5228638551056105241U;
            aOrbiterB = RotL64((aOrbiterB * 13369947664646167255U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11945166198089308564U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16268645041872996022U;
            aOrbiterC = RotL64((aOrbiterC * 5391448793718370911U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14781204627695095701U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5365325354838101092U;
            aOrbiterG = RotL64((aOrbiterG * 8017284997946310807U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 42U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterH, 5U));
            aWandererE = aWandererE + (((RotL64(aCross, 26U) + RotL64(aOrbiterC, 58U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 13U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + aPhaseGWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22632U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((aIndex + 22958U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 23075U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17481U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17578U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23976U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 60U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 17081642665820489793U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 14468854040067229623U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 2249450222593057429U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 48U)) + 14964389079511378664U) + aPhaseGOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 35U)) + 17003491054252360650U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12710882240582032588U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9887078182156755359U;
            aOrbiterB = RotL64((aOrbiterB * 8205865025853482573U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7665284531810584704U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7304284015511876717U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6193179739025093929U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5517927023543751734U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17704756310857362759U;
            aOrbiterI = RotL64((aOrbiterI * 15826832172923213591U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11347400363019508578U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11696395232760991243U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9725231749679442003U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10875780291242873583U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7808740614343437672U;
            aOrbiterE = RotL64((aOrbiterE * 8889516201913716283U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 39U)) + aOrbiterB) + aPhaseGWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterB, 20U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 28U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29312U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 26404U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25274U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27213U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27480U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27112U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 52U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 10881271196314989997U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 6406461249988567558U) + aPhaseGOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aCross, 19U)) + 17255067918280095959U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 16690850682497718411U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 52U)) + 5576201059361086866U) + aPhaseGOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 11991259685693687554U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14652535244217836909U;
            aOrbiterK = RotL64((aOrbiterK * 18283959577075524171U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1701789037170782122U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 953429054903473833U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13482379459700651427U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12064513610469714211U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7993881398822002424U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11572884842788918377U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14421313768013320050U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11112386845630998889U;
            aOrbiterI = RotL64((aOrbiterI * 11771526352030371669U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17069630896535699015U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3308240081138623373U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10449509484417835159U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 39U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterI, 27U));
            aWandererI = aWandererI + (((RotL64(aScatter, 48U) + aOrbiterI) + RotL64(aOrbiterF, 54U)) + aPhaseGWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 11U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
        // ingress from: aExpandLaneA, aExpandLaneB, aExpandLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneB backward forced, aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6934U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 4749U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6165U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1161U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6184U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 5482U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererH + RotL64(aCross, 37U)) + 12029393034357490020U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 4526754731580694987U;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 17060419646421271853U) + aPhaseHOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 11U)) + 4128488893837059683U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 29U)) + 12706894827547160110U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12506324593645825056U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12581344490649250025U;
            aOrbiterE = RotL64((aOrbiterE * 16311882267466003291U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14357032418199130132U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 15341977701796331249U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6332369248718076031U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7086602307544733241U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12398300065276832486U;
            aOrbiterI = RotL64((aOrbiterI * 18157408831225635333U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2499745046076601988U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7249361592814001829U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14597139848072319685U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3254456186337366437U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3472973415969046680U;
            aOrbiterG = RotL64((aOrbiterG * 14583566953969168353U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 14U) + aOrbiterG) + RotL64(aOrbiterA, 37U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 19U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterD, 50U));
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterE, 11U)) + aPhaseHWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13544U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 11535U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10177U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11716U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9885U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 8689U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 30U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 7651355040951791298U) + aPhaseHOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 54U)) + 13988210277931659312U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 9846849412579537783U;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 12746719939495876158U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aIngress, 43U)) + 11498066185182895284U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11101058955193080232U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15513734459555672046U;
            aOrbiterG = RotL64((aOrbiterG * 6974281215677538561U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 15711108675349394643U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4771231759949468556U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9806191054594333615U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11449258010811305256U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17036938391509986723U;
            aOrbiterA = RotL64((aOrbiterA * 7411466953205347639U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6999245666776654250U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2106819066263369528U;
            aOrbiterI = RotL64((aOrbiterI * 13005885810757743129U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12716183358903477216U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16752724547046059889U;
            aOrbiterB = RotL64((aOrbiterB * 11475905692393034141U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 10U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 48U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterB, 37U));
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterI, 50U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererB, 48U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24528U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 20270U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23801U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20987U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16634U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 21660U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aIngress, 3U)) + 5573188770530340913U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 1431772230889897111U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 44U)) + 4809192776429682319U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 5576603692574369341U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 2720143226007220386U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17220328778565331629U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9629485808442089423U;
            aOrbiterJ = RotL64((aOrbiterJ * 18349580416082045015U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1136998437010390983U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11893390497814523841U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5329621622743089531U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1764986431917532370U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 1741014798007010376U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13414914086049500731U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12221368453236547044U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7694538641172350430U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8439120733670016501U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17472344518811560603U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3308740700728172984U;
            aOrbiterK = RotL64((aOrbiterK * 15290400462887712083U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 26U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + aPhaseHWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 57U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25249U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 27689U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 26682U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24922U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28796U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 29778U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 44U) ^ RotL64(aCross, 57U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 12690502671561165478U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 17519943923428102801U) + aPhaseHOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 11U)) + 10705515807975331385U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 16586447272278538179U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 56U)) + 8006560996840971798U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12928600185788857701U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14240723153798267172U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7446040187505339853U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8636219177994872072U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7586790235186467512U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15052686382507614169U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1103807034179512424U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 7547526530239498693U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3360295583636013509U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8380239679344786397U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5690809173787433519U;
            aOrbiterI = RotL64((aOrbiterI * 5354724308093372953U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8390902801141804609U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3507306189192059486U;
            aOrbiterJ = RotL64((aOrbiterJ * 18336280496510253103U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 39U)) + aOrbiterI) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 19U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 26U) + aOrbiterB) + RotL64(aOrbiterJ, 48U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
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
