#include "TwistExpander_Billiards_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Billiards_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8E1C4AE0423C9253ULL + 0xB966AEBC7DB2EC74ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA3C3FCA393673565ULL + 0xB30511ECF09241D6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCFB1259AF65A6955ULL + 0xAAE632A95FE2DF19ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEC22F3F073A09F29ULL + 0xF2D5DA42578BB5E5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC500170776F88379ULL + 0xA715512124E04AFAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xEB06E3EFEFCFE089ULL + 0xFC98084DEF80E57CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x94E2E15810B955B9ULL + 0x8BDFC398CDBEC9B8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDC219A3B7E466537ULL + 0xDE2EBD147FD9252AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x915ADE609B1A724DULL + 0xF5CB25E6B2E9770DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x85A573FBDFA1AB8FULL + 0xD89590EFF8EE9A19ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x90BDD0EAFBBE75F3ULL + 0xF65B1E30E7CCBD10ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB0E8A18470C4B6B1ULL + 0xB33CC5D407FA79C7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEF54300C87A24665ULL + 0xF9001A19E046F744ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE6D138F439C0A3BDULL + 0x959738847A01D302ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD46F1715EA4C46E9ULL + 0xC91B73F7E99B7FABULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA05B8DAB95EEE05DULL + 0xC8010701A8C81467ULL);
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
            aIngress = RotL64(mSource[((aIndex + 4944U)) & S_BLOCK1], 10U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 3889U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 531U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 4266U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = (aWandererA + RotL64(aPrevious, 5U)) + 8101351470141807662U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 50U)) + 6965474099521076705U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 27U)) + 6803828268885684784U) + aNonceWordO;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 41U)) + 13454235922950972488U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 11678091885751244777U;
            aOrbiterA = (aWandererI + RotL64(aCross, 43U)) + 5307134544628507141U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 4873703518950429353U) + aNonceWordM;
            aOrbiterB = (aWandererE + RotL64(aIngress, 11U)) + 8542156221858586039U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 60U)) + 3993726182905296513U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aCross, 57U)) + 12113047622035464386U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 21U)) + 1944244448665721151U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 12914188029425467576U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2486762763475327024U;
            aOrbiterI = RotL64((aOrbiterI * 12319769994433811617U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14580191602982245481U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12093414832400135066U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 12720286833215690663U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13623906997320021065U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9977356009806428696U;
            aOrbiterD = RotL64((aOrbiterD * 2005536391712733499U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3694954095397810851U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11453812627797091638U;
            aOrbiterG = RotL64((aOrbiterG * 13730420725113907161U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 542311345544726351U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3024285045990499484U;
            aOrbiterA = RotL64((aOrbiterA * 5153745952148205645U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15397664082460849530U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10716856680110815056U;
            aOrbiterB = RotL64((aOrbiterB * 13947203772929252823U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 833342121331428547U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1111339940097269219U;
            aOrbiterE = RotL64((aOrbiterE * 17991642769781175473U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9312963978841402871U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8225496710723213204U;
            aOrbiterK = RotL64((aOrbiterK * 894499195498817065U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7947419530949269753U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 5028446114139808517U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5593084899736787263U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9818957208200746975U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17549192719666647522U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 4705007748877441833U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16389708540378477737U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 8101351470141807662U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9858235486537441981U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 43U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterB, 23U)) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 21U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 14U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterF, 11U)) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aScatter, 10U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 39U));
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterG, 29U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aCross, 48U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 47U)) + aNonceWordE) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 56U)) + aOrbiterG) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 6522U)) & S_BLOCK1], 40U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9654U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8021U)) & S_BLOCK1], 35U) ^ RotL64(pSnow[((aIndex + 8927U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 60U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 1142447269198373880U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 10581460640040336191U) + aNonceWordA;
            aOrbiterB = ((aWandererI + RotL64(aCross, 11U)) + 14703062773878202900U) + aNonceWordG;
            aOrbiterG = (aWandererH + RotL64(aIngress, 56U)) + 15737525756286914746U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 27U)) + 16178774478273186999U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 53U)) + 2514897053906809160U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 37U)) + 13702496607592508464U) + aNonceWordP;
            aOrbiterD = (aWandererK + RotL64(aIngress, 41U)) + 18030885275418337965U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 51U)) + 5241783876161655984U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aScatter, 30U)) + 2807052676283587925U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 8022804576763271327U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15597099852232205860U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1538435607932096400U;
            aOrbiterB = RotL64((aOrbiterB * 7900752511710516981U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11147868774413615365U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9325213746830411568U;
            aOrbiterJ = RotL64((aOrbiterJ * 561819005818948769U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13792300423550555634U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3134856508983945719U;
            aOrbiterG = RotL64((aOrbiterG * 4271845067763664863U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8654966018053784882U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8937113935476779267U;
            aOrbiterD = RotL64((aOrbiterD * 7386875687217705855U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4135676350355234788U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 11407912615743682678U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2773506587480714695U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10966950663872392059U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 6686634993700944582U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 2509459942163678241U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14154407529749257990U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18054640398549782388U;
            aOrbiterI = RotL64((aOrbiterI * 7830759861389060149U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14623473030642960240U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1857945571104460086U;
            aOrbiterK = RotL64((aOrbiterK * 18039903315045620079U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17650774450811065797U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9458168381246672881U;
            aOrbiterA = RotL64((aOrbiterA * 3452665113988737563U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16604923466236483242U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 12447748535184711684U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 5982708155382249061U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9589720286549780720U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1142447269198373880U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8176719948031280789U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 18U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterF, 11U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 43U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + aNonceWordE);
            aWandererG = aWandererG + ((RotL64(aScatter, 38U) + aOrbiterG) + RotL64(aOrbiterD, 30U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterD, 37U)) + aNonceWordD);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterF, 23U)) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 47U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 35U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterD, 26U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 18U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 15796U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 14954U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 13082U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14486U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 6U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 19U)) + 12122689833405846292U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 41U)) + 9640400270962766788U) + aNonceWordP;
            aOrbiterE = (aWandererC + RotL64(aIngress, 43U)) + 9141937998266739071U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 12U)) + 12899395770434090537U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 21U)) + 13457918115408031842U;
            aOrbiterD = (aWandererG + RotL64(aCross, 29U)) + 15134784483576000943U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 12540961268790055438U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 3U)) + 6306886773092764230U) + aNonceWordK;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 13573343491337243121U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 8545588657348974413U;
            aOrbiterI = (aWandererB + RotL64(aCross, 10U)) + 10891410570357275120U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2877137119767060151U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9178097682386595144U;
            aOrbiterE = RotL64((aOrbiterE * 3524486002084427513U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15528007881855616978U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11368419529245281435U;
            aOrbiterG = RotL64((aOrbiterG * 12433207037378339309U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5932738914934356645U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5551842263864055419U;
            aOrbiterF = RotL64((aOrbiterF * 16093776759971522681U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3824433359595690603U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17184628855571662441U;
            aOrbiterA = RotL64((aOrbiterA * 691208053136187317U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8724462245014132623U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7481349499528092352U;
            aOrbiterJ = RotL64((aOrbiterJ * 8212182934509617583U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6908362960248294718U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 5354057969992655314U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16586084885820679343U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11138301629323903147U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14164180536320940750U;
            aOrbiterK = RotL64((aOrbiterK * 9099767681053390287U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 709942920176922902U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17128241237359414945U;
            aOrbiterH = RotL64((aOrbiterH * 14063385518459963529U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6760410778228957309U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15333948259759012363U;
            aOrbiterD = RotL64((aOrbiterD * 3685416414008280787U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6929136132517755104U) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 13833415487953533365U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14860437994758579635U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16143046377679975216U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12122689833405846292U;
            aOrbiterC = RotL64((aOrbiterC * 227699085983424155U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 24U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterC, 39U)) + aNonceWordG);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 21U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 3U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 42U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 53U)) + aOrbiterA);
            aWandererI = aWandererI + (((((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 53U)) + aNonceWordD) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterG) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterI, 18U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 26U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 40U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16466U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21318U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 17960U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 19730U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21170U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 47U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 27U)) + 12380376990224645149U) + aNonceWordE;
            aOrbiterI = (aWandererK + RotL64(aIngress, 57U)) + 18296928500297384014U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 47U)) + 3550626816361145100U;
            aOrbiterE = ((((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 2667792936946706027U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 14U)) + 12020969779370926953U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 737340727886903447U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 11U)) + 1681797651799760502U;
            aOrbiterD = (aWandererG + RotL64(aCross, 37U)) + 2956186342689489064U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 51U)) + 1876852870402977177U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 6433205819353555071U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 44U)) + 9065076854974222998U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3254410578766789992U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2005081975473815576U;
            aOrbiterF = RotL64((aOrbiterF * 9947701153722014085U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15992999234834560419U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3458344156815120948U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 1668460113964608051U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17069783053664877727U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1260234710193913099U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 4561226779897414381U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3825186451876061335U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2905344294992827535U;
            aOrbiterG = RotL64((aOrbiterG * 2469896090698580795U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18141402347899180617U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8760129857609925066U) ^ aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2507999156108123047U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 594052473780678210U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13216719212966128379U;
            aOrbiterI = RotL64((aOrbiterI * 10691355329696722303U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10029948739466316169U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11912428807431992996U;
            aOrbiterK = RotL64((aOrbiterK * 85016510811938307U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8735634019801417287U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12785916159063273545U;
            aOrbiterH = RotL64((aOrbiterH * 1161917531260663357U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 367752057919802452U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3961036242431041564U;
            aOrbiterB = RotL64((aOrbiterB * 16352646009782597315U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3858415336170090719U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14325258358254321551U;
            aOrbiterC = RotL64((aOrbiterC * 12080431158781060059U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16872184337970977180U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12380376990224645149U;
            aOrbiterJ = RotL64((aOrbiterJ * 16559121155413059221U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 10U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 48U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterF, 19U));
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 37U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aScatter, 24U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 51U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterH, 3U)) + aNonceWordP);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 34U)) + aOrbiterB) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aIngress, 54U) + RotL64(aOrbiterI, 29U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterE, 53U)) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 26982U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 25931U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(pSnow[((aIndex + 23211U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26225U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23183U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 26919U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 54U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (aWandererH + RotL64(aScatter, 23U)) + 6068543441070417854U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 21U)) + 2995980468193441856U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 37U)) + 18020277482171594003U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 53U)) + 4293807434721230702U;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 51U)) + 7980599111583893156U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 11U)) + 8593141111851052016U) + aNonceWordC;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 5903487523900084325U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 15112035513447930209U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 41U)) + 9854037263057006439U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 26U)) + 16759760289688823193U) + aNonceWordH;
            aOrbiterF = (aWandererI + RotL64(aScatter, 29U)) + 12622628933030601390U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1264668857268123425U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16302812053619101593U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18291400055836111547U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16087995784896123610U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7970269262800468363U;
            aOrbiterE = RotL64((aOrbiterE * 14924752223305807461U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5331477046030959632U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16534913204255550893U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 1013433634373673565U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11042821902537871209U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8069677512345031660U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13622218526054132397U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5737130058129936372U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 1076627182956662997U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14342191224014199929U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13911061091801078190U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15397603151098990373U;
            aOrbiterI = RotL64((aOrbiterI * 1802890451633592245U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15137326716738637972U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11248737008959896786U;
            aOrbiterG = RotL64((aOrbiterG * 90789374131547005U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1847847987633923657U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10560748778679145431U;
            aOrbiterF = RotL64((aOrbiterF * 2919333327817231099U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2703726238610290251U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12950671360471467310U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7490327691501537047U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10331504168520449467U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1541527607705280906U;
            aOrbiterK = RotL64((aOrbiterK * 14197400812600186171U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9135056476214341809U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6068543441070417854U;
            aOrbiterD = RotL64((aOrbiterD * 14102524444094948875U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 4U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 40U) + aOrbiterE) + RotL64(aOrbiterC, 35U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterH, 44U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 41U)) + aOrbiterE) + aNonceWordP);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 13U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 11U)) + aNonceWordN) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 39U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterA, 37U));
            aWandererD = aWandererD + (((RotL64(aScatter, 20U) + aOrbiterG) + RotL64(aOrbiterJ, 28U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 23U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 28035U)) & S_BLOCK1], 12U) ^ RotL64(pSnow[((aIndex + 28096U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 27715U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31906U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28343U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 30717U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 14U)) + 5576732410244514238U) + aNonceWordO;
            aOrbiterK = (aWandererC + RotL64(aScatter, 35U)) + 2833808925935929629U;
            aOrbiterH = (aWandererA + RotL64(aCross, 29U)) + 3670188682914544792U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 19U)) + 15759072378887814995U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 47U)) + 13934007231137439994U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 27U)) + 11022225696007690512U;
            aOrbiterG = (aWandererI + RotL64(aCross, 57U)) + 16989177104453635790U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 9256930045263527091U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 52U)) + RotL64(aCarry, 57U)) + 17788596104417068290U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 23U)) + 17044369456673337625U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 1310908395523250343U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 12067065689034065422U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15130844248737512262U;
            aOrbiterH = RotL64((aOrbiterH * 9409499577465934107U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14532689204495587494U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8198147292120244178U;
            aOrbiterD = RotL64((aOrbiterD * 1418356389507740991U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5485494458627163347U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10830008207150307611U;
            aOrbiterA = RotL64((aOrbiterA * 6526039534042499457U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17770065502486618029U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6397859353395335459U;
            aOrbiterB = RotL64((aOrbiterB * 14286997752368893825U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5128700697381508319U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7103394110057060499U;
            aOrbiterC = RotL64((aOrbiterC * 5053680689949149633U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16024401282261796979U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12818445221897253410U;
            aOrbiterJ = RotL64((aOrbiterJ * 11450004517784155405U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13386978409145916350U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16740821954556699503U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5376430209628515105U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 313978038530994953U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1355733685461795345U;
            aOrbiterI = RotL64((aOrbiterI * 15955927322082619735U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12590581077253956064U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2298195367575496005U;
            aOrbiterE = RotL64((aOrbiterE * 17512801361187006363U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11847450675712272468U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 5914296379577670282U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14574813500616811367U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16901317262621287065U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5576732410244514238U;
            aOrbiterK = RotL64((aOrbiterK * 4514943876091531567U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 36U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterI, 5U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterB, 40U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterC, 47U));
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 43U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterI, 27U));
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 53U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 21U)) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterE, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 58U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 22U) + aOrbiterF) + RotL64(aOrbiterD, 37U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererB, 38U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Billiards_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAFCA8EA4E630B26DULL + 0xB1B018C159C00F9AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCC6D94F8193D096FULL + 0xA23EFFC413F9F63FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x98891ADC26FBBF6DULL + 0xCB1F48595F93E1BFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB6AA832C3868C123ULL + 0xB0C4F578E9DE5012ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCCB11036F545444DULL + 0x92CC5EFDAE3685B1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB81F3F8F54D83A43ULL + 0x99BDF7C0DAD5DA20ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE83A2F833006FC3BULL + 0xBDEAC174D016B5C2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE040DD74805605DDULL + 0xB669A9F507B95454ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFD06E7B7EFB89DFDULL + 0xBF7E16B8F220F0F6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFDAC9BFC17EA3FB5ULL + 0xB6C5B3493918DA3EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF2C3F0271581E3F3ULL + 0xC86E17BC093AEA7BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC7675FE96EBC93B5ULL + 0xB6C998275BDC12C4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDED6BC72414769ABULL + 0xCD06A262A68B2164ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA2DA1B51DAB4410BULL + 0xB019FFB93972B874ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE739D4E87277896DULL + 0xA59E065904E6FDC9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x977A64AA030B4DEDULL + 0xDE9265BC72556040ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 6484U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5213U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 1969U)) & S_BLOCK1], 6U) ^ RotL64(aFireLaneD[((aIndex + 6077U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 19U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = (aWandererI + RotL64(aScatter, 23U)) + 13499155707765393469U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 3740324981823726185U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 28U)) + 5470765363949735652U) + aNonceWordB;
            aOrbiterE = ((aWandererH + RotL64(aCross, 57U)) + 3446436171274452326U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 51U)) + 1778929412631211933U) + aNonceWordH;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 13U)) + 14666308799855220954U) + aNonceWordG;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 36U)) + RotL64(aCarry, 35U)) + 4548410236791175055U) + aNonceWordD;
            aOrbiterF = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 5829739767694190372U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aScatter, 47U)) + 14319231414903675748U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1513851750246111405U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1685620217748986019U;
            aOrbiterG = RotL64((aOrbiterG * 9286548037413609445U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16284162182006054402U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6271539598462003309U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13923286694131331137U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12669312437565969473U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11894755313393001665U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12556759675372354075U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6315983824634946566U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17106616474222892782U;
            aOrbiterE = RotL64((aOrbiterE * 167205520766791073U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13350266700180455548U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4608846311203767162U;
            aOrbiterK = RotL64((aOrbiterK * 2504857468837437365U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14195866746143604365U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7917977448256795054U;
            aOrbiterH = RotL64((aOrbiterH * 5927771378657284557U), 19U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 10707336923305131629U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17122696159336995392U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 13953518568670659191U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5182322763573586116U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6503754948502556246U;
            aOrbiterF = RotL64((aOrbiterF * 14749002194140663519U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 14907832047832987341U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6258064448676621346U;
            aOrbiterC = RotL64((aOrbiterC * 4407960312705621487U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 44U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 58U)) + aOrbiterK) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterD, 41U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + aNonceWordL);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 47U)) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 27U)) + aOrbiterJ) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aScatter, 10U) + RotL64(aOrbiterB, 51U)) + aOrbiterH) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterF, 12U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 37U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 40U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 13811U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((aIndex + 15580U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 11264U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13050U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13423U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererH + RotL64(aScatter, 23U)) + 5960680319644404115U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 16050752633567034185U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 41U)) + 8447503223226854741U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 60U)) + 14176813813397917591U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 47U)) + 10534915376130006644U) + aNonceWordD;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 6866224454375302514U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 16506374165041008396U) + aNonceWordL;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 30U)) + 7167814023968794098U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 37U)) + 13870852197416596664U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 18064038854848993105U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9869630811507771691U;
            aOrbiterE = RotL64((aOrbiterE * 13723164383800461387U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 863613100452759380U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16597969741225436529U;
            aOrbiterF = RotL64((aOrbiterF * 2680793528887208903U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6575347108051310653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17062262265485019063U;
            aOrbiterA = RotL64((aOrbiterA * 7601045488473620019U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7193399224636409133U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14146747818810433849U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 5273185769989530041U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9441449106442431427U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4303295336545399503U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8829695296836242587U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 12604760768543193458U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15779327512379787715U;
            aOrbiterD = RotL64((aOrbiterD * 14000905201441272597U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15553000781122708728U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17162740616060079717U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 9458662233556750239U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1032374679817715156U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16413393156165548232U;
            aOrbiterI = RotL64((aOrbiterI * 549659738811935015U), 3U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 14056855000013992045U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7399202019042538829U;
            aOrbiterH = RotL64((aOrbiterH * 6103508549612077695U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 44U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 18U) + aOrbiterI) + RotL64(aOrbiterA, 35U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 18U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterD) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterB, 3U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aCross, 23U) + RotL64(aOrbiterB, 54U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aScatter, 52U) + RotL64(aOrbiterA, 39U)) + aOrbiterC) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19670U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneD[((aIndex + 17350U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 24162U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19264U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20801U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 23608U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 27U)) + (RotL64(aPrevious, 14U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = ((aWandererA + RotL64(aCross, 30U)) + 12980104182836602177U) + aNonceWordD;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 3172622203188863995U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 57U)) + 1170974132219980203U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 47U)) + 6035201940965047490U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 10U)) + 18033907118424996722U;
            aOrbiterF = ((((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 14604813424800580304U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aWandererG + RotL64(aIngress, 39U)) + 13720232492851066035U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 3902659710585257448U) + aNonceWordO;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 5U)) + 8331560652661619868U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4485014147538689794U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 168202636924512424U;
            aOrbiterI = RotL64((aOrbiterI * 13711020666131492091U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16227825670092707848U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4792781933944671365U;
            aOrbiterF = RotL64((aOrbiterF * 15859849676231455283U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12636865372722601282U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 18198291399585556632U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18155803890313399795U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3650053185419807206U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5897288963905408776U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3706949366974086151U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9922308113622901726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13352279749091561510U;
            aOrbiterG = RotL64((aOrbiterG * 4025213180483632557U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14969461950939646117U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10231661776135056651U;
            aOrbiterD = RotL64((aOrbiterD * 11284575051455238501U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10621934544068320859U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6029116920305246887U;
            aOrbiterJ = RotL64((aOrbiterJ * 6087523725059376905U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 12887482425168671195U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8351351557123783853U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3839381627914762245U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5405938210926464973U) + aNonceWordE;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 385145802287899406U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8330751480464271445U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 30U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterA, 42U));
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 29U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 58U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 51U)) + aOrbiterD) + aNonceWordK);
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 60U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aCross, 10U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31801U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((aIndex + 32312U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31050U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27968U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30463U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 29778U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 11U)) + (RotL64(aCarry, 60U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 56U)) + RotL64(aCarry, 27U)) + 11450949896247900941U;
            aOrbiterA = (aWandererA + RotL64(aCross, 23U)) + 3905542253538116335U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 11U)) + 9529740545977785305U) + aNonceWordK;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 1856876631533143492U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 47U)) + 84253466320181686U) + aNonceWordP;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 35U)) + 12577480918745432444U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 51U)) + 5625703170397704029U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 11U)) + 694608607323629282U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 30U)) + 3993981243536262204U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 4119215953484892051U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8785040118556157146U;
            aOrbiterH = RotL64((aOrbiterH * 17113521266125471625U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16234403619456882890U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10398727475672860610U;
            aOrbiterF = RotL64((aOrbiterF * 5086871400049644715U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18327987141759096769U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2645964788056875452U;
            aOrbiterK = RotL64((aOrbiterK * 8778681366114628045U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2859452497983106129U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 7196557924940881076U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 14415389907490256711U), 47U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 930127943984174668U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15673596916054795749U;
            aOrbiterB = RotL64((aOrbiterB * 7505660488733199479U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16673140529110941163U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2258448294877833760U;
            aOrbiterA = RotL64((aOrbiterA * 1821550319748977445U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6870209259643931219U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12749790107942194104U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 4871407285968611725U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17131374134617173866U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6426448390733751612U;
            aOrbiterJ = RotL64((aOrbiterJ * 12490559588384058417U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15592826434339731146U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14182944418026376183U;
            aOrbiterC = RotL64((aOrbiterC * 7218860482893476233U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 20U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + aNonceWordI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + aNonceWordE);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 22U) + aOrbiterJ) + RotL64(aOrbiterG, 48U)) + aNonceWordJ) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + aNonceWordC);
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 3U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aCross, 18U) + aOrbiterH) + RotL64(aOrbiterG, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Billiards_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8FAE2C7AC2A8A4BFULL + 0xD21944C8AF6DDFECULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDF5EA8C83FA6304BULL + 0xAC8213AE407CAD91ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFB5CDA678B26556DULL + 0x87E4DCF5FBDE0402ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE5F97AD6F43EA18DULL + 0xBB2D69560D43CACBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9AD059B2429A3491ULL + 0xCFA32D176AFECC37ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAA92FB0564BBE1C1ULL + 0x9AD50F6CA76C9864ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9F7E8137E939E9E9ULL + 0xD19A0E01BAFECC65ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9613160477F98B15ULL + 0xB02E02E35530C009ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBD0C4AF8BE379257ULL + 0xACF47D30E5D86867ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF8ED621C8C245269ULL + 0xAF85D2E50BFF5BF9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFC41A340F6688939ULL + 0x8C87E0A7BDE2AB94ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD7A850C5FA9F205DULL + 0xE4FC6CC0C1320749ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD06CEAB1531D7359ULL + 0xB282D0DAC9E47A32ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9B2013F98D1ADC71ULL + 0xF37BBEEBDA0442D5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x931A854A6BAFD0F5ULL + 0x817E02A04EED06BCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x87CB1CE006F18A95ULL + 0xD28D414DCDEA867AULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 194U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 7492U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 855U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5266U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5696U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 40U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 2974056819475622600U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 53U)) + 7345051759236356098U) + aNonceWordL;
            aOrbiterJ = ((((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 12738468816846628882U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 7694520596043297922U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 26U)) + 5530753590015084774U) + aNonceWordG;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3776309161718383105U) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 784780304358106404U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 1503119308251871519U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8999942326995036509U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5194986506064092779U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15070787038006135963U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7920040007459652762U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11311997270710107937U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6227571709361790209U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5365231114813547251U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8630110234623825263U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2735881715888325759U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2358235238039571072U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 18059414891616491807U;
            aOrbiterG = RotL64((aOrbiterG * 17150786106857185467U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 58U);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 5U)) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 53U)) + aOrbiterA) + aNonceWordE);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 44U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 58U) + aOrbiterJ) + RotL64(aOrbiterG, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 4U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9551U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneC[((aIndex + 10226U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15833U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15002U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10442U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9337U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 37U)) ^ (RotL64(aIngress, 56U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (((aWandererK + RotL64(aCross, 51U)) + 15813325389431304548U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 2223874171125403602U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 34U)) + RotL64(aCarry, 41U)) + 5510483568496824130U;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 15474152493495661876U) + aNonceWordM;
            aOrbiterK = (((aWandererG + RotL64(aCross, 5U)) + 16846339705130829195U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 1289670576865739669U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 18017354919647006944U;
            aOrbiterH = RotL64((aOrbiterH * 13103155460891498469U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8539685539928984921U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3333721400836704048U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3745286323481400085U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2261560416623815491U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 4377786131746816567U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 9164777834392621157U), 51U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 18047393176583722719U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8184724021940434631U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9800116157750921119U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 10469895939183324807U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14543391765109879223U;
            aOrbiterD = RotL64((aOrbiterD * 4817987697437667225U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 52U)) + aOrbiterD) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterK, 5U)) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23845U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 16641U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 23707U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22603U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18909U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 20806U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 13U)) ^ (RotL64(aPrevious, 26U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = (((aWandererE + RotL64(aCross, 54U)) + RotL64(aCarry, 39U)) + 1888427424966603593U) + aNonceWordH;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 5436761445660415091U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (((aWandererG + RotL64(aIngress, 43U)) + 17322876217962143270U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 9728299982740564979U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 29U)) + 301720335271716921U) + aNonceWordD;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8069685428854814396U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 1973715500949100991U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 7940531594430629427U), 43U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 87666408799854155U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 12195436904339035245U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15427739165893738105U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4578742069143400295U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7828776048774876484U;
            aOrbiterF = RotL64((aOrbiterF * 4047964518501081039U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17203146364542781833U) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16913369550858890466U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13534417587921978507U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9632761514552265402U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9106637671877341286U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 9073709119482640391U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 56U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB) + aNonceWordC) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordA) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 40U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 35U)) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 21U)) + aOrbiterF) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25237U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((aIndex + 26715U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28349U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28637U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25707U)) & S_BLOCK1], 40U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27526U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 29453U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 28U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 30U)) + RotL64(aCarry, 3U)) + 3448371607470865612U) + aNonceWordD;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 3743742913651580573U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 13069491287948807280U) + aNonceWordB;
            aOrbiterC = (((aWandererF + RotL64(aCross, 19U)) + 16872779275586545632U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 5U)) + 17945792656755062795U) + aNonceWordJ;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 18199747196793731853U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15953311878379809513U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5476802169152352897U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 941268763494588338U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10090221530365796809U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14035236086292997613U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8335698093307607001U) + aNonceWordL;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 6147498804734306100U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 6904444049941211327U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5980246079567570090U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4152167624425912978U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 10019421651535123573U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14990418790239735916U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3418668387496597219U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 12814077238529863119U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 24U) + aOrbiterH) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 19U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 30U)) + aOrbiterB) + aNonceWordE) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 57U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 41U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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

