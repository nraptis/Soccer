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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xADCE17C7FC5F9465ULL + 0xD93F9F00F72DA8C2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBCE7894578FA3F41ULL + 0xFA28EB6161DB4751ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC20FD484606DF095ULL + 0xCCE1BF67C51D7262ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9BF603CA14A55169ULL + 0x9DD458BD5619ADACULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x94B5100ED5C6681FULL + 0xFAC079B0F4B4305BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC1444DC2DF4B5A0FULL + 0xBB0A7FF757A90ACCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB883EC03E45007D5ULL + 0xD191872ADC97250FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xABCED4EB2EDD7C27ULL + 0xCAD913B6F9FAB02DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDC3221C00F6A1DF7ULL + 0xE0856DD10E6CED5CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCA754E811BF406B1ULL + 0xD56924016C541DE7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD51E0717B6ED8773ULL + 0xB62D11E3E0A22A23ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEE9CFAA93B45E833ULL + 0xEC2F80FEED910660ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB6F15FF30BF7DC8BULL + 0xCAD350461F063741ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF204C281914671C1ULL + 0xD96F372A890A7186ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9D78DF092B360D9FULL + 0xAE8522E84FC3CB51ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBCDD1F65F1A32779ULL + 0xA677892A2E9AD133ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4315U)) & S_BLOCK1], 29U) ^ RotL64(pSnow[((aIndex + 4891U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 3514U)) & S_BLOCK1], 18U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 2828U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 6U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 39U)) + 13296600294247799698U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 37U)) + 5818503518080877515U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 21U)) + 6735784238734173597U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 23U)) + 7368398209488856201U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 35U)) + 961734029066455638U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 53U)) + 797011946660892011U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 18U)) + RotL64(aCarry, 3U)) + 12841876018396622350U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 16213253970483895623U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 15186950557113470375U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 5U)) + 5117930310827477341U) + aNonceWordM;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 28U)) + 12265429373166094162U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13920531346698601568U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 14695405206998211456U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 13950964363414164279U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7851960904825938443U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9501511171732550190U;
            aOrbiterF = RotL64((aOrbiterF * 5614164120361489613U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5663365182245722077U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9607860124321315555U;
            aOrbiterC = RotL64((aOrbiterC * 3461820361914280601U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 18171052650586819280U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3442698321538580861U;
            aOrbiterB = RotL64((aOrbiterB * 6317525514963824829U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1491052813469258970U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3956599824067616133U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2928600779267623085U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10963841237346073453U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2303020125591252534U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 9969099842343321981U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14503856057958162356U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11147548150090597694U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11856382308792700441U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9191681438318311481U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13556072770381999852U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18316231099054203683U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10103207278550444685U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10415809965217261104U;
            aOrbiterD = RotL64((aOrbiterD * 16562732599511350217U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17435033201864058457U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5540494424887364682U;
            aOrbiterH = RotL64((aOrbiterH * 18230910315317249045U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18020151683897013854U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13296600294247799698U;
            aOrbiterJ = RotL64((aOrbiterJ * 10000194329456668845U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 6U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 14U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + aNonceWordK);
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 50U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterA, 13U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 37U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 60U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 57U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 52U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordG);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10188U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9573U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 8566U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((aIndex + 7485U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 14U) + RotL64(aPrevious, 53U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 29U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aCross, 53U)) + 6024062041314952357U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 44U)) + RotL64(aCarry, 47U)) + 18340757093658015585U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 47U)) + 11911120493880346751U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 37U)) + 17428074353884654439U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = (aWandererH + RotL64(aScatter, 13U)) + 12790849760814795936U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 12633397052172117800U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 34U)) + 11946150433665237945U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 16842157900909419285U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 51U)) + 14186235783224155962U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 23U)) + 13284904542579767591U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 5U)) + 11609181965078844357U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9628562297095374984U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7850281529011259759U;
            aOrbiterJ = RotL64((aOrbiterJ * 17611485102925470357U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 257458718073794527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10693404545773519306U;
            aOrbiterC = RotL64((aOrbiterC * 14821443722828498323U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3430519236533871460U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6183054506953198055U;
            aOrbiterB = RotL64((aOrbiterB * 6121082743789970911U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2905610989884221654U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4472163910775333862U;
            aOrbiterA = RotL64((aOrbiterA * 7770678426310856745U), 27U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 16870142883133769663U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1403692060594816451U;
            aOrbiterI = RotL64((aOrbiterI * 9740854430251597879U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16904169913507057108U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4773518591580333357U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5306070307776061267U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6528141733853494275U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11254806909313951442U;
            aOrbiterE = RotL64((aOrbiterE * 6316669786405548827U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6857506858448143407U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2855763534355983644U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16881334940165182415U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12328391751024624740U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16475072086109949522U;
            aOrbiterH = RotL64((aOrbiterH * 15218626930666825883U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15505670341076785424U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6972128419331939330U;
            aOrbiterG = RotL64((aOrbiterG * 12206069109180246067U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7151546362283646210U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6024062041314952357U;
            aOrbiterF = RotL64((aOrbiterF * 10243806128059850493U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 28U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 51U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 14U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterK, 39U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aIngress, 58U) + RotL64(aOrbiterI, 60U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 43U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterD, 37U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterA, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11237U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12840U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 13873U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 11785U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aCross, 52U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aScatter, 41U)) + 3105313968748067810U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 39U)) + 9977249451119627064U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 53U)) + 17941392803495349366U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 26U)) + 4279533326705471133U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 5U)) + 13983828966811580039U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 3983490984234810378U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 308786542215259956U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 28U)) + RotL64(aCarry, 47U)) + 8443607695364427037U) + aNonceWordK;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 19U)) + 14939626441464340668U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 43U)) + 9350693577306121110U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 13U)) + 1717071159396961752U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15911765265202100610U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14898546272333182767U;
            aOrbiterE = RotL64((aOrbiterE * 2674900543810733067U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 3560903518513465868U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5367062725726860234U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8521908836601319553U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15233321480618877327U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9288449812290126074U;
            aOrbiterI = RotL64((aOrbiterI * 6815298520404038519U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5504840529511585676U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6825598386801620046U;
            aOrbiterK = RotL64((aOrbiterK * 11666542445846250077U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6433024450721339470U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 97934156644929458U;
            aOrbiterD = RotL64((aOrbiterD * 8630530773006923215U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3260053604798744515U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16539416623243059076U;
            aOrbiterH = RotL64((aOrbiterH * 12199577351166064503U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9814290051339038920U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13280156404507444041U;
            aOrbiterB = RotL64((aOrbiterB * 15269010043398910061U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11853942590993546833U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13207869904312989977U;
            aOrbiterG = RotL64((aOrbiterG * 15503461937625795969U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14536032167989376750U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3693282775047432356U;
            aOrbiterF = RotL64((aOrbiterF * 5290349323647887877U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5803176485246280271U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 16702526675475954730U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 13695676754973145769U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16454171963808313625U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3105313968748067810U;
            aOrbiterA = RotL64((aOrbiterA * 16572687178789102843U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 54U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterH, 27U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterH, 37U)) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + aNonceWordF);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 24U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterF, 51U));
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterF, 13U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 48U) + aOrbiterJ) + RotL64(aOrbiterA, 34U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterI, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18773U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 17887U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18803U)) & S_BLOCK1], 46U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 19199U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 34U) + RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 14U)) + 1393781663398437180U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 43U)) + 17414594746688585273U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 2823888497053071250U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 19U)) + 17032631958617884859U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 39U)) + 15222697630461125019U) + aNonceWordN;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 21U)) + 15737414920751551780U;
            aOrbiterK = (aWandererF + RotL64(aCross, 37U)) + 1357196111055783001U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 51U)) + 5315122321649251691U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 46U)) + 7893744655508595974U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 16721939414324611738U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 3444375866323610848U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1825716513674511632U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15582066843912467318U;
            aOrbiterI = RotL64((aOrbiterI * 12765146555943757373U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15673590949193923915U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13887365046280406413U;
            aOrbiterD = RotL64((aOrbiterD * 3169061375011420121U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12730414371734709356U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4819112390640821927U;
            aOrbiterJ = RotL64((aOrbiterJ * 8782547948627685451U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3089925954422937464U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7180179304678622530U;
            aOrbiterK = RotL64((aOrbiterK * 16118051565147747413U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17030269962085008657U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 6675917351883004046U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14134335325316949687U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12572022803491077491U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2801421744689267375U;
            aOrbiterA = RotL64((aOrbiterA * 315045745990934023U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4335148696780313055U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12526298573395110141U;
            aOrbiterB = RotL64((aOrbiterB * 11276803410698178607U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6984239833558496091U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12195433952105336808U;
            aOrbiterG = RotL64((aOrbiterG * 8642600547427664495U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6392683095502982341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18047201953488013325U;
            aOrbiterE = RotL64((aOrbiterE * 16151795290455603489U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15433458942878109208U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1700365768743794306U;
            aOrbiterH = RotL64((aOrbiterH * 16151638348775286903U), 19U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 10951473638533187729U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 1393781663398437180U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 2661447713922232789U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 46U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 23U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 36U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterH, 41U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 47U));
            aWandererK = aWandererK + (((RotL64(aIngress, 26U) + aOrbiterJ) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterH, 19U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterD, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 21U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 58U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 50U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordA);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25061U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((aIndex + 24820U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26246U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 25918U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 4U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 2617613537256538553U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 41U)) + 16642868916835132715U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 10860291124337073254U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 24U)) + 6432511273906902472U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 13U)) + 7505375005848241910U;
            aOrbiterH = (aWandererC + RotL64(aCross, 27U)) + 11086616004678821329U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 47U)) + 3298830587569881951U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 35U)) + 9775143140064220979U) + aNonceWordJ;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 13U)) + 4147601326580823120U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 52U)) + 12245920269898100415U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 29U)) + 8391940489176734499U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 17876893379544668477U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 18301882058180370541U;
            aOrbiterC = RotL64((aOrbiterC * 16680384667098921309U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6869225862715140102U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 15404118372589259800U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 5766851935950389915U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 17757381020518233814U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17677969146092374455U;
            aOrbiterA = RotL64((aOrbiterA * 3469432916562405063U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15783378556632870114U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5792858258663697864U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12008981883482080427U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11737803388202260296U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16001927091970715330U;
            aOrbiterG = RotL64((aOrbiterG * 3062030309852922061U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1749586939123286632U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6169421068855905938U;
            aOrbiterF = RotL64((aOrbiterF * 12374789910763348695U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10073586820719728062U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17744171227198661555U;
            aOrbiterJ = RotL64((aOrbiterJ * 10658375268803957647U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1149819647337612792U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7725598665625892006U;
            aOrbiterK = RotL64((aOrbiterK * 15097586655234391559U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13930096050550704122U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 3632241034947389647U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8442222389196610427U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17933893495867517142U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7888594392078082482U;
            aOrbiterI = RotL64((aOrbiterI * 9809847720610861237U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10805303827043372168U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2617613537256538553U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3940471942234248791U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 41U));
            aWandererD = aWandererD + (((RotL64(aCross, 30U) + RotL64(aOrbiterH, 26U)) + aOrbiterD) + aNonceWordA);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 51U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 37U)) + aNonceWordL) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterG, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 44U) + aOrbiterF) + RotL64(aOrbiterA, 6U));
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterK, 53U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 53U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31750U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32684U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30675U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30917U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 14U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 16189787374324972735U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 6U)) + RotL64(aCarry, 57U)) + 17563763730956242224U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 35U)) + 10572803498593789385U;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 47U)) + 7713105232072974166U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 23U)) + 10760839534772718139U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 13397069448391230253U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 43U)) + 4569255679998375682U) + aNonceWordP;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 41U)) + 9888769350817876949U;
            aOrbiterK = (aWandererK + RotL64(aCross, 37U)) + 11351796060878856300U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 39U)) + 18153775071965707204U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 52U)) + 1282846411145853435U) + aNonceWordL;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16457743979262460660U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 173493260775251032U;
            aOrbiterI = RotL64((aOrbiterI * 4935807229040883505U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3927345926316409630U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5158769729850853623U;
            aOrbiterF = RotL64((aOrbiterF * 2446452358663812945U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12331351600010165154U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3940794200348684050U;
            aOrbiterA = RotL64((aOrbiterA * 13248997263062075043U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11248514843822945425U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1391497323278226522U;
            aOrbiterJ = RotL64((aOrbiterJ * 8376841806072565005U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13265623528678787307U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2802033745265647317U;
            aOrbiterG = RotL64((aOrbiterG * 3437626962562016147U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6938444301018051844U) + aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1086544666755559028U;
            aOrbiterK = RotL64((aOrbiterK * 16039728388882079889U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16156443117365816536U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3619942859562697142U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 7589346043159112151U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 17681848914912743292U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8848238631758130416U;
            aOrbiterD = RotL64((aOrbiterD * 810402256099500607U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6019192027793541890U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16917288363166352778U;
            aOrbiterH = RotL64((aOrbiterH * 17673667086593738207U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5598218150530046752U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17285995539011279010U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15621233176885995065U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12380627610747299268U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16189787374324972735U;
            aOrbiterC = RotL64((aOrbiterC * 2144714828503219209U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (RotL64(aOrbiterK, 44U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterB, 30U)) + aNonceWordG);
            aWandererI = aWandererI + (((RotL64(aCross, 10U) + aOrbiterK) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterG, 53U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterC, 56U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 23U)) + aOrbiterH) + aNonceWordC);
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 46U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + aNonceWordK);
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 39U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordE);
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCAFE77EC0266F20FULL + 0xC8C126CFC285802AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8702CC8AB919F0EFULL + 0xEC597282925887C3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBB545DA2FC7B8D8BULL + 0xDDD04B2D78E65D1AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDB08D8190A8FB66DULL + 0xB01820DE3C802493ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF777C9E46EB6AC77ULL + 0xE2D6D8949C272661ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE14E92673BEA4C1BULL + 0xFE406780BAF54AE9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD0DCD6A1C605C89DULL + 0xAEC049412E66F8F1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF5CBF4256CB91259ULL + 0x8D1903220F06DFC3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA5A0822526309233ULL + 0xDC19F7EFFBD0F388ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x80DBF0D44F7A7943ULL + 0xE9D6E2475A5D6997ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA684EB8C382E7B37ULL + 0xD143416CD9700958ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB1D9B61C9787DA93ULL + 0xFA980FAB6FB07C53ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC43CC9DED285B3BBULL + 0xF713D7966EDBA457ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x93B123F2A4A1DD23ULL + 0xCBC501D0412EBDD4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x96C85AED8270AACDULL + 0xD71CCE0CDC3B4D68ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB168AF6A1AED4B1BULL + 0x91AAD8726A60E035ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 681U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6378U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2676U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7268U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 39U)) + (RotL64(aIngress, 56U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererJ + RotL64(aScatter, 39U)) + 6654158889644956636U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 58U)) + 9045779659363991870U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (aWandererI + RotL64(aCross, 43U)) + 3888897662136993491U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 6882016842864459345U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 11U)) + 15601891715956172291U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 27U)) + 5176811598629335350U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 12519945150889074325U) + aNonceWordH;
            aOrbiterF = (aWandererA + RotL64(aIngress, 48U)) + 4552583214397603278U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 14225482701804864688U) + aNonceWordB;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5485298070606280363U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11237713257388094289U;
            aOrbiterB = RotL64((aOrbiterB * 11032429223099413011U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14340345895626142788U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16275167270553643347U;
            aOrbiterG = RotL64((aOrbiterG * 7308578867128951199U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14041860597556520250U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 1436068974197066343U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3938460345031496843U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11483155566419547004U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4608508534724289325U;
            aOrbiterJ = RotL64((aOrbiterJ * 13461385011638899485U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2389196334288832895U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 4062682330273866602U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8787682133271101901U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5655656046585592034U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7977947821249746880U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 10082104644185964787U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 11653718118543974168U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5456429682072377614U;
            aOrbiterI = RotL64((aOrbiterI * 12504180638665296649U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12457179652004203574U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 445821754230182952U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 16043092621697786393U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12429505513284703263U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12480745784412363537U;
            aOrbiterA = RotL64((aOrbiterA * 643617210585287593U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 34U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterI, 41U));
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aPrevious, 50U) + aOrbiterD) + RotL64(aOrbiterH, 36U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 47U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterG, 4U)) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9798U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((aIndex + 8814U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14470U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 9954U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 38U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aIngress, 10U)) + 6733949564325516029U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aCross, 57U)) + 7304098437143918796U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 3923949518391777800U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 35U)) + 14243591003388927124U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 52U)) + RotL64(aCarry, 3U)) + 18329498724605410406U) + aNonceWordG;
            aOrbiterA = ((aWandererE + RotL64(aCross, 29U)) + 13118172167747037249U) + aNonceWordO;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 5272025143849174212U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 3U)) + 16075917179214318424U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 43U)) + 15263590648674658399U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 13730046728289525921U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7703141464499623408U;
            aOrbiterE = RotL64((aOrbiterE * 5886009900621521987U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1382279753822135359U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2973369221699098292U;
            aOrbiterK = RotL64((aOrbiterK * 7440242040663550631U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11578274119583013219U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3419411247737896674U;
            aOrbiterD = RotL64((aOrbiterD * 17814942652262802991U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2582783513078999303U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3959762790273529677U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 383974377372162751U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 465795011576934604U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17880826624185821135U;
            aOrbiterB = RotL64((aOrbiterB * 4445949147592860913U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10819659185349413173U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17298208553586835030U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1965860510614222093U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12585880006661489402U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 16650193903267408586U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 5781132589396936615U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 885882046325991589U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 869560078374809974U;
            aOrbiterA = RotL64((aOrbiterA * 13440973563438747181U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11871305571797951851U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12137095015607196226U;
            aOrbiterI = RotL64((aOrbiterI * 7618152256560808581U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 30U) + aOrbiterK) + RotL64(aOrbiterC, 29U)) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterD, 35U));
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 58U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 51U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 40U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18855U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 18809U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19186U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((aIndex + 18771U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 27U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aPrevious, 51U)) + 5480870806135400132U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 47U)) + 8034874599430768743U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 34U)) + 4006919843736863767U;
            aOrbiterK = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 2988069748674633718U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 12347295651973135786U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 43U)) + 14152683894431568192U) + aNonceWordJ;
            aOrbiterD = (aWandererA + RotL64(aIngress, 14U)) + 15765143815254196598U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 10473067082331244233U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 19U)) + 1089466925383677249U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13215039929873682230U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3957997712247961479U;
            aOrbiterE = RotL64((aOrbiterE * 7631186240013784703U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10023907397941685546U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14593012591254614353U;
            aOrbiterI = RotL64((aOrbiterI * 17111300092082154687U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13353797968154036726U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9259966668512102858U;
            aOrbiterK = RotL64((aOrbiterK * 8326732574268308221U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10757861831070349321U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 10530223113483866178U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11269177745265396583U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7554320926405521865U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6978052067277966996U;
            aOrbiterG = RotL64((aOrbiterG * 18020134738536217801U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 1053695861967171420U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15980734683539854451U;
            aOrbiterC = RotL64((aOrbiterC * 3208466640010555357U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17041258393808061556U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12846551858751995530U;
            aOrbiterD = RotL64((aOrbiterD * 9303891433380993639U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 14617434286683320666U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3999309956180741302U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15037707937050015205U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13452627760403094126U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2633241575260427158U;
            aOrbiterF = RotL64((aOrbiterF * 2638570213290747581U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 58U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 3U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterE, 36U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 29U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 51U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterC, 10U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterK, 57U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 41U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 24U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 20U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26072U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27048U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26297U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31682U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCross, 52U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererD + RotL64(aScatter, 60U)) + 2915859148137000694U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 23U)) + 210680583721444425U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 6668118118775650387U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 47U)) + 15794200818099010989U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 54U)) + 6565076707062828369U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 16323164497808856719U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 27U)) + 7965435318816716560U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 7390281030573369017U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 19U)) + 2269738866911824875U) + aNonceWordP;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9664014216039993873U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 18284857398028357633U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8402008251343393737U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 367667619795303009U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7935945060956274197U;
            aOrbiterD = RotL64((aOrbiterD * 5481786693511955209U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16683666162337789540U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10655658270998102390U;
            aOrbiterJ = RotL64((aOrbiterJ * 15231596813382239841U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8307037916581540297U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3247742749860703524U;
            aOrbiterA = RotL64((aOrbiterA * 15052136713218656641U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10446792483683818139U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16374602929344972364U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12599903932725787599U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2411334498322777183U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1093701164116833765U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13129220206835381729U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17018480952982840635U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17348395690080029814U;
            aOrbiterI = RotL64((aOrbiterI * 6212591395713433257U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16111252311283623152U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12776492920397785951U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 6136009241593081821U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12214538600808144816U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10043377462096783363U;
            aOrbiterG = RotL64((aOrbiterG * 14639467375095185877U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 38U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterI, 46U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 13U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 14U)) + aOrbiterH) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 28U) + RotL64(aOrbiterG, 51U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 23U));
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 57U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererE, 42U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordH);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD5E2440FBB8ABA15ULL + 0xE843B17A5CA48B43ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8B3296B0F57B98CFULL + 0x9352A99B8D82E9E8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA3249D16BB30AA75ULL + 0x889738AA9EBC48BDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x84F778722C7AE5CFULL + 0x8DF8AC2DE9FDFC9AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA5067C4FC4C035CFULL + 0xF49826777F091B4FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF130D3EEE5D9B3DFULL + 0xDA333EEBAAA62F2BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA5489DCD5BE7D8B9ULL + 0xE639643D8D530EF1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD78FF7E0DC0CD1D9ULL + 0xFA85B6D7CB47D90FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAA2E20B3BEB3C0F7ULL + 0xF8FEE6EAA00408EAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDC8C89E939A2C2F9ULL + 0x8E674024FB7C2BE1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA51D1AA33CC4C49FULL + 0xB59F7A3DB71A9FBEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBE428AB6DCD7F689ULL + 0xA1643497FFEE4006ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD71D79D6DEEDA687ULL + 0x897E551707BCCB88ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC2BDAD6E0EA1B4BDULL + 0xDE72481B4F9528C1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9644182013466EE3ULL + 0xF31F8002F1D88468ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF7D07C87C79DE565ULL + 0x9532F2191BE205F2ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 745U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((aIndex + 5853U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4883U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 3170U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCross, 22U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aScatter, 41U)) + 1142447269198373880U) + aNonceWordN;
            aOrbiterE = (aWandererF + RotL64(aIngress, 51U)) + 10581460640040336191U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 14703062773878202900U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 15737525756286914746U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aScatter, 20U)) + RotL64(aCarry, 29U)) + 16178774478273186999U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2514897053906809160U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 13702496607592508464U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16540143680974064057U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18030885275418337965U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 5241783876161655984U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10970981186787227937U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2807052676283587925U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 8022804576763271327U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11727096043219370577U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15597099852232205860U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1538435607932096400U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 7900752511710516981U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 11147868774413615365U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9325213746830411568U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 561819005818948769U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterF, 13U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 56U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 5U)) + aNonceWordA) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 35U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 21U)) + aOrbiterD) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordA);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10939U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 8757U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14684U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12310U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 57U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 36U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 2617613537256538553U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aCross, 57U)) + 16642868916835132715U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 10860291124337073254U) + aNonceWordJ;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 6432511273906902472U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 10U)) + 7505375005848241910U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11086616004678821329U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 3298830587569881951U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4304047944073454489U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9775143140064220979U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 4147601326580823120U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 13462244678782260871U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12245920269898100415U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8391940489176734499U;
            aOrbiterI = RotL64((aOrbiterI * 9119606167674098007U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17876893379544668477U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 18301882058180370541U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 16680384667098921309U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6869225862715140102U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15404118372589259800U;
            aOrbiterH = RotL64((aOrbiterH * 5766851935950389915U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterA, 36U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 51U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 24U) + aOrbiterI) + RotL64(aOrbiterD, 3U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererA, 12U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordE);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22547U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((aIndex + 22009U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22994U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 21299U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 43U)) ^ (RotL64(aCross, 29U) + RotL64(aPrevious, 58U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererF + RotL64(aPrevious, 11U)) + 6973892330986118220U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 58U)) + 9886813896272094864U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 10996306582517553173U) + aNonceWordO;
            aOrbiterF = ((((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 8490648283899856223U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 105141713530704655U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3114337422810562588U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 980857684690886131U;
            aOrbiterE = RotL64((aOrbiterE * 17407927633910728721U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6562042345807072665U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15665371138706353619U;
            aOrbiterI = RotL64((aOrbiterI * 8086237578564620623U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18113013571374375028U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 17405346422601997299U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11162604605443005253U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5130876096426182506U) + aNonceWordI;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 1813821672299154629U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15478100342425611875U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15793814882743306728U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 13925299440495476399U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12049601510660117401U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterI, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 20U) + aOrbiterI) + RotL64(aOrbiterE, 34U));
            aWandererC = aWandererC + (((((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 53U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aNonceWordM) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26847U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 29422U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29094U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 31409U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 58U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((((aWandererE + RotL64(aPrevious, 40U)) + RotL64(aCarry, 5U)) + 10915618884692072446U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 12634922308499254909U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 6533934734564499389U) + aNonceWordK;
            aOrbiterC = (aWandererG + RotL64(aIngress, 5U)) + 6744203303756105181U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 51U)) + 13086782386652045658U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 5693840533331397822U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1803663542535024611U;
            aOrbiterI = RotL64((aOrbiterI * 8511046986156781857U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3597219300593287708U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1429753448204448904U;
            aOrbiterB = RotL64((aOrbiterB * 10927459251773273143U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17229017825587322715U) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 1137574712801062932U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 3645832160939819415U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2401991077004083378U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1332473247826139292U;
            aOrbiterA = RotL64((aOrbiterA * 15029831858261506447U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11730946340796899885U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15319163439700390962U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1349242001887975499U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 22U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterB, 43U)) + aNonceWordN) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 39U)) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterC, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterB, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordN);
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCA828A5CE1417CA7ULL + 0xAAF54AC86A722273ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9F5C372F07AB1BC3ULL + 0xBD738D24513D40A3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB06E66B7BF9DB5D9ULL + 0xDBAEB81C81683F34ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB833F907221F05ABULL + 0xCB20B93D5625B1CBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC221A8ED0F7549ADULL + 0xFDAA9D80A618C039ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8B00E5DFDC37D095ULL + 0xF4AFF58E820BB52EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA971CFBBA8D91511ULL + 0x932C917FBE6CA375ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9E8A59F74FF92D19ULL + 0xF4E69DD076FC091BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDE8E49D971F56A1DULL + 0xE99CECD999C69A3CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA9E7BF56228190D1ULL + 0xBDA17DC237513708ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFC67BE0B58D4DC17ULL + 0xFF23D1669EFEB7C4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8619CE4E62A200CFULL + 0xCE3B0A427EF968C5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD839C7639A061781ULL + 0xE1629222D89ECA40ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC9D2D0006842FAC7ULL + 0xB70516D7716B3660ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x94BB38E5F7EFEBEFULL + 0xC17454D16CD2F5E5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA33D462612725B57ULL + 0xB278FD46DDCF65ECULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6924U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3299U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6208U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 4073U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 56U)) + (RotL64(aIngress, 43U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 17711946802293254150U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 5U)) + 16652362590489569378U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 21U)) + 6972810344198183097U;
            aOrbiterH = (aWandererF + RotL64(aCross, 29U)) + 13117100889782940546U;
            aOrbiterA = ((((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 41U)) + 13199305696782626591U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 50U)) + 992156184392760945U) + aNonceWordJ;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 13791265442074543880U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 17057087245252294859U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13444195995883541046U;
            aOrbiterK = RotL64((aOrbiterK * 13067044288608808777U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 6723678233676059420U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7913379431208430475U;
            aOrbiterA = RotL64((aOrbiterA * 2295062944289127123U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4481887195529300665U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11892724101424384078U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3468639499716604111U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7700902083270424194U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1888001433557140271U;
            aOrbiterB = RotL64((aOrbiterB * 8975562955027025349U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14996753906788986929U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 939004845422123765U;
            aOrbiterC = RotL64((aOrbiterC * 2507090308972292313U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11922230289291941807U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15681187459741147199U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 10124947739653819101U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9119043713532718155U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8327697433992362166U;
            aOrbiterF = RotL64((aOrbiterF * 11157657162184304567U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 46U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterB, 3U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 46U)) + RotL64(aCarry, 57U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 57U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterC, 13U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 21U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterC, 37U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8841U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 13170U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14854U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 11846U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 52U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 6381335981879993247U) + aNonceWordN;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 52U)) + 15595429101600023172U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 5449234297249826461U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 13U)) + 11213734849329731168U) + aNonceWordC;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 37U)) + 16438473952464514248U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 7357872882115186976U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 27U)) + 394402075160738643U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11112941985410283532U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14955125011182736212U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 10711684773326395603U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14770727009821304070U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11286366598129204910U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15884310771003021989U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7358400908565425780U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15635109923749114761U;
            aOrbiterI = RotL64((aOrbiterI * 12415152149408700329U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 13826842523738623579U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1072811298828325231U;
            aOrbiterG = RotL64((aOrbiterG * 9662800288646215083U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4017334196009350776U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8812213572751410831U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 12744171921566782795U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6723457786170634403U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 9785583533999417673U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7776915427605471097U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10265132640322153964U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8435670887514808087U;
            aOrbiterC = RotL64((aOrbiterC * 2706263045620662131U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterB, 5U)) + aNonceWordH);
            aWandererF = aWandererF + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 58U) + aOrbiterE) + RotL64(aOrbiterC, 35U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterD, 41U)) + aNonceWordB) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 50U)) + aOrbiterD) + aNonceWordD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 20U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23922U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19528U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22548U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 17567U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 24U)) + (RotL64(aCarry, 37U) + RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 11177787645248006236U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 3808340254579817169U) + aNonceWordI;
            aOrbiterF = ((aWandererA + RotL64(aCross, 3U)) + 828030667598518279U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 16177835921238398371U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 51U)) + 5518747735458708741U) + aNonceWordJ;
            aOrbiterA = (aWandererK + RotL64(aScatter, 10U)) + 17346319082399995165U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 57U)) + 6397156921893030937U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15559381654710713582U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 940404446491415088U;
            aOrbiterF = RotL64((aOrbiterF * 16401260971303026881U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8047166032048732645U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4688468645859470491U;
            aOrbiterI = RotL64((aOrbiterI * 14383536431614496369U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 3710878044770337260U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 116343189456629220U;
            aOrbiterB = RotL64((aOrbiterB * 5637725064169289339U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 883908030159391659U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 18058691521694880482U;
            aOrbiterD = RotL64((aOrbiterD * 3132200449123497619U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17521015077103586117U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3668332225435714918U;
            aOrbiterH = RotL64((aOrbiterH * 12658899101297839881U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12229480388278883300U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16206524049491531816U;
            aOrbiterA = RotL64((aOrbiterA * 11122340196620859805U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 5743265849441077466U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 2812293020719282236U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 8903956475200417109U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterA, 22U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterF, 47U));
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 30U) + aOrbiterH) + RotL64(aOrbiterA, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29197U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 31673U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25826U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 27780U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 38U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 58U)) + 6069475454765660321U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 11483704742497268068U) + aNonceWordM;
            aOrbiterC = ((aWandererE + RotL64(aCross, 5U)) + 11055697447388986418U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 10897095046039997004U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 27U)) + 4731637118230457840U) + aNonceWordI;
            aOrbiterE = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 13855839187084986751U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 21U)) + 5328208115460188239U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12479538544291412985U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10740165998792608231U;
            aOrbiterC = RotL64((aOrbiterC * 14046827922294477379U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6492798157284955373U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13056825957483891921U;
            aOrbiterE = RotL64((aOrbiterE * 14882112110627751751U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2068184064919194657U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5656302738780746294U;
            aOrbiterG = RotL64((aOrbiterG * 16493021179127646345U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11193756120230763294U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17306750816837208999U;
            aOrbiterB = RotL64((aOrbiterB * 7949360041241439741U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12952818800389361804U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15380412293642628312U;
            aOrbiterA = RotL64((aOrbiterA * 2914662289178925547U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7706090204767242996U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14598802276412649570U;
            aOrbiterK = RotL64((aOrbiterK * 4821408736292041399U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17819762117328075515U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 6481384240915075101U) ^ aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4836701121865783029U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 44U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 53U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 57U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aIngress, 30U) + RotL64(aOrbiterK, 19U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 11U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterC, 44U)) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 22U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordA);
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC935BA5F34C70E35ULL + 0xD982C6664E803869ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF88B86F9F69091B5ULL + 0xA7FF4EC457405CB5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAC6578919851CF53ULL + 0xE0B7BEBF7E06DD3FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB4CAC24E5BDCB53BULL + 0xC4B26205607F961FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x87FE551CA1E2E6CBULL + 0xF706494534F96998ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDBA0F2BAFD710521ULL + 0x916B93B77B0C2B23ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD86AA3E656DB55A7ULL + 0xD442B0982CD4E215ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC28C8C0E7C23C557ULL + 0xFC717D2A0173541DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDE93E915486C80C9ULL + 0xF215DE7C866C2C69ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBCE642FB316C3B6FULL + 0x8BF2D5A342394344ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF09794FED5B35459ULL + 0xFB623D8830A565C5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD214E98E0343DCB7ULL + 0xE9B7E0768DB95694ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB17BBDFB956823E1ULL + 0xEC40A7A9F61FF438ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDD3DF6EA2CA29F67ULL + 0x8D95C4EDAEAB42BCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB13A14FAD40CCD15ULL + 0xE42DB7B73970E45CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x961358FDD4E86CC9ULL + 0xA5DE0612AB3A0C98ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5342U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6311U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4997U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3807U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 23U) + RotL64(aCarry, 54U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 14157904117287696136U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 57U)) + 7369512677371640676U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 14U)) + 8411250745902073798U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 5002041814539710275U) + aNonceWordI;
            aOrbiterI = (aWandererI + RotL64(aScatter, 37U)) + 9538041410816283124U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 43U)) + 5210700103927513061U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 7600709399101287982U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2366369466696580499U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5544575244203019109U;
            aOrbiterB = RotL64((aOrbiterB * 16231219246786333057U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8710073749110329779U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 15998211310115361630U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 15275657696897688955U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15354357553877376422U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10657523549259276169U;
            aOrbiterE = RotL64((aOrbiterE * 13695239532898311073U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 10405750198355464768U) + aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3465819693133515142U;
            aOrbiterF = RotL64((aOrbiterF * 14678343718277562799U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16724189641701408630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3484340153620198872U;
            aOrbiterG = RotL64((aOrbiterG * 17247547677520703125U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 7420442404884871126U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11138445997256757636U;
            aOrbiterC = RotL64((aOrbiterC * 11167543379937571127U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1428191560884663125U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16950093140800653985U;
            aOrbiterD = RotL64((aOrbiterD * 4423012306984814805U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 54U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + aNonceWordG);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 53U) + RotL64(aOrbiterC, 37U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 26U) + RotL64(aOrbiterG, 11U)) + aOrbiterF) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 53U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 30U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14657U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9854U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10127U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12961U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererE + RotL64(aCross, 27U)) + 14249093584376402677U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 8756965951816492264U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 19U)) + 11221139480258176330U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 52U)) + 17218894445564194851U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 3U)) + 8064642692524949490U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 5822093203710704646U) + aNonceWordI;
            aOrbiterG = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 3217799620158102238U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2613757677892120843U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13647481499551657237U;
            aOrbiterA = RotL64((aOrbiterA * 5517563514031899891U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3545714196663685016U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9735422670576621521U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7276207208162697249U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3911046580637583767U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9315984027042049203U;
            aOrbiterE = RotL64((aOrbiterE * 12568550776487242469U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8926367674641729058U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11035347490524961446U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 10948288997163592463U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10748158733051120339U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2467801787989056455U;
            aOrbiterK = RotL64((aOrbiterK * 12621934274702358977U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 9244415080474351390U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8517784887959492079U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 17022899813765884147U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8409307332803038455U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11043806021873232950U;
            aOrbiterG = RotL64((aOrbiterG * 8294888329708842989U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 29U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterA, 46U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterE, 37U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 28U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 18743U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20743U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23350U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23119U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 36U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 51U)) + 2330952702412094686U) + aNonceWordG;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 7820188225935060799U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 5U)) + 9347644591709839145U) + aNonceWordE;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 2288624878446846870U;
            aOrbiterK = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 9358977729492824128U) + aOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 57U)) + 1858511275052455039U) + aNonceWordK;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 26U)) + 13715478509322292552U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16413396625604260455U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17714322215518432705U;
            aOrbiterD = RotL64((aOrbiterD * 1904184102419934333U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16188315436202861122U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5564445841368207813U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14125834616162835983U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 13717068949900594673U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14143659432287313765U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 17281441046722262917U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5729546141908425670U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 4297827922736712074U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13631630436759768885U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 829520109395163673U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11547160328525174295U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4759690159673049775U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 2907177944512117206U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11100346409065275671U;
            aOrbiterE = RotL64((aOrbiterE * 17927994356809011637U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1344592529249949068U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6470438516791143572U;
            aOrbiterC = RotL64((aOrbiterC * 13339390828725370475U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 60U) + aOrbiterJ) + RotL64(aOrbiterB, 39U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterA, 5U)) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 57U)) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterE, 21U)) + aNonceWordD);
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterC, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28695U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30500U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30095U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 28901U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 18U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererG + RotL64(aCross, 53U)) + 479672811032092393U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aWandererH + RotL64(aIngress, 3U)) + 18061121631394564425U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 14237400452740566065U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 14U)) + 6723123812257706134U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 21U)) + 4247997188026499248U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 1939107415066134869U) + aNonceWordM;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 3912640123546395979U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8295478436553964298U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3218960600711526885U;
            aOrbiterJ = RotL64((aOrbiterJ * 15443507655470278069U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5874096203353388890U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10294536533673023358U;
            aOrbiterG = RotL64((aOrbiterG * 15561710414949058923U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11268561953904130747U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16693201256788898423U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16291987237693567209U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7550969634681894654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9501647424602245869U;
            aOrbiterB = RotL64((aOrbiterB * 11265865222096866605U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8881869255994319423U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16770136406906800016U;
            aOrbiterD = RotL64((aOrbiterD * 1782039587385512923U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16185384746435761363U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13841034186650721627U;
            aOrbiterC = RotL64((aOrbiterC * 12000155593277035447U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 15229062695864608309U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3576122704615303733U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2433987493885779279U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 56U)) + aNonceWordL) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterH, 29U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + aNonceWordA);
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterG, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterF, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordD);
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9D42D96DB61779DBULL + 0xCB52DEFFE342550FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF82E9F07F7462207ULL + 0xD9AEAD5F9555647BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x932561D5FDF7E30BULL + 0x84712800E2409E24ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE7D5E055B9F892B7ULL + 0x9EC9897F89599051ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC0AD94BDDC7DAD97ULL + 0xB1614836CB8C5077ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEB264730B8ED2BB1ULL + 0xF1AE971CA9987BC3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA2EE762F9B76B2E5ULL + 0x944540A9CACF824AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x935534697331525FULL + 0xB390BC0E358E781AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBAC396FF79B8EF25ULL + 0xC8292FD43A71EC9AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC17C99F48F124893ULL + 0xF9E15E8155C46DA0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8137074CCA6FE54DULL + 0xAC91639F09076393ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBFCBA9DC5ECDA749ULL + 0xD252EC7CFD745F0EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB545197932878B67ULL + 0xF2CA8DB64C86F2CFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB7A421C444269EA5ULL + 0x91D60F26A6CB2B0EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC24C0017A8DBF091ULL + 0xC20F8A4D5EC70CEEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD092521A876819E5ULL + 0x861CFFC074D4B3C7ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2822U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 861U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2545U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 443U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 57U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aIngress, 37U)) + 18180797995100240808U) + aNonceWordA;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 10U)) + 6585906608223552885U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 14088708930575939855U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 468974153311516044U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 13U)) + 12481951025619894110U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 19U)) + 17227987923860711763U) + aNonceWordH;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 23U)) + 4373962756657477139U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 5U)) + 2077576476565420951U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 41U)) + 17435011300234663764U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 4118039398293246896U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 48U)) + 13724716599855216683U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12391461204689596339U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9900605191533799627U;
            aOrbiterI = RotL64((aOrbiterI * 13553565332531046301U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 972946858824366125U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17247681919694541215U;
            aOrbiterH = RotL64((aOrbiterH * 2974639094630445643U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15442851427306771601U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7303586227288294037U;
            aOrbiterC = RotL64((aOrbiterC * 15406402525021428799U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12650358753454105119U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1483710933373510492U;
            aOrbiterK = RotL64((aOrbiterK * 6531763256577221891U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 18065810162229740788U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11311677121338794007U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15116367961682119467U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 2355285311890287611U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1287783821903407734U;
            aOrbiterG = RotL64((aOrbiterG * 8054011680932255985U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9282654686791135654U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15488608017745542551U;
            aOrbiterD = RotL64((aOrbiterD * 7858866274035085123U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13296835576073421802U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7127700236018338741U;
            aOrbiterB = RotL64((aOrbiterB * 11246173563106014149U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1365928843264598789U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7777790578813003657U;
            aOrbiterA = RotL64((aOrbiterA * 10121688100505628161U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2104270617375082523U) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13363764449819651164U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 2685452132715528975U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2008038686059197988U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 18180797995100240808U;
            aOrbiterF = RotL64((aOrbiterF * 8978998151475372047U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterC, 60U)) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterC, 51U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterG, 43U));
            aWandererA = aWandererA + (((RotL64(aIngress, 10U) + aOrbiterH) + RotL64(aOrbiterA, 39U)) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 53U));
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 34U)) + aOrbiterI) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + RotL64(aWandererA, 50U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14731U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 12737U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8650U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((aIndex + 9114U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 56U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 9888431329297626900U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 40U)) + 2937735167534624403U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aIngress, 13U)) + 17626022970343789617U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 5665660859333693743U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 1060537034632076669U) + aNonceWordN;
            aOrbiterC = (((aWandererH + RotL64(aCross, 29U)) + 743777763907175800U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 3U)) + 5744905970181808845U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 5U)) + 3545351394494002180U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 53U)) + 4877547088414106007U;
            aOrbiterK = (aWandererE + RotL64(aCross, 10U)) + 11669378338379598445U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 35U)) + 2961072441706158212U) + aNonceWordA;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13984945589234919765U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1433097875470903205U;
            aOrbiterJ = RotL64((aOrbiterJ * 451996840039906781U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 716415411025451152U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 8542286150858297810U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9139015340823332449U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12932391786479661299U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14005503313299177013U;
            aOrbiterB = RotL64((aOrbiterB * 802663466907819743U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9382792812676318046U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5138554251079724724U;
            aOrbiterG = RotL64((aOrbiterG * 6386016499265056247U), 53U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 8522380066269546172U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11825536408101906458U;
            aOrbiterD = RotL64((aOrbiterD * 17042837108792016849U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15504062350899452495U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1219010998820336744U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10650635772711590803U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6442717843380349632U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1047843426279085117U;
            aOrbiterF = RotL64((aOrbiterF * 4074561571072878005U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10611039527108679173U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5092816736177358221U;
            aOrbiterC = RotL64((aOrbiterC * 14342779343820140833U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12327496881352988530U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6405703847824845457U;
            aOrbiterH = RotL64((aOrbiterH * 12094143526751620113U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8906613392335197542U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5962698890029858689U;
            aOrbiterK = RotL64((aOrbiterK * 9136193803330500489U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2610083915800734277U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9888431329297626900U;
            aOrbiterE = RotL64((aOrbiterE * 3794133356691218671U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 34U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 39U));
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 50U) + aOrbiterG) + RotL64(aOrbiterE, 41U)) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterI, 13U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 53U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterF, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterE, 24U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterH, 29U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterI, 26U)) + aNonceWordK) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ aNonceWordO;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17465U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19193U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20195U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 24040U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 37U)) ^ (RotL64(aCross, 4U) + RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererH + RotL64(aCross, 11U)) + 14008824488073394623U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 35U)) + 13317978415866411468U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 21U)) + 13209180141897453900U) + aNonceWordJ;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 40U)) + RotL64(aCarry, 35U)) + 11870521586865233578U;
            aOrbiterI = (aWandererA + RotL64(aCross, 51U)) + 8052156380448047385U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 53U)) + 12158131176743680605U;
            aOrbiterE = ((((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 14674467487607719347U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 37U)) + 18055496790566231147U) + aNonceWordC;
            aOrbiterG = (aWandererD + RotL64(aScatter, 27U)) + 3838105585041578784U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 14U)) + RotL64(aCarry, 57U)) + 2839568255183054418U;
            aOrbiterA = (aWandererE + RotL64(aCross, 47U)) + 11933612922864258179U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6289849094151630580U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2640344350528492271U;
            aOrbiterC = RotL64((aOrbiterC * 16197726750829369365U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16306175266267657791U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 3339898380394883600U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7105436590182982373U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 15017076663742800002U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8973064296077602496U;
            aOrbiterF = RotL64((aOrbiterF * 9309462227233615761U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17580319233338139859U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14063208878807603874U;
            aOrbiterI = RotL64((aOrbiterI * 16601475239075164585U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13326130855721009942U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12843186026737544416U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4975848122837321619U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14102887715772847499U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14495942314329085733U;
            aOrbiterD = RotL64((aOrbiterD * 4236795312917583565U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11564857125101669667U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17435970784822000464U;
            aOrbiterJ = RotL64((aOrbiterJ * 1472691848852381173U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16561390130356833062U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9952805588514363872U;
            aOrbiterH = RotL64((aOrbiterH * 3720874990001086597U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8246822023509690545U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 305480212301772662U;
            aOrbiterE = RotL64((aOrbiterE * 4295787267516476485U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11729872285756639125U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9669174142543613799U;
            aOrbiterG = RotL64((aOrbiterG * 9443240779947114779U), 39U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 7653344907616923293U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14008824488073394623U;
            aOrbiterA = RotL64((aOrbiterA * 8362849599309360823U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 39U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 48U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 21U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 13U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aIngress, 54U) + aOrbiterC) + RotL64(aOrbiterE, 42U)) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + aNonceWordB);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + aNonceWordP);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 19U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 29U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 34U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordN);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28107U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25776U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27318U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((aIndex + 28596U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 48U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 1888427424966603593U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aPrevious, 41U)) + 5436761445660415091U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 21U)) + 17322876217962143270U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 56U)) + 9728299982740564979U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 47U)) + 301720335271716921U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 27U)) + 8069685428854814396U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 1973715500949100991U) + aNonceWordC;
            aOrbiterG = ((aWandererG + RotL64(aCross, 53U)) + 87666408799854155U) + aNonceWordE;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 34U)) + RotL64(aCarry, 37U)) + 12195436904339035245U;
            aOrbiterF = (aWandererI + RotL64(aCross, 13U)) + 4578742069143400295U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 11U)) + 7828776048774876484U) + aNonceWordA;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17203146364542781833U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16913369550858890466U;
            aOrbiterB = RotL64((aOrbiterB * 13534417587921978507U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9632761514552265402U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9106637671877341286U;
            aOrbiterE = RotL64((aOrbiterE * 9073709119482640391U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15423680889126750876U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6087310684583331882U;
            aOrbiterJ = RotL64((aOrbiterJ * 8964465129744898619U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5420955876411796789U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14166807419730848032U;
            aOrbiterK = RotL64((aOrbiterK * 442659738632823751U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8118312450347026824U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4253043584558403086U;
            aOrbiterG = RotL64((aOrbiterG * 5651748455190536467U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8810774678371762700U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12218479555589447835U;
            aOrbiterH = RotL64((aOrbiterH * 11026364205248516355U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11389930523582876358U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16334420553471379915U;
            aOrbiterF = RotL64((aOrbiterF * 13830132212033904777U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 18201289372553710279U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7196540389657785361U;
            aOrbiterA = RotL64((aOrbiterA * 13058135202554889791U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2601046573550065116U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2243003381737071984U;
            aOrbiterI = RotL64((aOrbiterI * 10518763530499878945U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6058992247656841580U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10083863011670540073U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 17908394295613117155U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8505005026063156940U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 1888427424966603593U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 18298382581929885653U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 14U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 30U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterH, 37U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterK) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 21U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aScatter, 24U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 23U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 60U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 5U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 43U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterF, 39U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 54U) + aOrbiterA) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordN;
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x90BCB6979A8FA60BULL + 0x8EB672AA14EA1205ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x98EA6114E14B5947ULL + 0xD405F829B5578205ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC2D54C266830678BULL + 0xD6C7F6E83DCAEF35ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEE97DC087FC2BCFBULL + 0x89C952411BE2861EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x939005B5D17F903DULL + 0xEE73537D612391FFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x80678650A9335691ULL + 0xC64F847ED655BEF3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF0B6BF7F864C6131ULL + 0x96DF38D0D52CDB4EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEBD5D1DE7A9B7753ULL + 0x8F72626BD9F3699CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA8A4B6D3CED7E7EBULL + 0x9E62435A00A4DB28ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD404685B732BD5B3ULL + 0x981EBD6B896172E5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF870D9D56AC5EA6BULL + 0xA820E96B970CCADCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD0839A03EFB181E1ULL + 0xCE13B139E3E67A0CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE70AB83917F150C1ULL + 0xF63CAA79A791F0CAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAB98CE5EA61FA2B5ULL + 0x8FF70BA7001C2851ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA7B722F25E578EB1ULL + 0xCD09DFD04E0663A1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC1315811F15CCF47ULL + 0x8320D3EF74FB048BULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2102U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 3252U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4057U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 5081U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 4U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aIngress, 14U)) + RotL64(aCarry, 11U)) + 17912271996338180948U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 13259276608841847058U) + aNonceWordA;
            aOrbiterG = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 16225936008657276089U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 23U)) + 2243058962151834071U) + aNonceWordC;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 19U)) + 10637439274127347861U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 57U)) + 15312219216405992627U;
            aOrbiterC = (aWandererE + RotL64(aCross, 47U)) + 2393933972129878613U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 42U)) + 4327069337247976513U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 29U)) + 8307656353434167837U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17299145556933889336U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14458100581172798164U;
            aOrbiterG = RotL64((aOrbiterG * 16543734663677070509U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6410095654927998067U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6168964796264687686U;
            aOrbiterB = RotL64((aOrbiterB * 16218071040190475953U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 3667999465041020730U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16021552859323602007U;
            aOrbiterA = RotL64((aOrbiterA * 6427266472526362663U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 12941668202330045095U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4222032891850449934U;
            aOrbiterK = RotL64((aOrbiterK * 17292856787431308097U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1346342592002730785U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16860611785008118820U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 384963420804756607U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3193572711804730241U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5866881282680588589U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9226331800853634597U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17180332731328479126U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10222097519535882241U;
            aOrbiterC = RotL64((aOrbiterC * 9422887302872778795U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8863502179821584859U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14872318155712512999U;
            aOrbiterH = RotL64((aOrbiterH * 11830641277356873233U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16478790641892781150U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8414944141232294781U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 17443775794621154023U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 38U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererG = aWandererG + (((((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 29U)) + aNonceWordK) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterD, 53U));
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterC, 30U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 23U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterC, 35U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterG, 46U)) + RotL64(aCarry, 19U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterK, 57U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8914U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7084U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6907U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 9234U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 58U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererF + RotL64(aScatter, 48U)) + 18191288703716505885U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aWandererK + RotL64(aIngress, 57U)) + 9824014524910417136U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 11U)) + 11953012029254917548U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 53U)) + 6297568011027199089U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 2576999400457367975U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 13176139160575558254U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 19U)) + 9978408174563621810U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 4U)) + RotL64(aCarry, 57U)) + 16765834875061607142U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 23U)) + 16534507305459121344U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3114710944346151807U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10240517868726718592U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4645691562915606463U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10721450637990777883U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16689590768796583952U;
            aOrbiterB = RotL64((aOrbiterB * 3046344179729901637U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2427422768928450209U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 13495584061816457831U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 6670984773768885119U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7058636403765106682U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9897341853944713767U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14286816859999869231U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17749559755733386064U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12515645083926326659U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6582878478865838245U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2625692458813609962U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10596240255026143019U;
            aOrbiterF = RotL64((aOrbiterF * 11605800195771080135U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12374290338067865540U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1507386663796330249U;
            aOrbiterI = RotL64((aOrbiterI * 1210241080424446087U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9288099549484146726U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 15159312464747000702U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 500055502081347757U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14998608679505446229U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17625038109437732009U;
            aOrbiterK = RotL64((aOrbiterK * 14785862243019841689U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 52U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterK, 57U)) + aNonceWordC);
            aWandererK = aWandererK + (((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 28U)) + aOrbiterH) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 35U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterB, 41U));
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 52U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aScatter, 52U) + RotL64(aOrbiterB, 11U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererE, 26U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12386U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 15904U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12874U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 14266U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 24U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aScatter, 11U)) + 3650233661228036955U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 35U)) + 11607036400067735729U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 47U)) + 3899614406903883035U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 5U)) + 8159156925629965143U) + aNonceWordM;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 40U)) + RotL64(aCarry, 53U)) + 7148903913967261270U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 57U)) + 9161665622287517848U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 2981535013474059469U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 15812469008200319549U) + aNonceWordO;
            aOrbiterI = ((aWandererC + RotL64(aCross, 20U)) + 14687469489893270300U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 6025209349511417063U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12964750392311112676U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 12955480283032701843U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6572355895765394340U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3542300121890027981U;
            aOrbiterH = RotL64((aOrbiterH * 11201491178181273935U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6477175684045398359U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1081388388827929314U;
            aOrbiterG = RotL64((aOrbiterG * 8752188637514143529U), 51U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 13754328481584620771U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3684673342659575917U;
            aOrbiterB = RotL64((aOrbiterB * 6139923312873039143U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6542045150319909445U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5352102692424060388U;
            aOrbiterD = RotL64((aOrbiterD * 7385758355501860261U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9110100774657340354U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2813273684436269057U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 10468759062594022273U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5860425751137403755U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1598622981888978548U;
            aOrbiterA = RotL64((aOrbiterA * 651816500461718345U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14710305692377606725U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16280545617802383463U;
            aOrbiterJ = RotL64((aOrbiterJ * 12541767206978802063U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6849565243667718750U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12152381961996750050U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11185935780063403807U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 28U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterE, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 18U)) + aOrbiterG) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterH, 43U));
            aWandererG = aWandererG + ((RotL64(aCross, 44U) + aOrbiterH) + RotL64(aOrbiterJ, 47U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterD, 51U));
            aWandererA = aWandererA + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 23U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordJ) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 38U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aCross, 24U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 26U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21254U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 19418U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16913U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 20381U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 2915859148137000694U) + aNonceWordN;
            aOrbiterC = (aWandererH + RotL64(aScatter, 57U)) + 210680583721444425U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 4U)) + RotL64(aCarry, 3U)) + 6668118118775650387U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 23U)) + 15794200818099010989U;
            aOrbiterA = (aWandererD + RotL64(aCross, 13U)) + 6565076707062828369U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 43U)) + 16323164497808856719U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 47U)) + 7965435318816716560U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 7390281030573369017U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 38U)) + 2269738866911824875U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9664014216039993873U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 18284857398028357633U;
            aOrbiterD = RotL64((aOrbiterD * 8402008251343393737U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 367667619795303009U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 7935945060956274197U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5481786693511955209U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16683666162337789540U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10655658270998102390U;
            aOrbiterH = RotL64((aOrbiterH * 15231596813382239841U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8307037916581540297U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3247742749860703524U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15052136713218656641U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 10446792483683818139U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16374602929344972364U;
            aOrbiterI = RotL64((aOrbiterI * 12599903932725787599U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2411334498322777183U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1093701164116833765U;
            aOrbiterF = RotL64((aOrbiterF * 13129220206835381729U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17018480952982840635U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17348395690080029814U;
            aOrbiterG = RotL64((aOrbiterG * 6212591395713433257U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 16111252311283623152U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 12776492920397785951U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6136009241593081821U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12214538600808144816U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10043377462096783363U;
            aOrbiterC = RotL64((aOrbiterC * 14639467375095185877U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 60U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 20U) + RotL64(aOrbiterA, 5U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 47U)) + aOrbiterF) + aNonceWordJ) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterE, 58U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterK, 29U));
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 51U)) + aOrbiterD) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterC, 43U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 28U) + aOrbiterA) + RotL64(aOrbiterD, 20U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22260U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 27186U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23479U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24517U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 6U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererE + RotL64(aScatter, 60U)) + 12029393034357490020U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 41U)) + 4526754731580694987U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 17060419646421271853U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 4128488893837059683U) + aNonceWordG;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 52U)) + 12706894827547160110U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 11U)) + 12506324593645825056U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 23U)) + 12581344490649250025U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 14357032418199130132U) + aNonceWordO;
            aOrbiterI = (aWandererI + RotL64(aIngress, 5U)) + 15341977701796331249U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7086602307544733241U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12398300065276832486U;
            aOrbiterK = RotL64((aOrbiterK * 18157408831225635333U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2499745046076601988U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7249361592814001829U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14597139848072319685U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3254456186337366437U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3472973415969046680U;
            aOrbiterJ = RotL64((aOrbiterJ * 14583566953969168353U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7905718972111691591U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15941413652144021522U;
            aOrbiterI = RotL64((aOrbiterI * 3473779492962783565U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10583964125960308762U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13659925272340853715U;
            aOrbiterG = RotL64((aOrbiterG * 16708294803316630743U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9487054537489454887U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13287757570441887517U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17351439045329892107U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15279245465808571942U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 12424999114621745879U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 2274918760256527137U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13915392738892970475U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13797668053788805126U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 13752161103680525317U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14344766585550401077U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13727554194373146727U;
            aOrbiterC = RotL64((aOrbiterC * 17164450431362670223U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 36U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 47U) + RotL64(aOrbiterF, 12U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterK, 27U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 48U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterI, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ) + aNonceWordP);
            aWandererB = aWandererB + ((((RotL64(aScatter, 6U) + aOrbiterD) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 51U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28346U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 32423U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31599U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((aIndex + 29637U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 11U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 826930775230515406U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 5137814617363250861U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 18U)) + 14761561947426681616U) + aNonceWordO;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 12773023438753662590U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 23U)) + 7331345852207096322U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 47U)) + 3899381212671247460U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 30U)) + 10072004147620068599U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 57U)) + 3424585039401897560U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aIngress, 39U)) + 8246760141625966321U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3655992860610853290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11154618022505863898U;
            aOrbiterA = RotL64((aOrbiterA * 4791494171286145231U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15629361991059709973U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10842068502278489664U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17223002513104960799U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5571312349016336686U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 589313823745748879U;
            aOrbiterF = RotL64((aOrbiterF * 1356685926549786027U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13633457935771935260U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12684602052812183096U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4689206269919806711U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5711307583717354204U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7181854170553728211U;
            aOrbiterE = RotL64((aOrbiterE * 9835601115561325911U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1884620014396115821U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1471516373272364262U;
            aOrbiterI = RotL64((aOrbiterI * 5126319375714848029U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 742739371092077733U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8075893317715227838U;
            aOrbiterB = RotL64((aOrbiterB * 11208274111743259795U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8179547722249281263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15305282712174742323U;
            aOrbiterH = RotL64((aOrbiterH * 7951986906055462929U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1430543231751281079U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14585341768267283387U;
            aOrbiterK = RotL64((aOrbiterK * 313213844964269133U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 50U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 10U) + aOrbiterC) + RotL64(aOrbiterG, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterI, 44U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterB, 35U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 57U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 50U) + aOrbiterE) + RotL64(aOrbiterH, 39U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterC, 18U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 51U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 11U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererE, 54U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordA);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD665588515590D9BULL + 0x81B5FD867E2D01BDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF8A9E0997267C37BULL + 0xB4EE8EFBBBB47B3DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFAD98307B3817B1BULL + 0xF5D2810B824C8ED4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x929ACBBF2D658D67ULL + 0xDCDAB841E3FEB51EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF751A6C8F212130DULL + 0x805C365BAC37DA71ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE5F0D67474935C6BULL + 0xC3B037086F393F6FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAC59527A9E551F0FULL + 0x9D7F935819E5F043ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD3D1E248C7F70005ULL + 0x9849DA0E3D474878ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB945357A550A69C1ULL + 0xC54D6B2CED794A25ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x922C11A3DB1610CBULL + 0xA6DC11DFFBD00DAEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD8B978ECCC8D8F59ULL + 0xB4F1842871BC233EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA76B45E2833F6F17ULL + 0xC410D1A475BD25FCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF672C804A22CCCD1ULL + 0xBE6AAD66329D4AF3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF06B25BB905EB853ULL + 0xCED8532CEFCA91CCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFCAE64182268F723ULL + 0xE15C970C8F58467EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD5F7DACE2298668FULL + 0xBA248D569E1903A2ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2132U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4682U)) & W_KEY1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 548U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1015U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 36U) + RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 58U)) + 6916817163240024692U) + aPhaseAOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = ((((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 14554930751292077817U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 1098305064484336101U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 51U)) + 12192821172420471527U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 2435134991707318845U) + aNonceWordH;
            aOrbiterA = (aWandererA + RotL64(aIngress, 29U)) + 1896745368738512624U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 41U)) + 1114996424222923873U) + aNonceWordK;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9839135798371512656U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8037967239603177043U;
            aOrbiterE = RotL64((aOrbiterE * 7848951103759663025U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15185468738487237432U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4912098316394854543U;
            aOrbiterJ = RotL64((aOrbiterJ * 3072785550384399929U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13142688607850380888U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4507379759608945839U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 2989332387754215967U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7299006009652289342U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5390655277207053627U;
            aOrbiterI = RotL64((aOrbiterI * 10973744708856143715U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6744737023577785725U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15539737698867067285U;
            aOrbiterH = RotL64((aOrbiterH * 4686092035261336911U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 13329866734681377952U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 13284937458969166257U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3965985432462699445U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8695002088915702168U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3858059421620839286U;
            aOrbiterB = RotL64((aOrbiterB * 9559783727301092937U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 12U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterB, 19U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + aPhaseAWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordI) + aPhaseAWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + aNonceWordF);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9503U)) & S_BLOCK1], 42U) ^ RotL64(mSource[((aIndex + 8328U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7465U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 7143U)) & W_KEY1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 36U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 43U)) + 9855743441035905047U) + aNonceWordH;
            aOrbiterD = (aWandererD + RotL64(aIngress, 51U)) + 8426286937143990276U;
            aOrbiterA = ((((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 7146752367170267002U) + aPhaseAOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 12947210066678101726U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 53U)) + 15902163559925328965U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 11U)) + 8506649889346449469U;
            aOrbiterC = (aWandererF + RotL64(aCross, 27U)) + 8226286036430263052U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2703047093452420216U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6769351326360139560U;
            aOrbiterA = RotL64((aOrbiterA * 5318104980014706265U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9857025533281333281U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 238297452132277585U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12974709749856065985U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7203572312072908931U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12497027346166575632U;
            aOrbiterF = RotL64((aOrbiterF * 1703586436725662307U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 473851890609048879U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1664484956453886047U;
            aOrbiterD = RotL64((aOrbiterD * 8566500756326590209U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4635095143004754116U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17695676150967345793U;
            aOrbiterI = RotL64((aOrbiterI * 5780416541584439301U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 15628965269863402796U) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 9190117464399730235U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5586437438425999715U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17835918238346011086U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 4398005402429282682U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 14828737209913317463U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 28U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 35U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 27U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterB) + aNonceWordL);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterA, 60U)) + aNonceWordD);
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11229U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15206U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13751U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 15215U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 47U)) + 8367680518550579791U) + aNonceWordF;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 19U)) + 11491674725611181241U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 53U)) + 16673861720782164214U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 57U)) + 9786610124108350855U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 5745080601557577637U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 1959402215131684684U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 3U)) + 6121650036079196522U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12016309761037342392U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5986936646177049603U;
            aOrbiterE = RotL64((aOrbiterE * 3585650475703294895U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 1000367700904043468U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 17425288243569101032U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2174614006719048535U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4856917474950325209U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16312111093223166419U;
            aOrbiterA = RotL64((aOrbiterA * 11046477664487805241U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 456110002032422270U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11393724374787795662U;
            aOrbiterF = RotL64((aOrbiterF * 1176984359123668389U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8378176867715697176U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8086186452345234815U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8450438271765985235U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8470349167474173245U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2528229938740192694U;
            aOrbiterB = RotL64((aOrbiterB * 8717790851266520943U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13247168811545753141U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8745293957516815264U;
            aOrbiterJ = RotL64((aOrbiterJ * 14270617180621072619U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (RotL64(aOrbiterH, 22U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 21U)) + aOrbiterF) + aNonceWordD);
            aWandererA = aWandererA + ((((RotL64(aCross, 37U) + RotL64(aOrbiterE, 35U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterK, 27U));
            aWandererK = aWandererK + ((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 6U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 41U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + aNonceWordE) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18547U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16592U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19465U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((aIndex + 17197U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 24U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 4634399531433127141U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 23U)) + 16961792729406903200U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 4105280732301137738U;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 10U)) + 15692013501147331191U) + aPhaseAOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (((aWandererD + RotL64(aCross, 39U)) + 1252216715968780587U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 57U)) + 7958289043012473752U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 6611577301818896615U) + aNonceWordJ;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8506226754305949140U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3648813120449403353U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9521367946879238849U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5195245426245535735U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 542948051600803051U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4631106308856448475U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11974253551208964789U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 10596463592332655367U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10941161258815714641U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12015129484061440159U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8254944355710109060U;
            aOrbiterA = RotL64((aOrbiterA * 3233697992479357615U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2754858806943915419U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5007802002906662779U;
            aOrbiterH = RotL64((aOrbiterH * 15613733948331639723U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6262190752136523216U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10528977986487821428U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 1184258264034585525U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8511097226098211854U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12091864735686692582U;
            aOrbiterK = RotL64((aOrbiterK * 6128140528141411237U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterK, 4U)) + aNonceWordF);
            aWandererI = aWandererI + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterD, 27U));
            aWandererD = aWandererD + ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterD, 19U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25230U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 26466U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26758U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 25499U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 54U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 11521331427196538632U) + aPhaseAOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aWandererC + RotL64(aScatter, 43U)) + 16653824187682957632U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 36U)) + RotL64(aCarry, 41U)) + 11654676587350088289U;
            aOrbiterB = ((((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 8010313317412193584U) + aPhaseAOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 29U)) + 1108775560502907471U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 3U)) + 243952321439823521U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 53U)) + 2324945800401240403U) + aNonceWordP;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9257554497543369657U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16701314607244592540U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8790054741039817107U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3900445848034341782U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7652316487347103658U;
            aOrbiterK = RotL64((aOrbiterK * 11480123491361589799U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14980368605272070578U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 2001165460948764796U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 8110980921827107649U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1911044015666991050U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11366207111147818339U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17234439040652553865U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16469329744002456607U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8062793687044950815U;
            aOrbiterC = RotL64((aOrbiterC * 5856142259851144369U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15364721421972807872U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8979915611483540231U;
            aOrbiterJ = RotL64((aOrbiterJ * 10899377466171153383U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7654234623563110457U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 1526832460342135008U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 12766083052650723051U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 36U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 26U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterE, 5U));
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 37U)) + aOrbiterH) + aPhaseAWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 53U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + aPhaseAWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29118U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29741U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31565U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 29232U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 20U)) ^ (RotL64(aIngress, 35U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 15316464782468770057U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 13U)) + 6642872057476351588U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 43U)) + 660732654689529192U) + aNonceWordL;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 7235418086884000655U) + aPhaseAOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 50U)) + 14784518476694580493U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 5U)) + 12222433977933449375U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 8573001207708329927U) + aPhaseAOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16035256260815013172U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15767726974121910203U;
            aOrbiterB = RotL64((aOrbiterB * 719060452537759331U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17712217935322939971U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 13488963456923357159U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 16785285630840310405U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10222949131965611079U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1495561412321657209U;
            aOrbiterC = RotL64((aOrbiterC * 9706305581868526265U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16156530750584361434U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7773792489045606309U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10730624207715601393U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11544578291333360613U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3665587867634242865U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4840528190844842595U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 15248434984650998090U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15487979645426567581U;
            aOrbiterH = RotL64((aOrbiterH * 10868107809356766183U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6972347795052712690U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16074994810010431338U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1262655238856775853U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 50U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + aPhaseAWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 13U));
            aWandererF = aWandererF + (((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 37U)) + aNonceWordG) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 21U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aScatter, 10U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterH, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordH);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE02D0DD561F475AFULL + 0xBF79AB4CF45D765AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x938E17DE8045D83DULL + 0xDC8526E5066D7963ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE2A8C70D68D54CD3ULL + 0xA2C1D58C31926655ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x82B0B411BB3B733FULL + 0xDA22C4D207FD1155ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDDC22816B505F941ULL + 0x8F81ACCE2F233438ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAD5E0E66E2952233ULL + 0xF18A3597D08A9B0BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB741E84C7E64C48DULL + 0xCBCD3D8382B242C4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9BA8CB60B45D120DULL + 0x8B36226A2E854AC9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCE797F39D2097CCBULL + 0xDFA162B89D92C7D5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF3D13168753C7759ULL + 0x8F9979E837D5CE2FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC158FC5941C4C41FULL + 0xB91129F55DA01F20ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x802B59B7E038E161ULL + 0xF67E959AD1D59529ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x89A793E01ED77869ULL + 0xBE8C7CAB175A74E0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCA3E8FAB1EB82913ULL + 0xF4ED99F5531BAA50ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC7F146BDA323BEE1ULL + 0xDC9E7450F8D98D62ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE70773C1C15AAD5BULL + 0xB66316C65211E874ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4129U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4053U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2558U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((aIndex + 4972U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 56U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aPrevious, 23U)) + 14249093584376402677U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 51U)) + 8756965951816492264U) + aNonceWordF;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 11221139480258176330U) + aPhaseBOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 17218894445564194851U) + aNonceWordI;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 14U)) + RotL64(aCarry, 53U)) + 8064642692524949490U) + aPhaseBOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5822093203710704646U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3217799620158102238U;
            aOrbiterJ = RotL64((aOrbiterJ * 2806328682494910635U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2613757677892120843U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 13647481499551657237U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5517563514031899891U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3545714196663685016U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9735422670576621521U;
            aOrbiterG = RotL64((aOrbiterG * 7276207208162697249U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3911046580637583767U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 9315984027042049203U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12568550776487242469U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8926367674641729058U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 11035347490524961446U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 10948288997163592463U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 57U)) + aNonceWordE) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aScatter, 36U) + aOrbiterB) + RotL64(aOrbiterJ, 36U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6773U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9053U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9571U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 7406U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 24U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 5721224134332887360U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 37U)) + 6892749729775049095U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 4U)) + 3884839462099556836U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 4365431706830216193U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 13U)) + 15501528746571578773U) + aNonceWordJ;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4505911326320650606U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1865129050927879580U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9198152644404068721U), 19U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 2011737665969640369U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 611672935827062688U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12873671551304596619U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 663547038310431047U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5468932264754299556U;
            aOrbiterK = RotL64((aOrbiterK * 11968657455484578525U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17920294117231191705U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 486058453837528110U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 8851102552244026737U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2789178451938129313U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 420772587981211184U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 17402987842294006667U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aNonceWordF) + aPhaseBWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 29U)) + aOrbiterB);
            aWandererE = aWandererE + (((((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 51U)) + aNonceWordK) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + aNonceWordD);
            aWandererB = aWandererB + ((RotL64(aScatter, 58U) + aOrbiterK) + RotL64(aOrbiterI, 56U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11577U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 16193U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11776U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14461U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 12U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 17264605017518259932U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 57U)) + 15209184354580778643U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 29U)) + 3299527965014731384U) + aNonceWordP;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 16293096431816127821U) + aNonceWordE;
            aOrbiterG = ((aWandererI + RotL64(aCross, 18U)) + 11031983436878828337U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9188018632448236358U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 13420816400363406556U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 10958221259662190519U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2485063384097917101U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3089135816938128264U;
            aOrbiterB = RotL64((aOrbiterB * 8813152992957361153U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10730544971770435788U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10431767565618874806U;
            aOrbiterF = RotL64((aOrbiterF * 4723078464590561545U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14883796491656899074U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13465877783538483706U;
            aOrbiterE = RotL64((aOrbiterE * 14311686051108108503U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 13322163435314643713U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3307316600284371955U;
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + aNonceWordH);
            aWandererG = aWandererG + ((((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterB, 48U)) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterE, 57U));
            aWandererK = aWandererK + (((RotL64(aCross, 54U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterA, 35U)) + aNonceWordO) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16912U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 17241U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16491U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 18370U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 40U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 3199575576585871314U) + aNonceWordB;
            aOrbiterJ = (aWandererA + RotL64(aCross, 29U)) + 2533378188975571824U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 6819782112558312658U) + aNonceWordI;
            aOrbiterD = ((((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 35U)) + 12690060987724798497U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aWandererG + RotL64(aCross, 51U)) + 7088375139715629606U) + aPhaseBOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17785618677423695666U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1714999280296491277U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7675674437417383741U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 17611338506932491624U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6475727359297421201U;
            aOrbiterE = RotL64((aOrbiterE * 15133348244242438069U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2347744591204119530U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2739317903351401068U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15435029315209475631U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8663535261373274338U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8205245127823536479U;
            aOrbiterJ = RotL64((aOrbiterJ * 13857005110466856439U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8916510616749754516U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 3944805940148512932U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 18082271583211389701U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterB) + aNonceWordF) + aPhaseBWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + aPhaseBWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterE, 50U)) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterD, 3U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22530U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 22179U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27303U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27194U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 30U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (((aWandererB + RotL64(aCross, 54U)) + RotL64(aCarry, 11U)) + 3448371607470865612U) + aNonceWordC;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 3743742913651580573U) + aPhaseBOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 39U)) + 13069491287948807280U) + aPhaseBOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 16872779275586545632U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 23U)) + 17945792656755062795U) + aNonceWordI;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 18199747196793731853U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15953311878379809513U;
            aOrbiterE = RotL64((aOrbiterE * 5476802169152352897U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 941268763494588338U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 10090221530365796809U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14035236086292997613U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8335698093307607001U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6147498804734306100U;
            aOrbiterD = RotL64((aOrbiterD * 6904444049941211327U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5980246079567570090U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4152167624425912978U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 10019421651535123573U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14990418790239735916U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 3418668387496597219U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12814077238529863119U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 24U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterE, 57U));
            aWandererE = aWandererE + ((((RotL64(aCross, 56U) + RotL64(aOrbiterD, 28U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 37U)) + aOrbiterF) + aNonceWordP);
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterF, 11U)) + aNonceWordB) + aPhaseBWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordK);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32395U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 31798U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30718U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30288U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 6U)) ^ (RotL64(aCross, 37U) ^ RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 2177539223979303669U) + aPhaseBOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 3962004686551521471U;
            aOrbiterE = (aWandererE + RotL64(aCross, 44U)) + 8457602312617147662U;
            aOrbiterG = ((((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 18011802451816510632U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 27U)) + 9046101759168876832U) + aNonceWordC;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11135620637431969597U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15913029940697999701U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 646524659942693491U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16304193109948135982U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 13208892298820080981U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15093751072618884859U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4182377898949419225U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13970137023071326151U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 9075061559681739865U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 8402396284835248583U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8859190834060657829U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13552418608113716117U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9760005337757990392U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14108277760135744897U;
            aOrbiterF = RotL64((aOrbiterF * 4474681104256093885U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterE, 58U)) + aPhaseBWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterD, 47U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + aNonceWordE) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8506CBD13B88824FULL + 0x836597E39A99C1B0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x969C936E7DEEA0D1ULL + 0xAC8CD758A756D486ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD8A7A0A07CC366E1ULL + 0xB875CAEF0BCA7917ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF302E6DB2B17E0F9ULL + 0x92A68B9F1F54D29FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB7AD699942DF5E3DULL + 0x810689A8F7E75668ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE5AD8ECED74A6013ULL + 0xDADA26DDA6444C13ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE20B65CD7D203ABFULL + 0xCADE7243759EDEB5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD0F75EC37AA7ACEFULL + 0x8BEF31E34F56B598ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF7C939680EFB1659ULL + 0x92F905BAA55F49B8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDBF86C7E6B7AAC2FULL + 0xE3C551437270220BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAFA120427F53E5B7ULL + 0xC362D0E25983602AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x91FD81324F1E8823ULL + 0x914EC1CC800E90A3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC278C4A5FF0BBEC7ULL + 0xAD62F68272CCF2CBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD887759166DFBDAFULL + 0x98563CA10863F56AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA0F75746377D42E1ULL + 0x962363EC18879682ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8720E01DF7C0F14FULL + 0x89280CF2CCFC7616ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 979U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 2180U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2160U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 3350U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aIngress, 39U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = (((aWandererC + RotL64(aIngress, 50U)) + RotL64(aCarry, 37U)) + 3684295017013759987U) + aNonceWordP;
            aOrbiterG = (aWandererB + RotL64(aCross, 13U)) + 6740408842457292881U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 29U)) + 4563975890702399441U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 41U)) + 797804144825287940U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 19U)) + 2763779540450101303U) + aPhaseCOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 13211846164102089685U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 15214578447281401982U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 46U)) + 13745208628754232427U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 57U)) + 17358621225969190747U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 779739369960480023U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4370963533701407813U;
            aOrbiterD = RotL64((aOrbiterD * 3123135216876641039U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 6061333005507739975U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3589705340762734456U;
            aOrbiterA = RotL64((aOrbiterA * 16499293983611196967U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10607697666369230567U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9356757995305239271U;
            aOrbiterF = RotL64((aOrbiterF * 10945513661439954731U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10093033335903048138U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11037328061699834100U;
            aOrbiterK = RotL64((aOrbiterK * 11189760551792389605U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 558431161176115540U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17795680919453449358U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3910117359996283803U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6096779391116214109U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17594243286880690775U;
            aOrbiterJ = RotL64((aOrbiterJ * 12655610181937429915U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15414704802398002423U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18040588240488602196U;
            aOrbiterC = RotL64((aOrbiterC * 16344249573086571225U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14636298592697156931U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9677305688594936561U;
            aOrbiterG = RotL64((aOrbiterG * 8354776999961642997U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16408025751875050713U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10018342878801454965U;
            aOrbiterE = RotL64((aOrbiterE * 10349132962708124117U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 20U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 30U) + RotL64(aOrbiterE, 48U)) + aOrbiterB) + aPhaseCWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterD, 19U));
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 57U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 52U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterA, 39U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterK, 23U));
            aWandererI = aWandererI + ((RotL64(aIngress, 26U) + aOrbiterE) + RotL64(aOrbiterK, 27U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererD, 22U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9665U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8260U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8493U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((aIndex + 8824U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 19U) + RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = (((aWandererF + RotL64(aScatter, 36U)) + RotL64(aCarry, 5U)) + 7632760812370906911U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 53U)) + 6007174525479723089U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 47U)) + 3362829642521821048U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 43U)) + 18009548556107978286U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 19U)) + 17880909432272697327U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 15961567935420752568U) + aNonceWordK;
            aOrbiterK = (aWandererC + RotL64(aScatter, 19U)) + 10136559064656837921U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 13U)) + 17622019364405410277U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aPrevious, 5U)) + 6927494824421416306U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 7125170407794874847U) + aNonceWordE;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 12342273503071032250U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 867417849555857179U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14997696377476124836U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14874498694181230698U;
            aOrbiterI = RotL64((aOrbiterI * 4026127545746010937U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2549397729130885686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4217995818662767955U;
            aOrbiterK = RotL64((aOrbiterK * 5525525344485251063U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 4706089044415442525U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17983900172670031015U;
            aOrbiterF = RotL64((aOrbiterF * 541552737180932879U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 1904937798143929988U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10620877287033139483U;
            aOrbiterC = RotL64((aOrbiterC * 16711012562024287213U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15681091173163181525U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 2655543246639000084U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16686375598149755947U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2647895110857289213U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5581609212017175954U;
            aOrbiterD = RotL64((aOrbiterD * 15330263616699031311U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13609076329627787987U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6244266279516622070U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12488345779236971095U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5289624364508923581U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16351476803965903112U;
            aOrbiterH = RotL64((aOrbiterH * 9012522724650442597U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterD, 48U));
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 35U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 24U) + aOrbiterA) + RotL64(aOrbiterF, 23U));
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 57U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterC, 53U)) + aPhaseCWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterF, 27U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterG, 42U)) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 10U) + aOrbiterK) + RotL64(aOrbiterA, 3U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18044U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 20464U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17651U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16411U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = ((aWandererH + RotL64(aCross, 48U)) + 6024062041314952357U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 18340757093658015585U) + aNonceWordI;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 13U)) + 11911120493880346751U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 29U)) + 17428074353884654439U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 12790849760814795936U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 44U)) + RotL64(aCarry, 39U)) + 12633397052172117800U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 35U)) + 11946150433665237945U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 19U)) + 16842157900909419285U;
            aOrbiterE = (aWandererA + RotL64(aCross, 57U)) + 14186235783224155962U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13284904542579767591U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11609181965078844357U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 5455780554452453513U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9628562297095374984U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7850281529011259759U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17611485102925470357U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 257458718073794527U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10693404545773519306U;
            aOrbiterG = RotL64((aOrbiterG * 14821443722828498323U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3430519236533871460U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6183054506953198055U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6121082743789970911U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2905610989884221654U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4472163910775333862U;
            aOrbiterJ = RotL64((aOrbiterJ * 7770678426310856745U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16870142883133769663U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1403692060594816451U;
            aOrbiterK = RotL64((aOrbiterK * 9740854430251597879U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16904169913507057108U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4773518591580333357U;
            aOrbiterF = RotL64((aOrbiterF * 5306070307776061267U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6528141733853494275U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11254806909313951442U;
            aOrbiterA = RotL64((aOrbiterA * 6316669786405548827U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6857506858448143407U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2855763534355983644U;
            aOrbiterE = RotL64((aOrbiterE * 16881334940165182415U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 40U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF) + aNonceWordA);
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterH, 6U)) + RotL64(aCarry, 23U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 39U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterC) + aNonceWordK) + aPhaseCWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aPhaseCWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 47U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterH, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28605U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32064U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28944U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27986U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = ((aWandererG + RotL64(aCross, 12U)) + RotL64(aCarry, 3U)) + 9855743441035905047U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 8426286937143990276U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 19U)) + 7146752367170267002U) + aPhaseCOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 39U)) + 12947210066678101726U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 29U)) + 15902163559925328965U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 57U)) + 8506649889346449469U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 47U)) + 8226286036430263052U) + aNonceWordE;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 6U)) + RotL64(aCarry, 11U)) + 2703047093452420216U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 43U)) + 6769351326360139560U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9857025533281333281U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 238297452132277585U;
            aOrbiterI = RotL64((aOrbiterI * 12974709749856065985U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7203572312072908931U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12497027346166575632U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1703586436725662307U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 473851890609048879U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1664484956453886047U;
            aOrbiterK = RotL64((aOrbiterK * 8566500756326590209U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4635095143004754116U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17695676150967345793U;
            aOrbiterH = RotL64((aOrbiterH * 5780416541584439301U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15628965269863402796U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9190117464399730235U;
            aOrbiterF = RotL64((aOrbiterF * 5586437438425999715U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 17835918238346011086U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4398005402429282682U;
            aOrbiterJ = RotL64((aOrbiterJ * 14828737209913317463U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10902589938246551273U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15124274429081385923U;
            aOrbiterE = RotL64((aOrbiterE * 13524180348258805367U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8747233520702236018U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5445611443463112371U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10294109295823410447U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16296005217836151910U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6468336224317602364U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 7369779919748367133U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 34U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 51U)) + aOrbiterE) + aPhaseCWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 58U) + RotL64(aOrbiterH, 27U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterC, 19U));
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 13U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterF, 23U)) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aScatter, 30U) + RotL64(aOrbiterB, 41U)) + aOrbiterI) + aPhaseCWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterA, 58U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordG;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC58D0537318FC2A5ULL + 0xD39580FF36B31414ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB062B06042E7EB4DULL + 0x9385E107978154DBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB9ADDBD5A7CEC88BULL + 0x9C8C61FCDF9C5207ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD84A04F6B50ED8E1ULL + 0xF03C74D2069BC7F1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDC2DED040D2CF51DULL + 0xE0CC59AB8C5ACFE3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9304EF3F9253713FULL + 0xBDF7709AB422CF42ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9EC9C2D07DAAAE59ULL + 0xC0AB25972F4A1BADULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE132BD2E2D553661ULL + 0xFB5A43C2715338F7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC32253EEBD142013ULL + 0x84C51BC5B09C41DBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xEE1EC0BF4C28C7D5ULL + 0x9ACC2057DF07C22CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF1AA24F28AD4ADDBULL + 0x99E09D90D9946B98ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEC995BCBED3AD3C9ULL + 0xDFE74C2FB1FBE1F7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB78B67ACC0831D53ULL + 0xEDF2F2DCC64F8252ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA393E341FB1B3827ULL + 0x93509BA3B1BE2382ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDB35CD5B6088860FULL + 0xA48183689C6C917AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD79C81605C08D005ULL + 0xBB59559616E99CDFULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 30U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2663U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3475U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3002U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 18U)) + (RotL64(aIngress, 47U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aScatter, 23U)) + 7896237440058555694U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 47U)) + 11870529476037558635U) + aNonceWordI;
            aOrbiterD = ((aWandererE + RotL64(aCross, 29U)) + 9158983227801569448U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 4710172270996950329U) + aNonceWordO;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 11U)) + 14634482800356647630U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 20U)) + 8822207952170610891U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 13755891414028982553U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 4555293067488040719U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 41U)) + 2816805148093762081U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 13U)) + 2122631477965135190U;
            aOrbiterA = (aWandererG + RotL64(aCross, 4U)) + 4592922416380416071U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7102471666524164715U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 17274623547879474204U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 5443572270546181789U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 938587316977094680U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 18258015823797023523U;
            aOrbiterI = RotL64((aOrbiterI * 6068819567674605919U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5809987756043471595U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5083075160112581620U;
            aOrbiterF = RotL64((aOrbiterF * 3313957222154937503U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5960021727750946496U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5967477320950630150U;
            aOrbiterH = RotL64((aOrbiterH * 330964768256424655U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6578428711689296132U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5601728218197771276U;
            aOrbiterK = RotL64((aOrbiterK * 9552559022315971847U), 13U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 7923809409017855241U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 16479366540906497019U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7118578387798460919U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 17000467091738009736U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 6801634573655508028U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 10584635770060137089U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 123668445682719574U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14462802805503986316U;
            aOrbiterE = RotL64((aOrbiterE * 12398236364304875941U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2433338393261685871U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13869012262404991729U;
            aOrbiterC = RotL64((aOrbiterC * 12443261517483942937U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4832421585086516998U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11284414949564414958U;
            aOrbiterG = RotL64((aOrbiterG * 1586650935440790991U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17872556812561387030U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7896237440058555694U;
            aOrbiterJ = RotL64((aOrbiterJ * 16784165278693056013U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 18U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 42U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 21U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + aNonceWordE);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 60U)) + aNonceWordA);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 47U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterH, 24U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 34U) + aOrbiterE) + RotL64(aOrbiterG, 13U));
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterF, 51U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5635U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7883U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9421U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 9040U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 43U)) + (RotL64(aCross, 56U) ^ RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererH + RotL64(aScatter, 57U)) + 16189787374324972735U) + aNonceWordO;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 19U)) + 17563763730956242224U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 11U)) + 10572803498593789385U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 30U)) + RotL64(aCarry, 47U)) + 7713105232072974166U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 23U)) + 10760839534772718139U) + aNonceWordF;
            aOrbiterK = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 13397069448391230253U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 4569255679998375682U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 46U)) + 9888769350817876949U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 39U)) + 11351796060878856300U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 21U)) + 18153775071965707204U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aWandererI + RotL64(aScatter, 27U)) + 1282846411145853435U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16457743979262460660U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 173493260775251032U;
            aOrbiterB = RotL64((aOrbiterB * 4935807229040883505U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3927345926316409630U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5158769729850853623U;
            aOrbiterC = RotL64((aOrbiterC * 2446452358663812945U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12331351600010165154U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3940794200348684050U;
            aOrbiterA = RotL64((aOrbiterA * 13248997263062075043U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11248514843822945425U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1391497323278226522U;
            aOrbiterD = RotL64((aOrbiterD * 8376841806072565005U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13265623528678787307U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2802033745265647317U;
            aOrbiterI = RotL64((aOrbiterI * 3437626962562016147U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6938444301018051844U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 1086544666755559028U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 16039728388882079889U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16156443117365816536U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3619942859562697142U;
            aOrbiterG = RotL64((aOrbiterG * 7589346043159112151U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17681848914912743292U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8848238631758130416U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 810402256099500607U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6019192027793541890U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16917288363166352778U;
            aOrbiterJ = RotL64((aOrbiterJ * 17673667086593738207U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5598218150530046752U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17285995539011279010U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15621233176885995065U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12380627610747299268U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16189787374324972735U;
            aOrbiterE = RotL64((aOrbiterE * 2144714828503219209U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 12U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 6U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterE, 47U));
            aWandererE = aWandererE + (((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 51U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterH, 39U));
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 53U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterI, 37U));
            aWandererB = aWandererB + ((((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 18U)) + aNonceWordJ) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 29U)) + aOrbiterF) + aPhaseDWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 57U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterA, 41U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 36U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11258U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((aIndex + 11107U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14869U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((aIndex + 13184U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 35U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 14U)) + 9654059367478508868U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 51U)) + 6473006635864677427U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 39U)) + 6944184481315853243U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 4061496421939102306U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 3U)) + 15791809275719085463U;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 14050798802646323055U) + aNonceWordB;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 53U)) + 12072905924741758266U) + aPhaseDOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aWandererE + RotL64(aCross, 60U)) + 17639076509231343896U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 12195388285571234715U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 5U)) + 4325404419499496529U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 43U)) + 5910567888204238382U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13092940059929942699U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13381962590820308761U;
            aOrbiterB = RotL64((aOrbiterB * 6345904465930943295U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15622862439323440527U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14027151901132249793U;
            aOrbiterG = RotL64((aOrbiterG * 2273573821630510087U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4584410023907605157U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15763755180625487157U;
            aOrbiterD = RotL64((aOrbiterD * 6755736130607297639U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17023059745666559199U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5298529579288492971U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2483562793328357721U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2870152867331654736U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12017191100173748848U;
            aOrbiterJ = RotL64((aOrbiterJ * 9958191466506480519U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15899529176182436062U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16482713846343388735U;
            aOrbiterI = RotL64((aOrbiterI * 719465695044265601U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 12943393531812774449U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 9881108254540483225U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 8011108108007885059U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3532054586199716750U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7142230313294797435U;
            aOrbiterF = RotL64((aOrbiterF * 14154176174768868421U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 733958394016131587U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2060800099014517137U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 12988885554457108631U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2278498033811574812U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15342071118593803929U;
            aOrbiterK = RotL64((aOrbiterK * 7842196613533603835U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12987212219357101955U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9654059367478508868U;
            aOrbiterC = RotL64((aOrbiterC * 11796100167917742307U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 46U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterJ, 21U)) + aNonceWordH) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 51U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 5U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 10U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 27U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + aPhaseDWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 39U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 46U) + aOrbiterA) + RotL64(aOrbiterC, 24U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19302U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17793U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17992U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16688U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 38U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 11410829607777684449U) + aPhaseDOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 52U)) + 7502698839700975347U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 13267685058252106173U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 11U)) + 238242706996630625U) + aPhaseDOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aWandererF + RotL64(aIngress, 27U)) + 8184695499511454281U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 3U)) + 12767823220461985403U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 50U)) + 12293198423143850330U) + aNonceWordA;
            aOrbiterH = (aWandererK + RotL64(aCross, 41U)) + 11149495229952495939U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 7556992689338382800U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 43U)) + 3431338808774134649U) + aNonceWordM;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 5U)) + 16863099140844995099U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17872458049880677604U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16760153457252546974U;
            aOrbiterI = RotL64((aOrbiterI * 11225037229069712805U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3115544493537438408U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4359882942759752958U;
            aOrbiterC = RotL64((aOrbiterC * 561477566995575801U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13387113067202396536U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12955690074544490161U;
            aOrbiterB = RotL64((aOrbiterB * 12449941770827974511U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15614054443728226807U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1939441328066616114U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4484917074808974359U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4599016263007782537U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9962305629016158048U;
            aOrbiterH = RotL64((aOrbiterH * 1496184427500037279U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8428467674122750557U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3938884087806393439U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12810531094050481761U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6018636830758044658U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1510372000641305416U;
            aOrbiterA = RotL64((aOrbiterA * 9002834928626918247U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17592782466215337843U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8119921507606870360U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 1299795061644535485U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8753237702359236964U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12389957327067768090U;
            aOrbiterG = RotL64((aOrbiterG * 4586786761936601607U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17791633199762408683U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 11606494383812053915U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13041480602055778521U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4418614662439151979U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11410829607777684449U;
            aOrbiterK = RotL64((aOrbiterK * 3342270212301058781U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 28U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 47U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterG, 5U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterA, 19U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 58U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 56U) + aOrbiterH) + RotL64(aOrbiterK, 43U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterE, 50U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 54U) + aOrbiterG) + RotL64(aOrbiterI, 35U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23708U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22299U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24058U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22341U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 18U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererA + RotL64(aScatter, 41U)) + 18191288703716505885U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 26U)) + 9824014524910417136U) + aNonceWordN;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 11953012029254917548U;
            aOrbiterF = (aWandererG + RotL64(aCross, 53U)) + 6297568011027199089U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 2576999400457367975U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 47U)) + 13176139160575558254U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 29U)) + 9978408174563621810U) + aNonceWordI;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 16765834875061607142U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 4U)) + 16534507305459121344U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 57U)) + 3114710944346151807U) + aPhaseDOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 35U)) + 10240517868726718592U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10721450637990777883U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16689590768796583952U;
            aOrbiterJ = RotL64((aOrbiterJ * 3046344179729901637U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2427422768928450209U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 13495584061816457831U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 6670984773768885119U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7058636403765106682U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9897341853944713767U;
            aOrbiterE = RotL64((aOrbiterE * 14286816859999869231U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17749559755733386064U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12515645083926326659U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6582878478865838245U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2625692458813609962U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10596240255026143019U;
            aOrbiterG = RotL64((aOrbiterG * 11605800195771080135U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12374290338067865540U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1507386663796330249U;
            aOrbiterF = RotL64((aOrbiterF * 1210241080424446087U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9288099549484146726U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15159312464747000702U;
            aOrbiterK = RotL64((aOrbiterK * 500055502081347757U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14998608679505446229U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17625038109437732009U;
            aOrbiterI = RotL64((aOrbiterI * 14785862243019841689U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10543192232885637211U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10330547522729618042U;
            aOrbiterC = RotL64((aOrbiterC * 7635903835474874057U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5753298214283941201U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15943436872588208065U;
            aOrbiterB = RotL64((aOrbiterB * 17704547766822075741U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5757218926946874970U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 18191288703716505885U;
            aOrbiterA = RotL64((aOrbiterA * 2644970408001409575U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 53U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterI, 41U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 36U)) + aOrbiterB) + aNonceWordK) + aPhaseDWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 13U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 23U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterA, 5U)) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 58U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 18U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 29U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 22U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30209U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 31225U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29494U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32219U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 11U)) ^ (RotL64(aCarry, 60U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 9471546960258473684U) + aNonceWordK;
            aOrbiterC = (aWandererH + RotL64(aCross, 13U)) + 18050235435948942244U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 43U)) + 3005107102671544641U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 20U)) + RotL64(aCarry, 11U)) + 17898396434573801850U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aScatter, 53U)) + 15071602525497771648U;
            aOrbiterE = (aWandererI + RotL64(aCross, 27U)) + 5780119462702672108U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 29U)) + 13301326224151025687U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 18129323022260575961U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 5U)) + 1199228670638790709U) + aNonceWordB;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 23U)) + 1839199978088021020U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 34U)) + 4999517042246790165U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8788607633376516299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15143903839930468749U;
            aOrbiterH = RotL64((aOrbiterH * 12735914889325422675U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16674732686428431869U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15908873150953195581U;
            aOrbiterD = RotL64((aOrbiterD * 18049755517524334107U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11204775359756474667U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2525984309543939465U;
            aOrbiterE = RotL64((aOrbiterE * 3988529812023791571U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4566345170476825512U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14876612901557406267U;
            aOrbiterB = RotL64((aOrbiterB * 9047956948845135339U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14926290877038883931U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12710203178186614846U;
            aOrbiterK = RotL64((aOrbiterK * 14841163494801662515U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7315094513967387996U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11050116830482816766U;
            aOrbiterA = RotL64((aOrbiterA * 3702999495721152019U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4505368486032503953U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 17905748055257551092U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14775870175093453197U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5728886950801376350U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17998141690182325170U;
            aOrbiterF = RotL64((aOrbiterF * 16008599930125391379U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 4325978018819134558U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13526905108565989379U;
            aOrbiterJ = RotL64((aOrbiterJ * 14121321495714166291U), 19U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 10597169665474269506U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7500801022830471869U;
            aOrbiterC = RotL64((aOrbiterC * 3702717219742363777U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17063616328548689935U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9471546960258473684U;
            aOrbiterI = RotL64((aOrbiterI * 3029748230803396737U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 40U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 50U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 11U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 50U)) + aOrbiterE) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 19U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 42U) + RotL64(aOrbiterA, 27U)) + aOrbiterG) + aPhaseDWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 5U));
            aWandererG = aWandererG + ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterK, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 34U));
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterA, 47U));
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterG, 29U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordK);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA61689702452D7E3ULL + 0xEE7F2B4CA6A1C6A3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x986AD83FAA020A03ULL + 0xC566E463A2A7A6A0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFF3FED854F058C11ULL + 0x8850595BF6D2D86EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB9FC7B0BEF9B9BD7ULL + 0xF21F1DF9D0EE2F78ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCD9B4ECEEE9DBB3BULL + 0xC3A797BCF8D8F505ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE36B71A355348565ULL + 0xA458391ABD53496CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFB10A6FEBFE48D97ULL + 0xDF204203B01CECA4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA85DBCAADB8C5A8BULL + 0xE0653D4CB67947E0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x857385B64A96C34FULL + 0xACD3ECD471AF6DB1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x822E50E5CEA3492FULL + 0xA73FE8FFFE05DD2FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCA6EDDF45021B65FULL + 0x83700BEBD6912FD0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE456B506947A48D1ULL + 0x9A0140595FB7F57CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA0C0C12B9A7D3897ULL + 0xA0A26D470B1400E0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x93BBE1DF3CA4CF0DULL + 0xBD83512A368D2D71ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x95089DA7E124FCC3ULL + 0xC514701D29996502ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAD4A39647A630A7BULL + 0xE10BDBE965389938ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4585U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1848U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5319U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((aIndex + 290U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aCross, 5U)) + 8866844335448071821U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 50U)) + 15159698739856430085U) + aNonceWordM;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 9582805772989594633U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 1438538239931588373U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 3U)) + 10862044156620436139U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 37U)) + 13682173320058164615U) + aPhaseEOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 19U)) + 8351013291045977592U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 21U)) + 15777857431516633916U) + aNonceWordC;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 30U)) + 16178966745333885377U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 9031889187993001617U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 23U)) + 6308472367425865347U) + aPhaseEOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 642109145903321046U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9186268569255318035U;
            aOrbiterA = RotL64((aOrbiterA * 10714674348507516749U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 6091345356803675860U) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13218507921880873749U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15415157927185637717U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4266652275234474616U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4391422098164506195U;
            aOrbiterD = RotL64((aOrbiterD * 17634679403195085867U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5160682323243635577U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10351728852161347404U;
            aOrbiterB = RotL64((aOrbiterB * 11105410036471745951U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 3950932176454814023U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9536466386833427441U;
            aOrbiterF = RotL64((aOrbiterF * 18064984243491293435U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9927425919978776529U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6819384090527481081U;
            aOrbiterJ = RotL64((aOrbiterJ * 18032965969184368561U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1646274931424218507U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16166524473976135097U;
            aOrbiterK = RotL64((aOrbiterK * 11672192658072663849U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11252501968059485262U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16847854447987609067U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6326299154627028295U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16723218285355036446U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13870211254243048975U;
            aOrbiterH = RotL64((aOrbiterH * 10203222183774624097U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11401147367366049493U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4266628469244269926U;
            aOrbiterE = RotL64((aOrbiterE * 2409934496621365221U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 11578385782347296942U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8866844335448071821U;
            aOrbiterG = RotL64((aOrbiterG * 6456956795450036515U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 10U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 44U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 5U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 22U) + aOrbiterA) + RotL64(aOrbiterG, 21U));
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 23U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterI, 41U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterC, 28U)) + aOrbiterK);
            aWandererC = aWandererC + (((((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 53U)) + aNonceWordG) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 22U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8410U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 5624U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8934U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10281U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 3448371607470865612U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 53U)) + 3743742913651580573U) + aNonceWordN;
            aOrbiterE = (aWandererK + RotL64(aIngress, 46U)) + 13069491287948807280U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 39U)) + 16872779275586545632U) + aPhaseEOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 43U)) + 17945792656755062795U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 21U)) + 18199747196793731853U) + aNonceWordP;
            aOrbiterA = (aWandererH + RotL64(aCross, 35U)) + 15953311878379809513U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 10U)) + RotL64(aCarry, 11U)) + 941268763494588338U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 19U)) + 10090221530365796809U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 8335698093307607001U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 23U)) + 6147498804734306100U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5980246079567570090U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4152167624425912978U;
            aOrbiterE = RotL64((aOrbiterE * 10019421651535123573U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14990418790239735916U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3418668387496597219U;
            aOrbiterJ = RotL64((aOrbiterJ * 12814077238529863119U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4206650904177199425U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3905470780938996069U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16030122739273137005U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9968672788233080924U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 602258075661864866U;
            aOrbiterA = RotL64((aOrbiterA * 2615726693066300065U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17751667243048041383U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2414054413585296027U;
            aOrbiterB = RotL64((aOrbiterB * 1049512574773201893U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6523322402744047752U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6729901917767398779U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8039939871405367139U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 11460169185076814539U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7559640379553110573U;
            aOrbiterK = RotL64((aOrbiterK * 9864654321914036135U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17271150091827475028U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 3541809324556914646U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 12655168871428868639U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10332471447306597185U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 12580133010006951091U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 1159183486084705865U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17333553613777910945U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14179392055698682109U;
            aOrbiterD = RotL64((aOrbiterD * 17675559451285279251U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3996830751779338356U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3448371607470865612U;
            aOrbiterC = RotL64((aOrbiterC * 5375529914102609947U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 30U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 37U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + aNonceWordK);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 14U) + aOrbiterH) + RotL64(aOrbiterA, 42U));
            aWandererB = aWandererB + ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 19U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 21U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 44U) + aOrbiterE) + RotL64(aOrbiterB, 50U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 5U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 22U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15770U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 12919U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13746U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15865U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCarry, 3U) + RotL64(aIngress, 52U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 2330952702412094686U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 46U)) + 7820188225935060799U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 9347644591709839145U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 2288624878446846870U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 37U)) + 9358977729492824128U;
            aOrbiterG = (aWandererG + RotL64(aCross, 3U)) + 1858511275052455039U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 23U)) + 13715478509322292552U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aScatter, 13U)) + 16413396625604260455U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 41U)) + 17714322215518432705U) + aPhaseEOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aWandererI + RotL64(aCross, 39U)) + 16188315436202861122U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 50U)) + 5564445841368207813U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 13717068949900594673U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14143659432287313765U;
            aOrbiterA = RotL64((aOrbiterA * 17281441046722262917U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 5729546141908425670U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4297827922736712074U;
            aOrbiterG = RotL64((aOrbiterG * 13631630436759768885U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 829520109395163673U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11547160328525174295U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4759690159673049775U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2907177944512117206U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11100346409065275671U;
            aOrbiterI = RotL64((aOrbiterI * 17927994356809011637U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1344592529249949068U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6470438516791143572U;
            aOrbiterD = RotL64((aOrbiterD * 13339390828725370475U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5217751823741520847U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5371275223586938039U;
            aOrbiterK = RotL64((aOrbiterK * 12318403075523724125U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14218103150268532919U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1367628876596800571U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13777531272321533137U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2372041991018455610U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9870744274890595581U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12093443117747395585U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15531376915156611594U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11166549148968363252U;
            aOrbiterH = RotL64((aOrbiterH * 10024372567841218915U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8555942275137258839U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 3304132937209624841U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7965093976633155809U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14825330575158830172U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2330952702412094686U;
            aOrbiterC = RotL64((aOrbiterC * 9146641978165131495U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 4U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterF, 41U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterK, 3U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterC, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 27U));
            aWandererG = aWandererG + (((RotL64(aIngress, 20U) + RotL64(aOrbiterC, 23U)) + aOrbiterE) + aPhaseEWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 44U)) + aOrbiterK) + aNonceWordA);
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18292U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20025U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19468U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 17217U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCross, 27U) + RotL64(aIngress, 52U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aCross, 18U)) + 13481227414590594621U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 23U)) + 17425964381118918026U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 39U)) + 4792004356135956581U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 21U)) + 11926849936000639098U) + aNonceWordL;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 990697329347742142U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 12U)) + 9307721505373076588U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 17605732738841908719U;
            aOrbiterK = (aWandererD + RotL64(aCross, 29U)) + 13110764518634187439U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 27U)) + 17970109897810645911U) + aNonceWordF;
            aOrbiterH = ((aWandererI + RotL64(aCross, 53U)) + 10273133817644703654U) + aNonceWordB;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 11239046688920468137U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8355821483275763145U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15522151127786049345U;
            aOrbiterC = RotL64((aOrbiterC * 4844278537850520413U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5381663179722418112U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9551368011768104906U;
            aOrbiterD = RotL64((aOrbiterD * 14202470972121732997U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 16264476585232221270U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7721417776432288282U;
            aOrbiterJ = RotL64((aOrbiterJ * 10267770327791051869U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 339418090653475277U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3247926250495935511U;
            aOrbiterF = RotL64((aOrbiterF * 16824669543765729097U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3390560045236418590U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3894024951542543635U;
            aOrbiterK = RotL64((aOrbiterK * 10599637790900418767U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3878539166189668154U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5617705593218220843U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 82771190372750823U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12320861089148474544U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14943790251625519550U;
            aOrbiterH = RotL64((aOrbiterH * 13758322022902008313U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 18119213517612562775U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1413193144229486646U;
            aOrbiterI = RotL64((aOrbiterI * 14562375280658115687U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14810150213456844196U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8468712395797520201U;
            aOrbiterE = RotL64((aOrbiterE * 8167911669632436949U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 13501570100536254566U) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 15409772061478100850U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 955182899606655851U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8621805947309982779U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13481227414590594621U;
            aOrbiterG = RotL64((aOrbiterG * 9591362493722704105U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 3U)) + aOrbiterG) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterK, 39U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 50U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 30U) + aOrbiterH) + RotL64(aOrbiterJ, 11U));
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 21U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterA, 34U)) + aPhaseEWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 43U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 18U) + RotL64(aOrbiterE, 57U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24979U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23668U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25919U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24799U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 42U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (((aWandererF + RotL64(aIngress, 53U)) + 12615321415808640429U) + aPhaseEOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aWandererJ + RotL64(aCross, 14U)) + 15712784676459931207U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 23U)) + 11013335427004930046U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 11U)) + 8298733856304768806U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 6207732959150824216U) + aNonceWordF;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 28U)) + 9769864876127544038U) + aNonceWordD;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 10782181918651152563U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 35U)) + 5790454015845620939U) + aPhaseEOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aScatter, 3U)) + 15606578025386733803U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 47U)) + 5522352539991175304U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 5993355818572869649U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10864534396947622047U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12090053126235913528U;
            aOrbiterK = RotL64((aOrbiterK * 7250801471645972261U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 14191181677234981396U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2258570108233924592U;
            aOrbiterG = RotL64((aOrbiterG * 8307541155393855209U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8448114811381534603U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2702389315763499817U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 6710443836432274393U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17202184076718780200U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 150549910056015002U;
            aOrbiterJ = RotL64((aOrbiterJ * 195034681254956335U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4910512055808124967U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4783477997418403079U;
            aOrbiterA = RotL64((aOrbiterA * 861977492146512865U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13842899106208709771U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7930112618036681468U;
            aOrbiterB = RotL64((aOrbiterB * 8609551859830858419U), 51U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 8790107242863198659U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 6882768826643279144U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13745521454063360763U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12136498871759890015U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8120456314755584336U;
            aOrbiterH = RotL64((aOrbiterH * 1830725195528043575U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14425711740351183016U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15907406009196323049U;
            aOrbiterF = RotL64((aOrbiterF * 8599371693260686839U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4878521420367891861U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1184672056055028939U;
            aOrbiterD = RotL64((aOrbiterD * 5963961755367831967U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10126736568567000180U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12615321415808640429U;
            aOrbiterI = RotL64((aOrbiterI * 11663715449073755137U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 10U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterB, 18U)) + aNonceWordJ);
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 53U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 11U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterC, 21U));
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 37U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 24U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aPrevious, 52U) + RotL64(aOrbiterH, 51U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 22U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32314U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((aIndex + 27725U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32587U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 27600U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 12U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 13204735390996728477U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 19U)) + 851171359595647173U) + aPhaseEOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aIngress, 42U)) + RotL64(aCarry, 23U)) + 16745304202825290723U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 47U)) + 562392736584913979U) + aNonceWordG;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 57U)) + 3244267012529053918U) + aPhaseEOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 39U)) + 17282536111067869133U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 21U)) + 14851130066471729068U;
            aOrbiterK = (aWandererB + RotL64(aCross, 24U)) + 5256130407952363129U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 29U)) + 2904742485828362001U) + aNonceWordK;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 3723346325449225387U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 35U)) + 5344621093694027341U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12919263300833603026U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17989801264160996071U;
            aOrbiterF = RotL64((aOrbiterF * 15468293047311883751U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5022175042377172157U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16684822380107847758U;
            aOrbiterI = RotL64((aOrbiterI * 2834049270263837537U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2740326510600876682U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13981423865219318820U;
            aOrbiterD = RotL64((aOrbiterD * 14593082145080056441U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 231945878229848395U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14139797734944312580U;
            aOrbiterA = RotL64((aOrbiterA * 6492256080432266407U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16704102101387552373U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8506734780526852552U;
            aOrbiterK = RotL64((aOrbiterK * 4684566118627414659U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2774630043988894695U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 12490034334296488127U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16765455396278233145U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 545238171291436006U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 1023872898002379590U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8626333831510136515U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5065187021047872560U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10391809965648089863U;
            aOrbiterE = RotL64((aOrbiterE * 10912471108849550469U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5576919045471579002U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9761904001375034639U;
            aOrbiterB = RotL64((aOrbiterB * 8612901811320541361U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2001472279505185946U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11576457012366242134U;
            aOrbiterC = RotL64((aOrbiterC * 1070815118051466731U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17713147845216099336U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13204735390996728477U;
            aOrbiterH = RotL64((aOrbiterH * 10889281795183444943U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 56U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterA, 56U));
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterF, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 5U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 37U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterI, 60U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 13U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 40U) + RotL64(aOrbiterK, 21U)) + aOrbiterE) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterE, 41U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD38573FB18B6C96BULL + 0xC010CEF151397CA5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8F6DE03AD96D5C37ULL + 0xE7F9F0C98A0E07A2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA068BFFA9027A801ULL + 0x9F848C1C6BCF9E13ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF7E04C22B5649F89ULL + 0xFBEBA1E19D32A2E0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE39F4CEC6E160047ULL + 0xEAD883CAC12D9372ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFCA1107F13E32639ULL + 0xBB34A780A93C2107ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x934573BD3F955863ULL + 0xD8A76C1EA6F2768EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9CE605E17ED79DA7ULL + 0xAD4139C0A42B5184ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBECF9C0A7637E935ULL + 0xC554C8058FAA31E9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x86659B2E293F30EFULL + 0xBF92DCF733D8386DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA2EDEC50ADB4EC2BULL + 0x857C3DDE36DC1DDCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE09B1E7D1AB1CBA7ULL + 0xD965CB3FB4F0111EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA296A5407C0A08F9ULL + 0xBEEA13A589E9F659ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC7706EC6FECC46F5ULL + 0x90856E56EA62A508ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8E51D52CD379A541ULL + 0xDF8E8017957C888CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCAFAF2D5F417AE0FULL + 0xC3D9F30FC0DF65BCULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1738U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 2652U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2621U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 3325U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 52U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 1393781663398437180U) + aNonceWordK;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 40U)) + 17414594746688585273U) + aNonceWordL;
            aOrbiterH = (aWandererA + RotL64(aCross, 57U)) + 2823888497053071250U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 17032631958617884859U;
            aOrbiterD = (aWandererF + RotL64(aCross, 53U)) + 15222697630461125019U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 19U)) + 15737414920751551780U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 21U)) + 1357196111055783001U) + aPhaseFOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 5315122321649251691U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 43U)) + 7893744655508595974U) + aNonceWordN;
            aOrbiterC = (aWandererI + RotL64(aScatter, 14U)) + 16721939414324611738U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 5U)) + 3444375866323610848U) + aPhaseFOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1825716513674511632U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15582066843912467318U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12765146555943757373U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15673590949193923915U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13887365046280406413U;
            aOrbiterB = RotL64((aOrbiterB * 3169061375011420121U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12730414371734709356U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4819112390640821927U;
            aOrbiterJ = RotL64((aOrbiterJ * 8782547948627685451U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3089925954422937464U) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 7180179304678622530U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 16118051565147747413U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17030269962085008657U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6675917351883004046U;
            aOrbiterF = RotL64((aOrbiterF * 14134335325316949687U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12572022803491077491U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2801421744689267375U;
            aOrbiterG = RotL64((aOrbiterG * 315045745990934023U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4335148696780313055U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12526298573395110141U;
            aOrbiterK = RotL64((aOrbiterK * 11276803410698178607U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6984239833558496091U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12195433952105336808U;
            aOrbiterI = RotL64((aOrbiterI * 8642600547427664495U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 6392683095502982341U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 18047201953488013325U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16151795290455603489U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15433458942878109208U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1700365768743794306U;
            aOrbiterA = RotL64((aOrbiterA * 16151638348775286903U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10951473638533187729U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1393781663398437180U;
            aOrbiterC = RotL64((aOrbiterC * 2661447713922232789U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 38U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterD, 35U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterF, 6U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 51U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + aNonceWordJ);
            aWandererE = aWandererE + ((RotL64(aScatter, 4U) + aOrbiterI) + RotL64(aOrbiterA, 60U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 38U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6543U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((aIndex + 6203U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8802U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7323U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 60U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aCross, 23U)) + 15813325389431304548U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 28U)) + 2223874171125403602U) + aNonceWordE;
            aOrbiterH = (aWandererF + RotL64(aIngress, 41U)) + 5510483568496824130U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 3U)) + 15474152493495661876U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 19U)) + 16846339705130829195U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 1289670576865739669U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 18017354919647006944U) + aNonceWordD;
            aOrbiterK = (aWandererE + RotL64(aCross, 57U)) + 8539685539928984921U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 14U)) + 3333721400836704048U) + aPhaseFOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 2261560416623815491U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 51U)) + 4377786131746816567U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18047393176583722719U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8184724021940434631U;
            aOrbiterH = RotL64((aOrbiterH * 9800116157750921119U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10469895939183324807U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 14543391765109879223U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4817987697437667225U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5757225781746158178U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3539000495894022869U;
            aOrbiterC = RotL64((aOrbiterC * 1032298408884695925U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11288971092707065923U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2761384065186568294U;
            aOrbiterJ = RotL64((aOrbiterJ * 3323838837427471051U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7120580145300417101U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6977246291769372866U;
            aOrbiterI = RotL64((aOrbiterI * 15170353875184253779U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17625434527765525937U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3299714663631376190U;
            aOrbiterD = RotL64((aOrbiterD * 6532628892760776767U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10331889953489885250U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8550932256881727932U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 13085531621192583719U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11151195711186126257U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2552002192824926483U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 9754056316698523849U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8038115194286715268U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 16594489591573505305U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1241387574663818247U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 13476964484361081681U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2136330439951908303U;
            aOrbiterG = RotL64((aOrbiterG * 12728359054660550527U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 231990686776499700U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15813325389431304548U;
            aOrbiterA = RotL64((aOrbiterA * 9155088985405261637U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 51U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterA, 41U)) + aNonceWordP);
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 57U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 44U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterC, 39U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererF = aWandererF + ((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterD, 18U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 52U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15794U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 13765U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11134U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((aIndex + 13597U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 39U)) + (RotL64(aPrevious, 27U) + RotL64(aCarry, 14U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 26U)) + RotL64(aCarry, 57U)) + 252059974543142812U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 11690823093681457368U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 23U)) + 13282189752890971123U) + aNonceWordP;
            aOrbiterG = ((aWandererD + RotL64(aCross, 41U)) + 9507416294305708435U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 13U)) + 14053038174390776539U;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 14605253312318725009U) + aPhaseFOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 39U)) + 18138286582677863671U) + aNonceWordD;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 47U)) + 8530091235978489988U) + aNonceWordC;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 10U)) + 14381731677571170073U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 21U)) + 13316413456378978456U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 57U)) + 3910529530149320706U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6302070286831566901U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12324134652758551396U;
            aOrbiterI = RotL64((aOrbiterI * 17136438281540250165U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4773478557638475048U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4031153435446078944U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 3876928995240982769U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3114794895962903899U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3552936509969106796U;
            aOrbiterH = RotL64((aOrbiterH * 16823186892738820299U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5828754613946145627U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17985241114076114558U;
            aOrbiterK = RotL64((aOrbiterK * 1986669631395606833U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11319331046368072261U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6104267020171882160U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 12525117969211576177U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7662668379725735125U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6583034411403600735U;
            aOrbiterD = RotL64((aOrbiterD * 262095656452193889U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5569865728026310280U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4176065898330374039U;
            aOrbiterF = RotL64((aOrbiterF * 11305749530796963967U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13677146592276526676U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2734371113158117596U;
            aOrbiterG = RotL64((aOrbiterG * 13146444882662731975U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14890607377967461739U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3110674898918355049U;
            aOrbiterE = RotL64((aOrbiterE * 9637837600671200315U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15329760212453783067U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 18214263442264013242U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9139354822936682953U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6727267537859989206U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 252059974543142812U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 9559128226993261041U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterF, 18U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 3U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 24U) + aOrbiterF) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 10U));
            aWandererK = aWandererK + ((((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 23U)) + aOrbiterE) + aNonceWordN);
            aWandererE = aWandererE + ((((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterD, 37U)) + aNonceWordL) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + aPhaseFWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 46U) + RotL64(aOrbiterA, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 50U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17864U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((aIndex + 18308U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20702U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20484U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 54U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aPrevious, 41U)) + 15920462086654025436U;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 26U)) + 487844076858004017U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aWandererI + RotL64(aCross, 29U)) + 14502883786442630566U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 3787107318658233674U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 53U)) + 12548777544693755491U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 47U)) + 4907309444075181683U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 11U)) + 18342396700266492072U) + aNonceWordH;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 13503051997624242670U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 37U)) + 17845742460521374571U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 21U)) + 8640887211877858169U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 34U)) + RotL64(aCarry, 37U)) + 5273913123709097537U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17756844173695563883U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6713055830729302951U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2832836748513174311U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5106468334224035972U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 10228769728713526172U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9760310686414358435U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7687649520668883142U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7757480627354711605U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7222553727737349209U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10876291698508634557U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8149278085586014186U;
            aOrbiterB = RotL64((aOrbiterB * 8577133863470695381U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15592893988925610485U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8639028256640537165U;
            aOrbiterJ = RotL64((aOrbiterJ * 1880655276432963955U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 475660347892196219U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1903736092401853832U;
            aOrbiterF = RotL64((aOrbiterF * 8486318978769094799U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12463250192809450953U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7253918448601703982U;
            aOrbiterE = RotL64((aOrbiterE * 3821034106528009129U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5171661020093804486U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11627344933828324146U;
            aOrbiterG = RotL64((aOrbiterG * 5388047063152043277U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6206801139131132815U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 9221302203943031377U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 12912049016813367241U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1798857939965423979U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5476854168685641232U;
            aOrbiterK = RotL64((aOrbiterK * 3884216989250294213U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2816659151953455230U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15920462086654025436U;
            aOrbiterC = RotL64((aOrbiterC * 17843161654734820613U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterH, 43U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 20U)) + aOrbiterJ) + aNonceWordI);
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterF, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterC, 53U)) + aNonceWordM);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 41U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterI, 39U)) + aNonceWordE);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterF, 50U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + aPhaseFWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24250U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 24271U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25450U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 22038U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 43U)) + 6733949564325516029U) + aPhaseFOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 7304098437143918796U) + aNonceWordE;
            aOrbiterK = (aWandererH + RotL64(aScatter, 34U)) + 3923949518391777800U;
            aOrbiterF = (aWandererD + RotL64(aCross, 5U)) + 14243591003388927124U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 18329498724605410406U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 29U)) + 13118172167747037249U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 13U)) + 5272025143849174212U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 51U)) + 16075917179214318424U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 3U)) + 15263590648674658399U;
            aOrbiterG = (aWandererE + RotL64(aCross, 57U)) + 13730046728289525921U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 26U)) + RotL64(aCarry, 53U)) + 7703141464499623408U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 1382279753822135359U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2973369221699098292U;
            aOrbiterK = RotL64((aOrbiterK * 7440242040663550631U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11578274119583013219U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3419411247737896674U;
            aOrbiterH = RotL64((aOrbiterH * 17814942652262802991U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2582783513078999303U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3959762790273529677U;
            aOrbiterE = RotL64((aOrbiterE * 383974377372162751U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 465795011576934604U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17880826624185821135U;
            aOrbiterG = RotL64((aOrbiterG * 4445949147592860913U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10819659185349413173U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17298208553586835030U;
            aOrbiterC = RotL64((aOrbiterC * 1965860510614222093U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 12585880006661489402U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16650193903267408586U;
            aOrbiterF = RotL64((aOrbiterF * 5781132589396936615U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 885882046325991589U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 869560078374809974U;
            aOrbiterA = RotL64((aOrbiterA * 13440973563438747181U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11871305571797951851U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12137095015607196226U;
            aOrbiterI = RotL64((aOrbiterI * 7618152256560808581U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6044048326509186958U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 622564532811968856U;
            aOrbiterJ = RotL64((aOrbiterJ * 14988345089359014037U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17133994029325040272U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8612895899003926829U;
            aOrbiterB = RotL64((aOrbiterB * 2128664397481732179U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 2169081503433534750U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6733949564325516029U;
            aOrbiterD = RotL64((aOrbiterD * 10062179904046311601U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 11U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 30U)) + aOrbiterC) + aNonceWordC);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterG, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 34U) + aOrbiterB) + RotL64(aOrbiterI, 35U));
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 27U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 41U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 38U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 19U)) + aOrbiterE) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterJ, 43U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterB, 57U)) + aOrbiterH) + aNonceWordF) + aPhaseFWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 44U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30190U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 32366U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32677U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29381U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 48U)) + 2783898056762489197U) + aNonceWordA;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 41U)) + 7177192902873343053U;
            aOrbiterI = ((((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 12254703232691980774U) + aPhaseFOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aWandererF + RotL64(aScatter, 53U)) + 15446547245691219559U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 13U)) + 888475203006174856U) + aNonceWordL;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 21U)) + 3649183529366307877U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 4642631047518805167U;
            aOrbiterF = (aWandererD + RotL64(aCross, 3U)) + 6108329730724782250U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 27U)) + 8334054653023816636U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 5891895375031474350U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 24U)) + 3176720746238477862U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 6111038696865301675U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11914998302228682704U;
            aOrbiterI = RotL64((aOrbiterI * 11738924766359642853U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17005063057791320948U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18333780598768130670U;
            aOrbiterD = RotL64((aOrbiterD * 5416759844884107303U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2056115016443263153U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10245512728872962677U;
            aOrbiterA = RotL64((aOrbiterA * 707106795383284903U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4810366069422162351U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3051442983125942469U;
            aOrbiterH = RotL64((aOrbiterH * 13558537578054436423U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9285068547223654308U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13067251130180968842U;
            aOrbiterF = RotL64((aOrbiterF * 7000687697769766605U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3203670242792002165U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1770881716916463461U;
            aOrbiterB = RotL64((aOrbiterB * 13870229847371882171U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 16286823712870537410U) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 13067191141829694202U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 15629974528467350445U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3414576315085336932U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8979691827341555245U;
            aOrbiterK = RotL64((aOrbiterK * 15971594804040295757U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11370607523115189596U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1346943598249651668U;
            aOrbiterC = RotL64((aOrbiterC * 4994794423314630209U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2441719135451272926U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3347272129827184676U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10434510775894776597U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1116857329130532047U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2783898056762489197U;
            aOrbiterE = RotL64((aOrbiterE * 9504855173533274401U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 26U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterI, 47U)) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aScatter, 54U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 60U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 27U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + aNonceWordB);
            aWandererD = aWandererD + ((RotL64(aPrevious, 18U) + RotL64(aOrbiterG, 51U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 3U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 53U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 34U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordA);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCCCB73DC64C92711ULL + 0xAA5FA07A8F3FEA64ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEE8DD158533D56FDULL + 0xE09DE01CA5E170BBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x892DDA2F238B956DULL + 0x95E6B6ABE131D062ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA39FBA278E07528FULL + 0xBA6B0412F33F22E8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAB5A21C41A863E97ULL + 0xA3B0DBF40B547F64ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE6AF57252C87C077ULL + 0xC10673A997D38561ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA00EAC681E5752C7ULL + 0xF3C4EEB0DBF190B7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x90909D702704FEA9ULL + 0xF35537EBF546DBFDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC3B6AA52D536A771ULL + 0xBE49E3BC2FBF9768ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF82ECF2EFB7D8423ULL + 0xD61520C29EF30AB1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC4D6CCE18E838DC9ULL + 0x85D0A71547A516B0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD9C592E44863CFF5ULL + 0xCA9CF6F853F211DCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA101DF2A7F4561C3ULL + 0xC8AA26F8D4DCBDB7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA9DE9D27B3057525ULL + 0xB4A7322B8517D707ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBAD7FD0A622EA9DDULL + 0xED360EDAFBDA2AB4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF6B07C4B6CAFAF27ULL + 0x99935340EA39CDEBULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1080U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((aIndex + 2268U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5038U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5101U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 58U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aIngress, 5U)) + 6069475454765660321U;
            aOrbiterI = (aWandererD + RotL64(aCross, 39U)) + 11483704742497268068U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 60U)) + 11055697447388986418U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 23U)) + 10897095046039997004U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 4731637118230457840U) + aPhaseFOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 13855839187084986751U) + aNonceWordC;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 5328208115460188239U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 51U)) + 12479538544291412985U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 56U)) + 10740165998792608231U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 43U)) + 6492798157284955373U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 37U)) + 13056825957483891921U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2068184064919194657U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5656302738780746294U;
            aOrbiterA = RotL64((aOrbiterA * 16493021179127646345U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11193756120230763294U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17306750816837208999U;
            aOrbiterK = RotL64((aOrbiterK * 7949360041241439741U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12952818800389361804U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15380412293642628312U;
            aOrbiterD = RotL64((aOrbiterD * 2914662289178925547U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7706090204767242996U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14598802276412649570U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4821408736292041399U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 17819762117328075515U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6481384240915075101U;
            aOrbiterE = RotL64((aOrbiterE * 4836701121865783029U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 754936290510338717U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15510875946573720154U;
            aOrbiterC = RotL64((aOrbiterC * 2994718968852184303U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9245381722813944586U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2629847912019726214U;
            aOrbiterG = RotL64((aOrbiterG * 6718795794951106961U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3909987749797113773U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9277056074757335265U;
            aOrbiterI = RotL64((aOrbiterI * 11580847505996697115U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12577180954515966707U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9144513680789115458U;
            aOrbiterH = RotL64((aOrbiterH * 8880777678193004979U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1544232962956974411U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2658275904714859636U;
            aOrbiterF = RotL64((aOrbiterF * 1926083316365175327U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5733515391293514025U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6069475454765660321U;
            aOrbiterJ = RotL64((aOrbiterJ * 9627476106108146391U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 48U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 40U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterD, 43U)) + aNonceWordO);
            aWandererH = aWandererH + ((RotL64(aIngress, 44U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterE, 27U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 23U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 35U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aNonceWordD);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterC, 14U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordK);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6791U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((aIndex + 9774U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6839U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9922U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 20U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererH + RotL64(aIngress, 13U)) + 10038936806177516123U) + aNonceWordD;
            aOrbiterH = (aWandererF + RotL64(aCross, 53U)) + 1773168435195292638U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 56U)) + 10655711161526628072U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 29U)) + 14422295664639740437U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 35U)) + 4125228715513159576U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 3670449653158650845U;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 17553727567180813057U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 5111401772713882743U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 23U)) + 7688573124662314413U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 26U)) + 9438375825507814395U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 41U)) + 14177477039902118886U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 16329942595859623928U) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3990536794006836672U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 579024714339065373U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5072881436583180756U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16789727877867289997U;
            aOrbiterH = RotL64((aOrbiterH * 8766246302636197905U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17313956922306689438U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11530878396329822041U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11356860047841383129U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3612616532321160196U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 4172189825359187763U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12938945495299393177U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8677279703778052804U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1912172980909479362U;
            aOrbiterB = RotL64((aOrbiterB * 10053289257955474143U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1460085850227494500U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12116763868122868147U;
            aOrbiterI = RotL64((aOrbiterI * 6076945628020280957U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17571840610366424432U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15581362592611080868U;
            aOrbiterF = RotL64((aOrbiterF * 1129054058044872003U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14434700039977611666U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4534294602623329152U;
            aOrbiterC = RotL64((aOrbiterC * 5860911553425182045U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 865998255725903702U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16407778704555344108U;
            aOrbiterD = RotL64((aOrbiterD * 15571344643129797977U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 1948990288894429805U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 18218556219056835250U;
            aOrbiterA = RotL64((aOrbiterA * 16574160087642377293U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1309229265173143398U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10038936806177516123U;
            aOrbiterK = RotL64((aOrbiterK * 12954594462760207923U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 12U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterA, 51U)) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 23U)) + aOrbiterA) + aNonceWordJ);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 47U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterC, 58U));
            aWandererI = aWandererI + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterB, 21U));
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 26U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + aPhaseFWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterD, 56U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterA, 19U)) + aPhaseFWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11172U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12322U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15746U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 14211U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 58U) ^ RotL64(aIngress, 13U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 15920462086654025436U) + aNonceWordF;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 13U)) + 487844076858004017U) + aPhaseFOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 19U)) + 14502883786442630566U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 22U)) + RotL64(aCarry, 37U)) + 3787107318658233674U) + aNonceWordM;
            aOrbiterA = (aWandererH + RotL64(aCross, 27U)) + 12548777544693755491U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 4907309444075181683U) + aPhaseFOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 37U)) + 18342396700266492072U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 29U)) + 13503051997624242670U) + aNonceWordN;
            aOrbiterD = (aWandererB + RotL64(aCross, 43U)) + 17845742460521374571U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 34U)) + 8640887211877858169U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 51U)) + 5273913123709097537U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17756844173695563883U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6713055830729302951U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 2832836748513174311U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5106468334224035972U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10228769728713526172U;
            aOrbiterE = RotL64((aOrbiterE * 9760310686414358435U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7687649520668883142U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7757480627354711605U;
            aOrbiterC = RotL64((aOrbiterC * 7222553727737349209U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10876291698508634557U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8149278085586014186U;
            aOrbiterA = RotL64((aOrbiterA * 8577133863470695381U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15592893988925610485U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8639028256640537165U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 1880655276432963955U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 475660347892196219U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1903736092401853832U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8486318978769094799U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12463250192809450953U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7253918448601703982U;
            aOrbiterF = RotL64((aOrbiterF * 3821034106528009129U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 5171661020093804486U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11627344933828324146U;
            aOrbiterK = RotL64((aOrbiterK * 5388047063152043277U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6206801139131132815U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9221302203943031377U;
            aOrbiterJ = RotL64((aOrbiterJ * 12912049016813367241U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1798857939965423979U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5476854168685641232U;
            aOrbiterD = RotL64((aOrbiterD * 3884216989250294213U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2816659151953455230U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15920462086654025436U;
            aOrbiterG = RotL64((aOrbiterG * 17843161654734820613U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 39U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 6U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 43U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterK, 50U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + aNonceWordG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 6U) + RotL64(aOrbiterA, 13U)) + aOrbiterF) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterH, 5U));
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 36U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterC, 57U));
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterK, 21U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20942U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 16902U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20229U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16543U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aIngress, 47U)) + 13174219512651137892U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 2715455762789269341U;
            aOrbiterB = (aWandererA + RotL64(aCross, 56U)) + 1338018183235594313U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 11U)) + 16566866551729552930U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 5U)) + 6901845297307236726U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 2476078302049201718U) + aNonceWordM;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 29U)) + 15531109473927052260U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 51U)) + 4087849380858572351U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 23U)) + 5167830630098599644U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 37U)) + 7275995452428627217U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 3U)) + 14794340370010024117U) + aPhaseFOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8509217403041662849U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2321522025240806996U;
            aOrbiterB = RotL64((aOrbiterB * 113568101672878697U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5676672952755594051U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2304681269233504384U;
            aOrbiterC = RotL64((aOrbiterC * 15731441084605554497U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8383399721062437300U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 13181984036942227666U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1648761328771932069U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13602604532551684210U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12725687663616352843U;
            aOrbiterJ = RotL64((aOrbiterJ * 4684699861686199753U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5831790822416009806U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 4535048543735457407U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12076777878870257053U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10617608605149381858U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5244225377862618630U;
            aOrbiterF = RotL64((aOrbiterF * 15307177251167023999U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 18229989093139888456U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9728120630096192811U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 16052574428163231023U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1312233443099767304U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8043115602160128619U;
            aOrbiterA = RotL64((aOrbiterA * 9365756845731616963U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4679339316686216023U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 211799535650113758U;
            aOrbiterE = RotL64((aOrbiterE * 1478368466990144107U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13307123762743628190U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7093673238704478497U;
            aOrbiterI = RotL64((aOrbiterI * 13273906568866802561U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16396459072175632290U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13174219512651137892U;
            aOrbiterK = RotL64((aOrbiterK * 7581008806810219369U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 58U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterA, 36U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + aNonceWordF) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 11U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 39U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 23U)) + aOrbiterB) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aScatter, 18U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterH, 19U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 6U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24946U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21863U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23637U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 24626U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 60U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aPrevious, 13U)) + 17074147006464019918U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 35U)) + 10559516626129419928U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 13280363679503946221U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 27U)) + 17657115422132457413U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 13325837013304973008U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 18U)) + 3059707750486106037U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 4529045702503050852U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 41U)) + 10726578475550904292U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 57U)) + 14832537837996659885U) + aNonceWordC;
            aOrbiterD = ((aWandererC + RotL64(aCross, 11U)) + 220094417441809246U) + aNonceWordP;
            aOrbiterI = (aWandererH + RotL64(aIngress, 46U)) + 15343130035105342194U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16592263353426409884U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 15649290906447931918U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8405875177836650731U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11437410545843708269U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5859769136073011444U;
            aOrbiterA = RotL64((aOrbiterA * 1065016088086441107U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15188064100307340341U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4367466521843260049U;
            aOrbiterJ = RotL64((aOrbiterJ * 15916715854192820923U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8482617283860566845U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2585745804937342972U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8267269625632139809U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1687641344403425541U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13667916445979421400U;
            aOrbiterH = RotL64((aOrbiterH * 8191322670355590027U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7684258716388029228U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14764266202380443369U;
            aOrbiterK = RotL64((aOrbiterK * 1746254773647650741U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12685190466981675661U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9958374400222383893U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12696606920219838929U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 1352584794098160330U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16057453941015251708U;
            aOrbiterF = RotL64((aOrbiterF * 6051546505117202495U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5642244742563733299U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2946279435712646692U;
            aOrbiterI = RotL64((aOrbiterI * 3711867103848631343U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17305358424001395035U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1831722001182742673U;
            aOrbiterB = RotL64((aOrbiterB * 13867284970939557547U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12354430852596737299U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17074147006464019918U;
            aOrbiterC = RotL64((aOrbiterC * 17316050599218057961U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 30U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterK, 10U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 24U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterH, 19U));
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterB, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterB, 41U)) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 30U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 43U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 35U)) + aOrbiterI) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterH, 23U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 36U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27846U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28951U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32386U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29589U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 10U) + RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aCross, 47U)) + 6916817163240024692U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 24U)) + 14554930751292077817U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 1098305064484336101U) + aNonceWordK;
            aOrbiterI = (aWandererC + RotL64(aIngress, 53U)) + 12192821172420471527U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 27U)) + 2435134991707318845U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 3U)) + 1896745368738512624U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 50U)) + 1114996424222923873U) + aPhaseFOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 11U)) + 9839135798371512656U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 8037967239603177043U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 15185468738487237432U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 43U)) + 4912098316394854543U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13142688607850380888U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4507379759608945839U;
            aOrbiterJ = RotL64((aOrbiterJ * 2989332387754215967U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7299006009652289342U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5390655277207053627U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10973744708856143715U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 6744737023577785725U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15539737698867067285U;
            aOrbiterH = RotL64((aOrbiterH * 4686092035261336911U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13329866734681377952U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13284937458969166257U;
            aOrbiterC = RotL64((aOrbiterC * 3965985432462699445U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8695002088915702168U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3858059421620839286U;
            aOrbiterB = RotL64((aOrbiterB * 9559783727301092937U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6609163873243179836U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 9416165620556710540U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 240385043740268229U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1578449067529000433U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14309000104419489303U;
            aOrbiterK = RotL64((aOrbiterK * 7599078306153684729U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15785180680737461320U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10099222679918382021U;
            aOrbiterF = RotL64((aOrbiterF * 2012232597046182581U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10666287769220108179U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13648647399222807034U;
            aOrbiterD = RotL64((aOrbiterD * 10772381733103127201U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9292207828896796810U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9155130791347443553U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16838229790655977057U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11334395119119245556U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6916817163240024692U;
            aOrbiterI = RotL64((aOrbiterI * 9640906826978028183U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 52U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 39U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterB, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 60U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + aNonceWordA) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterK, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterD, 29U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 3U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ) + aNonceWordP) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 44U) + aOrbiterG) + RotL64(aOrbiterC, 46U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 7423U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2453U)) & W_KEY1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 7078U)) & W_KEY1], 54U) ^ RotL64(mSource[((aIndex + 3458U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererC + RotL64(aPrevious, 58U)) + 12692813903177772178U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 41U)) + 7112496446691277899U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 41U)) + 2112247138290568813U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 3699421080882855947U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 52U)) + 13761832028354380922U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 5U)) + 9243822514887600214U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 6863833516853046129U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 13U)) + 8863897995943098018U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 47U)) + 13346785686701467520U) + aPhaseCOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15309543066305531619U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17515530938817919111U;
            aOrbiterI = RotL64((aOrbiterI * 16625193986319048245U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 760493237816424254U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7282586354117620860U;
            aOrbiterF = RotL64((aOrbiterF * 2327153408185290635U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4129706068526969105U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7020175432730888755U;
            aOrbiterJ = RotL64((aOrbiterJ * 10095158356907592239U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9102258982216515596U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10822031305361453690U;
            aOrbiterG = RotL64((aOrbiterG * 2036205056490578491U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 12571477440964330246U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8436347026653095199U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17930734781213681573U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14214789872073941940U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12915911919403385001U;
            aOrbiterB = RotL64((aOrbiterB * 13161681603528031511U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15443240166233851298U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7311369180113240915U;
            aOrbiterH = RotL64((aOrbiterH * 13339195007946889423U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12976516224995960015U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7823308381434556721U;
            aOrbiterD = RotL64((aOrbiterD * 502385172763861451U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4829417661664149137U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16306394751966719700U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5294376579588592157U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 26U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterH, 60U)) + aPhaseCWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aPrevious, 56U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 27U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 56U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 47U)) + aPhaseCWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 44U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9715U)) & S_BLOCK1], 34U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 16205U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12024U)) & W_KEY1], 46U) ^ RotL64(aKeyRowReadB[((aIndex + 12143U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 13U)) ^ (RotL64(aCross, 44U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererA + RotL64(aCross, 43U)) + 1210605127156905516U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 11964595428173569519U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 48U)) + RotL64(aCarry, 19U)) + 16277319029916258482U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 57U)) + 12369497463101824572U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 39U)) + 6201248574067068202U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 21U)) + 1727477025667206661U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 14U)) + 1404510627789806851U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 6948213591282018925U) + aPhaseCOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aPrevious, 3U)) + 6688865181284421478U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3351130769402360855U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12681032488906270823U;
            aOrbiterK = RotL64((aOrbiterK * 3680893896579741263U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3591412591193726763U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16153817571210878589U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4165137036092246349U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3808228354421006630U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1427373776207504205U;
            aOrbiterB = RotL64((aOrbiterB * 4534374093769595531U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1831554180932501132U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1114853085120949215U;
            aOrbiterD = RotL64((aOrbiterD * 4264176108298812905U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2080935638828366835U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16104777999646489828U;
            aOrbiterI = RotL64((aOrbiterI * 15205199362011777473U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9782806013673440791U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3721620299829386454U;
            aOrbiterH = RotL64((aOrbiterH * 6286765834910272409U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4013706412064296527U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5751022780695158579U;
            aOrbiterJ = RotL64((aOrbiterJ * 13766736471646116397U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17684546333240329338U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1106947111128020920U;
            aOrbiterG = RotL64((aOrbiterG * 3158839453318658951U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11564229705849500598U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1585817314460274286U;
            aOrbiterA = RotL64((aOrbiterA * 12687162159791577431U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 34U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterI, 14U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterD, 19U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterB, 51U));
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 5U)) + aOrbiterA) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 39U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 30U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23537U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 17419U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 18278U)) & W_KEY1], 41U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 17926U)) & W_KEY1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 26U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererI + RotL64(aIngress, 14U)) + 12669015908335980355U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 5438715179868613192U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 47U)) + 13172104448184536460U;
            aOrbiterK = (aWandererF + RotL64(aCross, 51U)) + 13421421503244744803U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 13327113302994856582U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 57U)) + 4671768205922454413U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 35U)) + 5355759962838579929U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 10U)) + 6691720614265406851U) + aPhaseCOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 7063906424700911378U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17328616394166672263U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1542940602574207068U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8981679306319627975U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7203866278803132454U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 993485696233139264U;
            aOrbiterB = RotL64((aOrbiterB * 11609009908810366447U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15659679028507488331U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 18321361454094675842U;
            aOrbiterK = RotL64((aOrbiterK * 3966860765622641843U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9633319822696783352U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3496559332232402963U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7772060229838162977U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1918349708324205526U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7701088402761359134U;
            aOrbiterJ = RotL64((aOrbiterJ * 9649485438465644795U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6006824348814439686U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 18088375375347012557U;
            aOrbiterI = RotL64((aOrbiterI * 12801082943086128385U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12816533373478543584U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17951880253818836433U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8935839101517220201U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11311632024372748238U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9891349164779752351U;
            aOrbiterF = RotL64((aOrbiterF * 11405973752233193209U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 711130292000437038U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17818800917771709681U;
            aOrbiterE = RotL64((aOrbiterE * 10567029732245868263U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 54U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 39U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 24U)) + aOrbiterD) + aPhaseCWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererH = aWandererH + ((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterE, 19U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + aPhaseCWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 52U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aPrevious, 46U) + RotL64(aOrbiterF, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29187U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 29645U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29965U)) & S_BLOCK1], 12U) ^ RotL64(mSource[((aIndex + 28373U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 35U)) + 18144572925667544139U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aCross, 22U)) + RotL64(aCarry, 39U)) + 5659758077574059728U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 51U)) + 6343330616999166392U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 17754639838410839447U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 13U)) + 9451843819849581729U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 18U)) + RotL64(aCarry, 47U)) + 7957854457197462212U;
            aOrbiterG = (aWandererG + RotL64(aCross, 47U)) + 1461994799722205010U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 5U)) + 18002214276252170177U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 43U)) + 14689869073147027164U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3978104368003440293U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8512135845221335386U;
            aOrbiterD = RotL64((aOrbiterD * 10506667163729414667U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1477533446382953439U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2166717790929947990U;
            aOrbiterA = RotL64((aOrbiterA * 6538884492418324461U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8082437060686606995U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4363687722464700362U;
            aOrbiterG = RotL64((aOrbiterG * 7199165810993478887U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15782763348014924206U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8572509150015960728U;
            aOrbiterC = RotL64((aOrbiterC * 3340528604891897779U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12248271773316742521U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9602078627638561949U;
            aOrbiterE = RotL64((aOrbiterE * 1860631869877427405U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17244849374768558859U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 1030743048280579012U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10858949914285817051U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17722342363541914280U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15667504059789880034U;
            aOrbiterJ = RotL64((aOrbiterJ * 15872269872168533709U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12645332941998550794U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9938135244509986497U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16548185968987392957U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4024609904162105979U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6732064218696157303U;
            aOrbiterK = RotL64((aOrbiterK * 3815409766145891393U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 24U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterK, 18U));
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterB, 37U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 56U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 3U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + aPhaseCWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 41U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterB, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2602U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2768U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2477U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 6402U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 56U)) ^ (RotL64(aCross, 19U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 4384716820085860551U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 40U)) + 9715780315942116888U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 15963520052789178632U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 14346700690686392938U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 57U)) + 6005518012489966643U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2506732930310252119U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 16782163084851775826U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1527050617428162663U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 823673076571076303U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1634084509064077736U;
            aOrbiterH = RotL64((aOrbiterH * 1128407326773234517U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 1288134975466877686U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 2998220403162908444U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4321412662318298283U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 220430672180734911U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10223923547068528867U;
            aOrbiterE = RotL64((aOrbiterE * 12577370238343872139U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11696469696177647608U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6545430420379636963U;
            aOrbiterA = RotL64((aOrbiterA * 8387163146257553773U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterA, 14U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterC, 5U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterD, 27U)) + aPhaseDWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9429U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10054U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9098U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 9472U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 22U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererJ + RotL64(aIngress, 3U)) + 3238389262925516513U;
            aOrbiterH = (aWandererE + RotL64(aCross, 19U)) + 12381787182611386995U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 58U)) + RotL64(aCarry, 35U)) + 7883885539305181549U) + aPhaseDOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 1185413044597727092U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 15219353497204773135U) + aPhaseDOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7533774715626734082U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2599930450937763464U;
            aOrbiterA = RotL64((aOrbiterA * 13207380361960949159U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16074720663961214284U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15483613196360051221U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11717479088020532861U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9396557867081376268U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9668459976852660245U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11748505665890567063U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9037269914643207212U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16936742640861088240U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1040172193161012227U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16481274825758546398U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 481851372837611166U;
            aOrbiterI = RotL64((aOrbiterI * 2225030139210599207U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 6U)) + aOrbiterA) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 28U) + RotL64(aOrbiterF, 41U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 29U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 53U)) + aOrbiterA) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21922U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 23687U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22415U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17231U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 44U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererJ + RotL64(aCross, 53U)) + 15036852811491820366U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 305637140752898475U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 11948631574496129610U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 5321623592482991426U) + aPhaseDOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 14U)) + 4075270159062690728U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15111580500356908928U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7244150695504160363U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2445733898697939969U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5131563519577488862U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5881954992088651371U;
            aOrbiterE = RotL64((aOrbiterE * 2424421828597294607U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12780935808751507998U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12599159643925470226U;
            aOrbiterH = RotL64((aOrbiterH * 17690046932587062701U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9466589929741834066U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6093158735705189789U;
            aOrbiterD = RotL64((aOrbiterD * 7453778295800853653U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17461243886150519249U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15456408913739900718U;
            aOrbiterA = RotL64((aOrbiterA * 16093292401746174671U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 34U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 13U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 52U)) + aOrbiterF) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + aPhaseDWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 14U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30166U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25635U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28343U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 30956U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 21U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 29U)) + 16922357079016918108U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 11771749797137599131U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 4635668433708036077U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 14U)) + RotL64(aCarry, 3U)) + 15827952719230577008U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 5U)) + 1495675306110023086U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7294835466949728365U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 179122461212041978U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14467072888722097971U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 545981421632236251U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15338259639814630535U;
            aOrbiterI = RotL64((aOrbiterI * 14895421566334357871U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12924313840290895215U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17846785921286020610U;
            aOrbiterB = RotL64((aOrbiterB * 18309347016029917133U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5721472794107057875U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16359630793856870319U;
            aOrbiterF = RotL64((aOrbiterF * 14186771515526698907U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10614102110239037308U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 16421992251278236531U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2561232904676068089U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 3U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 58U) + aOrbiterF) + RotL64(aOrbiterG, 21U));
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterI, 3U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 37U)) + aPhaseDWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 52U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 14U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4218U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 6204U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7647U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2033U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 1708250618750199233U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 60U)) + 12009147777553691142U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 41U)) + 8393982703399156592U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 19U)) + 3247327098356831221U) + aPhaseEOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 3403590155376353737U) + aPhaseEOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 18197244558104735044U;
            aOrbiterB = (aWandererF + RotL64(aCross, 27U)) + 3096253642040701606U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8012692688785412179U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17531946907545680745U;
            aOrbiterI = RotL64((aOrbiterI * 16510602981731506381U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17687695944270225817U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16147773866007628769U;
            aOrbiterA = RotL64((aOrbiterA * 16926442582711557877U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18244641303026196497U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8839160526348897457U;
            aOrbiterE = RotL64((aOrbiterE * 14268021129087663397U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10599266240854068246U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 2056723540756216155U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13311591601230386375U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4629354220460621284U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9505955649473204942U;
            aOrbiterK = RotL64((aOrbiterK * 17775391885312236187U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17078153810088721310U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9470436761716263000U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5431855497250357229U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3305863413630104742U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14377172434239576161U;
            aOrbiterD = RotL64((aOrbiterD * 6880176890091033423U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 12U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 46U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 58U) + aOrbiterK) + RotL64(aOrbiterE, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterD, 53U));
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 29U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 37U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 42U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15894U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 12220U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8707U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((aIndex + 16146U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 14U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 12809562813316740345U;
            aOrbiterK = (((aWandererB + RotL64(aCross, 20U)) + RotL64(aCarry, 13U)) + 17084212535326321199U) + aPhaseEOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 35U)) + 16074921689983846769U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 51U)) + 14027986153007120145U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 7633455951809250227U;
            aOrbiterG = (aWandererF + RotL64(aCross, 29U)) + 340989348513370174U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 13U)) + 5307820377645020116U) + aPhaseEOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5605285015771527274U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5293500434746182790U;
            aOrbiterJ = RotL64((aOrbiterJ * 17674669610895537063U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7263156475892261811U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10672879570907433005U;
            aOrbiterA = RotL64((aOrbiterA * 2506338667179450741U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16659226780900986107U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9774892622769850665U;
            aOrbiterH = RotL64((aOrbiterH * 7487477727543183211U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10728057184108279042U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5032485856947407217U;
            aOrbiterK = RotL64((aOrbiterK * 16651577903809154285U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14642241075374862345U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8386481273395203518U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11649977733867003445U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2874153265304098104U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11519900149177261000U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2010158758971864505U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8885690878540115768U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4482143389870987714U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7105332459437434281U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 18U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterA, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 36U) + aOrbiterG) + RotL64(aOrbiterD, 23U));
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 36U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterG, 5U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterH, 43U));
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 57U)) + aOrbiterK) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24436U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 21158U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19667U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 16425U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 52U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 21U)) + 16189787374324972735U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 17563763730956242224U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 51U)) + 10572803498593789385U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 7713105232072974166U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 13U)) + 10760839534772718139U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 58U)) + 13397069448391230253U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 4569255679998375682U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9888769350817876949U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11351796060878856300U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13356749147334008399U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18153775071965707204U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1282846411145853435U;
            aOrbiterH = RotL64((aOrbiterH * 12294455920906257823U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16457743979262460660U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 173493260775251032U;
            aOrbiterJ = RotL64((aOrbiterJ * 4935807229040883505U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3927345926316409630U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5158769729850853623U;
            aOrbiterK = RotL64((aOrbiterK * 2446452358663812945U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12331351600010165154U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3940794200348684050U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13248997263062075043U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11248514843822945425U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1391497323278226522U;
            aOrbiterE = RotL64((aOrbiterE * 8376841806072565005U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13265623528678787307U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2802033745265647317U;
            aOrbiterF = RotL64((aOrbiterF * 3437626962562016147U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 51U));
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 34U) + aOrbiterF) + RotL64(aOrbiterD, 11U));
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 34U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 57U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 43U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32164U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 28035U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31609U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneD[((aIndex + 28266U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 56U)) ^ (RotL64(aIngress, 13U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 56U)) + RotL64(aCarry, 19U)) + 7893287783892523139U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 10257331997383491153U) + aPhaseEOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 3U)) + 14562226733652231753U) + aPhaseEOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aIngress, 23U)) + 14320342577110737851U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 41U)) + 9816717579822880756U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 11U)) + 9558926960095881953U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 9230371862654338324U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6414274291252913420U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 13868546184398350849U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1547986864837497409U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16940736952569949038U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2866957764814864371U;
            aOrbiterA = RotL64((aOrbiterA * 3554702178644797003U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7916721976073979724U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 1602444214978842275U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11072503711308122385U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9529061385251008037U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8402775110887376588U;
            aOrbiterK = RotL64((aOrbiterK * 13980225144628227381U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15003592180290390713U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14195681406520825751U;
            aOrbiterG = RotL64((aOrbiterG * 11455000833788877217U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3263577002367714202U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12019422062655581928U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5002313835338447799U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8508638054582582917U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6536618106353552880U;
            aOrbiterI = RotL64((aOrbiterI * 6233964121117511885U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterG, 28U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterG, 5U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterA, 39U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterK, 57U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 21U)) + aOrbiterI);
            aWandererA = aWandererA + ((((RotL64(aScatter, 4U) + aOrbiterG) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Lacrosse_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2978U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((aIndex + 328U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4068U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1854U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 11998579547770778580U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 8409465187298704610U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 50U)) + 3470222286110333500U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 3U)) + 5704486785203069994U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 10334944660253279633U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 7626852700722567477U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14631310754943209743U;
            aOrbiterA = RotL64((aOrbiterA * 1958866541508493967U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 807160297237854120U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5624154783624196107U;
            aOrbiterE = RotL64((aOrbiterE * 2404066593958052159U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 4971444394698940423U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6340057638461027062U;
            aOrbiterD = RotL64((aOrbiterD * 12027586111086798629U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9003019862787819481U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13632057463595873033U;
            aOrbiterH = RotL64((aOrbiterH * 12575202147280216765U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12766104026871797746U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4062118445824915939U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13130770039048080701U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 44U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9318U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14049U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15396U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((aIndex + 10628U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 50U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 8793908991006073956U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 22U)) + RotL64(aCarry, 13U)) + 2932916283348441943U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 11069042087940968262U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 39U)) + 14369628676782894441U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 57U)) + 8602903272780978282U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3827036107178568820U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8905245209036772489U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5744017326197157667U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13331387530760017893U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9880107580289737823U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10302652857542703753U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10199619040626900278U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2466307560891374281U;
            aOrbiterF = RotL64((aOrbiterF * 6295342978834217571U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13973403407981259448U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 2851460278409385243U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11226902976321781743U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10365453393815690776U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2382382358987358791U;
            aOrbiterJ = RotL64((aOrbiterJ * 481563628980705781U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 40U) + RotL64(aOrbiterE, 57U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 20U)) + aOrbiterI) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterI, 37U)) + aPhaseFWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22973U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18450U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22185U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22196U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aIngress, 37U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 12311607308490066301U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 54U)) + RotL64(aCarry, 11U)) + 13100864684740679846U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 13697304189274329704U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 11U)) + 9047976902871216732U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 3U)) + 2147897579538537888U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2072444829390996142U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2129307836981020908U;
            aOrbiterB = RotL64((aOrbiterB * 8065769537670939667U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10663145333751112064U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15019844390503785459U;
            aOrbiterJ = RotL64((aOrbiterJ * 7442321463110790449U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5460865577557928142U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15806522559993224197U;
            aOrbiterD = RotL64((aOrbiterD * 8722932687972240099U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6361113778657833389U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8306013884615042570U;
            aOrbiterC = RotL64((aOrbiterC * 8234258702656728667U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4038420580499706912U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11908091484457158973U;
            aOrbiterF = RotL64((aOrbiterF * 3964111175645156719U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterB, 47U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 39U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aCross, 54U) + aOrbiterB) + RotL64(aOrbiterJ, 56U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26923U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27142U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27993U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29529U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 8101351470141807662U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 3U)) + 6965474099521076705U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 6803828268885684784U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 13454235922950972488U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 34U)) + 11678091885751244777U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5307134544628507141U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4873703518950429353U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2680442582958424915U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8542156221858586039U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3993726182905296513U;
            aOrbiterF = RotL64((aOrbiterF * 11331376012938127609U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12113047622035464386U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1944244448665721151U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7010050836758762003U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12914188029425467576U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2486762763475327024U;
            aOrbiterH = RotL64((aOrbiterH * 12319769994433811617U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14580191602982245481U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12093414832400135066U;
            aOrbiterG = RotL64((aOrbiterG * 12720286833215690663U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 42U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterC, 39U)) + aPhaseFWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterG, 12U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterA, 23U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 4U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 392U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2788U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6368U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2684U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 18U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 3105313968748067810U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 27U)) + 9977249451119627064U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aScatter, 60U)) + 17941392803495349366U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 4279533326705471133U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 13983828966811580039U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3983490984234810378U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 308786542215259956U;
            aOrbiterF = RotL64((aOrbiterF * 4366245356597769425U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8443607695364427037U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14939626441464340668U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16793255020331774983U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9350693577306121110U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1717071159396961752U;
            aOrbiterA = RotL64((aOrbiterA * 11062480662625054525U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 15911765265202100610U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14898546272333182767U;
            aOrbiterD = RotL64((aOrbiterD * 2674900543810733067U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3560903518513465868U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5367062725726860234U;
            aOrbiterG = RotL64((aOrbiterG * 8521908836601319553U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 18U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterF, 24U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterC, 13U)) + aPhaseGWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 9728U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11125U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11881U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14571U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 37U)) + (RotL64(aCross, 51U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 16802219662864902427U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 35U)) + 14332033461409490629U) + aPhaseGOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 8781794298640286845U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 27U)) + 8459933908074937264U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 58U)) + 1883580287986004426U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17500258188004626118U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7934811305150872870U;
            aOrbiterB = RotL64((aOrbiterB * 10039004285642030761U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6380363892361098905U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12623079132626676910U;
            aOrbiterA = RotL64((aOrbiterA * 12406671746344127399U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10455208121949202703U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8805532707916767629U;
            aOrbiterF = RotL64((aOrbiterF * 666082374369701881U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9161544391400377699U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3501434325829663268U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7933545151293799637U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 651783304096081996U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 441505031509930622U;
            aOrbiterD = RotL64((aOrbiterD * 8045355432310956143U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterA, 39U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 11U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 54U) + RotL64(aOrbiterJ, 48U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 22630U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18136U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22606U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 19135U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 20U) + RotL64(aIngress, 39U)) ^ (RotL64(aCross, 3U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererD + RotL64(aIngress, 5U)) + 3255291173184001106U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 48U)) + RotL64(aCarry, 23U)) + 15308468160116255528U;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 18186972408589866656U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 4439324265978331914U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 21U)) + 13099263173016322486U) + aPhaseGOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7041561081767500660U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6196422612687812971U;
            aOrbiterB = RotL64((aOrbiterB * 13359900204297781063U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7664260932541281413U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17802347823020441056U;
            aOrbiterF = RotL64((aOrbiterF * 2220679459017369255U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 4253107484061190446U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13799496534030645312U;
            aOrbiterI = RotL64((aOrbiterI * 9167675060053848207U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14252892847595951926U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5663527578664291422U;
            aOrbiterA = RotL64((aOrbiterA * 18314294235895182465U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11148755959699137661U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 17036900929333594592U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16041243617369003291U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 40U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + aPhaseGWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 13U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 40U) + aOrbiterF) + RotL64(aOrbiterI, 54U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 32081U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 31889U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30432U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25298U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 22U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 3448371607470865612U) + aPhaseGOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 3743742913651580573U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 12U)) + RotL64(aCarry, 3U)) + 13069491287948807280U) + aPhaseGOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 37U)) + 16872779275586545632U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 51U)) + 17945792656755062795U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 18199747196793731853U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15953311878379809513U;
            aOrbiterK = RotL64((aOrbiterK * 5476802169152352897U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 941268763494588338U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10090221530365796809U;
            aOrbiterE = RotL64((aOrbiterE * 14035236086292997613U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8335698093307607001U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6147498804734306100U;
            aOrbiterI = RotL64((aOrbiterI * 6904444049941211327U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5980246079567570090U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4152167624425912978U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10019421651535123573U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14990418790239735916U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3418668387496597219U;
            aOrbiterG = RotL64((aOrbiterG * 12814077238529863119U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 11U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 26U) + RotL64(aOrbiterG, 27U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 309U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7541U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4070U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 496U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 47U)) + (RotL64(aIngress, 35U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererD + RotL64(aIngress, 41U)) + 3339283916456813609U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 52U)) + 11339086426180649584U) + aPhaseHOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 16819191669329316585U;
            aOrbiterF = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 8361916937762630725U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 18031328374429899857U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 18261756894092897276U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4250319792907645666U;
            aOrbiterA = RotL64((aOrbiterA * 7053489184750217963U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1492411503643460886U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17369549067879344180U;
            aOrbiterG = RotL64((aOrbiterG * 2947354306696216579U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7301713524358676722U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 2985193736033012535U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7473297294949338265U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 14086975808140927408U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10390516547834639800U;
            aOrbiterD = RotL64((aOrbiterD * 11441293212275890819U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 18205555540941493267U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16967799565443938873U;
            aOrbiterB = RotL64((aOrbiterB * 3009081009044782443U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 18U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 26U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + aPhaseHWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 12U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 10128U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8274U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15453U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 9555U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 12690502671561165478U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 21U)) + 17519943923428102801U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 47U)) + 10705515807975331385U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 16586447272278538179U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 30U)) + RotL64(aCarry, 41U)) + 8006560996840971798U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12928600185788857701U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14240723153798267172U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7446040187505339853U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 8636219177994872072U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7586790235186467512U;
            aOrbiterH = RotL64((aOrbiterH * 15052686382507614169U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1103807034179512424U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7547526530239498693U;
            aOrbiterE = RotL64((aOrbiterE * 3360295583636013509U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8380239679344786397U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5690809173787433519U;
            aOrbiterB = RotL64((aOrbiterB * 5354724308093372953U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8390902801141804609U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3507306189192059486U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18336280496510253103U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 13U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 60U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aScatter, 52U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 21972U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((aIndex + 20204U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20353U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17055U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 43U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 16200278595895089008U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 54U)) + 1029614154810465897U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 41U)) + 7129562468705441295U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 14388903902433951274U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 1013568949315967455U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3128823373497815651U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 14525694606889470589U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12053226114431679195U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14443983602196782887U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12244220415328641190U;
            aOrbiterE = RotL64((aOrbiterE * 15052949098014803181U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10477159225338766614U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2842870123078131566U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11522265477555954071U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8621138818955849917U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5038396344400303181U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14636756322207385447U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 2768613802894372496U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2027754864051410015U;
            aOrbiterI = RotL64((aOrbiterI * 2461322540050569287U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterA, 51U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 14U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterF, 23U)) + aOrbiterE) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 5U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 29184U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26800U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31786U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32399U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 58U)) + 12980104182836602177U) + aPhaseHOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 23U)) + 3172622203188863995U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 1170974132219980203U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 6035201940965047490U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 13U)) + 18033907118424996722U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14604813424800580304U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13720232492851066035U;
            aOrbiterG = RotL64((aOrbiterG * 8927246214721284759U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3902659710585257448U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8331560652661619868U;
            aOrbiterJ = RotL64((aOrbiterJ * 11418103770615560205U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4485014147538689794U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 168202636924512424U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13711020666131492091U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16227825670092707848U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4792781933944671365U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15859849676231455283U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12636865372722601282U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 18198291399585556632U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18155803890313399795U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 46U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterI, 29U));
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 57U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterG, 41U)) + aPhaseHWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 40U) + aOrbiterJ) + RotL64(aOrbiterE, 10U)) + aPhaseHWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
