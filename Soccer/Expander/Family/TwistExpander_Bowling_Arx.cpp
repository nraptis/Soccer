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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD5E77FE47243CB01ULL + 0xD7521A8B5BD5A1D7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x828628895B63FBA5ULL + 0xC491455FB69FB59DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xACA752B851DACD21ULL + 0x899BFDBE5881FFE1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9214B2FF375645B3ULL + 0xAF98412EA3702DD9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC4A9053733C0C67BULL + 0xA94EB0586D66748CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x94C69D0893F3741DULL + 0x97702DD80B836040ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x84D5224F04D504B3ULL + 0xE93AF27384F7D797ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB1D1D0CA45199775ULL + 0x8D58B480B04F01E8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC5696A41570F5A7DULL + 0xA778F7A1951A8E8CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC63FA66764A37F5BULL + 0xB0BA6D85C52BE1F7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB4935A120AEF5C6DULL + 0xB637D8F784381701ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC7E6D8C5415642BDULL + 0xE1ECB545C9EFA308ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB3D0DA255EBE51B7ULL + 0xE070175FDAC7D38BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD466DDE537B5F397ULL + 0xD5420567733FF320ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD873871A69DC8863ULL + 0x9CE874431BC6DA24ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBF4839987900E5F9ULL + 0xD554EBD11298CCD4ULL);
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
            aIngress = RotL64(mSource[((aIndex + 3582U)) & S_BLOCK1], 47U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 4452U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 855U)) & S_BLOCK1], 22U) ^ RotL64(mSource[((aIndex + 3078U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 42U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 23U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = (aWandererB + RotL64(aScatter, 51U)) + 5041131702736607991U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 3U)) + 9295010428212681446U;
            aOrbiterC = (aWandererA + RotL64(aCross, 43U)) + 6235875895358766017U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 2622227802531866918U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 48U)) + RotL64(aCarry, 11U)) + 3888894734834524972U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aCross, 21U)) + 241682012014701753U) + aNonceWordF;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 23U)) + 15758000422451568079U) + aNonceWordO;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 47U)) + 2061944548396976912U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 37U)) + 8177144990755754531U) + aNonceWordG;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 41U)) + 554978075608818497U) + aNonceWordI;
            aOrbiterD = (aWandererK + RotL64(aScatter, 34U)) + 250408260560714933U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8700027645880997552U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10026130047465480902U;
            aOrbiterC = RotL64((aOrbiterC * 12417270861933696623U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9785843014096326696U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9998582683258411251U;
            aOrbiterF = RotL64((aOrbiterF * 7197956237569462269U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13817734599383455151U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6647207154174092691U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1578528131687283531U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4957715980509035719U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4994885315786213197U;
            aOrbiterE = RotL64((aOrbiterE * 5676683798126497011U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5072908311783966503U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5535039946192891515U;
            aOrbiterI = RotL64((aOrbiterI * 2989412783482309753U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 6594577050344146271U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8750154123258714856U;
            aOrbiterK = RotL64((aOrbiterK * 6942158167127532003U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3514769314840874873U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8626045200273524281U;
            aOrbiterJ = RotL64((aOrbiterJ * 4315441782689789689U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8524870284841706517U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1841819423572964209U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9802481758007234681U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12668382464510772517U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6330331402801670515U;
            aOrbiterB = RotL64((aOrbiterB * 9096920618612750935U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10346986196055766087U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10932918162471200996U;
            aOrbiterH = RotL64((aOrbiterH * 6863632877625141567U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6264557195446069146U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5041131702736607991U;
            aOrbiterD = RotL64((aOrbiterD * 4978591546106895045U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 46U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterE, 34U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 53U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 39U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 13U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 36U) + aOrbiterG) + RotL64(aOrbiterD, 27U));
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterG, 51U)) + aOrbiterA) + aNonceWordE) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG + ((((RotL64(aCross, 40U) + RotL64(aOrbiterI, 12U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 18U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 9478U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5785U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5834U)) & S_BLOCK1], 56U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 9112U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = (aWandererD + RotL64(aPrevious, 27U)) + 1142447269198373880U;
            aOrbiterH = (aWandererE + RotL64(aCross, 23U)) + 10581460640040336191U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 57U)) + 14703062773878202900U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 15737525756286914746U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 16178774478273186999U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 34U)) + 2514897053906809160U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 53U)) + 13702496607592508464U) + aNonceWordM;
            aOrbiterI = (aWandererA + RotL64(aScatter, 43U)) + 18030885275418337965U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 5U)) + 5241783876161655984U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 2807052676283587925U) + aNonceWordL;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 18U)) + 8022804576763271327U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15597099852232205860U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1538435607932096400U;
            aOrbiterJ = RotL64((aOrbiterJ * 7900752511710516981U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11147868774413615365U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 9325213746830411568U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 561819005818948769U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13792300423550555634U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3134856508983945719U;
            aOrbiterH = RotL64((aOrbiterH * 4271845067763664863U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8654966018053784882U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8937113935476779267U;
            aOrbiterK = RotL64((aOrbiterK * 7386875687217705855U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4135676350355234788U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11407912615743682678U;
            aOrbiterB = RotL64((aOrbiterB * 2773506587480714695U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10966950663872392059U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6686634993700944582U;
            aOrbiterD = RotL64((aOrbiterD * 2509459942163678241U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14154407529749257990U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 18054640398549782388U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7830759861389060149U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14623473030642960240U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1857945571104460086U;
            aOrbiterF = RotL64((aOrbiterF * 18039903315045620079U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17650774450811065797U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9458168381246672881U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3452665113988737563U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16604923466236483242U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12447748535184711684U;
            aOrbiterG = RotL64((aOrbiterG * 5982708155382249061U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9589720286549780720U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1142447269198373880U;
            aOrbiterI = RotL64((aOrbiterI * 8176719948031280789U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterK, 53U)) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 30U)) + aOrbiterH) + aNonceWordB);
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 43U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 19U)) + aOrbiterF) + aNonceWordC);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aIngress, 14U) + aOrbiterK) + RotL64(aOrbiterH, 5U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterI, 37U));
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterG, 48U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 11808U)) & S_BLOCK1], 58U) ^ RotL64(mSource[((aIndex + 13829U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 15259U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((aIndex + 15080U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = ((aWandererB + RotL64(aIngress, 26U)) + 12980104182836602177U) + aNonceWordC;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 3172622203188863995U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 1170974132219980203U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 11U)) + 6035201940965047490U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aIngress, 37U)) + 18033907118424996722U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 29U)) + 14604813424800580304U) + aNonceWordO;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 23U)) + 13720232492851066035U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 3902659710585257448U) + aNonceWordE;
            aOrbiterB = (aWandererA + RotL64(aScatter, 19U)) + 8331560652661619868U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 21U)) + 4485014147538689794U) + aNonceWordK;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 52U)) + 168202636924512424U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16227825670092707848U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4792781933944671365U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 15859849676231455283U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12636865372722601282U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 18198291399585556632U;
            aOrbiterJ = RotL64((aOrbiterJ * 18155803890313399795U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3650053185419807206U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5897288963905408776U;
            aOrbiterD = RotL64((aOrbiterD * 3706949366974086151U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9922308113622901726U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13352279749091561510U;
            aOrbiterE = RotL64((aOrbiterE * 4025213180483632557U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 14969461950939646117U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10231661776135056651U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11284575051455238501U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10621934544068320859U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6029116920305246887U;
            aOrbiterB = RotL64((aOrbiterB * 6087523725059376905U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12887482425168671195U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 8351351557123783853U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 3839381627914762245U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5405938210926464973U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 385145802287899406U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 8330751480464271445U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7907749190875916461U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5138733192253468642U;
            aOrbiterI = RotL64((aOrbiterI * 17028325976353263843U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 14382272868178763187U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14354777100157531233U;
            aOrbiterF = RotL64((aOrbiterF * 7095764230272037767U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4390647647193363824U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12980104182836602177U;
            aOrbiterH = RotL64((aOrbiterH * 11124472075872147333U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 58U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 24U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 41U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 5U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterF, 21U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 37U));
            aWandererH = aWandererH + ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 47U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 19U)) + aOrbiterI) + aNonceWordH);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 28U) + RotL64(aOrbiterJ, 44U)) + aOrbiterC) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 13U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 57U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 44U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 18259U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 18027U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 16639U)) & S_BLOCK1], 18U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 17399U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21264U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 4U)) + (RotL64(aCarry, 35U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 2672739400294801233U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aScatter, 39U)) + 8475624545015101850U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 14U)) + 1252755112289831257U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 29U)) + 7938039507649183387U) + aNonceWordL;
            aOrbiterC = (aWandererH + RotL64(aIngress, 57U)) + 8167413146948861022U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 41U)) + 17712313989694374353U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 7637042279892596975U) + aNonceWordE;
            aOrbiterH = (aWandererE + RotL64(aCross, 10U)) + 15770412950033467341U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 3951812021898608685U;
            aOrbiterE = (aWandererC + RotL64(aCross, 19U)) + 8656983621098246507U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 27U)) + 17943342344730687317U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3087677463651608668U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16493240011924342788U;
            aOrbiterI = RotL64((aOrbiterI * 16898479041530771871U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7750923317452683057U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2185924841611106546U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 708072658250726381U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14676868738946722416U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6849098251696302393U;
            aOrbiterC = RotL64((aOrbiterC * 2599806275837778069U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 17817755047153606419U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9900465270314068757U;
            aOrbiterF = RotL64((aOrbiterF * 9267925873983176685U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11380000891112113701U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15930503831156546113U;
            aOrbiterG = RotL64((aOrbiterG * 14450535035065393845U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5439183530402949780U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3731802052051181843U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7739775058947333169U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14432344583247783600U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16192098795467501636U;
            aOrbiterB = RotL64((aOrbiterB * 6285466374319549047U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1523272672673940290U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7462092373525113574U;
            aOrbiterE = RotL64((aOrbiterE * 15067751170235540679U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4612539457663050732U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7959404391235752875U;
            aOrbiterK = RotL64((aOrbiterK * 137834571274065007U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11853468935131763944U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3575434598998149168U;
            aOrbiterH = RotL64((aOrbiterH * 16971321675425065041U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6135993440654291404U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2672739400294801233U;
            aOrbiterA = RotL64((aOrbiterA * 12891757276825641567U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 42U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterE, 57U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 41U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterA, 39U));
            aWandererA = aWandererA + ((((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterH, 37U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 14U)) + aOrbiterE) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            aWandererH = aWandererH + ((RotL64(aScatter, 20U) + RotL64(aOrbiterA, 53U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 30U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 26832U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 23787U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(pSnow[((aIndex + 26771U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 24493U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26075U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23427U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCarry, 18U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 3684295017013759987U;
            aOrbiterE = (aWandererC + RotL64(aCross, 51U)) + 6740408842457292881U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 36U)) + 4563975890702399441U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 13U)) + 797804144825287940U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 21U)) + 2763779540450101303U;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 19U)) + 13211846164102089685U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 15214578447281401982U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 13745208628754232427U) + aNonceWordE;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 6U)) + 17358621225969190747U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 47U)) + 779739369960480023U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 29U)) + 4370963533701407813U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6061333005507739975U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3589705340762734456U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16499293983611196967U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 10607697666369230567U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9356757995305239271U;
            aOrbiterI = RotL64((aOrbiterI * 10945513661439954731U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10093033335903048138U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 11037328061699834100U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 11189760551792389605U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 558431161176115540U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17795680919453449358U;
            aOrbiterH = RotL64((aOrbiterH * 3910117359996283803U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6096779391116214109U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 17594243286880690775U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 12655610181937429915U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15414704802398002423U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 18040588240488602196U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16344249573086571225U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14636298592697156931U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 9677305688594936561U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8354776999961642997U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16408025751875050713U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10018342878801454965U;
            aOrbiterJ = RotL64((aOrbiterJ * 10349132962708124117U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1841090936357114866U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16142637455878447020U;
            aOrbiterA = RotL64((aOrbiterA * 10565394571714418033U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4089676582910615502U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8749600984499831109U;
            aOrbiterF = RotL64((aOrbiterF * 3421055105090316521U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11408932421005107097U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3684295017013759987U;
            aOrbiterC = RotL64((aOrbiterC * 7037953759624065417U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 56U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterK, 37U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterK, 19U));
            aWandererG = aWandererG + ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 56U)) + aOrbiterE) + aNonceWordJ);
            aWandererH = aWandererH + (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 54U) + aOrbiterB) + RotL64(aOrbiterE, 43U)) + aNonceWordF);
            aWandererB = aWandererB + ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 23U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + aNonceWordP);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterH, 52U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 31387U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((aIndex + 31119U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27977U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31427U)) & S_BLOCK1], 30U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32070U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32230U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 41U)) + (RotL64(aCross, 54U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 3U)) + 13053031069776604052U) + aNonceWordA;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 21U)) + 1331396630251085122U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 15879286043343942393U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 13590365633321406830U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 24U)) + 14569235423040242618U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 41U)) + 11397370636618371560U;
            aOrbiterG = (aWandererC + RotL64(aCross, 51U)) + 3455933494593971847U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 1307153376443784593U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 35U)) + 10688618762584786871U) + aNonceWordK;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 6U)) + 17746248451153600096U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 53U)) + 8512568600755410158U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8950230550112591092U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17790968369472845496U;
            aOrbiterK = RotL64((aOrbiterK * 5104988920132008913U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12583323865381967534U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11243927099685293887U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12867003042486433971U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9690268715525781389U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7466066217365074653U;
            aOrbiterA = RotL64((aOrbiterA * 17565696765505320889U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3673528673209875118U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14079103852360952255U;
            aOrbiterC = RotL64((aOrbiterC * 17449228863409999629U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6747836856132250630U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 5027692924422297153U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2492421273167124437U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11370341866003395776U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14013204893442579282U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6602239957997240785U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3436953430697936790U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6399073534839993637U;
            aOrbiterG = RotL64((aOrbiterG * 14186050072610021241U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 7054057507823631422U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5752085719673338095U;
            aOrbiterF = RotL64((aOrbiterF * 13252660162476029593U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10628323020010327594U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5029617362660411790U;
            aOrbiterD = RotL64((aOrbiterD * 7230663968894173433U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6816547880074551571U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6683840259024813282U;
            aOrbiterH = RotL64((aOrbiterH * 13145224557159574541U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5952768353050729617U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13053031069776604052U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13710064584055068065U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 22U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 58U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + aNonceWordC);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 35U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 50U)) + aNonceWordM) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 37U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterD, 47U));
            aWandererE = aWandererE + ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 6U) + aOrbiterC) + RotL64(aOrbiterF, 26U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 41U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 43U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aCross, 51U) + RotL64(aOrbiterE, 35U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterA, 13U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB6060E9C6D2CDFEBULL + 0xE70F1F28EF324072ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC99378521197C991ULL + 0x979D0BABF99B69F0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCD6DE42FF88CDA23ULL + 0xA46333732CA6D573ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD48791728B57E32FULL + 0xB409BAEDBD90EC30ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCCBEFB8AB24D6989ULL + 0x8D147F010DABC8E3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9FED985ADBF6BF03ULL + 0xA17778E5FA58C3F9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC1BD5067483AD623ULL + 0xA4E7C1244B2E49DEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC7BB601D624B797FULL + 0xCF41938764C82E29ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC10F0D644922183FULL + 0xBCC55641737C1E4FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9CCCD4EB818B74ADULL + 0xDDDC0BF42679D678ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8A29CCFE688B53E9ULL + 0xB3367043F37B9ACCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x963F146B383421C3ULL + 0xA2D5E563F795E5FFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDB1EB2394211FE79ULL + 0xEE1B21BF9B7D4A00ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFBEB79236889AEEFULL + 0xDF94AE04BB7F2B15ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xAEA5DAD0283F327FULL + 0xF4CC2D6A5221345BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xADC0CF5A54E3B81DULL + 0xC23720EF8E7DBAF7ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 3301U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4617U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4194U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5974U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 24U)) + 3339283916456813609U) + aNonceWordD;
            aOrbiterA = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 11339086426180649584U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 43U)) + 16819191669329316585U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 47U)) + 8361916937762630725U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 19U)) + 18031328374429899857U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 18261756894092897276U) + aNonceWordH;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 47U)) + 4250319792907645666U) + aNonceWordM;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 13U)) + 1492411503643460886U) + aNonceWordF;
            aOrbiterG = (aWandererF + RotL64(aCross, 5U)) + 17369549067879344180U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7301713524358676722U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 2985193736033012535U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 7473297294949338265U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14086975808140927408U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 10390516547834639800U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11441293212275890819U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 18205555540941493267U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16967799565443938873U;
            aOrbiterK = RotL64((aOrbiterK * 3009081009044782443U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9209505304067579944U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3522631966146762306U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 3441982898533162599U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8811497120829041188U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14707301680850257294U;
            aOrbiterA = RotL64((aOrbiterA * 11383709499376464085U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10080595991787801029U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6822892187784299166U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7417016898027778287U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1981637172055758689U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16463077485583119324U;
            aOrbiterF = RotL64((aOrbiterF * 2876782050665869121U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8383837717361569465U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2788511294985017326U;
            aOrbiterC = RotL64((aOrbiterC * 2809163242875130677U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3529607472855930041U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8850940802020173766U;
            aOrbiterB = RotL64((aOrbiterB * 7821450253655655943U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 53U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterE, 58U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 19U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterJ, 5U)) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 12U) + aOrbiterI) + RotL64(aOrbiterK, 29U)) + aNonceWordE) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 39U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 14U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 26U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 14564U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneB[((aIndex + 14203U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 10561U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15775U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13161U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 58U)) ^ (RotL64(aCross, 11U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 13296600294247799698U) + aNonceWordI;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 11U)) + 5818503518080877515U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 42U)) + 6735784238734173597U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 27U)) + 7368398209488856201U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 19U)) + 961734029066455638U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 797011946660892011U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 46U)) + 12841876018396622350U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 16213253970483895623U) + aNonceWordG;
            aOrbiterI = (aWandererF + RotL64(aCross, 57U)) + 15186950557113470375U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5117930310827477341U) + aNonceWordP;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 12265429373166094162U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 1522823535151532249U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13920531346698601568U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14695405206998211456U;
            aOrbiterJ = RotL64((aOrbiterJ * 13950964363414164279U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7851960904825938443U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9501511171732550190U;
            aOrbiterB = RotL64((aOrbiterB * 5614164120361489613U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 5663365182245722077U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9607860124321315555U;
            aOrbiterE = RotL64((aOrbiterE * 3461820361914280601U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18171052650586819280U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3442698321538580861U;
            aOrbiterD = RotL64((aOrbiterD * 6317525514963824829U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 1491052813469258970U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3956599824067616133U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2928600779267623085U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10963841237346073453U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2303020125591252534U;
            aOrbiterI = RotL64((aOrbiterI * 9969099842343321981U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14503856057958162356U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11147548150090597694U;
            aOrbiterA = RotL64((aOrbiterA * 11856382308792700441U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9191681438318311481U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13556072770381999852U;
            aOrbiterK = RotL64((aOrbiterK * 18316231099054203683U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 51U)) + aOrbiterD) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterH, 22U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterH, 57U)) + aNonceWordN);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 34U) + aOrbiterK) + RotL64(aOrbiterB, 41U));
            aWandererD = aWandererD + ((((RotL64(aCross, 57U) + RotL64(aOrbiterK, 37U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 10U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererK, 44U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18824U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((aIndex + 24531U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21654U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18664U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 23043U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 18080U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = ((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 13U)) + 4773124477323378268U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 53U)) + 16848723289435796005U) + aNonceWordP;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 41U)) + 13846642134917107058U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 37U)) + 6472057872482789939U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 2747019500690707226U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 5U)) + 9003965289739733880U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 3013390651936257377U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 28U)) + 3331004709895625067U) + aNonceWordE;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 11U)) + 15355010435553517129U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7709870658004280052U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13568728443963926564U;
            aOrbiterD = RotL64((aOrbiterD * 6736090830113688981U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12409548853419307131U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 969183352023661537U;
            aOrbiterI = RotL64((aOrbiterI * 5549220554838837145U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15370309834426476775U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3896803894396631184U;
            aOrbiterF = RotL64((aOrbiterF * 11018830202891911603U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10848873633291935766U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12885336509190543440U;
            aOrbiterC = RotL64((aOrbiterC * 1487357252619221365U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 8252290890093788010U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9201553615601641350U;
            aOrbiterB = RotL64((aOrbiterB * 420321130559162915U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14014209645503188472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4015071464301844550U;
            aOrbiterG = RotL64((aOrbiterG * 17444195018239904971U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16173085647514027347U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 16916627014974363360U) ^ aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 7699587344277490953U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1591680303404522110U) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16499606051269327916U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 814405848002794813U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6932673635509444619U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8745681160108707944U;
            aOrbiterA = RotL64((aOrbiterA * 14565255558668084787U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterG, 23U)) + aNonceWordN) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 12U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterC, 57U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 35U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterA, 27U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 44U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterF, 52U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 24880U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 28645U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 31349U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27060U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30415U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 28126U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 35U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (((aWandererJ + RotL64(aCross, 18U)) + RotL64(aCarry, 5U)) + 77518479758428414U) + aNonceWordC;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 4832061802166300011U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aIngress, 51U)) + 11695291171006574112U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 11U)) + 7467412817843260094U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 5U)) + 17801484124471154757U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 47U)) + 5555455638503958639U) + aOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 5669470540733721606U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 42U)) + 3042388456327784163U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 35U)) + 2236734925228156691U) + aNonceWordP;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 14459720401528685450U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4814967631216658856U;
            aOrbiterH = RotL64((aOrbiterH * 18288097536171386643U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 16950679344449075945U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6262238639302011050U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 9942659897425088183U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3522256359074996724U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12524717897707074242U;
            aOrbiterF = RotL64((aOrbiterF * 6787771338063891989U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13891759914865623828U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11910250571469028666U;
            aOrbiterC = RotL64((aOrbiterC * 12311343917878428995U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2240189915640314069U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 5365912986308810837U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 15133972552032469957U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9323732721344489753U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13087326560957916553U;
            aOrbiterI = RotL64((aOrbiterI * 14659491687401151733U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16398238057564892809U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11517870519285159224U;
            aOrbiterG = RotL64((aOrbiterG * 1501848878469712681U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7758285512254776734U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17475149091906684720U;
            aOrbiterD = RotL64((aOrbiterD * 6015816725428299273U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2051631493975035243U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 11684740065349595315U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 10918975496337269197U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 30U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 18U)) + aOrbiterJ) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 10U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterE, 27U));
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterE, 12U));
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 30U) + aOrbiterI) + RotL64(aOrbiterJ, 51U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF58CBF88B56336C5ULL + 0xE0EB4B8BAD8C94DBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD2FB812C0A184B3BULL + 0x8239544B964D0FEEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB4F041B8534816F5ULL + 0xC11C1BFC1CBA8C4CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB9D6E8E3F6D05009ULL + 0xFA2E78BA93F505DDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9D5A72F0DCC480F3ULL + 0xEF5224CD4C480CD1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC6808F8243A4F01FULL + 0xEFB7F58D4AA2318DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x97CCEB4B1A9C9D1FULL + 0xB43EE8F6258F3810ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE16C70B999307CC1ULL + 0xECE262B400BC5962ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEF330E26B99BD29FULL + 0xBBA2347DC8F0DA30ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x83B40D6B463A1191ULL + 0xF276D2E5D17B0246ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC90C07F269D5F2CDULL + 0x85C91AFB0C45775AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA1D4A79ABB902DD5ULL + 0xB330B4B8A4BDD49FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFE8CC609A69E48ABULL + 0xB4FDB0D0AD087E4FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAC957BC39CBC1C4BULL + 0xA670B4D13A4229B6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF3D78F4EED39163FULL + 0xBA10C4FA99FB86D4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFFDCF317C69A3005ULL + 0xAA3632A2A77B8B2CULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneB, aWorkLaneB, aFireLaneD, aWorkLaneC, aFireLaneA
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 631U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 7756U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 122U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4976U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 5996U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 27U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 34U)) + RotL64(aCarry, 3U)) + 2558105147674438050U) + aNonceWordD;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 53U)) + 15856662514774702561U) + aNonceWordP;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 13346869226246584582U) + aNonceWordN;
            aOrbiterJ = ((((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 7632111846116243973U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 3U)) + 2102101361626976279U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 5605968705067851563U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6842483186584326681U;
            aOrbiterB = RotL64((aOrbiterB * 11344798544990575365U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5559797213819425064U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12422313931331576759U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7399849122565913401U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2751024420047872601U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 11031320239359798610U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 8607639453141148025U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14366375309473793217U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11971479429768505316U;
            aOrbiterC = RotL64((aOrbiterC * 10063001532313098203U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3947595951884469542U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 17882767922372770896U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 3361906348965810211U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 14U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterD, 13U)) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterC, 57U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 46U)) + aNonceWordC);
            aWandererC = aWandererC + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 21U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14290U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 12111U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13564U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8941U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8931U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 8535U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 35U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 9751314027302668907U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 19U)) + 12175450995523107056U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 47U)) + 17519694958730119552U) + aNonceWordE;
            aOrbiterI = ((((aWandererA + RotL64(aCross, 30U)) + RotL64(aCarry, 53U)) + 9093525527925682263U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 3713831321786810138U) + aNonceWordP;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10108355209191835040U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12956307447311314768U;
            aOrbiterA = RotL64((aOrbiterA * 9198936928658626667U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1904298513945877359U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4658049993308574460U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10482422152074338611U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9826333658248851902U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12058666914724365134U;
            aOrbiterD = RotL64((aOrbiterD * 964233873188373939U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2516574707110528099U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13335308331049750235U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 5880227828760598587U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8230749255538495304U) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16536559486797811486U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7097036838156464969U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 58U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 11U)) + aNonceWordI);
            aWandererI = aWandererI + (((RotL64(aScatter, 52U) + RotL64(aOrbiterA, 60U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterD, 51U)) + aNonceWordG) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneD
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22330U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 22110U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 22501U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24385U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18008U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23248U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 60U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 15316464782468770057U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 5U)) + 6642872057476351588U) + aNonceWordG;
            aOrbiterG = (((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 660732654689529192U) + aNonceWordP;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 60U)) + RotL64(aCarry, 51U)) + 7235418086884000655U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 13U)) + 14784518476694580493U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12222433977933449375U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 8573001207708329927U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17771120145431297541U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16035256260815013172U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 15767726974121910203U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 719060452537759331U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17712217935322939971U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13488963456923357159U;
            aOrbiterJ = RotL64((aOrbiterJ * 16785285630840310405U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10222949131965611079U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 1495561412321657209U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 9706305581868526265U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16156530750584361434U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7773792489045606309U;
            aOrbiterF = RotL64((aOrbiterF * 10730624207715601393U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 38U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 46U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterC, 11U)) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 56U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ) + aNonceWordJ);
            aWandererG = aWandererG + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 37U)) + aOrbiterH) + aNonceWordN) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 26U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32151U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 27187U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 30057U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26012U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28833U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29654U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25056U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 2330952702412094686U;
            aOrbiterK = ((((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 7820188225935060799U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 52U)) + RotL64(aCarry, 35U)) + 9347644591709839145U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 21U)) + 2288624878446846870U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 29U)) + 9358977729492824128U) + aNonceWordG;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1858511275052455039U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13715478509322292552U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 15552121744869003235U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16413396625604260455U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 17714322215518432705U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1904184102419934333U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16188315436202861122U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5564445841368207813U;
            aOrbiterI = RotL64((aOrbiterI * 14125834616162835983U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13717068949900594673U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14143659432287313765U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 17281441046722262917U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5729546141908425670U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 4297827922736712074U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 13631630436759768885U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterI, 37U));
            aWandererG = aWandererG + (((((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 11U)) + aNonceWordI) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterG, 11U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterH, 48U)) + RotL64(aCarry, 51U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + aNonceWordP) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 3U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x82458FEB5848E903ULL + 0x907D0AA53CF3DA74ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9E4682FEB9375A4DULL + 0x8AA92DC2D7CC265DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF9031F073B9A54A3ULL + 0xC9047988EEAA376DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD4D685CDB4C9198FULL + 0xE8A0020538F6EE19ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB1BEB1830243B699ULL + 0xBEEBB009C805DB45ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB84F4932E2EAB8B1ULL + 0xEC37B19E6A313860ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF263A10BFC0AEB6FULL + 0xB66ADAF39653F2A3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xAC053E526A34CBFBULL + 0xA97E2DE80AC21527ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC50C3B46BCB3F565ULL + 0xA7B2C14CEDEA41E5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8E9E79FAC361194BULL + 0xAC1774F71FE9C3C5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFA12E6BBD0039C09ULL + 0xFA5B785F42ECB74CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x979414CF477DA413ULL + 0xBF23D638B83E735DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x91BF5C5CB38D7CBDULL + 0xC555525B7735D13EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBDCDAF5ABEAEC5A5ULL + 0xAC0D0B54D83AD329ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA06256564193DBE7ULL + 0x83C30C8ABF427E40ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE4B3BC33666F727FULL + 0xEA5DED80A4EEFB5FULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aOperationLaneA, aWorkLaneA, aOperationLaneD, aFireLaneA, aWorkLaneB, aFireLaneB, aOperationLaneB, aWorkLaneC, aOperationLaneC, aFireLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 931U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 7752U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5019U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2685U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3041U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4171U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = ((((aWandererI + RotL64(aIngress, 18U)) + RotL64(aCarry, 13U)) + 7825479804710770560U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 5298124167101358123U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 17774541024369233726U) + aNonceWordH;
            aOrbiterI = (aWandererA + RotL64(aScatter, 51U)) + 7679371833537454082U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 5U)) + 5385914900748772224U) + aNonceWordL;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 11U)) + 3879781930908486531U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aCross, 29U)) + 659110346638873236U) + aNonceWordP;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 10749021728538539749U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3631252455767429457U;
            aOrbiterJ = RotL64((aOrbiterJ * 8552825360915119613U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2271978810960685021U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 5963558780692551176U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 4772055335210781149U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 974909966119198104U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9296998242911152296U;
            aOrbiterI = RotL64((aOrbiterI * 2613629915877957661U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2245318466901521959U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13391076374843288568U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18094558036982107419U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6184487746594236737U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1563385912137291418U;
            aOrbiterB = RotL64((aOrbiterB * 4805455299959232321U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 1744840092006498629U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2100927276837188416U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 3541788262067077997U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9998911862807246338U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12239948725635220096U;
            aOrbiterK = RotL64((aOrbiterK * 7098620484129489129U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterD, 58U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterB, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + aNonceWordD) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 29U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14192U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((aIndex + 13503U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11344U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12022U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14438U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 8645U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 15383045568644941552U) + aNonceWordL;
            aOrbiterD = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 17452811657750910067U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 15660117718455155603U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 37U)) + 10396441207743665753U) + aNonceWordM;
            aOrbiterK = (aWandererC + RotL64(aIngress, 3U)) + 3708971058200841442U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 60U)) + 7000673057768598750U) + aNonceWordH;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 19U)) + 9886354469011131596U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 16018065329058043467U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5024756166109352320U;
            aOrbiterH = RotL64((aOrbiterH * 11660932185479046483U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6587818720728886652U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3652672354944162319U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10807121230791716109U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6307315649915348048U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16405347331742979258U;
            aOrbiterC = RotL64((aOrbiterC * 7183142442906743699U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5427299664054601957U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 4983381733483185898U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 14646556236306407673U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10182995521328377487U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8694282877540593550U;
            aOrbiterB = RotL64((aOrbiterB * 14614602561910403893U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4085927978153269932U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6176195962815240877U;
            aOrbiterJ = RotL64((aOrbiterJ * 16792916528959579875U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 6966742100601433005U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9920952446921247521U;
            aOrbiterK = RotL64((aOrbiterK * 1879821050131820933U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterD, 12U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterH, 43U)) + aNonceWordJ);
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 53U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 27U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD) + aNonceWordC) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneB
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22546U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 19870U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21937U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22101U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21139U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22029U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 54U)) + RotL64(aCarry, 21U)) + 7632760812370906911U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 13U)) + 6007174525479723089U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 5U)) + 3362829642521821048U) + aNonceWordE;
            aOrbiterB = ((((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 18009548556107978286U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (aWandererI + RotL64(aIngress, 41U)) + 17880909432272697327U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 15961567935420752568U;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 27U)) + 10136559064656837921U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17622019364405410277U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6927494824421416306U;
            aOrbiterI = RotL64((aOrbiterI * 2686290883767829973U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7125170407794874847U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 12342273503071032250U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 867417849555857179U), 19U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 14997696377476124836U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14874498694181230698U;
            aOrbiterB = RotL64((aOrbiterB * 4026127545746010937U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2549397729130885686U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4217995818662767955U;
            aOrbiterE = RotL64((aOrbiterE * 5525525344485251063U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4706089044415442525U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 17983900172670031015U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 541552737180932879U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1904937798143929988U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10620877287033139483U;
            aOrbiterH = RotL64((aOrbiterH * 16711012562024287213U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15681091173163181525U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2655543246639000084U;
            aOrbiterJ = RotL64((aOrbiterJ * 16686375598149755947U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 37U) + RotL64(aOrbiterI, 60U)) + aOrbiterB) + aNonceWordG) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 35U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + aNonceWordC);
            aWandererA = aWandererA + ((((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 35U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneC
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32509U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 31498U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27659U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32517U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27507U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 26511U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 964165145848253292U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 54U)) + RotL64(aCarry, 3U)) + 10645976767204934746U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 37U)) + 8241612229349212650U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 4159196033256913347U) + aNonceWordO;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 3U)) + 7194795864620233507U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aScatter, 19U)) + 7638928444536778384U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 47U)) + 11819105916503968109U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 18052213302858186237U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8663575313970041570U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14131073322476609161U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16644136720439299786U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 16930316530442679864U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 2650922074098320859U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 16251107616988250593U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 7171986193609401665U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 3543709971414550087U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17885046834432626644U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7757069274715713557U;
            aOrbiterA = RotL64((aOrbiterA * 15766885299397923879U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 2212805322061155615U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6368539134638838822U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13383744883433594259U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5264326094252925613U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6126345334815012938U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 17180934809764905307U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13826731214018407061U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6621261811613643620U;
            aOrbiterB = RotL64((aOrbiterB * 2823596473596114171U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + aNonceWordA);
            aWandererE = aWandererE + ((((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 39U)) + aOrbiterE) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 40U) + aOrbiterD) + RotL64(aOrbiterJ, 56U)) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + aNonceWordG);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE9558F510F6F174FULL + 0xE1B3EA55D22F3A21ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAAC7C1CBFDCEE3EBULL + 0xA77C4B61529E91B5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF76EAC04501BF101ULL + 0x8244FFF82FBAD610ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9F0DF34E799A76A3ULL + 0xD46515CBDBCA17CCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF57025B502D36165ULL + 0xB822B92D09807530ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB254BE14F6C7683BULL + 0xB87A44E0F5B87B53ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x95A5F564C1C1CBBBULL + 0xACD56379824A2BF9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF1B0F2857F7B6697ULL + 0xF31F64395988A105ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB66DB2401B00D747ULL + 0xAF719B870DEF9C51ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA18FB3307F4482E7ULL + 0xD1B7CCB92219A5FBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA01997002775AE3DULL + 0xF4D9209C47AEFEC0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8BCEC528ABD98D13ULL + 0xC24E6C728C9734D8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xEA9BC3CF44C77B09ULL + 0xA6772C864C9136FDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x94E9567F927A7BBFULL + 0xDCE535800CBC122CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x86B347F87B68FEBFULL + 0xE97F034A364EEA90ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC52E5606436AC17BULL + 0xF261886F7C271BFBULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneD, aWorkLaneC, aWorkLaneD, aFireLaneA, aExpandLaneA, aFireLaneB, aOperationLaneB, aExpandLaneB, aOperationLaneC, aOperationLaneA, aExpandLaneC, aFireLaneC, aFireLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 869U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 4802U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 6702U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7656U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 158U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 2164U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 37U)) + (RotL64(aPrevious, 51U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 18087125778766689269U) + aNonceWordF;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 53U)) + 13710545066503235196U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 1701939704736254645U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 35U)) + 8064093611384019909U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 13U)) + 16623332751533885431U;
            aOrbiterI = (aWandererE + RotL64(aCross, 43U)) + 15590129153794910109U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 4U)) + 7413312683079107383U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4186064478651458810U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5501191643940735954U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14254804649177125269U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11064645242200570835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13825922087298055833U;
            aOrbiterD = RotL64((aOrbiterD * 7529317892716108867U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5944980709887369970U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8181136916070569646U;
            aOrbiterE = RotL64((aOrbiterE * 395183021205661827U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15442336949157292482U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 11580554435240641337U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 6654637892858767739U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11240018128174598322U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2027565596050777471U;
            aOrbiterH = RotL64((aOrbiterH * 18048186560314431815U), 11U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 16425887196883725233U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16828683527588834095U;
            aOrbiterF = RotL64((aOrbiterF * 17746289103235902485U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 9923829146479008804U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6669171007279929454U;
            aOrbiterA = RotL64((aOrbiterA * 681823450939955099U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 50U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 26U)) + aOrbiterB) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 57U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 35U)) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 18U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 42U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10432U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((aIndex + 12306U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 10905U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16044U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16257U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 11686U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 2974056819475622600U) + aOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = ((((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 7345051759236356098U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aWandererA + RotL64(aIngress, 29U)) + 12738468816846628882U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 3U)) + 7694520596043297922U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 11U)) + 5530753590015084774U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 50U)) + RotL64(aCarry, 21U)) + 3776309161718383105U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 35U)) + 784780304358106404U) + aNonceWordP;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8999942326995036509U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 5194986506064092779U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15070787038006135963U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7920040007459652762U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11311997270710107937U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 6227571709361790209U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 5365231114813547251U) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8630110234623825263U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2735881715888325759U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2358235238039571072U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18059414891616491807U;
            aOrbiterJ = RotL64((aOrbiterJ * 17150786106857185467U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14526050556461782864U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6937282036603272474U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14954512365270028029U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10105832250694931310U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 3884223553012098137U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16340956813003906195U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 10385284339549648087U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1257633893341505930U;
            aOrbiterK = RotL64((aOrbiterK * 2669950791270500977U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 21U);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterA, 20U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterK, 47U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterH, 41U)) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterC, 57U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterE, 3U)) + aOrbiterG) + aNonceWordH) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19559U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 16437U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 19346U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21757U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21589U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18059U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 37U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 60U)) + 17081642665820489793U) + aNonceWordL;
            aOrbiterA = (aWandererF + RotL64(aIngress, 37U)) + 14468854040067229623U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 5U)) + 2249450222593057429U) + aNonceWordH;
            aOrbiterB = (aWandererK + RotL64(aCross, 43U)) + 14964389079511378664U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 17003491054252360650U) + aNonceWordO;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 12710882240582032588U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 9887078182156755359U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7665284531810584704U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 7304284015511876717U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6193179739025093929U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5517927023543751734U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17704756310857362759U;
            aOrbiterB = RotL64((aOrbiterB * 15826832172923213591U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11347400363019508578U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11696395232760991243U;
            aOrbiterH = RotL64((aOrbiterH * 9725231749679442003U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10875780291242873583U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 7808740614343437672U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8889516201913716283U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 3145390996141902032U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16080636485642732615U;
            aOrbiterD = RotL64((aOrbiterD * 7445756373012217305U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3929263288176983844U) + aNonceWordN;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 18210228766683996806U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 13178080076505449091U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 13948962323541421431U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3037683309790156893U;
            aOrbiterA = RotL64((aOrbiterA * 13406672352222636739U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 3U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterG, 40U));
            aWandererC = aWandererC + ((((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 23U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterG, 21U)) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 21U) + RotL64(aOrbiterB, 47U)) + aOrbiterK) + aNonceWordC) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterB, 27U)) + aNonceWordK) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31747U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 26675U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 32440U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27614U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25097U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 30080U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = ((((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 13U)) + 12809562813316740345U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (aWandererB + RotL64(aScatter, 3U)) + 17084212535326321199U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 43U)) + 16074921689983846769U) + aNonceWordB;
            aOrbiterF = (((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 53U)) + 14027986153007120145U) + aNonceWordI;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 7633455951809250227U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 19U)) + 340989348513370174U) + aNonceWordM;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 11U)) + 5307820377645020116U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5605285015771527274U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5293500434746182790U;
            aOrbiterG = RotL64((aOrbiterG * 17674669610895537063U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7263156475892261811U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10672879570907433005U;
            aOrbiterK = RotL64((aOrbiterK * 2506338667179450741U), 13U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 16659226780900986107U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9774892622769850665U;
            aOrbiterC = RotL64((aOrbiterC * 7487477727543183211U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10728057184108279042U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5032485856947407217U;
            aOrbiterF = RotL64((aOrbiterF * 16651577903809154285U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14642241075374862345U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8386481273395203518U;
            aOrbiterB = RotL64((aOrbiterB * 11649977733867003445U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2874153265304098104U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 11519900149177261000U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2010158758971864505U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8885690878540115768U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4482143389870987714U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7105332459437434281U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 12U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 21U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterC, 11U)) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterE, 51U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 50U) + aOrbiterB) + RotL64(aOrbiterK, 44U)) + aNonceWordL) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x802B26D8D0580193ULL + 0x9637B6A3C920DD99ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x82FCFF616CE7C02BULL + 0xC9A0909885330FFDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9C39EF7101DD69EDULL + 0xFD29F4FC5143F675ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB3E1A8BB8AED0AADULL + 0xAD8D79C30CE8E86FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB2F33C960A855F19ULL + 0xA370F3FEA6869C07ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8BC8D72ABE2D3601ULL + 0xA6217031584F1A45ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8DD2CE63F2600315ULL + 0x9B73DB79636DEA5CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA26D4F5CC71C695DULL + 0xF442DF2D83A0193DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x80DB1A4D2E495F3DULL + 0xEF178D1220774335ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xABA3B33D89503C5BULL + 0x92715705039AD22AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE44F1A7EB4C80951ULL + 0x84943602330B6D4BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD39275C7A42D5B31ULL + 0x9D292F2263DDDAFAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBAB65D78979E240DULL + 0x853EDC189DF10A38ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB19A8456D9B15B83ULL + 0xD13C4C871AD3D4EDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE9FDB87AFE7C068DULL + 0xD6725ABB84E158FCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFC7731AA64314DA9ULL + 0xF88C8B10D316B43DULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneD, aExpandLaneC, aExpandLaneD, aWorkLaneC, aOperationLaneA, aFireLaneD, aFireLaneA, aOperationLaneB, aFireLaneB, aFireLaneC, aOperationLaneC, aWorkLaneB, aWorkLaneA
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2618U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 6509U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 4305U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4769U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2374U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 3126U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 30U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = (aWandererB + RotL64(aPrevious, 56U)) + 1557680213571812384U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 29U)) + 7387349725778021121U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 11U)) + 15379264067601586976U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 53U)) + 3730195724576043708U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 9637070085323827066U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 21U)) + 1170865717363676184U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 34U)) + 2750833653175252030U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 15118992811225568305U) + aNonceWordD;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 27U)) + 4974092922102988451U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 13U)) + 10625719096296719514U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 43U)) + 855167122475471865U) + aNonceWordH;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11322911068958340262U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4334591909425429835U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 10059025861172038183U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14263701737208936392U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 678723206735649084U;
            aOrbiterG = RotL64((aOrbiterG * 10823239851733632227U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15652053114252065230U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1705225940224061401U;
            aOrbiterF = RotL64((aOrbiterF * 3626023093533713579U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6826394665732900206U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11902946775066981141U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18300629262162694137U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9802212958998591310U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14001358545610206524U;
            aOrbiterB = RotL64((aOrbiterB * 13172645840788327099U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4299184726135884309U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7288757011999872416U;
            aOrbiterI = RotL64((aOrbiterI * 16806027820468277393U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 233801262480580205U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 14208660347238680268U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 6299693448313154603U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9217797359740446104U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 18165073197136050838U;
            aOrbiterD = RotL64((aOrbiterD * 11677479094709512887U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9101905235436427482U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2884224555227870272U;
            aOrbiterE = RotL64((aOrbiterE * 12085235281782370391U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13118509728421714433U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1385390888603164704U;
            aOrbiterA = RotL64((aOrbiterA * 6927424835779289199U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9621084561183039538U) + aNonceWordO;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 1557680213571812384U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 3202327770291862207U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 24U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterF, 51U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 26U) + RotL64(aOrbiterB, 29U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterB, 18U)) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 23U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 41U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 53U)) + aOrbiterD) + aNonceWordL);
            aWandererH = aWandererH + ((((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterF, 38U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 43U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 40U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10812U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 9859U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 8817U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10511U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9358U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 16070U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 24U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 6069475454765660321U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 20U)) + RotL64(aCarry, 27U)) + 11483704742497268068U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 11055697447388986418U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 53U)) + 10897095046039997004U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aWandererG + RotL64(aIngress, 47U)) + 4731637118230457840U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 57U)) + 13855839187084986751U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 50U)) + 5328208115460188239U) + aNonceWordE;
            aOrbiterE = (aWandererH + RotL64(aCross, 13U)) + 12479538544291412985U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 3U)) + 10740165998792608231U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 29U)) + 6492798157284955373U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 35U)) + 13056825957483891921U) + aNonceWordD;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2068184064919194657U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5656302738780746294U;
            aOrbiterA = RotL64((aOrbiterA * 16493021179127646345U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11193756120230763294U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17306750816837208999U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 7949360041241439741U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12952818800389361804U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15380412293642628312U;
            aOrbiterK = RotL64((aOrbiterK * 2914662289178925547U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7706090204767242996U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14598802276412649570U;
            aOrbiterI = RotL64((aOrbiterI * 4821408736292041399U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17819762117328075515U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6481384240915075101U;
            aOrbiterH = RotL64((aOrbiterH * 4836701121865783029U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 754936290510338717U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15510875946573720154U;
            aOrbiterJ = RotL64((aOrbiterJ * 2994718968852184303U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9245381722813944586U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2629847912019726214U;
            aOrbiterE = RotL64((aOrbiterE * 6718795794951106961U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 3909987749797113773U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 9277056074757335265U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11580847505996697115U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12577180954515966707U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9144513680789115458U;
            aOrbiterB = RotL64((aOrbiterB * 8880777678193004979U), 53U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 1544232962956974411U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2658275904714859636U;
            aOrbiterD = RotL64((aOrbiterD * 1926083316365175327U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5733515391293514025U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6069475454765660321U;
            aOrbiterC = RotL64((aOrbiterC * 9627476106108146391U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 56U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterK, 57U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterF, 41U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 40U) + aOrbiterG) + RotL64(aOrbiterB, 5U));
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 60U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 39U)) + aOrbiterG) + aNonceWordP);
            aWandererG = aWandererG + ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterE, 43U)) + aNonceWordJ);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterD, 11U)) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 34U)) + aOrbiterF) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneB
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneC
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19834U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 17848U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19951U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17529U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22224U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 17225U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 36U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 11U)) + 13854738573712660276U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 16835460633412286294U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 50U)) + RotL64(aCarry, 41U)) + 6785859293758091931U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 53U)) + 126317283127992659U;
            aOrbiterI = (aWandererE + RotL64(aCross, 29U)) + 7568963536291415413U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 35U)) + 12294016745653004819U) + aNonceWordD;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 41U)) + 18269588932920281147U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 5872406424994751026U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 22U)) + 7764434758831474129U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 27U)) + 4804168969415573371U) + aNonceWordO;
            aOrbiterJ = (aWandererI + RotL64(aCross, 39U)) + 959601763507651280U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9257644462479293048U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 14332699366894494579U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 8829304078930625541U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10487012596470786004U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 612729229562321440U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11380387280507726003U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 7845523921295625315U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12742115479740024747U;
            aOrbiterG = RotL64((aOrbiterG * 15578543510683986421U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10294667720904610944U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14369711143154904567U;
            aOrbiterD = RotL64((aOrbiterD * 13753005602288309379U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10918344717497681894U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18136794828308636957U;
            aOrbiterH = RotL64((aOrbiterH * 17899418637978002409U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14378638206724886404U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7077588188450008059U;
            aOrbiterE = RotL64((aOrbiterE * 485375960462924335U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8941870012851971932U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15242087859620352399U;
            aOrbiterC = RotL64((aOrbiterC * 4963002810455992839U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 10395280254030875387U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6826595516076975980U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6198886240333178001U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10407910809564430664U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6368255889263255730U;
            aOrbiterA = RotL64((aOrbiterA * 3809496492809859731U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6365669830464231626U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 596785214258266904U;
            aOrbiterK = RotL64((aOrbiterK * 6338109335634389561U), 41U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 4807438574488830717U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13854738573712660276U;
            aOrbiterJ = RotL64((aOrbiterJ * 6954368463489446551U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 58U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 12U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + aNonceWordG);
            aWandererB = aWandererB + ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 29U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterB, 50U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 47U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 30U) + RotL64(aOrbiterH, 11U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 3U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterE, 22U));
            aWandererK = aWandererK + (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterB, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 40U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneB
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneA
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30793U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 28394U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27655U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25521U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31324U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32620U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 48U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 5573188770530340913U) + aNonceWordJ;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 23U)) + 1431772230889897111U) + aNonceWordH;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 37U)) + 4809192776429682319U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 5576603692574369341U;
            aOrbiterA = (aWandererA + RotL64(aCross, 11U)) + 2720143226007220386U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 17220328778565331629U) + aNonceWordO;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 18U)) + 9629485808442089423U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 43U)) + 1136998437010390983U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 47U)) + 11893390497814523841U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 29U)) + 1764986431917532370U) + aNonceWordA;
            aOrbiterC = (aWandererF + RotL64(aScatter, 58U)) + 1741014798007010376U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12221368453236547044U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7694538641172350430U;
            aOrbiterK = RotL64((aOrbiterK * 8439120733670016501U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 17472344518811560603U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3308740700728172984U;
            aOrbiterA = RotL64((aOrbiterA * 15290400462887712083U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9535358833412446771U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11192312491731312451U;
            aOrbiterB = RotL64((aOrbiterB * 17405609148475445743U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14850451970047190039U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11932493299452443256U;
            aOrbiterH = RotL64((aOrbiterH * 7964808728820467795U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5972619895614731870U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17174497535809891690U;
            aOrbiterC = RotL64((aOrbiterC * 15471084511364572533U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17412894714378898351U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14675615208706549810U;
            aOrbiterG = RotL64((aOrbiterG * 7864845089606499769U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 16116792108013658523U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9702262005960966336U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 970452849653781703U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17337264966818542841U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7004462033775827275U;
            aOrbiterI = RotL64((aOrbiterI * 11943575980344402681U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17499850384482055438U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1839357713256560566U;
            aOrbiterF = RotL64((aOrbiterF * 12943750650487416281U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8144238113917577524U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 888195876227325908U;
            aOrbiterD = RotL64((aOrbiterD * 7941506708630993709U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5081763359501717653U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5573188770530340913U;
            aOrbiterJ = RotL64((aOrbiterJ * 9699901099898698965U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 24U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterA, 23U));
            aWandererG = aWandererG + ((RotL64(aIngress, 48U) + aOrbiterI) + RotL64(aOrbiterE, 51U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 18U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterE, 47U));
            aWandererK = aWandererK + (((RotL64(aScatter, 46U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 38U)) + aNonceWordC);
            aWandererE = aWandererE + ((((RotL64(aCross, 41U) + RotL64(aOrbiterG, 21U)) + aOrbiterK) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterI, 13U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 11U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 5U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 40U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB764FAC3BA0B90C3ULL + 0xCF6A4771811D491DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDD3C27240C5428B1ULL + 0xE66FE44DF931EF27ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD62D3B0021747D15ULL + 0x9035C00B8166CBFEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE2056DFC866644ADULL + 0x82AAB3B036C80C7BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAE8877B1427830C9ULL + 0xEEEC9915F4386142ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB971461ED0C1830DULL + 0x88C63CDB9727F204ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA7CA823317FAC58DULL + 0xD9A99B29D8A261CAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8A28B15C7CB0BBCFULL + 0xBA6C13AD39BED8B7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA332920719804E2FULL + 0xFAC1679963859539ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC016446354E73BBDULL + 0xD552A07E5E5CE3FFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8C3A7E142141D6F1ULL + 0xCE32822907A4E149ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDEDCC457E5E39B17ULL + 0x968F7472AB164AF0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xADCE12D266CFDBC3ULL + 0xFFCE751326DAE773ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD8E86FBB9192A5A5ULL + 0xE745CD3996CF76B8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x95443F4A3EAFB6DDULL + 0xD21ECA325A7518AFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB07AF3EF5853EDDDULL + 0xA03513B90EE71BAFULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aWorkLaneC, aExpandLaneA, aFireLaneD, aWorkLaneA, aExpandLaneB, aWorkLaneD, aFireLaneA, aExpandLaneC, aFireLaneC, aWorkLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1936U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 1524U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2544U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4655U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 457U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 782U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 47U)) ^ (RotL64(aIngress, 21U) + RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 19U)) + 16802219662864902427U) + aNonceWordK;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 60U)) + 14332033461409490629U) + aNonceWordL;
            aOrbiterH = ((aWandererD + RotL64(aCross, 29U)) + 8781794298640286845U) + aNonceWordM;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 8459933908074937264U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 47U)) + 1883580287986004426U;
            aOrbiterD = (aWandererG + RotL64(aCross, 23U)) + 17500258188004626118U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 54U)) + 7934811305150872870U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 6380363892361098905U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 19U)) + 12623079132626676910U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10455208121949202703U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8805532707916767629U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 666082374369701881U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9161544391400377699U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 3501434325829663268U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 7933545151293799637U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 651783304096081996U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 441505031509930622U;
            aOrbiterG = RotL64((aOrbiterG * 8045355432310956143U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1771159983581326424U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15227946417377695989U;
            aOrbiterD = RotL64((aOrbiterD * 1563141188972797601U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4153717524193279095U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4404521756523902829U;
            aOrbiterJ = RotL64((aOrbiterJ * 1410342912973206203U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6231945075461813285U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 3864780227164426690U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18031353247480673617U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1509699687948576558U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17316114302489411191U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15490661284980281585U), 23U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 2250572827340157410U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 6403966113144372915U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 726441947009132383U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2329903609147403156U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2486330017319455238U;
            aOrbiterI = RotL64((aOrbiterI * 17427461345935191757U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 47U)) + aOrbiterB) + aNonceWordE);
            aWandererE = aWandererE + ((RotL64(aScatter, 20U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterA, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterC, 52U));
            aWandererK = aWandererK + ((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 39U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 30U) + RotL64(aOrbiterH, 6U)) + aOrbiterJ) + aNonceWordF) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 26U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13937U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 10097U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 12867U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16151U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10354U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15421U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 34U)) + (RotL64(aCross, 3U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = (aWandererJ + RotL64(aScatter, 56U)) + 14179205183062705133U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 210032324058740920U;
            aOrbiterF = (aWandererD + RotL64(aCross, 21U)) + 7387115089142500152U;
            aOrbiterA = ((((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 17583362781238061430U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 4991442849150005943U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 51U)) + 2891376254689854555U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 60U)) + 10523274382407446239U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 47U)) + 3861893764676218667U) + aNonceWordO;
            aOrbiterE = (aWandererB + RotL64(aIngress, 3U)) + 3366674459852093746U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5898492634386601145U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7047353571244768721U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 2257518291062508467U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14374108805453186316U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8763667021501226510U;
            aOrbiterB = RotL64((aOrbiterB * 7694695426430267863U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18261523829316379575U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 650477532238860965U;
            aOrbiterG = RotL64((aOrbiterG * 8291758490821819851U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2162326554604894042U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5776546692501825278U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14911545784585246537U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3501863793638415049U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 14853789267425352958U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10590325397179928739U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15399673014671329743U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 12253428583438990426U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 12052855472196447849U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13202953937621953839U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7547616636832698398U;
            aOrbiterH = RotL64((aOrbiterH * 9533399972562428073U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15709801946594868318U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12458677982746610971U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6662570874316418993U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 6957370791367530127U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10511379961344950861U;
            aOrbiterE = RotL64((aOrbiterE * 15551333099264031337U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 6U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterA, 3U));
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterG, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 41U)) + aNonceWordE);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterB, 60U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 11U)) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 23U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterF, 36U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneD
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18008U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((aIndex + 21311U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17102U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23602U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21134U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 19154U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 21U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 42U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (aWandererC + RotL64(aScatter, 39U)) + 13583136155674166402U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 12830472187484919497U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 19U)) + 18081197909484522509U) + aNonceWordN;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 30U)) + RotL64(aCarry, 57U)) + 8680634051297891550U;
            aOrbiterI = (aWandererI + RotL64(aCross, 43U)) + 13939998767458656823U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 47U)) + 1795730579103692594U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 17369751719734069999U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 13U)) + 224769585901248068U) + aNonceWordL;
            aOrbiterE = ((aWandererB + RotL64(aCross, 60U)) + 4133547085925268180U) + aNonceWordJ;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7022512056309567391U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10319484359046945495U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 3400140531307001933U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10483878349412282069U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6481381149199985736U;
            aOrbiterI = RotL64((aOrbiterI * 9701719367082506253U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13721077228796934509U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9704818014314175007U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 760445624027740287U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6253040047758584339U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16890211690273641226U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5622534399866057841U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6216227831265032436U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 2023609047004658739U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 3252332895698310147U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9201669637050388263U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5106927540934338576U;
            aOrbiterC = RotL64((aOrbiterC * 6368134569042291431U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10080368957861445998U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10784789383436485808U;
            aOrbiterA = RotL64((aOrbiterA * 3794918350254445939U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15426339824951793026U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17637144549368340331U;
            aOrbiterE = RotL64((aOrbiterE * 10971293914614704441U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9941300382181962134U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8118046374121322097U;
            aOrbiterF = RotL64((aOrbiterF * 8481945819050983127U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 42U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 14U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterI, 60U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 47U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 35U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterB, 6U)) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 29U)) + aOrbiterE) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 4U) + aOrbiterD) + RotL64(aOrbiterC, 23U));
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26595U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 24787U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 32754U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27276U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32654U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26793U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 29U)) + (RotL64(aCross, 56U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 2783898056762489197U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 47U)) + 7177192902873343053U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 56U)) + 12254703232691980774U) + aNonceWordE;
            aOrbiterF = (aWandererH + RotL64(aIngress, 29U)) + 15446547245691219559U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 888475203006174856U;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 3649183529366307877U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 23U)) + 4642631047518805167U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 10U)) + 6108329730724782250U) + aNonceWordD;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 19U)) + 8334054653023816636U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5891895375031474350U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3176720746238477862U;
            aOrbiterC = RotL64((aOrbiterC * 1869961473768307911U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6111038696865301675U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11914998302228682704U;
            aOrbiterD = RotL64((aOrbiterD * 11738924766359642853U), 53U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 17005063057791320948U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 18333780598768130670U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5416759844884107303U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2056115016443263153U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10245512728872962677U;
            aOrbiterG = RotL64((aOrbiterG * 707106795383284903U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 4810366069422162351U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3051442983125942469U;
            aOrbiterE = RotL64((aOrbiterE * 13558537578054436423U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9285068547223654308U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13067251130180968842U;
            aOrbiterA = RotL64((aOrbiterA * 7000687697769766605U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3203670242792002165U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1770881716916463461U;
            aOrbiterB = RotL64((aOrbiterB * 13870229847371882171U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16286823712870537410U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 13067191141829694202U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15629974528467350445U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3414576315085336932U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8979691827341555245U;
            aOrbiterH = RotL64((aOrbiterH * 15971594804040295757U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 23U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterA, 14U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterA);
            aWandererD = aWandererD + (((((RotL64(aIngress, 34U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 51U)) + aNonceWordP) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterF, 43U));
            aWandererH = aWandererH + ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterD, 10U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + aNonceWordA) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 51U)) + aOrbiterI) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Bowling_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8D46D48F1E71CEE1ULL + 0xEA4FA008DDB02D64ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB6BC6154C214933BULL + 0xA571879D3B6A4AF8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA2A7AD9A0E0C2363ULL + 0xD2F067D350142A44ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x990DDF57B3E7742BULL + 0x8B17B475FEC72B27ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9FE4FCDF39F2C30FULL + 0xAAEEA2F497B39C60ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x816D606827D78BEDULL + 0xAA3573C0DBBD2DBEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDD2CAED492F96B03ULL + 0xA253583CDE16C891ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC29E7C9AB69CECABULL + 0xA4571880C3B40B17ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x92163740912ED041ULL + 0xFDA21E7CC6D1B8A5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAD1672F5397DDB8FULL + 0xA716697BBE4AB8E0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBDEB25BE754DF295ULL + 0xB6D565B8758AE884ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCCAE812852B00FFBULL + 0x9EE058EE1E29A2E8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x81E8339D2278C1BDULL + 0xD9DE364051E479B3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x87F969E4A5CA8943ULL + 0x864063ACAFF58140ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x923C992B8926BC1BULL + 0xBA4C9B7E70D9EAEDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC3B244F46C3FA7BFULL + 0xC4D142389A5A5C05ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneD, aWorkLaneC, aWorkLaneD, aOperationLaneD, aExpandLaneA, aOperationLaneC, aFireLaneA, aExpandLaneB, aFireLaneC, aFireLaneB, aExpandLaneC, aOperationLaneA, aOperationLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6951U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((aIndex + 3043U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 4602U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3164U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4474U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5091U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (aWandererK + RotL64(aScatter, 35U)) + 5573188770530340913U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 1431772230889897111U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 48U)) + RotL64(aCarry, 53U)) + 4809192776429682319U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aCross, 23U)) + 5576603692574369341U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 41U)) + 2720143226007220386U) + aNonceWordP;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 29U)) + 17220328778565331629U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 9629485808442089423U) + aNonceWordN;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 1136998437010390983U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11893390497814523841U;
            aOrbiterJ = RotL64((aOrbiterJ * 5329621622743089531U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1764986431917532370U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1741014798007010376U;
            aOrbiterH = RotL64((aOrbiterH * 13414914086049500731U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12221368453236547044U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7694538641172350430U;
            aOrbiterI = RotL64((aOrbiterI * 8439120733670016501U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17472344518811560603U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3308740700728172984U;
            aOrbiterC = RotL64((aOrbiterC * 15290400462887712083U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9535358833412446771U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11192312491731312451U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 17405609148475445743U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14850451970047190039U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11932493299452443256U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7964808728820467795U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5972619895614731870U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17174497535809891690U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15471084511364572533U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterF, 23U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterI, 60U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 3U)) + aNonceWordH);
            aWandererK = aWandererK + ((((RotL64(aIngress, 54U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15645U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 14011U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13554U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12619U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11351U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14482U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 43U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = ((aWandererC + RotL64(aCross, 19U)) + 4179952823252098240U) + aOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aIngress, 11U)) + 3745613452332101749U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 51U)) + 2955689793395307176U) + aNonceWordP;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 5639060180251322019U) + aNonceWordM;
            aOrbiterA = (aWandererF + RotL64(aIngress, 41U)) + 7901969163853586463U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 2242166787816318119U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 34U)) + RotL64(aCarry, 51U)) + 5239936443960750064U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13939136954732185558U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 17058884136712717463U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 7222348891215482977U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 18148618660054585941U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7022023484530327814U;
            aOrbiterA = RotL64((aOrbiterA * 650100011311048589U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7722084537340095637U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11764151879690934182U;
            aOrbiterG = RotL64((aOrbiterG * 12264384877711365655U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 16412785901758144708U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9666718667728274824U;
            aOrbiterI = RotL64((aOrbiterI * 10865799822751771795U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4307127540152109364U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2457646804702647606U;
            aOrbiterH = RotL64((aOrbiterH * 6340030928007058595U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 3179394870088602208U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 504977947273774249U;
            aOrbiterC = RotL64((aOrbiterC * 16190282058883481551U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 16182729401018310837U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7110817020445860609U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13371352088428584087U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 10U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 43U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 37U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 51U)) + aOrbiterG) + aNonceWordE) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 14U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterI, 5U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21068U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 17360U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24437U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22473U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23025U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 23164U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 41U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = ((aWandererH + RotL64(aCross, 60U)) + 2177539223979303669U) + aNonceWordJ;
            aOrbiterE = (aWandererD + RotL64(aIngress, 53U)) + 3962004686551521471U;
            aOrbiterK = ((((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 8457602312617147662U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 18011802451816510632U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 11U)) + 9046101759168876832U) + aNonceWordN;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 21U)) + 11135620637431969597U) + aNonceWordD;
            aOrbiterI = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 15913029940697999701U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16304193109948135982U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13208892298820080981U;
            aOrbiterK = RotL64((aOrbiterK * 15093751072618884859U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 4182377898949419225U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13970137023071326151U;
            aOrbiterF = RotL64((aOrbiterF * 9075061559681739865U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8402396284835248583U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8859190834060657829U;
            aOrbiterI = RotL64((aOrbiterI * 13552418608113716117U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9760005337757990392U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14108277760135744897U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4474681104256093885U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12226316121949012350U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3456392186754113960U;
            aOrbiterA = RotL64((aOrbiterA * 8704729827929941215U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5004087958637038973U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7176881295123125567U;
            aOrbiterE = RotL64((aOrbiterE * 15272157962928021009U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10889800478505074438U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 13728832441482547824U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 17588477761978646139U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aCross, 21U) + RotL64(aOrbiterD, 60U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 29U)) + aOrbiterD) + aNonceWordA);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 37U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 12U) + RotL64(aOrbiterE, 47U)) + aOrbiterD) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 13U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + aNonceWordF);
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29781U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 29903U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 31449U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29749U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25032U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32579U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 35U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 5U)) + 12380376990224645149U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 18296928500297384014U;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 57U)) + 3550626816361145100U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 2667792936946706027U) + aNonceWordL;
            aOrbiterB = ((aWandererI + RotL64(aCross, 51U)) + 12020969779370926953U) + aNonceWordM;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 29U)) + 737340727886903447U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 36U)) + RotL64(aCarry, 11U)) + 1681797651799760502U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 2956186342689489064U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1876852870402977177U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8875540081346621757U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6433205819353555071U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9065076854974222998U;
            aOrbiterC = RotL64((aOrbiterC * 5459675878087242021U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3254410578766789992U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2005081975473815576U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9947701153722014085U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15992999234834560419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3458344156815120948U;
            aOrbiterG = RotL64((aOrbiterG * 1668460113964608051U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17069783053664877727U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1260234710193913099U;
            aOrbiterF = RotL64((aOrbiterF * 4561226779897414381U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3825186451876061335U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2905344294992827535U;
            aOrbiterB = RotL64((aOrbiterB * 2469896090698580795U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 18141402347899180617U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8760129857609925066U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2507999156108123047U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterJ, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 12U) + aOrbiterC) + RotL64(aOrbiterJ, 53U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterF, 35U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 27U)) + aOrbiterG) + aNonceWordF);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAE4ED0D9E9F9D1A3ULL + 0x91671C527974FFA9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCEAA5CECE68C9C0BULL + 0xB03A506EDD998730ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD7EDB98E279ADB17ULL + 0xF1843E48FB60F173ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBA6463EC19E24495ULL + 0xA7C66839A64E5408ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9C8522A0D7A298F1ULL + 0xB4E7CF011EFE4D53ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC6233D08F293290BULL + 0xB39CF261451059ADULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF6C6AB90892BD5D7ULL + 0xBDACDC1F98A23384ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9B02594FDBC8A311ULL + 0xCC671A80E306C009ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCC478BA0CF39EB3FULL + 0xE2DE70912A6C9CB7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x99C4CE9D4A3B6C5BULL + 0xBE5E3E5570587720ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDEF4E1FD931D3953ULL + 0xFF6F07BCB80505A9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x88CC106DE75D8AD7ULL + 0xA6EE1F6F23E6AB49ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF13780B8A7C3B5ADULL + 0x9B753256CAA6804CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x973DFE017CBAB7D1ULL + 0xD65E058320AE6D40ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB7AB24C104357125ULL + 0x96F2EDADF52EEAC6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD49C17F0F9EB28D3ULL + 0xEAED08980EED5CBAULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1868U)) & W_KEY1], 58U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 99U)) & W_KEY1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 922U)) & W_KEY1], 34U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1370U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 39U)) ^ (RotL64(aCross, 3U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = ((aWandererF + RotL64(aCross, 5U)) + 4476099022490972343U) + aNonceWordO;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 16836423700375760429U) + aNonceWordD;
            aOrbiterB = (aWandererA + RotL64(aScatter, 27U)) + 8850577488928703557U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 19U)) + 7091631824560042743U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 12560498899956759494U;
            aOrbiterK = ((((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 7797973377112012161U) + aPhaseEOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aWandererG + RotL64(aCross, 60U)) + 6173820673874805794U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 10805025132310245348U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7139216143268029968U;
            aOrbiterB = RotL64((aOrbiterB * 8349754682635765573U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8241544862261635722U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 4735527016563596150U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6621354217673598381U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5166171126690294033U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11117641762075368393U;
            aOrbiterG = RotL64((aOrbiterG * 4980156869201219393U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6312932356458415421U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 1304139291184508668U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 90744653170922319U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10085025354842771067U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16745854428789531080U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1945983905747274355U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2497187958708890337U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16069701876646548995U;
            aOrbiterE = RotL64((aOrbiterE * 16606039730973709495U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17242004368025978091U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12334315722243232121U;
            aOrbiterC = RotL64((aOrbiterC * 16528598396696346719U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 43U)) + aOrbiterE) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + aNonceWordL);
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 57U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterG, 28U)) + aNonceWordK) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 37U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterI) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 40U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3546U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5380U)) & W_KEY1], 34U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4642U)) & W_KEY1], 29U) ^ RotL64(mSource[((aIndex + 4423U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 37U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 21U)) + 3970829908171131502U) + aNonceWordA;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 41U)) + 7040283759419531991U) + aPhaseEOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 11856292169397052901U) + aPhaseEOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 14U)) + 819598588791819022U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 57U)) + 2176451710970866848U) + aNonceWordN;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 35U)) + 6454704928613390494U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 11792122387218053841U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9254780213489752211U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16591812589999846482U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 5425771603523423167U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 1471246223935074832U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1424843083106386453U;
            aOrbiterE = RotL64((aOrbiterE * 15020536982657410783U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1856469958050891629U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6331743690452052712U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15327924647897459645U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 10351075711345476487U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9518585245330480185U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3792179827396760391U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17787514620244712033U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14182328067398162557U;
            aOrbiterG = RotL64((aOrbiterG * 18107337388659070197U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12798088948801072444U) + aNonceWordK;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9563215159275202323U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7058145016617349141U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9904919772580498232U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16579777394992143043U;
            aOrbiterH = RotL64((aOrbiterH * 10516761340320196661U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 50U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterA, 34U)) + RotL64(aCarry, 51U)) + aNonceWordM) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterE, 41U)) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + aNonceWordC) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 54U) + aOrbiterA) + RotL64(aOrbiterI, 5U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 39U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterD, 27U));
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 28U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 8110U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 8157U)) & W_KEY1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5813U)) & W_KEY1], 12U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6539U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 5962U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 14U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = (aWandererC + RotL64(aScatter, 60U)) + 2783898056762489197U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 41U)) + 7177192902873343053U) + aPhaseEOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 11U)) + 12254703232691980774U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 15446547245691219559U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 888475203006174856U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 3649183529366307877U) + aNonceWordF;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 35U)) + 4642631047518805167U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6108329730724782250U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8334054653023816636U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 9352516059501924393U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5891895375031474350U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3176720746238477862U;
            aOrbiterH = RotL64((aOrbiterH * 1869961473768307911U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6111038696865301675U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11914998302228682704U;
            aOrbiterG = RotL64((aOrbiterG * 11738924766359642853U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17005063057791320948U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 18333780598768130670U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 5416759844884107303U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2056115016443263153U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 10245512728872962677U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 707106795383284903U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 4810366069422162351U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3051442983125942469U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13558537578054436423U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9285068547223654308U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13067251130180968842U;
            aOrbiterD = RotL64((aOrbiterD * 7000687697769766605U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 36U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aNonceWordD);
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterH, 35U));
            aWandererK = aWandererK + (((((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 13U)) + aNonceWordO) + aPhaseEWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 5U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterI, 60U)) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterI, 21U)) + aOrbiterA) + aNonceWordL);
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 27U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 10880U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadB[((aIndex + 8515U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(mSource[((aIndex + 8693U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9985U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10092U)) & W_KEY1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8307U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 54U)) + (RotL64(aCross, 19U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 43U)) + 15036852811491820366U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 44U)) + 305637140752898475U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 37U)) + 11948631574496129610U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 3U)) + 5321623592482991426U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 13U)) + 4075270159062690728U) + aNonceWordK;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 15111580500356908928U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 7244150695504160363U) + aNonceWordJ;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5131563519577488862U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 5881954992088651371U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2424421828597294607U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12780935808751507998U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12599159643925470226U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 17690046932587062701U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9466589929741834066U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6093158735705189789U;
            aOrbiterD = RotL64((aOrbiterD * 7453778295800853653U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17461243886150519249U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 15456408913739900718U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16093292401746174671U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11260643903290392780U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 7870342756041882616U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 2431528656086173419U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 134484990005888936U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10626896209992890407U;
            aOrbiterF = RotL64((aOrbiterF * 12034131076645285597U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14031164129515132292U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1771835705730244212U;
            aOrbiterB = RotL64((aOrbiterB * 186981668443596623U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 53U) + RotL64(aOrbiterI, 4U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 37U)) + aOrbiterH) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterA, 23U));
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterD, 13U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12312U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 13055U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11207U)) & W_KEY1], 22U) ^ RotL64(mSource[((aIndex + 13025U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13570U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12636U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11595U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 26U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = (aWandererF + RotL64(aCross, 11U)) + 12849591986267890852U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 4U)) + RotL64(aCarry, 53U)) + 8232614804696815750U;
            aOrbiterF = ((((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 12141567259210877281U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 2928641981037885644U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 51U)) + 980733350554783938U) + aNonceWordF;
            aOrbiterD = (aWandererB + RotL64(aIngress, 35U)) + 2683985177993350746U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 21U)) + 14532148403815527355U) + aPhaseFOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7736296629433884203U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10428437770166310549U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 326634742742373401U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 18327174144859461029U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6810436935194432002U;
            aOrbiterE = RotL64((aOrbiterE * 2715987179577753597U), 35U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 12606153309690753435U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17123256945895150555U;
            aOrbiterA = RotL64((aOrbiterA * 13469111258504672565U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9057777759026189541U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16478485918911194442U;
            aOrbiterD = RotL64((aOrbiterD * 11054247078884894131U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 18064460487552100483U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11477276762421684083U;
            aOrbiterJ = RotL64((aOrbiterJ * 3886501230380184395U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 18318375441973295081U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13849305985380030986U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12962140243967824959U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10240409420338313641U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 18360586077779529086U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18196875422391501927U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 22U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 54U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 13U)) + aOrbiterA) + aNonceWordB) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterD, 5U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterK, 29U)) + aNonceWordN);
            aWandererG = aWandererG + (((((RotL64(aScatter, 46U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aNonceWordD) + aPhaseFWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 23U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14935U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14245U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15486U)) & W_KEY1], 56U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14595U)) & W_KEY1], 27U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15286U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15700U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16304U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 18U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 51U)) + 14249093584376402677U) + aNonceWordD;
            aOrbiterK = (aWandererF + RotL64(aIngress, 58U)) + 8756965951816492264U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 3U)) + 11221139480258176330U) + aPhaseFOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 17218894445564194851U) + aPhaseFOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aScatter, 11U)) + 8064642692524949490U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 5822093203710704646U) + aNonceWordM;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 3217799620158102238U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 2613757677892120843U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13647481499551657237U;
            aOrbiterI = RotL64((aOrbiterI * 5517563514031899891U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 3545714196663685016U) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9735422670576621521U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 7276207208162697249U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3911046580637583767U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9315984027042049203U;
            aOrbiterA = RotL64((aOrbiterA * 12568550776487242469U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8926367674641729058U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11035347490524961446U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10948288997163592463U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10748158733051120339U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2467801787989056455U;
            aOrbiterC = RotL64((aOrbiterC * 12621934274702358977U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9244415080474351390U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8517784887959492079U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17022899813765884147U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8409307332803038455U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11043806021873232950U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8294888329708842989U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterC, 11U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 41U)) + aOrbiterF) + aNonceWordL) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 35U)) + aOrbiterA) + aNonceWordI);
            aWandererI = aWandererI + ((((RotL64(aCross, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 14U) + aOrbiterG) + RotL64(aOrbiterF, 18U)) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18963U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 17813U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(mSource[((aIndex + 17457U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16973U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18164U)) & W_KEY1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19073U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17849U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 58U) ^ RotL64(aCarry, 37U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 36U)) + 17470880031634374199U) + aNonceWordP;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 29U)) + 757565846006937746U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 9419282475801345674U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 53U)) + 2014248014107898196U) + aPhaseGOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 15113928519446490441U) + aNonceWordO;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 3U)) + 7346126964886259935U) + aNonceWordJ;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 5594123113093162359U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5659237263369402005U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11565709683423969703U;
            aOrbiterK = RotL64((aOrbiterK * 16731289017588574671U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16782863743534856287U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 13499100900072115907U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5567729598873214433U), 5U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 11414447651044205242U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7545993795121430538U;
            aOrbiterC = RotL64((aOrbiterC * 10758488381206257261U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11778229237616454988U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2544793391976514665U;
            aOrbiterB = RotL64((aOrbiterB * 4021060413798523299U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9972156716619459164U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 17651030383827445664U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 6742914240706775487U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17439147296849134543U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10021926927948343656U;
            aOrbiterA = RotL64((aOrbiterA * 18139540407315440909U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9309867875882669289U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14951424455944346337U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10569523948169951309U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 48U)) + aOrbiterB) + aPhaseGWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterI, 57U)) + aPhaseGWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 48U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19242U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 21592U)) & S_BLOCK1], 40U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19776U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20680U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21188U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19970U)) & W_KEY1], 57U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21340U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20745U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 29U)) + 826930775230515406U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 10U)) + RotL64(aCarry, 3U)) + 5137814617363250861U) + aNonceWordL;
            aOrbiterG = (aWandererD + RotL64(aIngress, 39U)) + 14761561947426681616U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 3U)) + 12773023438753662590U;
            aOrbiterB = (aWandererK + RotL64(aCross, 51U)) + 7331345852207096322U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 3899381212671247460U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 47U)) + 10072004147620068599U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3424585039401897560U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8246760141625966321U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11478879365443736383U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 3655992860610853290U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11154618022505863898U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 4791494171286145231U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15629361991059709973U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10842068502278489664U;
            aOrbiterH = RotL64((aOrbiterH * 17223002513104960799U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5571312349016336686U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 589313823745748879U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 1356685926549786027U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13633457935771935260U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 12684602052812183096U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4689206269919806711U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5711307583717354204U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7181854170553728211U;
            aOrbiterC = RotL64((aOrbiterC * 9835601115561325911U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1884620014396115821U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1471516373272364262U;
            aOrbiterI = RotL64((aOrbiterI * 5126319375714848029U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 19U)) + aNonceWordH) + aPhaseGWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 58U)) + aNonceWordP) + aPhaseGWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 51U)) + aOrbiterH) + aNonceWordC);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 46U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + aNonceWordK);
            aWandererC = aWandererC + ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24558U)) & S_BLOCK1], 12U) ^ RotL64(aKeyRowReadA[((aIndex + 22636U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22650U)) & W_KEY1], 21U) ^ RotL64(aFireLaneC[((aIndex + 23307U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24273U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22790U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23021U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22699U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererI + RotL64(aIngress, 5U)) + 5510690816044082200U) + aNonceWordE;
            aOrbiterC = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 15967820875033940530U) + aNonceWordJ;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 19U)) + 539348720848176221U) + aNonceWordN;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 15779318183635560817U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 58U)) + 14511058534424187469U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aWandererE + RotL64(aScatter, 27U)) + 5811130556873428391U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 1085928476499444025U) + aPhaseGOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6973335316600768130U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10747243745475009744U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 17322489216048017061U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 1072260008981349754U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2018772405352495753U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10840562112080574241U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1092091597048996547U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15103140149542167197U;
            aOrbiterB = RotL64((aOrbiterB * 621856991658027989U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13194619321108681542U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16749188603268621850U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9575408950550922039U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7427959503086895166U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9895804051379551393U;
            aOrbiterD = RotL64((aOrbiterD * 2701997336201570715U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4526020800679774259U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 4484850928870048176U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 17556987520625677313U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1837404844299040155U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15213208978489570694U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7062740584650274133U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 19U)) + aOrbiterH) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 43U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 46U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterC, 13U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aCross, 50U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + aPhaseGWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 12U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25748U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 27161U)) & W_KEY1], 58U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25337U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 26604U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26861U)) & W_KEY1], 6U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24622U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25531U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 24995U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 13053031069776604052U) + aPhaseHOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 1331396630251085122U) + aNonceWordL;
            aOrbiterI = (aWandererB + RotL64(aScatter, 35U)) + 15879286043343942393U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 47U)) + 13590365633321406830U) + aNonceWordP;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 14569235423040242618U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aCross, 26U)) + 11397370636618371560U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 5U)) + 3455933494593971847U) + aNonceWordO;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1307153376443784593U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10688618762584786871U;
            aOrbiterI = RotL64((aOrbiterI * 9503823896874842411U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17746248451153600096U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8512568600755410158U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 16648320170768234063U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8950230550112591092U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17790968369472845496U;
            aOrbiterB = RotL64((aOrbiterB * 5104988920132008913U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12583323865381967534U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11243927099685293887U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12867003042486433971U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9690268715525781389U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7466066217365074653U;
            aOrbiterG = RotL64((aOrbiterG * 17565696765505320889U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3673528673209875118U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14079103852360952255U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17449228863409999629U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6747836856132250630U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5027692924422297153U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2492421273167124437U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 6U);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterJ, 53U)) + aNonceWordN) + aPhaseHWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + aNonceWordK);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 46U)) + aNonceWordM) + aPhaseHWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 5U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterB, 39U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28310U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneD[((aIndex + 29202U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27791U)) & W_KEY1], 35U) ^ RotL64(aFireLaneC[((aIndex + 27991U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28827U)) & W_KEY1], 12U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28788U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29256U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28270U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 43U)) + (RotL64(aCross, 56U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 23U)) + 3238389262925516513U) + aNonceWordA;
            aOrbiterD = (aWandererG + RotL64(aScatter, 14U)) + 12381787182611386995U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 47U)) + 7883885539305181549U) + aNonceWordC;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 1185413044597727092U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 15219353497204773135U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 57U)) + 7533774715626734082U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 2599930450937763464U) + aPhaseHOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 16074720663961214284U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15483613196360051221U;
            aOrbiterJ = RotL64((aOrbiterJ * 11717479088020532861U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9396557867081376268U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 9668459976852660245U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 11748505665890567063U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9037269914643207212U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 16936742640861088240U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 1040172193161012227U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16481274825758546398U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 481851372837611166U;
            aOrbiterD = RotL64((aOrbiterD * 2225030139210599207U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 13608921517203544108U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16930740723286214636U;
            aOrbiterG = RotL64((aOrbiterG * 2605108503821980865U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 902242902582149908U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1510861213079342977U;
            aOrbiterK = RotL64((aOrbiterK * 3309753895727400707U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7116243600304980310U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6631412278359709602U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11452627691392637463U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 4U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 12U) + RotL64(aOrbiterA, 12U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 35U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 21U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterH, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 19U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererB, 18U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31952U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 30112U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30467U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31958U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31583U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31255U)) & W_KEY1], 4U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 26U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = (((aWandererH + RotL64(aScatter, 28U)) + RotL64(aCarry, 19U)) + 2915859148137000694U) + aPhaseHOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aIngress, 51U)) + 210680583721444425U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 11U)) + 6668118118775650387U) + aPhaseHOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 15794200818099010989U) + aNonceWordG;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 21U)) + 6565076707062828369U) + aNonceWordN;
            aOrbiterG = (aWandererA + RotL64(aScatter, 57U)) + 16323164497808856719U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 7965435318816716560U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7390281030573369017U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 2269738866911824875U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1198697877998135567U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9664014216039993873U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18284857398028357633U;
            aOrbiterJ = RotL64((aOrbiterJ * 8402008251343393737U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 367667619795303009U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 7935945060956274197U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5481786693511955209U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16683666162337789540U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 10655658270998102390U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15231596813382239841U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 8307037916581540297U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3247742749860703524U;
            aOrbiterK = RotL64((aOrbiterK * 15052136713218656641U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10446792483683818139U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16374602929344972364U;
            aOrbiterB = RotL64((aOrbiterB * 12599903932725787599U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2411334498322777183U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1093701164116833765U;
            aOrbiterD = RotL64((aOrbiterD * 13129220206835381729U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 57U));
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterK, 41U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 14U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 6U)) + aOrbiterJ) + aNonceWordD) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 35U)) + aOrbiterK) + aPhaseHWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD2AFF2E66077DC6FULL + 0xC2A59CDFF6B59667ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFA19EA61541671B1ULL + 0x83EA44B7AE1B7D0AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD53240FF8C254683ULL + 0xC5ED60F8B1BE3D1EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF6D185FA098A0515ULL + 0xD14CAA7670DE19ADULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFD81CB26E1630841ULL + 0xE4949DFF18716AD8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA7799680FE02EE13ULL + 0xBCE3F2BAB1D1CB1FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF1C481D49DFB87F1ULL + 0xDF87A5D773FF6067ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA26E53569A18E807ULL + 0xA79B0241471FBFFAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x915C781E934249EDULL + 0x8533857D4F7E2F5FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8DB4B2F5B998651FULL + 0x9017F9673ACD201AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE57C6844D1A12793ULL + 0xCB33746E78CD6867ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB182267805D11C61ULL + 0x9F6B17C9A5B85168ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB1C3B61BD92F51BBULL + 0xCA914D90E14BFABFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD7EC893698B40A23ULL + 0xE656E56D08ADE62EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCD4DB63258925C39ULL + 0x922C01D7E997DF73ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEBF66CE32EDC0EBFULL + 0xA234341228AC65A3ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneD, aInvestLaneB, aFireLaneC, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2206U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 42U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1677U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3531U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5225U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aIngress, 11U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererG + RotL64(aIngress, 28U)) + 1457104756581596530U) + aPhaseAOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aCross, 37U)) + 6127240317844622874U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 16492290056044189421U) + aNonceWordN;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 10963676850938416468U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 4872917367399752405U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 15218882377875616148U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5934166612122118251U;
            aOrbiterB = RotL64((aOrbiterB * 10365045124180379919U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14215280930872003003U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11428034799044600979U;
            aOrbiterI = RotL64((aOrbiterI * 12162528943733976177U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5453003654321728726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14273775120265649389U;
            aOrbiterG = RotL64((aOrbiterG * 5139018128323795309U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 328723770018440271U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 13032190719588211088U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 13363368478932798315U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2386881543033598494U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 1649501123340887116U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 11148976582360499033U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 23U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 48U)) + aOrbiterB);
            aWandererG = aWandererG + (((((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 27U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aNonceWordM) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterI, 3U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererE, 48U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneD
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 6511U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 6634U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 8077U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7753U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 10499U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 14U) + RotL64(aCarry, 39U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 3U)) + 16160838483846078448U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 15404960896190227946U) + aNonceWordF;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 16904160594024977199U;
            aOrbiterI = ((((aWandererE + RotL64(aCross, 46U)) + RotL64(aCarry, 53U)) + 17790460246821031802U) + aPhaseAOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 29U)) + 16395168254086971959U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7484373204039901786U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18026814691322913510U;
            aOrbiterH = RotL64((aOrbiterH * 12688155753775099489U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 15244817793136966450U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5795491730356335666U;
            aOrbiterA = RotL64((aOrbiterA * 13253529465289332171U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3163873518027801504U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2690791759507349172U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 16677948635136515083U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17898067251167087906U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 8028010015006604239U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 5601629670521300241U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 7304739457289910555U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6476837815096530043U;
            aOrbiterI = RotL64((aOrbiterI * 16380545138701113267U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 40U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterB) + aNonceWordE);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterH, 19U));
            aWandererG = aWandererG + (((((RotL64(aCross, 13U) + RotL64(aOrbiterE, 37U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordC) + aPhaseAWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 48U)) + aOrbiterI) + aNonceWordH) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneC
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12695U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((aIndex + 14599U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 11924U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12240U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14672U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13053U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 964165145848253292U) + aNonceWordH;
            aOrbiterF = ((aWandererI + RotL64(aCross, 28U)) + 10645976767204934746U) + aNonceWordL;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 43U)) + 8241612229349212650U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 4159196033256913347U) + aNonceWordK;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 11U)) + 7194795864620233507U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 7638928444536778384U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11819105916503968109U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9052440449038441625U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18052213302858186237U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8663575313970041570U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14131073322476609161U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16644136720439299786U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16930316530442679864U;
            aOrbiterJ = RotL64((aOrbiterJ * 2650922074098320859U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16251107616988250593U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7171986193609401665U;
            aOrbiterF = RotL64((aOrbiterF * 3543709971414550087U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 17885046834432626644U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7757069274715713557U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15766885299397923879U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterH, 37U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 3U)) + aOrbiterF) + aNonceWordJ) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 10U) + RotL64(aOrbiterK, 24U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20079U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((aIndex + 19663U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 19450U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17609U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21708U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19569U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 57U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 12136097566601676613U) + aNonceWordC;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 3U)) + 7969431322248040056U) + aPhaseAOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 44U)) + RotL64(aCarry, 23U)) + 10530676021510553889U) + aNonceWordK;
            aOrbiterF = (aWandererF + RotL64(aScatter, 35U)) + 8740777303075445264U;
            aOrbiterA = ((((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 13249434169895564739U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15529577005925628472U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 344627093687331562U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 3226087371456521323U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8824277416519988893U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5636276438449709875U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 222817930773618893U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2079413361031851552U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7807998179168655561U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 961456853699784753U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13589392896232029112U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10733011474804473996U;
            aOrbiterJ = RotL64((aOrbiterJ * 361749145931578805U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15934162328347805968U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7573511217796245232U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10694563909931636155U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 4U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterJ, 39U));
            aWandererA = aWandererA + (((((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 19U)) + aNonceWordO) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + aNonceWordD);
            aWandererF = aWandererF + ((((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25705U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((aIndex + 25055U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24179U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23741U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23907U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 25275U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 57U)) + (RotL64(aIngress, 24U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 1898718075389870739U;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 37U)) + 5631794889237247403U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 18219714659484524607U) + aNonceWordJ;
            aOrbiterI = (aWandererF + RotL64(aCross, 52U)) + 15419581386225732921U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 9125575431710198210U) + aPhaseAOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12205871520544965505U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7617534300497343422U;
            aOrbiterD = RotL64((aOrbiterD * 10052675719887595625U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 18017579105368135814U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10693882161946020042U;
            aOrbiterB = RotL64((aOrbiterB * 2326507900303932855U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 11669615701700895306U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11045110212889232165U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 5965171269273719849U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 18019107802806469913U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12315940560472528716U;
            aOrbiterC = RotL64((aOrbiterC * 4505122470351404065U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4899009736070044310U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17412253404253730364U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10791901166391946485U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 4U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + aNonceWordF);
            aWandererE = aWandererE + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 23U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 40U) + RotL64(aOrbiterC, 39U)) + aOrbiterK) + aNonceWordP) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 13U)) + aOrbiterD) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28304U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 29790U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 28152U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28078U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28340U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 31872U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = ((((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 826930775230515406U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 48U)) + 5137814617363250861U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 14761561947426681616U) + aPhaseAOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 12773023438753662590U) + aNonceWordG;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 19U)) + 7331345852207096322U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3899381212671247460U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 10072004147620068599U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 5663583566047763435U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 3424585039401897560U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8246760141625966321U;
            aOrbiterH = RotL64((aOrbiterH * 11478879365443736383U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3655992860610853290U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11154618022505863898U;
            aOrbiterB = RotL64((aOrbiterB * 4791494171286145231U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15629361991059709973U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 10842068502278489664U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 17223002513104960799U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5571312349016336686U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 589313823745748879U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1356685926549786027U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 22U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterH, 19U)) + aNonceWordK);
            aWandererD = aWandererD + (((((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 46U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aNonceWordM) + aPhaseAWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 35U)) + aOrbiterB) + aNonceWordB) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA1B8AD9931EEF97FULL + 0x9E516D9C350ACC17ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x92DF116B0591B83BULL + 0x98180DC06DFBE052ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB455339494E88381ULL + 0xD9C8D10C3BAC485CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEA1CCB58EDF2A40FULL + 0xC42F90C8C8C9A767ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEE4899914DDBBB41ULL + 0xD3C01BDB5B2E6E5AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9A548910B58877EDULL + 0xB28E9D8476020FC5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF7F59076D60A83F3ULL + 0xC8502CD6DCBACCFEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF8CC7A694E82F03DULL + 0x86120225089AB7CDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8BD97FCA3DCF9959ULL + 0xD909045BDCAEA817ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC062FDE013524927ULL + 0xCA5D2EB7DA3FB85BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFA139A36E4BF6F49ULL + 0xE80DF9A99F5F0298ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE44D8701BDF450A9ULL + 0xF6DB42D504DD61BDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA2A4970BEB38C609ULL + 0xB9E82181035852C4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x81BEBBF6F502DDBFULL + 0xF1BC35BEF7F2651DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x864A64A6F45EB27BULL + 0xFA647E29BC2235E2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA8C9D7DBAA7AA6D7ULL + 0xDCDA07C6F9088334ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneB, aOperationLaneC, aOperationLaneD, aFireLaneB, aInvestLaneC, aExpandLaneA, aFireLaneD, aInvestLaneD, aExpandLaneC, aWorkLaneA, aFireLaneC, aWorkLaneB, aExpandLaneD, aWorkLaneC, aFireLaneA
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2132U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 743U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4774U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2580U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4575U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2573U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 54U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 22U)) + RotL64(aCarry, 35U)) + 3105313968748067810U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 57U)) + 9977249451119627064U) + aNonceWordE;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 35U)) + 17941392803495349366U) + aNonceWordO;
            aOrbiterA = (aWandererF + RotL64(aCross, 47U)) + 4279533326705471133U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 30U)) + 13983828966811580039U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 3983490984234810378U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 11U)) + 308786542215259956U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 51U)) + 8443607695364427037U) + aPhaseBOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 14939626441464340668U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9350693577306121110U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1717071159396961752U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11062480662625054525U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 15911765265202100610U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14898546272333182767U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 2674900543810733067U), 27U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 3560903518513465868U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5367062725726860234U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8521908836601319553U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15233321480618877327U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 9288449812290126074U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 6815298520404038519U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5504840529511585676U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6825598386801620046U;
            aOrbiterB = RotL64((aOrbiterB * 11666542445846250077U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6433024450721339470U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 97934156644929458U;
            aOrbiterJ = RotL64((aOrbiterJ * 8630530773006923215U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3260053604798744515U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16539416623243059076U;
            aOrbiterI = RotL64((aOrbiterI * 12199577351166064503U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9814290051339038920U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13280156404507444041U;
            aOrbiterK = RotL64((aOrbiterK * 15269010043398910061U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11853942590993546833U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13207869904312989977U;
            aOrbiterE = RotL64((aOrbiterE * 15503461937625795969U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 42U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterE, 3U)) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterI, 52U)) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + aPhaseBWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 46U) + RotL64(aOrbiterA, 21U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterI, 39U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 30U)) + aOrbiterG) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneA
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9773U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 8081U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10625U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 7299U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7012U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6286U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6380U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 37U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 22U)) + RotL64(aCarry, 27U)) + 6361545377408870615U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 2967245486744774933U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 5U)) + 3836634268482850139U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 13U)) + 7691642115360086297U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aWandererB + RotL64(aIngress, 57U)) + 16479280384178279281U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 27U)) + 2901468732552539249U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aWandererI + RotL64(aCross, 42U)) + 2600353867755647475U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 5666596904781510956U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 53U)) + 16108791609267427553U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8389926875737312112U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1689501721163024426U;
            aOrbiterE = RotL64((aOrbiterE * 6517194895779049139U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11721701506949917719U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3963842745030140473U;
            aOrbiterJ = RotL64((aOrbiterJ * 6692473494944919373U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 8510538243472109368U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 18281865214102080387U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1351546966368884609U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2259725140963665123U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11652011949557979650U;
            aOrbiterK = RotL64((aOrbiterK * 11260100762113295037U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1116085424226174473U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4725260319270802912U;
            aOrbiterI = RotL64((aOrbiterI * 4697109059565450269U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7348945429843437036U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1249234309180653260U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3136745255820405881U), 11U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 12463505532573389603U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2304125977906510386U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 9960816714791454421U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2178037443783425551U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11712110130079307683U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 9797864956200779505U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10703510612147312252U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 18155460326242413483U;
            aOrbiterA = RotL64((aOrbiterA * 6903953708987478723U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 23U);
            aIngress = aIngress + (RotL64(aOrbiterI, 36U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterA, 13U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 40U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterA, 18U));
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 35U)) + aOrbiterE) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterK, 23U)) + aPhaseBWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 4U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aCross, 36U) + RotL64(aOrbiterI, 43U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aExpandLaneC
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13182U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((aIndex + 13068U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15211U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15274U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneC[((aIndex + 13997U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 42U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 826930775230515406U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 29U)) + 5137814617363250861U) + aNonceWordM;
            aOrbiterK = (aWandererJ + RotL64(aCross, 14U)) + 14761561947426681616U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 5U)) + 12773023438753662590U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 23U)) + 7331345852207096322U) + aNonceWordB;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 3899381212671247460U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 10072004147620068599U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 43U)) + 3424585039401897560U) + aPhaseBOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 10U)) + 8246760141625966321U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 3655992860610853290U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 11154618022505863898U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 4791494171286145231U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15629361991059709973U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10842068502278489664U;
            aOrbiterI = RotL64((aOrbiterI * 17223002513104960799U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5571312349016336686U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 589313823745748879U;
            aOrbiterF = RotL64((aOrbiterF * 1356685926549786027U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13633457935771935260U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12684602052812183096U;
            aOrbiterD = RotL64((aOrbiterD * 4689206269919806711U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5711307583717354204U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7181854170553728211U;
            aOrbiterC = RotL64((aOrbiterC * 9835601115561325911U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1884620014396115821U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1471516373272364262U;
            aOrbiterA = RotL64((aOrbiterA * 5126319375714848029U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 742739371092077733U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 8075893317715227838U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 11208274111743259795U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8179547722249281263U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 15305282712174742323U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 7951986906055462929U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1430543231751281079U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 14585341768267283387U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 313213844964269133U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 44U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 29U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 60U)) + aOrbiterD) + aNonceWordK);
            aWandererK = aWandererK + ((((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 21U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 51U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 22U)) + aOrbiterE) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterD, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 10U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 20880U)) & S_BLOCK1], 22U) ^ RotL64(aInvestLaneC[((aIndex + 17926U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 20873U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16816U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20497U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 20U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 8101351470141807662U) + aNonceWordH;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 46U)) + RotL64(aCarry, 37U)) + 6965474099521076705U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 41U)) + 6803828268885684784U) + aPhaseBOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 13454235922950972488U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 37U)) + 11678091885751244777U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aWandererC + RotL64(aCross, 12U)) + 5307134544628507141U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 19U)) + 4873703518950429353U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 57U)) + 8542156221858586039U) + aNonceWordD;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 3U)) + 3993726182905296513U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12113047622035464386U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1944244448665721151U;
            aOrbiterI = RotL64((aOrbiterI * 7010050836758762003U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12914188029425467576U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2486762763475327024U;
            aOrbiterK = RotL64((aOrbiterK * 12319769994433811617U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 14580191602982245481U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12093414832400135066U;
            aOrbiterJ = RotL64((aOrbiterJ * 12720286833215690663U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13623906997320021065U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9977356009806428696U;
            aOrbiterD = RotL64((aOrbiterD * 2005536391712733499U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3694954095397810851U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11453812627797091638U;
            aOrbiterF = RotL64((aOrbiterF * 13730420725113907161U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 542311345544726351U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3024285045990499484U;
            aOrbiterB = RotL64((aOrbiterB * 5153745952148205645U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15397664082460849530U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 10716856680110815056U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13947203772929252823U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 833342121331428547U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1111339940097269219U;
            aOrbiterG = RotL64((aOrbiterG * 17991642769781175473U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9312963978841402871U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8225496710723213204U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 894499195498817065U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 18U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 34U) + RotL64(aOrbiterI, 14U)) + aOrbiterJ) + aNonceWordI) + aPhaseBWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + RotL64(aOrbiterK, 47U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterB, 51U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterD, 19U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterI, 37U));
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterK, 23U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 56U)) + aOrbiterK) + aNonceWordK) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 48U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aExpandLaneD
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22260U)) & S_BLOCK1], 22U) ^ RotL64(aInvestLaneD[((aIndex + 25555U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26017U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24361U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((aIndex + 24183U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 3684295017013759987U;
            aOrbiterJ = ((((aWandererB + RotL64(aCross, 28U)) + RotL64(aCarry, 27U)) + 6740408842457292881U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aWandererK + RotL64(aScatter, 19U)) + 4563975890702399441U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 47U)) + 797804144825287940U) + aPhaseBOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 39U)) + 2763779540450101303U) + aNonceWordJ;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 43U)) + 13211846164102089685U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 15214578447281401982U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 60U)) + 13745208628754232427U) + aNonceWordM;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 23U)) + 17358621225969190747U) + aNonceWordC;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 779739369960480023U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4370963533701407813U;
            aOrbiterE = RotL64((aOrbiterE * 3123135216876641039U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6061333005507739975U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3589705340762734456U;
            aOrbiterI = RotL64((aOrbiterI * 16499293983611196967U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10607697666369230567U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 9356757995305239271U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 10945513661439954731U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10093033335903048138U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11037328061699834100U;
            aOrbiterK = RotL64((aOrbiterK * 11189760551792389605U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 558431161176115540U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 17795680919453449358U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3910117359996283803U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6096779391116214109U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 17594243286880690775U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12655610181937429915U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15414704802398002423U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 18040588240488602196U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 16344249573086571225U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14636298592697156931U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 9677305688594936561U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8354776999961642997U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16408025751875050713U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10018342878801454965U;
            aOrbiterD = RotL64((aOrbiterD * 10349132962708124117U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 18U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 43U)) + aOrbiterB) + aNonceWordA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 44U) + aOrbiterI) + RotL64(aOrbiterE, 51U)) + aNonceWordI) + aPhaseBWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterK, 3U));
            aWandererG = aWandererG + ((((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 47U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 29U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI) + aPhaseBWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterI, 22U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28928U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 29722U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 32419U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31401U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28630U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 18U)) + (RotL64(aIngress, 51U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = (((aWandererF + RotL64(aCross, 41U)) + 18144572925667544139U) + aPhaseBOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 5659758077574059728U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 13U)) + 6343330616999166392U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 3U)) + 17754639838410839447U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 23U)) + 9451843819849581729U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 11U)) + 7957854457197462212U) + aNonceWordB;
            aOrbiterC = (aWandererK + RotL64(aCross, 35U)) + 1461994799722205010U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 18002214276252170177U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 54U)) + 14689869073147027164U) + aNonceWordD;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 3978104368003440293U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8512135845221335386U;
            aOrbiterH = RotL64((aOrbiterH * 10506667163729414667U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1477533446382953439U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2166717790929947990U;
            aOrbiterI = RotL64((aOrbiterI * 6538884492418324461U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8082437060686606995U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4363687722464700362U;
            aOrbiterD = RotL64((aOrbiterD * 7199165810993478887U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15782763348014924206U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8572509150015960728U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3340528604891897779U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12248271773316742521U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9602078627638561949U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1860631869877427405U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17244849374768558859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1030743048280579012U;
            aOrbiterC = RotL64((aOrbiterC * 10858949914285817051U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17722342363541914280U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15667504059789880034U;
            aOrbiterJ = RotL64((aOrbiterJ * 15872269872168533709U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 12645332941998550794U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9938135244509986497U;
            aOrbiterF = RotL64((aOrbiterF * 16548185968987392957U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4024609904162105979U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6732064218696157303U;
            aOrbiterK = RotL64((aOrbiterK * 3815409766145891393U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 38U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 56U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterK, 19U));
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 52U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 23U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 39U)) + aOrbiterD) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterC, 56U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            aWandererB = aWandererB + (((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + aPhaseBWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 40U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9CF83C26A241B26DULL + 0x83AE51F79A8A9522ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAC8C4FA56046CB7FULL + 0xBD268CBE4E872532ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9B8F9ABD10372921ULL + 0x9BAD494E441D39CDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD633C58C95DD44F9ULL + 0xBD12C2AC3BEA3FD4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA03149771247B04BULL + 0x9350F233A3CD33E5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD3439DF40F9C6D0DULL + 0xF57BE90420515C45ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBA1D8E959E541D27ULL + 0xAA23CDF60F5D56C9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCFFE684A476DFBA9ULL + 0x8AF877EC54C9D5F0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFB2FAEA248ACC3BFULL + 0xE5B5A633EBF6BC27ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFF878FA222B06DEFULL + 0x8745D105F716B2DBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8EE4E02CF93EEA81ULL + 0xC87DEE46796C4275ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF5F00EE9AF0B5887ULL + 0x8FB30C0E4421919CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x940AE02FA10E60C1ULL + 0xCC8FF694E141723EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEE145AF24D0C572FULL + 0x9FC074D680A36153ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x93F044ED982B3459ULL + 0x877CC414FD373C56ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE01F49A7C0CE732DULL + 0x86A61444D916E7E5ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2142U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 5373U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 1147U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4983U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 675U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 527U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 40U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (aWandererG + RotL64(aIngress, 47U)) + 13880995121909552664U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 19U)) + 14534942818069300546U) + aNonceWordD;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 17745973100886007133U;
            aOrbiterC = (aWandererF + RotL64(aCross, 35U)) + 2249805580771946872U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 41U)) + 4460116116396439410U) + aNonceWordN;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 21U)) + 3378683994078106878U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 3992996501048809123U) + aPhaseDOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12057768808864451929U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4115362079047921130U;
            aOrbiterI = RotL64((aOrbiterI * 12263015903331031345U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15297384955502206698U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 17623548383481905636U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 7487278217901483685U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3559213898000162417U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12311605719074507335U;
            aOrbiterF = RotL64((aOrbiterF * 3982199462062847697U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14807313864347885885U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11222085523291581822U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12580941911587215653U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 916681229436292462U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2441350114032314686U;
            aOrbiterA = RotL64((aOrbiterA * 7336079498999018067U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7361470539894653271U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12153585147213579808U;
            aOrbiterC = RotL64((aOrbiterC * 3040327545467672961U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13566300726101613579U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 14875254144748509128U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13699179902908972403U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 47U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 19U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterB, 12U)) + aNonceWordK) + aPhaseDWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 3U)) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 5U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6286U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 10671U)) & S_BLOCK1], 14U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9210U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 9247U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8285U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8100U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 10108U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 43U)) ^ (RotL64(aCross, 60U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = ((aWandererJ + RotL64(aCross, 57U)) + 2101601659597850213U) + aPhaseDOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 2759794072560720121U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 6U)) + RotL64(aCarry, 29U)) + 9443562552411269339U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 10801360546699857975U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 29U)) + 8020716394829332019U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 35U)) + 1021894212367773801U) + aNonceWordA;
            aOrbiterC = (aWandererA + RotL64(aIngress, 47U)) + 13346855534622490176U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16359309548462953836U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12642446944680783519U;
            aOrbiterH = RotL64((aOrbiterH * 12197935153255283321U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8197424982767553380U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14346334610901859094U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16982899923227935679U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14171304260534233539U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 334531601308283605U;
            aOrbiterD = RotL64((aOrbiterD * 5012968232749075075U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10707856298471572695U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 18364775750091914766U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 15735143943129143265U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8531394793118363836U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15352876929406908882U;
            aOrbiterF = RotL64((aOrbiterF * 475199047053777179U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 567682016232278157U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2068146551757663119U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1557877740957797555U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 7776122587613256525U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16430938890724272256U;
            aOrbiterC = RotL64((aOrbiterC * 4540270493783593257U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterF, 11U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 37U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 54U) + aOrbiterC) + RotL64(aOrbiterE, 29U)) + aNonceWordD) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterB, 43U)) + aNonceWordF) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterC, 3U)) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 19U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 58U)) + aOrbiterC) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 10976U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 13020U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13450U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13009U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14312U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 42U) + RotL64(aPrevious, 27U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = (aWandererE + RotL64(aPrevious, 44U)) + 5573188770530340913U;
            aOrbiterD = ((((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 1431772230889897111U) + aPhaseDOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 5U)) + 4809192776429682319U) + aPhaseDOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aScatter, 19U)) + 5576603692574369341U) + aNonceWordM;
            aOrbiterC = (aWandererA + RotL64(aCross, 29U)) + 2720143226007220386U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 17220328778565331629U) + aNonceWordF;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 9629485808442089423U) + aNonceWordI;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1136998437010390983U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11893390497814523841U;
            aOrbiterI = RotL64((aOrbiterI * 5329621622743089531U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1764986431917532370U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1741014798007010376U;
            aOrbiterB = RotL64((aOrbiterB * 13414914086049500731U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12221368453236547044U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7694538641172350430U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8439120733670016501U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17472344518811560603U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3308740700728172984U;
            aOrbiterC = RotL64((aOrbiterC * 15290400462887712083U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9535358833412446771U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 11192312491731312451U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 17405609148475445743U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14850451970047190039U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11932493299452443256U;
            aOrbiterK = RotL64((aOrbiterK * 7964808728820467795U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5972619895614731870U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 17174497535809891690U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15471084511364572533U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 28U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 12U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            aWandererG = aWandererG + (((((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 35U)) + aNonceWordG) + aPhaseDWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterE, 11U)) + aNonceWordB);
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterB) + aNonceWordO);
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterK, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 60U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 18970U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneA[((aIndex + 17114U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16877U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17481U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21338U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (aWandererD + RotL64(aIngress, 21U)) + 6916817163240024692U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 56U)) + RotL64(aCarry, 11U)) + 14554930751292077817U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 1098305064484336101U) + aNonceWordK;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 12192821172420471527U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 29U)) + 2435134991707318845U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 11U)) + 1896745368738512624U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 41U)) + 1114996424222923873U) + aNonceWordJ;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9839135798371512656U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8037967239603177043U;
            aOrbiterJ = RotL64((aOrbiterJ * 7848951103759663025U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15185468738487237432U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4912098316394854543U;
            aOrbiterI = RotL64((aOrbiterI * 3072785550384399929U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13142688607850380888U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4507379759608945839U;
            aOrbiterB = RotL64((aOrbiterB * 2989332387754215967U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7299006009652289342U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5390655277207053627U;
            aOrbiterE = RotL64((aOrbiterE * 10973744708856143715U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6744737023577785725U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15539737698867067285U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4686092035261336911U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13329866734681377952U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13284937458969166257U;
            aOrbiterA = RotL64((aOrbiterA * 3965985432462699445U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8695002088915702168U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3858059421620839286U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 9559783727301092937U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 41U)) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 60U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterJ, 53U)) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 22419U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((aIndex + 26275U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24340U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26769U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((aIndex + 27273U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 36U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 51U)) + 12980104182836602177U) + aNonceWordO;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 3172622203188863995U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 57U)) + 1170974132219980203U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = ((aWandererA + RotL64(aCross, 4U)) + 6035201940965047490U) + aPhaseDOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 18033907118424996722U) + aNonceWordD;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 14604813424800580304U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 37U)) + 13720232492851066035U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3902659710585257448U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8331560652661619868U;
            aOrbiterF = RotL64((aOrbiterF * 11418103770615560205U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4485014147538689794U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 168202636924512424U;
            aOrbiterB = RotL64((aOrbiterB * 13711020666131492091U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16227825670092707848U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 4792781933944671365U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15859849676231455283U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12636865372722601282U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 18198291399585556632U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 18155803890313399795U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3650053185419807206U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 5897288963905408776U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3706949366974086151U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9922308113622901726U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13352279749091561510U;
            aOrbiterH = RotL64((aOrbiterH * 4025213180483632557U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 14969461950939646117U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10231661776135056651U;
            aOrbiterJ = RotL64((aOrbiterJ * 11284575051455238501U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + aNonceWordN);
            aWandererK = aWandererK ^ (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterH, 29U)) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterB, 57U));
            aWandererE = aWandererE + (((RotL64(aCross, 60U) + RotL64(aOrbiterC, 21U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterB, 13U)) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterH, 38U)) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 31747U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((aIndex + 29199U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 29115U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31413U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32047U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 35U)) ^ (RotL64(aCarry, 47U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 3248574644570178787U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 11U)) + 4506961512959200024U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 27U)) + 8423739774540738590U) + aNonceWordB;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 6593975869641735337U;
            aOrbiterI = ((((aWandererK + RotL64(aCross, 34U)) + RotL64(aCarry, 23U)) + 16441716090557369103U) + aPhaseDOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 19U)) + 7936601450453207914U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 53U)) + 13333752583560167065U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8013703284795432973U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2349852779887439236U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2422888500648100783U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5318539364763284138U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11450957608502944376U;
            aOrbiterI = RotL64((aOrbiterI * 1957880366707810635U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9058992558327552687U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 632095686920230926U;
            aOrbiterC = RotL64((aOrbiterC * 12460364388358520799U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14734218428913777098U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16344357661370784442U;
            aOrbiterF = RotL64((aOrbiterF * 15049472842002138369U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2981145363531184308U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 14176472085175714494U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2584623327412130939U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11198457590069700889U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 952584436750426828U;
            aOrbiterJ = RotL64((aOrbiterJ * 1165713888651280355U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 4311591763498985972U) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 16194341833989936369U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 9997934560195932575U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 21U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aCross, 50U) + aOrbiterD) + RotL64(aOrbiterC, 12U)) + aNonceWordI);
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x91C29B7B8738A59FULL + 0xC5A2F382B2F5EC3AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAABFE4470E5BFE99ULL + 0xE13FDD2705758CA3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF65C3649E9263AA9ULL + 0xE60933C36C9B6637ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA774313E687C307FULL + 0x8BF84AF0274FD6D1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDB0F71A98A477021ULL + 0xF8C6FA2EA57506CBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x95278BCE0705DE6FULL + 0xE4C71AF0BF401A88ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF83D7B7554D9B4A3ULL + 0xD12EC5D29C90B962ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBAD68091BAAC4D39ULL + 0x99031AD029A1ECF9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF1CECD293F26297DULL + 0x87D8D3AA2C2FD95EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xEC09DF36B34C30B1ULL + 0xAF30141C63CE4655ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF93A32E5D1BA8101ULL + 0x8011DD1C3019A985ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE8AF76FA7F5D50B1ULL + 0xA9D7FFCF6F6CA1E2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBC2905E7AB8E2C77ULL + 0x82EF5E77E87867E8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD36A58F78118192DULL + 0xC4F18D1C8427078AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x81865CD688CD3FCFULL + 0xEDE70B50D5CC949EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB4ED54CC488D5751ULL + 0x93E47ECFFD60F376ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 1111U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneB[((aIndex + 4464U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 115U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 19U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 13U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 436U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 30U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = ((aWandererE + RotL64(aCross, 27U)) + 9435962834163239322U) + aNonceWordI;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 10524704356081318973U) + aNonceWordC;
            aOrbiterA = (aWandererD + RotL64(aScatter, 46U)) + 7403401305665208680U;
            aOrbiterK = ((((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 7525414805023556493U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aWandererG + RotL64(aIngress, 35U)) + 1116686470029070951U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 43U)) + 13257612299137802420U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 5U)) + 9181543003986598283U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 21U)) + 9739384852307501107U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 11308402900229016057U) + aNonceWordP;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 3U)) + 14935167593705272337U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 38U)) + 7171824007631943535U) + aPhaseEOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8068411284829563567U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12350207458513447578U;
            aOrbiterA = RotL64((aOrbiterA * 813973258659041895U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17039236343991574134U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 18291683592714999632U;
            aOrbiterI = RotL64((aOrbiterI * 7771718817924840713U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6239616841884430968U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10604527977569876774U;
            aOrbiterC = RotL64((aOrbiterC * 6972820410084939637U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1707724300671717658U) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 3802268808625297647U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11296811630387191563U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9423064323799920219U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 242153923313096551U;
            aOrbiterF = RotL64((aOrbiterF * 12117679073775630197U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 945801070951928277U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13094814302414492064U;
            aOrbiterJ = RotL64((aOrbiterJ * 14638176479878969775U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7572219725951040117U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16494986983782503428U;
            aOrbiterG = RotL64((aOrbiterG * 2739189408707408171U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10949497978229234856U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11219643352002119905U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 16900635614259262873U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14245670385849499678U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13771155918235018585U;
            aOrbiterD = RotL64((aOrbiterD * 14121731385133220921U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15722734439532828816U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11032710342174118366U;
            aOrbiterE = RotL64((aOrbiterE * 16096465375397981585U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2071496769185495150U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9435962834163239322U;
            aOrbiterH = RotL64((aOrbiterH * 10640995428633266765U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aPhaseEWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterI, 34U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 38U) + RotL64(aOrbiterA, 43U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 21U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterC) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterI, 19U));
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterH, 47U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterE, 60U)) + aOrbiterK) + aNonceWordF);
            aWandererD = aWandererD + ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 51U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterA) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 42U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 5841U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 7209U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 10490U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 10409U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 7570U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6302U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 7890U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 36U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = ((aWandererE + RotL64(aCross, 5U)) + 15726877954695761686U) + aPhaseEOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 53U)) + 14187652171881943587U) + aNonceWordH;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 8420423151313882782U) + aPhaseEOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 57U)) + 14942322692433259283U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 27U)) + 7272331475919796255U) + aNonceWordP;
            aOrbiterD = (((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 13U)) + 154504365041805840U) + aNonceWordB;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 39U)) + 17475491222554948786U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 51U)) + 5759181483165339605U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 5993060214499322845U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 14U)) + 10901786237875941844U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 43U)) + 17135786595614068473U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5208202073886811165U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6821452921018900631U;
            aOrbiterA = RotL64((aOrbiterA * 13119330055184115669U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13348064837402206969U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8967943922403445136U;
            aOrbiterH = RotL64((aOrbiterH * 300168481725373093U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8130283784171430891U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6351113882502502876U;
            aOrbiterG = RotL64((aOrbiterG * 15960622823993072903U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6894708729226455769U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12065058511247133944U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5432601727436935831U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17138279326229372741U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12987698199066890628U;
            aOrbiterD = RotL64((aOrbiterD * 12665716655177320977U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13688833537574196675U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4211971980434000618U;
            aOrbiterK = RotL64((aOrbiterK * 1374411763361518851U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 10376917117582537592U) + aNonceWordG;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4807742522197923516U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 15257251453302090961U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 18038296468177121243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6879666349379745258U;
            aOrbiterC = RotL64((aOrbiterC * 15819475269715810555U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5193656664432659624U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 680899397323387963U;
            aOrbiterB = RotL64((aOrbiterB * 9857476056194621321U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1851929589073547860U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 13093101559415170218U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13950928576652143737U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13695333301427028607U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 15726877954695761686U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 960063676226172027U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 50U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterB, 3U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterI, 14U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterF, 37U)) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 57U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 60U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 51U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 13303U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneA[((aIndex + 11405U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11059U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11884U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((aIndex + 12810U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 13U)) + (RotL64(aPrevious, 58U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 43U)) + 14214886793361825363U) + aPhaseEOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 47U)) + 17267959031078766320U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 10U)) + 16436067429484887644U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 27U)) + 9885951769332633820U) + aNonceWordC;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 12971711341813893304U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 199970353398450154U) + aNonceWordE;
            aOrbiterG = (aWandererI + RotL64(aCross, 29U)) + 1237341696444162094U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 24U)) + RotL64(aCarry, 3U)) + 7991128854417613360U;
            aOrbiterD = (aWandererE + RotL64(aCross, 51U)) + 14809029847149045833U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 35U)) + 2559509556915775947U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 13U)) + 14336829730147834160U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8853631886733610440U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 13346159398673246914U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13660497151446983393U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 12121095718571872976U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16239781125815589804U;
            aOrbiterE = RotL64((aOrbiterE * 5157009090454962231U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9051377033794324106U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13805815136723461780U;
            aOrbiterJ = RotL64((aOrbiterJ * 571129481747181357U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14849157800322754413U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 18116651528452542634U;
            aOrbiterK = RotL64((aOrbiterK * 3638480428016835537U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4105057226952948599U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5911714320560994391U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1796514171654961389U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4439149331729987587U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10278532228230163632U;
            aOrbiterB = RotL64((aOrbiterB * 17428224919864716517U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2342456582668741750U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2360578572554664800U;
            aOrbiterF = RotL64((aOrbiterF * 1108428466956691925U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12132934875391401246U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17213278726790245812U;
            aOrbiterG = RotL64((aOrbiterG * 11904899990681410419U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7994340481560109811U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13735851271080138255U;
            aOrbiterA = RotL64((aOrbiterA * 12387076892129731557U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6682417543888875268U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15642799286975840550U;
            aOrbiterD = RotL64((aOrbiterD * 7861250716882028053U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9839299346094784067U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14214886793361825363U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2103132743364916037U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 48U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 11U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 20U)) + aOrbiterG) + aPhaseEWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterK, 37U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 51U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 57U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 30U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 42U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + aNonceWordJ);
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ) + aNonceWordD);
            aWandererH = aWandererH + ((((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20214U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneA[((aIndex + 20779U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 17472U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18752U)) & S_BLOCK1], 44U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 20588U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 27U)) + 4739486756133131180U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 21U)) + 16089707555501328184U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 15310047330238536453U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 41U)) + 7901411596386834955U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 13U)) + 4357555491060982163U) + aNonceWordH;
            aOrbiterB = (((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 15667085602825720102U) + aNonceWordJ;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 19U)) + 8520635334382269253U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aIngress, 53U)) + 1772509779231068315U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 57U)) + 15336170957886025677U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 37U)) + 8628770833489469980U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 22U)) + 15469234024247246228U) + aNonceWordM;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 10796430900884288328U) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10660110397012853289U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9140007610912037461U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11202284258711214794U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17509491802893182994U;
            aOrbiterK = RotL64((aOrbiterK * 9329107599972703671U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 16212572740740103554U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2190030203761579226U;
            aOrbiterI = RotL64((aOrbiterI * 3101886685668871045U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12014337082293041909U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3733531010807001506U;
            aOrbiterJ = RotL64((aOrbiterJ * 5797362244066062299U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 7100994963061975529U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17837541162838600258U;
            aOrbiterB = RotL64((aOrbiterB * 8745987361678166553U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3311518938023146951U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7709505172646831553U;
            aOrbiterG = RotL64((aOrbiterG * 7121143171245765213U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4979968094554018443U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16822214821463034107U;
            aOrbiterD = RotL64((aOrbiterD * 8618262120451291765U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 8376124175020587079U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11084586282092424876U;
            aOrbiterF = RotL64((aOrbiterF * 5835632742522563537U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7816368455027681621U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10893292019060642422U;
            aOrbiterH = RotL64((aOrbiterH * 3995821210667317677U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13602875505184178486U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5425735673005681983U;
            aOrbiterA = RotL64((aOrbiterA * 12667085597129312079U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5995385043278810987U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4739486756133131180U;
            aOrbiterC = RotL64((aOrbiterC * 15709273328685013399U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (RotL64(aOrbiterC, 28U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 4U) + aOrbiterE) + RotL64(aOrbiterD, 23U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 12U)) + aOrbiterJ) + aNonceWordB);
            aWandererK = aWandererK + ((((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 43U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 41U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 37U)) + aOrbiterC) + aNonceWordI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 53U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterB, 39U)) + aOrbiterK) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterD, 18U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23096U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 22742U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 22131U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24872U)) & S_BLOCK1], 20U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23802U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23593U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 50U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = (aWandererH + RotL64(aCross, 14U)) + 9855743441035905047U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 35U)) + 8426286937143990276U;
            aOrbiterA = ((((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 7146752367170267002U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 3U)) + 12947210066678101726U) + aNonceWordO;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 44U)) + 15902163559925328965U) + aPhaseEOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 57U)) + 8506649889346449469U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 19U)) + 8226286036430263052U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 2703047093452420216U;
            aOrbiterI = (aWandererI + RotL64(aCross, 21U)) + 6769351326360139560U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 9857025533281333281U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 51U)) + 238297452132277585U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7203572312072908931U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12497027346166575632U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 1703586436725662307U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 473851890609048879U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1664484956453886047U;
            aOrbiterF = RotL64((aOrbiterF * 8566500756326590209U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4635095143004754116U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17695676150967345793U;
            aOrbiterB = RotL64((aOrbiterB * 5780416541584439301U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15628965269863402796U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9190117464399730235U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5586437438425999715U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17835918238346011086U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4398005402429282682U;
            aOrbiterH = RotL64((aOrbiterH * 14828737209913317463U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10902589938246551273U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15124274429081385923U;
            aOrbiterJ = RotL64((aOrbiterJ * 13524180348258805367U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8747233520702236018U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5445611443463112371U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 10294109295823410447U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16296005217836151910U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6468336224317602364U;
            aOrbiterD = RotL64((aOrbiterD * 7369779919748367133U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3827976387089403774U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7773383658122100111U;
            aOrbiterG = RotL64((aOrbiterG * 9784711300597525161U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 18273794621528918389U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8401424792700263455U;
            aOrbiterI = RotL64((aOrbiterI * 13003420427441089595U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11402828934846813949U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9855743441035905047U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7339549576423555273U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 22U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 11U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 54U)) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 37U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterK, 44U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 4U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32534U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneA[((aIndex + 32404U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31156U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29566U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneB[((aIndex + 28726U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 5131645209694953015U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 53U)) + 12070391048835379854U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 18U)) + 2604295836242338724U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 14042039029284001596U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 11U)) + 8914654543854559327U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 2185619407969359869U) + aNonceWordI;
            aOrbiterC = (aWandererA + RotL64(aIngress, 14U)) + 5187406295103352574U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 51U)) + 8022832481290871217U) + aPhaseEOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 39U)) + 8783061916740573472U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 37U)) + 10711028365596196301U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 29U)) + 13387065038269133571U) + aNonceWordF;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 11187001318931801582U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14191473173276034019U;
            aOrbiterJ = RotL64((aOrbiterJ * 2491253922434756431U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16207761776716426435U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9677408414452078760U;
            aOrbiterG = RotL64((aOrbiterG * 5487303383095129949U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17812460332794370649U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7736423148554132028U;
            aOrbiterH = RotL64((aOrbiterH * 15588733747232852555U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17293203944059014763U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 13487243633338010243U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9468688858740539095U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15979293016815060755U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17645215484691359547U;
            aOrbiterB = RotL64((aOrbiterB * 1449450767288733995U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11635961468586927692U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10530136578329059784U;
            aOrbiterI = RotL64((aOrbiterI * 8785021493374398437U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 4900370530116992731U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15952900504821599445U;
            aOrbiterK = RotL64((aOrbiterK * 5413316082800365261U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9938000151832814778U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 14170277411106520726U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 5058343552974910737U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 14091010427448547620U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 13658560822164111421U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9523184040517290629U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13954269172267844623U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3921811946419945868U;
            aOrbiterF = RotL64((aOrbiterF * 6839440867046147039U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 14296483810577739898U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 5131645209694953015U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 10190969526209064367U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 20U));
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterB, 23U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterB, 18U)) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterK, 41U)) + aPhaseEWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 53U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 43U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 47U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 37U)) + aNonceWordJ);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aIngress, 46U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAD625D9EEFD2EA9FULL + 0xE89774644EC64AB9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBAE4798F13893905ULL + 0xE8B70FE1ADACFF1DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAB018AC80A4AF1F7ULL + 0x9E86AE2A5B183C23ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB6D52E0B5BDBAB3DULL + 0xA0A097CEC745876DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB1A059E2B04A5501ULL + 0x8E72940499B312C8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD0166A30B00F4863ULL + 0xD5B993D97F146362ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE33094A7884996C5ULL + 0xC7479F2D5AD9DE6DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x803B696870D55809ULL + 0xD73D48DDBB142374ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC706CF9768AE38A1ULL + 0xE7D2A5B44245651FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xACF014B8E573E611ULL + 0xB980C548BA6F68CDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBE29231E7875F993ULL + 0xD528BA14BEF5DFFDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x93F398BA60C70E27ULL + 0xE22DBD1A89889913ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFE81F5ED00E91E6FULL + 0xD8824C91EED679E3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD223E558502505E7ULL + 0xEE0D5B7EC1DB2B1AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9F73106ADD3ACBADULL + 0x91EA5A64C6F13884ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD8EBFC6C3ACD194DULL + 0xC5ACBBE5C3F965C0ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneC, aSnowLaneC, aInvestLaneD, aInvestLaneB, aSnowLaneD, aWorkLaneD, aExpandLaneA, aInvestLaneC, aExpandLaneB, aSnowLaneB, aExpandLaneC, aInvestLaneA
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5020U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 4880U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 3457U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2719U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1143U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 3368U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aCross, 26U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = (aWandererG + RotL64(aCross, 47U)) + 1210605127156905516U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 35U)) + 11964595428173569519U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aScatter, 18U)) + 16277319029916258482U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 23U)) + 12369497463101824572U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 6201248574067068202U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 51U)) + 1727477025667206661U) + aNonceWordI;
            aOrbiterG = ((((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 1404510627789806851U) + aPhaseFOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aWandererK + RotL64(aCross, 58U)) + RotL64(aCarry, 5U)) + 6948213591282018925U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 27U)) + 6688865181284421478U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3351130769402360855U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 12681032488906270823U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 3680893896579741263U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3591412591193726763U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16153817571210878589U;
            aOrbiterD = RotL64((aOrbiterD * 4165137036092246349U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3808228354421006630U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 1427373776207504205U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 4534374093769595531U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1831554180932501132U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1114853085120949215U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4264176108298812905U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2080935638828366835U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16104777999646489828U;
            aOrbiterC = RotL64((aOrbiterC * 15205199362011777473U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9782806013673440791U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3721620299829386454U;
            aOrbiterB = RotL64((aOrbiterB * 6286765834910272409U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4013706412064296527U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5751022780695158579U;
            aOrbiterI = RotL64((aOrbiterI * 13766736471646116397U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17684546333240329338U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1106947111128020920U;
            aOrbiterK = RotL64((aOrbiterK * 3158839453318658951U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11564229705849500598U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1585817314460274286U;
            aOrbiterH = RotL64((aOrbiterH * 12687162159791577431U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 28U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterC, 34U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterB, 11U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + aNonceWordB) + aPhaseFWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 39U)) + aOrbiterH) + aNonceWordK);
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterB, 28U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aScatter, 54U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + aNonceWordM) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 9536U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 7600U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7656U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneD[((aIndex + 8880U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8138U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6631U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9521U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 56U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 11410829607777684449U;
            aOrbiterE = (aWandererD + RotL64(aCross, 44U)) + 7502698839700975347U;
            aOrbiterG = ((((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 13267685058252106173U) + aPhaseFOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 57U)) + 238242706996630625U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 35U)) + 8184695499511454281U) + aNonceWordK;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 12767823220461985403U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 27U)) + 12293198423143850330U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 14U)) + 11149495229952495939U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 21U)) + 7556992689338382800U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3431338808774134649U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16863099140844995099U;
            aOrbiterG = RotL64((aOrbiterG * 752376661101787919U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17872458049880677604U) + aNonceWordA;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 16760153457252546974U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 11225037229069712805U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3115544493537438408U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4359882942759752958U;
            aOrbiterH = RotL64((aOrbiterH * 561477566995575801U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13387113067202396536U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12955690074544490161U;
            aOrbiterF = RotL64((aOrbiterF * 12449941770827974511U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15614054443728226807U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1939441328066616114U;
            aOrbiterJ = RotL64((aOrbiterJ * 4484917074808974359U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4599016263007782537U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9962305629016158048U;
            aOrbiterD = RotL64((aOrbiterD * 1496184427500037279U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8428467674122750557U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3938884087806393439U;
            aOrbiterB = RotL64((aOrbiterB * 12810531094050481761U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6018636830758044658U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1510372000641305416U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9002834928626918247U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17592782466215337843U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8119921507606870360U;
            aOrbiterC = RotL64((aOrbiterC * 1299795061644535485U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 44U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 40U) + aOrbiterD) + RotL64(aOrbiterB, 27U)) + aNonceWordD) + aPhaseFWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterI, 6U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterB, 53U)) + aNonceWordN) + aPhaseFWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 34U) + aOrbiterC) + RotL64(aOrbiterI, 11U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 40U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 47U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 36U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aWorkLaneD
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 11890U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 12394U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16077U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 13967U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11298U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 58U)) + 11450949896247900941U;
            aOrbiterH = (aWandererE + RotL64(aCross, 13U)) + 3905542253538116335U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 53U)) + 9529740545977785305U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 1856876631533143492U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 23U)) + 84253466320181686U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 3U)) + 12577480918745432444U) + aPhaseFOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aScatter, 42U)) + RotL64(aCarry, 11U)) + 5625703170397704029U) + aNonceWordO;
            aOrbiterC = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 694608607323629282U) + aNonceWordK;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 29U)) + 3993981243536262204U) + aNonceWordP;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4119215953484892051U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 8785040118556157146U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 17113521266125471625U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16234403619456882890U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 10398727475672860610U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 5086871400049644715U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 18327987141759096769U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2645964788056875452U;
            aOrbiterD = RotL64((aOrbiterD * 8778681366114628045U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2859452497983106129U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7196557924940881076U;
            aOrbiterG = RotL64((aOrbiterG * 14415389907490256711U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 930127943984174668U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15673596916054795749U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 7505660488733199479U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16673140529110941163U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2258448294877833760U;
            aOrbiterK = RotL64((aOrbiterK * 1821550319748977445U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6870209259643931219U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12749790107942194104U;
            aOrbiterE = RotL64((aOrbiterE * 4871407285968611725U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17131374134617173866U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6426448390733751612U;
            aOrbiterB = RotL64((aOrbiterB * 12490559588384058417U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15592826434339731146U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14182944418026376183U;
            aOrbiterC = RotL64((aOrbiterC * 7218860482893476233U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 52U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 39U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterA, 51U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterB, 44U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterH, 23U));
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 35U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 11U)) + aOrbiterG) + aNonceWordC);
            aWandererK = aWandererK + (((RotL64(aIngress, 22U) + aOrbiterA) + RotL64(aOrbiterD, 4U)) + aPhaseFWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 28U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aInvestLaneC
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20912U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneC[((aIndex + 18577U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 20130U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 16841U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18766U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 19U)) ^ (RotL64(aCross, 52U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererG + RotL64(aCross, 24U)) + 15920462086654025436U) + aNonceWordE;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 487844076858004017U) + aNonceWordD;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 47U)) + 14502883786442630566U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 11U)) + 3787107318658233674U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 12548777544693755491U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 39U)) + 4907309444075181683U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 19U)) + 18342396700266492072U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 13503051997624242670U;
            aOrbiterK = (aWandererE + RotL64(aCross, 56U)) + 17845742460521374571U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8640887211877858169U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 5273913123709097537U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 1661149444148461791U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17756844173695563883U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6713055830729302951U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2832836748513174311U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5106468334224035972U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10228769728713526172U;
            aOrbiterF = RotL64((aOrbiterF * 9760310686414358435U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7687649520668883142U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7757480627354711605U;
            aOrbiterH = RotL64((aOrbiterH * 7222553727737349209U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10876291698508634557U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8149278085586014186U;
            aOrbiterK = RotL64((aOrbiterK * 8577133863470695381U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15592893988925610485U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8639028256640537165U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 1880655276432963955U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 475660347892196219U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1903736092401853832U;
            aOrbiterA = RotL64((aOrbiterA * 8486318978769094799U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12463250192809450953U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 7253918448601703982U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 3821034106528009129U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5171661020093804486U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11627344933828324146U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5388047063152043277U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 40U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 6U)) + aOrbiterA) + aNonceWordO);
            aWandererI = aWandererI + ((RotL64(aIngress, 58U) + RotL64(aOrbiterI, 35U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterE, 47U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterK, 20U)) + aNonceWordC);
            aWandererK = aWandererK + ((((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aSnowLaneB
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aSnowLaneB forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24233U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneD[((aIndex + 26912U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 22767U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24123U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneC[((aIndex + 21981U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = (aWandererE + RotL64(aScatter, 5U)) + 11274974230580265396U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 48U)) + RotL64(aCarry, 11U)) + 16658438747342741547U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 16612986966106053844U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 41U)) + 9329502236843231290U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 37U)) + 14088261356708344656U) + aNonceWordL;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 13692608802007789581U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 23U)) + 6824473946645682398U) + aPhaseFOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aWandererI + RotL64(aScatter, 10U)) + 2072915876348570040U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 29U)) + 7420507753044460759U) + aPhaseFOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4677557318688502593U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15081678577055628459U;
            aOrbiterK = RotL64((aOrbiterK * 16659305295251177155U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7026792817486507482U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 14871665922943969918U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 694073180313083145U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 6807734532159292872U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17882797335141303280U;
            aOrbiterJ = RotL64((aOrbiterJ * 15439872930381050291U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9233542707022629190U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1205501586581350876U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 2596053290311090589U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10878718669747466677U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8066049063548639241U;
            aOrbiterD = RotL64((aOrbiterD * 3031382633089381605U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 861295180226875235U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9134969787937288583U;
            aOrbiterE = RotL64((aOrbiterE * 7565008208670843555U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6726642007159809594U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8061661744643240470U;
            aOrbiterC = RotL64((aOrbiterC * 6703498926835391813U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13541412083111962884U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8617442758729315637U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 15471862889276160953U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16884403561131293362U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 9490680911678221233U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15988763830018001033U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 56U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 19U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 24U) + aOrbiterD) + RotL64(aOrbiterC, 4U));
            aWandererE = aWandererE + (((((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 43U)) + aNonceWordB) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 47U)) + aOrbiterG) + aNonceWordG);
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterA, 13U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG) + aNonceWordD) + aPhaseFWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 54U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterG, 39U)) + aNonceWordH);
            aWandererD = aWandererD + ((RotL64(aPrevious, 30U) + aOrbiterK) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28202U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 30160U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 31878U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32730U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32596U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 58U)) + 479672811032092393U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 35U)) + 18061121631394564425U) + aNonceWordJ;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 13U)) + 14237400452740566065U) + aNonceWordN;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 6723123812257706134U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aIngress, 40U)) + 4247997188026499248U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 23U)) + 1939107415066134869U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aWandererE + RotL64(aCross, 19U)) + 3912640123546395979U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 8295478436553964298U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 35U)) + 3218960600711526885U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5874096203353388890U) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 10294536533673023358U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15561710414949058923U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11268561953904130747U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16693201256788898423U;
            aOrbiterK = RotL64((aOrbiterK * 16291987237693567209U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7550969634681894654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9501647424602245869U;
            aOrbiterB = RotL64((aOrbiterB * 11265865222096866605U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 8881869255994319423U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16770136406906800016U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1782039587385512923U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16185384746435761363U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13841034186650721627U;
            aOrbiterI = RotL64((aOrbiterI * 12000155593277035447U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 15229062695864608309U) + aNonceWordH;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3576122704615303733U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2433987493885779279U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13898167174453181224U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12878032061609524049U;
            aOrbiterF = RotL64((aOrbiterF * 18104665741338251495U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12719156051299028649U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8640980843376950769U;
            aOrbiterA = RotL64((aOrbiterA * 10242616778390983333U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12133332160916004365U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8743563985229104484U;
            aOrbiterG = RotL64((aOrbiterG * 4575129690615054691U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 50U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 53U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aCross, 48U) + aOrbiterF) + RotL64(aOrbiterJ, 3U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 30U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterE, 41U)) + aNonceWordD) + aPhaseFWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + aNonceWordC) + aPhaseFWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterB, 13U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterB, 19U));
            aWandererC = aWandererC + ((((RotL64(aCross, 36U) + RotL64(aOrbiterI, 34U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9566D1164A204073ULL + 0xF423C9A94BF46C64ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x94C7B6BB35EB5A5FULL + 0xBE31C16EABD52560ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD1889C5762A69455ULL + 0x99E920EBD59565B5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAF59D4B05A898605ULL + 0xE48E563DCA40E087ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCFF8C8E5BAECC667ULL + 0xE8B6A3315EB5BD2BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB34F0B9621A8AF41ULL + 0xF7F901F51A98D92DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE84BAAE7DDB9B1BDULL + 0xAA073A3015BA6DA9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8A3D94ACD8B549F9ULL + 0xB6E05028786806E5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x98BCC6D29AFA537FULL + 0xBE8A2F20EA166895ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEB847A458B62BE55ULL + 0xD4DFD7ECCAC8F93FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xADD88A8E4DAE23BDULL + 0xD1865C322FB7985EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE52EFAD12CF19205ULL + 0xDA20187EDBA62251ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB511663B1E64D565ULL + 0xE54B9A4FC8147641ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF8665D3B5B39774BULL + 0xC03C95095CA41702ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9033A9B782C97A59ULL + 0xE8B5CCE688B70E4CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8EF3C4C6D5E8CA0DULL + 0xAB0F9D735D679955ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneB, aSnowLaneC, aSnowLaneD, aInvestLaneD, aWorkLaneA, aInvestLaneB, aInvestLaneC, aWorkLaneB, aInvestLaneA, aExpandLaneA, aFireLaneC, aExpandLaneB, aFireLaneD, aExpandLaneC, aFireLaneA
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneB
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5250U)) & S_BLOCK1], 38U) ^ RotL64(aSnowLaneB[((aIndex + 2669U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 971U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1032U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 4408U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 3224U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = (aWandererK + RotL64(aCross, 57U)) + 6916817163240024692U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 23U)) + 14554930751292077817U) + aNonceWordA;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 34U)) + 1098305064484336101U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (aWandererF + RotL64(aIngress, 41U)) + 12192821172420471527U;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 2435134991707318845U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 1896745368738512624U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 1114996424222923873U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9839135798371512656U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8037967239603177043U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 7848951103759663025U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 15185468738487237432U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4912098316394854543U;
            aOrbiterK = RotL64((aOrbiterK * 3072785550384399929U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13142688607850380888U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4507379759608945839U;
            aOrbiterF = RotL64((aOrbiterF * 2989332387754215967U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7299006009652289342U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5390655277207053627U;
            aOrbiterC = RotL64((aOrbiterC * 10973744708856143715U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6744737023577785725U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15539737698867067285U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 4686092035261336911U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 13329866734681377952U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13284937458969166257U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3965985432462699445U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8695002088915702168U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3858059421620839286U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 9559783727301092937U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 30U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 12U) + RotL64(aOrbiterA, 53U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + aNonceWordC);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 21U)) + aOrbiterB) + aNonceWordD) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterC, 60U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneC
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7589U)) & S_BLOCK1], 14U) ^ RotL64(aSnowLaneC[((aIndex + 7194U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 7713U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneB[((aIndex + 10820U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 7871U)) & S_BLOCK1], 24U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8305U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 7900U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 41U)) + (RotL64(aIngress, 60U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 5576732410244514238U) + aNonceWordE;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 27U)) + 2833808925935929629U) + aNonceWordP;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 3670188682914544792U) + aPhaseHOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 41U)) + 15759072378887814995U) + aNonceWordH;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 51U)) + 13934007231137439994U) + aPhaseHOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 57U)) + 11022225696007690512U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 20U)) + RotL64(aCarry, 3U)) + 16989177104453635790U) + aNonceWordK;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9256930045263527091U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17788596104417068290U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 675554110563253305U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17044369456673337625U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1310908395523250343U;
            aOrbiterG = RotL64((aOrbiterG * 16305084373037705921U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12067065689034065422U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15130844248737512262U;
            aOrbiterB = RotL64((aOrbiterB * 9409499577465934107U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14532689204495587494U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8198147292120244178U;
            aOrbiterF = RotL64((aOrbiterF * 1418356389507740991U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5485494458627163347U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10830008207150307611U;
            aOrbiterA = RotL64((aOrbiterA * 6526039534042499457U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17770065502486618029U) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6397859353395335459U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14286997752368893825U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5128700697381508319U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 7103394110057060499U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5053680689949149633U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 29U)) + aOrbiterB) + aPhaseHWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterK, 60U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 36U) + RotL64(aOrbiterE, 53U)) + aOrbiterH) + aNonceWordD) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 11U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 41U)) + aOrbiterF) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aInvestLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14350U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneA[((aIndex + 15453U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 15162U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15573U)) & S_BLOCK1], 50U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11643U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 40U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = ((aWandererH + RotL64(aCross, 44U)) + RotL64(aCarry, 47U)) + 4634399531433127141U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 16961792729406903200U) + aNonceWordA;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 4105280732301137738U) + aNonceWordK;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 21U)) + 15692013501147331191U) + aNonceWordL;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 29U)) + 1252216715968780587U) + aPhaseHOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aScatter, 5U)) + 7958289043012473752U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 35U)) + 6611577301818896615U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8506226754305949140U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3648813120449403353U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9521367946879238849U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5195245426245535735U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 542948051600803051U;
            aOrbiterF = RotL64((aOrbiterF * 4631106308856448475U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11974253551208964789U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10596463592332655367U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10941161258815714641U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12015129484061440159U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8254944355710109060U;
            aOrbiterA = RotL64((aOrbiterA * 3233697992479357615U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2754858806943915419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5007802002906662779U;
            aOrbiterG = RotL64((aOrbiterG * 15613733948331639723U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6262190752136523216U) + aNonceWordB;
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 10528977986487821428U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 1184258264034585525U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8511097226098211854U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12091864735686692582U;
            aOrbiterD = RotL64((aOrbiterD * 6128140528141411237U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterA, 13U)) + aNonceWordM) + aPhaseHWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + RotL64(aOrbiterG, 50U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterF, 43U)) + aNonceWordI) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 35U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterF, 21U)) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20681U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((aIndex + 21564U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 17122U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21461U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18586U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 58U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 9888431329297626900U) + aNonceWordA;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 35U)) + 2937735167534624403U) + aNonceWordC;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 51U)) + 17626022970343789617U) + aPhaseHOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 5665660859333693743U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 5U)) + 1060537034632076669U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 743777763907175800U) + aNonceWordE;
            aOrbiterF = (aWandererB + RotL64(aCross, 14U)) + 5744905970181808845U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3545351394494002180U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 4877547088414106007U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 5416792889338547109U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11669378338379598445U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2961072441706158212U;
            aOrbiterH = RotL64((aOrbiterH * 2677988507090705371U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 13984945589234919765U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1433097875470903205U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 451996840039906781U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 716415411025451152U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 8542286150858297810U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 9139015340823332449U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12932391786479661299U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 14005503313299177013U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 802663466907819743U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 9382792812676318046U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5138554251079724724U;
            aOrbiterJ = RotL64((aOrbiterJ * 6386016499265056247U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8522380066269546172U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11825536408101906458U;
            aOrbiterC = RotL64((aOrbiterC * 17042837108792016849U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterC, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterD, 19U)) + aNonceWordI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterC, 36U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 51U)) + aNonceWordF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 43U)) + aOrbiterH) + aPhaseHWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 13U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterD, 27U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 52U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aFireLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22171U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 24310U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 21983U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23081U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 23189U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 50U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 9435962834163239322U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 26U)) + 10524704356081318973U) + aPhaseHOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 35U)) + 7403401305665208680U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 7525414805023556493U) + aNonceWordO;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 1116686470029070951U) + aNonceWordM;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 41U)) + 13257612299137802420U;
            aOrbiterH = (aWandererF + RotL64(aCross, 57U)) + 9181543003986598283U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9739384852307501107U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11308402900229016057U;
            aOrbiterF = RotL64((aOrbiterF * 12690186771773188967U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14935167593705272337U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7171824007631943535U;
            aOrbiterK = RotL64((aOrbiterK * 4839974427616194289U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8068411284829563567U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 12350207458513447578U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 813973258659041895U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17039236343991574134U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 18291683592714999632U;
            aOrbiterC = RotL64((aOrbiterC * 7771718817924840713U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6239616841884430968U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10604527977569876774U;
            aOrbiterH = RotL64((aOrbiterH * 6972820410084939637U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1707724300671717658U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3802268808625297647U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11296811630387191563U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9423064323799920219U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 242153923313096551U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12117679073775630197U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 12U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 51U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + aNonceWordE) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aCross, 34U) + aOrbiterK) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 43U)) + aNonceWordB) + aPhaseHWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 43U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterA, 60U)) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30229U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 29178U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 30964U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28744U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneB[((aIndex + 29350U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCross, 14U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 21U)) + 10812151398716051703U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 43U)) + 18202551453336003710U;
            aOrbiterH = ((((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 9434410809101973752U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererI + RotL64(aCross, 53U)) + 12955829998028534045U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 12271740641929640181U) + aNonceWordA;
            aOrbiterI = (aWandererA + RotL64(aScatter, 27U)) + 14009351527014534752U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 14U)) + RotL64(aCarry, 51U)) + 4316296955679133450U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16473324966997442872U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15735123324965019802U;
            aOrbiterH = RotL64((aOrbiterH * 5624078184997601019U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17656375090484080236U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16066325053456055298U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 17912970706985130327U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 12908968778503516903U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12761433987676836197U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1023329467480907925U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12737513138040664509U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14535795767570998392U;
            aOrbiterD = RotL64((aOrbiterD * 15560519667062222269U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14370908061811284364U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7001358781208669795U;
            aOrbiterK = RotL64((aOrbiterK * 11641248025734015835U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7298578161120090849U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10498302152357484629U;
            aOrbiterF = RotL64((aOrbiterF * 13144110412179037175U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 11447343228638006767U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 18284143620422655675U;
            aOrbiterI = RotL64((aOrbiterI * 572862190073605651U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 29U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + aNonceWordB) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterF, 41U)) + aNonceWordE) + aPhaseHWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 60U)) + aOrbiterH) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            aWandererD = aWandererD + (((RotL64(aIngress, 18U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 434U)) & W_KEY1], 14U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 561U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 245U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1160U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 21U)) + (RotL64(aCross, 41U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 36U)) + RotL64(aCarry, 5U)) + 4622023259121087483U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 10253505250223501352U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 27U)) + 17133877904420462669U) + aPhaseAOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aIngress, 51U)) + 6162827793741796700U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 43U)) + 9610986424765907615U;
            aOrbiterG = (aWandererI + RotL64(aCross, 23U)) + 11210747154264753754U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 12U)) + RotL64(aCarry, 53U)) + 16554205219580654546U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 5U)) + 10352576357413766388U) + aPhaseAOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aScatter, 47U)) + 3651845783283479752U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18145542190463500476U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5415609566767162857U;
            aOrbiterI = RotL64((aOrbiterI * 6474184559323816389U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2033734872464201570U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3507213117125813345U;
            aOrbiterG = RotL64((aOrbiterG * 5453058336688881113U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8716253393049851856U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 695984869565941856U;
            aOrbiterB = RotL64((aOrbiterB * 8377921610764044735U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7661578828878284931U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 906654265099155956U;
            aOrbiterA = RotL64((aOrbiterA * 8117625377607536949U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6050049984731254612U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17882717590338190821U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10807367411402733215U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4996521991532815957U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4246460672800604436U;
            aOrbiterC = RotL64((aOrbiterC * 12047466401960824903U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8700148116452518842U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 10039050281847466206U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11884791271239660157U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4513844680425845372U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3037563127442815153U;
            aOrbiterE = RotL64((aOrbiterE * 18363509277992292407U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1005237931570968724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1373258132025712065U;
            aOrbiterH = RotL64((aOrbiterH * 10458020799382532395U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 30U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterG, 30U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterB, 51U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterK, 39U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterE, 20U));
            aWandererI = aWandererI + (((RotL64(aCross, 24U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3854U)) & S_BLOCK1], 14U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3179U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5147U)) & W_KEY1], 42U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5182U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aPrevious, 35U)) + (RotL64(aIngress, 47U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 53U)) + 2974056819475622600U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aScatter, 11U)) + 7345051759236356098U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 46U)) + 12738468816846628882U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 23U)) + 7694520596043297922U) + aPhaseAOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 27U)) + 5530753590015084774U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 3776309161718383105U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 784780304358106404U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 8999942326995036509U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 3U)) + 5194986506064092779U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7920040007459652762U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11311997270710107937U;
            aOrbiterE = RotL64((aOrbiterE * 6227571709361790209U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5365231114813547251U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8630110234623825263U;
            aOrbiterK = RotL64((aOrbiterK * 2735881715888325759U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2358235238039571072U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 18059414891616491807U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17150786106857185467U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14526050556461782864U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6937282036603272474U;
            aOrbiterH = RotL64((aOrbiterH * 14954512365270028029U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10105832250694931310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3884223553012098137U;
            aOrbiterG = RotL64((aOrbiterG * 16340956813003906195U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10385284339549648087U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1257633893341505930U;
            aOrbiterI = RotL64((aOrbiterI * 2669950791270500977U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5528890519572824318U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15664241747527713256U;
            aOrbiterC = RotL64((aOrbiterC * 16670884497088220497U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14264122979415331887U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17985061405540198036U;
            aOrbiterA = RotL64((aOrbiterA * 2729487440173395133U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1663986734997903415U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3706166884286400587U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10549736618301955745U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 42U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 4U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererD = aWandererD + ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 60U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterH, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 24U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 42U) + aOrbiterJ) + RotL64(aOrbiterG, 47U)) + aPhaseAWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7767U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7381U)) & W_KEY1], 42U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5961U)) & W_KEY1], 50U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7540U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6997U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 40U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererK + RotL64(aCross, 19U)) + 3970829908171131502U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 39U)) + 7040283759419531991U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 24U)) + RotL64(aCarry, 11U)) + 11856292169397052901U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 35U)) + 819598588791819022U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 2176451710970866848U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 5U)) + 6454704928613390494U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aScatter, 53U)) + 11792122387218053841U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 57U)) + 9254780213489752211U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 44U)) + RotL64(aCarry, 29U)) + 16591812589999846482U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1471246223935074832U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1424843083106386453U;
            aOrbiterI = RotL64((aOrbiterI * 15020536982657410783U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1856469958050891629U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6331743690452052712U;
            aOrbiterE = RotL64((aOrbiterE * 15327924647897459645U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10351075711345476487U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9518585245330480185U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3792179827396760391U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 17787514620244712033U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14182328067398162557U;
            aOrbiterH = RotL64((aOrbiterH * 18107337388659070197U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12798088948801072444U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9563215159275202323U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7058145016617349141U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9904919772580498232U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16579777394992143043U;
            aOrbiterG = RotL64((aOrbiterG * 10516761340320196661U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6344049286854588503U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3531503618941046788U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10855385899703024105U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11334308840132700377U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11093833870078787770U;
            aOrbiterC = RotL64((aOrbiterC * 16105889714648555755U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3831491136025364271U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12505259454860591372U;
            aOrbiterB = RotL64((aOrbiterB * 6135450888433504093U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 40U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterI, 29U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterA, 14U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterG, 37U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 18U) + aOrbiterC) + RotL64(aOrbiterJ, 41U));
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 21U)) + aOrbiterH) + aPhaseAWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterA, 47U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 58U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 46U) + RotL64(aOrbiterG, 5U)) + aOrbiterH) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 38U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9634U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 9068U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(mSource[((aIndex + 10430U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8682U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10609U)) & W_KEY1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10201U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 34U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aPrevious, 47U)) + 4068921616130916949U;
            aOrbiterA = (aWandererG + RotL64(aCross, 24U)) + 12077715273915151726U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 16047546802670596833U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 29U)) + 9690277462716999763U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 57U)) + 14484814700447992628U) + aPhaseBOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aScatter, 14U)) + 17089267243053958210U) + aPhaseBOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 9138746214446211147U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 10181001536979097045U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 53U)) + 6657458969093373191U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7515983477876590988U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3039935555863947600U;
            aOrbiterI = RotL64((aOrbiterI * 12511160550780270119U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16209389224740851136U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 725253312098083182U;
            aOrbiterB = RotL64((aOrbiterB * 17535989492095522597U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13307041115748941383U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7159572004825238263U;
            aOrbiterH = RotL64((aOrbiterH * 4855009895002398449U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12027236743251643820U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8717826175991286553U;
            aOrbiterJ = RotL64((aOrbiterJ * 1175614802543098451U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4769096034227659937U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11201226563992939616U;
            aOrbiterD = RotL64((aOrbiterD * 15595355978388159931U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17295978531215563256U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11850923890626719833U;
            aOrbiterE = RotL64((aOrbiterE * 3854851059897397075U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14139441565288097706U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 988684899382304485U;
            aOrbiterA = RotL64((aOrbiterA * 11929090869999700891U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6159251276942253175U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4849529993914550651U;
            aOrbiterF = RotL64((aOrbiterF * 18240712676783671317U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6679745455842119497U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15838404437552215214U;
            aOrbiterG = RotL64((aOrbiterG * 17357853511591350887U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 44U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterD, 56U)) + aPhaseBWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 35U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterE, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterE, 60U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12033U)) & S_BLOCK1], 28U) ^ RotL64(aKeyRowReadA[((aIndex + 11353U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11933U)) & W_KEY1], 13U) ^ RotL64(mSource[((aIndex + 12320U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12568U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12324U)) & S_BLOCK1], 46U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12417U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 56U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 18U)) + RotL64(aCarry, 57U)) + 11410829607777684449U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 7502698839700975347U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 51U)) + 13267685058252106173U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 47U)) + 238242706996630625U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 13U)) + 8184695499511454281U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 41U)) + 12767823220461985403U;
            aOrbiterA = (aWandererD + RotL64(aCross, 27U)) + 12293198423143850330U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 23U)) + 11149495229952495939U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 19U)) + 7556992689338382800U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3431338808774134649U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16863099140844995099U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 752376661101787919U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17872458049880677604U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16760153457252546974U;
            aOrbiterG = RotL64((aOrbiterG * 11225037229069712805U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3115544493537438408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4359882942759752958U;
            aOrbiterA = RotL64((aOrbiterA * 561477566995575801U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 13387113067202396536U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12955690074544490161U;
            aOrbiterE = RotL64((aOrbiterE * 12449941770827974511U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 15614054443728226807U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1939441328066616114U;
            aOrbiterF = RotL64((aOrbiterF * 4484917074808974359U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4599016263007782537U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9962305629016158048U;
            aOrbiterD = RotL64((aOrbiterD * 1496184427500037279U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8428467674122750557U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3938884087806393439U;
            aOrbiterI = RotL64((aOrbiterI * 12810531094050481761U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6018636830758044658U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1510372000641305416U;
            aOrbiterJ = RotL64((aOrbiterJ * 9002834928626918247U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17592782466215337843U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8119921507606870360U;
            aOrbiterC = RotL64((aOrbiterC * 1299795061644535485U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 48U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 3U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterA, 52U));
            aWandererC = aWandererC + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterE, 29U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterG, 47U));
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterI, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15588U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneA[((aIndex + 15323U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15665U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14429U)) & W_KEY1], 19U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14712U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13850U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15476U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 4U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererK + RotL64(aCross, 43U)) + 2177539223979303669U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 58U)) + RotL64(aCarry, 43U)) + 3962004686551521471U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 21U)) + 8457602312617147662U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 18011802451816510632U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 9046101759168876832U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 29U)) + 11135620637431969597U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 53U)) + 15913029940697999701U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 39U)) + 16304193109948135982U) + aPhaseBOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 10U)) + 13208892298820080981U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4182377898949419225U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13970137023071326151U;
            aOrbiterF = RotL64((aOrbiterF * 9075061559681739865U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8402396284835248583U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8859190834060657829U;
            aOrbiterC = RotL64((aOrbiterC * 13552418608113716117U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9760005337757990392U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14108277760135744897U;
            aOrbiterI = RotL64((aOrbiterI * 4474681104256093885U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12226316121949012350U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3456392186754113960U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8704729827929941215U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 5004087958637038973U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7176881295123125567U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15272157962928021009U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10889800478505074438U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13728832441482547824U;
            aOrbiterK = RotL64((aOrbiterK * 17588477761978646139U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17345665880706866772U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 301139993853297566U;
            aOrbiterG = RotL64((aOrbiterG * 5812445396758354505U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2061389844760610160U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13631862266139238355U;
            aOrbiterH = RotL64((aOrbiterH * 143613352104722701U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10767186080827509622U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4893486019456886013U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5194746459545610901U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 36U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 19U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 48U) + aOrbiterI) + RotL64(aOrbiterJ, 5U));
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 46U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 27U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 35U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 34U) + aOrbiterH) + RotL64(aOrbiterF, 23U));
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 56U)) + aOrbiterB) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17117U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 18525U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(mSource[((aIndex + 18849U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 18257U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17432U)) & W_KEY1], 35U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18071U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 19008U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 18U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererI + RotL64(aScatter, 57U)) + 9914837590440975587U;
            aOrbiterI = (((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 6706125076401958051U) + aPhaseCOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 16570817772679258409U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 34U)) + 6843705658115186948U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 19U)) + 16099930446791572351U) + aPhaseCOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 5420550009556030459U;
            aOrbiterC = (aWandererG + RotL64(aCross, 11U)) + 5729549069420177477U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 53U)) + 15590601126188675834U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 28U)) + 13044027390998620029U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11068338135659636772U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6584988841809544332U;
            aOrbiterE = RotL64((aOrbiterE * 1683336180438945439U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8516813219883915404U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10647314042912492785U;
            aOrbiterK = RotL64((aOrbiterK * 15559481057047148785U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 201691689889605304U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15512161798401184003U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11473219183982564709U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3883760518944464145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13861805129175491145U;
            aOrbiterI = RotL64((aOrbiterI * 17194438894492581181U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12019138626550801486U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13030350224959652248U;
            aOrbiterD = RotL64((aOrbiterD * 11724200983306280107U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2643807255422544248U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4127143302485631794U;
            aOrbiterC = RotL64((aOrbiterC * 5441038881111578487U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14602951930809633069U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4555737199162278494U;
            aOrbiterB = RotL64((aOrbiterB * 12415825635220991865U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6343143902997169834U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10404783711336491985U;
            aOrbiterA = RotL64((aOrbiterA * 6235474458879439079U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 7406959231434835393U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6684368109277850196U;
            aOrbiterF = RotL64((aOrbiterF * 8760360417572331159U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 14U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 10U)) + aOrbiterC) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterK, 41U));
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterF, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterK, 19U));
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterC, 35U));
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterD, 29U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterC, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20896U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 21074U)) & S_BLOCK1], 48U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21628U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 19794U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21495U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20685U)) & W_KEY1], 46U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20654U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20209U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 12669015908335980355U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 28U)) + RotL64(aCarry, 53U)) + 5438715179868613192U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 13172104448184536460U;
            aOrbiterK = (aWandererG + RotL64(aCross, 21U)) + 13421421503244744803U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 11U)) + 13327113302994856582U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 47U)) + 4671768205922454413U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 57U)) + 5355759962838579929U) + aPhaseCOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aScatter, 40U)) + 6691720614265406851U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 53U)) + 7063906424700911378U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17328616394166672263U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1542940602574207068U;
            aOrbiterD = RotL64((aOrbiterD * 8981679306319627975U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7203866278803132454U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 993485696233139264U;
            aOrbiterC = RotL64((aOrbiterC * 11609009908810366447U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15659679028507488331U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 18321361454094675842U;
            aOrbiterE = RotL64((aOrbiterE * 3966860765622641843U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9633319822696783352U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3496559332232402963U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7772060229838162977U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 1918349708324205526U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7701088402761359134U;
            aOrbiterH = RotL64((aOrbiterH * 9649485438465644795U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6006824348814439686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18088375375347012557U;
            aOrbiterK = RotL64((aOrbiterK * 12801082943086128385U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12816533373478543584U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17951880253818836433U;
            aOrbiterB = RotL64((aOrbiterB * 8935839101517220201U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11311632024372748238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9891349164779752351U;
            aOrbiterJ = RotL64((aOrbiterJ * 11405973752233193209U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 711130292000437038U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17818800917771709681U;
            aOrbiterI = RotL64((aOrbiterI * 10567029732245868263U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 46U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 39U));
            aWandererB = aWandererB + ((RotL64(aIngress, 34U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterB, 47U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterE, 52U)) + RotL64(aCarry, 27U)) + aPhaseCWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 43U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterE, 13U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterI) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23622U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadA[((aIndex + 23001U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 21939U)) & W_KEY1], 43U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22407U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23384U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24266U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22407U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneB[((aIndex + 22509U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCarry, 53U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 5906639480605353429U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 23U)) + 5293518570213287605U) + aPhaseCOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 39U)) + 15383185501428521377U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 15364072512743978902U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 48U)) + RotL64(aCarry, 11U)) + 4525473357144014271U) + aPhaseCOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 19U)) + 10400911938125603074U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 53U)) + 16417506293824627550U;
            aOrbiterG = (aWandererE + RotL64(aCross, 11U)) + 2419329331753341815U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 44U)) + 14929222427923332069U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16771573504983922586U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1863466450051787622U;
            aOrbiterJ = RotL64((aOrbiterJ * 2585626547126027053U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12895350137096692415U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3700979086526298327U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10279730254867618193U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1977099106211282426U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6144698304096915742U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5039822990560519609U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3858895556659724975U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1283646340363435327U;
            aOrbiterG = RotL64((aOrbiterG * 11622421841377018069U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 6240532051889108891U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 757364889381634634U;
            aOrbiterB = RotL64((aOrbiterB * 943852137901972945U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5272945693977418174U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6850528198786172283U;
            aOrbiterI = RotL64((aOrbiterI * 1966383079897679953U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14431587733859573714U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16124590257870999553U;
            aOrbiterA = RotL64((aOrbiterA * 7755796211433191143U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14912695018110241411U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11098623474413346520U;
            aOrbiterD = RotL64((aOrbiterD * 15167688959990872051U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3484847683376368686U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2295388097292719800U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1240808318176106909U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 26U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterB, 22U)) + RotL64(aCarry, 3U)) + aPhaseCWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterG, 39U));
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 57U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterA, 3U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 30U)) + aOrbiterI) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterH, 13U));
            aWandererE = aWandererE + (((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 28U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25622U)) & S_BLOCK1], 40U) ^ RotL64(aKeyRowReadA[((aIndex + 26061U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25294U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26957U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24987U)) & W_KEY1], 50U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25223U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27250U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneB[((aIndex + 26999U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 6U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 6U)) + 3248574644570178787U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 4506961512959200024U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 8423739774540738590U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 11U)) + 6593975869641735337U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 57U)) + 16441716090557369103U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 7936601450453207914U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 47U)) + 13333752583560167065U) + aPhaseDOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 53U)) + 8013703284795432973U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 30U)) + 2349852779887439236U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5318539364763284138U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11450957608502944376U;
            aOrbiterI = RotL64((aOrbiterI * 1957880366707810635U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9058992558327552687U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 632095686920230926U;
            aOrbiterC = RotL64((aOrbiterC * 12460364388358520799U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14734218428913777098U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16344357661370784442U;
            aOrbiterF = RotL64((aOrbiterF * 15049472842002138369U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2981145363531184308U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14176472085175714494U;
            aOrbiterG = RotL64((aOrbiterG * 2584623327412130939U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11198457590069700889U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 952584436750426828U;
            aOrbiterK = RotL64((aOrbiterK * 1165713888651280355U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4311591763498985972U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16194341833989936369U;
            aOrbiterJ = RotL64((aOrbiterJ * 9997934560195932575U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7560794022401107431U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10683789740265711603U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15637823045351977883U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11614366395125937178U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10750771385100564416U;
            aOrbiterH = RotL64((aOrbiterH * 4987921274272444283U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 2934697034132204529U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4646873794658020363U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10555456865641580175U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 20U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 5U));
            aWandererI = aWandererI + ((RotL64(aCross, 10U) + aOrbiterI) + RotL64(aOrbiterF, 11U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 30U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + aPhaseDWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 48U) + aOrbiterC) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterC, 35U)) + aPhaseDWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterF, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28862U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneD[((aIndex + 28544U)) & S_BLOCK1], 40U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29461U)) & W_KEY1], 13U) ^ RotL64(aFireLaneC[((aIndex + 29686U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27504U)) & W_KEY1], 40U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28836U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28309U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27746U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 10U)) + (RotL64(aCarry, 27U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererG + RotL64(aPrevious, 3U)) + 8767379393098711499U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 7168159491580816433U) + aPhaseDOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aCross, 52U)) + 9879279829061883406U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 23U)) + 10537167136053399303U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 2839070018069188936U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 13844278063968429732U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 43U)) + 11278946626186474646U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 39U)) + 11798425216660557799U) + aPhaseDOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 56U)) + 7618446090703335192U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 695423597006983660U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14344728202803488813U;
            aOrbiterA = RotL64((aOrbiterA * 5168825904902285909U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11656100506575697086U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 10384358779985773937U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 247494692039140973U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17585001605131977341U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9964478171465522911U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13484044854790175315U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2710943171829692624U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17809072853457153057U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16341884203303271365U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12814092033910687774U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1743186323268668740U;
            aOrbiterC = RotL64((aOrbiterC * 11150822630624332557U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10750472346626754704U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15925901217078035356U;
            aOrbiterJ = RotL64((aOrbiterJ * 9276504171291801637U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2569102106359362359U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8868261301410769739U;
            aOrbiterG = RotL64((aOrbiterG * 3662495603133918101U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2143691008373582476U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10606616796243205921U;
            aOrbiterH = RotL64((aOrbiterH * 15794414817813485643U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16258070651850746855U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11720192793689633315U;
            aOrbiterE = RotL64((aOrbiterE * 14475623219460678021U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 4U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterG, 12U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 47U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 21U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 3U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 35U));
            aWandererE = aWandererE + (((RotL64(aScatter, 30U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 26U)) + aOrbiterI) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 57U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30443U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32213U)) & W_KEY1], 38U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32633U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31823U)) & S_BLOCK1], 28U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32280U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 31222U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 18U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 7893287783892523139U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 10257331997383491153U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 36U)) + 14562226733652231753U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 53U)) + 14320342577110737851U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 27U)) + 9816717579822880756U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 9558926960095881953U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 11U)) + 9230371862654338324U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 4U)) + 6414274291252913420U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 47U)) + 13868546184398350849U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16940736952569949038U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2866957764814864371U;
            aOrbiterG = RotL64((aOrbiterG * 3554702178644797003U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7916721976073979724U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1602444214978842275U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11072503711308122385U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9529061385251008037U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8402775110887376588U;
            aOrbiterE = RotL64((aOrbiterE * 13980225144628227381U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15003592180290390713U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14195681406520825751U;
            aOrbiterC = RotL64((aOrbiterC * 11455000833788877217U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3263577002367714202U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12019422062655581928U;
            aOrbiterJ = RotL64((aOrbiterJ * 5002313835338447799U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8508638054582582917U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6536618106353552880U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6233964121117511885U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9654542989321430868U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7019594782797863244U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1234877854354279981U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8256061220727519919U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9232754129467036130U;
            aOrbiterH = RotL64((aOrbiterH * 17556001874302369781U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5608829951337740378U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12632120498473345701U;
            aOrbiterF = RotL64((aOrbiterF * 6994794653605831925U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 50U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 13U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 18U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterF, 47U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 53U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 4U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterC, 23U)) + aOrbiterG) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneC, aInvestLaneD, aFireLaneB, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2038U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 2816U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3820U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2700U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5138U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererH + RotL64(aIngress, 3U)) + 3199575576585871314U;
            aOrbiterH = (aWandererA + RotL64(aCross, 19U)) + 2533378188975571824U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 6819782112558312658U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 12690060987724798497U;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 7088375139715629606U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aCross, 44U)) + 17785618677423695666U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aPrevious, 11U)) + 1714999280296491277U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17611338506932491624U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6475727359297421201U;
            aOrbiterK = RotL64((aOrbiterK * 15133348244242438069U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2347744591204119530U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2739317903351401068U;
            aOrbiterJ = RotL64((aOrbiterJ * 15435029315209475631U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8663535261373274338U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8205245127823536479U;
            aOrbiterG = RotL64((aOrbiterG * 13857005110466856439U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8916510616749754516U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 3944805940148512932U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18082271583211389701U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14094751253118853302U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14094299829196076311U;
            aOrbiterF = RotL64((aOrbiterF * 6370012560657108493U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3940673811518673802U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3015106523254484839U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9655401190755573379U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15404103131982599922U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1828655763233900875U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13024358077740310049U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 39U));
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 21U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aCross, 4U) + aOrbiterI) + RotL64(aOrbiterH, 48U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneC
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8211U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((aIndex + 10784U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9383U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6848U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10748U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U)) + (RotL64(aPrevious, 26U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 1042610313571524121U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 3505725321008825582U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 21U)) + 12584654563843782991U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 35U)) + 6645399144515770935U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 60U)) + 3608978423753715584U) + aPhaseEOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 8089198857670370983U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 41U)) + 15207251813516399879U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9579268660105824516U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16055044469473802812U;
            aOrbiterD = RotL64((aOrbiterD * 2269649280637188723U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 583811872609805949U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7027491967970873942U;
            aOrbiterB = RotL64((aOrbiterB * 12686754713465826139U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 18256061823189677508U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12708429127816136937U;
            aOrbiterJ = RotL64((aOrbiterJ * 12593886633108075321U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12169216645156306078U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12694325407567795065U;
            aOrbiterI = RotL64((aOrbiterI * 3711789483877261899U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16109994660203297503U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4234704064165718913U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 730085881474787681U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14119541943554602878U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8777769004811352951U;
            aOrbiterC = RotL64((aOrbiterC * 2556957257736134223U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15642663488392549609U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11594468530833278624U;
            aOrbiterH = RotL64((aOrbiterH * 6639306656361601143U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 60U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 23U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 29U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 4U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aCross, 10U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterB, 53U)) + aPhaseEWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneB
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13979U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 14266U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 15695U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15714U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16222U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 15657U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aPrevious, 23U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 4068921616130916949U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 43U)) + 12077715273915151726U) + aPhaseEOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 16047546802670596833U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 37U)) + 9690277462716999763U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 14484814700447992628U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 29U)) + 17089267243053958210U;
            aOrbiterH = (aWandererK + RotL64(aCross, 52U)) + 9138746214446211147U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10181001536979097045U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6657458969093373191U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4311019792293202747U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7515983477876590988U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3039935555863947600U;
            aOrbiterD = RotL64((aOrbiterD * 12511160550780270119U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16209389224740851136U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 725253312098083182U;
            aOrbiterC = RotL64((aOrbiterC * 17535989492095522597U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 13307041115748941383U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7159572004825238263U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4855009895002398449U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12027236743251643820U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8717826175991286553U;
            aOrbiterJ = RotL64((aOrbiterJ * 1175614802543098451U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4769096034227659937U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11201226563992939616U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15595355978388159931U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17295978531215563256U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11850923890626719833U;
            aOrbiterA = RotL64((aOrbiterA * 3854851059897397075U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 27U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 30U) + aOrbiterC) + RotL64(aOrbiterB, 57U)) + aPhaseEWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 48U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterA, 3U)) + aPhaseEWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 41U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterD, 21U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20956U)) & S_BLOCK1], 28U) ^ RotL64(aInvestLaneC[((aIndex + 18550U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 21147U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18122U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17158U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17897U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererA + RotL64(aCross, 53U)) + 16016931609704150191U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 14511433515861302636U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 35U)) + 11691237442613269593U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 27U)) + 16383220587320484649U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 14U)) + RotL64(aCarry, 41U)) + 14293015313458219868U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aIngress, 5U)) + 4407695248205526670U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 1158323195324398372U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6577683409653864555U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 171080079472863843U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3063978974927752653U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5766333425872228205U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 16173508656917582960U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12187968015372936695U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11781450063402219202U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13033139686637576694U;
            aOrbiterH = RotL64((aOrbiterH * 4331137994135472025U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 4006310759400926020U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13156817947481574467U;
            aOrbiterD = RotL64((aOrbiterD * 563189239835001483U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12791290558893516411U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 989729955679243234U;
            aOrbiterI = RotL64((aOrbiterI * 8757228712495095017U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 838379839663022790U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2830743864262313606U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10173947177104802797U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2146646527331684652U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4629168181742174906U;
            aOrbiterE = RotL64((aOrbiterE * 9046124907945045131U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 22U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 51U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 43U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterI, 58U));
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 35U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 54U) + aOrbiterI) + RotL64(aOrbiterG, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 39U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27080U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 24084U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25331U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23590U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 24806U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 21943U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 16651241552253078315U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 43U)) + 4558144676982478003U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 8814884320080367550U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 16011579668555672117U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 21U)) + 4738918668759862438U) + aPhaseEOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 53U)) + 12526083125540985108U;
            aOrbiterC = (aWandererG + RotL64(aCross, 4U)) + 8048723561746000552U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1082218464034639039U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8432043246965946816U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7801965585991025451U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9982080524048636852U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6720069955755215919U;
            aOrbiterB = RotL64((aOrbiterB * 1025046364205332059U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1019035028070247757U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7360619079463870467U;
            aOrbiterG = RotL64((aOrbiterG * 6623074813047915863U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10893918488381348474U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1390297670907738019U;
            aOrbiterE = RotL64((aOrbiterE * 11909657437658597735U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12512200589031203480U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14741471280748399540U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3012135242889901095U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8543897248359826770U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8545972622733791272U;
            aOrbiterC = RotL64((aOrbiterC * 11793879362775346821U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7049384618581928664U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14730773807906925408U;
            aOrbiterI = RotL64((aOrbiterI * 10711566871536755073U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterB, 35U));
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 56U)) + aOrbiterB) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 3U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterC, 23U));
            aWandererB = aWandererB + (((RotL64(aCross, 34U) + RotL64(aOrbiterJ, 41U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterI, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererG, 18U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28862U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 30780U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27432U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29857U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32383U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 32044U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 11U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aCross, 23U)) + 12690502671561165478U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 17519943923428102801U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 6U)) + 10705515807975331385U) + aPhaseEOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 16586447272278538179U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 35U)) + 8006560996840971798U;
            aOrbiterK = (aWandererC + RotL64(aCross, 13U)) + 12928600185788857701U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 14240723153798267172U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8636219177994872072U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7586790235186467512U;
            aOrbiterB = RotL64((aOrbiterB * 15052686382507614169U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1103807034179512424U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7547526530239498693U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3360295583636013509U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8380239679344786397U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 5690809173787433519U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5354724308093372953U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8390902801141804609U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3507306189192059486U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18336280496510253103U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6190745292098482871U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8065418693975056902U;
            aOrbiterA = RotL64((aOrbiterA * 6414621418430102589U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12111755051718111803U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7605877769709909297U;
            aOrbiterK = RotL64((aOrbiterK * 17525248694315944599U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5969794501112646237U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5127559299360591476U;
            aOrbiterI = RotL64((aOrbiterI * 4521563633438853069U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 19U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 60U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 5U)) + aOrbiterH) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneA, aSnowLaneA, aExpandLaneD, aInvestLaneB, aSnowLaneB, aInvestLaneD, aWorkLaneA, aExpandLaneB, aWorkLaneB, aInvestLaneA, aWorkLaneC, aInvestLaneC
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneA backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1541U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 1477U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 1858U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3495U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3772U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 118U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 52U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererH + RotL64(aScatter, 47U)) + 17470880031634374199U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 35U)) + 757565846006937746U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 41U)) + 9419282475801345674U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 39U)) + 2014248014107898196U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 15113928519446490441U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 10U)) + 7346126964886259935U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 5594123113093162359U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 5659237263369402005U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 21U)) + 11565709683423969703U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 51U)) + 16782863743534856287U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aPrevious, 6U)) + 13499100900072115907U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11414447651044205242U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7545993795121430538U;
            aOrbiterC = RotL64((aOrbiterC * 10758488381206257261U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11778229237616454988U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2544793391976514665U;
            aOrbiterI = RotL64((aOrbiterI * 4021060413798523299U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9972156716619459164U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17651030383827445664U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6742914240706775487U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17439147296849134543U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10021926927948343656U;
            aOrbiterK = RotL64((aOrbiterK * 18139540407315440909U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9309867875882669289U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14951424455944346337U;
            aOrbiterA = RotL64((aOrbiterA * 10569523948169951309U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2166343974068770659U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11386993629011562026U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3091639433512536097U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5747849744680120960U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4019290369160113026U;
            aOrbiterD = RotL64((aOrbiterD * 5567515306039646735U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3820540009554769592U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8210747198363020939U;
            aOrbiterJ = RotL64((aOrbiterJ * 16215133106542452509U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3006494852696036003U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2736305345451919450U;
            aOrbiterB = RotL64((aOrbiterB * 11993452696344358247U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6148431711118275178U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6986633012691940738U;
            aOrbiterG = RotL64((aOrbiterG * 15672039482523804893U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7837859154831245165U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17470880031634374199U;
            aOrbiterE = RotL64((aOrbiterE * 2153299273348512243U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 23U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterI, 5U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterH, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterE, 28U));
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterK, 23U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterC, 37U)) + aPhaseFWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterD, 42U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aIngress, 20U) + aOrbiterA) + RotL64(aOrbiterB, 3U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 13U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneD
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10390U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneC[((aIndex + 5685U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7804U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7215U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7611U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6721U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 10892U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererA + RotL64(aIngress, 5U)) + 6361545377408870615U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 29U)) + 2967245486744774933U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 3U)) + 3836634268482850139U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 7691642115360086297U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 47U)) + 16479280384178279281U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 22U)) + 2901468732552539249U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 2600353867755647475U;
            aOrbiterC = (aWandererD + RotL64(aCross, 43U)) + 5666596904781510956U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 35U)) + 16108791609267427553U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 18U)) + RotL64(aCarry, 11U)) + 8389926875737312112U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 41U)) + 1689501721163024426U) + aPhaseFOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11721701506949917719U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3963842745030140473U;
            aOrbiterK = RotL64((aOrbiterK * 6692473494944919373U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8510538243472109368U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 18281865214102080387U;
            aOrbiterE = RotL64((aOrbiterE * 1351546966368884609U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2259725140963665123U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11652011949557979650U;
            aOrbiterC = RotL64((aOrbiterC * 11260100762113295037U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 1116085424226174473U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4725260319270802912U;
            aOrbiterD = RotL64((aOrbiterD * 4697109059565450269U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7348945429843437036U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1249234309180653260U;
            aOrbiterH = RotL64((aOrbiterH * 3136745255820405881U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12463505532573389603U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2304125977906510386U;
            aOrbiterG = RotL64((aOrbiterG * 9960816714791454421U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2178037443783425551U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11712110130079307683U;
            aOrbiterB = RotL64((aOrbiterB * 9797864956200779505U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10703510612147312252U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 18155460326242413483U;
            aOrbiterI = RotL64((aOrbiterI * 6903953708987478723U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5753486645345036069U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2314216774606770444U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14002639533287566667U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9662599462788305323U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3805101172359199209U;
            aOrbiterJ = RotL64((aOrbiterJ * 10669315962181581543U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 1073926575064224947U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6361545377408870615U;
            aOrbiterF = RotL64((aOrbiterF * 10685650563722188837U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 41U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 54U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterF, 43U)) + aPhaseFWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterG, 27U));
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterE, 60U));
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 57U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 19U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aCross, 58U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneD
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 16077U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 11166U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 15987U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13051U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((aIndex + 14098U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 10U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 13583136155674166402U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 51U)) + 12830472187484919497U) + aPhaseFOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 29U)) + 18081197909484522509U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 8680634051297891550U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 39U)) + 13939998767458656823U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 14U)) + 1795730579103692594U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 21U)) + 17369751719734069999U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 23U)) + 224769585901248068U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 4133547085925268180U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 19U)) + 7022512056309567391U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 44U)) + 10319484359046945495U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10483878349412282069U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6481381149199985736U;
            aOrbiterJ = RotL64((aOrbiterJ * 9701719367082506253U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13721077228796934509U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9704818014314175007U;
            aOrbiterG = RotL64((aOrbiterG * 760445624027740287U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6253040047758584339U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16890211690273641226U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5622534399866057841U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6216227831265032436U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2023609047004658739U;
            aOrbiterE = RotL64((aOrbiterE * 3252332895698310147U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9201669637050388263U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 5106927540934338576U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6368134569042291431U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10080368957861445998U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10784789383436485808U;
            aOrbiterC = RotL64((aOrbiterC * 3794918350254445939U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15426339824951793026U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17637144549368340331U;
            aOrbiterI = RotL64((aOrbiterI * 10971293914614704441U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9941300382181962134U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8118046374121322097U;
            aOrbiterD = RotL64((aOrbiterD * 8481945819050983127U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5138086185042567633U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7279942739248982986U;
            aOrbiterB = RotL64((aOrbiterB * 12911998308338410917U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 12135610639038562853U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12945353426409788798U;
            aOrbiterH = RotL64((aOrbiterH * 7434977715954413699U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7534876598022096222U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13583136155674166402U;
            aOrbiterK = RotL64((aOrbiterK * 8194058098043157015U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 34U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + aPhaseFWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 5U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterI, 42U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 51U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 23U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 48U) + aOrbiterI) + RotL64(aOrbiterH, 21U));
            aWandererF = aWandererF + (((RotL64(aCross, 21U) + RotL64(aOrbiterE, 18U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 53U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aExpandLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19911U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneA[((aIndex + 17337U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16534U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17039U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 16849U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 14U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererC + RotL64(aCross, 10U)) + 10915618884692072446U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 51U)) + 12634922308499254909U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 35U)) + 6533934734564499389U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 6744203303756105181U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 13086782386652045658U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 29U)) + 5693840533331397822U;
            aOrbiterF = (aWandererB + RotL64(aCross, 57U)) + 1803663542535024611U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 43U)) + 3597219300593287708U) + aPhaseFOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 41U)) + 1429753448204448904U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 60U)) + RotL64(aCarry, 41U)) + 17229017825587322715U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 23U)) + 1137574712801062932U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2401991077004083378U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1332473247826139292U;
            aOrbiterH = RotL64((aOrbiterH * 15029831858261506447U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11730946340796899885U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 15319163439700390962U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1349242001887975499U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4744141870145159917U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6067132201862688684U;
            aOrbiterC = RotL64((aOrbiterC * 6046100687757836027U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14991509179286371800U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4342608825699398682U;
            aOrbiterD = RotL64((aOrbiterD * 10240526103933275875U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3727521409410742075U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3302027219498304367U;
            aOrbiterB = RotL64((aOrbiterB * 12153634588200479559U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6039539483340398858U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2902581519976937051U;
            aOrbiterE = RotL64((aOrbiterE * 2057584328877854239U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 12332784713738947242U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13761272577223712786U;
            aOrbiterA = RotL64((aOrbiterA * 14930145045480030821U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2947946397617043735U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11107014023853644521U;
            aOrbiterJ = RotL64((aOrbiterJ * 15030903626191481831U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6212403196992771516U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16107261731677426470U;
            aOrbiterI = RotL64((aOrbiterI * 13764822942405295129U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8414111492161335472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3625937496991123221U;
            aOrbiterF = RotL64((aOrbiterF * 1736741235159600739U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5466667339391480293U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10915618884692072446U;
            aOrbiterK = RotL64((aOrbiterK * 14719282928172086707U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 56U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterH, 5U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterF, 37U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 42U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterI, 51U));
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 23U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterK, 29U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 18U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 6U) + aOrbiterJ) + RotL64(aOrbiterB, 47U));
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 53U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 39U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererH, 14U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aInvestLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25996U)) & S_BLOCK1], 54U) ^ RotL64(aSnowLaneB[((aIndex + 24399U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24787U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22356U)) & S_BLOCK1], 20U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 24698U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 34U)) + (RotL64(aIngress, 3U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererB + RotL64(aPrevious, 6U)) + 9220392006207660113U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 11305018553489132882U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 5860373868073513684U;
            aOrbiterF = (aWandererD + RotL64(aCross, 3U)) + 12319586170883987589U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 47U)) + 14072333614354649021U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 19U)) + 9332158529453194608U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 57U)) + 3860569321145958686U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 54U)) + 8119005668901240093U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 13U)) + 13918259792880333239U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 29U)) + 6938856216758228704U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 43U)) + 3960905839118710604U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6043879193734253929U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15691425268831319195U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7189195135654636271U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14912209933584715274U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16180183395910618923U;
            aOrbiterK = RotL64((aOrbiterK * 3942858974766467849U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4966642362507707776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6962226782462822861U;
            aOrbiterI = RotL64((aOrbiterI * 3647802407741095419U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12409120845092026295U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2302946450253872465U;
            aOrbiterD = RotL64((aOrbiterD * 7099576330777297911U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16118304388937163838U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15968419034359049422U;
            aOrbiterF = RotL64((aOrbiterF * 11736207775827080165U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17098982091525008231U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10298979200690822062U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12620028874653521945U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 552826643694256437U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11786560990790695378U;
            aOrbiterE = RotL64((aOrbiterE * 11190309640069208311U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13730399230389329793U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17614226859252305432U;
            aOrbiterA = RotL64((aOrbiterA * 2640019643570222977U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1062738267846296283U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13959480457644980835U;
            aOrbiterC = RotL64((aOrbiterC * 1194145909157002977U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4635071137794189167U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13374502212707796180U;
            aOrbiterG = RotL64((aOrbiterG * 129680788767298945U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11479902881487238033U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9220392006207660113U;
            aOrbiterJ = RotL64((aOrbiterJ * 1437457810224888809U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 22U);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 13U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterD, 43U));
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 26U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterK, 21U));
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterH, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterC, 37U));
            aWandererB = aWandererB + ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 23U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterB, 30U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32688U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((aIndex + 31469U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 31107U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31739U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 31621U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 52U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 8866844335448071821U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 51U)) + 15159698739856430085U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 53U)) + 9582805772989594633U;
            aOrbiterD = (aWandererD + RotL64(aCross, 21U)) + 1438538239931588373U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 43U)) + 10862044156620436139U) + aPhaseFOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 13682173320058164615U) + aPhaseFOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aScatter, 29U)) + 8351013291045977592U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 57U)) + 15777857431516633916U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 16178966745333885377U;
            aOrbiterI = (aWandererF + RotL64(aCross, 46U)) + 9031889187993001617U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 23U)) + 6308472367425865347U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 642109145903321046U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9186268569255318035U;
            aOrbiterA = RotL64((aOrbiterA * 10714674348507516749U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6091345356803675860U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13218507921880873749U;
            aOrbiterJ = RotL64((aOrbiterJ * 15415157927185637717U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4266652275234474616U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4391422098164506195U;
            aOrbiterC = RotL64((aOrbiterC * 17634679403195085867U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5160682323243635577U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 10351728852161347404U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11105410036471745951U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 3950932176454814023U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9536466386833427441U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18064984243491293435U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9927425919978776529U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6819384090527481081U;
            aOrbiterK = RotL64((aOrbiterK * 18032965969184368561U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1646274931424218507U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16166524473976135097U;
            aOrbiterB = RotL64((aOrbiterB * 11672192658072663849U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11252501968059485262U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16847854447987609067U;
            aOrbiterI = RotL64((aOrbiterI * 6326299154627028295U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16723218285355036446U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13870211254243048975U;
            aOrbiterF = RotL64((aOrbiterF * 10203222183774624097U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11401147367366049493U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4266628469244269926U;
            aOrbiterD = RotL64((aOrbiterD * 2409934496621365221U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11578385782347296942U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8866844335448071821U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6456956795450036515U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 48U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterG, 21U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 53U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterF, 60U));
            aWandererF = aWandererF + ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 29U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 13U));
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 39U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterI, 11U));
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 28U) + aOrbiterE) + RotL64(aOrbiterK, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 21U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3115U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((aIndex + 1899U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 3277U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4189U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2968U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 252U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 19U)) + (RotL64(aIngress, 47U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 18U)) + RotL64(aCarry, 29U)) + 13481227414590594621U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 53U)) + 17425964381118918026U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aScatter, 3U)) + 4792004356135956581U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 11926849936000639098U) + aPhaseGOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 990697329347742142U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9307721505373076588U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17605732738841908719U;
            aOrbiterF = RotL64((aOrbiterF * 13123627214143336281U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13110764518634187439U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17970109897810645911U;
            aOrbiterK = RotL64((aOrbiterK * 10395095143998920213U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10273133817644703654U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11239046688920468137U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5197802934333553327U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8355821483275763145U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15522151127786049345U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4844278537850520413U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5381663179722418112U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9551368011768104906U;
            aOrbiterG = RotL64((aOrbiterG * 14202470972121732997U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 38U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 27U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterC, 3U)) + aPhaseGWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 18U) + aOrbiterC) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15116U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 11350U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 8769U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9322U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8211U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13505U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 2558105147674438050U) + aPhaseGOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 15856662514774702561U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 3U)) + 13346869226246584582U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 7632111846116243973U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 20U)) + 2102101361626976279U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5605968705067851563U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6842483186584326681U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11344798544990575365U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5559797213819425064U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12422313931331576759U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7399849122565913401U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2751024420047872601U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11031320239359798610U;
            aOrbiterC = RotL64((aOrbiterC * 8607639453141148025U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14366375309473793217U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11971479429768505316U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10063001532313098203U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3947595951884469542U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17882767922372770896U;
            aOrbiterB = RotL64((aOrbiterB * 3361906348965810211U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 46U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 27U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 40U) + aOrbiterB) + RotL64(aOrbiterD, 38U));
            aWandererB = aWandererB + ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterF, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23389U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneA[((aIndex + 21128U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 19655U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18932U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20325U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 17406U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 21U)) + 3238389262925516513U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 12381787182611386995U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 41U)) + 7883885539305181549U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 1185413044597727092U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 3U)) + 15219353497204773135U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7533774715626734082U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2599930450937763464U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13207380361960949159U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 16074720663961214284U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15483613196360051221U;
            aOrbiterI = RotL64((aOrbiterI * 11717479088020532861U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9396557867081376268U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9668459976852660245U;
            aOrbiterK = RotL64((aOrbiterK * 11748505665890567063U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9037269914643207212U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16936742640861088240U;
            aOrbiterC = RotL64((aOrbiterC * 1040172193161012227U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 16481274825758546398U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 481851372837611166U;
            aOrbiterA = RotL64((aOrbiterA * 2225030139210599207U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 53U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 54U) + aOrbiterD) + RotL64(aOrbiterK, 46U));
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 3U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 19U)) + aOrbiterC) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 58U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27245U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 31704U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25966U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25982U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30346U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29482U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 6U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 898812731947995389U) + aPhaseGOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 42U)) + RotL64(aCarry, 43U)) + 8677347622525527167U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 23U)) + 770321564027567654U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 11020474858081526395U) + aPhaseGOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 3U)) + 17289793580414993470U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10111912559295118444U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8083622125544542011U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3610772128071340341U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7149858558922988240U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 5919683821379905699U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16705119888884231567U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6860902846079238714U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15083517836867542075U;
            aOrbiterI = RotL64((aOrbiterI * 4686657139237578325U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14852868368708376381U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9860233289028878323U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13418143547952204667U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 772406119079116272U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7971141501337627589U;
            aOrbiterF = RotL64((aOrbiterF * 10168120622976358617U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 30U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 39U)) + aOrbiterK) + aPhaseGWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 29U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 40U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + aPhaseGWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 4U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
        // ingress from: aExpandLaneA, aExpandLaneB, aExpandLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneB backward forced, aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5221U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 6967U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 3632U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1391U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 222U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 3178U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 5U)) + 5573188770530340913U) + aPhaseHOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 1431772230889897111U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 22U)) + RotL64(aCarry, 23U)) + 4809192776429682319U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 5576603692574369341U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 37U)) + 2720143226007220386U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 17220328778565331629U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 9629485808442089423U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18349580416082045015U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1136998437010390983U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11893390497814523841U;
            aOrbiterE = RotL64((aOrbiterE * 5329621622743089531U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1764986431917532370U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1741014798007010376U;
            aOrbiterB = RotL64((aOrbiterB * 13414914086049500731U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12221368453236547044U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7694538641172350430U;
            aOrbiterA = RotL64((aOrbiterA * 8439120733670016501U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17472344518811560603U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3308740700728172984U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15290400462887712083U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterA, 58U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterB, 11U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 14U) + aOrbiterE) + RotL64(aOrbiterA, 21U)) + aPhaseHWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 3U)) + aOrbiterB) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14680U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((aIndex + 10846U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15034U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10841U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9214U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12922U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 20U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 22U)) + RotL64(aCarry, 5U)) + 12615321415808640429U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 15712784676459931207U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 43U)) + 11013335427004930046U) + aPhaseHOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 11U)) + 8298733856304768806U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 57U)) + 6207732959150824216U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9769864876127544038U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10782181918651152563U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16814396040248716483U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5790454015845620939U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15606578025386733803U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7079287329365566355U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5522352539991175304U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5993355818572869649U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15221467311057431139U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10864534396947622047U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12090053126235913528U;
            aOrbiterE = RotL64((aOrbiterE * 7250801471645972261U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14191181677234981396U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2258570108233924592U;
            aOrbiterD = RotL64((aOrbiterD * 8307541155393855209U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 54U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 22U) + aOrbiterD) + RotL64(aOrbiterE, 23U)) + aPhaseHWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterB, 60U)) + aPhaseHWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18752U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 19029U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 20049U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19133U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18115U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16850U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 13583136155674166402U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 50U)) + RotL64(aCarry, 43U)) + 12830472187484919497U) + aPhaseHOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aPrevious, 3U)) + 18081197909484522509U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 8680634051297891550U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 19U)) + 13939998767458656823U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1795730579103692594U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17369751719734069999U;
            aOrbiterD = RotL64((aOrbiterD * 2633464694273697123U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 224769585901248068U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4133547085925268180U;
            aOrbiterE = RotL64((aOrbiterE * 2611561365156544735U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7022512056309567391U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10319484359046945495U;
            aOrbiterH = RotL64((aOrbiterH * 3400140531307001933U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10483878349412282069U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 6481381149199985736U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9701719367082506253U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13721077228796934509U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9704818014314175007U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 760445624027740287U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 41U)) + aOrbiterE) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterA, 27U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterH, 12U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterD, 53U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25544U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 27221U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 28573U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27913U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32453U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 25498U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 20U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 9041099828460168106U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 5U)) + 12883711604096848454U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 19U)) + 17420968786226443079U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 28U)) + RotL64(aCarry, 37U)) + 3448213891716125104U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 11866455977445336560U) + aPhaseHOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4119356835384495905U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2186212599698637068U;
            aOrbiterG = RotL64((aOrbiterG * 6756888950976735707U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 6506144898969301620U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12556800923644051626U;
            aOrbiterI = RotL64((aOrbiterI * 15961043406612913121U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4075551535185182945U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17877694808492008749U;
            aOrbiterH = RotL64((aOrbiterH * 901315308379887473U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5553428900598223316U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14362304852277160675U;
            aOrbiterB = RotL64((aOrbiterB * 11415103199856419303U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 9174200302876075831U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16110739511917638547U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7004356839428657949U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 26U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 38U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterI, 27U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterB, 57U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