void TwistExpander_Billiards_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE761C468FCD8BB93ULL + 0xD0576B74B38261FAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDEC1625BA8945D17ULL + 0xACFC0E0952F1CD37ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x95737EF3F37F568DULL + 0xE2C4CBF86CE261C0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDDDDDCFCEA04BDEDULL + 0x9B4219AFDA7CCC03ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBA60A061B82CEEA3ULL + 0xAC9A9D33025173B8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB727CD6737C99E2DULL + 0xC0FEF930C6159C7DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDD374B344389BA3BULL + 0xB75C9E5DFDB017F5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB7D0A08ABFBFC1C9ULL + 0xA7828C96A9150A92ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAF9D6A950A0272D9ULL + 0xE063613BA564A437ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE8A7B24FDB16D39BULL + 0xC7D790DA2E91C468ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9AEBA0D935B015EFULL + 0xA71EF910A173C08EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE532883E1A5049DFULL + 0xBEA3C97400AAC4ECULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF4726502143CABCFULL + 0xECD1C2447AF1A368ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBB15B6F391D93BC3ULL + 0xC23A9F8831B65B29ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA87F3BFBF11690E3ULL + 0xC8673B9995EEEA49ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFF2ABF6B5461B9C5ULL + 0xA39AFCA8BD141169ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aFireLaneC, aWorkLaneA, aOperationLaneA, aOperationLaneD, aWorkLaneB, aFireLaneA, aOperationLaneB, aWorkLaneC, aFireLaneB, aOperationLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4267U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 7278U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 1192U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5950U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1786U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6084U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 18180797995100240808U) + aNonceWordI;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 57U)) + 6585906608223552885U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 14088708930575939855U) + aNonceWordP;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 50U)) + RotL64(aCarry, 27U)) + 468974153311516044U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 3U)) + 12481951025619894110U) + aNonceWordC;
            aOrbiterI = (aWandererI + RotL64(aIngress, 35U)) + 17227987923860711763U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 11U)) + 4373962756657477139U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2077576476565420951U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17435011300234663764U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 8910133867294004711U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4118039398293246896U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 13724716599855216683U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 17556333902751079677U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12391461204689596339U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9900605191533799627U;
            aOrbiterI = RotL64((aOrbiterI * 13553565332531046301U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 972946858824366125U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17247681919694541215U;
            aOrbiterA = RotL64((aOrbiterA * 2974639094630445643U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 15442851427306771601U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7303586227288294037U;
            aOrbiterD = RotL64((aOrbiterD * 15406402525021428799U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12650358753454105119U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1483710933373510492U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6531763256577221891U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 18065810162229740788U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11311677121338794007U;
            aOrbiterJ = RotL64((aOrbiterJ * 15116367961682119467U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 22U) + aOrbiterI) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterE, 27U)) + aNonceWordB);
            aWandererI = aWandererI + (((((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aNonceWordO) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterI, 60U)) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterK, 53U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 18U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10590U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 13564U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 15179U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8556U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9404U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 11893U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 44U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = ((aWandererG + RotL64(aCross, 47U)) + 9435962834163239322U) + aNonceWordO;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 12U)) + 10524704356081318973U) + aNonceWordD;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 7403401305665208680U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 7525414805023556493U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 1116686470029070951U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 35U)) + 13257612299137802420U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 3U)) + 9181543003986598283U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9739384852307501107U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11308402900229016057U;
            aOrbiterC = RotL64((aOrbiterC * 12690186771773188967U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 14935167593705272337U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7171824007631943535U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4839974427616194289U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 8068411284829563567U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12350207458513447578U;
            aOrbiterA = RotL64((aOrbiterA * 813973258659041895U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 17039236343991574134U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 18291683592714999632U;
            aOrbiterI = RotL64((aOrbiterI * 7771718817924840713U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6239616841884430968U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10604527977569876774U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 6972820410084939637U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 1707724300671717658U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3802268808625297647U;
            aOrbiterB = RotL64((aOrbiterB * 11296811630387191563U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9423064323799920219U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 242153923313096551U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 12117679073775630197U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 42U);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterE, 3U));
            aWandererF = aWandererF + (((((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 53U)) + aNonceWordG) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterC, 60U)) + aOrbiterH) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterH, 47U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterK, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterC, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 42U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19381U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 19200U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 24123U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20357U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19875U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 21694U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 54U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 1457104756581596530U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 6127240317844622874U) + aNonceWordE;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 16492290056044189421U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 27U)) + 10963676850938416468U) + aNonceWordM;
            aOrbiterC = (aWandererE + RotL64(aCross, 50U)) + 4872917367399752405U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 35U)) + 15218882377875616148U) + aNonceWordD;
            aOrbiterA = (aWandererI + RotL64(aIngress, 41U)) + 5934166612122118251U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14215280930872003003U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11428034799044600979U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12162528943733976177U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5453003654321728726U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14273775120265649389U;
            aOrbiterJ = RotL64((aOrbiterJ * 5139018128323795309U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 328723770018440271U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13032190719588211088U;
            aOrbiterH = RotL64((aOrbiterH * 13363368478932798315U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 2386881543033598494U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1649501123340887116U;
            aOrbiterE = RotL64((aOrbiterE * 11148976582360499033U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16462401546754210583U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1510579201823042227U;
            aOrbiterF = RotL64((aOrbiterF * 16287912400104043275U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6889066000014251983U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11324594596597724357U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15344987814648586023U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12237796033168436537U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17306069670330000343U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3167451351403385259U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 58U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterE, 23U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterA, 6U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 20U) + RotL64(aOrbiterC, 41U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 53U)) + aOrbiterF) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 35U)) + aOrbiterG) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 36U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneC
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25371U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((aIndex + 28135U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 32307U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24898U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29585U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 30911U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 35U)) + (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (((aWandererD + RotL64(aIngress, 37U)) + 8375305456876489425U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 16193562952772453047U) + aNonceWordO;
            aOrbiterD = ((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 3U)) + 18088652458594816223U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 767344788620249944U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 11U)) + 7705194930396368752U) + aNonceWordP;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 3U)) + 3829736891311272834U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 51U)) + 9881681671347640061U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1721196560190164264U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3002652618388454213U;
            aOrbiterD = RotL64((aOrbiterD * 15289749311593032657U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9811621464004005202U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5652598941069986530U;
            aOrbiterG = RotL64((aOrbiterG * 4797973356708091621U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6250499348327316328U) + aNonceWordC;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 16025054277615264530U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 16446892258704281903U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13800298546867243172U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12256104592865905782U;
            aOrbiterA = RotL64((aOrbiterA * 16983140179497142713U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17817225416918329229U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17738671327352776217U;
            aOrbiterF = RotL64((aOrbiterF * 393488251327705063U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6816031224188400541U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16989563985059237014U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8677884225771717797U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16891524847268207549U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 1833508573940405571U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 9709196587703979539U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterG, 57U)) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + aNonceWordF);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterF, 20U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 37U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 27U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 48U) + aOrbiterF) + RotL64(aOrbiterE, 51U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererD, 12U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Billiards_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8F069BFFF734496FULL + 0xDD57972446549400ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE5E84C3C74DAF9B9ULL + 0xD2022C48857A05DFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE5BA6ADA38EEFD77ULL + 0xA01D5B99842084B1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8F433FF606257C7BULL + 0xF0DAC7B929E41EEEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9C59BBBABAF78B2DULL + 0x8EEC62CE2F3B9709ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA938DE87E470BF61ULL + 0xCAEA5076C1EC1DEEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD098E1440C011343ULL + 0xB97CA5FB7A97666FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x92373C2F0BC562D1ULL + 0xDF3C0C91C7A69B3EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x93C9FCA32836FB0BULL + 0x97FCD6156636A426ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC4EE6E19E32D2A07ULL + 0xDDAF0C60740C229FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD2E7AEF7FC0644F1ULL + 0x8243B91F80BF34BDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD5CAB1A298337BF3ULL + 0xC6731EC8976A3203ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF84C9160E66305B7ULL + 0xDECEA67C9B31AAC5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB44FEA1AE2763991ULL + 0x8BDF30DFA3C266CAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB4A2B3DA014B9E0DULL + 0xD1B2EBA26820498DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC82D28223EB63379ULL + 0x8BCF664474D1E90DULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aWorkLaneD, aFireLaneA, aExpandLaneA, aFireLaneB, aOperationLaneA, aExpandLaneB, aOperationLaneC, aFireLaneD, aExpandLaneC, aOperationLaneD, aFireLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3723U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((aIndex + 4690U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 6432U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7553U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3953U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2312U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 20U) + RotL64(aIngress, 3U)) ^ (RotL64(aCross, 51U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = (aWandererK + RotL64(aScatter, 21U)) + 1708250618750199233U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 12009147777553691142U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 37U)) + 8393982703399156592U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 3247327098356831221U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 13U)) + 3403590155376353737U) + aNonceWordG;
            aOrbiterC = ((aWandererH + RotL64(aCross, 3U)) + 18197244558104735044U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 28U)) + RotL64(aCarry, 57U)) + 3096253642040701606U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 8012692688785412179U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17531946907545680745U;
            aOrbiterH = RotL64((aOrbiterH * 16510602981731506381U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17687695944270225817U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16147773866007628769U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 16926442582711557877U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 18244641303026196497U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8839160526348897457U;
            aOrbiterF = RotL64((aOrbiterF * 14268021129087663397U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10599266240854068246U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 2056723540756216155U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 13311591601230386375U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4629354220460621284U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 9505955649473204942U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17775391885312236187U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17078153810088721310U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 9470436761716263000U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5431855497250357229U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3305863413630104742U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14377172434239576161U;
            aOrbiterJ = RotL64((aOrbiterJ * 6880176890091033423U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 37U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterF, 21U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 13U)) + aOrbiterC) + aNonceWordP);
            aWandererK = aWandererK + ((((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 60U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 6U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10354U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 12103U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10085U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11579U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9309U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10503U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 57U)) ^ (RotL64(aCarry, 29U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererF + RotL64(aCross, 11U)) + 9774364261626083532U) + aNonceWordC;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 18059001521926116420U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 57U)) + 10615626210406381148U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 21U)) + 10536484278007898620U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 27U)) + 13320663045139972700U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 42U)) + RotL64(aCarry, 13U)) + 17127001787268166583U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 16742574590844166551U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8347719720758228053U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13502468705946051986U;
            aOrbiterE = RotL64((aOrbiterE * 13822952083584784695U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3512687886188904904U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 495660316165795934U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6724596801190194913U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 5092722552034477356U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15641128019608284015U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3621036395703527059U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15421873776811085458U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 17978775513204574125U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18359600395119440183U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 16617179197537669849U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1931805387534012528U;
            aOrbiterB = RotL64((aOrbiterB * 3400139345857733775U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9544923119559308431U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12930999400470173353U;
            aOrbiterC = RotL64((aOrbiterC * 16791006919271490005U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13673733276226249890U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2032263473309124738U;
            aOrbiterF = RotL64((aOrbiterF * 3088728329261360607U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 58U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 29U)) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 50U) + aOrbiterC) + RotL64(aOrbiterB, 48U)) + aNonceWordF);
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterG, 11U)) + aNonceWordJ) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterF, 21U)) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20875U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 17003U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23005U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24011U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17734U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18826U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = ((aWandererF + RotL64(aIngress, 43U)) + 6068543441070417854U) + aNonceWordD;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 13U)) + 2995980468193441856U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 50U)) + RotL64(aCarry, 5U)) + 18020277482171594003U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 4293807434721230702U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 35U)) + 7980599111583893156U) + aNonceWordJ;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 8593141111851052016U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 3U)) + 5903487523900084325U) + aNonceWordO;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15112035513447930209U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9854037263057006439U;
            aOrbiterC = RotL64((aOrbiterC * 396276470208637283U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16759760289688823193U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12622628933030601390U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2151912984825538321U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1264668857268123425U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16302812053619101593U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 18291400055836111547U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 16087995784896123610U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7970269262800468363U;
            aOrbiterA = RotL64((aOrbiterA * 14924752223305807461U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 5331477046030959632U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16534913204255550893U;
            aOrbiterD = RotL64((aOrbiterD * 1013433634373673565U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11042821902537871209U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8069677512345031660U;
            aOrbiterG = RotL64((aOrbiterG * 13622218526054132397U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5737130058129936372U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1076627182956662997U;
            aOrbiterH = RotL64((aOrbiterH * 14342191224014199929U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 12U) + aOrbiterC) + RotL64(aOrbiterJ, 29U)) + aNonceWordP);
            aWandererK = aWandererK + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 60U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 26U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27881U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 32053U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32064U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31673U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32700U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 30857U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 38U)) + (RotL64(aCarry, 21U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 15904465836916519864U) + aNonceWordM;
            aOrbiterG = ((aWandererG + RotL64(aCross, 18U)) + RotL64(aCarry, 53U)) + 17725629806317789307U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 53U)) + 13794170125914914828U) + aNonceWordJ;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 41U)) + 2149055907476874332U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 5U)) + 5342047776745074649U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 27U)) + 8268148484060546838U) + aNonceWordB;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 10821151364028563719U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4294213820894407378U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 10884726101307943090U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 1116128870387229159U), 27U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 16432210042202444824U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15196602644336228055U;
            aOrbiterA = RotL64((aOrbiterA * 12680438355124070237U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14117787670220328165U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 219833877949480215U;
            aOrbiterG = RotL64((aOrbiterG * 10736293047771972173U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3326396981881473962U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14918513066311426279U;
            aOrbiterK = RotL64((aOrbiterK * 14269763278564574663U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11795234681370163206U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 3068267285352664813U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15746255933920904619U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 245233356957999496U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 709926406353796673U;
            aOrbiterF = RotL64((aOrbiterF * 13627039596842073595U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5378105439430271038U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10114555061122044430U;
            aOrbiterE = RotL64((aOrbiterE * 5351295043424885549U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 30U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 28U)) + aOrbiterE) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterF, 57U)) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 5U)) + aOrbiterF) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 35U);
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

void TwistExpander_Billiards_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBA9E7F27F0835F37ULL + 0xAF2A18BFE35B238DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEC559520304F2C13ULL + 0xB5C65614C92EEA8CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xECE34121050A35D5ULL + 0x96EEF7CD30CF0DA6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD1D94BA85E975623ULL + 0xE451B82690AB832EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE4E8A542702ED2FFULL + 0xA8B46B45361346D6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD0569BDD45C6C25DULL + 0xADCD66A36108180FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBAE6417E490B076FULL + 0x9C7B10D3F0BD8F20ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8F2DE49350BA3D73ULL + 0xC2022199B96F50EAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAA7FE90699A68DE9ULL + 0x998EFFB15389F3E2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF65CCF98F485E69DULL + 0xF629A7D4B062BD74ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x98812E7171B653D1ULL + 0xB72B61251A67B8E0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBD93F325320E7EF5ULL + 0xD7FCBD91CDBD76D8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDED00E696C41161DULL + 0xB28DAE1D704DF9DBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCCBC65DBED849C33ULL + 0xC1FD57E4FF2F7E3EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xADE9065F159270BBULL + 0xC98B225DEE680280ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE8E4B92ACE7E6A5DULL + 0xCCE1E1332DEA8B19ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aFireLaneB, aOperationLaneA, aFireLaneA, aWorkLaneD, aOperationLaneB, aFireLaneC, aWorkLaneA, aOperationLaneC, aWorkLaneC, aWorkLaneB
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3516U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 1484U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6564U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1399U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4199U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5441U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 24U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((aWandererA + RotL64(aIngress, 37U)) + 8402620908307642697U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aScatter, 53U)) + 11347672014525086047U;
            aOrbiterA = (aWandererI + RotL64(aCross, 24U)) + 2816462912503401876U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 11U)) + 6940159795470696093U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 9134692490095883851U) + aNonceWordC;
            aOrbiterC = (aWandererB + RotL64(aCross, 35U)) + 4999455497008026526U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 5992451460350651332U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 6U)) + 3417087346651371924U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 3U)) + 3612773820086198270U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 463398077083428570U) + aNonceWordM;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 39U)) + 11249391303705089012U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17027535139825739501U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 568131384979596481U;
            aOrbiterA = RotL64((aOrbiterA * 5683451044852895957U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4793712537158004047U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10415170179135963622U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 13729564030210361415U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2391473979460065630U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4240058362680064261U;
            aOrbiterH = RotL64((aOrbiterH * 12375884373396400889U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9963957011090031698U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3325305624067445525U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 3128542681461806309U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2094945647665114693U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 10703615640774042674U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12641986098450423751U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3768738815518590289U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 15021301790376706827U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14445850924223550339U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10571246886181608316U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5130325144599151793U;
            aOrbiterC = RotL64((aOrbiterC * 3185251943547657467U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8617523421720966373U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16574597770835250074U;
            aOrbiterD = RotL64((aOrbiterD * 1759209403428937799U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17474733286551120355U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17914672092861237776U;
            aOrbiterK = RotL64((aOrbiterK * 13657291990878792267U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12856557371623447773U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1636296609747335898U;
            aOrbiterI = RotL64((aOrbiterI * 9286345529656087313U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12588848560509679821U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8402620908307642697U;
            aOrbiterF = RotL64((aOrbiterF * 2269772223506258147U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 36U);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterF, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterD, 41U));
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 27U)) + aOrbiterB) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 60U)) + aOrbiterA);
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 13U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterB, 29U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 21U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 35U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterB, 3U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + aNonceWordL) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 6U) + aOrbiterB) + RotL64(aOrbiterG, 24U)) + RotL64(aCarry, 43U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 26U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10911U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((aIndex + 8750U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 14616U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9252U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11870U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9986U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 8604208734152026945U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 1374329953253889829U) + aNonceWordF;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 44U)) + 5779278910548228339U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 27U)) + 17670451230882805140U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 13U)) + 8193848740764866860U;
            aOrbiterC = (aWandererE + RotL64(aCross, 21U)) + 15801168428145650104U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 2584718176087499066U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 23U)) + 14950366247822737997U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 29U)) + 9779293225265670135U) + aNonceWordK;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 36U)) + 8688968319288372383U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 53U)) + 13665723186950342601U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9395428688359973510U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2152719218018108418U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 15271961483518392671U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1350324137411377992U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8729317951386057921U;
            aOrbiterC = RotL64((aOrbiterC * 6008790836417785083U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6317310451893678411U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10175620379041384281U;
            aOrbiterK = RotL64((aOrbiterK * 14079679617394330781U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1203082119358827708U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 523869107818193101U;
            aOrbiterF = RotL64((aOrbiterF * 4629501113595689157U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4028324959540432983U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15447631947468213912U;
            aOrbiterH = RotL64((aOrbiterH * 6037306615787729185U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14225888694733041031U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11925000696281947629U;
            aOrbiterI = RotL64((aOrbiterI * 4337022940520411253U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15015531024930608745U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 16752579225076943550U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 15551083683579981439U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2432733494869267901U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 10103430321388601485U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18372919379972432569U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15943360147468638325U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9782703760233558733U;
            aOrbiterB = RotL64((aOrbiterB * 685056980418243879U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18345087852012669037U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8897505040792027675U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 14333687539092412967U), 27U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 7402581293947129667U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8604208734152026945U;
            aOrbiterJ = RotL64((aOrbiterJ * 9965525485538037673U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 18U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + aNonceWordD);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 52U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 11U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 34U));
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 4U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + aNonceWordO);
            aWandererB = aWandererB + ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 56U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 46U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneC
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneA
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20286U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 17666U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22401U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16799U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21771U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 22011U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 14U) + RotL64(aCross, 41U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererJ + RotL64(aScatter, 57U)) + 4476099022490972343U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 13U)) + 16836423700375760429U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 8850577488928703557U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 37U)) + 7091631824560042743U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 5U)) + 12560498899956759494U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 29U)) + 7797973377112012161U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 40U)) + RotL64(aCarry, 27U)) + 6173820673874805794U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 35U)) + 10805025132310245348U;
            aOrbiterK = (aWandererI + RotL64(aCross, 51U)) + 7139216143268029968U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 53U)) + 8241544862261635722U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (((aWandererE + RotL64(aScatter, 20U)) + RotL64(aCarry, 47U)) + 4735527016563596150U) + aNonceWordJ;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5166171126690294033U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11117641762075368393U;
            aOrbiterA = RotL64((aOrbiterA * 4980156869201219393U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6312932356458415421U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1304139291184508668U;
            aOrbiterH = RotL64((aOrbiterH * 90744653170922319U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10085025354842771067U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16745854428789531080U;
            aOrbiterJ = RotL64((aOrbiterJ * 1945983905747274355U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2497187958708890337U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16069701876646548995U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 16606039730973709495U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17242004368025978091U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12334315722243232121U;
            aOrbiterF = RotL64((aOrbiterF * 16528598396696346719U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8007042082518126895U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 5665686359038811484U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11289316305875751813U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3913477186958600592U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16918984318564170343U;
            aOrbiterG = RotL64((aOrbiterG * 5128293326494417281U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10227611546502931418U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7187623463085447228U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8479839369622163181U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16655159122037336519U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9844145011519243346U;
            aOrbiterB = RotL64((aOrbiterB * 16512883184116277583U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8660130685326542506U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16192687259641294851U;
            aOrbiterI = RotL64((aOrbiterI * 2882649237163668499U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15208432734447317310U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 4476099022490972343U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7447168142776253041U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 12U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 4U) + aOrbiterK) + RotL64(aOrbiterA, 50U));
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterH, 23U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterI, 29U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 53U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 60U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 6U) + RotL64(aOrbiterH, 21U)) + aOrbiterB) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterG, 37U)) + aOrbiterC) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterE, 3U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterG, 13U)) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererF, 44U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneC
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30827U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((aIndex + 25428U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26568U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24913U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29111U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26441U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((aWandererK + RotL64(aCross, 13U)) + 3339283916456813609U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 37U)) + 11339086426180649584U) + aNonceWordP;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 46U)) + 16819191669329316585U) + aNonceWordE;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 19U)) + 8361916937762630725U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 57U)) + 18031328374429899857U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 18261756894092897276U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 3U)) + 4250319792907645666U) + aNonceWordO;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 1492411503643460886U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 30U)) + 17369549067879344180U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 51U)) + 7301713524358676722U) + aNonceWordL;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 2985193736033012535U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14086975808140927408U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10390516547834639800U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 11441293212275890819U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 18205555540941493267U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16967799565443938873U;
            aOrbiterD = RotL64((aOrbiterD * 3009081009044782443U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9209505304067579944U) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 3522631966146762306U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3441982898533162599U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 8811497120829041188U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14707301680850257294U;
            aOrbiterJ = RotL64((aOrbiterJ * 11383709499376464085U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10080595991787801029U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6822892187784299166U;
            aOrbiterH = RotL64((aOrbiterH * 7417016898027778287U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1981637172055758689U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16463077485583119324U;
            aOrbiterK = RotL64((aOrbiterK * 2876782050665869121U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8383837717361569465U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2788511294985017326U;
            aOrbiterI = RotL64((aOrbiterI * 2809163242875130677U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3529607472855930041U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8850940802020173766U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 7821450253655655943U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7469160295100147267U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16973986572163482061U;
            aOrbiterE = RotL64((aOrbiterE * 15660743778376905023U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12371372942863279718U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12098525148034303633U;
            aOrbiterB = RotL64((aOrbiterB * 11234127652230231751U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5138683482859889480U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3339283916456813609U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10975353228235695455U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterF, 39U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 36U) + aOrbiterD) + RotL64(aOrbiterB, 43U));
            aWandererC = aWandererC + ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterC, 51U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterC, 26U)) + aNonceWordK) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterF, 57U)) + aNonceWordA);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterF, 37U)) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterJ, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 11U) + RotL64(aOrbiterF, 22U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererD, 6U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Billiards_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBE76D7E9944F02E7ULL + 0xA0D601022F799120ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC5492A4F8985C92DULL + 0xD1BD66AA5DAF4CEAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBDA2B63A6076BE6DULL + 0xC0D305E83B0094DEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEDDEA7F31323ECBBULL + 0xF730A9FDC9EB6186ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB3190A77AE5A3415ULL + 0x973121B8111A0D3CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE67091F124AE564DULL + 0xF601C5ADB26A8332ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEBB45386A6C93159ULL + 0x8F9505715FA31467ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA54B97690777FF03ULL + 0xE61E997EBE6608BCULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBB7FC9AC35C7DB71ULL + 0xE37855F7060191D5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF2AD006543B82E0DULL + 0xE507D7BD725B5CC7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB9B7C522A7906C9FULL + 0xF2F20A89FB8EE0B8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA0A1E7974D2515B9ULL + 0xD4D6CB42D6F1EE0FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDE2FE0E1BD70984BULL + 0xCC32BA79656670BAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF62621552FAEB93DULL + 0xE69CB626A580476DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE74CF4F35D94EEE7ULL + 0x8406293BA576A0CDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDDBDDACEF6DAA78FULL + 0xD93A186C173F7EA6ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneD, aExpandLaneA, aFireLaneC, aFireLaneA, aExpandLaneB, aWorkLaneB, aFireLaneB, aExpandLaneC, aFireLaneD, aWorkLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5143U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((aIndex + 385U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 303U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3944U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3565U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3855U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 9630214189402543339U) + aNonceWordP;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 39U)) + 4072576573737526819U) + aNonceWordD;
            aOrbiterD = ((aWandererC + RotL64(aCross, 11U)) + 15994787452709618869U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 60U)) + 6403240137132259482U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 5U)) + 10229266900170507720U) + aNonceWordK;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 5025294577989748989U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 29U)) + 16696461238217956883U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 56U)) + 9878318855341719119U) + aNonceWordH;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 16086635438116177346U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12295437783084203730U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7681150419912842402U;
            aOrbiterD = RotL64((aOrbiterD * 7289497379725191451U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2639104034287637448U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12298170009332243573U;
            aOrbiterC = RotL64((aOrbiterC * 9397919591171238575U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3485932317267669626U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16569551670038752475U;
            aOrbiterB = RotL64((aOrbiterB * 8139802826402217631U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4448490103784103954U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14510534073046885941U;
            aOrbiterF = RotL64((aOrbiterF * 7777192047386438305U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4286195398675733451U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15790355933840266463U;
            aOrbiterI = RotL64((aOrbiterI * 13342257823027075501U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6362891510370156055U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15121822034579983174U) ^ aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7268045994574844937U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13817341015719915628U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14113474087906143783U;
            aOrbiterJ = RotL64((aOrbiterJ * 12838910141533126059U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9988301252236121106U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11287477288382171758U;
            aOrbiterK = RotL64((aOrbiterK * 4979297247881426383U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9491727010910328644U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7961202721830514030U;
            aOrbiterG = RotL64((aOrbiterG * 16300364540313620767U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterD, 19U)) + aWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 34U) + aOrbiterJ) + RotL64(aOrbiterK, 28U)) + RotL64(aCarry, 53U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterI, 47U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 53U)) + aOrbiterF) + aNonceWordA) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 42U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aFireLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15394U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneC[((aIndex + 8597U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8443U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10610U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8468U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10964U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 40U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = (aWandererG + RotL64(aCross, 56U)) + 13350544654542863236U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 12364346790125404372U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 23U)) + 9738750172849512764U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererK + RotL64(aIngress, 3U)) + 3781373837635491421U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 16635020317512702337U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 39U)) + 5383653921676231276U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 10181959815492056493U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 34U)) + 10005510924273927017U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = ((aWandererB + RotL64(aCross, 19U)) + 9524687662265740565U) + aNonceWordC;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4259138552009771014U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8973051213213726023U;
            aOrbiterB = RotL64((aOrbiterB * 12625091476068190979U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17602611840127337490U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8218984546932905269U;
            aOrbiterC = RotL64((aOrbiterC * 17504305273683304231U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 18102186122213487888U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2629927500298092976U;
            aOrbiterE = RotL64((aOrbiterE * 6983280164448292723U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2491581597835795234U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9506602492971620955U;
            aOrbiterI = RotL64((aOrbiterI * 9559829640915637163U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13422942713680612924U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15037354693234876601U;
            aOrbiterJ = RotL64((aOrbiterJ * 12692376075738621447U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12896066842192894694U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2202952306291905855U;
            aOrbiterF = RotL64((aOrbiterF * 6779368532763429997U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12160313482450599313U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10812986281270407756U;
            aOrbiterG = RotL64((aOrbiterG * 7786608700746771809U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12474638293190144525U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5882870951276225224U;
            aOrbiterK = RotL64((aOrbiterK * 15532427302173572457U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3782896138051179209U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 10965680631059882311U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 14060923998307082385U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 4U);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterC, 37U)) + aNonceWordB);
            aWandererG = aWandererG + (((((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 41U)) + aNonceWordA) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterF, 24U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterG, 19U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 47U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 57U)) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterJ, 42U)) + aOrbiterB) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 11U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneB
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18469U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((aIndex + 22326U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24500U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21598U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16740U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 20214U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 22U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererJ + RotL64(aCross, 19U)) + 17454559218352016650U) + aNonceWordL;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 11U)) + 8005709669325164803U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 43U)) + 13393741948412816357U) + aNonceWordK;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 4U)) + 3665865624348875553U) + aNonceWordA;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 8334142570031883436U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 23U)) + 17226066128706139657U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 51U)) + 3319093033121522613U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 6657535603401588798U;
            aOrbiterI = ((((aWandererB + RotL64(aPrevious, 30U)) + RotL64(aCarry, 57U)) + 5469746182326331147U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17846791786050221418U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15939541003714896288U;
            aOrbiterB = RotL64((aOrbiterB * 1400351482213119809U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12076763190461077406U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3594038213596405284U;
            aOrbiterK = RotL64((aOrbiterK * 10244002692575821495U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8301291631324464622U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8460406137668390582U;
            aOrbiterG = RotL64((aOrbiterG * 9117147929757711595U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7612394867020871200U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 8525076134853103975U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 5790440201072204659U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11929899088215090379U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7119509166360685726U;
            aOrbiterC = RotL64((aOrbiterC * 1662341427992528823U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5081078459225240607U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17149991983909906705U;
            aOrbiterA = RotL64((aOrbiterA * 950223374568067343U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 8817303295675241994U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7962039282652745113U;
            aOrbiterJ = RotL64((aOrbiterJ * 12773588587795522121U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 13596273086338032370U) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8186297702278180956U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6226504769888753861U), 37U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 1696277861691580263U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17360461831507082959U;
            aOrbiterE = RotL64((aOrbiterE * 1651378456022210983U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 60U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterE) + aNonceWordC);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 39U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 47U));
            aWandererK = aWandererK + (((RotL64(aScatter, 18U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterC, 22U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterJ, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterF, 3U)) + aOrbiterK) + aNonceWordJ) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 28U)) + aOrbiterA) + aNonceWordB) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneA
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 24979U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((aIndex + 27336U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 31540U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24669U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27089U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31889U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 22U)) ^ (RotL64(aCross, 47U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = (aWandererK + RotL64(aIngress, 23U)) + 252059974543142812U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 42U)) + 11690823093681457368U) + aNonceWordM;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 13U)) + 13282189752890971123U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 29U)) + 9507416294305708435U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 14053038174390776539U) + aNonceWordP;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 14605253312318725009U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 51U)) + 18138286582677863671U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 6U)) + 8530091235978489988U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 14381731677571170073U) + aNonceWordG;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13316413456378978456U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3910529530149320706U;
            aOrbiterK = RotL64((aOrbiterK * 16000139333493588429U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6302070286831566901U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12324134652758551396U;
            aOrbiterF = RotL64((aOrbiterF * 17136438281540250165U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4773478557638475048U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4031153435446078944U;
            aOrbiterB = RotL64((aOrbiterB * 3876928995240982769U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3114794895962903899U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3552936509969106796U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16823186892738820299U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5828754613946145627U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 17985241114076114558U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1986669631395606833U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11319331046368072261U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6104267020171882160U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 12525117969211576177U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7662668379725735125U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 6583034411403600735U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 262095656452193889U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5569865728026310280U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4176065898330374039U;
            aOrbiterE = RotL64((aOrbiterE * 11305749530796963967U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13677146592276526676U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2734371113158117596U;
            aOrbiterI = RotL64((aOrbiterI * 13146444882662731975U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 34U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 24U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aCross, 28U) + aOrbiterK) + RotL64(aOrbiterA, 5U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterA, 47U)) + aNonceWordK);
            aWandererE = aWandererE + (((((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterH, 28U)) + RotL64(aCarry, 21U)) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterI, 51U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterF, 35U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Billiards_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8DC903C87E668AE3ULL + 0x8CF6182AF2E8ABD1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC2DAC8C1B48044B9ULL + 0xD3A228F8B1F8AD11ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8250A282C64D8D75ULL + 0xC42AAE69738DF775ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD1E3AD5F2EB100FFULL + 0xCFC9519ACCD081B5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCB3C5A4DBAAB35B7ULL + 0xECB495B8E6B41A4EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x88FF83662D6BB2F7ULL + 0xAB3A16162463EA63ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x90BEA5EED2E7CA43ULL + 0x8C0A0D92D72D8ADBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD1C9EC29EC363805ULL + 0xA4F20366CE7BEADAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDE18E0C1E281F6E7ULL + 0xEEBDF5F1D9571888ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAFD15493103AD085ULL + 0xF06F73AD8A343E79ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9A43BC1FEB77E5CFULL + 0x8920AA7DAF8902C7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC264194BDD1D907FULL + 0xD637686F55F52C84ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB3C48AC39EAF76A9ULL + 0xF012530F7EA4C362ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xABC2A81BC97D1445ULL + 0xBD329241F5A32080ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBC0A9558A8CD0D19ULL + 0xFBF831C07ED09EAEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xADA7B8CB0308BEB3ULL + 0xAB820A5C990B2822ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aOperationLaneD, aOperationLaneA, aExpandLaneB, aOperationLaneB, aFireLaneC, aExpandLaneC, aFireLaneB, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1432U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 2575U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5963U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6035U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1720U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 2449U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 60U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 41U)) + 15549114274303128055U) + aNonceWordA;
            aOrbiterG = ((aWandererA + RotL64(aCross, 35U)) + 16466750056388063241U) + aNonceWordB;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 12209449840836787142U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 14551496099734294336U) + aNonceWordN;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 27U)) + 6266576428679808622U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aWandererE + RotL64(aScatter, 47U)) + 16892841575635668152U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 13U)) + 7375966221423362125U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11926105302821753530U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16219253791550461124U;
            aOrbiterF = RotL64((aOrbiterF * 2117550758226173419U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7299056065319248160U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15234001484933728439U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8182244796017018911U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6615802589932632120U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5481176858895819247U;
            aOrbiterE = RotL64((aOrbiterE * 3604590158551984877U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17220507586542139380U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14137921473739415340U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 10634645686035907603U), 43U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 16981960446540932787U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10897565927079518588U;
            aOrbiterD = RotL64((aOrbiterD * 418843936329303571U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2746889569299593263U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4894117146736361379U;
            aOrbiterK = RotL64((aOrbiterK * 2656750612042673191U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18294823016957137777U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 86828501068883383U;
            aOrbiterG = RotL64((aOrbiterG * 11432686669235402365U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterG, 43U)) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterA, 57U)) + aOrbiterK) + aNonceWordG);
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + aNonceWordK);
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 50U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 12U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13292U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 8198U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14710U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10962U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10002U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15176U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 24U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 13U)) + 16462052553719977502U) + aNonceWordO;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 5U)) + 12337064059566619581U) + aNonceWordB;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 43U)) + 15801005007094515447U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 23U)) + 8228706742665081656U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 11006723027845190869U;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 18173765337829177450U) + aNonceWordA;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 27U)) + 530215083653542558U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 6608611827035564511U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2246051826221626809U;
            aOrbiterI = RotL64((aOrbiterI * 6333352641495253539U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5228575308895381421U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10999213210689606857U;
            aOrbiterC = RotL64((aOrbiterC * 5467601259546342925U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3773371037240485696U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8887985779436152504U;
            aOrbiterB = RotL64((aOrbiterB * 698713082830739677U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11150566414723818350U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 8336366151003049546U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9033771197242493699U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13233968794237090787U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8172558473508478819U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17837070423649268435U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 133564480283347997U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15104810248883567064U;
            aOrbiterG = RotL64((aOrbiterG * 706802420642303533U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9138629520201127075U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13993086066341664080U;
            aOrbiterE = RotL64((aOrbiterE * 4875046427147105077U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 56U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + aNonceWordC) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 47U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererD = aWandererD + (((((RotL64(aCross, 21U) + RotL64(aOrbiterH, 53U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aNonceWordL) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 12U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17892U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneD[((aIndex + 20489U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20879U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24336U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18625U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 18652U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 18U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = ((aWandererE + RotL64(aScatter, 5U)) + 1888427424966603593U) + aNonceWordG;
            aOrbiterJ = ((((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 5436761445660415091U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 17322876217962143270U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 57U)) + 9728299982740564979U) + aNonceWordE;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 301720335271716921U) + aNonceWordO;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 37U)) + 8069685428854814396U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 50U)) + 1973715500949100991U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 87666408799854155U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12195436904339035245U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15427739165893738105U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4578742069143400295U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7828776048774876484U;
            aOrbiterH = RotL64((aOrbiterH * 4047964518501081039U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17203146364542781833U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16913369550858890466U;
            aOrbiterC = RotL64((aOrbiterC * 13534417587921978507U), 13U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 9632761514552265402U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9106637671877341286U;
            aOrbiterD = RotL64((aOrbiterD * 9073709119482640391U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 15423680889126750876U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6087310684583331882U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8964465129744898619U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5420955876411796789U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14166807419730848032U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 442659738632823751U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8118312450347026824U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4253043584558403086U;
            aOrbiterA = RotL64((aOrbiterA * 5651748455190536467U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF) + aNonceWordB);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 38U)) + RotL64(aCarry, 57U)) + aNonceWordI) + aWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 5U)) + aOrbiterA) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + aNonceWordH);
            aWandererD = aWandererD + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 19U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27930U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 30299U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25066U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29234U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30140U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 30549U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (aWandererE + RotL64(aCross, 43U)) + 13442819395490639310U;
            aOrbiterB = ((((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 8187292523194120936U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 11U)) + 11469697159823131388U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 3U)) + 13414083692375929653U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 11404010733687907517U) + aNonceWordE;
            aOrbiterI = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 6783212827186218247U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 58U)) + 8561131439340372614U) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6252609642004429113U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12804867444200448952U;
            aOrbiterD = RotL64((aOrbiterD * 3114688959081972615U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2739648749603690781U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14808861217017399752U;
            aOrbiterF = RotL64((aOrbiterF * 373911885694012101U), 11U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 17588866502571268888U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5882260142735642980U;
            aOrbiterG = RotL64((aOrbiterG * 7688252946143263869U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15493099088132862949U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5175647411532429582U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15226544495598541883U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14279707376173642767U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 6826363572161275158U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 5263708315440161809U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13267185753040999992U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 9980987858092888720U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 13210290848800728635U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3582972937645514549U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10140409019562890804U;
            aOrbiterI = RotL64((aOrbiterI * 6944490201647678479U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 51U)) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterD, 13U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 4U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Billiards_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF73CCF30A4E2A2A1ULL + 0x905CB1EB49523327ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE0CC69884826C591ULL + 0x86909C04D1209899ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8D06C40C89CA60A3ULL + 0xEE0F851AAE3F6DC5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xACFBF100FBB91275ULL + 0xE4F9A3DA0BA5243DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFC3E29A1239445D9ULL + 0xEBE2328F07908540ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8688F44C7081411FULL + 0xA127AF4156EEF504ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA5B947467626EABDULL + 0xE5162E9F8E150135ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDBC0694B406BECA9ULL + 0xA7E5AE0A02D61F18ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF43E8D3FF4A3FBE7ULL + 0xAFCE74A4FA25AB62ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE9B438207E303DEFULL + 0x842F1C86FBEF8B77ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAD1787600AFAFE69ULL + 0xA70A452335636B2DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB54E3554F52AF765ULL + 0xA33EB375C29EF9FBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC392A2152971E883ULL + 0xAEB73A4D2CAA20B7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBEE74098F2673591ULL + 0x88ED0A88C70AA2FFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEEAE295065A106A1ULL + 0xADBB32CEDC3A1854ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD50444D4297FE747ULL + 0x9CB6B4933B99F630ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2041U)) & W_KEY1], 40U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 766U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1310U)) & W_KEY1], 4U) ^ RotL64(mSource[((aIndex + 278U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (((aWandererC + RotL64(aCross, 13U)) + 1952750591494698524U) + aPhaseEOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 4488270851303332830U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 42U)) + 2738763375328927635U) + aNonceWordG;
            aOrbiterD = ((((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 6728843649480454340U) + aPhaseEOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aWandererD + RotL64(aCross, 23U)) + 10490717875258865358U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 51U)) + 1429288737812910205U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 2761375016998907636U) + aNonceWordH;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 1088988605204499835U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6829840407300289709U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13101432880030791787U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9267240337867690471U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 8120113021183975703U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 14296504593187173107U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1340980511302566784U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11874452169979878835U;
            aOrbiterB = RotL64((aOrbiterB * 8638486178860092537U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 1872314794140971426U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6013952618696225751U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 7994863587373565715U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3644011378086236002U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8501867691997891731U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 7115282675461711509U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2493546555198066143U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5179240189571799179U;
            aOrbiterD = RotL64((aOrbiterD * 1267579130962756135U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11273348247858394197U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4577476419423118925U;
            aOrbiterI = RotL64((aOrbiterI * 8427261005061162673U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 50U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterF, 29U));
            aWandererK = aWandererK + (((((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 19U)) + aNonceWordK) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 6U) + aOrbiterK) + RotL64(aOrbiterF, 37U));
            aWandererC = aWandererC + ((((RotL64(aCross, 51U) + RotL64(aOrbiterD, 51U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterD, 19U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 58U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4196U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadA[((aIndex + 5311U)) & W_KEY1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2766U)) & W_KEY1], 58U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5223U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 4U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 4634399531433127141U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 10U)) + RotL64(aCarry, 23U)) + 16961792729406903200U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 53U)) + 4105280732301137738U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 27U)) + 15692013501147331191U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 43U)) + 1252216715968780587U) + aNonceWordO;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 7958289043012473752U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 3U)) + 6611577301818896615U) + aNonceWordA;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8506226754305949140U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3648813120449403353U;
            aOrbiterJ = RotL64((aOrbiterJ * 9521367946879238849U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5195245426245535735U) + aNonceWordB;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 542948051600803051U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 4631106308856448475U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11974253551208964789U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10596463592332655367U;
            aOrbiterE = RotL64((aOrbiterE * 10941161258815714641U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12015129484061440159U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8254944355710109060U;
            aOrbiterI = RotL64((aOrbiterI * 3233697992479357615U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2754858806943915419U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5007802002906662779U;
            aOrbiterB = RotL64((aOrbiterB * 15613733948331639723U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6262190752136523216U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 10528977986487821428U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 1184258264034585525U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8511097226098211854U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12091864735686692582U;
            aOrbiterG = RotL64((aOrbiterG * 6128140528141411237U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 20U) + aOrbiterE) + RotL64(aOrbiterF, 51U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 11U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterI, 41U)) + aNonceWordJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 29U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 3U)) + aPhaseEWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5904U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7756U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7062U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6892U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6385U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 18U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 15813325389431304548U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 2223874171125403602U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 29U)) + 5510483568496824130U;
            aOrbiterK = ((((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 15474152493495661876U) + aPhaseEOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 11U)) + 16846339705130829195U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 22U)) + 1289670576865739669U) + aNonceWordE;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 35U)) + 18017354919647006944U) + aNonceWordK;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8539685539928984921U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3333721400836704048U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 3745286323481400085U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 2261560416623815491U) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 4377786131746816567U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9164777834392621157U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18047393176583722719U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8184724021940434631U;
            aOrbiterK = RotL64((aOrbiterK * 9800116157750921119U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10469895939183324807U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14543391765109879223U;
            aOrbiterD = RotL64((aOrbiterD * 4817987697437667225U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5757225781746158178U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3539000495894022869U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1032298408884695925U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11288971092707065923U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2761384065186568294U;
            aOrbiterB = RotL64((aOrbiterB * 3323838837427471051U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7120580145300417101U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6977246291769372866U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 15170353875184253779U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 18U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 36U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 37U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9441U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 9501U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(mSource[((aIndex + 8934U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8826U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8489U)) & W_KEY1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10509U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 48U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (aWandererJ + RotL64(aIngress, 13U)) + 12583180859826261500U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 37U)) + 9067093488553721468U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 12173106198862881754U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 29U)) + 11333491014394592654U) + aNonceWordO;
            aOrbiterF = ((((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 3511883526940919554U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 7416810692106273044U) + aNonceWordJ;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 46U)) + 8341174972619784110U) + aNonceWordN;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2220852854836962979U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8090781422229383825U;
            aOrbiterJ = RotL64((aOrbiterJ * 578293950675644397U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2338801236599102223U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12484514711848308104U;
            aOrbiterF = RotL64((aOrbiterF * 10364216764253366067U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13684861340589131816U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12796636819991873058U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5533508014234835669U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7634198650894837690U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 10240326122201201762U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8758703497719125901U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4162814763739453934U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2766504649149048469U;
            aOrbiterA = RotL64((aOrbiterA * 16731843453895178671U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11051393030148769655U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 17687055068651386665U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 1042927176246229537U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3353615315436983420U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5971640796220306310U;
            aOrbiterD = RotL64((aOrbiterD * 15804313508835034807U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterB, 50U)) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 21U)) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 13U)) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 35U)) + aOrbiterE) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + aPhaseFWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 58U) + aOrbiterE) + RotL64(aOrbiterA, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12873U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 11921U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12650U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 12526U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13173U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12857U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12824U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 40U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 41U)) + 8506388683755208267U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 51U)) + 2179323259055019735U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 11U)) + 3345902531140983016U) + aPhaseFOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 43U)) + 17456139311481306584U) + aNonceWordD;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 14587864088462311164U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 30U)) + RotL64(aCarry, 57U)) + 13178947246650647057U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 21U)) + 12866578138946916962U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 13098524333655118173U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15451329483787541982U;
            aOrbiterH = RotL64((aOrbiterH * 13580376920467431451U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9494299579678389385U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15581954810375490643U;
            aOrbiterJ = RotL64((aOrbiterJ * 13670002280188424825U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 4487042505730624892U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2774455928791636186U;
            aOrbiterE = RotL64((aOrbiterE * 15847933919136777451U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12435319582397755819U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10077180055177766823U;
            aOrbiterB = RotL64((aOrbiterB * 3924363471701748703U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10391963896910956455U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6149237416725301794U;
            aOrbiterG = RotL64((aOrbiterG * 10115917698918612823U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15673402771629639978U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14729117178956592426U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9070464269215820531U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14492001279368870240U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6278248084483259952U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 16731228350971263873U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 34U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 11U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 53U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 28U) + aOrbiterC) + RotL64(aOrbiterJ, 41U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + aNonceWordI) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 51U)) + aNonceWordM) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterB, 21U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14767U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16271U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16368U)) & W_KEY1], 56U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13690U)) & W_KEY1], 3U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15807U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14282U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14428U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 6973892330986118220U) + aNonceWordP;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 27U)) + 9886813896272094864U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 10996306582517553173U;
            aOrbiterF = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 8490648283899856223U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 54U)) + 105141713530704655U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 21U)) + 3114337422810562588U) + aNonceWordF;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 41U)) + 980857684690886131U) + aPhaseFOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6562042345807072665U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15665371138706353619U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8086237578564620623U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18113013571374375028U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17405346422601997299U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 11162604605443005253U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5130876096426182506U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1813821672299154629U;
            aOrbiterG = RotL64((aOrbiterG * 15478100342425611875U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15793814882743306728U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13925299440495476399U;
            aOrbiterF = RotL64((aOrbiterF * 12049601510660117401U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 9924458846049579438U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 7810034662781768090U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 10310594595026622513U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 12812586478656872854U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5709576448057435237U;
            aOrbiterA = RotL64((aOrbiterA * 9101555233909853025U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7839807649914541516U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4717944526755429647U;
            aOrbiterC = RotL64((aOrbiterC * 8515229146471335721U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 4U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 39U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 47U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterG, 57U)) + aNonceWordM) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterK, 4U)) + aOrbiterG) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterC) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18195U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 17453U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(mSource[((aIndex + 18835U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 18243U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16410U)) & W_KEY1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17935U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17908U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aPrevious, 57U)) + (RotL64(aCross, 44U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 57U)) + 13687218104610230596U) + aPhaseGOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 6841550124960692709U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 17418968668458764131U) + aPhaseGOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 8303537912696948204U) + aNonceWordK;
            aOrbiterI = (aWandererA + RotL64(aIngress, 35U)) + 12376614417285936537U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 43U)) + 14215749063579232654U) + aNonceWordI;
            aOrbiterG = (aWandererI + RotL64(aScatter, 20U)) + 4111736931433665347U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11250375934571631522U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5367367837773331275U;
            aOrbiterE = RotL64((aOrbiterE * 7262723007545807179U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15514089192382674434U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1475991716685034960U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 17720681295551650891U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5531622777788629748U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8363822215908303335U;
            aOrbiterH = RotL64((aOrbiterH * 17850203366840994883U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3741256932685720414U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11634667238062155772U;
            aOrbiterK = RotL64((aOrbiterK * 15925089729784547403U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 18180546911210417155U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5123234656838556335U;
            aOrbiterI = RotL64((aOrbiterI * 15362857462853398025U), 3U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 11215734271189250284U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16863747802158398092U;
            aOrbiterG = RotL64((aOrbiterG * 1828035970246160023U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9859050606636646323U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9331300036643654675U;
            aOrbiterC = RotL64((aOrbiterC * 2502263410556166281U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + aNonceWordC) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + aNonceWordO);
            aWandererD = aWandererD + ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterC, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 28U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterI, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21333U)) & S_BLOCK1], 38U) ^ RotL64(mSource[((aIndex + 19223U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21294U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 19148U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19535U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19763U)) & W_KEY1], 47U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19147U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 19945U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 43U)) + 13499155707765393469U) + aNonceWordN;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 4U)) + RotL64(aCarry, 5U)) + 3740324981823726185U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 5470765363949735652U) + aPhaseGOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 51U)) + 3446436171274452326U) + aNonceWordA;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 13U)) + 1778929412631211933U) + aPhaseGOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 14666308799855220954U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 27U)) + 4548410236791175055U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5829739767694190372U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 14319231414903675748U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 4966501102515775601U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1513851750246111405U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1685620217748986019U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 9286548037413609445U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16284162182006054402U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6271539598462003309U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13923286694131331137U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12669312437565969473U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 11894755313393001665U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 12556759675372354075U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6315983824634946566U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17106616474222892782U;
            aOrbiterD = RotL64((aOrbiterD * 167205520766791073U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13350266700180455548U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4608846311203767162U;
            aOrbiterF = RotL64((aOrbiterF * 2504857468837437365U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14195866746143604365U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 7917977448256795054U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5927771378657284557U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 58U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterB, 44U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 27U)) + aOrbiterI) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 12U) + aOrbiterD) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + aNonceWordK);
            aWandererF = aWandererF + ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterB, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterC, 51U));
            aWandererG = aWandererG + (((((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aNonceWordF) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23014U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 23911U)) & W_KEY1], 60U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22330U)) & W_KEY1], 11U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22218U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23993U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21943U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23311U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((aIndex + 23809U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 36U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 13296600294247799698U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 5818503518080877515U) + aPhaseGOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 21U)) + 6735784238734173597U) + aNonceWordI;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 51U)) + 7368398209488856201U) + aNonceWordH;
            aOrbiterI = (aWandererD + RotL64(aScatter, 43U)) + 961734029066455638U;
            aOrbiterG = (aWandererA + RotL64(aCross, 11U)) + 797011946660892011U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 35U)) + 12841876018396622350U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 16213253970483895623U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15186950557113470375U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4647470430467908107U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5117930310827477341U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12265429373166094162U;
            aOrbiterI = RotL64((aOrbiterI * 1522823535151532249U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13920531346698601568U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14695405206998211456U;
            aOrbiterE = RotL64((aOrbiterE * 13950964363414164279U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7851960904825938443U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9501511171732550190U;
            aOrbiterJ = RotL64((aOrbiterJ * 5614164120361489613U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5663365182245722077U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9607860124321315555U;
            aOrbiterG = RotL64((aOrbiterG * 3461820361914280601U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 18171052650586819280U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3442698321538580861U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6317525514963824829U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1491052813469258970U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3956599824067616133U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 2928600779267623085U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 44U) + aOrbiterA) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 37U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + aNonceWordL);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 12U)) + aOrbiterI) + aNonceWordP) + aPhaseGWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererB, 56U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25560U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 26212U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26483U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26135U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26955U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24684U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25217U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((aIndex + 24778U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 50U)) + (RotL64(aIngress, 37U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (aWandererE + RotL64(aIngress, 60U)) + 9774364261626083532U;
            aOrbiterG = ((((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 18059001521926116420U) + aPhaseHOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aWandererB + RotL64(aScatter, 23U)) + 10615626210406381148U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 37U)) + 10536484278007898620U) + aNonceWordE;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 13320663045139972700U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 17127001787268166583U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 53U)) + 16742574590844166551U) + aPhaseHOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8347719720758228053U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13502468705946051986U;
            aOrbiterD = RotL64((aOrbiterD * 13822952083584784695U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3512687886188904904U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 495660316165795934U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6724596801190194913U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5092722552034477356U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15641128019608284015U;
            aOrbiterH = RotL64((aOrbiterH * 3621036395703527059U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15421873776811085458U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17978775513204574125U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18359600395119440183U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16617179197537669849U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1931805387534012528U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 3400139345857733775U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9544923119559308431U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12930999400470173353U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16791006919271490005U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 13673733276226249890U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2032263473309124738U;
            aOrbiterE = RotL64((aOrbiterE * 3088728329261360607U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 29U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 21U)) + aOrbiterH) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 11U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterI, 46U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + aPhaseHWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 43U)) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 37U)) + aOrbiterD) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29861U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((aIndex + 29353U)) & S_BLOCK1], 46U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29026U)) & W_KEY1], 3U) ^ RotL64(aFireLaneC[((aIndex + 28235U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29947U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29900U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30019U)) & S_BLOCK1], 48U) ^ RotL64(aFireLaneB[((aIndex + 29490U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 11U)) + (RotL64(aPrevious, 24U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 4U)) + RotL64(aCarry, 57U)) + 3684295017013759987U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 39U)) + 6740408842457292881U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 27U)) + 4563975890702399441U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 797804144825287940U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 2763779540450101303U) + aNonceWordM;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 13U)) + 13211846164102089685U) + aNonceWordG;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 19U)) + 15214578447281401982U) + aNonceWordH;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13745208628754232427U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 17358621225969190747U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5325024317338823061U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 779739369960480023U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4370963533701407813U;
            aOrbiterF = RotL64((aOrbiterF * 3123135216876641039U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6061333005507739975U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3589705340762734456U;
            aOrbiterK = RotL64((aOrbiterK * 16499293983611196967U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10607697666369230567U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 9356757995305239271U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10945513661439954731U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10093033335903048138U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11037328061699834100U;
            aOrbiterG = RotL64((aOrbiterG * 11189760551792389605U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 558431161176115540U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17795680919453449358U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3910117359996283803U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6096779391116214109U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17594243286880690775U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 12655610181937429915U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 53U)) + aOrbiterK) + aNonceWordE) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ) + aNonceWordC);
            aWandererF = aWandererF + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 4U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 21U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 43U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + aPhaseHWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 22U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31100U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30714U)) & W_KEY1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31754U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31779U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30273U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31021U)) & W_KEY1], 43U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (aWandererF + RotL64(aPrevious, 27U)) + 4970414922752555648U;
            aOrbiterC = (aWandererH + RotL64(aCross, 43U)) + 9462756592787669327U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 3948790686662213095U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 57U)) + 14542857212241578311U) + aPhaseHOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 3387479009827029547U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 51U)) + 1411421370057797877U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 14U)) + RotL64(aCarry, 29U)) + 16894451466895681236U) + aNonceWordM;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12727136462290223542U) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 4625389198191960525U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 5726474430977810191U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3471881403786164913U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6433115856048534831U;
            aOrbiterJ = RotL64((aOrbiterJ * 9363233870194144053U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9825592965466157982U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 1553125767261293088U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 411535191177308781U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9951616357109647617U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 11231080382787286889U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14024961994986659187U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13419663264017317947U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4835055642466215566U;
            aOrbiterE = RotL64((aOrbiterE * 17898065852351759171U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14558747666410946768U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 13120938960926874504U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5681766019285559739U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11910501376797343986U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15074100100781785300U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 228976960937473851U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 18U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + aNonceWordH);
            aWandererF = aWandererF + (((((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 27U)) + aNonceWordF) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterC, 5U)) + aNonceWordA);
            aWandererD = aWandererD + ((((RotL64(aCross, 44U) + RotL64(aOrbiterB, 34U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterI, 47U));
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 41U)) + aOrbiterB) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 28U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
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

void TwistExpander_Billiards_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9879882A69B84D3FULL + 0xA364B167A9281D70ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEAC3AD861B62F31FULL + 0xF0937F30319ED120ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8F8C41EB66AC89C7ULL + 0xCF63FD4BA39920E0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCBDFC9491ED37863ULL + 0xD2AC6D15BF618B47ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE3D2AF9940C4C61FULL + 0xC899C2ABF1FBA297ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC22BE9826CA2D9D5ULL + 0xB5DA7ED6A3716B31ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD146CBE317378E57ULL + 0xFAD8741A3A49EB4BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC20FC8A6990838BBULL + 0xA1E2F854D1F55053ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x81A433BD904578B1ULL + 0xA0331118A3B564D8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC82948DF1943440BULL + 0xD1C7EE80A4A7AD6FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xABBCFC03DA8DDCD9ULL + 0xC7CEF99C9FB7B329ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE0D135CC7E14EDC5ULL + 0xA94D25E971D68739ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA73682830C7013B9ULL + 0x82C235D6644C5E6AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC3E4CD3D4C6FFD97ULL + 0xB7375EFAA0CB0688ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEAE5923CE6C6F8EFULL + 0xFDB0AFF87DF26D39ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF886AE850006B57DULL + 0xAD840EDD9E06F1B2ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneB, aInvestLaneB, aFireLaneA, aOperationLaneA, aFireLaneC, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4329U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 4278U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 4855U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1700U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3207U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 36U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = ((((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 77518479758428414U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aWandererF + RotL64(aCross, 54U)) + 4832061802166300011U) + aNonceWordP;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 11695291171006574112U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 7467412817843260094U) + aNonceWordJ;
            aOrbiterG = (aWandererA + RotL64(aCross, 3U)) + 17801484124471154757U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5555455638503958639U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5669470540733721606U;
            aOrbiterK = RotL64((aOrbiterK * 17219613748084498879U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 3042388456327784163U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2236734925228156691U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 10076582424701705531U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14459720401528685450U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4814967631216658856U;
            aOrbiterC = RotL64((aOrbiterC * 18288097536171386643U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16950679344449075945U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6262238639302011050U;
            aOrbiterA = RotL64((aOrbiterA * 9942659897425088183U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3522256359074996724U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12524717897707074242U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6787771338063891989U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 4U) + aOrbiterK) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 41U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 5U)) + aOrbiterC) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterC, 29U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + aNonceWordC) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneB
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 7599U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 7814U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5820U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5462U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 5890U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 60U)) ^ (RotL64(aCarry, 29U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (aWandererJ + RotL64(aScatter, 23U)) + 9107326720193244489U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 10868585484401664145U) + aNonceWordB;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 48U)) + 13637736741437846622U) + aPhaseAOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 6130725216183918844U) + aPhaseAOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 2063834478521338187U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8564870627911949158U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 6524015751064086390U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 12055267995727104463U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9874937766875388236U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14723718409522680894U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17379140128833323431U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 13767059954741528279U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6387608251033722169U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 6601902195707980693U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5391425980008431000U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11524218415655093779U;
            aOrbiterD = RotL64((aOrbiterD * 12508457981779189389U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 155510463350385905U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10554591788433641311U;
            aOrbiterI = RotL64((aOrbiterI * 5412084824127934293U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 21U)) + aOrbiterF) + aNonceWordM);
            aWandererK = aWandererK + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 50U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + aNonceWordG) + aPhaseAWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 15710U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 13772U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 15378U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11373U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12329U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15461U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 4U)) + 9751314027302668907U) + aNonceWordA;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 53U)) + 12175450995523107056U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 17519694958730119552U) + aNonceWordM;
            aOrbiterK = (((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 9093525527925682263U) + aNonceWordH;
            aOrbiterG = ((((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 3713831321786810138U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 10108355209191835040U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 12956307447311314768U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 9198936928658626667U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1904298513945877359U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 4658049993308574460U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10482422152074338611U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9826333658248851902U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12058666914724365134U;
            aOrbiterG = RotL64((aOrbiterG * 964233873188373939U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 2516574707110528099U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13335308331049750235U;
            aOrbiterK = RotL64((aOrbiterK * 5880227828760598587U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8230749255538495304U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16536559486797811486U;
            aOrbiterC = RotL64((aOrbiterC * 7097036838156464969U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + aPhaseAWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterE, 53U)) + aNonceWordF);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordL) + aPhaseAWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 22U) + RotL64(aOrbiterC, 26U)) + aOrbiterG) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17081U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneA[((aIndex + 18541U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 18858U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18496U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17750U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18630U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 39U)) + 17264605017518259932U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 15209184354580778643U) + aNonceWordI;
            aOrbiterB = ((aWandererF + RotL64(aCross, 22U)) + RotL64(aCarry, 47U)) + 3299527965014731384U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 16293096431816127821U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 3U)) + 11031983436878828337U) + aNonceWordB;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9188018632448236358U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13420816400363406556U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 10958221259662190519U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2485063384097917101U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3089135816938128264U;
            aOrbiterA = RotL64((aOrbiterA * 8813152992957361153U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10730544971770435788U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10431767565618874806U;
            aOrbiterD = RotL64((aOrbiterD * 4723078464590561545U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14883796491656899074U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13465877783538483706U;
            aOrbiterK = RotL64((aOrbiterK * 14311686051108108503U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 13322163435314643713U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3307316600284371955U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12337846092069506365U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 27U)) + aOrbiterK) + aPhaseAWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 12U) + aOrbiterD) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 23U)) + aNonceWordK);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterI, 19U)) + aPhaseAWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26285U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 24615U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23788U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26856U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23902U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 25272U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 4U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((((aWandererE + RotL64(aCross, 56U)) + RotL64(aCarry, 11U)) + 10805654776556844351U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 582794182442795335U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 21U)) + 2858343650974681068U) + aNonceWordA;
            aOrbiterF = ((((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 8189584049022064284U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 3U)) + 1565100751996962893U) + aNonceWordH;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8062028016947611891U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 8280504280578451745U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 5212851648135050483U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11326869194491655350U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 1671695656567777163U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 7511554500524257921U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2349843105293943452U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 13015545152052004254U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1316662811685429983U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 16703354404749291869U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 8713231044374305801U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 9242480982197688625U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 11118401674497783533U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14857556493734710364U;
            aOrbiterI = RotL64((aOrbiterI * 3452566050389715195U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 38U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterG, 24U)) + aNonceWordF) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 13U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + aNonceWordN) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 13U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 52U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28396U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 32654U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 32463U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31656U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32601U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 32074U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 48U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 3255291173184001106U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aCross, 53U)) + 15308468160116255528U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 20U)) + 18186972408589866656U) + aNonceWordM;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 4439324265978331914U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 43U)) + 13099263173016322486U) + aNonceWordD;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 7041561081767500660U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6196422612687812971U;
            aOrbiterF = RotL64((aOrbiterF * 13359900204297781063U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 7664260932541281413U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17802347823020441056U;
            aOrbiterC = RotL64((aOrbiterC * 2220679459017369255U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4253107484061190446U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 13799496534030645312U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 9167675060053848207U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14252892847595951926U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5663527578664291422U;
            aOrbiterG = RotL64((aOrbiterG * 18314294235895182465U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11148755959699137661U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 17036900929333594592U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 16041243617369003291U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 18U)) + aOrbiterH) + aNonceWordG) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterC, 51U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 58U) + aOrbiterF) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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

