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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x99EE08EE139380EBULL + 0xA8A13678DD53DE31ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8A9659E3E7C5A365ULL + 0xF22A18BF1F6279CCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD77C3F91E00B6B03ULL + 0x85215A48EEEF1834ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFAC1759900E793FDULL + 0xEC8FCAA3AB32C5D6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF031B730A6EC8669ULL + 0xFE1F3E92D821F682ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCEFACBF4DD6839CDULL + 0xC7CA02EDB293056EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFA091CE7796397E5ULL + 0x98D62FE9C5B08FCDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCB8190A10F5F4E2BULL + 0x93BCA25E90DF3502ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFB7901A8151A2477ULL + 0xDB52D1D6472AF1ECULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA1961F91D4157275ULL + 0xAF8F798DD400CF83ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAF91224D335B2EEBULL + 0xD00F45A5ACD13F8EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEC67BCA870CC2953ULL + 0xB360838BFE7B5DF6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8B109E0827C2F93DULL + 0xC3C974CB5E53D9D8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFD8D8EC467ADE0E5ULL + 0xBA496F08C211113DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA4877AEB304B4D39ULL + 0xAA49C1759B40C5E6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB4B826CD24311EF3ULL + 0xA741E916927A77DFULL);
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
            aIngress = RotL64(mSource[((aIndex + 1593U)) & S_BLOCK1], 54U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 2644U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 2126U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((aIndex + 967U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 26U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (aWandererJ + RotL64(aIngress, 53U)) + 12029393034357490020U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 24U)) + RotL64(aCarry, 19U)) + 4526754731580694987U) + aNonceWordJ;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 37U)) + 17060419646421271853U;
            aOrbiterB = (aWandererG + RotL64(aCross, 21U)) + 4128488893837059683U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 11U)) + 12706894827547160110U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 57U)) + 12506324593645825056U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 3U)) + 12581344490649250025U) + aNonceWordM;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 14357032418199130132U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aCross, 40U)) + 15341977701796331249U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 13U)) + 7086602307544733241U) + aNonceWordE;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 12398300065276832486U) + aNonceWordK;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2499745046076601988U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7249361592814001829U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 14597139848072319685U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3254456186337366437U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3472973415969046680U;
            aOrbiterA = RotL64((aOrbiterA * 14583566953969168353U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7905718972111691591U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15941413652144021522U;
            aOrbiterC = RotL64((aOrbiterC * 3473779492962783565U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10583964125960308762U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 13659925272340853715U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16708294803316630743U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9487054537489454887U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13287757570441887517U;
            aOrbiterJ = RotL64((aOrbiterJ * 17351439045329892107U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15279245465808571942U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12424999114621745879U;
            aOrbiterD = RotL64((aOrbiterD * 2274918760256527137U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13915392738892970475U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13797668053788805126U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 13752161103680525317U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14344766585550401077U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13727554194373146727U;
            aOrbiterI = RotL64((aOrbiterI * 17164450431362670223U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1332966642432651232U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 938583742533681467U;
            aOrbiterF = RotL64((aOrbiterF * 13323340043936037549U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5659239372701978244U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8501778564909302938U;
            aOrbiterH = RotL64((aOrbiterH * 15629932660749672503U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1698500835332753591U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12029393034357490020U;
            aOrbiterB = RotL64((aOrbiterB * 18176507271635640153U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterK, 23U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 24U) + aOrbiterB) + RotL64(aOrbiterF, 41U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 57U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterA, 28U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterA, 19U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 6590U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 8071U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7391U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((aIndex + 10809U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 41U) ^ RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = ((aWandererB + RotL64(aScatter, 21U)) + 9774364261626083532U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 39U)) + 18059001521926116420U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 10615626210406381148U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 42U)) + 10536484278007898620U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 57U)) + 13320663045139972700U) + aNonceWordN;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 17127001787268166583U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 16742574590844166551U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 12U)) + 8347719720758228053U) + aNonceWordE;
            aOrbiterE = ((aWandererI + RotL64(aCross, 53U)) + 13502468705946051986U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aPrevious, 51U)) + 3512687886188904904U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 19U)) + 495660316165795934U) + aNonceWordI;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5092722552034477356U) + aNonceWordB;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15641128019608284015U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 3621036395703527059U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15421873776811085458U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17978775513204574125U;
            aOrbiterK = RotL64((aOrbiterK * 18359600395119440183U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16617179197537669849U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1931805387534012528U;
            aOrbiterF = RotL64((aOrbiterF * 3400139345857733775U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9544923119559308431U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12930999400470173353U;
            aOrbiterD = RotL64((aOrbiterD * 16791006919271490005U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 13673733276226249890U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2032263473309124738U;
            aOrbiterC = RotL64((aOrbiterC * 3088728329261360607U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14868502349358414206U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 10116495537187552321U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1380512121796709469U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5341113995358179244U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8415417980279705731U;
            aOrbiterG = RotL64((aOrbiterG * 8521501372683793821U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2462819265072352463U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7657062767608441931U;
            aOrbiterA = RotL64((aOrbiterA * 15554638801273540163U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8153420530633265789U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 10990681417675210534U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 1928509513380702895U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17035995983178569271U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2806563871848226777U;
            aOrbiterB = RotL64((aOrbiterB * 4137935663733587867U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6570698907081812011U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9774364261626083532U;
            aOrbiterH = RotL64((aOrbiterH * 1766375419340392741U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (RotL64(aOrbiterF, 34U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 6U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterC, 19U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterF, 21U)) + aNonceWordD) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 40U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + aNonceWordJ);
            aWandererG = aWandererG + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 13U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterH, 51U));
            aWandererF = aWandererF + ((RotL64(aCross, 34U) + aOrbiterG) + RotL64(aOrbiterJ, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 48U)) + aOrbiterE) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 16006U)) & S_BLOCK1], 52U) ^ RotL64(mSource[((aIndex + 11939U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 11084U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 11805U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 29U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 3U)) + 8367680518550579791U) + aNonceWordL;
            aOrbiterG = ((aWandererK + RotL64(aCross, 19U)) + 11491674725611181241U) + aNonceWordA;
            aOrbiterI = (aWandererA + RotL64(aScatter, 46U)) + 16673861720782164214U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 27U)) + 9786610124108350855U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 53U)) + 5745080601557577637U) + aNonceWordE;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 1959402215131684684U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 6121650036079196522U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 58U)) + RotL64(aCarry, 21U)) + 12016309761037342392U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 5U)) + 5986936646177049603U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 23U)) + 1000367700904043468U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 37U)) + 17425288243569101032U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4856917474950325209U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16312111093223166419U;
            aOrbiterI = RotL64((aOrbiterI * 11046477664487805241U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 456110002032422270U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11393724374787795662U;
            aOrbiterA = RotL64((aOrbiterA * 1176984359123668389U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8378176867715697176U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8086186452345234815U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8450438271765985235U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8470349167474173245U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2528229938740192694U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8717790851266520943U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13247168811545753141U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8745293957516815264U;
            aOrbiterJ = RotL64((aOrbiterJ * 14270617180621072619U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6165915500564961987U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12015407798844173213U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3913451986559154153U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 545006684939922156U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16366753936267185001U;
            aOrbiterC = RotL64((aOrbiterC * 6495185976430013201U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 3097605623436091728U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15950167830259022926U;
            aOrbiterB = RotL64((aOrbiterB * 4415538963984293323U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8356327899232213426U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10183421678251169945U;
            aOrbiterE = RotL64((aOrbiterE * 9474380650337109299U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16327340177970834683U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7086901180933495535U;
            aOrbiterG = RotL64((aOrbiterG * 1276521829484494857U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13421211370092080006U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8367680518550579791U;
            aOrbiterD = RotL64((aOrbiterD * 12256662446176946163U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 6U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 18U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 30U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aIngress, 40U) + RotL64(aOrbiterK, 51U)) + aOrbiterJ) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterB, 13U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterC, 21U)) + aNonceWordF);
            aWandererC = aWandererC + ((((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterK, 54U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterF, 43U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 21530U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((aIndex + 18230U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 17194U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 19886U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20924U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 20U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 16183871922837164759U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 36U)) + 7002058258090219055U;
            aOrbiterH = (aWandererE + RotL64(aCross, 3U)) + 5650868611888303705U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 13U)) + 11899839660943876690U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 43U)) + 15349649504488111111U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 14060149569086744970U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 12920917574225030112U) + aNonceWordG;
            aOrbiterG = (aWandererH + RotL64(aScatter, 47U)) + 2831994965175330135U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 53U)) + 18312543585028439192U) + aNonceWordL;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 56U)) + 11657562205118394239U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 51U)) + 10850792819281246052U) + aNonceWordH;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17810371216216125323U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7963413941144223128U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 534217972450595401U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5498715358793875584U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9256727548911651373U;
            aOrbiterJ = RotL64((aOrbiterJ * 10498848323914000989U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17246360111302191699U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 18309978718113983369U;
            aOrbiterK = RotL64((aOrbiterK * 18267472694666221077U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3100998994319502921U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8129301860291235970U;
            aOrbiterA = RotL64((aOrbiterA * 17847033539279176187U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1889641029473279114U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 16538494307002917945U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 8081488217920885783U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5432230549146849322U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2634437941396090817U;
            aOrbiterD = RotL64((aOrbiterD * 7612999214758935211U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16940172599174185058U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13151669140593952203U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 16225319638131723487U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3995064294869931681U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 913081077665768816U;
            aOrbiterG = RotL64((aOrbiterG * 9299514648768060453U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2469001696075411481U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2167390955194185443U;
            aOrbiterI = RotL64((aOrbiterI * 11805065572289005223U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1574066406534010796U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8736976961589874013U;
            aOrbiterE = RotL64((aOrbiterE * 5980070607180321955U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4233621443153132083U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16183871922837164759U;
            aOrbiterF = RotL64((aOrbiterF * 4030569514959370895U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 44U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 38U) + aOrbiterE) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 37U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 37U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 35U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + aNonceWordA) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + RotL64(aOrbiterF, 20U)) + aOrbiterD) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 41U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterH, 3U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterI, 24U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 25389U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 22519U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(pSnow[((aIndex + 23256U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 26295U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26855U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 22969U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 12U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 13333509828310369865U) + aNonceWordP;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 50U)) + 7645352517103840797U) + aNonceWordG;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 21U)) + 5310766306660062655U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 13U)) + 5165635069832352932U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 39U)) + 15684141764734281849U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 3327963374225061738U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 5U)) + 8625811794878848871U) + aNonceWordD;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 7598657468430485291U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 54U)) + 2881171216276746485U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 43U)) + 10237691227222918101U) + aNonceWordH;
            aOrbiterI = (aWandererI + RotL64(aIngress, 29U)) + 6419254255884834497U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4238455444646479956U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 14936613353493061492U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 3544216916806292273U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15324699725208372627U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9506640480601832011U;
            aOrbiterK = RotL64((aOrbiterK * 12819564111348390227U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3709149613660215641U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 1724290199312754307U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 12597580418257897965U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 13191172833570139194U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3686087945377837886U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10883609557429936283U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10418330386245397022U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5383531313632347245U;
            aOrbiterF = RotL64((aOrbiterF * 2987755379396160073U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7414716553072652212U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11301761123966206201U;
            aOrbiterD = RotL64((aOrbiterD * 1546727321088592187U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8570229732236388847U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8773754460060264773U;
            aOrbiterG = RotL64((aOrbiterG * 3251360788932563495U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 13636929800504199371U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5486599841558573720U;
            aOrbiterA = RotL64((aOrbiterA * 2867914211589815153U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 13277541451512422776U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10409779509190185921U;
            aOrbiterC = RotL64((aOrbiterC * 1926650154570961573U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7268295836403414306U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13815969853235433830U;
            aOrbiterE = RotL64((aOrbiterE * 11603750346752441535U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9353249174240162324U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13333509828310369865U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10381405217943841655U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + RotL64(aOrbiterF, 27U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 37U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aIngress, 44U) + RotL64(aOrbiterG, 39U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterD, 41U));
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterC, 18U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 35U)) + aOrbiterI) + aNonceWordA);
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 14U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterK, 5U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 60U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 12U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 27549U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((aIndex + 27528U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 29387U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28041U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29507U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 29767U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 13U)) + 11480359716598965890U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aWandererB + RotL64(aScatter, 60U)) + 15431182525482873419U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 11360504974812776707U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 27U)) + 9292576416573382769U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aScatter, 19U)) + 1549257414531028975U) + aNonceWordP;
            aOrbiterG = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 5347769463033129317U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 35U)) + 17019199177478377234U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 42U)) + 16558106007323125094U;
            aOrbiterF = (aWandererI + RotL64(aCross, 5U)) + 3976182233825939422U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 53U)) + 2889047161195954395U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 2241831345026962605U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12850802412140579294U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13541744735436450160U;
            aOrbiterC = RotL64((aOrbiterC * 906089290000537439U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 2085863085516538212U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2969034221711544086U;
            aOrbiterJ = RotL64((aOrbiterJ * 7768528124408400403U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6482666944512391472U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16969153556875844613U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 9483462388353216219U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5161314086757363678U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7150282484670673211U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8522427002337918663U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5465304381272305847U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2344610773390354017U;
            aOrbiterD = RotL64((aOrbiterD * 17010258514288089191U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8335906578006588582U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13668796013474193793U;
            aOrbiterB = RotL64((aOrbiterB * 8228000547141147777U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9663362594301419686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3683773739120343413U;
            aOrbiterH = RotL64((aOrbiterH * 8319320803406104749U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2538583190438044942U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 4454069062219406996U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16329554225309389599U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17177136683616247897U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3680497519697457252U;
            aOrbiterK = RotL64((aOrbiterK * 6479357366957384599U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 16812938441063719463U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4545693142067578891U;
            aOrbiterF = RotL64((aOrbiterF * 17479957806084346527U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9232311730019478327U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11480359716598965890U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6678546065399772697U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 18U);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 20U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 41U)) + aOrbiterG) + aNonceWordM);
            aWandererB = aWandererB + ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterK, 43U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 6U) + aOrbiterD) + RotL64(aOrbiterB, 39U));
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterH, 11U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterA, 5U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterC, 27U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterE, 53U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 46U) + aOrbiterE) + RotL64(aOrbiterC, 56U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterB, 29U)) + aNonceWordA) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererH, 54U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA05A8760C7A07D59ULL + 0xF7E7175988758441ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x93A38DF51EDC7EA9ULL + 0xB85F1DE0E183D0BFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9640EC5D1D446E5FULL + 0xA794893C2F88BEE9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF6B32474D6DAA741ULL + 0xDDAAC53B5FDE57E3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB502D2900C1970B5ULL + 0xE9DB6D6AD388A70EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFE37F0B46C4F8259ULL + 0xBAADB107D553B08DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x929F5B263A40FCA5ULL + 0xD6F1940D09FBA3BEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC3A41F02037DFCEBULL + 0xFDFFEEFD20A3D041ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE3318B5ECAD72F55ULL + 0xD74D4A8448A5F71BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCCCA1B388BD7F97BULL + 0xA320C2C836DD72FEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB0E9B79817BB68DFULL + 0xF292FAE309C8BA6CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x829F76C649CC9D43ULL + 0xD7674E7AEDA52471ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA423AA5299E2E925ULL + 0x8CA9C2BF9145A5F3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA5876CBED9AB5A6DULL + 0xFDF2D6EC6D567092ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDEA426FD7F198A9BULL + 0xAA1E7FE187ADE104ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9F16C5ACA52D7E15ULL + 0x8DBE4EBA92EA9618ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 1706U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 536U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6331U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((aIndex + 3351U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aPrevious, 13U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererA + RotL64(aScatter, 57U)) + 9446153639709651566U) + aNonceWordP;
            aOrbiterJ = (aWandererK + RotL64(aCross, 53U)) + 10550762260670758167U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 10U)) + 7062634922142578383U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererF + RotL64(aIngress, 35U)) + 9178499097812764515U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 43U)) + 6887103379773525538U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 6239750312052010257U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 17645022614523287959U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 3639618183259408272U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 4U)) + 3131737117548745095U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7253994382396406554U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15217993711938379561U;
            aOrbiterB = RotL64((aOrbiterB * 17853313384747259923U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 12594152227603630033U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 11250170200489647869U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 546800378327864723U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12936942656624279424U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 10990736056052106149U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 7123916809953459187U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12787293075893090465U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17154990205620778151U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 10031369940028159521U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1270827262969060301U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17337623431665013136U;
            aOrbiterH = RotL64((aOrbiterH * 1517262088236356107U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 830330490987911853U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6828309232554560547U;
            aOrbiterD = RotL64((aOrbiterD * 9742464176986145819U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11470087853413986203U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10470148870747884420U;
            aOrbiterJ = RotL64((aOrbiterJ * 6766079738799967443U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18315536891901859637U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12264670822285914271U;
            aOrbiterI = RotL64((aOrbiterI * 5841574505408674119U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10931842095884524879U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11134871340959676257U;
            aOrbiterC = RotL64((aOrbiterC * 11714837622285605745U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 48U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD) + aNonceWordA);
            aWandererG = aWandererG + ((((RotL64(aCross, 42U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 38U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 53U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 43U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 18U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12891U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneB[((aIndex + 11198U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9312U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16345U)) & S_BLOCK1], 12U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8624U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 4476099022490972343U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 16836423700375760429U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 8850577488928703557U) + aNonceWordN;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 52U)) + 7091631824560042743U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (aWandererK + RotL64(aIngress, 27U)) + 12560498899956759494U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 5U)) + 7797973377112012161U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 41U)) + 6173820673874805794U) + aNonceWordD;
            aOrbiterD = (aWandererA + RotL64(aCross, 58U)) + 10805025132310245348U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 35U)) + 7139216143268029968U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8241544862261635722U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4735527016563596150U;
            aOrbiterI = RotL64((aOrbiterI * 6621354217673598381U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5166171126690294033U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11117641762075368393U) ^ aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4980156869201219393U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6312932356458415421U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1304139291184508668U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 90744653170922319U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10085025354842771067U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16745854428789531080U;
            aOrbiterB = RotL64((aOrbiterB * 1945983905747274355U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2497187958708890337U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16069701876646548995U;
            aOrbiterC = RotL64((aOrbiterC * 16606039730973709495U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17242004368025978091U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12334315722243232121U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 16528598396696346719U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8007042082518126895U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5665686359038811484U;
            aOrbiterG = RotL64((aOrbiterG * 11289316305875751813U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 3913477186958600592U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16918984318564170343U;
            aOrbiterD = RotL64((aOrbiterD * 5128293326494417281U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10227611546502931418U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7187623463085447228U;
            aOrbiterJ = RotL64((aOrbiterJ * 8479839369622163181U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 24U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterD, 14U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterK, 51U));
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK) + aNonceWordK);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 58U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aIngress, 56U) + aOrbiterB) + RotL64(aOrbiterC, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterC, 47U));
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19827U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((aIndex + 21796U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18113U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17860U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20489U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 20163U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 57U)) + (RotL64(aPrevious, 24U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (aWandererB + RotL64(aScatter, 21U)) + 6069475454765660321U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 52U)) + RotL64(aCarry, 57U)) + 11483704742497268068U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 47U)) + 11055697447388986418U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 35U)) + 10897095046039997004U) + aNonceWordF;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 29U)) + 4731637118230457840U) + aNonceWordO;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 13855839187084986751U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 11U)) + 5328208115460188239U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 41U)) + 12479538544291412985U) + aNonceWordL;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 56U)) + 10740165998792608231U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6492798157284955373U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13056825957483891921U;
            aOrbiterK = RotL64((aOrbiterK * 14882112110627751751U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2068184064919194657U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 5656302738780746294U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 16493021179127646345U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11193756120230763294U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17306750816837208999U;
            aOrbiterC = RotL64((aOrbiterC * 7949360041241439741U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 12952818800389361804U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15380412293642628312U;
            aOrbiterG = RotL64((aOrbiterG * 2914662289178925547U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7706090204767242996U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14598802276412649570U;
            aOrbiterF = RotL64((aOrbiterF * 4821408736292041399U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17819762117328075515U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6481384240915075101U;
            aOrbiterA = RotL64((aOrbiterA * 4836701121865783029U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 754936290510338717U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15510875946573720154U;
            aOrbiterE = RotL64((aOrbiterE * 2994718968852184303U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 9245381722813944586U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2629847912019726214U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6718795794951106961U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3909987749797113773U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9277056074757335265U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11580847505996697115U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 46U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 27U)) + aNonceWordN);
            aWandererA = aWandererA + ((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 41U)) + aOrbiterB) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterE, 5U)) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aCross, 38U) + RotL64(aOrbiterH, 14U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterE, 23U));
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32478U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneC[((aIndex + 25887U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 24910U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24728U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28839U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 30009U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aPrevious, 47U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = (aWandererJ + RotL64(aIngress, 57U)) + 18319689184146942855U;
            aOrbiterE = ((((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 8041304130090501019U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 11347064191990897738U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 51U)) + 15242243470024447468U) + aNonceWordE;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 26U)) + RotL64(aCarry, 5U)) + 10619749107163611105U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aScatter, 43U)) + 14795614276221947128U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 39U)) + 1578095288886372393U) + aNonceWordB;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 5U)) + 13593906305770501684U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 18U)) + 8919815528334599172U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17425548324720065145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11125018338392347335U;
            aOrbiterA = RotL64((aOrbiterA * 4377887040461528587U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3779189180734244399U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10958224663276134041U;
            aOrbiterF = RotL64((aOrbiterF * 6206963519509783781U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4317305352561612995U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4891139433808505355U;
            aOrbiterB = RotL64((aOrbiterB * 11507024985663120317U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 5166074784835930965U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 10080890270621589202U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 13170894418184288695U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4501071771615514619U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6486573807774431753U;
            aOrbiterK = RotL64((aOrbiterK * 324029625116648669U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15714881857668975753U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3506619392820235900U;
            aOrbiterJ = RotL64((aOrbiterJ * 5707033870161224499U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5295711072762443783U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11192836530396570648U;
            aOrbiterG = RotL64((aOrbiterG * 4361810118382207039U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 7993389678399774574U) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 12551394763541226695U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11903486656172026403U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11553674370322129668U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4459881583199320245U;
            aOrbiterI = RotL64((aOrbiterI * 2805857426321555685U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 38U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 34U)) + aOrbiterJ) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 39U));
            aWandererD = aWandererD + ((RotL64(aIngress, 34U) + aOrbiterA) + RotL64(aOrbiterH, 3U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterE, 14U)) + aNonceWordO) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterK, 19U)) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterH, 43U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererH, 12U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEE7379F569A1C321ULL + 0xC50A123C10EA42C4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x886B7EA3C4F4EF17ULL + 0xCAA5783AD619D053ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE289970A40FF896DULL + 0x8DD16FAAE7EFAFF3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA0C2F6FEE81B814DULL + 0xC068C94B4496F16BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCEC2ED610E850301ULL + 0xD3FA3D32A415E74CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x84EE4837FD7EE801ULL + 0xCF2ACD37CD597826ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x94E5679C6F654AF9ULL + 0xFC86E835E9DDE9DBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF0C1889CCA6FEBBFULL + 0xA75A577E757B5B08ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x83D03773C15A3293ULL + 0x9D65DD6910C1DFF8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8DADFE688E660957ULL + 0xD844C210D4FBC0CBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBF89710719751AFDULL + 0x9EE7BAC622FFDD96ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFBD2875E21576F2DULL + 0xBE88D312F459B1F9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA846D71EEC2551C5ULL + 0xE52290A78A028D89ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE4530E4E329B7869ULL + 0xDEC0643BF3E84A25ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8CDCDF13E1FDE07BULL + 0xF5FCBF6C3727C8EBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC4C627D98F4A21F5ULL + 0xEA1FEFFA2B9C956EULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneA, aWorkLaneB, aFireLaneD, aWorkLaneC, aFireLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4732U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 5382U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4745U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6566U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 5452U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 4U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 19U)) + 12262991801139086177U) + aNonceWordO;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 7963038771924890197U) + aNonceWordL;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 37U)) + 15540520327933568896U) + aNonceWordA;
            aOrbiterI = ((((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 8745565892055020722U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 52U)) + RotL64(aCarry, 23U)) + 16619329199683755286U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10865705026433867260U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2743368697984518059U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2989232417816919375U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5556006271515473135U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5355833281353498588U;
            aOrbiterD = RotL64((aOrbiterD * 4190140212757841511U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8313616108963479829U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16657121016801866434U;
            aOrbiterI = RotL64((aOrbiterI * 331533349428472477U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16532226425013000833U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 5800465874932467232U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5966395771690704577U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17882948163883121328U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15029375310296563175U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17021415832288477713U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 14U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterE, 4U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE) + aNonceWordP);
            aWandererA = aWandererA + (((((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + aNonceWordI) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 48U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14344U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((aIndex + 15103U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 16091U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15569U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8849U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15262U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 9914837590440975587U) + aNonceWordK;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 29U)) + 6706125076401958051U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 16570817772679258409U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 46U)) + RotL64(aCarry, 13U)) + 6843705658115186948U) + aNonceWordB;
            aOrbiterB = (((aWandererD + RotL64(aCross, 3U)) + 16099930446791572351U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5420550009556030459U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5729549069420177477U;
            aOrbiterJ = RotL64((aOrbiterJ * 7842192631021712569U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15590601126188675834U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13044027390998620029U;
            aOrbiterC = RotL64((aOrbiterC * 16845199115313444123U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11068338135659636772U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 6584988841809544332U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 1683336180438945439U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 8516813219883915404U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10647314042912492785U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 15559481057047148785U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 201691689889605304U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15512161798401184003U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11473219183982564709U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 12U) + aOrbiterJ) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 47U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 42U)) + aOrbiterJ) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 29U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22514U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 18194U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 17361U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20693U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18373U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 19439U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 39U)) + (RotL64(aCarry, 6U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 7948891781097675369U) + aNonceWordP;
            aOrbiterA = (aWandererC + RotL64(aIngress, 51U)) + 13928362874228230226U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 30U)) + RotL64(aCarry, 43U)) + 10776180542602258926U) + aNonceWordE;
            aOrbiterD = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 5735115172149470447U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aIngress, 5U)) + 5353591822981766987U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 562301708107268570U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 10467810247578364868U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 10449089554007059823U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 14541630141152308564U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2350076897065139429U;
            aOrbiterI = RotL64((aOrbiterI * 12222554362482034393U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17519109078651162228U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6061035173339902910U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10021905773432907835U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 15654836633731000065U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 13723521735153718904U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 14459516479283070563U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2849680038315532197U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17336102435576647923U;
            aOrbiterG = RotL64((aOrbiterG * 10984689101753586739U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterA, 60U)) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterH, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 51U)) + aOrbiterD) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aScatter, 14U) + RotL64(aOrbiterG, 21U)) + aOrbiterI) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererG, 20U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27650U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 30148U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28294U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24653U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29710U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26581U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 29073U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 50U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 3U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 12380376990224645149U;
            aOrbiterG = ((((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 18296928500297384014U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 56U)) + 3550626816361145100U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 2667792936946706027U) + aNonceWordH;
            aOrbiterH = ((aWandererI + RotL64(aCross, 19U)) + 12020969779370926953U) + aNonceWordC;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 737340727886903447U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1681797651799760502U;
            aOrbiterA = RotL64((aOrbiterA * 11923920414802777451U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2956186342689489064U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1876852870402977177U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8875540081346621757U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 6433205819353555071U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9065076854974222998U;
            aOrbiterG = RotL64((aOrbiterG * 5459675878087242021U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3254410578766789992U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2005081975473815576U;
            aOrbiterJ = RotL64((aOrbiterJ * 9947701153722014085U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 15992999234834560419U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3458344156815120948U;
            aOrbiterE = RotL64((aOrbiterE * 1668460113964608051U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 46U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + aNonceWordB);
            aWandererA = aWandererA + ((((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterH, 12U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterA, 53U)) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDF88C537087A1E6FULL + 0xE76E765DD9172C47ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8F90DD641C1C16A3ULL + 0x9290B4963958C9F6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA5409E111D91EF69ULL + 0xDEACEFA899B7BFFBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFEC46EB0CA98BB2FULL + 0xAB083C0C92910B3BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB93414602DBC0A0DULL + 0x90010E07880C8C08ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD3275224C69E3E93ULL + 0xAB8B413EC9A05A55ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB8A0DC79A4C30BD7ULL + 0x998EA1A4368B3C40ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8FEBBD6F89209BDDULL + 0x83138DDC9EB37D41ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9EC0B44C37621A4BULL + 0xBDB16066C02161D8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA43BA98417753567ULL + 0xC1253E2FA6C33811ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x98EBCF4A2A4DDEADULL + 0x951AB3AB06C64101ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9D216F6DAEE06EC9ULL + 0x84A72C849F757CC0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9A8B0362BC544A7BULL + 0xF32246EF7E044B05ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x94110DF2038BD1FBULL + 0x975D7272ED2181A9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDFF0F842FB1821B9ULL + 0x8D7D108F51D9C5ECULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE3E704B23E5F6B21ULL + 0x93473B538BDC6BD8ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aFireLaneC, aWorkLaneA, aOperationLaneC, aOperationLaneB, aWorkLaneB, aOperationLaneD, aFireLaneA, aWorkLaneC, aFireLaneD, aOperationLaneA
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5437U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 6594U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4831U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2888U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5083U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 1437U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = ((aWandererA + RotL64(aScatter, 23U)) + 898812731947995389U) + aNonceWordI;
            aOrbiterG = (aWandererC + RotL64(aIngress, 50U)) + 8677347622525527167U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 41U)) + 770321564027567654U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 35U)) + 11020474858081526395U) + aNonceWordF;
            aOrbiterF = ((((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 17289793580414993470U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 10111912559295118444U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 8083622125544542011U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7149858558922988240U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 5919683821379905699U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16705119888884231567U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6860902846079238714U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15083517836867542075U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 4686657139237578325U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14852868368708376381U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9860233289028878323U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 13418143547952204667U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 772406119079116272U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7971141501337627589U;
            aOrbiterK = RotL64((aOrbiterK * 10168120622976358617U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8478568022896691911U) + aNonceWordP;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 4027604850785607101U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 4826627523578901467U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17199331557841535430U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 7515957656979776361U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5468950152869656599U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17138249294921502391U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16236812863923234668U;
            aOrbiterF = RotL64((aOrbiterF * 2925542836624164807U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 37U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF) + aNonceWordC) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 3U)) + aNonceWordE);
            aWandererB = aWandererB + ((((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterK, 28U)) + RotL64(aCarry, 27U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 4U) + aOrbiterD) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 4U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15394U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 15136U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 15326U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12737U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14084U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 10507U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCross, 27U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 44U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = (aWandererJ + RotL64(aIngress, 21U)) + 4634399531433127141U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 16961792729406903200U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 27U)) + 4105280732301137738U) + aNonceWordF;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 15692013501147331191U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 1252216715968780587U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aPrevious, 53U)) + 7958289043012473752U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 6U)) + 6611577301818896615U) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8506226754305949140U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3648813120449403353U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 9521367946879238849U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5195245426245535735U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 542948051600803051U;
            aOrbiterI = RotL64((aOrbiterI * 4631106308856448475U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11974253551208964789U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10596463592332655367U;
            aOrbiterA = RotL64((aOrbiterA * 10941161258815714641U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12015129484061440159U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8254944355710109060U;
            aOrbiterJ = RotL64((aOrbiterJ * 3233697992479357615U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 2754858806943915419U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5007802002906662779U;
            aOrbiterF = RotL64((aOrbiterF * 15613733948331639723U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6262190752136523216U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10528977986487821428U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 1184258264034585525U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 8511097226098211854U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12091864735686692582U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6128140528141411237U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 19U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 28U)) + aOrbiterD) + aNonceWordH);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterA) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneD
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneA
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23280U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((aIndex + 21651U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 22497U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22251U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23397U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 23896U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererK + RotL64(aIngress, 60U)) + 7893287783892523139U) + aNonceWordC;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 10257331997383491153U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 43U)) + 14562226733652231753U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 14320342577110737851U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 9816717579822880756U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 5U)) + 9558926960095881953U) + aNonceWordJ;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 53U)) + 9230371862654338324U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6414274291252913420U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13868546184398350849U;
            aOrbiterD = RotL64((aOrbiterD * 1547986864837497409U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16940736952569949038U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2866957764814864371U;
            aOrbiterK = RotL64((aOrbiterK * 3554702178644797003U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 7916721976073979724U) + aNonceWordM;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 1602444214978842275U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 11072503711308122385U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9529061385251008037U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8402775110887376588U;
            aOrbiterJ = RotL64((aOrbiterJ * 13980225144628227381U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15003592180290390713U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14195681406520825751U;
            aOrbiterA = RotL64((aOrbiterA * 11455000833788877217U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3263577002367714202U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 12019422062655581928U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 5002313835338447799U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8508638054582582917U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6536618106353552880U;
            aOrbiterC = RotL64((aOrbiterC * 6233964121117511885U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 22U);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterB, 58U)) + aNonceWordF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 52U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 41U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 13U)) + aOrbiterA) + aNonceWordK);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31738U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 31434U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26426U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24923U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29627U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28911U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 34U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 46U)) + 826930775230515406U) + aNonceWordM;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 5U)) + 5137814617363250861U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 14761561947426681616U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 27U)) + 12773023438753662590U) + aNonceWordH;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 13U)) + 7331345852207096322U) + aNonceWordB;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 3899381212671247460U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 10072004147620068599U) + aNonceWordJ;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 3424585039401897560U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8246760141625966321U;
            aOrbiterA = RotL64((aOrbiterA * 11478879365443736383U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3655992860610853290U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 11154618022505863898U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4791494171286145231U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 15629361991059709973U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10842068502278489664U;
            aOrbiterB = RotL64((aOrbiterB * 17223002513104960799U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5571312349016336686U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 589313823745748879U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1356685926549786027U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13633457935771935260U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12684602052812183096U;
            aOrbiterF = RotL64((aOrbiterF * 4689206269919806711U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5711307583717354204U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7181854170553728211U;
            aOrbiterG = RotL64((aOrbiterG * 9835601115561325911U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1884620014396115821U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1471516373272364262U;
            aOrbiterD = RotL64((aOrbiterD * 5126319375714848029U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 46U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 43U)) + aOrbiterB) + aNonceWordA);
            aWandererH = aWandererH + (((((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aNonceWordP) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + aNonceWordK);
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 30U) + aOrbiterA) + RotL64(aOrbiterB, 27U)) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 13U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE0885CE16648E603ULL + 0xED4FC12BBD2568F5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x874697EE7AF46299ULL + 0x9B3AFF48E5D16DFCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC975145FFB357C05ULL + 0x97E63D5FECC8C83BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF09BB5957CA441A3ULL + 0xA1D30203E954C910ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF17ECE11874BBC53ULL + 0x917174B8E3E545BEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8DDC1BD3155E3949ULL + 0xD6486624D1574909ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD4138F89E25C24A5ULL + 0x91168C9613B8F899ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8FB5ECD255E6E055ULL + 0xC695A0038C73B0BEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD2CA3626DA4A244FULL + 0xE77CC0DA80C0507EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE7303CC3DA48007FULL + 0xDA8ED3BD0F51B460ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB528726E81F703AFULL + 0x89B6824DF546C407ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDCF3A9FB8997B383ULL + 0x95ADFE7A46A6A7F5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA115AB97C7699697ULL + 0xDBF9511E6EE213F7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9289108B402B4ED1ULL + 0x9CDEA1F243317556ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA0493AFDA21BD341ULL + 0xF1B0F8D1E390E7C0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x917DB34319B1153FULL + 0xB27E6301D11DA800ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneA, aWorkLaneC, aWorkLaneD, aOperationLaneD, aExpandLaneA, aFireLaneD, aOperationLaneB, aExpandLaneB, aOperationLaneC, aOperationLaneA, aExpandLaneC, aFireLaneB, aFireLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6941U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 5417U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2337U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7129U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6175U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6358U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 36U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 4622023259121087483U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 11U)) + 10253505250223501352U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 17133877904420462669U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aCross, 20U)) + RotL64(aCarry, 5U)) + 6162827793741796700U;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 3U)) + 9610986424765907615U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aWandererA + RotL64(aCross, 57U)) + 11210747154264753754U) + aNonceWordP;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 27U)) + 16554205219580654546U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10352576357413766388U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3651845783283479752U;
            aOrbiterB = RotL64((aOrbiterB * 1011289824180799641U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18145542190463500476U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5415609566767162857U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6474184559323816389U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2033734872464201570U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3507213117125813345U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5453058336688881113U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8716253393049851856U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 695984869565941856U;
            aOrbiterJ = RotL64((aOrbiterJ * 8377921610764044735U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7661578828878284931U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 906654265099155956U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 8117625377607536949U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 6050049984731254612U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17882717590338190821U;
            aOrbiterE = RotL64((aOrbiterE * 10807367411402733215U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4996521991532815957U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4246460672800604436U;
            aOrbiterC = RotL64((aOrbiterC * 12047466401960824903U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 54U) + aOrbiterJ) + RotL64(aOrbiterB, 57U));
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterF, 11U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + aNonceWordL);
            aWandererF = aWandererF + ((((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 20U)) + aNonceWordG) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 36U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12677U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneC[((aIndex + 12117U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 12042U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12860U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8235U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9951U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCarry, 58U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 7893287783892523139U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 10257331997383491153U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aCross, 47U)) + 14562226733652231753U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aIngress, 54U)) + 14320342577110737851U) + aNonceWordA;
            aOrbiterG = (aWandererE + RotL64(aScatter, 19U)) + 9816717579822880756U;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 9558926960095881953U) + aNonceWordK;
            aOrbiterH = (aWandererH + RotL64(aCross, 13U)) + 9230371862654338324U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6414274291252913420U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 13868546184398350849U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 1547986864837497409U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 16940736952569949038U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2866957764814864371U;
            aOrbiterG = RotL64((aOrbiterG * 3554702178644797003U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7916721976073979724U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1602444214978842275U;
            aOrbiterK = RotL64((aOrbiterK * 11072503711308122385U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9529061385251008037U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8402775110887376588U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13980225144628227381U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15003592180290390713U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14195681406520825751U;
            aOrbiterB = RotL64((aOrbiterB * 11455000833788877217U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3263577002367714202U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12019422062655581928U;
            aOrbiterH = RotL64((aOrbiterH * 5002313835338447799U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8508638054582582917U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 6536618106353552880U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 6233964121117511885U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 27U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 11U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 41U)) + aOrbiterH) + aNonceWordD) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterD, 18U)) + aOrbiterH) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 57U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 28U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21880U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 23175U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18084U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19188U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18041U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 17114U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 44U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 21U)) + 8604208734152026945U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 28U)) + RotL64(aCarry, 41U)) + 1374329953253889829U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 5779278910548228339U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 17670451230882805140U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 43U)) + 8193848740764866860U) + aNonceWordN;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 51U)) + 15801168428145650104U) + aNonceWordP;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 13U)) + 2584718176087499066U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 14950366247822737997U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9779293225265670135U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 11625969538497982117U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 8688968319288372383U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13665723186950342601U;
            aOrbiterE = RotL64((aOrbiterE * 292035540396910837U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9395428688359973510U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2152719218018108418U;
            aOrbiterB = RotL64((aOrbiterB * 15271961483518392671U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1350324137411377992U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8729317951386057921U;
            aOrbiterG = RotL64((aOrbiterG * 6008790836417785083U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 6317310451893678411U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10175620379041384281U;
            aOrbiterI = RotL64((aOrbiterI * 14079679617394330781U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1203082119358827708U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 523869107818193101U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 4629501113595689157U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4028324959540432983U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15447631947468213912U;
            aOrbiterC = RotL64((aOrbiterC * 6037306615787729185U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterC, 14U)) + aOrbiterG) + aNonceWordG) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterI, 5U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 53U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 36U) + aOrbiterA) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31201U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 26147U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31418U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26033U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26061U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 31687U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (aWandererK + RotL64(aScatter, 13U)) + 15383045568644941552U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 58U)) + 17452811657750910067U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 15660117718455155603U;
            aOrbiterE = ((((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 10396441207743665753U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 3708971058200841442U;
            aOrbiterG = (aWandererF + RotL64(aCross, 29U)) + 7000673057768598750U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 51U)) + 9886354469011131596U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16018065329058043467U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5024756166109352320U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 11660932185479046483U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 6587818720728886652U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 3652672354944162319U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 10807121230791716109U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6307315649915348048U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16405347331742979258U;
            aOrbiterD = RotL64((aOrbiterD * 7183142442906743699U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5427299664054601957U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 4983381733483185898U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 14646556236306407673U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10182995521328377487U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8694282877540593550U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14614602561910403893U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4085927978153269932U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6176195962815240877U;
            aOrbiterB = RotL64((aOrbiterB * 16792916528959579875U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6966742100601433005U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9920952446921247521U;
            aOrbiterI = RotL64((aOrbiterI * 1879821050131820933U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterG) + aNonceWordI) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 29U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterI, 23U)) + aNonceWordP);
            aWandererD = aWandererD + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 38U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterI, 53U));
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9D8A40A8A62FF751ULL + 0x9082327029CA0CABULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB59462012880EF79ULL + 0xD5D705A871198A62ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDD4CBEF19D846EE3ULL + 0xD28C92DE7AE9B1C8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x96F77E28A5AA81EFULL + 0xEA69D4BA161739D9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFA19FACCBC7BB473ULL + 0x89D4E1330A2F0F37ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD01BCFEE6995FD41ULL + 0x9B0FE37546EBAC32ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB24ADACA88D950EDULL + 0xEE0E83CC85A7F098ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFC72215CAF163971ULL + 0x9BE9F7281386D93FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAAC60629B9BDB80DULL + 0xA2F3625059AD2523ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAA8848EF52B472EBULL + 0x9796C8511778D44EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB8C80C9CD222E033ULL + 0xA85EE8EE62145E90ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF0E0F2B1AD8934D3ULL + 0x9B12E59D65539A26ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE46E5F3772894C01ULL + 0xFBB7095178D48299ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA0ACE2D19B4BC909ULL + 0xC3CF4D32D3DA6DA0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAB1EBA5B561F07A3ULL + 0xB04497582CA31FBFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEFCAC754AB1C0D81ULL + 0xB7382F28F2B07A76ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aOperationLaneA, aWorkLaneD, aWorkLaneC, aOperationLaneB, aFireLaneD, aWorkLaneB, aOperationLaneC, aFireLaneA, aFireLaneC
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6262U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 6409U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 6138U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1128U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7656U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4716U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (aWandererE + RotL64(aIngress, 11U)) + 8020711767807230555U;
            aOrbiterF = (aWandererC + RotL64(aCross, 53U)) + 15368693777246341570U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 39U)) + 5117523734225562401U) + aNonceWordN;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 11U)) + 13155269151097507808U) + aNonceWordB;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 13U)) + 9879303753623578272U) + aNonceWordA;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 41U)) + 1165799257173794826U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 930641942062732091U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 23U)) + 11330571332221123153U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 19U)) + 2862963158282518899U) + aNonceWordI;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 48U)) + 6019186399361476659U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 1924419843785161958U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12618629043591380461U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9334176504266512405U;
            aOrbiterK = RotL64((aOrbiterK * 18239109235362925739U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16829692481030013551U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5604784396927022709U;
            aOrbiterI = RotL64((aOrbiterI * 2833893610883508353U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16124030106598549644U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 16571659812830230677U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4668250364992383549U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15171089673591843703U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2826755560293849328U;
            aOrbiterF = RotL64((aOrbiterF * 9397017963457655287U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9976785768283589291U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11845100564714691809U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4935139932585319251U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7318560453127859950U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3039196878830506712U;
            aOrbiterE = RotL64((aOrbiterE * 3140508261330698717U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8850992055588337843U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4219373528176869146U;
            aOrbiterC = RotL64((aOrbiterC * 1310964742529956743U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1341474458715938799U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15937557372891732898U;
            aOrbiterJ = RotL64((aOrbiterJ * 11437307017920192915U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 7512741986101399499U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4304636545688233645U;
            aOrbiterB = RotL64((aOrbiterB * 1948671766238131953U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11460886069492094055U) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2019818350627642126U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9802784763505584769U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3190374588085859096U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8020711767807230555U;
            aOrbiterH = RotL64((aOrbiterH * 12055760672321414929U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 26U);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 22U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + aNonceWordC) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 23U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterH, 14U));
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aPrevious, 18U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 37U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 51U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterF, 46U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 44U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 52U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneD
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10997U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((aIndex + 9599U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8365U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14525U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12050U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 13476U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (aWandererF + RotL64(aCross, 18U)) + 12122689833405846292U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 11U)) + 9640400270962766788U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 27U)) + 9141937998266739071U) + aNonceWordF;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 13U)) + 12899395770434090537U) + aNonceWordI;
            aOrbiterF = (aWandererI + RotL64(aCross, 3U)) + 13457918115408031842U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 15134784483576000943U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 12540961268790055438U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 20U)) + 6306886773092764230U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 35U)) + 13573343491337243121U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 8545588657348974413U) + aNonceWordG;
            aOrbiterB = (aWandererC + RotL64(aIngress, 57U)) + 10891410570357275120U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2877137119767060151U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9178097682386595144U;
            aOrbiterC = RotL64((aOrbiterC * 3524486002084427513U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 15528007881855616978U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11368419529245281435U;
            aOrbiterF = RotL64((aOrbiterF * 12433207037378339309U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5932738914934356645U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5551842263864055419U;
            aOrbiterJ = RotL64((aOrbiterJ * 16093776759971522681U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3824433359595690603U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 17184628855571662441U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 691208053136187317U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8724462245014132623U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7481349499528092352U;
            aOrbiterD = RotL64((aOrbiterD * 8212182934509617583U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6908362960248294718U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5354057969992655314U;
            aOrbiterB = RotL64((aOrbiterB * 16586084885820679343U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11138301629323903147U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14164180536320940750U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9099767681053390287U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 709942920176922902U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17128241237359414945U;
            aOrbiterA = RotL64((aOrbiterA * 14063385518459963529U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6760410778228957309U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15333948259759012363U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3685416414008280787U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6929136132517755104U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13833415487953533365U;
            aOrbiterE = RotL64((aOrbiterE * 14860437994758579635U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16143046377679975216U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12122689833405846292U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 227699085983424155U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 54U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + aNonceWordH);
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterE, 14U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterB, 53U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterG, 46U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterI, 51U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterD, 21U)) + aOrbiterA) + aNonceWordB) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterK, 39U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneD
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 16528U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 16903U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18753U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22865U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18961U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 19352U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 35U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererK + RotL64(aCross, 13U)) + 16160838483846078448U) + aNonceWordH;
            aOrbiterB = (aWandererB + RotL64(aScatter, 19U)) + 15404960896190227946U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 16904160594024977199U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 48U)) + RotL64(aCarry, 47U)) + 17790460246821031802U;
            aOrbiterK = (aWandererG + RotL64(aCross, 35U)) + 16395168254086971959U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 29U)) + 7484373204039901786U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 43U)) + 18026814691322913510U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 5U)) + 15244817793136966450U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 3U)) + 5795491730356335666U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 3163873518027801504U) + aNonceWordB;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 56U)) + 2690791759507349172U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17898067251167087906U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8028010015006604239U;
            aOrbiterG = RotL64((aOrbiterG * 5601629670521300241U), 37U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 7304739457289910555U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6476837815096530043U;
            aOrbiterE = RotL64((aOrbiterE * 16380545138701113267U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14242499233467960602U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17305645693017634630U;
            aOrbiterF = RotL64((aOrbiterF * 14442976693206929569U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9772864059444171908U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7897200728282156408U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 816306719390807411U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 4890999319172950996U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8165132649356094963U;
            aOrbiterH = RotL64((aOrbiterH * 17297706071263690189U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9342923520083533265U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7213639583505088067U;
            aOrbiterB = RotL64((aOrbiterB * 1349251979649428909U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 4079475132684197272U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3350998022472827283U;
            aOrbiterJ = RotL64((aOrbiterJ * 948841791460066265U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2479140576609216238U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7703147534931674972U;
            aOrbiterI = RotL64((aOrbiterI * 11419116495223970801U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9050277787914448469U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13295888852307317371U;
            aOrbiterA = RotL64((aOrbiterA * 3027097172772140975U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 15380254190549884741U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17653690414528791774U;
            aOrbiterK = RotL64((aOrbiterK * 15923958179714368315U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6825072759468337036U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16160838483846078448U;
            aOrbiterC = RotL64((aOrbiterC * 11690325563580492415U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 6U);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 44U) + RotL64(aOrbiterK, 23U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterC, 41U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 26U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 43U)) + aOrbiterK) + aNonceWordO);
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 35U)) + aOrbiterB) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterB, 50U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterD, 21U)) + aNonceWordA) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterE, 37U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 28U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 48U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneC
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31571U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((aIndex + 27233U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 29202U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26025U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31900U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 24712U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 23U)) + (RotL64(aCarry, 38U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 53U)) + 5173905450211892891U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 3555542451908039957U;
            aOrbiterC = (aWandererH + RotL64(aCross, 11U)) + 11559884700283861559U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 6U)) + 1352524329968738673U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 8914206450420616349U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 2251523378498463946U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 13U)) + 9541575923299247038U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 34U)) + 1239854507907214595U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 39U)) + 17698101462598498934U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 27U)) + 12305566971683256060U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 23U)) + 13804545036303215569U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10239749097704329264U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4212214906286320308U;
            aOrbiterC = RotL64((aOrbiterC * 3661436621615751071U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12192418916967430783U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 4475514289326450361U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 17497164630368757887U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17376102613298827459U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 18129393209955439341U;
            aOrbiterK = RotL64((aOrbiterK * 6404089025014118979U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4014763724300253568U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17325007199676828814U;
            aOrbiterE = RotL64((aOrbiterE * 1420888274815627083U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15480474849292388685U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 14357924730184375449U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 16723492259068034209U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4335731868597970070U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8296023680394303015U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 14027415401430120543U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2807312426993262800U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 15510369660839648501U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 18207954408298333959U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12597844696606519907U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7231012798553551535U;
            aOrbiterG = RotL64((aOrbiterG * 2841306785994479299U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 849663631945232360U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4002310581470781194U;
            aOrbiterH = RotL64((aOrbiterH * 2148877014350721479U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16067735571435654555U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4607980694199923842U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10401780756830017477U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5346879191913449715U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5173905450211892891U;
            aOrbiterJ = RotL64((aOrbiterJ * 15360571827429301833U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 50U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterC, 35U));
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 23U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterE, 57U));
            aWandererF = aWandererF + (((RotL64(aScatter, 56U) + aOrbiterI) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterE, 47U));
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterH, 20U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterG, 13U));
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 27U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 37U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 40U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 36U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9A488CB9F7F64CBDULL + 0xBEA3600FE60A2DA7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8BCB417DAB387C67ULL + 0x9B6780478D82FD3FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCE5BFEDBB4C5F879ULL + 0x800F40A644D60B59ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xACC02D1133FAA7A7ULL + 0xC21E44231281C7E4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE34EB52498AEA949ULL + 0xC05F722A3A6D62B0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF11F477EA8F5A7CFULL + 0xF4164AC6FE12E715ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEF153B37A4898109ULL + 0xE5FF4020EE2F5DDCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFCE9D3459C510D49ULL + 0xA834CC52B19BA2EDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBC26628204AE8D75ULL + 0xE4C769ADD55D13CFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDDC91C7FC2AC6FE9ULL + 0x8BC7ECF7F9D9D1ADULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAB8C1A257C67C3C5ULL + 0xD2579B0ED1C25E3CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF324EB9CA2142B1BULL + 0xF6D47A7B00E9E203ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFE74D6D5478A598FULL + 0xCFD46C34ABF02248ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA1E6510AA14C8197ULL + 0xC995F8C7A6613002ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEE3E546D1C8A746DULL + 0xF812F16E966303E2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x91ECA8D20F80B12DULL + 0xC184B91B0F8DEBADULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneC, aExpandLaneA, aWorkLaneB, aWorkLaneA, aExpandLaneB, aFireLaneD, aWorkLaneD, aExpandLaneC, aFireLaneA, aFireLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7601U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 6622U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 3007U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7840U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2679U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3157U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 18U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = ((aWandererE + RotL64(aScatter, 20U)) + 6068543441070417854U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 43U)) + 2995980468193441856U) + aNonceWordH;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 18020277482171594003U) + aNonceWordJ;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 4293807434721230702U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 13U)) + 7980599111583893156U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 53U)) + 8593141111851052016U) + aNonceWordN;
            aOrbiterA = (aWandererB + RotL64(aIngress, 58U)) + 5903487523900084325U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 15112035513447930209U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 47U)) + 9854037263057006439U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 16759760289688823193U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12622628933030601390U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 2151912984825538321U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1264668857268123425U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16302812053619101593U;
            aOrbiterH = RotL64((aOrbiterH * 18291400055836111547U), 37U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 16087995784896123610U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7970269262800468363U;
            aOrbiterI = RotL64((aOrbiterI * 14924752223305807461U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5331477046030959632U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16534913204255550893U;
            aOrbiterD = RotL64((aOrbiterD * 1013433634373673565U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11042821902537871209U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8069677512345031660U;
            aOrbiterA = RotL64((aOrbiterA * 13622218526054132397U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5737130058129936372U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1076627182956662997U;
            aOrbiterF = RotL64((aOrbiterF * 14342191224014199929U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13911061091801078190U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15397603151098990373U;
            aOrbiterC = RotL64((aOrbiterC * 1802890451633592245U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 15137326716738637972U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11248737008959896786U;
            aOrbiterE = RotL64((aOrbiterE * 90789374131547005U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1847847987633923657U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10560748778679145431U;
            aOrbiterB = RotL64((aOrbiterB * 2919333327817231099U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 20U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 18U) + aOrbiterE) + RotL64(aOrbiterH, 48U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 27U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 57U)) + aOrbiterH) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterD, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterB, 3U));
            aWandererB = aWandererB + (((((RotL64(aCross, 36U) + RotL64(aOrbiterI, 18U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aNonceWordL) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 37U)) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aWorkLaneB
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13643U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 9677U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15753U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8984U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13878U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8351U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 28U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (aWandererD + RotL64(aScatter, 40U)) + 18319689184146942855U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 8041304130090501019U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 53U)) + 11347064191990897738U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 13U)) + 15242243470024447468U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 10619749107163611105U) + aNonceWordP;
            aOrbiterE = (aWandererK + RotL64(aIngress, 29U)) + 14795614276221947128U;
            aOrbiterF = (aWandererG + RotL64(aCross, 35U)) + 1578095288886372393U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 13593906305770501684U) + aNonceWordE;
            aOrbiterD = ((aWandererA + RotL64(aCross, 60U)) + 8919815528334599172U) + aNonceWordD;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17425548324720065145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11125018338392347335U;
            aOrbiterH = RotL64((aOrbiterH * 4377887040461528587U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3779189180734244399U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10958224663276134041U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6206963519509783781U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4317305352561612995U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4891139433808505355U;
            aOrbiterF = RotL64((aOrbiterF * 11507024985663120317U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5166074784835930965U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10080890270621589202U;
            aOrbiterA = RotL64((aOrbiterA * 13170894418184288695U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4501071771615514619U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6486573807774431753U;
            aOrbiterE = RotL64((aOrbiterE * 324029625116648669U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15714881857668975753U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3506619392820235900U;
            aOrbiterI = RotL64((aOrbiterI * 5707033870161224499U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 5295711072762443783U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 11192836530396570648U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 4361810118382207039U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7993389678399774574U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12551394763541226695U;
            aOrbiterK = RotL64((aOrbiterK * 11903486656172026403U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 11553674370322129668U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4459881583199320245U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 2805857426321555685U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 26U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 36U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 5U) + RotL64(aOrbiterH, 27U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 23U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 18U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 39U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 35U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 43U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aCross, 18U) + aOrbiterG) + RotL64(aOrbiterI, 12U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneD
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneD
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 16427U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((aIndex + 22755U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 24448U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20091U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18851U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 22728U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 26U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 54U)) + RotL64(aCarry, 57U)) + 15549114274303128055U;
            aOrbiterG = (aWandererI + RotL64(aCross, 39U)) + 16466750056388063241U;
            aOrbiterF = ((((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 12209449840836787142U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 11U)) + 14551496099734294336U) + aNonceWordF;
            aOrbiterB = (aWandererB + RotL64(aIngress, 35U)) + 6266576428679808622U;
            aOrbiterC = (aWandererE + RotL64(aCross, 29U)) + 16892841575635668152U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 5U)) + 7375966221423362125U) + aNonceWordG;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 35U)) + 11926105302821753530U) + aNonceWordP;
            aOrbiterI = ((aWandererG + RotL64(aCross, 43U)) + 16219253791550461124U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7299056065319248160U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15234001484933728439U;
            aOrbiterF = RotL64((aOrbiterF * 8182244796017018911U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 6615802589932632120U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5481176858895819247U;
            aOrbiterG = RotL64((aOrbiterG * 3604590158551984877U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 17220507586542139380U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 14137921473739415340U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 10634645686035907603U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16981960446540932787U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10897565927079518588U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 418843936329303571U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2746889569299593263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4894117146736361379U;
            aOrbiterI = RotL64((aOrbiterI * 2656750612042673191U), 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 18294823016957137777U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 86828501068883383U;
            aOrbiterC = RotL64((aOrbiterC * 11432686669235402365U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6322053762209547826U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6754524552483363820U;
            aOrbiterE = RotL64((aOrbiterE * 1746163087826694641U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7306452650619361017U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12717201204443785828U;
            aOrbiterB = RotL64((aOrbiterB * 6121251603905574991U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10422327053543898585U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14786413282036348183U;
            aOrbiterH = RotL64((aOrbiterH * 8713024293107068275U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 53U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 14U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 13U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 20U) + aOrbiterH) + RotL64(aOrbiterG, 51U)) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 60U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 38U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + aNonceWordM);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterG, 46U)) + aNonceWordH);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28551U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((aIndex + 31882U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 31106U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29962U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32732U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 32614U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = (aWandererC + RotL64(aPrevious, 51U)) + 5568146815535263910U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 43U)) + 7736084960873834666U) + aNonceWordE;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 6U)) + RotL64(aCarry, 23U)) + 1336413621817562093U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 35U)) + 5218462026934984692U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 21U)) + 7048890985969555935U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 29U)) + 13415955213864702118U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 13U)) + 5657023257021528548U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 14338310943137497116U) + aNonceWordO;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 11U)) + 12305161641833950473U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 14514226578370459131U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12692904083266024340U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14800805065279908839U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11012959130001327964U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7106471380403489078U;
            aOrbiterF = RotL64((aOrbiterF * 515626559384817223U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3718101961355280891U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13364192077222322664U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 1411328915372590283U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6720867800318913440U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14497243926965866546U;
            aOrbiterI = RotL64((aOrbiterI * 13595058589060114653U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5789056168233262435U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14438482587495779937U;
            aOrbiterD = RotL64((aOrbiterD * 10593535547917767263U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 313917798940179945U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15241845511889502917U;
            aOrbiterB = RotL64((aOrbiterB * 16483477103771326107U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3591957424821693032U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1559050939014453558U;
            aOrbiterH = RotL64((aOrbiterH * 17933346117866604725U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15340590914441451383U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5538037287390050110U;
            aOrbiterK = RotL64((aOrbiterK * 4082576643144951473U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4151270491894969214U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 263593701314144898U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10372046955804512457U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 20U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 12U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 12U) + RotL64(aOrbiterE, 41U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + aNonceWordF);
            aWandererE = aWandererE + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 47U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterF, 60U)) + aOrbiterD) + aNonceWordC) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 24U) + RotL64(aOrbiterF, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD919AFAE577B6D8DULL + 0x808C2323A3233771ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDB0F3B0F3AF26B57ULL + 0x8CEF9B876DFD8701ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC1AD48AB3C749EF7ULL + 0xBD10280F712859A4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE32410321E49D95BULL + 0xDE9263DA84660069ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEE46884568B80153ULL + 0xDDE7A223AEE5E848ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA30C3B8382832A4FULL + 0xB3E90F2FE1CEF9BBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD93DE8AB985B22F5ULL + 0x8E09E6142D7D41ACULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB9CB1BBE64921977ULL + 0x8956CDC230E4362EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD54BAC7635037ACDULL + 0xB1F702202EBDCE28ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x95243A3D3FB77269ULL + 0x98583877F2017DEEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC7EB2641AEDEABF7ULL + 0xBD5DB6F443D45222ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB56BD1D9F144142FULL + 0xB0BF9AAAC25E8140ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9A8D1FF97F6C9C97ULL + 0xEF2A27926DA2A0D5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE3F1771C50792E0DULL + 0x8B4A56CD1DE21684ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE0383A7E09F03B6FULL + 0xB843C2E773027256ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD7CF731F058D29FBULL + 0xC1F07CEF2D109D2FULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aWorkLaneD, aOperationLaneD, aExpandLaneA, aOperationLaneA, aFireLaneB, aExpandLaneB, aFireLaneD, aOperationLaneB, aExpandLaneC, aFireLaneA, aOperationLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6040U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 3356U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 572U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 821U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7152U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 911U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererJ + RotL64(aCross, 60U)) + RotL64(aCarry, 11U)) + 9855743441035905047U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 47U)) + 8426286937143990276U) + aNonceWordO;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 5U)) + 7146752367170267002U) + aNonceWordI;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 21U)) + 12947210066678101726U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 15902163559925328965U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 8506649889346449469U) + aOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 35U)) + 8226286036430263052U) + aNonceWordB;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 2703047093452420216U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6769351326360139560U;
            aOrbiterF = RotL64((aOrbiterF * 5318104980014706265U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9857025533281333281U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 238297452132277585U;
            aOrbiterI = RotL64((aOrbiterI * 12974709749856065985U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7203572312072908931U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12497027346166575632U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 1703586436725662307U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 473851890609048879U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 1664484956453886047U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 8566500756326590209U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4635095143004754116U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17695676150967345793U;
            aOrbiterB = RotL64((aOrbiterB * 5780416541584439301U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 15628965269863402796U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 9190117464399730235U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 5586437438425999715U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17835918238346011086U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 4398005402429282682U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 14828737209913317463U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 53U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aCross, 22U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterE, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 5U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 44U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 19U)) + aNonceWordP);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterK, 37U)) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8348U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((aIndex + 13448U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 15781U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11309U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12927U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15660U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 26U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 43U)) + 6654158889644956636U) + aNonceWordP;
            aOrbiterG = (((aWandererG + RotL64(aCross, 51U)) + 9045779659363991870U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = ((((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 3888897662136993491U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aWandererI + RotL64(aIngress, 24U)) + 6882016842864459345U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 15601891715956172291U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 11U)) + 5176811598629335350U) + aNonceWordO;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 12519945150889074325U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4552583214397603278U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14225482701804864688U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8526052833180466359U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5485298070606280363U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11237713257388094289U;
            aOrbiterF = RotL64((aOrbiterF * 11032429223099413011U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14340345895626142788U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 16275167270553643347U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 7308578867128951199U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14041860597556520250U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1436068974197066343U;
            aOrbiterJ = RotL64((aOrbiterJ * 3938460345031496843U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 11483155566419547004U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4608508534724289325U;
            aOrbiterK = RotL64((aOrbiterK * 13461385011638899485U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2389196334288832895U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4062682330273866602U;
            aOrbiterB = RotL64((aOrbiterB * 8787682133271101901U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5655656046585592034U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7977947821249746880U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10082104644185964787U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 13U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterB, 20U));
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + aNonceWordJ) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19208U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((aIndex + 16898U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 21407U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22803U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19262U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 23263U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = (((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 9774364261626083532U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aScatter, 4U)) + RotL64(aCarry, 11U)) + 18059001521926116420U) + aNonceWordF;
            aOrbiterA = ((((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 10615626210406381148U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 21U)) + 10536484278007898620U) + aNonceWordB;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 47U)) + 13320663045139972700U) + aNonceWordC;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 29U)) + 17127001787268166583U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 37U)) + 16742574590844166551U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8347719720758228053U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13502468705946051986U;
            aOrbiterA = RotL64((aOrbiterA * 13822952083584784695U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3512687886188904904U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 495660316165795934U;
            aOrbiterG = RotL64((aOrbiterG * 6724596801190194913U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5092722552034477356U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15641128019608284015U;
            aOrbiterE = RotL64((aOrbiterE * 3621036395703527059U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15421873776811085458U) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17978775513204574125U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 18359600395119440183U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16617179197537669849U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1931805387534012528U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3400139345857733775U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9544923119559308431U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12930999400470173353U;
            aOrbiterJ = RotL64((aOrbiterJ * 16791006919271490005U), 57U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 13673733276226249890U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2032263473309124738U;
            aOrbiterD = RotL64((aOrbiterD * 3088728329261360607U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 18U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterG, 21U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 14U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 22U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29599U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 32711U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 29058U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25283U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31129U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 31749U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 12U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 57U)) + 13960289014350612206U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 28U)) + 3483331015269589730U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 6873299241002444518U) + aNonceWordM;
            aOrbiterI = (aWandererF + RotL64(aCross, 21U)) + 3562094007125534229U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 5U)) + 11422367439932782705U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 532453428514259816U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 17810941465810193088U) + aNonceWordN;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 11869759058631106331U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8837581071876177566U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 15329827515970522213U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17185378327053837778U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7578253375676981500U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13371647568758721729U), 27U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 17112646434432814442U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 14949096407295697881U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 14770977858283051753U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4259590620758467836U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6534899413644542303U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 7987609419215568661U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2637407498893694243U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15819295597921425711U;
            aOrbiterJ = RotL64((aOrbiterJ * 5202015597375051399U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6373559542002699718U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11694562937392022505U;
            aOrbiterB = RotL64((aOrbiterB * 9311557972331218597U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3308736483775453062U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12749929710650475901U;
            aOrbiterC = RotL64((aOrbiterC * 248428400724560945U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 36U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 41U)) + aNonceWordK);
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterI, 53U)) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 14U)) + aNonceWordO);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 37U));
            aWandererC = aWandererC + ((RotL64(aCross, 6U) + RotL64(aOrbiterA, 29U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterD, 5U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 21U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC6A77FB0CE8E64B9ULL + 0xD8B0AF3CB7A9C5D9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xED5BB8CF90FC5D21ULL + 0xF5325557710A3525ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE94DBEAA39C5CD5DULL + 0xD07CF97F36866CF1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCE94596CE998EA6BULL + 0xA7B003E8FB8DBC5CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCA85D47BC439EFD1ULL + 0xE47FE1B5CC0F837BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9A75C935933EFFE7ULL + 0xCEDE2A599401E0CDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA72F5DF31A1762E3ULL + 0x9AB4636C8B09F53FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA93EAB8F1B7D586DULL + 0xC38796DF6A6C4BA1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCB921601AA0ECD8BULL + 0xC323B93B7B71651EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAFC5FBE067978B25ULL + 0x9DEAFC9F5281B8E4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEADB5E19178F80BDULL + 0xAD67F46EACAB685FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAFAABC4F5400787FULL + 0xE428B4B5E9929989ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD20B3933F37B60EDULL + 0xD51A6E09D838E799ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC32BDCEA5882002FULL + 0xAB0DB8EC099D8525ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB8E435936406A113ULL + 0x9806D9B4008592DCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBF8D7321150D33BBULL + 0xA782BC2153E8ECE6ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1327U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1810U)) & W_KEY1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2565U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 2226U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 6U)) + (RotL64(aIngress, 35U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 16451272412693907816U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((((aWandererD + RotL64(aPrevious, 18U)) + RotL64(aCarry, 39U)) + 10099485419723255462U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aWandererF + RotL64(aScatter, 41U)) + 17668900099534923192U;
            aOrbiterC = (aWandererG + RotL64(aCross, 57U)) + 5497093724143181753U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 27U)) + 10354044773550071706U) + aNonceWordA;
            aOrbiterA = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 12728258851198019099U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 51U)) + 4144050505314242618U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14133805325480076530U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 308863673210602899U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2672613556981540433U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11741180130160569753U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12926863156769180448U;
            aOrbiterF = RotL64((aOrbiterF * 9726030996091054939U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 211920854786494259U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13234608842479411078U;
            aOrbiterA = RotL64((aOrbiterA * 2556747209733759467U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9164711974854618892U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6667377062281954219U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2603737166987437649U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4559040002406721850U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1749875480850675109U;
            aOrbiterG = RotL64((aOrbiterG * 15822640067349481089U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9555365165561936366U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 18289733999504213574U;
            aOrbiterJ = RotL64((aOrbiterJ * 14156217554673229429U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8727162691639622461U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 291406782452963706U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 8413500075082350243U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 22U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterI, 29U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 35U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 43U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterG, 51U)) + aNonceWordE) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 19U)) + aOrbiterA) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterI, 10U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererD, 28U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4370U)) & S_BLOCK1], 44U) ^ RotL64(aKeyRowReadA[((aIndex + 5141U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2846U)) & W_KEY1], 6U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3265U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = ((aWandererG + RotL64(aScatter, 21U)) + 13880995121909552664U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 14534942818069300546U;
            aOrbiterF = ((((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 17745973100886007133U) + aPhaseEOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 2249805580771946872U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 3U)) + 4460116116396439410U) + aNonceWordA;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 27U)) + 3378683994078106878U) + aNonceWordG;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 14U)) + 3992996501048809123U) + aNonceWordM;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 12057768808864451929U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4115362079047921130U;
            aOrbiterF = RotL64((aOrbiterF * 12263015903331031345U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15297384955502206698U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17623548383481905636U;
            aOrbiterK = RotL64((aOrbiterK * 7487278217901483685U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3559213898000162417U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12311605719074507335U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3982199462062847697U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14807313864347885885U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 11222085523291581822U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 12580941911587215653U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 916681229436292462U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2441350114032314686U;
            aOrbiterC = RotL64((aOrbiterC * 7336079498999018067U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7361470539894653271U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 12153585147213579808U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3040327545467672961U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13566300726101613579U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14875254144748509128U;
            aOrbiterA = RotL64((aOrbiterA * 13699179902908972403U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aCross, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordP) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + aNonceWordC) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 19U)) + aOrbiterA) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aCross, 12U) + RotL64(aOrbiterD, 37U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterD, 46U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 21U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6974U)) & S_BLOCK1], 20U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7779U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7307U)) & W_KEY1], 28U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6621U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6576U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 36U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 8604208734152026945U;
            aOrbiterG = (aWandererE + RotL64(aCross, 11U)) + 1374329953253889829U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 47U)) + 5779278910548228339U) + aNonceWordN;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 5U)) + 17670451230882805140U) + aNonceWordL;
            aOrbiterK = (((aWandererK + RotL64(aCross, 53U)) + 8193848740764866860U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 15801168428145650104U) + aNonceWordE;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 19U)) + 2584718176087499066U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14950366247822737997U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9779293225265670135U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11625969538497982117U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 8688968319288372383U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 13665723186950342601U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 292035540396910837U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9395428688359973510U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 2152719218018108418U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 15271961483518392671U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1350324137411377992U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8729317951386057921U;
            aOrbiterH = RotL64((aOrbiterH * 6008790836417785083U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6317310451893678411U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10175620379041384281U;
            aOrbiterK = RotL64((aOrbiterK * 14079679617394330781U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1203082119358827708U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 523869107818193101U;
            aOrbiterF = RotL64((aOrbiterF * 4629501113595689157U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4028324959540432983U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15447631947468213912U;
            aOrbiterD = RotL64((aOrbiterD * 6037306615787729185U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterF, 37U)) + aOrbiterB) + aNonceWordM) + aPhaseEWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 11U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 37U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 42U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterB, 53U)) + aNonceWordH) + aPhaseEWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterH, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9806U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 9749U)) & W_KEY1], 34U));
            aIngress ^= (RotL64(mSource[((aIndex + 10405U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9802U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9205U)) & W_KEY1], 34U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8288U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 23U)) + (RotL64(aIngress, 4U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (aWandererI + RotL64(aScatter, 47U)) + 14249093584376402677U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 8756965951816492264U;
            aOrbiterF = (aWandererF + RotL64(aCross, 41U)) + 11221139480258176330U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 11U)) + 17218894445564194851U) + aPhaseFOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = ((((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 8064642692524949490U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 5822093203710704646U) + aNonceWordE;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 54U)) + 3217799620158102238U) + aNonceWordN;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2613757677892120843U) + aNonceWordO;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 13647481499551657237U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 5517563514031899891U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3545714196663685016U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 9735422670576621521U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7276207208162697249U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3911046580637583767U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9315984027042049203U;
            aOrbiterH = RotL64((aOrbiterH * 12568550776487242469U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8926367674641729058U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11035347490524961446U;
            aOrbiterG = RotL64((aOrbiterG * 10948288997163592463U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10748158733051120339U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 2467801787989056455U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 12621934274702358977U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9244415080474351390U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8517784887959492079U;
            aOrbiterA = RotL64((aOrbiterA * 17022899813765884147U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8409307332803038455U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11043806021873232950U;
            aOrbiterE = RotL64((aOrbiterE * 8294888329708842989U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 6U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 47U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterG, 29U)) + aOrbiterK) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 23U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterC, 12U)) + aNonceWordP) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aCross, 29U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordD) + aPhaseFWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 22U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 13552U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 12332U)) & W_KEY1], 6U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11539U)) & W_KEY1], 35U) ^ RotL64(mSource[((aIndex + 13364U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13218U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12829U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10938U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCross, 56U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = (aWandererC + RotL64(aIngress, 29U)) + 9751314027302668907U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 12175450995523107056U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 17519694958730119552U) + aNonceWordA;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 9093525527925682263U) + aPhaseFOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aIngress, 37U)) + 3713831321786810138U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 21U)) + 10108355209191835040U) + aNonceWordF;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 14U)) + 12956307447311314768U) + aNonceWordJ;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1904298513945877359U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4658049993308574460U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 10482422152074338611U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9826333658248851902U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 12058666914724365134U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 964233873188373939U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 2516574707110528099U) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13335308331049750235U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5880227828760598587U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8230749255538495304U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 16536559486797811486U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 7097036838156464969U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12387639130570188998U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8459259798142872020U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8001346480955847013U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16083784052002800300U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 1957284290736468379U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5046501301740813065U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7349538179311335863U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16395170077006105258U;
            aOrbiterB = RotL64((aOrbiterB * 4230485452156662763U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterB, 51U));
            aWandererC = aWandererC + (((((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 57U)) + aNonceWordO) + aPhaseFWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 11U));
            aWandererF = aWandererF + ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 20U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14668U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 14538U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15264U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14646U)) & W_KEY1], 21U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14821U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15352U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14536U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (((aWandererG + RotL64(aCross, 10U)) + 9041099828460168106U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 29U)) + 12883711604096848454U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 17420968786226443079U) + aNonceWordJ;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 3448213891716125104U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 11866455977445336560U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 57U)) + 4119356835384495905U) + aNonceWordO;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 41U)) + 2186212599698637068U) + aNonceWordH;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6506144898969301620U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12556800923644051626U;
            aOrbiterG = RotL64((aOrbiterG * 15961043406612913121U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4075551535185182945U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17877694808492008749U;
            aOrbiterD = RotL64((aOrbiterD * 901315308379887473U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5553428900598223316U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 14362304852277160675U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 11415103199856419303U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9174200302876075831U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16110739511917638547U;
            aOrbiterK = RotL64((aOrbiterK * 7004356839428657949U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10189881974519849402U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2128076632642616677U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 8860453653433114929U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 18133523799074400083U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9916472958834153766U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 3454601168808001733U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10274457562795569227U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14134814273275356425U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15912501063665343159U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 34U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterK, 47U)) + aNonceWordP);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterC, 19U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aNonceWordI) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18485U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 18691U)) & W_KEY1], 50U));
            aIngress ^= (RotL64(mSource[((aIndex + 17702U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16973U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18067U)) & W_KEY1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17349U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18999U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 27U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 7632760812370906911U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 21U)) + 6007174525479723089U) + aNonceWordG;
            aOrbiterF = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 3362829642521821048U) + aNonceWordE;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 18009548556107978286U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aCross, 29U)) + 17880909432272697327U) + aNonceWordF;
            aOrbiterH = (aWandererE + RotL64(aScatter, 53U)) + 15961567935420752568U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 12U)) + 10136559064656837921U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 17622019364405410277U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 6927494824421416306U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2686290883767829973U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7125170407794874847U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12342273503071032250U;
            aOrbiterB = RotL64((aOrbiterB * 867417849555857179U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14997696377476124836U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14874498694181230698U;
            aOrbiterA = RotL64((aOrbiterA * 4026127545746010937U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 2549397729130885686U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4217995818662767955U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 5525525344485251063U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4706089044415442525U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17983900172670031015U;
            aOrbiterD = RotL64((aOrbiterD * 541552737180932879U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1904937798143929988U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10620877287033139483U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 16711012562024287213U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 15681091173163181525U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2655543246639000084U;
            aOrbiterH = RotL64((aOrbiterH * 16686375598149755947U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterC, 23U)) + aNonceWordI) + aPhaseGWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterE, 47U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterF, 41U)) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterE) + aNonceWordB);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aIngress, 10U) + RotL64(aOrbiterD, 60U)) + aOrbiterB) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20979U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((aIndex + 20028U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19652U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19745U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21823U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21256U)) & W_KEY1], 11U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20169U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20164U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 4U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = (aWandererI + RotL64(aScatter, 47U)) + 9774364261626083532U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 18059001521926116420U) + aNonceWordD;
            aOrbiterC = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 10615626210406381148U) + aNonceWordA;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 10536484278007898620U) + aNonceWordF;
            aOrbiterK = (aWandererK + RotL64(aIngress, 35U)) + 13320663045139972700U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 29U)) + 17127001787268166583U) + aPhaseGOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 12U)) + 16742574590844166551U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 8347719720758228053U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13502468705946051986U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13822952083584784695U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3512687886188904904U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 495660316165795934U;
            aOrbiterF = RotL64((aOrbiterF * 6724596801190194913U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5092722552034477356U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15641128019608284015U;
            aOrbiterI = RotL64((aOrbiterI * 3621036395703527059U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15421873776811085458U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 17978775513204574125U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18359600395119440183U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16617179197537669849U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1931805387534012528U;
            aOrbiterE = RotL64((aOrbiterE * 3400139345857733775U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9544923119559308431U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12930999400470173353U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 16791006919271490005U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 13673733276226249890U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2032263473309124738U;
            aOrbiterK = RotL64((aOrbiterK * 3088728329261360607U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 50U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 5U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterK, 52U));
            aWandererF = aWandererF + (((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterE) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23357U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 23751U)) & W_KEY1], 14U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23427U)) & W_KEY1], 41U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22672U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23520U)) & S_BLOCK1], 28U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21974U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23312U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23708U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 21U)) + (RotL64(aIngress, 51U) + RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = (aWandererD + RotL64(aScatter, 11U)) + 3970829908171131502U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 7040283759419531991U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 41U)) + 11856292169397052901U) + aNonceWordB;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 819598588791819022U) + aNonceWordP;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 50U)) + RotL64(aCarry, 39U)) + 2176451710970866848U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 57U)) + 6454704928613390494U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 27U)) + 11792122387218053841U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9254780213489752211U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16591812589999846482U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5425771603523423167U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1471246223935074832U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 1424843083106386453U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15020536982657410783U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1856469958050891629U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6331743690452052712U;
            aOrbiterK = RotL64((aOrbiterK * 15327924647897459645U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10351075711345476487U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9518585245330480185U;
            aOrbiterE = RotL64((aOrbiterE * 3792179827396760391U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17787514620244712033U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14182328067398162557U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 18107337388659070197U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12798088948801072444U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9563215159275202323U;
            aOrbiterH = RotL64((aOrbiterH * 7058145016617349141U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9904919772580498232U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16579777394992143043U;
            aOrbiterD = RotL64((aOrbiterD * 10516761340320196661U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 47U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterH, 6U)) + aNonceWordN) + aPhaseGWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 23U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterC, 41U)) + aPhaseGWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 35U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 53U)) + aOrbiterH) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25448U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 25180U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26821U)) & S_BLOCK1], 44U) ^ RotL64(aFireLaneB[((aIndex + 26243U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26704U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25018U)) & S_BLOCK1], 12U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26280U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25452U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererC + RotL64(aScatter, 23U)) + 252059974543142812U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 11690823093681457368U) + aPhaseHOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aCross, 13U)) + 13282189752890971123U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 57U)) + 9507416294305708435U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 5U)) + 14053038174390776539U) + aNonceWordP;
            aOrbiterC = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 14605253312318725009U) + aNonceWordK;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 50U)) + RotL64(aCarry, 37U)) + 18138286582677863671U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 8530091235978489988U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14381731677571170073U;
            aOrbiterE = RotL64((aOrbiterE * 11675896999665768253U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 13316413456378978456U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3910529530149320706U;
            aOrbiterC = RotL64((aOrbiterC * 16000139333493588429U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6302070286831566901U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12324134652758551396U;
            aOrbiterB = RotL64((aOrbiterB * 17136438281540250165U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4773478557638475048U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 4031153435446078944U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3876928995240982769U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3114794895962903899U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3552936509969106796U;
            aOrbiterH = RotL64((aOrbiterH * 16823186892738820299U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5828754613946145627U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17985241114076114558U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 1986669631395606833U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11319331046368072261U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 6104267020171882160U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12525117969211576177U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 27U)) + aOrbiterH) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterE) + aNonceWordO);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterG, 53U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 60U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 21U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterD, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28583U)) & S_BLOCK1], 42U) ^ RotL64(aFireLaneD[((aIndex + 29771U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28484U)) & W_KEY1], 53U) ^ RotL64(aFireLaneC[((aIndex + 27813U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28688U)) & W_KEY1], 58U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29487U)) & S_BLOCK1], 41U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27903U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29316U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 24U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 1708250618750199233U;
            aOrbiterI = (aWandererB + RotL64(aCross, 54U)) + 12009147777553691142U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 23U)) + 8393982703399156592U) + aNonceWordL;
            aOrbiterA = ((((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 3247327098356831221U) + aPhaseHOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aWandererF + RotL64(aCross, 47U)) + 3403590155376353737U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 29U)) + 18197244558104735044U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 3096253642040701606U) + aPhaseHOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 8012692688785412179U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17531946907545680745U;
            aOrbiterK = RotL64((aOrbiterK * 16510602981731506381U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 17687695944270225817U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16147773866007628769U;
            aOrbiterD = RotL64((aOrbiterD * 16926442582711557877U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18244641303026196497U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8839160526348897457U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14268021129087663397U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10599266240854068246U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 2056723540756216155U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 13311591601230386375U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4629354220460621284U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9505955649473204942U;
            aOrbiterI = RotL64((aOrbiterI * 17775391885312236187U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17078153810088721310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9470436761716263000U;
            aOrbiterH = RotL64((aOrbiterH * 5431855497250357229U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3305863413630104742U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14377172434239576161U;
            aOrbiterA = RotL64((aOrbiterA * 6880176890091033423U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 10U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 27U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterI, 11U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 23U)) + aOrbiterK) + aPhaseHWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 60U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31144U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30189U)) & W_KEY1], 22U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30282U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31656U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31204U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30606U)) & W_KEY1], 47U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 47U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 5171470532667965920U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 37U)) + 750549462358682403U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 5U)) + 3325689257577120525U) + aNonceWordD;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 18031575461559790826U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 30U)) + 13874739537012288677U) + aNonceWordH;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 13U)) + 4250029868785016865U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 8211158803112611161U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1083939790236786027U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3446525462376962464U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 13603702473750888213U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6973817815000417325U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15230876489676945543U;
            aOrbiterH = RotL64((aOrbiterH * 7737039082964537651U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 9359727659738755880U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8775170107816327654U;
            aOrbiterG = RotL64((aOrbiterG * 6910680458261008653U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11958941755525038545U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16966819714283167348U;
            aOrbiterC = RotL64((aOrbiterC * 16363457661846050749U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14556087985619763243U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17915047508377045221U;
            aOrbiterK = RotL64((aOrbiterK * 6727635453185130109U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 8578745677485367222U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7002181668717618866U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12329703532414955235U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3569939503066735457U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2956247934282522184U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9946650822131152531U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 54U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + aNonceWordC);
            aWandererH = aWandererH + ((((RotL64(aCross, 26U) + aOrbiterB) + RotL64(aOrbiterH, 58U)) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterC, 51U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 35U)) + aOrbiterH) + aNonceWordA) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 29U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF9165753AB23A437ULL + 0xC1AA32C7242F51D1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE8897924BCD5D751ULL + 0xCD0AF2050892B409ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD47C0DC93A811431ULL + 0xAF401EFFF9009885ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xED9B4CA85AC3665FULL + 0xAE72D3D98463506BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB8BC33F9AB78A519ULL + 0x8CCD28AFD6C0C1CCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA7C444B115DF1773ULL + 0xAF7B5DD41331EB9AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC41D56EE2B808263ULL + 0xDD4FCBA92B7A24C1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB9EB42F0D0EA0027ULL + 0xAF59078204FD769EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD84E8D3D677639FBULL + 0xC7F61470643E5D3EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCBB8824D9BED6F01ULL + 0xDB7202E8907153BEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBCA77B416B15F7E1ULL + 0xB15A25E89A2FB5D7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBF95C7571EFAD64BULL + 0xC703C79E765DCC06ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB4A5DC1128DCD8C5ULL + 0xF4A156E4CD0BA51FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8D70950B1574291DULL + 0xA097C424EBA41E23ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA65D8D617B280999ULL + 0xBEAC81A2F77F71EDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF5BA8178F96E9595ULL + 0xB622C48AB043ABBBULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2831U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 1703U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3084U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1000U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 4979U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 56U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = ((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 19U)) + 6342299552323486695U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 13U)) + 12692748514781367538U) + aPhaseAOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 39U)) + 8202639945493229155U) + aNonceWordO;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 4439975701793231639U) + aNonceWordI;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 16774235182859553759U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 8764155413335405667U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7167848811974967685U;
            aOrbiterC = RotL64((aOrbiterC * 1052856924757654735U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16768278912125334220U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9090838954826296201U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5459329624017272077U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7644075729758006298U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17326182797908071215U;
            aOrbiterG = RotL64((aOrbiterG * 2408330168749256075U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16158809721888137555U) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8029938783858263694U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 12628072435324195483U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8716553521415553404U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7012599977009208840U;
            aOrbiterK = RotL64((aOrbiterK * 8775355876188948851U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 46U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 23U)) + aOrbiterK) + aNonceWordL);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 37U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordH) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD) + aNonceWordE) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 28U) + aOrbiterG) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterD, 56U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererG, 54U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8856U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 10917U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7450U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10211U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 7984U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = (((aWandererE + RotL64(aScatter, 48U)) + RotL64(aCarry, 23U)) + 10812151398716051703U) + aNonceWordP;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 18202551453336003710U) + aNonceWordL;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 13U)) + 9434410809101973752U) + aPhaseAOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 12955829998028534045U) + aNonceWordO;
            aOrbiterK = (((aWandererH + RotL64(aCross, 21U)) + 12271740641929640181U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14009351527014534752U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4316296955679133450U;
            aOrbiterJ = RotL64((aOrbiterJ * 11582128345511775161U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16473324966997442872U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15735123324965019802U;
            aOrbiterK = RotL64((aOrbiterK * 5624078184997601019U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17656375090484080236U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16066325053456055298U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17912970706985130327U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12908968778503516903U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12761433987676836197U;
            aOrbiterF = RotL64((aOrbiterF * 1023329467480907925U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12737513138040664509U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14535795767570998392U;
            aOrbiterB = RotL64((aOrbiterB * 15560519667062222269U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + aNonceWordJ);
            aWandererD = aWandererD + (((((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 11U)) + aNonceWordN) + aPhaseAWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterB, 19U)) + aNonceWordF) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 38U) + RotL64(aOrbiterJ, 38U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12030U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 11817U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 16215U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14415U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12182U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 15465U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 51U)) ^ (RotL64(aCross, 19U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (((aWandererD + RotL64(aIngress, 20U)) + RotL64(aCarry, 51U)) + 8975885703279267062U) + aNonceWordP;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 35U)) + 8664844915562660637U) + aNonceWordI;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 12281774799736296726U) + aPhaseAOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 11U)) + 15347461352311329726U) + aPhaseAOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 12967500561828907834U) + aNonceWordK;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5002833859280402726U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11908257536954668983U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4384790916151202785U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 17017174811949227162U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16851323125613931180U;
            aOrbiterJ = RotL64((aOrbiterJ * 12446990992858763577U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13469326957728686706U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5228638551056105241U;
            aOrbiterH = RotL64((aOrbiterH * 13369947664646167255U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11945166198089308564U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16268645041872996022U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 5391448793718370911U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14781204627695095701U) + aNonceWordJ;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 5365325354838101092U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 8017284997946310807U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 6U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 48U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 29U)) + aNonceWordN);
            aWandererD = aWandererD + (((((RotL64(aIngress, 56U) + aOrbiterJ) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 3U)) + aNonceWordL) + aPhaseAWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ) + aNonceWordM) + aPhaseAWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17116U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneA[((aIndex + 18191U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 19345U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16819U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20056U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 17056U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 40U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 14U)) + 17081642665820489793U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 14468854040067229623U) + aNonceWordO;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 2249450222593057429U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 14964389079511378664U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 57U)) + 17003491054252360650U) + aPhaseAOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 12710882240582032588U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9887078182156755359U;
            aOrbiterH = RotL64((aOrbiterH * 8205865025853482573U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 7665284531810584704U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7304284015511876717U;
            aOrbiterJ = RotL64((aOrbiterJ * 6193179739025093929U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5517927023543751734U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 17704756310857362759U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15826832172923213591U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 11347400363019508578U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11696395232760991243U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9725231749679442003U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10875780291242873583U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7808740614343437672U;
            aOrbiterI = RotL64((aOrbiterI * 8889516201913716283U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 22U)) + aOrbiterH) + aNonceWordG) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI) + aNonceWordJ) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23622U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 25346U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25692U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23067U)) & S_BLOCK1], 52U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22272U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 26104U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 37U)) + (RotL64(aIngress, 6U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 47U)) + 7825479804710770560U) + aPhaseAOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 5U)) + 5298124167101358123U) + aNonceWordL;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 28U)) + RotL64(aCarry, 23U)) + 17774541024369233726U) + aNonceWordH;
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 7679371833537454082U) + aPhaseAOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aCross, 13U)) + 5385914900748772224U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 3879781930908486531U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 659110346638873236U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17439162088869824407U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10749021728538539749U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3631252455767429457U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 8552825360915119613U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 2271978810960685021U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5963558780692551176U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 4772055335210781149U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 974909966119198104U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9296998242911152296U;
            aOrbiterD = RotL64((aOrbiterD * 2613629915877957661U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2245318466901521959U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 13391076374843288568U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18094558036982107419U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 21U)) + aOrbiterD) + aPhaseAWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterC) + aNonceWordJ);
            aWandererD = aWandererD + (((((RotL64(aCross, 18U) + RotL64(aOrbiterB, 38U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordO) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + aNonceWordB);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28623U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 27614U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 31982U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27708U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32118U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 28057U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 13714409587461539863U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 14101156723903265839U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aWandererI + RotL64(aScatter, 11U)) + 7063754562895369001U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 12320578575245519386U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 46U)) + 11744826789631008424U) + aNonceWordJ;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8744816505096675597U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10405435520084528645U;
            aOrbiterF = RotL64((aOrbiterF * 13279521344071568023U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1463157688070683543U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12379603577919617703U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 14858901470015109311U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1343439118031348146U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16118850268070235540U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 11184386483735388257U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14116264435819277136U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5251698273012432109U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1495818611622063967U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14806408656041403829U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11569345414052398227U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9913158908301414861U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 28U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aIngress, 4U) + aOrbiterI) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 13U)) + aNonceWordP) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 3U)) + aOrbiterF) + aNonceWordN) + aPhaseAWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            aWandererG = aWandererG + ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterI, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFA3F5F1D6434B861ULL + 0xFC592C763D3DD085ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDBDEDC736D4E07C3ULL + 0xA7176F3E9536AFC1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA8415875F3930785ULL + 0xA31F6C02FBB5D13DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFA5DAC652A7251EFULL + 0x94D9DB9D8D632C33ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x821426D9A0DCA9E3ULL + 0xB6DE88253F6922F8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x814068972215DE9FULL + 0xE5246422DB558DABULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB6CE0DECC3611161ULL + 0x8A14E66273FCABAEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC97956CA4528001BULL + 0xA0C7983FC43C50AFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA862935A664B12F9ULL + 0xC374AC3D6467594BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF198A13F2EA313FDULL + 0xEC1A6B94B9FD08A3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAF00B261E20F025DULL + 0x953A7238EC3DA9AAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDDCC31FFA078C92BULL + 0x9FAE7868F657109BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF46A6FB3F7CE39F5ULL + 0x9704EB8532C54F75ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB98EA0E7A473DEF9ULL + 0xC5FE58BE3F15EDDDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEC72A70B4C9FD3AFULL + 0xAC72C30AD0A087ACULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD5212EE3B61E9DE3ULL + 0x87FBF11F2E78725BULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aExpandLaneD, aInvestLaneC, aFireLaneC, aExpandLaneC, aInvestLaneD, aFireLaneA, aWorkLaneA, aFireLaneD, aWorkLaneB, aExpandLaneA, aWorkLaneC, aExpandLaneB
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3308U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 724U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4827U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 711U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5149U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 670U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 48U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (aWandererK + RotL64(aPrevious, 11U)) + 13333509828310369865U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 27U)) + 7645352517103840797U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 5310766306660062655U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 60U)) + 5165635069832352932U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 43U)) + 15684141764734281849U) + aPhaseBOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 21U)) + 3327963374225061738U) + aPhaseBOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 35U)) + 8625811794878848871U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 7598657468430485291U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 54U)) + 2881171216276746485U) + aNonceWordA;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10237691227222918101U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6419254255884834497U;
            aOrbiterF = RotL64((aOrbiterF * 3816625473642865305U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4238455444646479956U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14936613353493061492U;
            aOrbiterH = RotL64((aOrbiterH * 3544216916806292273U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15324699725208372627U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9506640480601832011U;
            aOrbiterA = RotL64((aOrbiterA * 12819564111348390227U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3709149613660215641U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1724290199312754307U;
            aOrbiterE = RotL64((aOrbiterE * 12597580418257897965U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13191172833570139194U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3686087945377837886U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 10883609557429936283U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10418330386245397022U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5383531313632347245U;
            aOrbiterI = RotL64((aOrbiterI * 2987755379396160073U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 7414716553072652212U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11301761123966206201U;
            aOrbiterB = RotL64((aOrbiterB * 1546727321088592187U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8570229732236388847U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8773754460060264773U;
            aOrbiterG = RotL64((aOrbiterG * 3251360788932563495U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13636929800504199371U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5486599841558573720U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2867914211589815153U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 24U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + aNonceWordF);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterF, 48U)) + RotL64(aCarry, 27U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 3U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aScatter, 40U) + aOrbiterC) + RotL64(aOrbiterA, 43U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 57U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 37U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterI, 26U)) + aNonceWordE);
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 21U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterH, 53U)) + aOrbiterE) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8128U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 6389U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7531U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9741U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10869U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8443U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9184U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 44U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 43U)) + 5576732410244514238U) + aNonceWordF;
            aOrbiterG = (aWandererG + RotL64(aIngress, 14U)) + 2833808925935929629U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 3U)) + 3670188682914544792U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 29U)) + 15759072378887814995U) + aNonceWordA;
            aOrbiterC = ((((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 13934007231137439994U) + aPhaseBOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererA + RotL64(aCross, 24U)) + RotL64(aCarry, 39U)) + 11022225696007690512U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 57U)) + 16989177104453635790U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 9256930045263527091U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 37U)) + 17788596104417068290U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17044369456673337625U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1310908395523250343U;
            aOrbiterJ = RotL64((aOrbiterJ * 16305084373037705921U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12067065689034065422U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15130844248737512262U;
            aOrbiterC = RotL64((aOrbiterC * 9409499577465934107U), 53U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 14532689204495587494U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8198147292120244178U;
            aOrbiterA = RotL64((aOrbiterA * 1418356389507740991U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5485494458627163347U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10830008207150307611U;
            aOrbiterB = RotL64((aOrbiterB * 6526039534042499457U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 17770065502486618029U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6397859353395335459U;
            aOrbiterG = RotL64((aOrbiterG * 14286997752368893825U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5128700697381508319U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7103394110057060499U;
            aOrbiterF = RotL64((aOrbiterF * 5053680689949149633U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16024401282261796979U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 12818445221897253410U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11450004517784155405U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13386978409145916350U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16740821954556699503U;
            aOrbiterK = RotL64((aOrbiterK * 5376430209628515105U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 313978038530994953U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1355733685461795345U;
            aOrbiterH = RotL64((aOrbiterH * 15955927322082619735U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 12U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 30U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + aPhaseBWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterD, 19U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 43U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 56U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 4U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + aNonceWordI);
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + aNonceWordD) + aPhaseBWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererB, 56U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aFireLaneA
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 11995U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 11704U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14357U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13273U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12930U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = (aWandererH + RotL64(aScatter, 35U)) + 3650233661228036955U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 22U)) + RotL64(aCarry, 3U)) + 11607036400067735729U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 3899614406903883035U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 43U)) + 8159156925629965143U) + aNonceWordD;
            aOrbiterG = (aWandererC + RotL64(aScatter, 3U)) + 7148903913967261270U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 9161665622287517848U) + aPhaseBOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 14U)) + 2981535013474059469U) + aNonceWordA;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 47U)) + 15812469008200319549U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aWandererB + RotL64(aCross, 29U)) + 14687469489893270300U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6025209349511417063U) + aNonceWordP;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 12964750392311112676U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 12955480283032701843U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6572355895765394340U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3542300121890027981U;
            aOrbiterA = RotL64((aOrbiterA * 11201491178181273935U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6477175684045398359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1081388388827929314U;
            aOrbiterE = RotL64((aOrbiterE * 8752188637514143529U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13754328481584620771U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3684673342659575917U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6139923312873039143U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6542045150319909445U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5352102692424060388U;
            aOrbiterJ = RotL64((aOrbiterJ * 7385758355501860261U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9110100774657340354U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2813273684436269057U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 10468759062594022273U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5860425751137403755U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1598622981888978548U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 651816500461718345U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 14710305692377606725U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16280545617802383463U;
            aOrbiterC = RotL64((aOrbiterC * 12541767206978802063U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6849565243667718750U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12152381961996750050U;
            aOrbiterD = RotL64((aOrbiterD * 11185935780063403807U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 23U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 10U) + aOrbiterC) + RotL64(aOrbiterG, 6U)) + aPhaseBWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 51U)) + aOrbiterA) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + aPhaseBWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterA, 60U)) + aNonceWordJ);
            aWandererB = aWandererB + ((((RotL64(aScatter, 14U) + RotL64(aOrbiterD, 27U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 14U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18335U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneC[((aIndex + 18292U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 21692U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21448U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17350U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 13U)) ^ (RotL64(aCarry, 60U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 1297415699043177788U) + aPhaseBOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 23U)) + 17583786534509260153U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 643197858925708798U) + aNonceWordP;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 58U)) + RotL64(aCarry, 51U)) + 5062653766915694874U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 19U)) + 7034273638367180511U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 5U)) + 2026909726972916996U) + aNonceWordM;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 41U)) + 2785690475553211646U) + aPhaseBOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aCross, 48U)) + 2910341716302991892U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 29U)) + 2834181605200829791U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13323052600571281928U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10434901530315760460U;
            aOrbiterJ = RotL64((aOrbiterJ * 2042210188346767033U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 247903955625194782U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5196515747387257163U;
            aOrbiterG = RotL64((aOrbiterG * 1799024689023272275U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7196305682377987476U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14777739876892587484U;
            aOrbiterI = RotL64((aOrbiterI * 95220583948241581U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10609060796540136671U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8386027207212484155U;
            aOrbiterA = RotL64((aOrbiterA * 4855610536246556893U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 729659744301903424U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2350564261412606157U;
            aOrbiterK = RotL64((aOrbiterK * 16713856782349084977U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16611987556673864177U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1525195188708550503U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10045858602151004553U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 4654808490980989596U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8189569777087686263U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17278657566389299577U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10932857495004451792U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1833880112534916813U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8004341577533825681U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13100236350175516423U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2773759534195186313U;
            aOrbiterF = RotL64((aOrbiterF * 3194954066097323161U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 42U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 52U) + aOrbiterJ) + RotL64(aOrbiterK, 56U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + aNonceWordF);
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 37U)) + aOrbiterI) + aNonceWordG);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 23U)) + aOrbiterF) + aNonceWordC) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 28U) + aOrbiterA) + RotL64(aOrbiterK, 41U)) + aNonceWordK);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterB, 47U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23404U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneD[((aIndex + 22333U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25666U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22653U)) & S_BLOCK1], 18U) ^ RotL64(aInvestLaneC[((aIndex + 23093U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 6U)) + 13650869943246163567U) + aNonceWordC;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 47U)) + 3435284932011770999U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 21U)) + 12388155658186776579U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 2374345913955712039U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 6095094526980292156U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 57U)) + 4965147025852444174U) + aPhaseBOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 42U)) + 3261881216269075298U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 53U)) + 4939780217097329222U) + aNonceWordH;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 3019862009792676287U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 901910626217143974U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3647055146712366383U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1792602402476450009U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7731765438957392967U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13409819457393479741U;
            aOrbiterA = RotL64((aOrbiterA * 3345078200262410715U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5415832109107794258U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8876738832313114471U;
            aOrbiterD = RotL64((aOrbiterD * 1304277600444504135U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17135570542519390359U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2373193062766802082U;
            aOrbiterK = RotL64((aOrbiterK * 4213691513185791519U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16318403285501718552U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8456043288604687045U;
            aOrbiterI = RotL64((aOrbiterI * 10556964529144571683U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10572534930284516528U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14616251186735204677U;
            aOrbiterF = RotL64((aOrbiterF * 2048651204265459805U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2837006243817205610U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5315917323622194254U;
            aOrbiterJ = RotL64((aOrbiterJ * 4080522050089666599U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12084676282761185907U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7922080344175593788U;
            aOrbiterH = RotL64((aOrbiterH * 7603522302708937379U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 17620847289789547792U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12140386059533463650U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1443266480620969535U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 30U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 53U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterG, 22U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 43U)) + aNonceWordD);
            aWandererD = aWandererD + ((RotL64(aCross, 42U) + RotL64(aOrbiterG, 29U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 37U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + aNonceWordO);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterD, 48U)) + aPhaseBWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 14U) + aOrbiterK) + RotL64(aOrbiterA, 57U)) + aPhaseBWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30517U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 29120U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 32102U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31515U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 31052U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 50U) ^ RotL64(aIngress, 19U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 43U)) + 12426357877879529292U) + aNonceWordL;
            aOrbiterG = (aWandererD + RotL64(aIngress, 29U)) + 12604900366173639176U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 10U)) + RotL64(aCarry, 23U)) + 13511119007338929401U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 9878720081166788060U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 39U)) + 15463195409806395076U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererC + RotL64(aCross, 3U)) + 6407922778852833423U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 56U)) + RotL64(aCarry, 3U)) + 7690427254160734016U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 51U)) + 18030974031722143619U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 21U)) + 17983938038322737041U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16605512170117753884U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 681802273302348322U;
            aOrbiterH = RotL64((aOrbiterH * 14608920184802647123U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15550312921312083819U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17824154101711884508U;
            aOrbiterF = RotL64((aOrbiterF * 7358612830654795357U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1939207786756735430U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3132864634777826569U;
            aOrbiterB = RotL64((aOrbiterB * 13606281919426730325U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12822929773923954849U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16576106045887115660U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 16370914370769903051U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2398825881649235260U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13700821892926092479U;
            aOrbiterK = RotL64((aOrbiterK * 10830623703416956043U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2439833784883391606U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15870638514107637833U;
            aOrbiterC = RotL64((aOrbiterC * 3797380922767479287U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9165457123134229670U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8736642509192659417U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16219277537523484065U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9232719746484835693U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7826680628853322541U;
            aOrbiterG = RotL64((aOrbiterG * 12578050118133526187U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14323652326982518782U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2254524512851399313U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 4119339547645451149U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 38U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterK, 57U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 43U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterB, 18U));
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 11U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterC, 5U)) + aPhaseBWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 24U) + RotL64(aOrbiterD, 35U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aNonceWordJ);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterB, 24U)) + aNonceWordE) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 53U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 18U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB6F0043DEDCBD173ULL + 0xD297973D4883F8BAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB93EA9F8BC318B3DULL + 0x896E68A048CC9AD3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDCDC413A416C9133ULL + 0xC404155541BDCE07ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB87BDE13F5F4AD51ULL + 0x9AD89609EBA9B717ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC18B1D185B94C3BDULL + 0xB7090084AE03343BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x816E0B8CC225B9DBULL + 0xAB30B6332F77081EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA7F9A9645C54E655ULL + 0xFC64575D1607E94BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8D263A1DD5FF6E15ULL + 0xE77AC5AB904EC6FAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC8148AB41B1DD5CBULL + 0xD6F2590517602EDCULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xABB4A50A59133DADULL + 0xA3727E227924E0FDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE5F1B5FB6D3E5597ULL + 0xB08AC9997C77DBBCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xADE42222B986E687ULL + 0xDE11000C4448B0A5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC797059CA22AF18BULL + 0xF64C926BB7A5C063ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB13CBF357369880FULL + 0xFFB2178E55180E55ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC60D651604C0A59DULL + 0xC18CCF1B3FFD6F0EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB0CBFC0D9E9AAA19ULL + 0xFC3B45207046338DULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4783U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 3146U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 73U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2744U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1918U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 1416U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 22U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 3U)) + 3550722402315312207U) + aPhaseDOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 57U)) + 16724184551669522754U) + aNonceWordN;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 981751330116773021U) + aPhaseDOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 41U)) + 7891159229704944868U) + aNonceWordH;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 30U)) + RotL64(aCarry, 29U)) + 13618396711464799841U) + aNonceWordG;
            aOrbiterD = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 5969291018449003648U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 19U)) + 14595540413313640042U) + aNonceWordJ;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3287990436916111762U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12534369400200483704U;
            aOrbiterK = RotL64((aOrbiterK * 2345945228434740707U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 2277312067930392274U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10026320559261334353U;
            aOrbiterG = RotL64((aOrbiterG * 11020464940995912637U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11258082063135659551U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 1445958517675746990U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 10062265337488757971U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1011298251290970844U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6487834862470043744U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15477913837027179675U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9966279022928268335U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10285993486057704393U;
            aOrbiterA = RotL64((aOrbiterA * 15965714363201157535U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 16005362468813966136U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 223843444699390781U;
            aOrbiterF = RotL64((aOrbiterF * 665392038954573081U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18178876294968532775U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12490136112181806806U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 16380841616662993709U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aCross, 38U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 23U)) + aNonceWordF) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 27U)) + aOrbiterA) + aNonceWordP);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterF, 54U)) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterD) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6671U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 9553U)) & S_BLOCK1], 48U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10733U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((aIndex + 8895U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8338U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5551U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 9767U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 19U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 2783898056762489197U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 30U)) + 7177192902873343053U) + aPhaseDOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 12254703232691980774U) + aPhaseDOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 37U)) + 15446547245691219559U) + aNonceWordD;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 888475203006174856U) + aNonceWordP;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 43U)) + 3649183529366307877U) + aNonceWordN;
            aOrbiterD = (aWandererF + RotL64(aIngress, 21U)) + 4642631047518805167U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 6108329730724782250U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8334054653023816636U;
            aOrbiterF = RotL64((aOrbiterF * 9352516059501924393U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5891895375031474350U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3176720746238477862U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1869961473768307911U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6111038696865301675U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11914998302228682704U;
            aOrbiterJ = RotL64((aOrbiterJ * 11738924766359642853U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 17005063057791320948U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 18333780598768130670U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5416759844884107303U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2056115016443263153U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10245512728872962677U;
            aOrbiterA = RotL64((aOrbiterA * 707106795383284903U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4810366069422162351U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3051442983125942469U;
            aOrbiterK = RotL64((aOrbiterK * 13558537578054436423U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9285068547223654308U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13067251130180968842U;
            aOrbiterH = RotL64((aOrbiterH * 7000687697769766605U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 42U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 4U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + aNonceWordO);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterI, 5U)) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterI, 18U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 11U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aNonceWordF) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 29U)) + aNonceWordH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15192U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 12675U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13717U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 15087U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 15601U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 35U)) + (RotL64(aIngress, 47U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererH + RotL64(aIngress, 13U)) + 9446153639709651566U) + aNonceWordD;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 34U)) + RotL64(aCarry, 41U)) + 10550762260670758167U) + aNonceWordM;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 7062634922142578383U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 9178499097812764515U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 47U)) + 6887103379773525538U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 41U)) + 6239750312052010257U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 23U)) + 17645022614523287959U) + aPhaseDOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3639618183259408272U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3131737117548745095U;
            aOrbiterK = RotL64((aOrbiterK * 6585057380704940395U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7253994382396406554U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15217993711938379561U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17853313384747259923U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12594152227603630033U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11250170200489647869U;
            aOrbiterE = RotL64((aOrbiterE * 546800378327864723U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12936942656624279424U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10990736056052106149U;
            aOrbiterI = RotL64((aOrbiterI * 7123916809953459187U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12787293075893090465U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 17154990205620778151U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10031369940028159521U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 1270827262969060301U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17337623431665013136U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1517262088236356107U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 830330490987911853U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6828309232554560547U;
            aOrbiterA = RotL64((aOrbiterA * 9742464176986145819U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterH, 29U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK) + aPhaseDWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 60U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterC) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 20620U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneA[((aIndex + 19397U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17118U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18087U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21348U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCarry, 53U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 21U)) + 17225673071833726819U) + aPhaseDOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aCross, 42U)) + RotL64(aCarry, 39U)) + 10301458382103627331U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 3960233050857362414U) + aNonceWordF;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 35U)) + 17768665685046605837U) + aNonceWordE;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 53U)) + 14471018461213959767U) + aNonceWordP;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 10730597892721340453U) + aNonceWordM;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 27U)) + 14863394003122760542U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9948587274816688296U) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 3573569431435100993U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 2303922230056523077U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8153670675740450590U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16438856577722561424U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4689247488336908827U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15765587867581925041U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1082039522061775213U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17023740047246402641U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4202521649260798876U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15877659681260461141U;
            aOrbiterI = RotL64((aOrbiterI * 11369910758551088173U), 21U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 2551560426129646123U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3005102326163906320U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4241583192662435107U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1675501058857208089U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12774812270956702043U;
            aOrbiterH = RotL64((aOrbiterH * 5488437008504905105U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1044886020922563597U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4857445127457225171U;
            aOrbiterE = RotL64((aOrbiterE * 13223560654459705259U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterF, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 13U));
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 19U)) + aOrbiterE) + aNonceWordK);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + aNonceWordN) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 43U)) + aOrbiterH) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 28U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterB, 37U)) + aOrbiterK) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24407U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneB[((aIndex + 22058U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24809U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22423U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 22198U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 57U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = (aWandererK + RotL64(aIngress, 60U)) + 17454559218352016650U;
            aOrbiterE = ((((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 8005709669325164803U) + aPhaseDOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 13393741948412816357U) + aPhaseDOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 3665865624348875553U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 29U)) + 8334142570031883436U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 37U)) + 17226066128706139657U) + aNonceWordF;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 43U)) + 3319093033121522613U) + aNonceWordM;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6657535603401588798U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5469746182326331147U;
            aOrbiterG = RotL64((aOrbiterG * 11315450342347794329U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17846791786050221418U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15939541003714896288U;
            aOrbiterF = RotL64((aOrbiterF * 1400351482213119809U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12076763190461077406U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3594038213596405284U;
            aOrbiterA = RotL64((aOrbiterA * 10244002692575821495U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8301291631324464622U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8460406137668390582U;
            aOrbiterJ = RotL64((aOrbiterJ * 9117147929757711595U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 7612394867020871200U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8525076134853103975U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5790440201072204659U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 11929899088215090379U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 7119509166360685726U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 1662341427992528823U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5081078459225240607U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17149991983909906705U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 950223374568067343U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 20U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK) + aPhaseDWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 21U)) + aNonceWordE);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterG, 36U)) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 43U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 32324U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((aIndex + 28269U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27557U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29007U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27754U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 43U)) + 16160838483846078448U) + aNonceWordE;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 21U)) + 15404960896190227946U) + aPhaseDOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aIngress, 3U)) + 16904160594024977199U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 53U)) + 17790460246821031802U) + aNonceWordF;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 16395168254086971959U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 35U)) + 7484373204039901786U) + aNonceWordN;
            aOrbiterI = (((aWandererF + RotL64(aCross, 29U)) + 18026814691322913510U) + aPhaseDOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15244817793136966450U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 5795491730356335666U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 13253529465289332171U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3163873518027801504U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2690791759507349172U;
            aOrbiterC = RotL64((aOrbiterC * 16677948635136515083U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17898067251167087906U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8028010015006604239U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5601629670521300241U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7304739457289910555U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6476837815096530043U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 16380545138701113267U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14242499233467960602U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 17305645693017634630U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14442976693206929569U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9772864059444171908U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7897200728282156408U;
            aOrbiterI = RotL64((aOrbiterI * 816306719390807411U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4890999319172950996U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8165132649356094963U;
            aOrbiterG = RotL64((aOrbiterG * 17297706071263690189U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterG, 51U));
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterH, 57U)) + aPhaseDWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterF) + aPhaseDWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterI, 42U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 23U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aIngress, 4U) + aOrbiterA) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 13U)) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDD6F6943695F82EFULL + 0xBC8EC137E0F37177ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA84E52DB3AAC3F19ULL + 0xA6501D81DC22F5E5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8D102B9709842C15ULL + 0xBAAD0E611EEBF011ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA2087BECEF78E2ADULL + 0xFB419F5B1B039E9EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA900E5D3396D9BA9ULL + 0xEA63EAD0C6122297ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD677D68504ED48C7ULL + 0x89411D30CE417606ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFEF50D41EE89085FULL + 0xC5930223B6E96B7BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB458B2EA32E436D3ULL + 0xC5999DB68589080EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x955B331E90E7B145ULL + 0xEE2DD4F9C02B2F87ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x84ED40A7E32D0A2DULL + 0x91E1FA0F8A8721B2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEEAE356282C427E3ULL + 0xA9C5FBAA99006F12ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF9E09778C9A9F6B7ULL + 0xE2054B0BD0DCB09FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF2BD2F9504F33591ULL + 0xD2F37C184D09881AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9FADDF524231878FULL + 0xA513B24D248DD249ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x866C4A7E7F4F86E9ULL + 0xDBDC72849DCCF436ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC43A547D76B53BA5ULL + 0x801BD129635C902FULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 456U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneB[((aIndex + 3738U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 725U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 355U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2875U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3396U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 35U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 51U)) + 7651355040951791298U) + aNonceWordJ;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 14U)) + RotL64(aCarry, 29U)) + 13988210277931659312U) + aPhaseEOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 23U)) + 9846849412579537783U;
            aOrbiterC = (aWandererK + RotL64(aCross, 5U)) + 12746719939495876158U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 3U)) + 11498066185182895284U) + aNonceWordL;
            aOrbiterE = (aWandererB + RotL64(aIngress, 39U)) + 11101058955193080232U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 15513734459555672046U) + aPhaseEOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 15711108675349394643U) + aNonceWordM;
            aOrbiterH = (aWandererI + RotL64(aScatter, 29U)) + 4771231759949468556U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 41U)) + 11449258010811305256U) + aNonceWordC;
            aOrbiterD = (aWandererG + RotL64(aIngress, 56U)) + 17036938391509986723U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6999245666776654250U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2106819066263369528U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13005885810757743129U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12716183358903477216U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16752724547046059889U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 11475905692393034141U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17623077680983093163U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6726003022297274986U;
            aOrbiterB = RotL64((aOrbiterB * 14709385877103232653U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2842410225096524740U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 9235178377537910514U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11813751114775673845U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2619888019860844610U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6295481948199619613U;
            aOrbiterA = RotL64((aOrbiterA * 15429161806953951205U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9724921158061115570U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4070976180958458679U;
            aOrbiterH = RotL64((aOrbiterH * 6080566609081811453U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5864247978960125554U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 7771249710071026757U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 4787660062590737657U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15006900854988166845U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2755659268987119046U;
            aOrbiterD = RotL64((aOrbiterD * 8043939381186802359U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1922321482806966418U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13910818219761929659U;
            aOrbiterC = RotL64((aOrbiterC * 8895973123729951173U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7540972911473176026U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5419023469522423893U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1380429266266313945U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2349651834739320824U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 7651355040951791298U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3713776056028698433U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 37U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 13U)) + aOrbiterB) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 19U)) + aOrbiterA) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 53U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterE, 30U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 39U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 37U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterA, 35U));
            aWandererA = aWandererA + (((RotL64(aCross, 60U) + RotL64(aOrbiterH, 60U)) + aOrbiterJ) + aNonceWordB);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 10289U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((aIndex + 9973U)) & S_BLOCK1], 30U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 6639U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8728U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5999U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10628U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8603U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 60U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 11U)) + 4751694786009671052U) + aPhaseEOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 16362725160370844224U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 41U)) + 6360885380915941057U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 47U)) + 5154536007972297036U) + aPhaseEOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aWandererC + RotL64(aIngress, 21U)) + 9362540581874808253U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 60U)) + RotL64(aCarry, 53U)) + 13902493871525612934U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 23U)) + 10208452885367546542U) + aNonceWordN;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 3117030377279160998U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 57U)) + 17286247690414027870U) + aNonceWordK;
            aOrbiterF = (aWandererI + RotL64(aCross, 52U)) + 3930314320040949141U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 5U)) + 7289525252391668404U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3434167955466809185U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17852573095128575663U;
            aOrbiterC = RotL64((aOrbiterC * 1485660158767033425U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6137259687928853253U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13992510605237574698U;
            aOrbiterB = RotL64((aOrbiterB * 15346263295995333395U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6470556523400123474U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4333255670390099293U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 11089933812030082647U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7700424876430257995U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16920736951239453071U;
            aOrbiterA = RotL64((aOrbiterA * 8920407493132380497U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 1635071690430295730U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9966700845966398620U;
            aOrbiterD = RotL64((aOrbiterD * 17210048121896546867U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 9833458070123027075U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1990346556486746432U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 8704943923474148699U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13339523466436517327U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5018264760406215603U;
            aOrbiterK = RotL64((aOrbiterK * 2769197961801783627U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 123427497520755346U) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 4535841104215792886U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 1417676310539177131U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3525925567359163763U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3273741481392187986U;
            aOrbiterG = RotL64((aOrbiterG * 16116160744647235811U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6230742908784102407U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 7578784912496239362U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2614448818452560369U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14669810330213234082U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4751694786009671052U;
            aOrbiterF = RotL64((aOrbiterF * 9583151676882991817U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 50U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 10U) + aOrbiterD) + RotL64(aOrbiterG, 46U)) + aPhaseEWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterE, 13U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 21U)) + aOrbiterF) + aNonceWordI);
            aWandererD = aWandererD + ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterH, 27U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 11U)) + aOrbiterD) + aNonceWordE);
            aWandererE = aWandererE + ((RotL64(aIngress, 38U) + RotL64(aOrbiterD, 41U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterC, 53U)) + aNonceWordD);
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 38U)) + RotL64(aCarry, 27U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 14378U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 12038U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 12073U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10943U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15947U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 43U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 1457104756581596530U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 35U)) + 6127240317844622874U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 60U)) + 16492290056044189421U;
            aOrbiterC = (aWandererH + RotL64(aCross, 13U)) + 10963676850938416468U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 41U)) + 4872917367399752405U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 5U)) + 15218882377875616148U;
            aOrbiterH = (aWandererD + RotL64(aCross, 47U)) + 5934166612122118251U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 21U)) + 14215280930872003003U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 38U)) + 11428034799044600979U) + aNonceWordD;
            aOrbiterB = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 5453003654321728726U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 14273775120265649389U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 328723770018440271U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13032190719588211088U;
            aOrbiterA = RotL64((aOrbiterA * 13363368478932798315U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2386881543033598494U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1649501123340887116U;
            aOrbiterD = RotL64((aOrbiterD * 11148976582360499033U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16462401546754210583U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1510579201823042227U;
            aOrbiterC = RotL64((aOrbiterC * 16287912400104043275U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6889066000014251983U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11324594596597724357U;
            aOrbiterK = RotL64((aOrbiterK * 15344987814648586023U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12237796033168436537U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17306069670330000343U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 3167451351403385259U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14197284538008811658U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4754134852883071927U;
            aOrbiterJ = RotL64((aOrbiterJ * 3484427259538998699U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17201907781639753736U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8318419319239859855U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10320390501983802091U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16012488623961565780U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 15583721012865354925U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 10656414363201743961U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14680351201973315018U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14483973292275372321U;
            aOrbiterH = RotL64((aOrbiterH * 9279222721410811027U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16324317860030681248U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7038506963317910910U;
            aOrbiterE = RotL64((aOrbiterE * 2960451734542956767U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12767672960346001218U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1457104756581596530U;
            aOrbiterG = RotL64((aOrbiterG * 1560375242310194691U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 22U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 23U)) + aOrbiterH) + aNonceWordF);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterH, 53U)) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aCross, 14U) + aOrbiterJ) + RotL64(aOrbiterC, 11U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterB, 60U));
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterF, 37U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterA, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterG, 35U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 40U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 43U)) + aOrbiterI) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 43U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16508U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((aIndex + 18672U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 16949U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20103U)) & S_BLOCK1], 46U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18041U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 39U)) ^ (RotL64(aIngress, 22U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 16802219662864902427U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 22U)) + 14332033461409490629U) + aNonceWordH;
            aOrbiterI = (aWandererE + RotL64(aCross, 39U)) + 8781794298640286845U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 41U)) + 8459933908074937264U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 51U)) + 1883580287986004426U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aPrevious, 37U)) + 17500258188004626118U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 53U)) + 7934811305150872870U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 5U)) + 6380363892361098905U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 12623079132626676910U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 10455208121949202703U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 56U)) + 8805532707916767629U) + aNonceWordF;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9161544391400377699U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 3501434325829663268U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7933545151293799637U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 651783304096081996U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 441505031509930622U;
            aOrbiterA = RotL64((aOrbiterA * 8045355432310956143U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1771159983581326424U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15227946417377695989U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1563141188972797601U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4153717524193279095U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4404521756523902829U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 1410342912973206203U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6231945075461813285U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3864780227164426690U;
            aOrbiterJ = RotL64((aOrbiterJ * 18031353247480673617U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1509699687948576558U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17316114302489411191U;
            aOrbiterG = RotL64((aOrbiterG * 15490661284980281585U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2250572827340157410U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6403966113144372915U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 726441947009132383U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2329903609147403156U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2486330017319455238U;
            aOrbiterK = RotL64((aOrbiterK * 17427461345935191757U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9333421733051210144U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14779925626161889533U;
            aOrbiterD = RotL64((aOrbiterD * 9120486933147706541U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4343688173541745311U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12686722305368397686U;
            aOrbiterB = RotL64((aOrbiterB * 17484250022537912537U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3745163111502795473U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16802219662864902427U;
            aOrbiterF = RotL64((aOrbiterF * 4343730534036919417U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 50U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterG, 43U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 56U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 38U) + RotL64(aOrbiterD, 19U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterK, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 29U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + aNonceWordL) + aPhaseEWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 22U) + RotL64(aOrbiterG, 21U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterB, 36U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24684U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneB[((aIndex + 24907U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26018U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23663U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22965U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 25156U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 13U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (aWandererD + RotL64(aPrevious, 11U)) + 12131317914288566437U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 57U)) + 5672805657999385496U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 52U)) + 3581710244233124197U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 5U)) + 15251296040538489436U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aCross, 23U)) + 11295008604679904153U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 2230897493419504490U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 43U)) + 7109600123297458999U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 36U)) + 13119156643107683803U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 14755160867807355250U) + aNonceWordB;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 16829363373287496832U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 21U)) + 16981122946707720883U) + aNonceWordK;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8806000776958603317U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16810923047720876014U;
            aOrbiterB = RotL64((aOrbiterB * 17872735050219539145U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8129657889554436328U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8653100378491974463U;
            aOrbiterC = RotL64((aOrbiterC * 11395283153912468661U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17048985838727432415U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10892675550889823573U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 976298937314081913U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15960158965421254346U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 12290011578634850001U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 9280475585104357745U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16265047040311479093U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10312956912303656248U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3012584393253845131U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16706890352221352779U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10630955894218491929U;
            aOrbiterK = RotL64((aOrbiterK * 12675937483456206355U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4009352551041162434U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3043810773683888556U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4328135390387997315U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1398071019814944785U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 16689766557488135301U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 8403881916549404871U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15934647144489136524U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13521276033614992223U;
            aOrbiterH = RotL64((aOrbiterH * 18003640895553609933U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4281211055727414100U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11848150507497406421U;
            aOrbiterA = RotL64((aOrbiterA * 1107789990317433481U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12022829841608199449U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12131317914288566437U;
            aOrbiterD = RotL64((aOrbiterD * 13275753083882829973U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 10U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterJ, 48U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterH, 41U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterC, 39U)) + aNonceWordF) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 23U)) + aOrbiterB) + aNonceWordO) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterG, 37U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterG, 50U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 35U)) + aOrbiterH);
            aWandererA = aWandererA ^ (((RotL64(aCross, 58U) + aOrbiterI) + RotL64(aOrbiterJ, 29U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 53U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28036U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((aIndex + 28317U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30851U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31845U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30888U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((aWandererA + RotL64(aIngress, 41U)) + 16424657151168221875U) + aNonceWordP;
            aOrbiterI = (aWandererE + RotL64(aCross, 3U)) + 17150123681886380361U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 14U)) + RotL64(aCarry, 13U)) + 16041993588694572757U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 9871185846434828537U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 51U)) + 11227236398354430757U) + aNonceWordH;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 21U)) + 5399325217402192631U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 11U)) + 9248828789282890454U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 53U)) + 9041370494203701062U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 57U)) + 14944424084524970764U) + aNonceWordO;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 19U)) + 5481938174456671041U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 43U)) + 14783648629543752715U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12355573914530445723U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9863991559011968318U;
            aOrbiterG = RotL64((aOrbiterG * 8495251211794343179U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 16149688605937250965U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 106041828692026825U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 12199934305374582599U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8076098639554567792U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11155119311895580013U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1495180896564818647U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6847612160595917702U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16094377920388017367U;
            aOrbiterF = RotL64((aOrbiterF * 4875801863643206333U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13584719866672696684U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13446209321646234607U;
            aOrbiterD = RotL64((aOrbiterD * 9945349065094781529U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15829806645369560988U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12573767256739062550U;
            aOrbiterI = RotL64((aOrbiterI * 5649504278826069077U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3850030870300393809U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11857593987748189858U;
            aOrbiterC = RotL64((aOrbiterC * 15942863910931814193U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5505918410521728373U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12949653497121247860U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 90944913639560027U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2448323375614082955U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 4386059032042654583U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 11730132905525317201U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 108129028178045299U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 18292666533864994149U;
            aOrbiterA = RotL64((aOrbiterA * 2599590507178673531U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10771402979550786312U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16424657151168221875U;
            aOrbiterE = RotL64((aOrbiterE * 6255743082177474607U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 26U);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 6U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterD, 23U)) + aOrbiterF) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 41U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 37U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterF, 48U));
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 21U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 11U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 48U) + aOrbiterA) + RotL64(aOrbiterB, 51U));
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterH, 39U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterH, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAC2D0CE4AA2D9149ULL + 0xD77CEDC93498E399ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB75F4A119E4A6C93ULL + 0xDE208E55AC5C9CE2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x89267DD4C41B6F9BULL + 0xD4454F718304DDEAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAAB20FA55ED1B3EDULL + 0xB7CAA925CEBFECC9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE7D987504C9FC153ULL + 0xC36ED41846A4D839ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC0E5C430FBBB6193ULL + 0xDAECE9743559DC8CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBEBB28E5B31F0E15ULL + 0xDE441ADF56756CB2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFB6F6142907D4A61ULL + 0xEA716B3D3609D8B9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDF83071932C2F363ULL + 0x85CC1509800B91FBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF73A28147BD4669BULL + 0x8F1B2179533467C9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8CA46F2D89164881ULL + 0xFD40DF0B44FBDEC2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA36834560D0E28BFULL + 0xBD10D9F001F34DEDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD36A6A73CDB4144FULL + 0xC402342FA7454588ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD0A91B7EFDE0A0E9ULL + 0xC10B765939C37530ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCED62D7F042E8D4BULL + 0xC303596909966AB9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA179435486D893EBULL + 0xE5C62F75C07488B4ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneD, aOperationLaneC, aOperationLaneD, aWorkLaneD, aSnowLaneC, aWorkLaneC, aSnowLaneB, aSnowLaneD, aInvestLaneB, aExpandLaneA, aInvestLaneA, aExpandLaneB, aInvestLaneC, aExpandLaneC, aSnowLaneA
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 213U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 3356U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2943U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2867U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1582U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1208U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = ((aWandererB + RotL64(aIngress, 60U)) + 16651241552253078315U) + aNonceWordI;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 4558144676982478003U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 23U)) + 8814884320080367550U;
            aOrbiterA = ((((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 16011579668555672117U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 4738918668759862438U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 56U)) + 12526083125540985108U) + aNonceWordC;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 37U)) + 8048723561746000552U) + aPhaseFOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 27U)) + 1082218464034639039U) + aNonceWordE;
            aOrbiterC = (aWandererH + RotL64(aIngress, 11U)) + 8432043246965946816U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9982080524048636852U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6720069955755215919U;
            aOrbiterG = RotL64((aOrbiterG * 1025046364205332059U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1019035028070247757U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7360619079463870467U;
            aOrbiterJ = RotL64((aOrbiterJ * 6623074813047915863U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10893918488381348474U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1390297670907738019U;
            aOrbiterA = RotL64((aOrbiterA * 11909657437658597735U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12512200589031203480U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14741471280748399540U;
            aOrbiterE = RotL64((aOrbiterE * 3012135242889901095U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8543897248359826770U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8545972622733791272U;
            aOrbiterD = RotL64((aOrbiterD * 11793879362775346821U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7049384618581928664U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14730773807906925408U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 10711566871536755073U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11480717275652449986U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 1135397594974536859U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 6347492892938856497U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6897207625849516702U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10920630712550287148U;
            aOrbiterK = RotL64((aOrbiterK * 4140705091806993359U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1094056478999931332U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6784487144549717207U;
            aOrbiterB = RotL64((aOrbiterB * 6295177724167067891U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 12U) + aOrbiterJ) + RotL64(aOrbiterA, 5U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 48U)) + aOrbiterK) + aNonceWordK);
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterB, 57U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 39U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 24U) + RotL64(aOrbiterB, 43U)) + aOrbiterA) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 53U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterE, 18U)) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 29U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneC
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aSnowLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 6891U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 10570U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8169U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8440U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10285U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9869U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aSnowLaneB[((aIndex + 7912U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (aWandererH + RotL64(aCross, 29U)) + 8988572360732005217U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 41U)) + 17889613225105985335U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 24U)) + 15563478320513948626U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 47U)) + 3441351228410524816U) + aNonceWordP;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 19U)) + 4425592689451435346U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 12733160231627305928U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 3574152157304607854U) + aNonceWordN;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 37U)) + 15167631896729808783U) + aPhaseFOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 10U)) + RotL64(aCarry, 47U)) + 15822667973915417055U) + aNonceWordO;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17181685481076577637U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9979204751408873468U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 8244434774754786565U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1334240485667164762U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 9190066751460137016U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 14585141844653660363U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15465215829109246336U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2305208282453624419U;
            aOrbiterE = RotL64((aOrbiterE * 10257861974108363283U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16951510027310993926U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11117938943423526901U;
            aOrbiterB = RotL64((aOrbiterB * 7805486716716924787U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12461379120662979432U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11719697049048823897U;
            aOrbiterJ = RotL64((aOrbiterJ * 14880996802304818757U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6843357278142933570U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12727898578324702374U;
            aOrbiterF = RotL64((aOrbiterF * 9786435451654365097U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 18127999660067652233U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11754709060558683082U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12798744012150745847U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16940151146420516184U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12924950783056761895U;
            aOrbiterI = RotL64((aOrbiterI * 8898170377271926745U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 14829713915929878471U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 840466047621042565U;
            aOrbiterH = RotL64((aOrbiterH * 10748511630509529489U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 26U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterF, 39U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 43U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 34U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterB, 23U)) + aPhaseFWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + aNonceWordA);
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterI, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterF, 12U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aInvestLaneB
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 14906U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 13685U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 11990U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12916U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14711U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 14499676118633326000U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 29U)) + 17191273593018552288U;
            aOrbiterG = (aWandererK + RotL64(aCross, 19U)) + 4085176294948097737U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 54U)) + 11112671474158908186U) + aPhaseFOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 8745787969012266485U) + aPhaseFOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aWandererH + RotL64(aScatter, 5U)) + 18074049663777707948U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 47U)) + 2543758649719164688U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 4659584749412700523U) + aNonceWordD;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 58U)) + 974639159259871273U) + aNonceWordF;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9211220687971081987U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8567024626862182714U;
            aOrbiterG = RotL64((aOrbiterG * 7755874089832496393U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5803002132294840900U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11968489432878148467U;
            aOrbiterD = RotL64((aOrbiterD * 4501441062617123165U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9470807228394903442U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1692347973120388469U;
            aOrbiterJ = RotL64((aOrbiterJ * 17433393164156231575U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16510815732690193145U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 755159406833096510U;
            aOrbiterK = RotL64((aOrbiterK * 14091736464659561165U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 1518824876475937620U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 701225390867330446U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 12264618860580199927U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8425976693733003889U) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7182176375442410367U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8860605703761731859U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4546566785167467924U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2593340999038753749U;
            aOrbiterF = RotL64((aOrbiterF * 10152461487764567563U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9756331608356622299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5511625814747641978U;
            aOrbiterH = RotL64((aOrbiterH * 4806076157539829529U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8694400787420160733U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 12648969491371382682U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5346585704222643759U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (RotL64(aOrbiterF, 34U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterF, 48U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 30U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 41U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 4U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterE, 23U)) + aNonceWordH) + aPhaseFWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 37U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterE, 53U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21276U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneC[((aIndex + 20847U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 18551U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 19065U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 17193U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererH + RotL64(aCross, 57U)) + 3238389262925516513U) + aNonceWordA;
            aOrbiterC = (aWandererF + RotL64(aIngress, 28U)) + 12381787182611386995U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 7883885539305181549U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 1185413044597727092U) + aNonceWordB;
            aOrbiterH = ((((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 15219353497204773135U) + aPhaseFOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aWandererC + RotL64(aScatter, 41U)) + 7533774715626734082U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 6U)) + 2599930450937763464U) + aNonceWordO;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 37U)) + 16074720663961214284U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aPrevious, 13U)) + 15483613196360051221U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9396557867081376268U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 9668459976852660245U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11748505665890567063U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9037269914643207212U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16936742640861088240U;
            aOrbiterH = RotL64((aOrbiterH * 1040172193161012227U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16481274825758546398U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 481851372837611166U;
            aOrbiterB = RotL64((aOrbiterB * 2225030139210599207U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13608921517203544108U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16930740723286214636U;
            aOrbiterJ = RotL64((aOrbiterJ * 2605108503821980865U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 902242902582149908U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1510861213079342977U;
            aOrbiterF = RotL64((aOrbiterF * 3309753895727400707U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7116243600304980310U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6631412278359709602U;
            aOrbiterA = RotL64((aOrbiterA * 11452627691392637463U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9246698682265275165U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8594373032014031450U;
            aOrbiterC = RotL64((aOrbiterC * 2550138341089957033U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15912837963877821048U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 11404583513022627609U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 17715204726760125357U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17295214920690244319U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 18315664494984189344U;
            aOrbiterI = RotL64((aOrbiterI * 17398893532076312945U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (RotL64(aOrbiterC, 26U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterB, 13U)) + aNonceWordN) + aPhaseFWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 18U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 34U) + aOrbiterC) + RotL64(aOrbiterE, 43U));
            aWandererE = aWandererE + ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterK, 27U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 39U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterK, 57U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aCross, 29U) + RotL64(aOrbiterH, 4U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aInvestLaneC
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26160U)) & S_BLOCK1], 24U) ^ RotL64(aSnowLaneD[((aIndex + 25053U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 24753U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21860U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneC[((aIndex + 24961U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (((aWandererF + RotL64(aScatter, 58U)) + 2617613537256538553U) + aPhaseFOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 53U)) + 16642868916835132715U;
            aOrbiterB = (aWandererK + RotL64(aCross, 23U)) + 10860291124337073254U;
            aOrbiterG = ((((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 6432511273906902472U) + aPhaseFOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 7505375005848241910U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 4U)) + 11086616004678821329U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 3298830587569881951U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 47U)) + 9775143140064220979U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 37U)) + 4147601326580823120U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12245920269898100415U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 8391940489176734499U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 9119606167674098007U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17876893379544668477U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18301882058180370541U;
            aOrbiterF = RotL64((aOrbiterF * 16680384667098921309U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6869225862715140102U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15404118372589259800U;
            aOrbiterA = RotL64((aOrbiterA * 5766851935950389915U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17757381020518233814U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 17677969146092374455U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3469432916562405063U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15783378556632870114U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 5792858258663697864U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12008981883482080427U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11737803388202260296U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16001927091970715330U;
            aOrbiterD = RotL64((aOrbiterD * 3062030309852922061U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 1749586939123286632U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6169421068855905938U;
            aOrbiterJ = RotL64((aOrbiterJ * 12374789910763348695U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10073586820719728062U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17744171227198661555U;
            aOrbiterH = RotL64((aOrbiterH * 10658375268803957647U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1149819647337612792U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7725598665625892006U;
            aOrbiterI = RotL64((aOrbiterI * 15097586655234391559U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 52U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 52U) + aOrbiterF) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 21U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterA, 12U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 3U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 27U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterD, 57U)) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 52U)) + aOrbiterG) + aNonceWordB);
            aWandererI = aWandererI + ((((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 35U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31016U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 27775U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 29489U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29996U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((aIndex + 29070U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 48U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = ((aWandererH + RotL64(aIngress, 47U)) + 12583180859826261500U) + aNonceWordH;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 4U)) + 9067093488553721468U;
            aOrbiterF = (aWandererG + RotL64(aCross, 19U)) + 12173106198862881754U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 27U)) + 11333491014394592654U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 3511883526940919554U) + aNonceWordG;
            aOrbiterA = ((((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 7416810692106273044U) + aPhaseFOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererE + RotL64(aScatter, 39U)) + 8341174972619784110U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 39U)) + 2220852854836962979U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 34U)) + 8090781422229383825U) + aNonceWordI;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2338801236599102223U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12484514711848308104U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10364216764253366067U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13684861340589131816U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12796636819991873058U;
            aOrbiterH = RotL64((aOrbiterH * 5533508014234835669U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 7634198650894837690U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10240326122201201762U;
            aOrbiterG = RotL64((aOrbiterG * 8758703497719125901U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4162814763739453934U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2766504649149048469U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 16731843453895178671U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11051393030148769655U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17687055068651386665U;
            aOrbiterC = RotL64((aOrbiterC * 1042927176246229537U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3353615315436983420U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5971640796220306310U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15804313508835034807U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12299773092762384765U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7435804907797063411U;
            aOrbiterE = RotL64((aOrbiterE * 9848139805288165965U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 8735783937125735699U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11903126115475835615U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16942088822124940265U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4427166023462475475U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6011733469446008137U;
            aOrbiterJ = RotL64((aOrbiterJ * 17298067225913923517U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 34U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 20U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 57U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 35U)) + aOrbiterH) + aNonceWordO) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aCross, 30U) + aOrbiterE) + RotL64(aOrbiterA, 39U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 29U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 52U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAF3D5007BC2D19AFULL + 0x84BAAAE02D6EDB49ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCA70227E9136D5E3ULL + 0x9508CD1EDAC8530AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCFF8D34339C486A7ULL + 0xD4A51FE0350D24A1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBE57FAFE3E2FDA57ULL + 0x8BDD518798A5FF43ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBA14BE9D90AF26EFULL + 0x8D5EA3CF77CEAB58ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFD78C9B7AB5A2A27ULL + 0xC0237F03EFD240A4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE127380060BBC0CDULL + 0xD8B74D0581B4A62FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x936C0AB38D0FAB7DULL + 0xA8582A9AC4FC7018ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE202B7F310E3AAA7ULL + 0xFF02B5CD1D2AF1E9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8E68E1C64CD5BCC3ULL + 0xD3C9714671A2FBAEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFE667ABE9054BCBFULL + 0x87FAEC24114EB11BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x873486EDBEBE0E15ULL + 0xEC359C70D3F6A927ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x91A422FFAFAE5935ULL + 0xDADC082D17D0A50BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF3D4B292EB27A02DULL + 0xDFA7BF1934FEBF2AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF001339D13211475ULL + 0x9962CD8DF8ADB7F5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAFA09E0E97A5F295ULL + 0xA1ED948F08B8C665ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneD, aWorkLaneA, aFireLaneC, aFireLaneA, aWorkLaneB, aInvestLaneC, aExpandLaneA, aInvestLaneB, aExpandLaneB, aFireLaneB, aExpandLaneC, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneA
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4796U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((aIndex + 1706U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 1716U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 3103U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 1876U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 137U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 24U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = ((aWandererJ + RotL64(aCross, 58U)) + 12136097566601676613U) + aNonceWordD;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 35U)) + 7969431322248040056U) + aNonceWordG;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 11U)) + 10530676021510553889U) + aNonceWordH;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 8740777303075445264U) + aPhaseHOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 13249434169895564739U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 29U)) + 15529577005925628472U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 344627093687331562U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8824277416519988893U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5636276438449709875U;
            aOrbiterF = RotL64((aOrbiterF * 222817930773618893U), 41U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 2079413361031851552U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7807998179168655561U;
            aOrbiterJ = RotL64((aOrbiterJ * 961456853699784753U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13589392896232029112U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10733011474804473996U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 361749145931578805U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15934162328347805968U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7573511217796245232U;
            aOrbiterH = RotL64((aOrbiterH * 10694563909931636155U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4828475187337891975U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13284974329890393113U;
            aOrbiterI = RotL64((aOrbiterI * 10831075817642374287U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13173869918669643112U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15841507674783398167U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15632933198136963277U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14168272451055700516U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11134471485501999898U;
            aOrbiterA = RotL64((aOrbiterA * 8019507184494591705U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterH, 29U)) + aNonceWordF) + aPhaseHWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 57U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 35U)) + aOrbiterF) + aPhaseHWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 10U)) + aOrbiterC) + aNonceWordM);
            aWandererH = aWandererH + ((((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 11U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererB, 12U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneA
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7635U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneC[((aIndex + 5617U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 7175U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6762U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 7653U)) & S_BLOCK1], 50U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 10613U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6091U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 22U) + RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (((aWandererE + RotL64(aIngress, 43U)) + 3650233661228036955U) + aPhaseHOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 11607036400067735729U;
            aOrbiterH = (aWandererB + RotL64(aCross, 53U)) + 3899614406903883035U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 35U)) + 8159156925629965143U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 60U)) + RotL64(aCarry, 23U)) + 7148903913967261270U) + aPhaseHOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 9161665622287517848U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 29U)) + 2981535013474059469U) + aNonceWordI;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15812469008200319549U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14687469489893270300U;
            aOrbiterH = RotL64((aOrbiterH * 14142363399696670451U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6025209349511417063U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12964750392311112676U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 12955480283032701843U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6572355895765394340U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 3542300121890027981U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 11201491178181273935U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6477175684045398359U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1081388388827929314U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8752188637514143529U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 13754328481584620771U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3684673342659575917U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6139923312873039143U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6542045150319909445U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5352102692424060388U;
            aOrbiterF = RotL64((aOrbiterF * 7385758355501860261U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9110100774657340354U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2813273684436269057U;
            aOrbiterJ = RotL64((aOrbiterJ * 10468759062594022273U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 28U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + aPhaseHWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 37U)) + aOrbiterH) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterF, 58U)) + aNonceWordE);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aNonceWordF) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterH, 29U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 20U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13504U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneA[((aIndex + 15678U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14066U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14288U)) & S_BLOCK1], 54U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15971U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 53U)) + 8685374557928800912U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 13U)) + 3482312691892161229U) + aNonceWordH;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 6948130297389161165U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 37U)) + 5506385663788942690U) + aNonceWordO;
            aOrbiterG = ((((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 17859982009307397161U) + aPhaseHOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 9178488809207094043U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 26U)) + 1835479501226057169U) + aNonceWordJ;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5368101733632614939U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9050459666576835422U;
            aOrbiterH = RotL64((aOrbiterH * 10351719549990259551U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9042186993119635078U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 17528342580198295025U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14316671546614386775U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6495418332558436882U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8834495762667327342U;
            aOrbiterE = RotL64((aOrbiterE * 10783141541937645995U), 37U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 4364314196965690905U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6357485231062120459U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 289429584586504995U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3321488322626415347U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10817330671781848737U;
            aOrbiterA = RotL64((aOrbiterA * 15875919466358823335U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17974092279281611763U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2871472057292789157U;
            aOrbiterK = RotL64((aOrbiterK * 16104199340711015181U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15187929795092006849U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 13482063681546475923U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14466266308157364963U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 30U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + aNonceWordD) + aPhaseHWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 43U)) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterF, 3U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 21U)) + aOrbiterI) + aPhaseHWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterK, 58U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterI, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21577U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 19530U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21354U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20945U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18621U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 12583180859826261500U) + aPhaseHOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aScatter, 11U)) + 9067093488553721468U) + aPhaseHOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 12173106198862881754U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 11333491014394592654U) + aNonceWordE;
            aOrbiterF = (aWandererC + RotL64(aScatter, 58U)) + 3511883526940919554U;
            aOrbiterI = (aWandererD + RotL64(aCross, 3U)) + 7416810692106273044U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 21U)) + 8341174972619784110U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2220852854836962979U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8090781422229383825U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 578293950675644397U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2338801236599102223U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12484514711848308104U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10364216764253366067U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13684861340589131816U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 12796636819991873058U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 5533508014234835669U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7634198650894837690U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10240326122201201762U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8758703497719125901U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4162814763739453934U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2766504649149048469U;
            aOrbiterA = RotL64((aOrbiterA * 16731843453895178671U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11051393030148769655U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17687055068651386665U;
            aOrbiterI = RotL64((aOrbiterI * 1042927176246229537U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3353615315436983420U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5971640796220306310U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 15804313508835034807U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 36U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 39U)) + aNonceWordJ);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + aNonceWordB) + aPhaseHWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterK, 57U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 43U)) + aOrbiterG) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 21U)) + aOrbiterK) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 42U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25972U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 26064U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 25259U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22916U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 24867U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 57U)) ^ (RotL64(aIngress, 20U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 18144572925667544139U;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 37U)) + 5659758077574059728U) + aPhaseHOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 21U)) + 6343330616999166392U) + aNonceWordG;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 60U)) + 17754639838410839447U) + aNonceWordJ;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 3U)) + 9451843819849581729U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 29U)) + 7957854457197462212U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 1461994799722205010U) + aNonceWordL;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 18002214276252170177U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14689869073147027164U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12242482963989582191U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3978104368003440293U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8512135845221335386U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10506667163729414667U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1477533446382953439U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2166717790929947990U;
            aOrbiterF = RotL64((aOrbiterF * 6538884492418324461U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8082437060686606995U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4363687722464700362U;
            aOrbiterE = RotL64((aOrbiterE * 7199165810993478887U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15782763348014924206U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8572509150015960728U;
            aOrbiterA = RotL64((aOrbiterA * 3340528604891897779U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12248271773316742521U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9602078627638561949U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 1860631869877427405U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17244849374768558859U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1030743048280579012U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 10858949914285817051U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 12U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterA, 12U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA + (((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterB, 37U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + aNonceWordI);
            aWandererI = aWandererI + ((((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 53U)) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 19U)) + aOrbiterF) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 5U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30839U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 29462U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 27330U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30081U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 32278U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 37U)) + (RotL64(aPrevious, 6U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 57U)) + 12380376990224645149U) + aNonceWordO;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 34U)) + RotL64(aCarry, 39U)) + 18296928500297384014U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 21U)) + 3550626816361145100U;
            aOrbiterF = ((((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 2667792936946706027U) + aPhaseHOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 12020969779370926953U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 3U)) + 737340727886903447U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 41U)) + 1681797651799760502U) + aPhaseHOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 2956186342689489064U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1876852870402977177U;
            aOrbiterI = RotL64((aOrbiterI * 8875540081346621757U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6433205819353555071U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 9065076854974222998U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 5459675878087242021U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3254410578766789992U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2005081975473815576U;
            aOrbiterJ = RotL64((aOrbiterJ * 9947701153722014085U), 41U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 15992999234834560419U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3458344156815120948U;
            aOrbiterB = RotL64((aOrbiterB * 1668460113964608051U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17069783053664877727U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1260234710193913099U;
            aOrbiterF = RotL64((aOrbiterF * 4561226779897414381U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3825186451876061335U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2905344294992827535U;
            aOrbiterK = RotL64((aOrbiterK * 2469896090698580795U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 18141402347899180617U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8760129857609925066U;
            aOrbiterE = RotL64((aOrbiterE * 2507999156108123047U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 13U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 41U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterB, 41U));
            aWandererA = aWandererA + ((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterE, 3U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterK, 34U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterB, 47U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1661U)) & W_KEY1], 30U) ^ RotL64(aKeyRowReadB[((aIndex + 1029U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1792U)) & W_KEY1], 50U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 798U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 20U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aScatter, 47U)) + 9446153639709651566U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 39U)) + 10550762260670758167U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 12U)) + 7062634922142578383U) + aPhaseAOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 9178499097812764515U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 6887103379773525538U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 29U)) + 6239750312052010257U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 51U)) + 17645022614523287959U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 34U)) + 3639618183259408272U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 3131737117548745095U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7253994382396406554U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 15217993711938379561U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17853313384747259923U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12594152227603630033U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11250170200489647869U;
            aOrbiterI = RotL64((aOrbiterI * 546800378327864723U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12936942656624279424U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10990736056052106149U;
            aOrbiterJ = RotL64((aOrbiterJ * 7123916809953459187U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12787293075893090465U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17154990205620778151U;
            aOrbiterC = RotL64((aOrbiterC * 10031369940028159521U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1270827262969060301U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17337623431665013136U;
            aOrbiterG = RotL64((aOrbiterG * 1517262088236356107U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 830330490987911853U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6828309232554560547U;
            aOrbiterD = RotL64((aOrbiterD * 9742464176986145819U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11470087853413986203U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10470148870747884420U;
            aOrbiterH = RotL64((aOrbiterH * 6766079738799967443U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18315536891901859637U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12264670822285914271U;
            aOrbiterE = RotL64((aOrbiterE * 5841574505408674119U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10931842095884524879U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11134871340959676257U;
            aOrbiterF = RotL64((aOrbiterF * 11714837622285605745U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 22U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterG, 23U));
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 50U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 39U));
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterI, 11U)) + aPhaseAWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 3U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterD, 44U));
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 57U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4248U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2948U)) & W_KEY1], 42U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4884U)) & W_KEY1], 28U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3401U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 6U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererI + RotL64(aCross, 39U)) + 12690502671561165478U) + aPhaseAOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aScatter, 47U)) + 17519943923428102801U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 28U)) + 10705515807975331385U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 16586447272278538179U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 21U)) + 8006560996840971798U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 12928600185788857701U) + aPhaseAOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 52U)) + 14240723153798267172U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 8636219177994872072U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 57U)) + 7586790235186467512U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1103807034179512424U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7547526530239498693U;
            aOrbiterC = RotL64((aOrbiterC * 3360295583636013509U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8380239679344786397U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5690809173787433519U;
            aOrbiterK = RotL64((aOrbiterK * 5354724308093372953U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8390902801141804609U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3507306189192059486U;
            aOrbiterG = RotL64((aOrbiterG * 18336280496510253103U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6190745292098482871U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8065418693975056902U;
            aOrbiterE = RotL64((aOrbiterE * 6414621418430102589U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 12111755051718111803U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7605877769709909297U;
            aOrbiterI = RotL64((aOrbiterI * 17525248694315944599U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5969794501112646237U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5127559299360591476U;
            aOrbiterH = RotL64((aOrbiterH * 4521563633438853069U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10593847754747739786U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4401750688524310121U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14265829318976633707U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6927893132508779499U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4874009978647014479U;
            aOrbiterA = RotL64((aOrbiterA * 13340466017023540755U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13146693487138744677U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3298472134223595298U;
            aOrbiterJ = RotL64((aOrbiterJ * 2145005258008477281U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 46U) + aOrbiterI) + RotL64(aOrbiterC, 52U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 27U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 56U) + aOrbiterE) + RotL64(aOrbiterC, 23U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 48U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 19U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 43U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterA, 39U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6180U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 5758U)) & W_KEY1], 12U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7068U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5750U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7421U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 36U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 35U)) + 11700815697312060726U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 58U)) + RotL64(aCarry, 5U)) + 11808423452327465441U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aPrevious, 13U)) + 8670503858631730886U;
            aOrbiterA = (aWandererE + RotL64(aCross, 51U)) + 2400061067991988544U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 19U)) + 16163118178366229686U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 3280178595904941068U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 30U)) + RotL64(aCarry, 19U)) + 3298683600817047727U;
            aOrbiterC = (aWandererD + RotL64(aCross, 3U)) + 16321624053445183574U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 47U)) + 6730229877611375225U) + aPhaseAOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10162830636713641322U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15646771327759599256U;
            aOrbiterD = RotL64((aOrbiterD * 15333053762177144775U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14841751262270544102U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9545541117228834895U;
            aOrbiterJ = RotL64((aOrbiterJ * 11529769874752969377U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14676615635857599982U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1231768638470558855U;
            aOrbiterB = RotL64((aOrbiterB * 2716808508509014677U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1945905595345404833U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1406171421638586846U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4577864352425476233U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1970292335806697198U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12309719390375013297U;
            aOrbiterG = RotL64((aOrbiterG * 16540660957923687327U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5352135521358954576U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15465675376193501658U;
            aOrbiterI = RotL64((aOrbiterI * 16385761112921041387U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2842123638916600369U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3544764287036748668U;
            aOrbiterC = RotL64((aOrbiterC * 3360772950777850115U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6038297172906492282U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10249342332287140970U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16701083081566042277U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 1662076777040529446U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1949705569959740274U;
            aOrbiterA = RotL64((aOrbiterA * 11340691546658994529U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 26U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterB, 36U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterD, 53U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 19U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterD, 40U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 27U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 34U) + aOrbiterA) + RotL64(aOrbiterG, 13U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterH, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10246U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 8774U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(mSource[((aIndex + 9122U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9644U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9375U)) & W_KEY1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10015U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 5131645209694953015U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 23U)) + 12070391048835379854U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 58U)) + 2604295836242338724U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 19U)) + 14042039029284001596U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 27U)) + 8914654543854559327U;
            aOrbiterF = (aWandererD + RotL64(aCross, 51U)) + 2185619407969359869U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 12U)) + RotL64(aCarry, 23U)) + 5187406295103352574U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 8022832481290871217U) + aPhaseBOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 5U)) + 8783061916740573472U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10711028365596196301U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13387065038269133571U;
            aOrbiterI = RotL64((aOrbiterI * 12444578026365205255U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11187001318931801582U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14191473173276034019U;
            aOrbiterE = RotL64((aOrbiterE * 2491253922434756431U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16207761776716426435U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 9677408414452078760U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5487303383095129949U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17812460332794370649U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7736423148554132028U;
            aOrbiterA = RotL64((aOrbiterA * 15588733747232852555U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17293203944059014763U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 13487243633338010243U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9468688858740539095U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15979293016815060755U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17645215484691359547U;
            aOrbiterF = RotL64((aOrbiterF * 1449450767288733995U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11635961468586927692U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10530136578329059784U;
            aOrbiterH = RotL64((aOrbiterH * 8785021493374398437U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4900370530116992731U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15952900504821599445U;
            aOrbiterB = RotL64((aOrbiterB * 5413316082800365261U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9938000151832814778U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14170277411106520726U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5058343552974910737U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 34U) + RotL64(aOrbiterG, 23U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 28U)) + aOrbiterA) + aPhaseBWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 47U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterA, 53U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 5U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 28U) + aOrbiterG) + RotL64(aOrbiterC, 19U));
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterB, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 13U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 42U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 18U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11788U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 13469U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13210U)) & W_KEY1], 21U) ^ RotL64(mSource[((aIndex + 11512U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12834U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13498U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12953U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 43U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 60U)) + 13350544654542863236U) + aPhaseBOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 12364346790125404372U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 9738750172849512764U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 29U)) + 3781373837635491421U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 47U)) + 16635020317512702337U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 23U)) + 5383653921676231276U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 11U)) + 10181959815492056493U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 5U)) + 10005510924273927017U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 34U)) + RotL64(aCarry, 3U)) + 9524687662265740565U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4259138552009771014U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8973051213213726023U;
            aOrbiterH = RotL64((aOrbiterH * 12625091476068190979U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 17602611840127337490U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8218984546932905269U;
            aOrbiterI = RotL64((aOrbiterI * 17504305273683304231U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18102186122213487888U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2629927500298092976U;
            aOrbiterC = RotL64((aOrbiterC * 6983280164448292723U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2491581597835795234U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9506602492971620955U;
            aOrbiterD = RotL64((aOrbiterD * 9559829640915637163U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13422942713680612924U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 15037354693234876601U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12692376075738621447U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12896066842192894694U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2202952306291905855U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6779368532763429997U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12160313482450599313U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10812986281270407756U;
            aOrbiterE = RotL64((aOrbiterE * 7786608700746771809U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12474638293190144525U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5882870951276225224U;
            aOrbiterF = RotL64((aOrbiterF * 15532427302173572457U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3782896138051179209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10965680631059882311U;
            aOrbiterK = RotL64((aOrbiterK * 14060923998307082385U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterD, 5U)) + aPhaseBWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 54U) + aOrbiterA) + RotL64(aOrbiterE, 39U));
            aWandererI = aWandererI + ((((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 28U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterF, 43U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 14U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aCross, 58U) + aOrbiterK) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16317U)) & S_BLOCK1], 48U) ^ RotL64(aInvestLaneA[((aIndex + 15877U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15654U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14631U)) & W_KEY1], 13U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15364U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14190U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15243U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 47U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aIngress, 34U)) + 18191288703716505885U) + aPhaseBOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 9824014524910417136U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 3U)) + 11953012029254917548U) + aPhaseBOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 6297568011027199089U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 23U)) + 2576999400457367975U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 13U)) + 13176139160575558254U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 27U)) + 9978408174563621810U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 19U)) + 16765834875061607142U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 40U)) + RotL64(aCarry, 35U)) + 16534507305459121344U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3114710944346151807U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10240517868726718592U;
            aOrbiterB = RotL64((aOrbiterB * 4645691562915606463U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10721450637990777883U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16689590768796583952U;
            aOrbiterH = RotL64((aOrbiterH * 3046344179729901637U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2427422768928450209U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13495584061816457831U;
            aOrbiterG = RotL64((aOrbiterG * 6670984773768885119U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7058636403765106682U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9897341853944713767U;
            aOrbiterF = RotL64((aOrbiterF * 14286816859999869231U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17749559755733386064U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12515645083926326659U;
            aOrbiterC = RotL64((aOrbiterC * 6582878478865838245U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2625692458813609962U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10596240255026143019U;
            aOrbiterE = RotL64((aOrbiterE * 11605800195771080135U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12374290338067865540U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1507386663796330249U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1210241080424446087U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9288099549484146726U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15159312464747000702U;
            aOrbiterJ = RotL64((aOrbiterJ * 500055502081347757U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14998608679505446229U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17625038109437732009U;
            aOrbiterD = RotL64((aOrbiterD * 14785862243019841689U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 26U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 56U) + aOrbiterJ) + RotL64(aOrbiterF, 34U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 19U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 47U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterF, 51U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 34U) + aOrbiterG) + RotL64(aOrbiterD, 3U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 56U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17528U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 18181U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(mSource[((aIndex + 18848U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 16853U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18064U)) & W_KEY1], 35U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17904U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17766U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererF + RotL64(aCross, 4U)) + RotL64(aCarry, 43U)) + 7960325128608297381U) + aPhaseCOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aScatter, 57U)) + 12773836012104052042U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 3173972621347773016U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 3708401356314308171U;
            aOrbiterI = (aWandererA + RotL64(aCross, 41U)) + 950774285720019449U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 47U)) + 4170092315705438265U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 53U)) + 17000449130864980747U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 23U)) + 8793910540062893860U) + aPhaseCOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aIngress, 18U)) + 520277969543516469U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12762214857389827271U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2932451184340207695U;
            aOrbiterB = RotL64((aOrbiterB * 7513337346940091655U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11062179998786293839U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7919119215271524178U;
            aOrbiterD = RotL64((aOrbiterD * 9053677007180081359U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1774988449597115155U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3799792889466518953U;
            aOrbiterF = RotL64((aOrbiterF * 17512791286490623455U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1815062051307896589U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15260373951371654483U;
            aOrbiterH = RotL64((aOrbiterH * 2208604434669491625U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12867546628945676853U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7772820973895846946U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7581704643538761985U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14213957831821966834U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16561105721170419454U;
            aOrbiterA = RotL64((aOrbiterA * 2540533987337175367U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16556502948339949526U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9706742922075498974U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8527361328901355457U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13455756934917486016U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9107769876332723454U;
            aOrbiterG = RotL64((aOrbiterG * 1722386100852683783U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15793099079168487016U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7968278803691283365U;
            aOrbiterI = RotL64((aOrbiterI * 11644765391940099387U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 22U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 29U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterI, 29U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterH, 4U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 35U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 43U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterB, 47U)) + aPhaseCWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterF, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterE, 22U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 18U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20209U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 20811U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20564U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 20128U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21212U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20727U)) & W_KEY1], 36U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20857U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 20461U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 4U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aCross, 11U)) + 6024062041314952357U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 18340757093658015585U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 58U)) + RotL64(aCarry, 29U)) + 11911120493880346751U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 37U)) + 17428074353884654439U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 43U)) + 12790849760814795936U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 51U)) + 12633397052172117800U) + aPhaseCOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 19U)) + 11946150433665237945U;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 4U)) + RotL64(aCarry, 11U)) + 16842157900909419285U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 23U)) + 14186235783224155962U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13284904542579767591U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11609181965078844357U;
            aOrbiterJ = RotL64((aOrbiterJ * 5455780554452453513U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9628562297095374984U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7850281529011259759U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17611485102925470357U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 257458718073794527U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10693404545773519306U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14821443722828498323U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3430519236533871460U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6183054506953198055U;
            aOrbiterI = RotL64((aOrbiterI * 6121082743789970911U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2905610989884221654U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 4472163910775333862U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7770678426310856745U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16870142883133769663U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1403692060594816451U;
            aOrbiterD = RotL64((aOrbiterD * 9740854430251597879U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16904169913507057108U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4773518591580333357U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5306070307776061267U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6528141733853494275U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11254806909313951442U;
            aOrbiterA = RotL64((aOrbiterA * 6316669786405548827U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6857506858448143407U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2855763534355983644U;
            aOrbiterF = RotL64((aOrbiterF * 16881334940165182415U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 29U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 56U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 18U) + aOrbiterG) + RotL64(aOrbiterK, 47U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 5U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 39U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterI, 10U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterK, 19U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 12U) + RotL64(aOrbiterH, 43U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererK, 10U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24395U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 23798U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 21972U)) & W_KEY1], 46U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23866U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23176U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23651U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24471U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 24473U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 53U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aPrevious, 57U)) + 16519040829220310189U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 6888002778416941825U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 12U)) + RotL64(aCarry, 13U)) + 1310832187746534025U;
            aOrbiterC = (aWandererA + RotL64(aCross, 29U)) + 5890888009051281674U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 5143864838362464857U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 53U)) + 15591534069452660003U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 23U)) + 1466867671765325096U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 46U)) + 13931443680107902488U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aIngress, 19U)) + 15400747367673245552U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2836975369734495759U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2370720358274970117U;
            aOrbiterH = RotL64((aOrbiterH * 4615571902817575375U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3470677184188006133U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7175584278499266723U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10067096593682482345U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6095078817776863055U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2176637999243513070U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12215701810843975501U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5580391239754903129U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15196125567953871184U;
            aOrbiterE = RotL64((aOrbiterE * 12686361960729564519U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12787014151503209931U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1523153207064063495U;
            aOrbiterC = RotL64((aOrbiterC * 3113907543551927561U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12973289026485937829U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9087439766232078173U;
            aOrbiterJ = RotL64((aOrbiterJ * 5817029335999350327U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16318022893068674015U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11089160685103562409U;
            aOrbiterK = RotL64((aOrbiterK * 17087834321385147603U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8680037953925067235U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3112588943274158119U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9214011370307670371U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16749015684369649821U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9419550535891334966U;
            aOrbiterF = RotL64((aOrbiterF * 5421312787569114811U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 51U));
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 34U) + aOrbiterH) + RotL64(aOrbiterE, 11U));
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 56U)) + aOrbiterH) + aPhaseCWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterK, 47U));
            aWandererH = aWandererH + ((RotL64(aScatter, 38U) + aOrbiterG) + RotL64(aOrbiterJ, 30U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 41U)) + aOrbiterH) + aPhaseCWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25473U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadA[((aIndex + 26961U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26243U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneB[((aIndex + 26207U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24640U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26364U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25107U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26156U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 5U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererH + RotL64(aPrevious, 6U)) + 12311607308490066301U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 43U)) + 13100864684740679846U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 13697304189274329704U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aCross, 23U)) + 9047976902871216732U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 27U)) + 2147897579538537888U;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 2072444829390996142U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 60U)) + 2129307836981020908U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 10663145333751112064U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 51U)) + 15019844390503785459U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5460865577557928142U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15806522559993224197U;
            aOrbiterD = RotL64((aOrbiterD * 8722932687972240099U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6361113778657833389U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8306013884615042570U;
            aOrbiterF = RotL64((aOrbiterF * 8234258702656728667U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4038420580499706912U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11908091484457158973U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3964111175645156719U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 11133912466611921250U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2469227904206936928U;
            aOrbiterK = RotL64((aOrbiterK * 2704438771198001599U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13234017916788297295U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9061117693840451988U;
            aOrbiterC = RotL64((aOrbiterC * 3637440416741459419U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12013423690843812324U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14371779015144617412U;
            aOrbiterG = RotL64((aOrbiterG * 3359568073302062667U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10044883414565441442U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14334898081890462218U;
            aOrbiterJ = RotL64((aOrbiterJ * 4878939077928220019U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13788962593988366125U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8377887372059713516U;
            aOrbiterI = RotL64((aOrbiterI * 1925913354197206851U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4584439257847749371U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13335592911357756498U;
            aOrbiterB = RotL64((aOrbiterB * 6515028218115896375U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 12U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterG, 51U));
            aWandererA = aWandererA + ((RotL64(aIngress, 38U) + RotL64(aOrbiterF, 44U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 29U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + aPhaseDWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 30U) + RotL64(aOrbiterC, 39U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterC, 23U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 19U)) + aPhaseDWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 18U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28608U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 28160U)) & S_BLOCK1], 46U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28794U)) & W_KEY1], 35U) ^ RotL64(aFireLaneC[((aIndex + 28882U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27431U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27527U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29565U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((aIndex + 27591U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 38U) ^ RotL64(aCross, 53U)) ^ (RotL64(aCarry, 19U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererG + RotL64(aCross, 5U)) + 11410829607777684449U;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 34U)) + RotL64(aCarry, 19U)) + 7502698839700975347U) + aPhaseDOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 13U)) + 13267685058252106173U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 39U)) + 238242706996630625U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 47U)) + 8184695499511454281U;
            aOrbiterF = (((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 11U)) + 12767823220461985403U) + aPhaseDOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 23U)) + 12293198423143850330U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 41U)) + 11149495229952495939U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 19U)) + 7556992689338382800U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3431338808774134649U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16863099140844995099U;
            aOrbiterK = RotL64((aOrbiterK * 752376661101787919U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17872458049880677604U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16760153457252546974U;
            aOrbiterF = RotL64((aOrbiterF * 11225037229069712805U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3115544493537438408U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4359882942759752958U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 561477566995575801U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13387113067202396536U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12955690074544490161U;
            aOrbiterD = RotL64((aOrbiterD * 12449941770827974511U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 15614054443728226807U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1939441328066616114U;
            aOrbiterE = RotL64((aOrbiterE * 4484917074808974359U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4599016263007782537U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9962305629016158048U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1496184427500037279U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8428467674122750557U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3938884087806393439U;
            aOrbiterC = RotL64((aOrbiterC * 12810531094050481761U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6018636830758044658U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1510372000641305416U;
            aOrbiterG = RotL64((aOrbiterG * 9002834928626918247U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17592782466215337843U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8119921507606870360U;
            aOrbiterA = RotL64((aOrbiterA * 1299795061644535485U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 24U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterE, 5U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 18U) + aOrbiterI) + RotL64(aOrbiterA, 14U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterE, 27U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterA, 19U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterG, 58U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 30U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterF, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32573U)) & S_BLOCK1], 38U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30833U)) & W_KEY1], 53U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31712U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31292U)) & S_BLOCK1], 48U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31404U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31082U)) & W_KEY1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererF + RotL64(aPrevious, 34U)) + 9041099828460168106U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 3U)) + 12883711604096848454U) + aPhaseDOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 17420968786226443079U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 3448213891716125104U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 19U)) + 11866455977445336560U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 53U)) + 4119356835384495905U;
            aOrbiterF = (aWandererB + RotL64(aCross, 39U)) + 2186212599698637068U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 60U)) + 6506144898969301620U;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 47U)) + 12556800923644051626U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4075551535185182945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17877694808492008749U;
            aOrbiterJ = RotL64((aOrbiterJ * 901315308379887473U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5553428900598223316U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14362304852277160675U;
            aOrbiterE = RotL64((aOrbiterE * 11415103199856419303U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9174200302876075831U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16110739511917638547U;
            aOrbiterB = RotL64((aOrbiterB * 7004356839428657949U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10189881974519849402U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2128076632642616677U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8860453653433114929U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18133523799074400083U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9916472958834153766U;
            aOrbiterG = RotL64((aOrbiterG * 3454601168808001733U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10274457562795569227U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14134814273275356425U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15912501063665343159U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6394306369514735480U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4825761192736485643U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12534544147331805643U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5672807934779206275U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3881953574159390421U;
            aOrbiterI = RotL64((aOrbiterI * 7448770570912161095U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12012232712634303203U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14176392925893052596U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11288668529893084583U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 10U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 56U) + aOrbiterC) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 43U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterE, 23U)) + aPhaseDWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 12U) + RotL64(aOrbiterF, 29U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterA, 39U)) + aPhaseDWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterD, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterB, 14U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneA, aInvestLaneD, aFireLaneD, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3742U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 4690U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 1323U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2059U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 1961U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCarry, 52U)) + (RotL64(aCross, 39U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 898812731947995389U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aScatter, 29U)) + 8677347622525527167U;
            aOrbiterG = (aWandererG + RotL64(aCross, 35U)) + 770321564027567654U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 11020474858081526395U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 11U)) + 17289793580414993470U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 60U)) + 10111912559295118444U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 8083622125544542011U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7149858558922988240U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 5919683821379905699U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16705119888884231567U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6860902846079238714U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15083517836867542075U;
            aOrbiterB = RotL64((aOrbiterB * 4686657139237578325U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14852868368708376381U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9860233289028878323U;
            aOrbiterF = RotL64((aOrbiterF * 13418143547952204667U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 772406119079116272U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7971141501337627589U;
            aOrbiterE = RotL64((aOrbiterE * 10168120622976358617U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8478568022896691911U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4027604850785607101U;
            aOrbiterJ = RotL64((aOrbiterJ * 4826627523578901467U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17199331557841535430U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7515957656979776361U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5468950152869656599U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17138249294921502391U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16236812863923234668U;
            aOrbiterC = RotL64((aOrbiterC * 2925542836624164807U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterF, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterI, 51U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterF, 23U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 58U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 28U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneA
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 6371U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 7652U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10046U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5771U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10535U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererH + RotL64(aIngress, 51U)) + 12136097566601676613U;
            aOrbiterD = (aWandererC + RotL64(aCross, 23U)) + 7969431322248040056U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 10530676021510553889U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 58U)) + 8740777303075445264U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 13249434169895564739U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 29U)) + 15529577005925628472U) + aPhaseEOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 344627093687331562U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8824277416519988893U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5636276438449709875U;
            aOrbiterG = RotL64((aOrbiterG * 222817930773618893U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2079413361031851552U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7807998179168655561U;
            aOrbiterB = RotL64((aOrbiterB * 961456853699784753U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13589392896232029112U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10733011474804473996U;
            aOrbiterD = RotL64((aOrbiterD * 361749145931578805U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15934162328347805968U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7573511217796245232U;
            aOrbiterK = RotL64((aOrbiterK * 10694563909931636155U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 4828475187337891975U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13284974329890393113U;
            aOrbiterH = RotL64((aOrbiterH * 10831075817642374287U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13173869918669643112U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 15841507674783398167U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15632933198136963277U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14168272451055700516U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11134471485501999898U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8019507184494591705U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 13U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterB, 21U));
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 4U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneD
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 12452U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 14493U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 11415U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12516U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15028U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 13245U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 14U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aCross, 51U)) + 15383045568644941552U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aIngress, 44U)) + RotL64(aCarry, 29U)) + 17452811657750910067U) + aPhaseEOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 15660117718455155603U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 10396441207743665753U;
            aOrbiterD = (aWandererB + RotL64(aCross, 35U)) + 3708971058200841442U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 23U)) + 7000673057768598750U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 29U)) + 9886354469011131596U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16018065329058043467U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5024756166109352320U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11660932185479046483U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6587818720728886652U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3652672354944162319U;
            aOrbiterA = RotL64((aOrbiterA * 10807121230791716109U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6307315649915348048U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16405347331742979258U;
            aOrbiterH = RotL64((aOrbiterH * 7183142442906743699U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5427299664054601957U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4983381733483185898U;
            aOrbiterI = RotL64((aOrbiterI * 14646556236306407673U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10182995521328377487U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8694282877540593550U;
            aOrbiterD = RotL64((aOrbiterD * 14614602561910403893U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4085927978153269932U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6176195962815240877U;
            aOrbiterE = RotL64((aOrbiterE * 16792916528959579875U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6966742100601433005U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9920952446921247521U;
            aOrbiterB = RotL64((aOrbiterB * 1879821050131820933U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 46U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 41U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 35U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 22U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterJ, 29U));
            aWandererK = aWandererK + (((RotL64(aScatter, 18U) + RotL64(aOrbiterJ, 53U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 4U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18763U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneC[((aIndex + 18750U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20614U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19355U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21353U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 18846U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 42U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererH + RotL64(aIngress, 47U)) + 6069475454765660321U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 11483704742497268068U) + aPhaseEOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 29U)) + 11055697447388986418U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 51U)) + 10897095046039997004U) + aPhaseEOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 13U)) + 4731637118230457840U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 36U)) + RotL64(aCarry, 39U)) + 13855839187084986751U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 5U)) + 5328208115460188239U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 12479538544291412985U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10740165998792608231U;
            aOrbiterJ = RotL64((aOrbiterJ * 14046827922294477379U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6492798157284955373U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13056825957483891921U;
            aOrbiterG = RotL64((aOrbiterG * 14882112110627751751U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2068184064919194657U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5656302738780746294U;
            aOrbiterA = RotL64((aOrbiterA * 16493021179127646345U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11193756120230763294U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17306750816837208999U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7949360041241439741U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12952818800389361804U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15380412293642628312U;
            aOrbiterC = RotL64((aOrbiterC * 2914662289178925547U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7706090204767242996U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14598802276412649570U;
            aOrbiterF = RotL64((aOrbiterF * 4821408736292041399U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17819762117328075515U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6481384240915075101U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4836701121865783029U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterA, 22U)) + aPhaseEWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 20U) + aOrbiterI) + RotL64(aOrbiterA, 57U));
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 13U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 37U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 48U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27085U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 22500U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 24279U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22375U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 26918U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 23384U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 60U)) ^ (RotL64(aCross, 41U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 6318740973868639425U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 26U)) + 5487840061430920881U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 57U)) + 10258706763248072672U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 18356875269730338208U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 12883160282903147010U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 13U)) + 1010140474942697730U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 5U)) + 17733939421700898293U) + aPhaseEOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13693055887924981201U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14574732452793385269U;
            aOrbiterJ = RotL64((aOrbiterJ * 9373765929885750185U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10832873941223609012U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8212600587135328040U;
            aOrbiterH = RotL64((aOrbiterH * 5334613996794796145U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5312744319781971178U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6173741211706546923U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12854414066390848249U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3693249147883790810U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 18365859989736602556U;
            aOrbiterF = RotL64((aOrbiterF * 3348463719324104997U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10645056678337549771U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1175668356822251045U;
            aOrbiterE = RotL64((aOrbiterE * 6579675292775345579U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13556844570541823717U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4790355739411849736U;
            aOrbiterC = RotL64((aOrbiterC * 4083544011788850307U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14905575502272644116U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17047244574558476634U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2356386971503880047U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 28U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterK, 51U)) + aPhaseEWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterB, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 4U) + aOrbiterF) + RotL64(aOrbiterH, 21U)) + aPhaseEWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 35U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 44U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29203U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 30058U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 30204U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31254U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30684U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 29845U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 29U)) + 14823268998003220191U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 15295237288788213847U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 16434853402001133899U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 7555911304407871631U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 5U)) + 14977248264994834620U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 23U)) + 9707764144919392380U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 13U)) + 1277304385464681529U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3089786220465849395U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3700503853358695085U;
            aOrbiterC = RotL64((aOrbiterC * 2079089949442685421U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3240054112993517371U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16897532076915366859U;
            aOrbiterB = RotL64((aOrbiterB * 4120874717534309035U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18167359289798364307U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8870819278575769863U;
            aOrbiterK = RotL64((aOrbiterK * 9334066154398059075U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15363069206212330251U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 14858164441499725158U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14931933411393847915U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5357144808788707522U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2910681277417754860U;
            aOrbiterJ = RotL64((aOrbiterJ * 13170868582159347059U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9824408699018165151U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 368370224788793300U;
            aOrbiterI = RotL64((aOrbiterI * 14358982366258729959U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7095398304588825115U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11418879758164313554U;
            aOrbiterF = RotL64((aOrbiterF * 5983520332639771791U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterJ, 21U));
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 54U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 42U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 38U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneD, aSnowLaneA, aExpandLaneA, aExpandLaneC, aSnowLaneB, aExpandLaneB, aWorkLaneA, aInvestLaneA, aWorkLaneB, aInvestLaneB, aWorkLaneC, aInvestLaneC
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3484U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((aIndex + 3609U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2836U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4948U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4505U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 4298U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aCross, 54U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererE + RotL64(aIngress, 3U)) + 4739486756133131180U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 51U)) + 16089707555501328184U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 18U)) + 15310047330238536453U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 27U)) + 7901411596386834955U) + aPhaseFOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 43U)) + 4357555491060982163U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 11U)) + 15667085602825720102U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 56U)) + RotL64(aCarry, 51U)) + 8520635334382269253U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 23U)) + 1772509779231068315U;
            aOrbiterF = (aWandererC + RotL64(aCross, 29U)) + 15336170957886025677U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 13U)) + 8628770833489469980U) + aPhaseFOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 15469234024247246228U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 10796430900884288328U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10660110397012853289U;
            aOrbiterE = RotL64((aOrbiterE * 9140007610912037461U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11202284258711214794U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17509491802893182994U;
            aOrbiterG = RotL64((aOrbiterG * 9329107599972703671U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16212572740740103554U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2190030203761579226U;
            aOrbiterI = RotL64((aOrbiterI * 3101886685668871045U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 12014337082293041909U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3733531010807001506U;
            aOrbiterJ = RotL64((aOrbiterJ * 5797362244066062299U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7100994963061975529U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17837541162838600258U;
            aOrbiterH = RotL64((aOrbiterH * 8745987361678166553U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3311518938023146951U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7709505172646831553U;
            aOrbiterK = RotL64((aOrbiterK * 7121143171245765213U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4979968094554018443U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16822214821463034107U;
            aOrbiterC = RotL64((aOrbiterC * 8618262120451291765U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8376124175020587079U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11084586282092424876U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5835632742522563537U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7816368455027681621U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10893292019060642422U;
            aOrbiterA = RotL64((aOrbiterA * 3995821210667317677U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13602875505184178486U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5425735673005681983U;
            aOrbiterF = RotL64((aOrbiterF * 12667085597129312079U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5995385043278810987U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4739486756133131180U;
            aOrbiterB = RotL64((aOrbiterB * 15709273328685013399U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 26U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 21U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterG, 35U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 24U) + aOrbiterI) + RotL64(aOrbiterC, 11U));
            aWandererG = aWandererG + (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 50U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterB, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterK, 41U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererF = aWandererF + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 57U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneA
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneC backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9133U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 8758U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10727U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 10619U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8586U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9006U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 7005U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 58U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 19U)) + 1393781663398437180U) + aPhaseFOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 17414594746688585273U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 2823888497053071250U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 5U)) + 17032631958617884859U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 37U)) + 15222697630461125019U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 27U)) + 15737414920751551780U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 44U)) + 1357196111055783001U;
            aOrbiterB = (aWandererK + RotL64(aCross, 13U)) + 5315122321649251691U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 21U)) + 7893744655508595974U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 16721939414324611738U;
            aOrbiterK = (aWandererI + RotL64(aCross, 24U)) + 3444375866323610848U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1825716513674511632U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15582066843912467318U;
            aOrbiterI = RotL64((aOrbiterI * 12765146555943757373U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15673590949193923915U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13887365046280406413U;
            aOrbiterJ = RotL64((aOrbiterJ * 3169061375011420121U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12730414371734709356U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4819112390640821927U;
            aOrbiterD = RotL64((aOrbiterD * 8782547948627685451U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3089925954422937464U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7180179304678622530U;
            aOrbiterC = RotL64((aOrbiterC * 16118051565147747413U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 17030269962085008657U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6675917351883004046U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14134335325316949687U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12572022803491077491U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2801421744689267375U;
            aOrbiterH = RotL64((aOrbiterH * 315045745990934023U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4335148696780313055U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 12526298573395110141U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11276803410698178607U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6984239833558496091U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12195433952105336808U;
            aOrbiterK = RotL64((aOrbiterK * 8642600547427664495U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6392683095502982341U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18047201953488013325U;
            aOrbiterG = RotL64((aOrbiterG * 16151795290455603489U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15433458942878109208U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1700365768743794306U;
            aOrbiterF = RotL64((aOrbiterF * 16151638348775286903U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10951473638533187729U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1393781663398437180U;
            aOrbiterE = RotL64((aOrbiterE * 2661447713922232789U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 42U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterD, 53U));
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 37U)) + aOrbiterB) + aPhaseFWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 44U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterI, 11U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 35U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 22U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 27U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 18U) + aOrbiterE) + RotL64(aOrbiterI, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneB
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14490U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 13496U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13624U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14499U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15171U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 18U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererB + RotL64(aScatter, 37U)) + 12535417189990029950U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 48U)) + 6204401443676390273U;
            aOrbiterB = (aWandererD + RotL64(aCross, 5U)) + 869613505613154672U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 43U)) + 15053590879563855802U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 13338989605204591428U) + aPhaseFOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 18U)) + RotL64(aCarry, 3U)) + 18306470022403825392U;
            aOrbiterD = (aWandererF + RotL64(aCross, 53U)) + 1150696349434090218U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 13549541786420596437U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 39U)) + 14302878430259588461U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 29U)) + 4660437084477165225U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 51U)) + 1653628537860912069U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5594199757006711631U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11008472193138708891U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13645764762027798301U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3668516817279364310U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 128159531749679984U;
            aOrbiterI = RotL64((aOrbiterI * 4523246859249826987U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6378674346113979108U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11438762460659123362U;
            aOrbiterJ = RotL64((aOrbiterJ * 2733309638158283953U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10624263004446482910U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12546839706919241411U;
            aOrbiterD = RotL64((aOrbiterD * 11468326687628079347U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8466639576503293921U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5828694979857951504U;
            aOrbiterE = RotL64((aOrbiterE * 7835487310289634515U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16496305151014092976U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 589464613876410567U;
            aOrbiterA = RotL64((aOrbiterA * 13190816610718051897U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4168532743415647825U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15944887793736489375U;
            aOrbiterK = RotL64((aOrbiterK * 17273403561158196717U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11642456814106259483U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1609897693632334867U;
            aOrbiterH = RotL64((aOrbiterH * 12912773555616819941U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14950238412766325479U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11862438528287402255U;
            aOrbiterF = RotL64((aOrbiterF * 7635864312080265695U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5900629306795222263U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3221591991392500536U;
            aOrbiterG = RotL64((aOrbiterG * 7188525011266868855U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16938699391746264010U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 12535417189990029950U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18212319484142613215U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 28U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 26U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterK, 23U)) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 34U) + aOrbiterE) + RotL64(aOrbiterK, 13U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 39U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 5U));
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 51U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 14U) + aOrbiterG) + RotL64(aOrbiterH, 44U));
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 11U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 19U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 37U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aInvestLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18961U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((aIndex + 18465U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 20238U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18102U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneD[((aIndex + 17844U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 10U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererE + RotL64(aCross, 41U)) + 2617613537256538553U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aIngress, 60U)) + 16642868916835132715U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 3U)) + 10860291124337073254U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 47U)) + 6432511273906902472U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 11U)) + 7505375005848241910U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 51U)) + 11086616004678821329U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 47U)) + 3298830587569881951U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 9775143140064220979U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 6U)) + RotL64(aCarry, 13U)) + 4147601326580823120U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 43U)) + 12245920269898100415U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 53U)) + 8391940489176734499U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17876893379544668477U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 18301882058180370541U;
            aOrbiterB = RotL64((aOrbiterB * 16680384667098921309U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6869225862715140102U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15404118372589259800U;
            aOrbiterA = RotL64((aOrbiterA * 5766851935950389915U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17757381020518233814U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17677969146092374455U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3469432916562405063U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15783378556632870114U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5792858258663697864U;
            aOrbiterK = RotL64((aOrbiterK * 12008981883482080427U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11737803388202260296U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16001927091970715330U;
            aOrbiterC = RotL64((aOrbiterC * 3062030309852922061U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1749586939123286632U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6169421068855905938U;
            aOrbiterH = RotL64((aOrbiterH * 12374789910763348695U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10073586820719728062U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17744171227198661555U;
            aOrbiterI = RotL64((aOrbiterI * 10658375268803957647U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1149819647337612792U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7725598665625892006U;
            aOrbiterG = RotL64((aOrbiterG * 15097586655234391559U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13930096050550704122U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 3632241034947389647U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8442222389196610427U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17933893495867517142U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7888594392078082482U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9809847720610861237U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10805303827043372168U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2617613537256538553U;
            aOrbiterJ = RotL64((aOrbiterJ * 3940471942234248791U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterH, 30U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterE, 13U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 50U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 41U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterC, 27U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterK, 21U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 23U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterA, 60U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterG, 47U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 12U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aInvestLaneB
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25058U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((aIndex + 24607U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26334U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24207U)) & S_BLOCK1], 6U) ^ RotL64(aSnowLaneA[((aIndex + 25060U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererB + RotL64(aScatter, 50U)) + 17074147006464019918U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 19U)) + 10559516626129419928U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 47U)) + 13280363679503946221U;
            aOrbiterI = (aWandererC + RotL64(aCross, 35U)) + 17657115422132457413U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 43U)) + 13325837013304973008U;
            aOrbiterK = (aWandererF + RotL64(aCross, 11U)) + 3059707750486106037U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 23U)) + 4529045702503050852U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 10726578475550904292U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 14832537837996659885U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aScatter, 52U)) + RotL64(aCarry, 41U)) + 220094417441809246U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 21U)) + 15343130035105342194U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16592263353426409884U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15649290906447931918U;
            aOrbiterF = RotL64((aOrbiterF * 8405875177836650731U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11437410545843708269U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5859769136073011444U;
            aOrbiterK = RotL64((aOrbiterK * 1065016088086441107U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15188064100307340341U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4367466521843260049U;
            aOrbiterG = RotL64((aOrbiterG * 15916715854192820923U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8482617283860566845U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2585745804937342972U;
            aOrbiterD = RotL64((aOrbiterD * 8267269625632139809U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1687641344403425541U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13667916445979421400U;
            aOrbiterE = RotL64((aOrbiterE * 8191322670355590027U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7684258716388029228U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14764266202380443369U;
            aOrbiterB = RotL64((aOrbiterB * 1746254773647650741U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12685190466981675661U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9958374400222383893U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12696606920219838929U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1352584794098160330U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16057453941015251708U;
            aOrbiterC = RotL64((aOrbiterC * 6051546505117202495U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5642244742563733299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2946279435712646692U;
            aOrbiterH = RotL64((aOrbiterH * 3711867103848631343U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 17305358424001395035U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1831722001182742673U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13867284970939557547U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12354430852596737299U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17074147006464019918U;
            aOrbiterA = RotL64((aOrbiterA * 17316050599218057961U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 27U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterH, 44U));
            aWandererA = aWandererA + (((RotL64(aScatter, 42U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 21U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterK, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 13U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 46U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 10U) + aOrbiterA) + RotL64(aOrbiterK, 53U));
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 37U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 40U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32616U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 29377U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 30828U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30392U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29968U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 43U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aScatter, 3U)) + 3448371607470865612U;
            aOrbiterD = (aWandererI + RotL64(aCross, 6U)) + 3743742913651580573U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 21U)) + 13069491287948807280U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 27U)) + 16872779275586545632U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 17945792656755062795U) + aPhaseFOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 52U)) + RotL64(aCarry, 27U)) + 18199747196793731853U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 47U)) + 15953311878379809513U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 941268763494588338U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 11U)) + 10090221530365796809U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 41U)) + 8335698093307607001U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aScatter, 39U)) + 6147498804734306100U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5980246079567570090U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4152167624425912978U;
            aOrbiterF = RotL64((aOrbiterF * 10019421651535123573U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14990418790239735916U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3418668387496597219U;
            aOrbiterI = RotL64((aOrbiterI * 12814077238529863119U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4206650904177199425U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3905470780938996069U;
            aOrbiterK = RotL64((aOrbiterK * 16030122739273137005U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9968672788233080924U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 602258075661864866U;
            aOrbiterG = RotL64((aOrbiterG * 2615726693066300065U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17751667243048041383U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2414054413585296027U;
            aOrbiterB = RotL64((aOrbiterB * 1049512574773201893U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6523322402744047752U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6729901917767398779U;
            aOrbiterA = RotL64((aOrbiterA * 8039939871405367139U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11460169185076814539U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7559640379553110573U;
            aOrbiterH = RotL64((aOrbiterH * 9864654321914036135U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17271150091827475028U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3541809324556914646U;
            aOrbiterE = RotL64((aOrbiterE * 12655168871428868639U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10332471447306597185U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12580133010006951091U;
            aOrbiterC = RotL64((aOrbiterC * 1159183486084705865U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17333553613777910945U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14179392055698682109U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17675559451285279251U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3996830751779338356U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3448371607470865612U;
            aOrbiterJ = RotL64((aOrbiterJ * 5375529914102609947U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterB, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 44U) + aOrbiterE) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 27U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterC, 3U));
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterI, 60U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 5U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 34U) + RotL64(aOrbiterD, 13U)) + aOrbiterG) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 19U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 40U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7339U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 533U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 195U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1466U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6178U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6861U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 479672811032092393U) + aPhaseGOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 5U)) + 18061121631394564425U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 56U)) + RotL64(aCarry, 11U)) + 14237400452740566065U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 19U)) + 6723123812257706134U) + aPhaseGOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 4247997188026499248U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 1939107415066134869U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3912640123546395979U;
            aOrbiterD = RotL64((aOrbiterD * 9779626695085572877U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8295478436553964298U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3218960600711526885U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15443507655470278069U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 5874096203353388890U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10294536533673023358U;
            aOrbiterI = RotL64((aOrbiterI * 15561710414949058923U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11268561953904130747U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16693201256788898423U;
            aOrbiterC = RotL64((aOrbiterC * 16291987237693567209U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7550969634681894654U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 9501647424602245869U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11265865222096866605U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterB, 21U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 11U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterH, 48U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 34U) + aOrbiterC) + RotL64(aOrbiterI, 37U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10584U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 12141U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15464U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12864U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12382U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14220U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 4U)) + RotL64(aCarry, 3U)) + 12615321415808640429U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 15712784676459931207U) + aPhaseGOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 11013335427004930046U) + aPhaseGOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aCross, 37U)) + 8298733856304768806U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 27U)) + 6207732959150824216U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9769864876127544038U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10782181918651152563U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16814396040248716483U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5790454015845620939U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15606578025386733803U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7079287329365566355U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5522352539991175304U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5993355818572869649U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15221467311057431139U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10864534396947622047U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12090053126235913528U;
            aOrbiterI = RotL64((aOrbiterI * 7250801471645972261U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14191181677234981396U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2258570108233924592U;
            aOrbiterD = RotL64((aOrbiterD * 8307541155393855209U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 27U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 14U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 46U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 40U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21294U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 24128U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 22791U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20887U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17622U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 19209U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 14U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 1087148170018530502U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 29U)) + 15530846874509311414U) + aPhaseGOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 12U)) + RotL64(aCarry, 53U)) + 16987358651515511212U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 12504143181007924259U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 43U)) + 393322117322732418U) + aPhaseGOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14325937299241887166U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9395262907017475742U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3442643798173589117U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13658510441418344769U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6410754322737005336U;
            aOrbiterE = RotL64((aOrbiterE * 6932217611373076391U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9257290738538818434U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7489828960857692286U;
            aOrbiterF = RotL64((aOrbiterF * 16519674788777989043U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4118778591214588387U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 16619215231168796563U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14876884956536265157U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11326283811003573430U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 1865401866017614604U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8378326058282460073U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + aPhaseGWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 51U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterD, 43U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 54U) + aOrbiterI) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 34U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30702U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 28411U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25281U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25626U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26343U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 31963U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 13854738573712660276U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 28U)) + RotL64(aCarry, 5U)) + 16835460633412286294U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 13U)) + 6785859293758091931U) + aPhaseGOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 126317283127992659U) + aPhaseGOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 41U)) + 7568963536291415413U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12294016745653004819U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 18269588932920281147U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9031152619272892317U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5872406424994751026U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7764434758831474129U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3772146788188420071U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 4804168969415573371U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 959601763507651280U;
            aOrbiterI = RotL64((aOrbiterI * 4647396592804833217U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9257644462479293048U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14332699366894494579U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8829304078930625541U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10487012596470786004U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 612729229562321440U;
            aOrbiterC = RotL64((aOrbiterC * 11380387280507726003U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 4U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 27U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 37U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 51U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 4U) + aOrbiterI) + RotL64(aOrbiterJ, 4U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererK, 48U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5638U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 3898U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 7394U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4601U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5651U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 3049U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 28U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererA + RotL64(aCross, 28U)) + 1866656689936219099U) + aPhaseHOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 2312314528139448289U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 3554037526469185237U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 405707755060974111U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 11U)) + 1862976326004007697U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12992483065443288263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3793854946371595197U;
            aOrbiterH = RotL64((aOrbiterH * 1819119223110966487U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4244007978867369382U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10280867500312580308U;
            aOrbiterA = RotL64((aOrbiterA * 13729899124177931289U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 472563452959164242U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12041770406895816553U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17811798500132002631U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6118634015704900486U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13637107920449233307U;
            aOrbiterJ = RotL64((aOrbiterJ * 17712028184714868053U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16673735670669318830U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8602681273646630496U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6995213887710749241U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 42U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 29U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterH, 3U));
            aWandererI = aWandererI + (((RotL64(aScatter, 22U) + RotL64(aOrbiterA, 52U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 21U)) + aPhaseHWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 39U)) + aOrbiterI) + aPhaseHWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11336U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((aIndex + 13686U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 8384U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11866U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14450U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 12495U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 48U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 12046647397183218524U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 41U)) + 2760779375026461991U) + aPhaseHOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 41U)) + 13735454443176855650U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 58U)) + 4370377000586647724U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 14566322384189969094U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5056565959818422786U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8795403810686579209U;
            aOrbiterG = RotL64((aOrbiterG * 11205867337479457471U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9625947666256011567U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1703669290934254701U;
            aOrbiterE = RotL64((aOrbiterE * 5763881345676123583U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 6664070663184147951U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2104148316797553431U;
            aOrbiterF = RotL64((aOrbiterF * 12887842067180975983U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1197910004222596145U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9922977170060903197U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13047828062605568603U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2048376210852567829U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 12568990647075931409U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9860242601194210927U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 36U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + aPhaseHWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 54U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterF, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22444U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 17883U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 24306U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16438U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22025U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24214U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 35U)) ^ (RotL64(aCross, 4U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 47U)) + 5088525177670191619U) + aPhaseHOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 9966456257813932112U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 7707646574027146307U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 13U)) + 75480203757681173U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 56U)) + RotL64(aCarry, 5U)) + 384659134071835163U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 3158769775373307778U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17360830943513941272U;
            aOrbiterK = RotL64((aOrbiterK * 9986023786908098621U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5317278822721604586U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1371427105215954781U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10956603063464438611U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3162710551223553423U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5332921933853550756U;
            aOrbiterJ = RotL64((aOrbiterJ * 11709546145149357887U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10572462410297815854U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10234389605554817892U;
            aOrbiterC = RotL64((aOrbiterC * 2130374833440291193U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 13421365517991380605U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 10186643614984034083U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8554471709467808453U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterK, 5U)) + aPhaseHWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterA, 26U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 51U)) + aOrbiterA) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25463U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((aIndex + 28890U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28598U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29969U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29496U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 28221U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 10U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 10812151398716051703U) + aPhaseHOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aIngress, 52U)) + RotL64(aCarry, 23U)) + 18202551453336003710U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aPrevious, 35U)) + 9434410809101973752U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 12955829998028534045U;
            aOrbiterK = (aWandererD + RotL64(aCross, 23U)) + 12271740641929640181U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14009351527014534752U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4316296955679133450U;
            aOrbiterE = RotL64((aOrbiterE * 11582128345511775161U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16473324966997442872U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15735123324965019802U;
            aOrbiterA = RotL64((aOrbiterA * 5624078184997601019U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17656375090484080236U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16066325053456055298U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17912970706985130327U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12908968778503516903U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12761433987676836197U;
            aOrbiterG = RotL64((aOrbiterG * 1023329467480907925U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12737513138040664509U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14535795767570998392U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15560519667062222269U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 40U) + aOrbiterK) + RotL64(aOrbiterH, 19U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 60U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 51U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + aPhaseHWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererE, 24U);
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