void TwistExpander_Billiards_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC9D940A1B8400EC7ULL + 0xA570E49B7F2967F4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFEC202A960EF977BULL + 0xE54B5B527A172137ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE9FDC52FD435CE23ULL + 0xEA83728190F9D27AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDB63A675DA5F85B9ULL + 0xCDF2E0F3B0C8650AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB44026C1020452C1ULL + 0xA6ABDBE3D4876ABBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEE0B37BADC011E59ULL + 0x9D9A41D631CC557AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF0B194898ED265DBULL + 0x9F8E7023FE65971AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA55A84239C1DB3FFULL + 0xF1E480DDB3D89279ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8480DC41134EB79DULL + 0xE53C7429826002C9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC344C86C9E809EE9ULL + 0x8C1F2B605FE0BC4FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE85B4DBB5005D947ULL + 0xB7A02EE749EEC6D4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE6707E5B9DDFDF31ULL + 0xBD4D1B93B8788CA5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x89705E576E51A493ULL + 0xAD63ACECC5CEB1A3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB2872A525ADBE267ULL + 0xC44C96BE18495322ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB023171B28BABD33ULL + 0x8D563CC78E3D0328ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9FC40D68411DC0CFULL + 0xE655DAF41D780281ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneD, aOperationLaneC, aOperationLaneD, aExpandLaneC, aInvestLaneC, aFireLaneC, aFireLaneA, aInvestLaneD, aFireLaneB, aWorkLaneA, aExpandLaneA, aWorkLaneB, aExpandLaneB, aWorkLaneC, aFireLaneD
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4564U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 7U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 1739U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1535U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1311U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4078U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 40U)) + (RotL64(aIngress, 19U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 1952750591494698524U) + aNonceWordF;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 4488270851303332830U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 47U)) + 2738763375328927635U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 19U)) + 6728843649480454340U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 56U)) + 10490717875258865358U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 1429288737812910205U;
            aOrbiterE = (aWandererF + RotL64(aCross, 51U)) + 2761375016998907636U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 39U)) + 1088988605204499835U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 10U)) + 6829840407300289709U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9267240337867690471U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8120113021183975703U;
            aOrbiterJ = RotL64((aOrbiterJ * 14296504593187173107U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1340980511302566784U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11874452169979878835U;
            aOrbiterI = RotL64((aOrbiterI * 8638486178860092537U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1872314794140971426U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 6013952618696225751U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 7994863587373565715U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3644011378086236002U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8501867691997891731U;
            aOrbiterB = RotL64((aOrbiterB * 7115282675461711509U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2493546555198066143U) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 5179240189571799179U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 1267579130962756135U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 11273348247858394197U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4577476419423118925U;
            aOrbiterH = RotL64((aOrbiterH * 8427261005061162673U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6201955123046621919U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3930651302557530185U;
            aOrbiterE = RotL64((aOrbiterE * 1563512534463027965U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7571426325227856019U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11098508505512361002U;
            aOrbiterC = RotL64((aOrbiterC * 9229352429618815089U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6154830144380484305U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4282054616147137364U;
            aOrbiterG = RotL64((aOrbiterG * 14984813139796280171U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 4U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 10U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 43U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 39U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterK, 6U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 24U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 27U)) + aOrbiterK) + aPhaseBWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 4U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneA backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9194U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 8381U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10485U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 7002U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7905U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8030U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6934U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 52U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 43U)) + 4634399531433127141U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 54U)) + RotL64(aCarry, 5U)) + 16961792729406903200U) + aNonceWordI;
            aOrbiterI = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 4105280732301137738U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 39U)) + 15692013501147331191U) + aPhaseBOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aWandererA + RotL64(aIngress, 29U)) + 1252216715968780587U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 35U)) + 7958289043012473752U) + aPhaseBOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 58U)) + 6611577301818896615U) + aNonceWordB;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 8506226754305949140U;
            aOrbiterF = (aWandererF + RotL64(aCross, 13U)) + 3648813120449403353U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5195245426245535735U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 542948051600803051U;
            aOrbiterI = RotL64((aOrbiterI * 4631106308856448475U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 11974253551208964789U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10596463592332655367U;
            aOrbiterC = RotL64((aOrbiterC * 10941161258815714641U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12015129484061440159U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8254944355710109060U;
            aOrbiterB = RotL64((aOrbiterB * 3233697992479357615U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2754858806943915419U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5007802002906662779U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 15613733948331639723U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6262190752136523216U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10528977986487821428U;
            aOrbiterK = RotL64((aOrbiterK * 1184258264034585525U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8511097226098211854U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12091864735686692582U;
            aOrbiterJ = RotL64((aOrbiterJ * 6128140528141411237U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 4970966265236842566U) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10728884018459718341U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 18205183219769602827U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13760057185629905360U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6590269178744829056U;
            aOrbiterH = RotL64((aOrbiterH * 14482684769712170123U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 765826377665103262U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9364759196106579706U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10315111163659289329U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 44U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterI, 18U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 28U) + RotL64(aOrbiterC, 13U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterC) + aNonceWordJ);
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterE, 22U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 3U)) + aOrbiterK) + aPhaseBWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterB, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 12U) + aOrbiterA) + RotL64(aOrbiterC, 51U));
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15692U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 14795U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11867U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15832U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 12870U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 19U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 8988572360732005217U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aCross, 12U)) + 17889613225105985335U) + aNonceWordC;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 29U)) + 15563478320513948626U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 47U)) + 3441351228410524816U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 4425592689451435346U) + aNonceWordP;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 35U)) + 12733160231627305928U) + aNonceWordK;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 58U)) + RotL64(aCarry, 23U)) + 3574152157304607854U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 5U)) + 15167631896729808783U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 41U)) + 15822667973915417055U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17181685481076577637U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9979204751408873468U;
            aOrbiterA = RotL64((aOrbiterA * 8244434774754786565U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1334240485667164762U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9190066751460137016U;
            aOrbiterD = RotL64((aOrbiterD * 14585141844653660363U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 15465215829109246336U) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2305208282453624419U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10257861974108363283U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16951510027310993926U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11117938943423526901U;
            aOrbiterJ = RotL64((aOrbiterJ * 7805486716716924787U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12461379120662979432U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11719697049048823897U;
            aOrbiterB = RotL64((aOrbiterB * 14880996802304818757U), 39U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 6843357278142933570U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12727898578324702374U;
            aOrbiterC = RotL64((aOrbiterC * 9786435451654365097U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 18127999660067652233U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11754709060558683082U;
            aOrbiterI = RotL64((aOrbiterI * 12798744012150745847U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 16940151146420516184U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12924950783056761895U;
            aOrbiterE = RotL64((aOrbiterE * 8898170377271926745U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14829713915929878471U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 840466047621042565U;
            aOrbiterH = RotL64((aOrbiterH * 10748511630509529489U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 20U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterC, 10U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + aNonceWordG);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterI, 18U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 3U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aExpandLaneA
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aExpandLaneA forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18243U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneC[((aIndex + 17059U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17391U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21251U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18453U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 26U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (((aWandererK + RotL64(aScatter, 14U)) + RotL64(aCarry, 27U)) + 9630214189402543339U) + aNonceWordH;
            aOrbiterE = ((aWandererE + RotL64(aCross, 29U)) + 4072576573737526819U) + aPhaseBOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aIngress, 53U)) + 15994787452709618869U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 19U)) + 6403240137132259482U) + aPhaseBOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 10229266900170507720U) + aNonceWordB;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 5U)) + 5025294577989748989U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 47U)) + 16696461238217956883U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 18U)) + 9878318855341719119U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 39U)) + 16086635438116177346U) + aNonceWordJ;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12295437783084203730U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7681150419912842402U;
            aOrbiterA = RotL64((aOrbiterA * 7289497379725191451U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2639104034287637448U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12298170009332243573U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9397919591171238575U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3485932317267669626U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16569551670038752475U;
            aOrbiterH = RotL64((aOrbiterH * 8139802826402217631U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4448490103784103954U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 14510534073046885941U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7777192047386438305U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4286195398675733451U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15790355933840266463U;
            aOrbiterB = RotL64((aOrbiterB * 13342257823027075501U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6362891510370156055U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15121822034579983174U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7268045994574844937U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13817341015719915628U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14113474087906143783U;
            aOrbiterG = RotL64((aOrbiterG * 12838910141533126059U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9988301252236121106U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11287477288382171758U;
            aOrbiterE = RotL64((aOrbiterE * 4979297247881426383U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9491727010910328644U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7961202721830514030U;
            aOrbiterC = RotL64((aOrbiterC * 16300364540313620767U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 48U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterB, 23U));
            aWandererE = aWandererE + (((RotL64(aIngress, 58U) + aOrbiterE) + RotL64(aOrbiterJ, 34U)) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterD, 43U)) + aPhaseBWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterB, 19U)) + aNonceWordM);
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 30U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 30U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 6U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aExpandLaneB
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25985U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneD[((aIndex + 23784U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23055U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26380U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23677U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 44U)) + (RotL64(aCross, 27U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererB + RotL64(aScatter, 19U)) + 6024062041314952357U) + aNonceWordA;
            aOrbiterD = ((aWandererE + RotL64(aCross, 29U)) + 18340757093658015585U) + aNonceWordC;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 23U)) + 11911120493880346751U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 54U)) + 17428074353884654439U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 11U)) + 12790849760814795936U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 12633397052172117800U) + aNonceWordB;
            aOrbiterI = (aWandererC + RotL64(aIngress, 5U)) + 11946150433665237945U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 16842157900909419285U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((((aWandererG + RotL64(aIngress, 48U)) + RotL64(aCarry, 21U)) + 14186235783224155962U) + aPhaseBOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13284904542579767591U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11609181965078844357U;
            aOrbiterA = RotL64((aOrbiterA * 5455780554452453513U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 9628562297095374984U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7850281529011259759U;
            aOrbiterJ = RotL64((aOrbiterJ * 17611485102925470357U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 257458718073794527U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10693404545773519306U;
            aOrbiterH = RotL64((aOrbiterH * 14821443722828498323U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3430519236533871460U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6183054506953198055U;
            aOrbiterD = RotL64((aOrbiterD * 6121082743789970911U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 2905610989884221654U) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4472163910775333862U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7770678426310856745U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 16870142883133769663U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1403692060594816451U;
            aOrbiterE = RotL64((aOrbiterE * 9740854430251597879U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 16904169913507057108U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4773518591580333357U;
            aOrbiterC = RotL64((aOrbiterC * 5306070307776061267U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6528141733853494275U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11254806909313951442U;
            aOrbiterG = RotL64((aOrbiterG * 6316669786405548827U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6857506858448143407U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2855763534355983644U;
            aOrbiterI = RotL64((aOrbiterI * 16881334940165182415U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 39U);
            aIngress = aIngress + (RotL64(aOrbiterD, 52U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterD, 36U)) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterG) + aNonceWordN) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterF, 53U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 3U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterA, 24U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + aPhaseBWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 58U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31717U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 28576U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27588U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30302U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30564U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 4U)) + (RotL64(aIngress, 35U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 35U)) + 2783898056762489197U) + aPhaseBOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 19U)) + 7177192902873343053U) + aNonceWordP;
            aOrbiterB = (aWandererD + RotL64(aCross, 39U)) + 12254703232691980774U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 27U)) + 15446547245691219559U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 52U)) + RotL64(aCarry, 53U)) + 888475203006174856U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 3649183529366307877U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 43U)) + 4642631047518805167U) + aNonceWordH;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 6108329730724782250U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 58U)) + 8334054653023816636U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5891895375031474350U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3176720746238477862U;
            aOrbiterB = RotL64((aOrbiterB * 1869961473768307911U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6111038696865301675U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11914998302228682704U;
            aOrbiterA = RotL64((aOrbiterA * 11738924766359642853U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17005063057791320948U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 18333780598768130670U;
            aOrbiterJ = RotL64((aOrbiterJ * 5416759844884107303U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2056115016443263153U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10245512728872962677U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 707106795383284903U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4810366069422162351U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3051442983125942469U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13558537578054436423U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9285068547223654308U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13067251130180968842U;
            aOrbiterG = RotL64((aOrbiterG * 7000687697769766605U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 3203670242792002165U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1770881716916463461U;
            aOrbiterI = RotL64((aOrbiterI * 13870229847371882171U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16286823712870537410U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13067191141829694202U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15629974528467350445U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3414576315085336932U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8979691827341555245U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 15971594804040295757U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 52U) + RotL64(aOrbiterI, 37U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterK, 27U)) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 6U)) + aOrbiterC) + aPhaseBWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + aNonceWordO);
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterK) + aNonceWordG);
            aWandererF = aWandererF + (((((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterI, 18U)) + RotL64(aCarry, 19U)) + aNonceWordJ) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterK, 23U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterG, 43U)) + aOrbiterD) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Billiards_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x999E5D45AD428E99ULL + 0xD1470A979BE7F334ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA6BFF474906F7EC5ULL + 0xDAFD8BB7EE834DC6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDBA9F3751A173727ULL + 0xAC51EE7E65060C4CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x820876AFB5F68323ULL + 0x933E98C58168474FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x805BC0DB099C243FULL + 0x9228DB8EA8BDD70EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF335784E4A9EFA07ULL + 0xA44929473C6DAAF0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEC38CEF7010A7333ULL + 0x919E3FBD24547E8FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x912CE4F1406BB619ULL + 0xC481A92700AE98A2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFD0DDD3A25ED2265ULL + 0xE739DC77835EF4E9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xED9204C18CED3AC5ULL + 0x90B76578F9DFBC4EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB319F981192A4247ULL + 0xBB8042637C4157B5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFA42F6ABACE468F9ULL + 0xC1837D174DDDAB58ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x99F73FEE091A3097ULL + 0xCC09C04F75DDC1F9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9DE7441082072FF9ULL + 0xFC323C8CB0FD21C2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE60D9E9A07B0C657ULL + 0xF91032E678D8386AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBAC6B6A03E8E39D3ULL + 0xC872DAB5BE62441AULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2606U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((aIndex + 1878U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 4962U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3596U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4334U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 2911U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 13053031069776604052U) + aNonceWordC;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 1331396630251085122U) + aNonceWordP;
            aOrbiterD = (aWandererD + RotL64(aCross, 57U)) + 15879286043343942393U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 50U)) + RotL64(aCarry, 19U)) + 13590365633321406830U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 37U)) + 14569235423040242618U) + aPhaseDOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 5U)) + 11397370636618371560U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 29U)) + 3455933494593971847U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1307153376443784593U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10688618762584786871U;
            aOrbiterD = RotL64((aOrbiterD * 9503823896874842411U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 17746248451153600096U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8512568600755410158U;
            aOrbiterH = RotL64((aOrbiterH * 16648320170768234063U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8950230550112591092U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 17790968369472845496U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5104988920132008913U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12583323865381967534U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11243927099685293887U;
            aOrbiterK = RotL64((aOrbiterK * 12867003042486433971U), 29U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 9690268715525781389U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7466066217365074653U;
            aOrbiterE = RotL64((aOrbiterE * 17565696765505320889U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3673528673209875118U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14079103852360952255U;
            aOrbiterG = RotL64((aOrbiterG * 17449228863409999629U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6747836856132250630U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5027692924422297153U;
            aOrbiterB = RotL64((aOrbiterB * 2492421273167124437U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 27U)) + aOrbiterC) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 19U)) + aOrbiterH) + aNonceWordD) + aPhaseDWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 5U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterE, 37U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 50U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 57U)) + aOrbiterK) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererK, 20U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9947U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 6053U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 7454U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 6432U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7249U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6249U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 8918U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aIngress, 51U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererC + RotL64(aCross, 48U)) + 5160910997561396461U) + aNonceWordI;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 3U)) + 14920764751058512062U) + aNonceWordD;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 57U)) + 6080952401749660022U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 29U)) + 17667234330526298627U) + aPhaseDOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 760630072638686756U) + aNonceWordF;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 3504157162816997476U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 23U)) + 9489022223422585882U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1149898536879968964U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10492284328940025310U;
            aOrbiterJ = RotL64((aOrbiterJ * 7893416766300156495U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13213275606286399312U) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 10557118912847180413U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 10077877991284587845U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15618980209023994776U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 5268600749854045564U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3849660559223919613U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8011552687609649990U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3148133096349525066U;
            aOrbiterA = RotL64((aOrbiterA * 5245156554959620007U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12032847944237867285U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 14999005703490824673U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6631584955208646049U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5426735969392906710U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3593177531650386729U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 12997284886192717043U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1701444719333347373U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15928731228196894960U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1919318226904213433U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 4U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterD, 51U)) + aNonceWordN);
            aWandererD = aWandererD + (((((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 39U)) + aNonceWordL) + aPhaseDWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterI, 11U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterJ, 21U)) + aNonceWordB) + aPhaseDWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12594U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 12395U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11633U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13168U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15992U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aIngress, 5U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = (((aWandererC + RotL64(aScatter, 11U)) + 18319689184146942855U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aWandererG + RotL64(aIngress, 37U)) + 8041304130090501019U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 11347064191990897738U) + aNonceWordH;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 3U)) + 15242243470024447468U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 10619749107163611105U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 53U)) + 14795614276221947128U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 20U)) + RotL64(aCarry, 39U)) + 1578095288886372393U) + aNonceWordC;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13593906305770501684U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8919815528334599172U;
            aOrbiterK = RotL64((aOrbiterK * 2033810402808238127U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17425548324720065145U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 11125018338392347335U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 4377887040461528587U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3779189180734244399U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 10958224663276134041U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 6206963519509783781U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4317305352561612995U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4891139433808505355U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11507024985663120317U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5166074784835930965U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10080890270621589202U;
            aOrbiterC = RotL64((aOrbiterC * 13170894418184288695U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4501071771615514619U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6486573807774431753U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 324029625116648669U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15714881857668975753U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3506619392820235900U;
            aOrbiterE = RotL64((aOrbiterE * 5707033870161224499U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 40U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 58U) + RotL64(aOrbiterK, 51U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterE, 29U)) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterB) + aNonceWordD) + aPhaseDWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 52U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 17282U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneA[((aIndex + 20860U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 20471U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20096U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17056U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 23U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 14214886793361825363U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 43U)) + 17267959031078766320U) + aNonceWordD;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 16436067429484887644U) + aNonceWordE;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 9885951769332633820U) + aNonceWordJ;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 11U)) + 12971711341813893304U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 23U)) + 199970353398450154U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 60U)) + 1237341696444162094U) + aPhaseDOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7991128854417613360U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14809029847149045833U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5940857360838299105U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2559509556915775947U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14336829730147834160U;
            aOrbiterD = RotL64((aOrbiterD * 15103242520064900873U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8853631886733610440U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 13346159398673246914U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 13660497151446983393U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12121095718571872976U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16239781125815589804U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5157009090454962231U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9051377033794324106U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13805815136723461780U;
            aOrbiterH = RotL64((aOrbiterH * 571129481747181357U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14849157800322754413U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 18116651528452542634U;
            aOrbiterB = RotL64((aOrbiterB * 3638480428016835537U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 4105057226952948599U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5911714320560994391U;
            aOrbiterJ = RotL64((aOrbiterJ * 1796514171654961389U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterG, 53U)) + aPhaseDWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 36U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + aNonceWordL);
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterE, 35U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 22U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 27030U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((aIndex + 22545U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23583U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25474U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneA[((aIndex + 25502U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 3U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (aWandererA + RotL64(aCross, 35U)) + 898812731947995389U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 29U)) + 8677347622525527167U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 19U)) + 770321564027567654U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 11020474858081526395U) + aNonceWordP;
            aOrbiterG = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 17289793580414993470U;
            aOrbiterI = ((((aWandererD + RotL64(aIngress, 42U)) + RotL64(aCarry, 53U)) + 10111912559295118444U) + aPhaseDOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 51U)) + 8083622125544542011U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7149858558922988240U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5919683821379905699U;
            aOrbiterE = RotL64((aOrbiterE * 16705119888884231567U), 41U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 6860902846079238714U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 15083517836867542075U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4686657139237578325U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14852868368708376381U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9860233289028878323U;
            aOrbiterA = RotL64((aOrbiterA * 13418143547952204667U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 772406119079116272U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7971141501337627589U;
            aOrbiterI = RotL64((aOrbiterI * 10168120622976358617U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8478568022896691911U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 4027604850785607101U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 4826627523578901467U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17199331557841535430U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7515957656979776361U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5468950152869656599U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17138249294921502391U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16236812863923234668U;
            aOrbiterF = RotL64((aOrbiterF * 2925542836624164807U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 14U)) + aOrbiterK) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterF, 53U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterI, 21U)) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 6U) + aOrbiterA) + RotL64(aOrbiterI, 37U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 20U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 31180U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((aIndex + 29102U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28505U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28910U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29810U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 5U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 1297415699043177788U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 18U)) + RotL64(aCarry, 37U)) + 17583786534509260153U) + aNonceWordG;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 37U)) + 643197858925708798U) + aNonceWordB;
            aOrbiterB = ((((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 5062653766915694874U) + aPhaseDOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (aWandererH + RotL64(aScatter, 5U)) + 7034273638367180511U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 11U)) + 2026909726972916996U;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 53U)) + 2785690475553211646U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2910341716302991892U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2834181605200829791U;
            aOrbiterJ = RotL64((aOrbiterJ * 1510617068750957651U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13323052600571281928U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 10434901530315760460U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 2042210188346767033U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 247903955625194782U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5196515747387257163U;
            aOrbiterC = RotL64((aOrbiterC * 1799024689023272275U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 7196305682377987476U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14777739876892587484U;
            aOrbiterK = RotL64((aOrbiterK * 95220583948241581U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10609060796540136671U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8386027207212484155U;
            aOrbiterA = RotL64((aOrbiterA * 4855610536246556893U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 729659744301903424U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2350564261412606157U;
            aOrbiterB = RotL64((aOrbiterB * 16713856782349084977U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 16611987556673864177U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1525195188708550503U;
            aOrbiterE = RotL64((aOrbiterE * 10045858602151004553U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 11U)) + aOrbiterC) + aNonceWordP);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 27U)) + aPhaseDWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 57U)) + aNonceWordH) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 19U)) + aOrbiterA) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterA, 53U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + aNonceWordD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 58U) + aOrbiterD) + RotL64(aOrbiterE, 42U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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

void TwistExpander_Billiards_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEDFFF8CC41AC70ABULL + 0xADDB3AA5426DA1BCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCB3F0243493D7145ULL + 0xA3331ACA55B1E933ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBA80A970A3ECEB19ULL + 0xE7BD6D33993130DEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC50C97F6712A41E9ULL + 0xD3663181A9B0111FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9154360F086BB4C1ULL + 0xAECF2D44C584E11CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC9B3570A01D76685ULL + 0xEF9178E2241A91BAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD62A754CFFA4CC5DULL + 0xA2DFE12A4CA84383ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8286ED0E24F984B3ULL + 0xDA2CD951EE7A36ADULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC4AE13459F046BA9ULL + 0x897096ABCBEEB68FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8CB6DA3820CAAB05ULL + 0xF91FEF9EC8C85C17ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCA5AA4362422C987ULL + 0x9E8BB1271403F5B9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCF6A84E9F93D5D23ULL + 0x98B3595D1A1F7049ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB39D78E16672C3A9ULL + 0xBCF1C82BF323EC21ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF9E84E567ACED853ULL + 0xDA064EB23A99024DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEDEC52A548F9E679ULL + 0xBD33B841756399F8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFF8DE65B802F9B0FULL + 0xAFA4D6FBEF250A67ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 636U)) & S_BLOCK1], 12U) ^ RotL64(aInvestLaneB[((aIndex + 2606U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2809U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4358U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3789U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4467U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 22U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 37U)) + 17074147006464019918U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 42U)) + 10559516626129419928U) + aNonceWordJ;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 13280363679503946221U) + aPhaseEOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 35U)) + 17657115422132457413U) + aPhaseEOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 13325837013304973008U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 23U)) + 3059707750486106037U) + aNonceWordI;
            aOrbiterK = (aWandererG + RotL64(aScatter, 47U)) + 4529045702503050852U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 19U)) + 10726578475550904292U) + aNonceWordO;
            aOrbiterE = (aWandererK + RotL64(aIngress, 29U)) + 14832537837996659885U;
            aOrbiterD = (aWandererA + RotL64(aCross, 50U)) + 220094417441809246U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 5U)) + 15343130035105342194U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16592263353426409884U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15649290906447931918U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8405875177836650731U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11437410545843708269U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5859769136073011444U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1065016088086441107U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15188064100307340341U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4367466521843260049U;
            aOrbiterC = RotL64((aOrbiterC * 15916715854192820923U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8482617283860566845U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2585745804937342972U;
            aOrbiterE = RotL64((aOrbiterE * 8267269625632139809U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1687641344403425541U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13667916445979421400U;
            aOrbiterK = RotL64((aOrbiterK * 8191322670355590027U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7684258716388029228U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14764266202380443369U;
            aOrbiterB = RotL64((aOrbiterB * 1746254773647650741U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12685190466981675661U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9958374400222383893U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 12696606920219838929U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1352584794098160330U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16057453941015251708U;
            aOrbiterA = RotL64((aOrbiterA * 6051546505117202495U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5642244742563733299U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2946279435712646692U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 3711867103848631343U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17305358424001395035U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1831722001182742673U;
            aOrbiterF = RotL64((aOrbiterF * 13867284970939557547U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12354430852596737299U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17074147006464019918U;
            aOrbiterG = RotL64((aOrbiterG * 17316050599218057961U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 22U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterB, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 13U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterE, 54U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 3U)) + aNonceWordD);
            aWandererD = aWandererD + ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterE, 39U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 41U)) + aOrbiterB) + aNonceWordC);
            aWandererE = aWandererE + ((((RotL64(aScatter, 34U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterF, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 10787U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneC[((aIndex + 5725U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 10436U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10792U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9691U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8057U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 6355U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 14U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 18U)) + 9855743441035905047U) + aPhaseEOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 39U)) + 8426286937143990276U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 37U)) + 7146752367170267002U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 12947210066678101726U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 15902163559925328965U) + aNonceWordM;
            aOrbiterG = (aWandererB + RotL64(aIngress, 35U)) + 8506649889346449469U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 3U)) + 8226286036430263052U) + aNonceWordG;
            aOrbiterA = (aWandererC + RotL64(aCross, 37U)) + 2703047093452420216U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 27U)) + 6769351326360139560U) + aNonceWordE;
            aOrbiterH = (aWandererK + RotL64(aCross, 20U)) + 9857025533281333281U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 11U)) + 238297452132277585U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7203572312072908931U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12497027346166575632U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1703586436725662307U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 473851890609048879U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1664484956453886047U;
            aOrbiterG = RotL64((aOrbiterG * 8566500756326590209U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4635095143004754116U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17695676150967345793U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 5780416541584439301U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15628965269863402796U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9190117464399730235U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5586437438425999715U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 17835918238346011086U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4398005402429282682U;
            aOrbiterJ = RotL64((aOrbiterJ * 14828737209913317463U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10902589938246551273U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15124274429081385923U;
            aOrbiterA = RotL64((aOrbiterA * 13524180348258805367U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8747233520702236018U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5445611443463112371U;
            aOrbiterC = RotL64((aOrbiterC * 10294109295823410447U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16296005217836151910U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6468336224317602364U;
            aOrbiterD = RotL64((aOrbiterD * 7369779919748367133U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3827976387089403774U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7773383658122100111U;
            aOrbiterK = RotL64((aOrbiterK * 9784711300597525161U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 18273794621528918389U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8401424792700263455U;
            aOrbiterH = RotL64((aOrbiterH * 13003420427441089595U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11402828934846813949U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9855743441035905047U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7339549576423555273U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 46U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 34U));
            aWandererC = aWandererC + (((RotL64(aIngress, 6U) + aOrbiterE) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterD, 57U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 21U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + aPhaseEWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 43U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + aNonceWordC) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 37U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterI, 26U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 19U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterK, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterJ, 5U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 12539U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneA[((aIndex + 14195U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11527U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13037U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneC[((aIndex + 16031U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 56U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = ((aWandererB + RotL64(aScatter, 14U)) + 9220392006207660113U) + aNonceWordD;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 5U)) + 11305018553489132882U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 5860373868073513684U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 37U)) + 12319586170883987589U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 14072333614354649021U) + aNonceWordI;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 9332158529453194608U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 29U)) + 3860569321145958686U;
            aOrbiterC = (aWandererI + RotL64(aCross, 57U)) + 8119005668901240093U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 27U)) + 13918259792880333239U) + aPhaseEOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 52U)) + 6938856216758228704U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 11U)) + 3960905839118710604U) + aNonceWordH;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6043879193734253929U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15691425268831319195U;
            aOrbiterF = RotL64((aOrbiterF * 7189195135654636271U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14912209933584715274U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16180183395910618923U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 3942858974766467849U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4966642362507707776U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6962226782462822861U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3647802407741095419U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12409120845092026295U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2302946450253872465U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 7099576330777297911U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16118304388937163838U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15968419034359049422U;
            aOrbiterJ = RotL64((aOrbiterJ * 11736207775827080165U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17098982091525008231U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10298979200690822062U;
            aOrbiterE = RotL64((aOrbiterE * 12620028874653521945U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 552826643694256437U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11786560990790695378U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11190309640069208311U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13730399230389329793U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17614226859252305432U;
            aOrbiterB = RotL64((aOrbiterB * 2640019643570222977U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1062738267846296283U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13959480457644980835U;
            aOrbiterA = RotL64((aOrbiterA * 1194145909157002977U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 4635071137794189167U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13374502212707796180U;
            aOrbiterD = RotL64((aOrbiterD * 129680788767298945U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11479902881487238033U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9220392006207660113U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1437457810224888809U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 56U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + aNonceWordN) + aPhaseEWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 41U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 18U)) + aOrbiterK) + aNonceWordM);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterF, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterE, 29U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 53U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 37U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterG, 14U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 47U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 10U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 54U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19661U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((aIndex + 20060U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 20942U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16933U)) & S_BLOCK1], 28U) ^ RotL64(aInvestLaneD[((aIndex + 20964U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 57U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererA + RotL64(aCross, 3U)) + 2168513956284366370U) + aNonceWordB;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 10290361969974613111U) + aNonceWordF;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 15673836275828498050U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 18U)) + 16600540024145812236U;
            aOrbiterI = (aWandererB + RotL64(aCross, 13U)) + 9428052101528111892U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 51U)) + 12763657928312763377U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 10751286982008662485U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 47U)) + 1708230173038057979U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 41U)) + 4011389705422783816U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 38U)) + 11704428328093077714U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aIngress, 27U)) + 2055336619674699284U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1870865272102705804U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3574214263751923179U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13132083406834413563U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 984611970726966186U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15207945449947643672U;
            aOrbiterD = RotL64((aOrbiterD * 9539470161576639981U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4181398506373973169U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15222345431506025949U;
            aOrbiterI = RotL64((aOrbiterI * 6925143692628659467U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 15023513452326240962U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14965669361708810699U;
            aOrbiterE = RotL64((aOrbiterE * 587008860996713147U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7985755518735406360U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 225592097619240187U;
            aOrbiterA = RotL64((aOrbiterA * 2313509354133400439U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3659537916566939383U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17043668033610689611U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10797634709118100773U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10217321522161675848U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8013663869536146842U;
            aOrbiterB = RotL64((aOrbiterB * 2293233079384777175U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13762445330867496042U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2692400019659269106U;
            aOrbiterC = RotL64((aOrbiterC * 167704184292219399U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 18232551682424867647U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14785847596876239854U;
            aOrbiterH = RotL64((aOrbiterH * 4569180925037758487U), 3U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 5910282247522389536U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16556038638738871204U;
            aOrbiterJ = RotL64((aOrbiterJ * 18356922295088260901U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 141620663839815754U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2168513956284366370U;
            aOrbiterG = RotL64((aOrbiterG * 8605382725635471683U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 34U) + RotL64(aOrbiterC, 48U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterK, 29U));
            aWandererB = aWandererB + ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterC, 37U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterJ, 39U)) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterA, 14U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterE, 35U)) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22093U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneB[((aIndex + 24002U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26113U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26894U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26331U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25745U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 54U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (aWandererJ + RotL64(aScatter, 23U)) + 6733949564325516029U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 47U)) + 7304098437143918796U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aWandererA + RotL64(aIngress, 19U)) + 3923949518391777800U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 14243591003388927124U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 26U)) + 18329498724605410406U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 3U)) + 13118172167747037249U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 5272025143849174212U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 16075917179214318424U) + aNonceWordO;
            aOrbiterK = (aWandererF + RotL64(aCross, 37U)) + 15263590648674658399U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 51U)) + 13730046728289525921U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 40U)) + 7703141464499623408U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1382279753822135359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2973369221699098292U;
            aOrbiterE = RotL64((aOrbiterE * 7440242040663550631U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11578274119583013219U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3419411247737896674U;
            aOrbiterH = RotL64((aOrbiterH * 17814942652262802991U), 5U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 2582783513078999303U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 3959762790273529677U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 383974377372162751U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 465795011576934604U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17880826624185821135U;
            aOrbiterK = RotL64((aOrbiterK * 4445949147592860913U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10819659185349413173U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17298208553586835030U;
            aOrbiterJ = RotL64((aOrbiterJ * 1965860510614222093U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12585880006661489402U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16650193903267408586U;
            aOrbiterF = RotL64((aOrbiterF * 5781132589396936615U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 885882046325991589U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 869560078374809974U;
            aOrbiterB = RotL64((aOrbiterB * 13440973563438747181U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11871305571797951851U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12137095015607196226U;
            aOrbiterI = RotL64((aOrbiterI * 7618152256560808581U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6044048326509186958U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 622564532811968856U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14988345089359014037U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17133994029325040272U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8612895899003926829U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2128664397481732179U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2169081503433534750U) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6733949564325516029U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10062179904046311601U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 54U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 58U) + aOrbiterK) + RotL64(aOrbiterC, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterE, 60U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ) + aNonceWordK) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterA, 37U)) + aNonceWordI);
            aWandererK = aWandererK + ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterK, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterC, 46U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterD, 27U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + aPhaseEWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterG, 19U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28970U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 32632U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31762U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31865U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29281U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 479672811032092393U;
            aOrbiterB = (aWandererB + RotL64(aCross, 51U)) + 18061121631394564425U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 11U)) + 14237400452740566065U) + aPhaseEOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 6723123812257706134U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 34U)) + 4247997188026499248U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 39U)) + 1939107415066134869U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 29U)) + 3912640123546395979U) + aNonceWordF;
            aOrbiterC = (aWandererC + RotL64(aCross, 3U)) + 8295478436553964298U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 43U)) + 3218960600711526885U;
            aOrbiterG = (aWandererD + RotL64(aCross, 58U)) + 5874096203353388890U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 10294536533673023358U) + aNonceWordA;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11268561953904130747U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16693201256788898423U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16291987237693567209U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7550969634681894654U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9501647424602245869U;
            aOrbiterK = RotL64((aOrbiterK * 11265865222096866605U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8881869255994319423U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16770136406906800016U;
            aOrbiterC = RotL64((aOrbiterC * 1782039587385512923U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16185384746435761363U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13841034186650721627U;
            aOrbiterE = RotL64((aOrbiterE * 12000155593277035447U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15229062695864608309U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3576122704615303733U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2433987493885779279U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 13898167174453181224U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12878032061609524049U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 18104665741338251495U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12719156051299028649U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8640980843376950769U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 10242616778390983333U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12133332160916004365U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8743563985229104484U;
            aOrbiterB = RotL64((aOrbiterB * 4575129690615054691U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7362223873479167793U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4230720394788635807U;
            aOrbiterI = RotL64((aOrbiterI * 3658720603716856293U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 5095842824285329272U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7483469517256234638U;
            aOrbiterD = RotL64((aOrbiterD * 9782114499878763883U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17426017004856399653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 479672811032092393U;
            aOrbiterA = RotL64((aOrbiterA * 14921028515589317919U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 54U) + aOrbiterC) + RotL64(aOrbiterK, 19U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 51U)) + aOrbiterF) + aNonceWordL) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 23U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 38U));
            aWandererE = aWandererE + ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterE, 57U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 53U)) + aOrbiterI) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aIngress, 10U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterG, 3U));
            aWandererH = aWandererH + ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterA, 30U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererB, 44U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Billiards_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB13E46A4831A644DULL + 0xD29A18D64461E614ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE39EA3ABA1ECB98BULL + 0xE351D2A737E17747ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB7D76A9F26BF11DDULL + 0x9002FAFBCE39AC95ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD54048E22E1C09ABULL + 0xCED67EB40DAF001EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA5F900ACD03BC2E5ULL + 0xFE0CA6B9C86F3510ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA4E289DD2D24A4E9ULL + 0xEF6957E3893D1066ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFF8C8CB435F7EB63ULL + 0x935AC7AB4D275675ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA3C484A2EDDE7109ULL + 0xD5729F9A14C94DE1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA49168A1C8624E39ULL + 0x8CD22D763FB4E3B7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBAE88FC42E61B27DULL + 0x8423D1BC9DFA8B84ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9317257BC82BEDF1ULL + 0xED8818CC187B13A8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD7E8A715661621FDULL + 0xB0EC81890D67D97FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8D2823463DD135A7ULL + 0xC5F872BAEEDA3C5CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC8C6BDEEC6B75899ULL + 0xE6C6080E8C8505FBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEA97578DE7FA4D51ULL + 0x887B3DEE1403D36BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB76C5C7377508B43ULL + 0x81553101719D5785ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneB, aOperationLaneC, aOperationLaneD, aSnowLaneB, aSnowLaneC, aWorkLaneD, aWorkLaneC, aSnowLaneD, aInvestLaneD, aExpandLaneA, aSnowLaneA, aExpandLaneB, aInvestLaneA, aExpandLaneC, aInvestLaneC
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aSnowLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aSnowLaneB backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4074U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((aIndex + 5327U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 1745U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2083U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2703U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aSnowLaneB[((aIndex + 1415U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 34U) + RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (aWandererB + RotL64(aCross, 3U)) + 9220392006207660113U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 54U)) + 11305018553489132882U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 5860373868073513684U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 12319586170883987589U) + aNonceWordO;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 41U)) + 14072333614354649021U) + aNonceWordG;
            aOrbiterD = (aWandererJ + RotL64(aCross, 10U)) + 9332158529453194608U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 19U)) + 3860569321145958686U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 29U)) + 8119005668901240093U;
            aOrbiterC = ((((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 13918259792880333239U) + aPhaseFOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6938856216758228704U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3960905839118710604U;
            aOrbiterA = RotL64((aOrbiterA * 16203746868670689793U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6043879193734253929U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15691425268831319195U;
            aOrbiterE = RotL64((aOrbiterE * 7189195135654636271U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14912209933584715274U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 16180183395910618923U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 3942858974766467849U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4966642362507707776U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 6962226782462822861U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3647802407741095419U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12409120845092026295U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 2302946450253872465U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7099576330777297911U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16118304388937163838U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15968419034359049422U;
            aOrbiterB = RotL64((aOrbiterB * 11736207775827080165U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17098982091525008231U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10298979200690822062U;
            aOrbiterK = RotL64((aOrbiterK * 12620028874653521945U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 552826643694256437U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11786560990790695378U;
            aOrbiterC = RotL64((aOrbiterC * 11190309640069208311U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 13730399230389329793U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17614226859252305432U;
            aOrbiterI = RotL64((aOrbiterI * 2640019643570222977U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 26U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterF, 53U));
            aWandererG = aWandererG + ((((RotL64(aCross, 60U) + RotL64(aOrbiterK, 39U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterH, 28U)) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + aNonceWordH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 18U) + RotL64(aOrbiterE, 47U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 4U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterC, 43U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 5565U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 8825U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7050U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8541U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8807U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10660U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 9914U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 57U)) + 17081642665820489793U) + aNonceWordA;
            aOrbiterF = (((aWandererD + RotL64(aCross, 27U)) + 14468854040067229623U) + aPhaseFOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aWandererG + RotL64(aScatter, 6U)) + 2249450222593057429U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 51U)) + 14964389079511378664U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aScatter, 47U)) + 17003491054252360650U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 39U)) + 12710882240582032588U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 12U)) + RotL64(aCarry, 11U)) + 9887078182156755359U) + aNonceWordG;
            aOrbiterB = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 7665284531810584704U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 7304284015511876717U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5517927023543751734U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17704756310857362759U;
            aOrbiterI = RotL64((aOrbiterI * 15826832172923213591U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11347400363019508578U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11696395232760991243U;
            aOrbiterF = RotL64((aOrbiterF * 9725231749679442003U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 10875780291242873583U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7808740614343437672U;
            aOrbiterG = RotL64((aOrbiterG * 8889516201913716283U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 3145390996141902032U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 16080636485642732615U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7445756373012217305U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3929263288176983844U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 18210228766683996806U;
            aOrbiterH = RotL64((aOrbiterH * 13178080076505449091U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13948962323541421431U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3037683309790156893U;
            aOrbiterE = RotL64((aOrbiterE * 13406672352222636739U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17827265198532699474U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7270895262023504864U;
            aOrbiterC = RotL64((aOrbiterC * 13467417362477308167U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6431243064980879185U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6680205390976259885U;
            aOrbiterD = RotL64((aOrbiterD * 10421386694108590789U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15910655919164357152U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8046213498216027383U;
            aOrbiterK = RotL64((aOrbiterK * 18061867495824063553U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 24U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterH, 42U)) + aNonceWordH) + aPhaseFWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterK, 37U));
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 53U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + aNonceWordL);
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterG, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + aNonceWordF);
            aWandererG = aWandererG + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aNonceWordC);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterI, 6U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 6U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aInvestLaneD
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 12152U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 15302U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 11214U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12356U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneC[((aIndex + 11156U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 24U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (aWandererB + RotL64(aCross, 58U)) + 12809562813316740345U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 17084212535326321199U) + aNonceWordD;
            aOrbiterD = (aWandererC + RotL64(aScatter, 13U)) + 16074921689983846769U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 14027986153007120145U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 7633455951809250227U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 27U)) + 340989348513370174U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 48U)) + 5307820377645020116U) + aPhaseFOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = ((aWandererF + RotL64(aCross, 35U)) + 5605285015771527274U) + aPhaseFOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 41U)) + 5293500434746182790U) + aNonceWordB;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7263156475892261811U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10672879570907433005U;
            aOrbiterD = RotL64((aOrbiterD * 2506338667179450741U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16659226780900986107U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9774892622769850665U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7487477727543183211U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 10728057184108279042U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5032485856947407217U;
            aOrbiterH = RotL64((aOrbiterH * 16651577903809154285U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14642241075374862345U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8386481273395203518U;
            aOrbiterE = RotL64((aOrbiterE * 11649977733867003445U), 39U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 2874153265304098104U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11519900149177261000U;
            aOrbiterA = RotL64((aOrbiterA * 2010158758971864505U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8885690878540115768U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4482143389870987714U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7105332459437434281U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17469068567801886615U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 5121422018622394837U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14823827133212643467U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3130788210672745618U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6139244627510113216U;
            aOrbiterF = RotL64((aOrbiterF * 2640754184921507389U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10488511756324474710U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1760223670304953696U;
            aOrbiterI = RotL64((aOrbiterI * 4007062295003769311U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 42U)) + aNonceWordH);
            aWandererF = aWandererF + ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterA, 47U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 13U)) + aOrbiterC) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 47U) + RotL64(aOrbiterD, 23U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 5U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 53U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterC, 27U)) + aNonceWordK);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 28U) + aOrbiterH) + RotL64(aOrbiterD, 36U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aSnowLaneA
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aSnowLaneA forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18173U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 19632U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 19877U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 20091U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 16481U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 3U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (aWandererF + RotL64(aPrevious, 54U)) + 1898718075389870739U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 39U)) + 5631794889237247403U) + aNonceWordG;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 43U)) + 18219714659484524607U) + aNonceWordN;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 11U)) + 15419581386225732921U) + aNonceWordF;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 9125575431710198210U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 12205871520544965505U;
            aOrbiterG = ((((aWandererJ + RotL64(aScatter, 60U)) + RotL64(aCarry, 27U)) + 7617534300497343422U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aWandererH + RotL64(aCross, 3U)) + 18017579105368135814U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 29U)) + 10693882161946020042U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11669615701700895306U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11045110212889232165U;
            aOrbiterB = RotL64((aOrbiterB * 5965171269273719849U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 18019107802806469913U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 12315940560472528716U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4505122470351404065U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4899009736070044310U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 17412253404253730364U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 10791901166391946485U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4826286251927854181U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4523455921321845084U;
            aOrbiterI = RotL64((aOrbiterI * 14534103906736598099U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4132514462154182215U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7164745605985109269U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14107325508977225261U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 6297434295807635654U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8813887638672996646U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17495632530773158201U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11086381278955626084U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 5660733992573928887U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 11248164458720777889U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14851044686208609882U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12707776386060264479U;
            aOrbiterJ = RotL64((aOrbiterJ * 4470919091467313071U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11508023384209716657U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11752973809740920034U;
            aOrbiterC = RotL64((aOrbiterC * 10212754472298834769U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 34U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterE, 38U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 19U)) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 43U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 47U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterC, 23U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 20U) + aOrbiterB) + RotL64(aOrbiterC, 51U));
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 12U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aInvestLaneA
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22176U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneD[((aIndex + 26251U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 27197U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27290U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 25732U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 10U)) + 1888427424966603593U) + aNonceWordH;
            aOrbiterH = (((aWandererH + RotL64(aCross, 29U)) + 5436761445660415091U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 39U)) + 17322876217962143270U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 9728299982740564979U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 301720335271716921U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 14U)) + 8069685428854814396U) + aNonceWordK;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 1973715500949100991U) + aPhaseFOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 57U)) + 87666408799854155U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 35U)) + 12195436904339035245U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4578742069143400295U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7828776048774876484U;
            aOrbiterJ = RotL64((aOrbiterJ * 4047964518501081039U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17203146364542781833U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16913369550858890466U;
            aOrbiterI = RotL64((aOrbiterI * 13534417587921978507U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9632761514552265402U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9106637671877341286U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9073709119482640391U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15423680889126750876U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6087310684583331882U;
            aOrbiterF = RotL64((aOrbiterF * 8964465129744898619U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5420955876411796789U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14166807419730848032U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 442659738632823751U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8118312450347026824U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4253043584558403086U;
            aOrbiterA = RotL64((aOrbiterA * 5651748455190536467U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8810774678371762700U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12218479555589447835U;
            aOrbiterH = RotL64((aOrbiterH * 11026364205248516355U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11389930523582876358U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16334420553471379915U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13830132212033904777U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 18201289372553710279U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7196540389657785361U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 13058135202554889791U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 6U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 60U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + aPhaseFWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterE) + aNonceWordP);
            aWandererG = aWandererG + ((((RotL64(aCross, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 42U)) + aOrbiterG) + aNonceWordN);
            aWandererJ = aWandererJ + ((RotL64(aCross, 58U) + RotL64(aOrbiterB, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32539U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((aIndex + 28200U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 27525U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29270U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27390U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 47U)) + (RotL64(aIngress, 60U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (aWandererD + RotL64(aCross, 4U)) + 13650869943246163567U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 19U)) + 3435284932011770999U;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 12388155658186776579U) + aNonceWordD;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 47U)) + 2374345913955712039U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 39U)) + 6095094526980292156U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 4965147025852444174U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 29U)) + 3261881216269075298U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 4939780217097329222U) + aNonceWordM;
            aOrbiterA = (aWandererJ + RotL64(aCross, 34U)) + 3019862009792676287U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 901910626217143974U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3647055146712366383U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 1792602402476450009U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7731765438957392967U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13409819457393479741U;
            aOrbiterK = RotL64((aOrbiterK * 3345078200262410715U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5415832109107794258U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8876738832313114471U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1304277600444504135U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17135570542519390359U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2373193062766802082U;
            aOrbiterB = RotL64((aOrbiterB * 4213691513185791519U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16318403285501718552U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8456043288604687045U;
            aOrbiterH = RotL64((aOrbiterH * 10556964529144571683U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10572534930284516528U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14616251186735204677U;
            aOrbiterC = RotL64((aOrbiterC * 2048651204265459805U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2837006243817205610U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5315917323622194254U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 4080522050089666599U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 12084676282761185907U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7922080344175593788U;
            aOrbiterD = RotL64((aOrbiterD * 7603522302708937379U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17620847289789547792U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12140386059533463650U;
            aOrbiterA = RotL64((aOrbiterA * 1443266480620969535U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 42U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterH, 18U)) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 56U) + RotL64(aOrbiterJ, 51U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 57U)) + aOrbiterB);
            aWandererI = aWandererI + (((((RotL64(aCross, 35U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordO) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterD, 34U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 47U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 5U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aCross, 30U) + aOrbiterF) + RotL64(aOrbiterK, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Billiards_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE442899715ED75E9ULL + 0xEF4978D0F83C112FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA30A2EB703FDEB13ULL + 0x81A49037E03BFF24ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x856D542AE0621E63ULL + 0xF006616662D0655DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBD36DFA3520E10C3ULL + 0x86206BA678FF01C3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEE9D4FE7C9FF231DULL + 0xFE1CA74B37EDCBDEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA431B8C44749EFCDULL + 0x8C437300A81D0D03ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB7F7FBA7DD1748F1ULL + 0xBBF74E9E7D279B92ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB31CC2DA53C77F97ULL + 0xA3A729A95CA6F9D8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFA0B5328B53F1CDDULL + 0x9CE7248FB4AC4A19ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8E99E64338BFA7F9ULL + 0xA41C3A3F92879A40ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAD57CFC03E53F2B1ULL + 0xDF67EBC0E4AB28E3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCEE00020CC1F771BULL + 0xC627D2E3AA2DE099ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB92903BD679EA85BULL + 0xC0E67E1562A75977ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAE29D719CD4F9CE1ULL + 0xFF1028AC0D14E561ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8BFDD56BAC72A4CFULL + 0x8D1430BEED0C7950ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD9394CF92FCC1727ULL + 0x89BA424F7CE5F68AULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneB, aSnowLaneC, aSnowLaneD, aFireLaneA, aWorkLaneA, aFireLaneB, aInvestLaneA, aWorkLaneB, aFireLaneD, aExpandLaneA, aFireLaneC, aExpandLaneB, aInvestLaneD, aExpandLaneC, aInvestLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneB
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneA
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5193U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneB[((aIndex + 1964U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 330U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 4628U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 4921U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 609U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 2168513956284366370U) + aNonceWordO;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 10290361969974613111U) + aNonceWordH;
            aOrbiterC = (aWandererF + RotL64(aCross, 11U)) + 15673836275828498050U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 50U)) + RotL64(aCarry, 11U)) + 16600540024145812236U) + aNonceWordG;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 21U)) + 9428052101528111892U) + aPhaseHOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 43U)) + 12763657928312763377U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 27U)) + 10751286982008662485U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1708230173038057979U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4011389705422783816U;
            aOrbiterC = RotL64((aOrbiterC * 11692237130784795961U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11704428328093077714U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2055336619674699284U;
            aOrbiterD = RotL64((aOrbiterD * 6374289210096410907U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1870865272102705804U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 3574214263751923179U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13132083406834413563U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 984611970726966186U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15207945449947643672U;
            aOrbiterF = RotL64((aOrbiterF * 9539470161576639981U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4181398506373973169U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15222345431506025949U;
            aOrbiterJ = RotL64((aOrbiterJ * 6925143692628659467U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15023513452326240962U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14965669361708810699U;
            aOrbiterA = RotL64((aOrbiterA * 587008860996713147U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 7985755518735406360U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 225592097619240187U;
            aOrbiterG = RotL64((aOrbiterG * 2313509354133400439U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterC, 58U)) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterD, 29U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 23U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 30U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + aNonceWordB) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + aPhaseHWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 41U)) + aOrbiterA) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneA
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7784U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneC[((aIndex + 6310U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 5933U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 6033U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 6978U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 6499U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 6120U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 3U)) ^ (RotL64(aIngress, 36U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 19U)) + 12583180859826261500U) + aNonceWordF;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 9067093488553721468U;
            aOrbiterC = ((((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 12173106198862881754U) + aPhaseHOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aWandererF + RotL64(aCross, 37U)) + 11333491014394592654U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 53U)) + 3511883526940919554U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 13U)) + 7416810692106273044U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 46U)) + RotL64(aCarry, 53U)) + 8341174972619784110U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 2220852854836962979U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8090781422229383825U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 578293950675644397U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2338801236599102223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12484514711848308104U;
            aOrbiterG = RotL64((aOrbiterG * 10364216764253366067U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13684861340589131816U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12796636819991873058U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 5533508014234835669U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7634198650894837690U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10240326122201201762U;
            aOrbiterI = RotL64((aOrbiterI * 8758703497719125901U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4162814763739453934U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2766504649149048469U;
            aOrbiterD = RotL64((aOrbiterD * 16731843453895178671U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11051393030148769655U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17687055068651386665U;
            aOrbiterJ = RotL64((aOrbiterJ * 1042927176246229537U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3353615315436983420U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5971640796220306310U;
            aOrbiterE = RotL64((aOrbiterE * 15804313508835034807U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 29U)) + aOrbiterH) + aNonceWordN) + aPhaseHWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 23U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterI, 39U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 50U) + aOrbiterJ) + RotL64(aOrbiterD, 14U)) + aPhaseHWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aFireLaneD
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16309U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 11008U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 10955U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10961U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 16251U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 57U) + RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 51U)) + 4179952823252098240U) + aNonceWordP;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 30U)) + RotL64(aCarry, 3U)) + 3745613452332101749U) + aNonceWordC;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 43U)) + 2955689793395307176U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 3U)) + 5639060180251322019U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 7901969163853586463U) + aPhaseHOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 57U)) + 2242166787816318119U) + aNonceWordF;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 5239936443960750064U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13939136954732185558U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 17058884136712717463U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 7222348891215482977U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18148618660054585941U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 7022023484530327814U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 650100011311048589U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7722084537340095637U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11764151879690934182U;
            aOrbiterK = RotL64((aOrbiterK * 12264384877711365655U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16412785901758144708U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9666718667728274824U;
            aOrbiterI = RotL64((aOrbiterI * 10865799822751771795U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4307127540152109364U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2457646804702647606U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6340030928007058595U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3179394870088602208U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 504977947273774249U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16190282058883481551U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16182729401018310837U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7110817020445860609U;
            aOrbiterD = RotL64((aOrbiterD * 13371352088428584087U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 58U) + RotL64(aOrbiterI, 41U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aNonceWordA) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterE, 27U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterD, 47U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterD, 54U)) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterK, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18707U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 17624U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 16392U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17591U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneD[((aIndex + 20454U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 56U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 1364174714924216027U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 37U)) + 13561796874229506613U;
            aOrbiterC = ((((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 11845572344206238305U) + aPhaseHOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aWandererK + RotL64(aIngress, 26U)) + 15762708240326773763U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 57U)) + 1157119665207900473U) + aNonceWordC;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 43U)) + 6823546624372055260U) + aPhaseHOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aWandererF + RotL64(aCross, 51U)) + 14465564210523945121U) + aNonceWordD;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10667464548080807531U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13445737493224316575U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 12137295000900795711U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3009837893785957665U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2886920524111083752U;
            aOrbiterF = RotL64((aOrbiterF * 15308180928967762543U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10886177449328249656U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 15067759884678100433U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5724566815989860041U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18307930462682331536U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 8791864377579255801U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 9265158882471421767U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 805797468642992351U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 5743305867058244964U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 16263000753351131717U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17102025528234481273U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1841579177327486899U;
            aOrbiterK = RotL64((aOrbiterK * 3841603385577825265U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2189493507896508972U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 18209567010094914374U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3737080408976852351U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + aNonceWordK);
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 47U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 3U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterC, 20U)) + aNonceWordG);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterD, 57U)) + aNonceWordI) + aPhaseHWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aInvestLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22113U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 25834U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 23287U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26003U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 23479U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 19U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 29U)) + 12690502671561165478U) + aNonceWordF;
            aOrbiterF = (aWandererK + RotL64(aScatter, 57U)) + 17519943923428102801U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 10705515807975331385U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 42U)) + 16586447272278538179U;
            aOrbiterG = ((((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 8006560996840971798U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 12928600185788857701U) + aPhaseHOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 5U)) + 14240723153798267172U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 8636219177994872072U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7586790235186467512U;
            aOrbiterJ = RotL64((aOrbiterJ * 15052686382507614169U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 1103807034179512424U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7547526530239498693U;
            aOrbiterG = RotL64((aOrbiterG * 3360295583636013509U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8380239679344786397U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 5690809173787433519U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5354724308093372953U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8390902801141804609U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3507306189192059486U;
            aOrbiterB = RotL64((aOrbiterB * 18336280496510253103U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6190745292098482871U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8065418693975056902U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 6414621418430102589U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12111755051718111803U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7605877769709909297U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17525248694315944599U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5969794501112646237U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5127559299360591476U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 4521563633438853069U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 58U);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 41U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 13U)) + aOrbiterH) + aPhaseHWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 50U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 22U)) + aNonceWordP);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 47U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterH, 41U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27593U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 28870U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 29238U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32558U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 31559U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCross, 39U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (((aWandererE + RotL64(aScatter, 11U)) + 11698283336767769359U) + aPhaseHOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 18U)) + RotL64(aCarry, 47U)) + 13297826354831483872U;
            aOrbiterD = ((((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 15254999058287530795U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 17474166585085346567U) + aNonceWordI;
            aOrbiterK = (aWandererF + RotL64(aIngress, 29U)) + 15684783498452840289U;
            aOrbiterE = (aWandererB + RotL64(aCross, 37U)) + 5061229733465216486U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 51U)) + 15370981279168377944U) + aNonceWordB;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17966672773619554092U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14685092893994491068U;
            aOrbiterD = RotL64((aOrbiterD * 1627758964162892429U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12798804186209406389U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2848444181474221574U;
            aOrbiterK = RotL64((aOrbiterK * 13730480364920876877U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8551142075919636146U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8833198159158950723U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7650289040764974737U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7351473160893666232U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14204899612487622222U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 6317485031956448029U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 7008985178526543258U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13576796403863120356U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13745839827679114077U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5769784656937900699U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14075925808204936705U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 5844894088757604713U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17818667502858010896U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16016922065572683130U;
            aOrbiterE = RotL64((aOrbiterE * 7525645833898085373U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + aNonceWordO) + aPhaseHWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterC, 35U));
            aWandererB = aWandererB + (((((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 35U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 50U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 41U)) + aOrbiterB) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterC, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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

void TwistExpander_Billiards_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 925U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[((aIndex + 1423U)) & W_KEY1], 36U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 913U)) & W_KEY1], 35U) ^ RotL64(mSource[((aIndex + 940U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 2783898056762489197U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 48U)) + 7177192902873343053U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 12254703232691980774U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 23U)) + 15446547245691219559U) + aPhaseAOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 888475203006174856U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 37U)) + 3649183529366307877U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 30U)) + 4642631047518805167U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 5U)) + 6108329730724782250U) + aPhaseAOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aPrevious, 19U)) + 8334054653023816636U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 5891895375031474350U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3176720746238477862U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1869961473768307911U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6111038696865301675U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11914998302228682704U;
            aOrbiterI = RotL64((aOrbiterI * 11738924766359642853U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17005063057791320948U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 18333780598768130670U;
            aOrbiterK = RotL64((aOrbiterK * 5416759844884107303U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2056115016443263153U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 10245512728872962677U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 707106795383284903U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4810366069422162351U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3051442983125942469U;
            aOrbiterE = RotL64((aOrbiterE * 13558537578054436423U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9285068547223654308U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13067251130180968842U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7000687697769766605U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3203670242792002165U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1770881716916463461U;
            aOrbiterH = RotL64((aOrbiterH * 13870229847371882171U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16286823712870537410U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13067191141829694202U;
            aOrbiterC = RotL64((aOrbiterC * 15629974528467350445U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3414576315085336932U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8979691827341555245U;
            aOrbiterF = RotL64((aOrbiterF * 15971594804040295757U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 30U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterE, 46U));
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 57U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 26U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterC, 53U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 12U)) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterE, 3U));
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 23U)) + aOrbiterB) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererD, 54U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4012U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 3182U)) & W_KEY1], 6U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3370U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4578U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 58U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aIngress, 20U)) + 17074147006464019918U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 47U)) + 10559516626129419928U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 13280363679503946221U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 17657115422132457413U;
            aOrbiterC = (aWandererG + RotL64(aCross, 39U)) + 13325837013304973008U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 28U)) + RotL64(aCarry, 47U)) + 3059707750486106037U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 5U)) + 4529045702503050852U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 35U)) + 10726578475550904292U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 53U)) + 14832537837996659885U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 220094417441809246U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15343130035105342194U;
            aOrbiterJ = RotL64((aOrbiterJ * 7984652435043810845U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16592263353426409884U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15649290906447931918U;
            aOrbiterC = RotL64((aOrbiterC * 8405875177836650731U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11437410545843708269U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5859769136073011444U;
            aOrbiterH = RotL64((aOrbiterH * 1065016088086441107U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15188064100307340341U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4367466521843260049U;
            aOrbiterB = RotL64((aOrbiterB * 15916715854192820923U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8482617283860566845U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2585745804937342972U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8267269625632139809U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1687641344403425541U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13667916445979421400U;
            aOrbiterF = RotL64((aOrbiterF * 8191322670355590027U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7684258716388029228U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14764266202380443369U;
            aOrbiterG = RotL64((aOrbiterG * 1746254773647650741U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12685190466981675661U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9958374400222383893U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12696606920219838929U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1352584794098160330U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16057453941015251708U;
            aOrbiterA = RotL64((aOrbiterA * 6051546505117202495U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 11U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 24U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            aWandererG = aWandererG + (((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 27U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 47U)) + aOrbiterE) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterA, 58U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterC, 5U)) + aPhaseAWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterI, 18U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6460U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 5620U)) & W_KEY1], 24U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7927U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7734U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 7455U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 29U)) + (RotL64(aCarry, 44U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 12809562813316740345U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 14U)) + RotL64(aCarry, 57U)) + 17084212535326321199U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 16074921689983846769U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 47U)) + 14027986153007120145U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 43U)) + 7633455951809250227U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 18U)) + 340989348513370174U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 51U)) + 5307820377645020116U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 29U)) + 5605285015771527274U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 23U)) + 5293500434746182790U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7263156475892261811U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10672879570907433005U;
            aOrbiterC = RotL64((aOrbiterC * 2506338667179450741U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16659226780900986107U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9774892622769850665U;
            aOrbiterH = RotL64((aOrbiterH * 7487477727543183211U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10728057184108279042U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5032485856947407217U;
            aOrbiterJ = RotL64((aOrbiterJ * 16651577903809154285U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14642241075374862345U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8386481273395203518U;
            aOrbiterG = RotL64((aOrbiterG * 11649977733867003445U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2874153265304098104U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11519900149177261000U;
            aOrbiterA = RotL64((aOrbiterA * 2010158758971864505U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8885690878540115768U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4482143389870987714U;
            aOrbiterF = RotL64((aOrbiterF * 7105332459437434281U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17469068567801886615U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5121422018622394837U;
            aOrbiterI = RotL64((aOrbiterI * 14823827133212643467U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3130788210672745618U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6139244627510113216U;
            aOrbiterD = RotL64((aOrbiterD * 2640754184921507389U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10488511756324474710U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1760223670304953696U;
            aOrbiterK = RotL64((aOrbiterK * 4007062295003769311U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 54U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 35U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aPrevious, 34U) + RotL64(aOrbiterK, 47U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 19U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 28U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aCross, 52U) + aOrbiterC) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterD, 51U));
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterG, 39U)) + aPhaseAWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 58U)) + aOrbiterH) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9904U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadB[((aIndex + 10629U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(mSource[((aIndex + 8632U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 9920U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9290U)) & W_KEY1], 50U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9132U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 18U)) + (RotL64(aPrevious, 39U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 13854738573712660276U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 58U)) + 16835460633412286294U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 47U)) + 6785859293758091931U) + aPhaseBOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 126317283127992659U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 7568963536291415413U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 3U)) + 12294016745653004819U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 41U)) + 18269588932920281147U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 11U)) + 5872406424994751026U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 52U)) + 7764434758831474129U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4804168969415573371U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 959601763507651280U;
            aOrbiterC = RotL64((aOrbiterC * 4647396592804833217U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9257644462479293048U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14332699366894494579U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8829304078930625541U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10487012596470786004U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 612729229562321440U;
            aOrbiterI = RotL64((aOrbiterI * 11380387280507726003U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7845523921295625315U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12742115479740024747U;
            aOrbiterA = RotL64((aOrbiterA * 15578543510683986421U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10294667720904610944U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14369711143154904567U;
            aOrbiterD = RotL64((aOrbiterD * 13753005602288309379U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10918344717497681894U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 18136794828308636957U;
            aOrbiterK = RotL64((aOrbiterK * 17899418637978002409U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14378638206724886404U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7077588188450008059U;
            aOrbiterH = RotL64((aOrbiterH * 485375960462924335U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8941870012851971932U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15242087859620352399U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4963002810455992839U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10395280254030875387U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6826595516076975980U;
            aOrbiterB = RotL64((aOrbiterB * 6198886240333178001U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 48U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterC, 27U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterG, 12U));
            aWandererG = aWandererG + (((RotL64(aCross, 10U) + RotL64(aOrbiterC, 53U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 19U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 47U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterB, 39U));
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterD, 43U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 42U) + aOrbiterE) + RotL64(aOrbiterA, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 24U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13094U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 11405U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13152U)) & W_KEY1], 27U) ^ RotL64(mSource[((aIndex + 12646U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 10924U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12117U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11742U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererF + RotL64(aPrevious, 48U)) + 16200278595895089008U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 3U)) + 1029614154810465897U) + aPhaseBOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 35U)) + 7129562468705441295U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 41U)) + 14388903902433951274U) + aPhaseBOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aCross, 53U)) + 1013568949315967455U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 10U)) + RotL64(aCarry, 13U)) + 3128823373497815651U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 14525694606889470589U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 14443983602196782887U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 57U)) + 12244220415328641190U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10477159225338766614U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2842870123078131566U;
            aOrbiterA = RotL64((aOrbiterA * 11522265477555954071U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8621138818955849917U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5038396344400303181U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14636756322207385447U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2768613802894372496U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2027754864051410015U;
            aOrbiterI = RotL64((aOrbiterI * 2461322540050569287U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2848088309172056399U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15017458513904884651U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9926904679902843055U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9079797279596336139U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15424866642305110811U;
            aOrbiterK = RotL64((aOrbiterK * 12912331089970158845U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13751764050290602740U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7694557131324740282U;
            aOrbiterG = RotL64((aOrbiterG * 14980807690491467023U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3508673897305667669U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3600868397311393233U;
            aOrbiterJ = RotL64((aOrbiterJ * 5165032044164139165U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1222655844979128996U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2257342337168905875U;
            aOrbiterF = RotL64((aOrbiterF * 6198995971182272119U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6290990717563682725U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15308494772443447109U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1925593111157842325U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterG, 58U));
            aWandererH = aWandererH + (((RotL64(aScatter, 42U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererB = aWandererB + ((((RotL64(aCross, 29U) + RotL64(aOrbiterK, 29U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterF, 39U)) + aPhaseBWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterI, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 18U) + aOrbiterD) + RotL64(aOrbiterK, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererD, 58U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14491U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((aIndex + 15596U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14933U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13800U)) & W_KEY1], 35U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14566U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15757U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14774U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 23U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererA + RotL64(aPrevious, 3U)) + 5721224134332887360U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 28U)) + RotL64(aCarry, 27U)) + 6892749729775049095U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 3884839462099556836U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 47U)) + 4365431706830216193U) + aPhaseBOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 51U)) + 15501528746571578773U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 4505911326320650606U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 12U)) + 1865129050927879580U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 35U)) + 2011737665969640369U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 43U)) + 611672935827062688U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 663547038310431047U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5468932264754299556U;
            aOrbiterB = RotL64((aOrbiterB * 11968657455484578525U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17920294117231191705U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 486058453837528110U;
            aOrbiterF = RotL64((aOrbiterF * 8851102552244026737U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2789178451938129313U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 420772587981211184U;
            aOrbiterJ = RotL64((aOrbiterJ * 17402987842294006667U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16196774774442181825U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16264169656793713547U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6900221986041638783U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10207659833859860796U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8593749091183323678U;
            aOrbiterA = RotL64((aOrbiterA * 10696776033512404927U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7224922076047787384U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15366267474865172373U;
            aOrbiterG = RotL64((aOrbiterG * 10134187073321814217U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4235342515820080294U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5239480080426950612U;
            aOrbiterC = RotL64((aOrbiterC * 12077621553561927079U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10891752830598395582U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7797358829694471108U;
            aOrbiterK = RotL64((aOrbiterK * 7621206775460997431U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3755715857903753416U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3172069024987421726U;
            aOrbiterI = RotL64((aOrbiterI * 16048490837178650865U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 40U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 4U)) + aOrbiterB) + aPhaseBWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 57U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 43U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterF, 51U));
            aWandererK = aWandererK + (((RotL64(aIngress, 56U) + aOrbiterG) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 37U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 12U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 58U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18563U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 16885U)) & W_KEY1], 26U));
            aIngress ^= (RotL64(mSource[((aIndex + 18315U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17790U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16527U)) & W_KEY1], 37U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17537U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 16479U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 52U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererF + RotL64(aIngress, 52U)) + 13481227414590594621U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 13U)) + 17425964381118918026U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 4792004356135956581U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 5U)) + 11926849936000639098U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 35U)) + 990697329347742142U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 24U)) + 9307721505373076588U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 17605732738841908719U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 13110764518634187439U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 57U)) + 17970109897810645911U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10273133817644703654U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11239046688920468137U;
            aOrbiterA = RotL64((aOrbiterA * 5197802934333553327U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8355821483275763145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15522151127786049345U;
            aOrbiterG = RotL64((aOrbiterG * 4844278537850520413U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5381663179722418112U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9551368011768104906U;
            aOrbiterE = RotL64((aOrbiterE * 14202470972121732997U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16264476585232221270U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 7721417776432288282U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10267770327791051869U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 339418090653475277U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3247926250495935511U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16824669543765729097U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3390560045236418590U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3894024951542543635U;
            aOrbiterH = RotL64((aOrbiterH * 10599637790900418767U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3878539166189668154U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5617705593218220843U;
            aOrbiterF = RotL64((aOrbiterF * 82771190372750823U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12320861089148474544U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 14943790251625519550U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13758322022902008313U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 18119213517612562775U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1413193144229486646U;
            aOrbiterI = RotL64((aOrbiterI * 14562375280658115687U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 46U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterA, 29U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterE, 35U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 11U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 30U) + aOrbiterH) + RotL64(aOrbiterB, 52U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterD, 39U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterH, 18U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19574U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((aIndex + 20207U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21482U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((aIndex + 19150U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20544U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20260U)) & W_KEY1], 47U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21534U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 20821U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 57U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererB + RotL64(aIngress, 57U)) + 9888431329297626900U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 3U)) + 2937735167534624403U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 40U)) + RotL64(aCarry, 13U)) + 17626022970343789617U) + aPhaseCOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aScatter, 11U)) + 5665660859333693743U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 27U)) + 1060537034632076669U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 53U)) + 743777763907175800U;
            aOrbiterG = (aWandererH + RotL64(aCross, 18U)) + 5744905970181808845U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 3545351394494002180U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 4877547088414106007U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11669378338379598445U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2961072441706158212U;
            aOrbiterH = RotL64((aOrbiterH * 2677988507090705371U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 13984945589234919765U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1433097875470903205U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 451996840039906781U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 716415411025451152U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8542286150858297810U;
            aOrbiterC = RotL64((aOrbiterC * 9139015340823332449U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12932391786479661299U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14005503313299177013U;
            aOrbiterD = RotL64((aOrbiterD * 802663466907819743U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9382792812676318046U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5138554251079724724U;
            aOrbiterG = RotL64((aOrbiterG * 6386016499265056247U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8522380066269546172U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11825536408101906458U;
            aOrbiterI = RotL64((aOrbiterI * 17042837108792016849U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15504062350899452495U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 1219010998820336744U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10650635772711590803U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6442717843380349632U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1047843426279085117U;
            aOrbiterA = RotL64((aOrbiterA * 4074561571072878005U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10611039527108679173U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5092816736177358221U;
            aOrbiterB = RotL64((aOrbiterB * 14342779343820140833U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 40U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterH, 24U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterH, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 36U) + aOrbiterA) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 35U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterH, 20U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterC, 43U)) + aPhaseCWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 42U) + RotL64(aOrbiterC, 53U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 39U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 50U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23350U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[((aIndex + 24057U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22640U)) & W_KEY1], 39U) ^ RotL64(aFireLaneC[((aIndex + 22675U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23903U)) & S_BLOCK1], 28U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24378U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23562U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneB[((aIndex + 22516U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aIngress, 43U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 21U)) + 8793908991006073956U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 47U)) + 2932916283348441943U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 11069042087940968262U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 14369628676782894441U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 11U)) + 8602903272780978282U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 28U)) + 3827036107178568820U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 19U)) + 8905245209036772489U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 41U)) + 13331387530760017893U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 5U)) + 9880107580289737823U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10199619040626900278U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2466307560891374281U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6295342978834217571U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13973403407981259448U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2851460278409385243U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11226902976321781743U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10365453393815690776U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2382382358987358791U;
            aOrbiterC = RotL64((aOrbiterC * 481563628980705781U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5058198848163792422U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10500434740387593487U;
            aOrbiterD = RotL64((aOrbiterD * 5946747708776079787U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11289798395177667084U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14327152153231286666U;
            aOrbiterB = RotL64((aOrbiterB * 18155778059595245561U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8065137263811956313U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3865153574847924816U;
            aOrbiterF = RotL64((aOrbiterF * 9495741102667755161U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18102279969722473375U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6306428427188742325U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17826782872351406167U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 16953348204663693724U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11950791817032898613U;
            aOrbiterA = RotL64((aOrbiterA * 1498946055469611133U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11980823193543752994U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17845490308799454871U;
            aOrbiterJ = RotL64((aOrbiterJ * 16385153013485463791U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 36U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterA, 35U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterJ, 60U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterI, 47U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 53U)) + aOrbiterC) + aPhaseCWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterK, 24U));
            aWandererH = aWandererH + ((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 39U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24706U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 24733U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26168U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25634U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26065U)) & W_KEY1], 46U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24600U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25340U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneB[((aIndex + 26831U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 27U)) + 5171470532667965920U) + aPhaseDOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 51U)) + 750549462358682403U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 35U)) + 3325689257577120525U) + aPhaseDOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aCross, 42U)) + 18031575461559790826U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 13U)) + 13874739537012288677U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 4250029868785016865U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 8211158803112611161U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 1083939790236786027U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 4U)) + 3446525462376962464U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6973817815000417325U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15230876489676945543U;
            aOrbiterH = RotL64((aOrbiterH * 7737039082964537651U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9359727659738755880U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8775170107816327654U;
            aOrbiterC = RotL64((aOrbiterC * 6910680458261008653U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11958941755525038545U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16966819714283167348U;
            aOrbiterE = RotL64((aOrbiterE * 16363457661846050749U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14556087985619763243U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17915047508377045221U;
            aOrbiterG = RotL64((aOrbiterG * 6727635453185130109U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8578745677485367222U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7002181668717618866U;
            aOrbiterI = RotL64((aOrbiterI * 12329703532414955235U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3569939503066735457U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2956247934282522184U;
            aOrbiterF = RotL64((aOrbiterF * 9946650822131152531U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4285180013402474041U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5976239869535619811U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3458095419039067465U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2424524955161695463U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6849595426583763537U;
            aOrbiterK = RotL64((aOrbiterK * 12727902040238318101U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11414890686374886716U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5668287266836153445U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8011885266143066285U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterC, 57U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 4U) + RotL64(aOrbiterJ, 26U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 19U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 11U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aIngress, 44U) + aOrbiterH) + RotL64(aOrbiterI, 30U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 39U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 43U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 22U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28930U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneD[((aIndex + 27691U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28139U)) & W_KEY1], 21U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29504U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28771U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28641U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29813U)) & S_BLOCK1], 22U) ^ RotL64(aFireLaneB[((aIndex + 27750U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererC + RotL64(aIngress, 35U)) + 6973892330986118220U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 9886813896272094864U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 26U)) + 10996306582517553173U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 8490648283899856223U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 47U)) + 105141713530704655U) + aPhaseDOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aIngress, 53U)) + 3114337422810562588U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 21U)) + 980857684690886131U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 3U)) + 6562042345807072665U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 11U)) + 15665371138706353619U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 18113013571374375028U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17405346422601997299U;
            aOrbiterF = RotL64((aOrbiterF * 11162604605443005253U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5130876096426182506U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1813821672299154629U;
            aOrbiterE = RotL64((aOrbiterE * 15478100342425611875U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15793814882743306728U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13925299440495476399U;
            aOrbiterJ = RotL64((aOrbiterJ * 12049601510660117401U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9924458846049579438U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7810034662781768090U;
            aOrbiterA = RotL64((aOrbiterA * 10310594595026622513U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12812586478656872854U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5709576448057435237U;
            aOrbiterD = RotL64((aOrbiterD * 9101555233909853025U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7839807649914541516U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4717944526755429647U;
            aOrbiterH = RotL64((aOrbiterH * 8515229146471335721U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3933911971504256022U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 4814079680865379831U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15100740696230557391U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18352577312212175569U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 9670612998448920742U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5743579439303300553U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 72737302703035726U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10032869372369626210U;
            aOrbiterI = RotL64((aOrbiterI * 7449905669249993731U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 36U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterB, 6U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 46U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 35U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 51U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterI, 23U));
            aWandererC = aWandererC + (((RotL64(aScatter, 18U) + aOrbiterA) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterE, 19U));
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 60U)) + aPhaseDWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 29U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31935U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[((aIndex + 30312U)) & W_KEY1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32175U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31992U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30553U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 30125U)) & W_KEY1], 12U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 24U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererG + RotL64(aCross, 46U)) + 8685374557928800912U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 3482312691892161229U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 23U)) + 6948130297389161165U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 5506385663788942690U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 29U)) + 17859982009307397161U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 19U)) + 9178488809207094043U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 3U)) + 1835479501226057169U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 57U)) + 5368101733632614939U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 52U)) + RotL64(aCarry, 19U)) + 9050459666576835422U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9042186993119635078U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17528342580198295025U;
            aOrbiterK = RotL64((aOrbiterK * 14316671546614386775U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6495418332558436882U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8834495762667327342U;
            aOrbiterH = RotL64((aOrbiterH * 10783141541937645995U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4364314196965690905U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6357485231062120459U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 289429584586504995U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3321488322626415347U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10817330671781848737U;
            aOrbiterG = RotL64((aOrbiterG * 15875919466358823335U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17974092279281611763U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2871472057292789157U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16104199340711015181U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15187929795092006849U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13482063681546475923U;
            aOrbiterC = RotL64((aOrbiterC * 14466266308157364963U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 6232152545071397380U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17488906002621373262U;
            aOrbiterA = RotL64((aOrbiterA * 4719340606442742577U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12444819880507588549U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13808941689757772497U;
            aOrbiterB = RotL64((aOrbiterB * 6541360905282412317U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8049361354387692374U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7137831335606542401U;
            aOrbiterI = RotL64((aOrbiterI * 11022231291507235007U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 14U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterD, 47U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterK, 14U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            aWandererA = aWandererA + ((RotL64(aIngress, 6U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 51U)) + aOrbiterI) + aPhaseDWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 43U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterD, 3U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 24U) + aOrbiterK) + RotL64(aOrbiterG, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Billiards_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneB, aInvestLaneD, aFireLaneA, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2647U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 5313U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 100U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1617U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 1583U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 22U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererI + RotL64(aScatter, 29U)) + 13915875634607599122U) + aPhaseEOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 1695770381382411673U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 3709105579778295511U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 7673376335333251804U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 60U)) + 8814147709738503518U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 19U)) + 13451412605350381172U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 5U)) + 6447870234069609538U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13419487997946496825U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5478309847615220345U;
            aOrbiterC = RotL64((aOrbiterC * 12953043149543448765U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3635184969215610049U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12527903812035294828U;
            aOrbiterG = RotL64((aOrbiterG * 12540800512035534967U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1684685110885338814U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12860354576326835090U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12743745087733307255U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9081823570147481835U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14369321778210049109U;
            aOrbiterK = RotL64((aOrbiterK * 17865953349448767035U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11518132079084873250U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11893535026126957389U;
            aOrbiterD = RotL64((aOrbiterD * 15751374986135615095U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7084079180579206226U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2999676609847603277U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14602698397511266403U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17683445810614029153U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11576460512964896969U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5243651036457051155U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 40U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 36U) + aOrbiterG) + RotL64(aOrbiterF, 21U));
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 60U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterD, 35U));
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 41U)) + aOrbiterD) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneB
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 5869U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((aIndex + 7173U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10727U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9263U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6540U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 26U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 43U)) + 9855743441035905047U) + aPhaseEOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 8426286937143990276U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aScatter, 37U)) + 7146752367170267002U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 12947210066678101726U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 13U)) + 15902163559925328965U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 44U)) + 8506649889346449469U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 5U)) + 8226286036430263052U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2703047093452420216U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6769351326360139560U;
            aOrbiterJ = RotL64((aOrbiterJ * 5318104980014706265U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9857025533281333281U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 238297452132277585U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12974709749856065985U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7203572312072908931U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12497027346166575632U;
            aOrbiterG = RotL64((aOrbiterG * 1703586436725662307U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 473851890609048879U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1664484956453886047U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8566500756326590209U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4635095143004754116U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17695676150967345793U;
            aOrbiterB = RotL64((aOrbiterB * 5780416541584439301U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15628965269863402796U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9190117464399730235U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5586437438425999715U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17835918238346011086U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4398005402429282682U;
            aOrbiterD = RotL64((aOrbiterD * 14828737209913317463U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 58U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 21U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 11U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterG, 29U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 28U) + aOrbiterJ) + RotL64(aOrbiterG, 57U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 44U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 35U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 11034U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((aIndex + 14926U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11494U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15687U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16296U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 10949U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 53U) + RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 1042610313571524121U) + aPhaseEOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aCross, 50U)) + 3505725321008825582U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 12584654563843782991U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 35U)) + 6645399144515770935U;
            aOrbiterE = (aWandererF + RotL64(aCross, 41U)) + 3608978423753715584U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 8089198857670370983U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 19U)) + 15207251813516399879U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9579268660105824516U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16055044469473802812U;
            aOrbiterC = RotL64((aOrbiterC * 2269649280637188723U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 583811872609805949U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7027491967970873942U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12686754713465826139U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 18256061823189677508U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12708429127816136937U;
            aOrbiterA = RotL64((aOrbiterA * 12593886633108075321U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12169216645156306078U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 12694325407567795065U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3711789483877261899U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16109994660203297503U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4234704064165718913U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 730085881474787681U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14119541943554602878U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8777769004811352951U;
            aOrbiterB = RotL64((aOrbiterB * 2556957257736134223U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15642663488392549609U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11594468530833278624U;
            aOrbiterH = RotL64((aOrbiterH * 6639306656361601143U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aCross, 35U) + RotL64(aOrbiterA, 27U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterB, 36U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 47U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 5U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterB, 11U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21247U)) & S_BLOCK1], 46U) ^ RotL64(aInvestLaneC[((aIndex + 21675U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 20734U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17959U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17610U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19034U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 50U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 7632760812370906911U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 6007174525479723089U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 29U)) + 3362829642521821048U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 18009548556107978286U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 36U)) + 17880909432272697327U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 5U)) + 15961567935420752568U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 43U)) + 10136559064656837921U) + aPhaseEOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17622019364405410277U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6927494824421416306U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2686290883767829973U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7125170407794874847U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12342273503071032250U;
            aOrbiterI = RotL64((aOrbiterI * 867417849555857179U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 14997696377476124836U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14874498694181230698U;
            aOrbiterC = RotL64((aOrbiterC * 4026127545746010937U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2549397729130885686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4217995818662767955U;
            aOrbiterH = RotL64((aOrbiterH * 5525525344485251063U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4706089044415442525U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17983900172670031015U;
            aOrbiterA = RotL64((aOrbiterA * 541552737180932879U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1904937798143929988U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10620877287033139483U;
            aOrbiterK = RotL64((aOrbiterK * 16711012562024287213U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 15681091173163181525U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2655543246639000084U;
            aOrbiterJ = RotL64((aOrbiterJ * 16686375598149755947U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 10U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 28U) + aOrbiterE) + RotL64(aOrbiterA, 60U)) + aPhaseEWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterC, 37U));
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 23U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22282U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 23650U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 25166U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21899U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23942U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 24219U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCarry, 43U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 3550722402315312207U;
            aOrbiterI = (aWandererD + RotL64(aCross, 48U)) + 16724184551669522754U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 57U)) + 981751330116773021U) + aPhaseEOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aIngress, 3U)) + 7891159229704944868U) + aPhaseEOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 39U)) + 13618396711464799841U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 5969291018449003648U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 14595540413313640042U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3287990436916111762U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12534369400200483704U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2345945228434740707U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2277312067930392274U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10026320559261334353U;
            aOrbiterI = RotL64((aOrbiterI * 11020464940995912637U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11258082063135659551U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1445958517675746990U;
            aOrbiterE = RotL64((aOrbiterE * 10062265337488757971U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1011298251290970844U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6487834862470043744U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15477913837027179675U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9966279022928268335U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10285993486057704393U;
            aOrbiterG = RotL64((aOrbiterG * 15965714363201157535U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16005362468813966136U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 223843444699390781U;
            aOrbiterD = RotL64((aOrbiterD * 665392038954573081U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 18178876294968532775U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12490136112181806806U;
            aOrbiterB = RotL64((aOrbiterB * 16380841616662993709U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 30U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterA, 39U));
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + RotL64(aOrbiterE, 29U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 36U) + aOrbiterI) + RotL64(aOrbiterB, 12U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28540U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 28686U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 32640U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30570U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28143U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 31815U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCarry, 27U)) + (RotL64(aPrevious, 57U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererH + RotL64(aCross, 14U)) + 2571116506511057880U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 13112435411509707292U) + aPhaseEOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 23U)) + 10403251762787357256U) + aPhaseEOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 29U)) + 8461951095541400405U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 9890793478557463815U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 35U)) + 3030229465991783707U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 7273848154043719247U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10681774862516028276U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7105082755586853104U;
            aOrbiterG = RotL64((aOrbiterG * 12217705329504230357U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6588579345319551129U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14616333550242386092U;
            aOrbiterD = RotL64((aOrbiterD * 2934574715879306337U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15439666290229654921U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3360304356760164799U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5164191920584106237U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14438730801970761889U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14515616787452085729U;
            aOrbiterJ = RotL64((aOrbiterJ * 2041601927968559821U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4167853822635132419U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8950982233003320239U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 887144270884244907U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12391327853728029953U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7100871010552394421U;
            aOrbiterB = RotL64((aOrbiterB * 16552349374101955967U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15381697462381887944U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6801677551341079401U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13325954438427340703U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 26U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + aPhaseEWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 23U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterF, 29U));
            aWandererI = aWandererI + (((RotL64(aIngress, 38U) + aOrbiterF) + RotL64(aOrbiterB, 36U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 43U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Billiards_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneA, aSnowLaneA, aInvestLaneC, aInvestLaneB, aSnowLaneB, aExpandLaneC, aWorkLaneA, aExpandLaneB, aWorkLaneB, aInvestLaneD, aWorkLaneC, aExpandLaneD
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneA backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2543U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((aIndex + 4236U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5009U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 825U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4861U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 3753U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 23U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 27U)) + 16462052553719977502U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 41U)) + 12337064059566619581U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 54U)) + 15801005007094515447U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 37U)) + 8228706742665081656U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 11006723027845190869U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 18173765337829177450U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 19U)) + 530215083653542558U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 56U)) + 6608611827035564511U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 43U)) + 2246051826221626809U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 5228575308895381421U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 51U)) + 10999213210689606857U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3773371037240485696U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8887985779436152504U;
            aOrbiterJ = RotL64((aOrbiterJ * 698713082830739677U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11150566414723818350U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8336366151003049546U;
            aOrbiterB = RotL64((aOrbiterB * 9033771197242493699U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13233968794237090787U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8172558473508478819U;
            aOrbiterH = RotL64((aOrbiterH * 17837070423649268435U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 133564480283347997U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15104810248883567064U;
            aOrbiterF = RotL64((aOrbiterF * 706802420642303533U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9138629520201127075U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13993086066341664080U;
            aOrbiterE = RotL64((aOrbiterE * 4875046427147105077U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6547273508580516932U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9838727018769865759U;
            aOrbiterC = RotL64((aOrbiterC * 11395273371936839815U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11685694999526122626U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8945983172566303116U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17791527981004597623U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17606249889617356327U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9296903152000480008U;
            aOrbiterK = RotL64((aOrbiterK * 18066622289408024413U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14248192861977167583U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5467843420970464193U;
            aOrbiterG = RotL64((aOrbiterG * 10121398470914323221U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17072313558131700643U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7932446176598954438U;
            aOrbiterI = RotL64((aOrbiterI * 11684711939539349335U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 15377107166135929052U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16462052553719977502U;
            aOrbiterA = RotL64((aOrbiterA * 9057188521274832217U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 50U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterB, 37U));
            aWandererF = aWandererF + ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterD, 48U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 44U) + aOrbiterA) + RotL64(aOrbiterH, 39U));
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 51U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterA, 23U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 46U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterG, 43U)) + aPhaseFWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 44U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneC
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6300U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 6322U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7217U)) & S_BLOCK1], 34U) ^ RotL64(aInvestLaneC[((aIndex + 6796U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8147U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7574U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 10343U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 30U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 16451272412693907816U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aIngress, 47U)) + 10099485419723255462U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 18U)) + 17668900099534923192U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 57U)) + 5497093724143181753U) + aPhaseFOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 21U)) + 10354044773550071706U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 23U)) + 12728258851198019099U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 36U)) + 4144050505314242618U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 5U)) + 14133805325480076530U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 308863673210602899U;
            aOrbiterI = (aWandererC + RotL64(aCross, 41U)) + 11741180130160569753U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 12926863156769180448U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 211920854786494259U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13234608842479411078U;
            aOrbiterK = RotL64((aOrbiterK * 2556747209733759467U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9164711974854618892U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6667377062281954219U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2603737166987437649U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 4559040002406721850U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1749875480850675109U;
            aOrbiterD = RotL64((aOrbiterD * 15822640067349481089U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9555365165561936366U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18289733999504213574U;
            aOrbiterE = RotL64((aOrbiterE * 14156217554673229429U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8727162691639622461U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 291406782452963706U;
            aOrbiterA = RotL64((aOrbiterA * 8413500075082350243U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8294911802626492257U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15853578397277298548U;
            aOrbiterI = RotL64((aOrbiterI * 13256191781365357747U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11535146194939658681U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2177540476748375661U;
            aOrbiterC = RotL64((aOrbiterC * 15791341922007841029U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2705306323728084136U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17617871830709148043U;
            aOrbiterJ = RotL64((aOrbiterJ * 3449981219502809255U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3699834746313613206U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17952609181629473245U;
            aOrbiterH = RotL64((aOrbiterH * 6103160209028988839U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8016694658897707674U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6971251395823324489U;
            aOrbiterF = RotL64((aOrbiterF * 13483776115929040277U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17467528888050817915U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16451272412693907816U;
            aOrbiterB = RotL64((aOrbiterB * 13689734638238895071U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 54U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterF, 19U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 37U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aIngress, 54U) + RotL64(aOrbiterA, 54U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 56U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 30U) + aOrbiterB) + RotL64(aOrbiterD, 41U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererH, 24U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneC
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15403U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 11443U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 15343U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15654U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12179U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 37U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererI + RotL64(aCross, 37U)) + 15549114274303128055U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 16466750056388063241U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 39U)) + 12209449840836787142U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 14551496099734294336U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 24U)) + RotL64(aCarry, 11U)) + 6266576428679808622U) + aPhaseFOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 35U)) + 16892841575635668152U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 19U)) + 7375966221423362125U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 57U)) + 11926105302821753530U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 6U)) + 16219253791550461124U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 29U)) + 7299056065319248160U;
            aOrbiterH = (aWandererB + RotL64(aCross, 27U)) + 15234001484933728439U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6615802589932632120U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5481176858895819247U;
            aOrbiterC = RotL64((aOrbiterC * 3604590158551984877U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17220507586542139380U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14137921473739415340U;
            aOrbiterF = RotL64((aOrbiterF * 10634645686035907603U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16981960446540932787U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10897565927079518588U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 418843936329303571U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2746889569299593263U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4894117146736361379U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2656750612042673191U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 18294823016957137777U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 86828501068883383U;
            aOrbiterE = RotL64((aOrbiterE * 11432686669235402365U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6322053762209547826U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6754524552483363820U;
            aOrbiterI = RotL64((aOrbiterI * 1746163087826694641U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7306452650619361017U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12717201204443785828U;
            aOrbiterA = RotL64((aOrbiterA * 6121251603905574991U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10422327053543898585U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14786413282036348183U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8713024293107068275U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4599182534559908397U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5080179685914177581U;
            aOrbiterJ = RotL64((aOrbiterJ * 14984675846207762951U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6527649204956325409U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8327234966110052920U;
            aOrbiterH = RotL64((aOrbiterH * 9343969092668123661U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7845497893651522069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15549114274303128055U;
            aOrbiterD = RotL64((aOrbiterD * 15263427406359082909U), 43U);
            //
            aIngress = RotL64(aOrbiterD, 42U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 34U) + aOrbiterC) + RotL64(aOrbiterB, 50U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterI, 21U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterA, 11U));
            aWandererF = aWandererF + ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterE, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterI, 27U));
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 19U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 23U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + RotL64(aOrbiterD, 54U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterA, 5U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 14U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18806U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((aIndex + 21819U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 17409U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21701U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20446U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 16519040829220310189U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 27U)) + 6888002778416941825U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 39U)) + 1310832187746534025U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 50U)) + 5890888009051281674U;
            aOrbiterD = (aWandererH + RotL64(aCross, 3U)) + 5143864838362464857U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 15591534069452660003U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 1466867671765325096U) + aPhaseFOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 47U)) + 13931443680107902488U;
            aOrbiterI = (aWandererE + RotL64(aCross, 23U)) + 15400747367673245552U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 43U)) + 2836975369734495759U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 58U)) + 2370720358274970117U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3470677184188006133U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7175584278499266723U;
            aOrbiterC = RotL64((aOrbiterC * 10067096593682482345U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6095078817776863055U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2176637999243513070U;
            aOrbiterG = RotL64((aOrbiterG * 12215701810843975501U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5580391239754903129U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15196125567953871184U;
            aOrbiterE = RotL64((aOrbiterE * 12686361960729564519U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12787014151503209931U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1523153207064063495U;
            aOrbiterA = RotL64((aOrbiterA * 3113907543551927561U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12973289026485937829U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9087439766232078173U;
            aOrbiterI = RotL64((aOrbiterI * 5817029335999350327U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16318022893068674015U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11089160685103562409U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17087834321385147603U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8680037953925067235U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3112588943274158119U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9214011370307670371U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16749015684369649821U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 9419550535891334966U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5421312787569114811U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12309598080688360615U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12244971765096881835U;
            aOrbiterJ = RotL64((aOrbiterJ * 17260277357109449509U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10088685417774847648U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3241987595838650154U;
            aOrbiterH = RotL64((aOrbiterH * 14096986158958931367U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17916401586500786536U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16519040829220310189U;
            aOrbiterF = RotL64((aOrbiterF * 6742024268853509861U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 6U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterA, 3U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 46U));
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 27U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterA, 35U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 19U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 21U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 58U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 53U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterF, 43U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 38U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25457U)) & S_BLOCK1], 40U) ^ RotL64(aSnowLaneB[((aIndex + 26753U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 25152U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22116U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((aIndex + 23284U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 27U)) + (RotL64(aIngress, 40U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 23U)) + 13442819395490639310U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 27U)) + 8187292523194120936U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 13U)) + 11469697159823131388U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 60U)) + 13414083692375929653U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 11404010733687907517U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 19U)) + 6783212827186218247U) + aPhaseFOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 21U)) + 8561131439340372614U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 6252609642004429113U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 3U)) + 12804867444200448952U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 35U)) + 2739648749603690781U;
            aOrbiterB = (((aWandererI + RotL64(aCross, 10U)) + RotL64(aCarry, 39U)) + 14808861217017399752U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17588866502571268888U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5882260142735642980U;
            aOrbiterG = RotL64((aOrbiterG * 7688252946143263869U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15493099088132862949U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5175647411532429582U;
            aOrbiterJ = RotL64((aOrbiterJ * 15226544495598541883U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14279707376173642767U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6826363572161275158U;
            aOrbiterI = RotL64((aOrbiterI * 5263708315440161809U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13267185753040999992U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 9980987858092888720U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13210290848800728635U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3582972937645514549U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 10140409019562890804U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6944490201647678479U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6160444117287330557U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 16344602960561293113U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2319964919335633293U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3497141036108337171U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 91269118352540308U;
            aOrbiterE = RotL64((aOrbiterE * 5160060720189045505U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12739932748793144857U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12820180915064791197U;
            aOrbiterB = RotL64((aOrbiterB * 5843849637411948699U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17572075652083359962U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10684041099654982701U;
            aOrbiterH = RotL64((aOrbiterH * 7121293375756263771U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10739534650885677354U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9731206787727954809U;
            aOrbiterD = RotL64((aOrbiterD * 3730875775588585547U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9655432616347117764U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13442819395490639310U;
            aOrbiterC = RotL64((aOrbiterC * 3650859301708619119U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 41U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterI, 26U));
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 54U) + aOrbiterA) + RotL64(aOrbiterK, 13U));
            aWandererH = aWandererH + ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 35U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 30U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 21U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + aPhaseFWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 6U) + aOrbiterI) + RotL64(aOrbiterG, 39U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterH, 43U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32537U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 32744U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31136U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32141U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30563U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 52U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererC + RotL64(aCross, 37U)) + 4622023259121087483U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 27U)) + 10253505250223501352U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aIngress, 23U)) + 17133877904420462669U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 5U)) + 6162827793741796700U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 9610986424765907615U) + aPhaseFOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aCross, 54U)) + RotL64(aCarry, 5U)) + 11210747154264753754U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 19U)) + 16554205219580654546U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 10352576357413766388U;
            aOrbiterA = (aWandererA + RotL64(aCross, 35U)) + 3651845783283479752U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 13U)) + 18145542190463500476U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 48U)) + 5415609566767162857U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2033734872464201570U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3507213117125813345U;
            aOrbiterC = RotL64((aOrbiterC * 5453058336688881113U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8716253393049851856U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 695984869565941856U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8377921610764044735U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7661578828878284931U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 906654265099155956U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8117625377607536949U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6050049984731254612U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17882717590338190821U;
            aOrbiterA = RotL64((aOrbiterA * 10807367411402733215U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4996521991532815957U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4246460672800604436U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12047466401960824903U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8700148116452518842U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10039050281847466206U;
            aOrbiterE = RotL64((aOrbiterE * 11884791271239660157U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4513844680425845372U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3037563127442815153U;
            aOrbiterH = RotL64((aOrbiterH * 18363509277992292407U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1005237931570968724U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1373258132025712065U;
            aOrbiterK = RotL64((aOrbiterK * 10458020799382532395U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12759144329395682277U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5139371668116336931U;
            aOrbiterJ = RotL64((aOrbiterJ * 10761543179345026943U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 3211005174890625715U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 18045286961878287418U;
            aOrbiterB = RotL64((aOrbiterB * 4536094526540761611U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4454078771279674978U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4622023259121087483U;
            aOrbiterD = RotL64((aOrbiterD * 8991756794989027019U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 42U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterK, 39U));
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 14U) + aOrbiterK) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 26U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 23U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterB, 13U));
            aWandererD = aWandererD + (((RotL64(aScatter, 18U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + aPhaseFWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterF, 46U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterD, 19U)) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Billiards_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
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
        // ingress from: aWorkLaneA, aWorkLaneB, aInvestLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4207U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 1431U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 1483U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7452U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4767U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 5192U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 6U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererG + RotL64(aIngress, 13U)) + 6654158889644956636U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 9045779659363991870U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 3888897662136993491U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 58U)) + RotL64(aCarry, 11U)) + 6882016842864459345U) + aPhaseGOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aScatter, 21U)) + 15601891715956172291U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5176811598629335350U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12519945150889074325U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8721098129033306427U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4552583214397603278U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14225482701804864688U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8526052833180466359U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5485298070606280363U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11237713257388094289U;
            aOrbiterI = RotL64((aOrbiterI * 11032429223099413011U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14340345895626142788U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16275167270553643347U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7308578867128951199U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14041860597556520250U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1436068974197066343U;
            aOrbiterA = RotL64((aOrbiterA * 3938460345031496843U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 26U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterI, 12U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 3U)) + aOrbiterA) + aPhaseGWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 50U) + aOrbiterK) + RotL64(aOrbiterE, 39U)) + aPhaseGWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 21U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // grow_key_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aInvestLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8261U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 14895U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8718U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11537U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15591U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 8429U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 58U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 6068543441070417854U) + aPhaseGOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 2995980468193441856U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 11U)) + 18020277482171594003U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 44U)) + RotL64(aCarry, 27U)) + 4293807434721230702U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 57U)) + 7980599111583893156U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8593141111851052016U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5903487523900084325U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2508618861111356699U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15112035513447930209U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9854037263057006439U;
            aOrbiterF = RotL64((aOrbiterF * 396276470208637283U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 16759760289688823193U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12622628933030601390U;
            aOrbiterG = RotL64((aOrbiterG * 2151912984825538321U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1264668857268123425U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16302812053619101593U;
            aOrbiterB = RotL64((aOrbiterB * 18291400055836111547U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16087995784896123610U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7970269262800468363U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14924752223305807461U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterE, 3U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 12U) + aOrbiterE) + RotL64(aOrbiterB, 40U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterE, 53U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // grow_key_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aInvestLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20378U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((aIndex + 17044U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 17541U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20971U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17070U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 19408U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererG + RotL64(aIngress, 50U)) + 4752759164691497960U) + aPhaseGOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 12088872623537639782U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 35U)) + 3734943577379734227U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 8854778183012444234U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 16948373492893967275U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7962415690046184385U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 1872682375669714454U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 959061892772099785U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7776801806943853566U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16665439117257230732U;
            aOrbiterB = RotL64((aOrbiterB * 6866375628213114965U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11088186766134265676U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10850237991780969350U;
            aOrbiterG = RotL64((aOrbiterG * 7547414856143095121U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6464817712131305812U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 244557182884209844U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2394270354887582889U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 13261563971157415841U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2323811103717827362U;
            aOrbiterE = RotL64((aOrbiterE * 11483723582415081925U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 24U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterG, 13U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + RotL64(aOrbiterE, 46U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterK, 3U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 30U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // grow_key_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneA, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneA backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25810U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 30067U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 28539U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29564U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29921U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 28028U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 48U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererF + RotL64(aScatter, 51U)) + 18144572925667544139U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 5659758077574059728U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aIngress, 26U)) + RotL64(aCarry, 37U)) + 6343330616999166392U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 17754639838410839447U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 11U)) + 9451843819849581729U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 7957854457197462212U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1461994799722205010U;
            aOrbiterD = RotL64((aOrbiterD * 13431080873536691809U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 18002214276252170177U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14689869073147027164U;
            aOrbiterF = RotL64((aOrbiterF * 12242482963989582191U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3978104368003440293U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8512135845221335386U;
            aOrbiterH = RotL64((aOrbiterH * 10506667163729414667U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1477533446382953439U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2166717790929947990U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6538884492418324461U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8082437060686606995U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4363687722464700362U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7199165810993478887U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 42U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 23U)) + aOrbiterD) + aPhaseGWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 46U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererE, 44U);
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

void TwistExpander_Billiards_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
        // ingress from: aExpandLaneA, aExpandLaneB, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4869U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 3184U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2624U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4456U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6754U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3344U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 6654158889644956636U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 9045779659363991870U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 26U)) + 3888897662136993491U) + aPhaseHOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 6882016842864459345U;
            aOrbiterB = (aWandererA + RotL64(aCross, 5U)) + 15601891715956172291U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 5176811598629335350U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12519945150889074325U;
            aOrbiterC = RotL64((aOrbiterC * 8721098129033306427U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4552583214397603278U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14225482701804864688U;
            aOrbiterA = RotL64((aOrbiterA * 8526052833180466359U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5485298070606280363U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11237713257388094289U;
            aOrbiterB = RotL64((aOrbiterB * 11032429223099413011U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14340345895626142788U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16275167270553643347U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7308578867128951199U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14041860597556520250U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1436068974197066343U;
            aOrbiterK = RotL64((aOrbiterK * 3938460345031496843U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 46U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 23U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 44U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + aPhaseHWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterK, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // grow_key_b loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aInvestLaneB
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14495U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((aIndex + 14371U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 13066U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8203U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8770U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11502U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 48U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 5131645209694953015U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 12070391048835379854U) + aPhaseHOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 21U)) + 2604295836242338724U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 12U)) + RotL64(aCarry, 29U)) + 14042039029284001596U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 39U)) + 8914654543854559327U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2185619407969359869U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5187406295103352574U;
            aOrbiterF = RotL64((aOrbiterF * 10497064008152537837U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8022832481290871217U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8783061916740573472U;
            aOrbiterK = RotL64((aOrbiterK * 3309891377744201773U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 10711028365596196301U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 13387065038269133571U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12444578026365205255U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11187001318931801582U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14191473173276034019U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2491253922434756431U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16207761776716426435U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9677408414452078760U;
            aOrbiterC = RotL64((aOrbiterC * 5487303383095129949U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 36U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterK, 13U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 54U) + aOrbiterC) + RotL64(aOrbiterH, 21U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterE, 5U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // grow_key_b loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aInvestLaneC
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21079U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 18710U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 17749U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19372U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21361U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21945U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 8988572360732005217U;
            aOrbiterE = (aWandererK + RotL64(aCross, 52U)) + 17889613225105985335U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 35U)) + 15563478320513948626U;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 3441351228410524816U) + aPhaseHOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 4425592689451435346U) + aPhaseHOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 12733160231627305928U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3574152157304607854U;
            aOrbiterI = RotL64((aOrbiterI * 3488682351509384035U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15167631896729808783U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15822667973915417055U;
            aOrbiterD = RotL64((aOrbiterD * 5155661648455308057U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17181685481076577637U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9979204751408873468U;
            aOrbiterJ = RotL64((aOrbiterJ * 8244434774754786565U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 1334240485667164762U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 9190066751460137016U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14585141844653660363U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15465215829109246336U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2305208282453624419U;
            aOrbiterH = RotL64((aOrbiterH * 10257861974108363283U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 58U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 35U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterE, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 28U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // grow_key_b loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30456U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 26003U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 29715U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26979U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26929U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 25009U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 47U) + RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererA + RotL64(aIngress, 27U)) + 7893287783892523139U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 10257331997383491153U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 14562226733652231753U;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 14320342577110737851U) + aPhaseHOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 58U)) + 9816717579822880756U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9558926960095881953U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9230371862654338324U;
            aOrbiterK = RotL64((aOrbiterK * 8842712825810461561U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6414274291252913420U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13868546184398350849U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1547986864837497409U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16940736952569949038U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2866957764814864371U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3554702178644797003U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7916721976073979724U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1602444214978842275U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11072503711308122385U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9529061385251008037U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8402775110887376588U;
            aOrbiterA = RotL64((aOrbiterA * 13980225144628227381U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 18U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 14U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 47U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterD, 37U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 46U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
