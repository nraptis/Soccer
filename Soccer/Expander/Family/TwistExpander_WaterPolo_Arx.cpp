#include "TwistExpander_WaterPolo_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_WaterPolo_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x985EA5B66FC51F9BULL + 0xCAAD0E7083967B54ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC22760295DB67273ULL + 0xBC3A77016D4F143AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD3954C9C19ACAE55ULL + 0xAFEF9F78FB4EF72AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8B9DF89B10058A77ULL + 0xACA9A48BCB933157ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD99966999ADED8D1ULL + 0xEFC436C775660792ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x85110375F0E287E9ULL + 0xE218E55993BDFCE8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFB9131E6645AA4FFULL + 0xA4A64EB926697DEEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE5B51A7C52A6E39FULL + 0xEE40EA7A6743A252ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE3B780118D445E11ULL + 0xDCE9228F9C020003ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCE3FC040EF255E8BULL + 0xF892155D1AEA21B5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC132B27AFB540BDDULL + 0xB2722657FC61A325ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x835C7FFEC0DED65FULL + 0xDAA509FBF7352FFAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB716F235D2EE14CDULL + 0x9F443C79D3C539F0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA5A202F7052C0B39ULL + 0xCE7403036DF5E445ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB68013F818B0A149ULL + 0xFA21F2B4543F25E9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x890D63C8BB5DC9BBULL + 0xA5E86B14E1663264ULL);
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
            aIngress = RotL64(mSource[((aIndex + 2960U)) & S_BLOCK1], 58U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 4394U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 5204U)) & S_BLOCK1], 38U) ^ RotL64(mSource[((aIndex + 3719U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = ((aWandererB + RotL64(aCross, 18U)) + 14249093584376402677U) + aNonceWordO;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 57U)) + 8756965951816492264U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 51U)) + 11221139480258176330U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 13U)) + 17218894445564194851U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 5U)) + 8064642692524949490U) + aNonceWordH;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 5822093203710704646U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aPrevious, 21U)) + 3217799620158102238U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 2613757677892120843U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 47U)) + 13647481499551657237U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 43U)) + 3545714196663685016U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 10U)) + RotL64(aCarry, 53U)) + 9735422670576621521U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3911046580637583767U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9315984027042049203U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 12568550776487242469U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8926367674641729058U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11035347490524961446U;
            aOrbiterD = RotL64((aOrbiterD * 10948288997163592463U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10748158733051120339U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2467801787989056455U;
            aOrbiterG = RotL64((aOrbiterG * 12621934274702358977U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9244415080474351390U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8517784887959492079U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17022899813765884147U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8409307332803038455U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11043806021873232950U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8294888329708842989U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17512395828450251457U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 16849067939795823992U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 9361991804481514337U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17541946638063238056U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11430501673960586718U;
            aOrbiterH = RotL64((aOrbiterH * 15074409630605450091U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 78307505705383302U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4834528975263832983U;
            aOrbiterJ = RotL64((aOrbiterJ * 17245673681686752861U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9647985402149698269U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6610247710757518931U;
            aOrbiterE = RotL64((aOrbiterE * 8672486173272686859U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2706696306041774372U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 9519896513600816252U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 7468605169665549731U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14647351223431646222U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14249093584376402677U;
            aOrbiterK = RotL64((aOrbiterK * 8296105266618697281U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 10U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 46U) + RotL64(aOrbiterA, 43U)) + aOrbiterC) + aNonceWordE);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterH, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 6U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterD, 41U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 43U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterB, 53U)) + aNonceWordA) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 36U) + RotL64(aOrbiterK, 22U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 11U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 10583U)) & S_BLOCK1], 12U) ^ RotL64(mSource[((aIndex + 7659U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5479U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 5654U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 28U) ^ RotL64(aCarry, 43U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (aWandererC + RotL64(aCross, 60U)) + 6069475454765660321U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 39U)) + 11483704742497268068U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 19U)) + 11055697447388986418U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 41U)) + 10897095046039997004U;
            aOrbiterH = (aWandererB + RotL64(aCross, 43U)) + 4731637118230457840U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 13855839187084986751U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 56U)) + 5328208115460188239U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 12479538544291412985U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 53U)) + 10740165998792608231U) + aNonceWordO;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 6492798157284955373U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 13U)) + 13056825957483891921U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2068184064919194657U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5656302738780746294U;
            aOrbiterI = RotL64((aOrbiterI * 16493021179127646345U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11193756120230763294U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17306750816837208999U;
            aOrbiterA = RotL64((aOrbiterA * 7949360041241439741U), 41U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 12952818800389361804U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15380412293642628312U;
            aOrbiterG = RotL64((aOrbiterG * 2914662289178925547U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7706090204767242996U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14598802276412649570U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 4821408736292041399U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17819762117328075515U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6481384240915075101U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4836701121865783029U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 754936290510338717U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15510875946573720154U;
            aOrbiterH = RotL64((aOrbiterH * 2994718968852184303U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9245381722813944586U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2629847912019726214U;
            aOrbiterC = RotL64((aOrbiterC * 6718795794951106961U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3909987749797113773U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9277056074757335265U;
            aOrbiterK = RotL64((aOrbiterK * 11580847505996697115U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12577180954515966707U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9144513680789115458U;
            aOrbiterE = RotL64((aOrbiterE * 8880777678193004979U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1544232962956974411U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2658275904714859636U;
            aOrbiterD = RotL64((aOrbiterD * 1926083316365175327U), 11U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 5733515391293514025U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6069475454765660321U;
            aOrbiterJ = RotL64((aOrbiterJ * 9627476106108146391U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 34U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterJ, 51U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 39U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + aNonceWordB);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 30U)) + aOrbiterH) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + aNonceWordG) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 13U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterA, 5U));
            aWandererK = aWandererK + ((RotL64(aIngress, 46U) + RotL64(aOrbiterG, 22U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 12332U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 12301U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 14143U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11126U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 39U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererK + RotL64(aPrevious, 51U)) + 4179952823252098240U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 18U)) + 3745613452332101749U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 2955689793395307176U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 5639060180251322019U) + aNonceWordK;
            aOrbiterB = (aWandererC + RotL64(aIngress, 3U)) + 7901969163853586463U;
            aOrbiterA = (aWandererB + RotL64(aCross, 13U)) + 2242166787816318119U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 11U)) + 5239936443960750064U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 29U)) + 13939136954732185558U) + aNonceWordO;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 17058884136712717463U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 26U)) + 18148618660054585941U) + aNonceWordN;
            aOrbiterH = ((aWandererF + RotL64(aCross, 47U)) + 7022023484530327814U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7722084537340095637U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11764151879690934182U;
            aOrbiterG = RotL64((aOrbiterG * 12264384877711365655U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 16412785901758144708U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9666718667728274824U;
            aOrbiterA = RotL64((aOrbiterA * 10865799822751771795U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4307127540152109364U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2457646804702647606U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6340030928007058595U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3179394870088602208U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 504977947273774249U;
            aOrbiterC = RotL64((aOrbiterC * 16190282058883481551U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16182729401018310837U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7110817020445860609U;
            aOrbiterB = RotL64((aOrbiterB * 13371352088428584087U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12960656706837391973U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7103806893724395904U;
            aOrbiterI = RotL64((aOrbiterI * 14365984439655979791U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1248300178080633527U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7195473175424961337U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 4633558992739305045U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 13007951568242991449U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10296811247653636372U;
            aOrbiterF = RotL64((aOrbiterF * 16469682651380549395U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13922797949001028335U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16773545425463040155U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10639282630227832397U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 2888887140296117803U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10279517418046269817U;
            aOrbiterK = RotL64((aOrbiterK * 8600355360339461535U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17303373436784809093U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 4179952823252098240U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3675754609699406437U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 18U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterB, 34U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterI, 53U)) + aOrbiterC) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ) + aNonceWordB) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 21U)) + aOrbiterI) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterH, 39U)) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 37U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 51U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aIngress, 24U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 29U));
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 26U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 20U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16666U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17386U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 16961U)) & S_BLOCK1], 54U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 21593U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19303U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (aWandererC + RotL64(aIngress, 6U)) + 5568146815535263910U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 3U)) + 7736084960873834666U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 1336413621817562093U) + aNonceWordB;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 11U)) + 5218462026934984692U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 41U)) + 7048890985969555935U) + aNonceWordD;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 43U)) + 13415955213864702118U) + aNonceWordO;
            aOrbiterA = (aWandererA + RotL64(aIngress, 29U)) + 5657023257021528548U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 14338310943137497116U;
            aOrbiterG = ((((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 12305161641833950473U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (aWandererK + RotL64(aIngress, 24U)) + 14514226578370459131U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 53U)) + 12692904083266024340U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11012959130001327964U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7106471380403489078U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 515626559384817223U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3718101961355280891U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13364192077222322664U;
            aOrbiterD = RotL64((aOrbiterD * 1411328915372590283U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6720867800318913440U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14497243926965866546U;
            aOrbiterF = RotL64((aOrbiterF * 13595058589060114653U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5789056168233262435U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14438482587495779937U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 10593535547917767263U), 5U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 313917798940179945U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15241845511889502917U;
            aOrbiterJ = RotL64((aOrbiterJ * 16483477103771326107U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3591957424821693032U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1559050939014453558U;
            aOrbiterA = RotL64((aOrbiterA * 17933346117866604725U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 15340590914441451383U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5538037287390050110U;
            aOrbiterH = RotL64((aOrbiterH * 4082576643144951473U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4151270491894969214U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 263593701314144898U;
            aOrbiterB = RotL64((aOrbiterB * 10372046955804512457U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9025145270653080646U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6867950904094870056U;
            aOrbiterC = RotL64((aOrbiterC * 9975247022340627751U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 3183454301841252109U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3054904157641290615U;
            aOrbiterE = RotL64((aOrbiterE * 4092317552439599475U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1768555574434776135U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5568146815535263910U;
            aOrbiterG = RotL64((aOrbiterG * 12466957001078663927U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 36U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 42U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 6U)) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 50U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterB, 53U));
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterC, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + aNonceWordL);
            aWandererG = aWandererG + ((((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterF, 41U)) + aNonceWordP) + aWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 27U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 56U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterD, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 14U) + RotL64(aOrbiterI, 51U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 22997U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 25268U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(pSnow[((aIndex + 27133U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 22344U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23057U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 22164U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = (aWandererI + RotL64(aCross, 36U)) + 898812731947995389U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 19U)) + 8677347622525527167U) + aNonceWordP;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 23U)) + 770321564027567654U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 3U)) + 11020474858081526395U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 44U)) + RotL64(aCarry, 19U)) + 17289793580414993470U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 13U)) + 10111912559295118444U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 21U)) + 8083622125544542011U;
            aOrbiterH = (aWandererC + RotL64(aCross, 57U)) + 7149858558922988240U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 5919683821379905699U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 29U)) + 6860902846079238714U) + aNonceWordB;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 39U)) + 15083517836867542075U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 14852868368708376381U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9860233289028878323U;
            aOrbiterI = RotL64((aOrbiterI * 13418143547952204667U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 772406119079116272U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7971141501337627589U;
            aOrbiterC = RotL64((aOrbiterC * 10168120622976358617U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8478568022896691911U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4027604850785607101U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4826627523578901467U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17199331557841535430U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7515957656979776361U;
            aOrbiterB = RotL64((aOrbiterB * 5468950152869656599U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17138249294921502391U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16236812863923234668U;
            aOrbiterE = RotL64((aOrbiterE * 2925542836624164807U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16941524155859123682U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 11240343728857342866U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 7281012444214294659U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15163914964139858328U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6673576554415729652U;
            aOrbiterF = RotL64((aOrbiterF * 1558880328574736975U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5399050402101642989U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 11806006719060024615U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 15782156615926092159U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9812148913932011655U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4737919734590584193U;
            aOrbiterK = RotL64((aOrbiterK * 2739737604370936959U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3415477403346468057U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5922725868927615919U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12390148483052777871U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17435294951520465659U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 898812731947995389U;
            aOrbiterD = RotL64((aOrbiterD * 17248379279729365007U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 28U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterG, 13U)) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 24U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 54U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterI, 39U)) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 35U));
            aWandererB = aWandererB + (((RotL64(aScatter, 58U) + RotL64(aOrbiterH, 22U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterK, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterD, 37U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 28373U)) & S_BLOCK1], 34U) ^ RotL64(pSnow[((aIndex + 28143U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 28005U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30786U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32026U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 31073U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 6U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (aWandererF + RotL64(aPrevious, 28U)) + 6916817163240024692U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 57U)) + 14554930751292077817U) + aNonceWordL;
            aOrbiterE = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 1098305064484336101U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 41U)) + 12192821172420471527U) + aNonceWordO;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 11U)) + 2435134991707318845U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 5U)) + 1896745368738512624U) + aNonceWordF;
            aOrbiterG = (aWandererJ + RotL64(aCross, 35U)) + 1114996424222923873U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 9839135798371512656U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 46U)) + RotL64(aCarry, 29U)) + 8037967239603177043U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 53U)) + 15185468738487237432U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 39U)) + 4912098316394854543U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13142688607850380888U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4507379759608945839U;
            aOrbiterE = RotL64((aOrbiterE * 2989332387754215967U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7299006009652289342U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5390655277207053627U;
            aOrbiterB = RotL64((aOrbiterB * 10973744708856143715U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6744737023577785725U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15539737698867067285U;
            aOrbiterH = RotL64((aOrbiterH * 4686092035261336911U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13329866734681377952U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13284937458969166257U;
            aOrbiterC = RotL64((aOrbiterC * 3965985432462699445U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8695002088915702168U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3858059421620839286U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9559783727301092937U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6609163873243179836U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 9416165620556710540U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 240385043740268229U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1578449067529000433U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 14309000104419489303U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7599078306153684729U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 15785180680737461320U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10099222679918382021U;
            aOrbiterI = RotL64((aOrbiterI * 2012232597046182581U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10666287769220108179U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13648647399222807034U;
            aOrbiterK = RotL64((aOrbiterK * 10772381733103127201U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9292207828896796810U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9155130791347443553U;
            aOrbiterF = RotL64((aOrbiterF * 16838229790655977057U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11334395119119245556U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6916817163240024692U;
            aOrbiterA = RotL64((aOrbiterA * 9640906826978028183U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 48U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 47U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aCross, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 38U) + aOrbiterH) + RotL64(aOrbiterE, 35U)) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterK, 28U)) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterF, 53U)) + aOrbiterE) + aNonceWordG);
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterB, 38U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_WaterPolo_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9EED0EB82AEC7365ULL + 0xFAAA255F5EFF2A86ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE390E91DE51D096DULL + 0xD5A363F3C30B36DAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x923F9F4E67B1D891ULL + 0xB95FFFDDDA98AA02ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD4FDB901A0AC2AE3ULL + 0xF10894336E2F29CEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9B95799598E90DB3ULL + 0xABB20B38391404AFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC45579345736F877ULL + 0xA5578147205D31F6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x93DD828F48368345ULL + 0x90D8D51AB528A891ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA7B8AC5AB9C67913ULL + 0xED229B591D305AC4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD18A177F651C9A87ULL + 0x969D463DC72390A7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFBF0A494F2EB94BBULL + 0xE7C1C494886DD565ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFFEF954946BAEAABULL + 0x8108D808A66C4D66ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA8491D1031D34743ULL + 0xEBD81D4B2382B072ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8D2B36757359E72FULL + 0xC432E9EF89C30E14ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC6A7051ABE334CE1ULL + 0xDBD3B96056A94F1FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8DB71A118C097A29ULL + 0x964B3EA7EE1A161DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC3A5AECA56AE6E97ULL + 0x90A68E9F4894BEF4ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 6123U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((aIndex + 4812U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4446U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneD[((aIndex + 8059U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = (((aWandererK + RotL64(aScatter, 60U)) + RotL64(aCarry, 39U)) + 9914837590440975587U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aIngress, 5U)) + 6706125076401958051U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 23U)) + 16570817772679258409U) + aNonceWordD;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 19U)) + 6843705658115186948U) + aNonceWordI;
            aOrbiterB = (aWandererF + RotL64(aScatter, 37U)) + 16099930446791572351U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 5420550009556030459U) + aNonceWordN;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 5729549069420177477U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 28U)) + 15590601126188675834U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 51U)) + 13044027390998620029U) + aNonceWordL;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 11068338135659636772U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6584988841809544332U;
            aOrbiterI = RotL64((aOrbiterI * 1683336180438945439U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8516813219883915404U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10647314042912492785U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15559481057047148785U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 201691689889605304U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15512161798401184003U;
            aOrbiterB = RotL64((aOrbiterB * 11473219183982564709U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3883760518944464145U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13861805129175491145U;
            aOrbiterD = RotL64((aOrbiterD * 17194438894492581181U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12019138626550801486U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13030350224959652248U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11724200983306280107U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2643807255422544248U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4127143302485631794U;
            aOrbiterK = RotL64((aOrbiterK * 5441038881111578487U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 14602951930809633069U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4555737199162278494U;
            aOrbiterH = RotL64((aOrbiterH * 12415825635220991865U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 6343143902997169834U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 10404783711336491985U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 6235474458879439079U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 7406959231434835393U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6684368109277850196U;
            aOrbiterE = RotL64((aOrbiterE * 8760360417572331159U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 6U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterI, 13U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 58U)) + aOrbiterA) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterD, 27U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 46U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterG, 5U));
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12294U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((aIndex + 14288U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 15410U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15553U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((aIndex + 15190U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = ((aWandererA + RotL64(aIngress, 47U)) + 8604208734152026945U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aScatter, 12U)) + RotL64(aCarry, 27U)) + 1374329953253889829U) + aNonceWordK;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 23U)) + 5779278910548228339U) + aNonceWordN;
            aOrbiterD = (((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 17670451230882805140U) + aNonceWordF;
            aOrbiterB = (aWandererB + RotL64(aScatter, 35U)) + 8193848740764866860U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 53U)) + 15801168428145650104U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 51U)) + 2584718176087499066U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aWandererD + RotL64(aCross, 27U)) + 14950366247822737997U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 39U)) + 9779293225265670135U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8688968319288372383U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13665723186950342601U;
            aOrbiterJ = RotL64((aOrbiterJ * 292035540396910837U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9395428688359973510U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2152719218018108418U;
            aOrbiterG = RotL64((aOrbiterG * 15271961483518392671U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1350324137411377992U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 8729317951386057921U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 6008790836417785083U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6317310451893678411U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10175620379041384281U;
            aOrbiterD = RotL64((aOrbiterD * 14079679617394330781U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1203082119358827708U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 523869107818193101U;
            aOrbiterI = RotL64((aOrbiterI * 4629501113595689157U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4028324959540432983U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15447631947468213912U;
            aOrbiterE = RotL64((aOrbiterE * 6037306615787729185U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14225888694733041031U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11925000696281947629U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4337022940520411253U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15015531024930608745U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16752579225076943550U;
            aOrbiterH = RotL64((aOrbiterH * 15551083683579981439U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2432733494869267901U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10103430321388601485U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18372919379972432569U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 38U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterE, 53U));
            aWandererE = aWandererE + ((RotL64(aCross, 12U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 57U)) + aNonceWordC);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 28U)) + aOrbiterC) + aNonceWordA) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 13U)) + aOrbiterH) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterD, 39U)) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20321U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((aIndex + 23442U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20590U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16554U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 23731U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 23456U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 34U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 30U)) + 7790166497945719700U;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 57U)) + 7136208896846119188U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 5U)) + 12123156943355100886U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 5095546037880875199U) + aNonceWordG;
            aOrbiterB = (((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 17642705393916765992U) + aNonceWordN;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 23U)) + 9918479837334416990U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 37U)) + 4890009823843176466U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 10U)) + 17652590786213674124U) + aNonceWordJ;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 41U)) + 870002527644696135U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12545429703552643682U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5310272867406182581U;
            aOrbiterH = RotL64((aOrbiterH * 10420003334833925011U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3264719049050179440U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 1967241238180278937U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 13004319774269457957U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 773883832927040736U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12766817190261232485U;
            aOrbiterA = RotL64((aOrbiterA * 7448864556802318431U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 260069382395598265U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15462103891287350123U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 5029268763635635753U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 4072032867513289827U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17153061419083897076U;
            aOrbiterG = RotL64((aOrbiterG * 11934532169271718913U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6207264270332656966U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18048064697837314947U;
            aOrbiterE = RotL64((aOrbiterE * 13632594619404208489U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14484617445340272026U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16160443600497652026U;
            aOrbiterB = RotL64((aOrbiterB * 1988599349457831597U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5873314228291583482U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16418290052752166515U;
            aOrbiterK = RotL64((aOrbiterK * 18270363452003213317U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9158414409987627714U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8205937960146492168U;
            aOrbiterF = RotL64((aOrbiterF * 14008398661393344261U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 20U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterF, 51U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 30U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterK, 56U)) + aNonceWordC);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 37U)) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + aNonceWordB);
            aWandererD = aWandererD + ((RotL64(aIngress, 6U) + RotL64(aOrbiterE, 3U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterC, 43U));
            aWandererB = aWandererB + ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 14U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 37U)) + aOrbiterB) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26961U)) & S_BLOCK1], 28U) ^ RotL64(aFireLaneC[((aIndex + 27468U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 29483U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25910U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27138U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 30244U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (aWandererH + RotL64(aPrevious, 29U)) + 8988572360732005217U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 51U)) + 17889613225105985335U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 15563478320513948626U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 19U)) + 3441351228410524816U) + aNonceWordJ;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 56U)) + RotL64(aCarry, 21U)) + 4425592689451435346U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aScatter, 35U)) + 12733160231627305928U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 47U)) + 3574152157304607854U) + aNonceWordK;
            aOrbiterF = ((aWandererD + RotL64(aCross, 5U)) + 15167631896729808783U) + aNonceWordM;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 10U)) + RotL64(aCarry, 11U)) + 15822667973915417055U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17181685481076577637U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9979204751408873468U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 8244434774754786565U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1334240485667164762U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9190066751460137016U;
            aOrbiterJ = RotL64((aOrbiterJ * 14585141844653660363U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15465215829109246336U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2305208282453624419U;
            aOrbiterB = RotL64((aOrbiterB * 10257861974108363283U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16951510027310993926U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11117938943423526901U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 7805486716716924787U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12461379120662979432U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11719697049048823897U;
            aOrbiterF = RotL64((aOrbiterF * 14880996802304818757U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6843357278142933570U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12727898578324702374U;
            aOrbiterD = RotL64((aOrbiterD * 9786435451654365097U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 18127999660067652233U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11754709060558683082U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 12798744012150745847U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16940151146420516184U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12924950783056761895U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8898170377271926745U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14829713915929878471U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 840466047621042565U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10748511630509529489U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterG, 57U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 22U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 35U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 50U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + aNonceWordD);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 3U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 13U)) + aOrbiterG) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterC, 50U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_WaterPolo_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFD738C2214F36A89ULL + 0x8727456A6878B7FFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDC5BD867699441B9ULL + 0xD6D6D711194D2059ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFD7E80C826BC1A69ULL + 0xC72B1357001E1A33ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x99CEABA629F2EFE9ULL + 0xC179AF832E69D13DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC19B6516D6074D0FULL + 0x9805E5C8F4CF78EBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x83D8624D509FCD99ULL + 0xD4735830F7651673ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB6025BADA3FFD051ULL + 0xBEB114AC2CAC999FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9C137AC2163B58DBULL + 0xF6D7579FB7026E12ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8930EB219E3CC4ADULL + 0xC6BCF18C514F4FC5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF55F4A9170545E75ULL + 0x9F83F32A75D59B19ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD78B02A9C18F2D79ULL + 0xD4C2FFE9AD2B836FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEE4F72CB6622C4D1ULL + 0xDA274273EC0394C9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCDD8FC3CF8ED9ECDULL + 0xD3AA4F6B9C0F2FACULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x94C55F297A03C0BDULL + 0xDB9EA91C2102CF1BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x876CF7903CEA4EA1ULL + 0xB7EFEE4E08B41EA6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9049E8CFED0C2CE1ULL + 0x8BF1D88C9651463FULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7349U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 1910U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 3281U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5492U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7742U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 11U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 16462052553719977502U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 12337064059566619581U) + aNonceWordM;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 29U)) + 15801005007094515447U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 58U)) + RotL64(aCarry, 11U)) + 8228706742665081656U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 19U)) + 11006723027845190869U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18173765337829177450U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 530215083653542558U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8938680024265564887U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6608611827035564511U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2246051826221626809U;
            aOrbiterJ = RotL64((aOrbiterJ * 6333352641495253539U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5228575308895381421U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10999213210689606857U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5467601259546342925U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 3773371037240485696U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8887985779436152504U;
            aOrbiterK = RotL64((aOrbiterK * 698713082830739677U), 37U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 11150566414723818350U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 8336366151003049546U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 9033771197242493699U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 3U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + aNonceWordD);
            aWandererK = aWandererK + (((((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 47U)) + aNonceWordH) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 48U) + aOrbiterJ) + RotL64(aOrbiterE, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterH, 20U)) + RotL64(aCarry, 35U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9020U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 13540U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15955U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10701U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10895U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 14745U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 9023059520606551446U) + aNonceWordF;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 662441755115638133U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 18U)) + RotL64(aCarry, 13U)) + 16957253361196144712U) + aNonceWordD;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 27U)) + 7840955025765308605U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (((aWandererE + RotL64(aCross, 3U)) + 346855809270395799U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16099139781586668343U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 3706457327118322098U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 7810030620470889591U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12166825885547622870U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 7792658665720344200U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 16305542632794270697U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7128477606152986326U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 11116533962780290084U) ^ aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 11993485572912492297U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10443889548568288532U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 4402387036946561017U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9032964741841833277U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13002706161178447654U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 13929727277530310708U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 7005639090871200285U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 3U)) + aOrbiterH);
            aWandererE = aWandererE + (((((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 12U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordO) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + aNonceWordH);
            aWandererA = aWandererA + ((((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 37U)) + aOrbiterB) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21515U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((aIndex + 18104U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 21001U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22324U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17040U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 21073U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 39U) + RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 4U)) + RotL64(aCarry, 3U)) + 15316464782468770057U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 47U)) + 6642872057476351588U) + aNonceWordL;
            aOrbiterC = ((((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 660732654689529192U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 7235418086884000655U) + aNonceWordB;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 13U)) + 14784518476694580493U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12222433977933449375U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8573001207708329927U;
            aOrbiterC = RotL64((aOrbiterC * 17771120145431297541U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16035256260815013172U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15767726974121910203U;
            aOrbiterK = RotL64((aOrbiterK * 719060452537759331U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 17712217935322939971U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13488963456923357159U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 16785285630840310405U), 5U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 10222949131965611079U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1495561412321657209U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9706305581868526265U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16156530750584361434U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7773792489045606309U;
            aOrbiterE = RotL64((aOrbiterE * 10730624207715601393U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterH, 48U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterH, 40U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 28U) + aOrbiterH) + RotL64(aOrbiterC, 57U)) + aWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 57U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + aNonceWordM);
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterI, 11U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27060U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((aIndex + 32712U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28230U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26111U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28651U)) & S_BLOCK1], 40U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26106U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27049U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (aWandererF + RotL64(aScatter, 56U)) + 3650233661228036955U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 11607036400067735729U) + aNonceWordG;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 3899614406903883035U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 8159156925629965143U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 43U)) + 7148903913967261270U) + aNonceWordJ;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9161665622287517848U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2981535013474059469U;
            aOrbiterG = RotL64((aOrbiterG * 4434815231517266013U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 15812469008200319549U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 14687469489893270300U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14142363399696670451U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6025209349511417063U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 12964750392311112676U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12955480283032701843U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6572355895765394340U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 3542300121890027981U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 11201491178181273935U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6477175684045398359U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1081388388827929314U;
            aOrbiterI = RotL64((aOrbiterI * 8752188637514143529U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 54U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 27U)) + aNonceWordM) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterE, 39U)) + aNonceWordE);
            aWandererF = aWandererF + ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 53U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 50U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + aNonceWordA) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 20U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_WaterPolo_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9C38F21D6DA66DC1ULL + 0x8B1B960A990BE131ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xACD57B66C830BD21ULL + 0xA60D53C411B617B1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD43C5819F5484E75ULL + 0x986BC65B7442BCD5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9467E5B45A7FBFC1ULL + 0xEE0F0C6EDA97799AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC0EC8BE1E6FED3ABULL + 0xD970627C5C8605EEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x97981FE3160D7CE1ULL + 0xB1CC1657369ADB4CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC6288BC2EC88518FULL + 0xA517EB9E1B54EDBBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBB8B1B4CAEFFBF49ULL + 0xA0A2FDA111CF6599ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF358D4F94B13D20BULL + 0x9946280449EEF7FDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE3958393CDD6D68BULL + 0x92D356222B341995ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBA6DDA99221D2DF1ULL + 0xCDFCA9F055598759ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAD9BF74C8FE9503DULL + 0xCE7626DA93FCFCF0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC65AA61B068BFF25ULL + 0xB562608F6EFCD41FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x96279C334FF25883ULL + 0x91DABE1EDDE636AEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFDDDAE455EDF14ADULL + 0x8AC71DD9E1F3ECB8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEF3AC811E2AA42DFULL + 0xA7AFBEEFD70F60F9ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aFireLaneC, aWorkLaneA, aOperationLaneB, aOperationLaneD, aWorkLaneB, aFireLaneA, aFireLaneD, aWorkLaneC, aOperationLaneC, aOperationLaneA
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 752U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((aIndex + 2841U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7327U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2034U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4770U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 1808U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 20U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 4U)) + 964165145848253292U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 10645976767204934746U) + aNonceWordH;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 8241612229349212650U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 4159196033256913347U) + aNonceWordL;
            aOrbiterA = (aWandererI + RotL64(aIngress, 29U)) + 7194795864620233507U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 13U)) + 7638928444536778384U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 51U)) + 11819105916503968109U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 18052213302858186237U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8663575313970041570U;
            aOrbiterE = RotL64((aOrbiterE * 14131073322476609161U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16644136720439299786U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 16930316530442679864U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 2650922074098320859U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16251107616988250593U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7171986193609401665U;
            aOrbiterH = RotL64((aOrbiterH * 3543709971414550087U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17885046834432626644U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7757069274715713557U;
            aOrbiterD = RotL64((aOrbiterD * 15766885299397923879U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 2212805322061155615U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6368539134638838822U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 13383744883433594259U), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 5264326094252925613U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6126345334815012938U;
            aOrbiterI = RotL64((aOrbiterI * 17180934809764905307U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13826731214018407061U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 6621261811613643620U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 2823596473596114171U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 3U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aNonceWordN) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterC, 27U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterE, 35U)) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 47U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 19U)) + aOrbiterA) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 58U)) + aOrbiterC) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneB
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13994U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((aIndex + 8766U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8984U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10096U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10477U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 8652U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = (((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 13174219512651137892U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 35U)) + 2715455762789269341U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 43U)) + 1338018183235594313U;
            aOrbiterA = ((((aWandererE + RotL64(aPrevious, 12U)) + RotL64(aCarry, 27U)) + 16566866551729552930U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aWandererA + RotL64(aCross, 57U)) + 6901845297307236726U) + aNonceWordB;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 21U)) + 2476078302049201718U) + aNonceWordD;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 3U)) + 15531109473927052260U) + aNonceWordM;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4087849380858572351U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5167830630098599644U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1982835131228146099U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7275995452428627217U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14794340370010024117U;
            aOrbiterG = RotL64((aOrbiterG * 8779497557416568379U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8509217403041662849U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 2321522025240806996U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 113568101672878697U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5676672952755594051U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2304681269233504384U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 15731441084605554497U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8383399721062437300U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 13181984036942227666U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 1648761328771932069U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 13602604532551684210U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12725687663616352843U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 4684699861686199753U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5831790822416009806U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4535048543735457407U;
            aOrbiterA = RotL64((aOrbiterA * 12076777878870257053U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterA, 29U));
            aWandererA = aWandererA + (((RotL64(aCross, 56U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterB, 21U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterA, 38U)) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 47U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21528U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 21963U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18089U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18566U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18244U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 19718U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 13U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = (((aWandererB + RotL64(aIngress, 53U)) + 2225397913940961213U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 3U)) + 8342544893601343643U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 37U)) + 162922186381417187U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 20U)) + RotL64(aCarry, 41U)) + 11660218373710972210U) + aNonceWordC;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 11U)) + 14909034764605802354U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 16776955237009701511U;
            aOrbiterF = ((((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 5834487809188925253U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1498492772767040320U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4161765458781579617U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15535994410289065281U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10511923076962447765U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8575954471692620021U;
            aOrbiterE = RotL64((aOrbiterE * 12526744988828982731U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6536325446331340573U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1790628986900286346U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5262997114200816715U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2623814807619278590U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11676970995834706612U;
            aOrbiterF = RotL64((aOrbiterF * 10057461115132434901U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13836786354224256591U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6293096163612129260U;
            aOrbiterH = RotL64((aOrbiterH * 8977954126326217153U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4271144764978661248U) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15938494256992560202U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10004841288382726739U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11038155227307702976U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 12408749795071243930U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 5527720475032868855U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 26U);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterC, 29U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aIngress, 4U) + aOrbiterJ) + RotL64(aOrbiterD, 21U)) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + aNonceWordB);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 52U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25509U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 26074U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 24936U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25086U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32213U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31110U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aCross, 52U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 17225673071833726819U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 35U)) + 10301458382103627331U;
            aOrbiterF = (aWandererD + RotL64(aCross, 57U)) + 3960233050857362414U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 48U)) + RotL64(aCarry, 3U)) + 17768665685046605837U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 3U)) + 14471018461213959767U) + aNonceWordE;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 41U)) + 10730597892721340453U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 23U)) + 14863394003122760542U) + aNonceWordA;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9948587274816688296U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3573569431435100993U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 2303922230056523077U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8153670675740450590U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 16438856577722561424U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4689247488336908827U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15765587867581925041U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1082039522061775213U;
            aOrbiterJ = RotL64((aOrbiterJ * 17023740047246402641U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4202521649260798876U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 15877659681260461141U) ^ aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 11369910758551088173U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2551560426129646123U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 3005102326163906320U) ^ aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 4241583192662435107U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1675501058857208089U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12774812270956702043U;
            aOrbiterG = RotL64((aOrbiterG * 5488437008504905105U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1044886020922563597U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4857445127457225171U;
            aOrbiterA = RotL64((aOrbiterA * 13223560654459705259U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 53U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 10U)) + aOrbiterH) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 21U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 41U)) + aOrbiterH);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aIngress, 22U) + aOrbiterA) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 18U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_WaterPolo_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCF9758CF8E906D57ULL + 0x9F007752D18D69F2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC95DA9F92A6D8B0BULL + 0xA4DA977507DD76B3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB873BA2C849AD8EBULL + 0xB36454DF31E0C9B8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x93C7271503CDF4A7ULL + 0xAC63306350CB6486ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8882FA95C5D97A93ULL + 0xF17F0AB52E371E2DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE252E4E4A17C6D15ULL + 0xD81AE117753D99B8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBCE2DF1F3ED792C1ULL + 0x8A7078098FE6E917ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF69BF37F8EF3623FULL + 0xEC73D4F881720909ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA467F67622DD2A75ULL + 0xB24084E011289115ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF1033A5BA9BFC6C3ULL + 0x9FB45500A9D2B834ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x86F13E803F15675DULL + 0xA34C636D2E757069ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC00C761538C669B5ULL + 0x9D0A20B5169AAD54ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCA4C1D6A1C7E7D6BULL + 0xFA6DFB0558BE79BEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF2AFB6D1E433A1DBULL + 0xA2D88F5E5068BCC6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x95AFAAC364F55CA9ULL + 0x8F40147F6668952DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEFDA0465BED47BF1ULL + 0xFB2294434F5CD98FULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD, aFireLaneA, aExpandLaneA, aFireLaneD, aOperationLaneA, aExpandLaneB, aOperationLaneB, aOperationLaneD, aExpandLaneC, aFireLaneC, aFireLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1969U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 5796U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 5440U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5033U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6917U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8109U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 29U) + RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (((aWandererI + RotL64(aIngress, 35U)) + 12690502671561165478U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aWandererB + RotL64(aCross, 47U)) + 17519943923428102801U;
            aOrbiterI = ((((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 10705515807975331385U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 16586447272278538179U) + aNonceWordC;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 60U)) + 8006560996840971798U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 12928600185788857701U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 21U)) + 14240723153798267172U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8636219177994872072U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7586790235186467512U;
            aOrbiterI = RotL64((aOrbiterI * 15052686382507614169U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1103807034179512424U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7547526530239498693U;
            aOrbiterE = RotL64((aOrbiterE * 3360295583636013509U), 51U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 8380239679344786397U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5690809173787433519U;
            aOrbiterD = RotL64((aOrbiterD * 5354724308093372953U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 8390902801141804609U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3507306189192059486U;
            aOrbiterA = RotL64((aOrbiterA * 18336280496510253103U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6190745292098482871U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8065418693975056902U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6414621418430102589U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 12111755051718111803U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7605877769709909297U;
            aOrbiterH = RotL64((aOrbiterH * 17525248694315944599U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5969794501112646237U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5127559299360591476U;
            aOrbiterF = RotL64((aOrbiterF * 4521563633438853069U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 20U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 35U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aCross, 22U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 53U)) + aOrbiterA) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + aNonceWordF) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16137U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 10583U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13851U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10621U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15705U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 15325U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aIngress, 60U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 1042610313571524121U) + aNonceWordM;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 27U)) + 3505725321008825582U;
            aOrbiterH = ((((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 12584654563843782991U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 6645399144515770935U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 12U)) + 3608978423753715584U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 5U)) + 8089198857670370983U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aWandererK + RotL64(aCross, 43U)) + 15207251813516399879U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9579268660105824516U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16055044469473802812U;
            aOrbiterH = RotL64((aOrbiterH * 2269649280637188723U), 27U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 583811872609805949U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 7027491967970873942U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 12686754713465826139U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 18256061823189677508U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12708429127816136937U;
            aOrbiterD = RotL64((aOrbiterD * 12593886633108075321U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12169216645156306078U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12694325407567795065U;
            aOrbiterJ = RotL64((aOrbiterJ * 3711789483877261899U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16109994660203297503U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4234704064165718913U;
            aOrbiterE = RotL64((aOrbiterE * 730085881474787681U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14119541943554602878U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 8777769004811352951U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 2556957257736134223U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15642663488392549609U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11594468530833278624U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 6639306656361601143U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 23U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 41U)) + aOrbiterE) + aNonceWordJ);
            aWandererF = aWandererF + ((RotL64(aCross, 40U) + aOrbiterH) + RotL64(aOrbiterE, 13U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ) + aNonceWordB) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 29U)) + aOrbiterB) + aNonceWordE);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneD
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 16385U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 19361U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 21691U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23628U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22876U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20606U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 24U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 9774364261626083532U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 18059001521926116420U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 20U)) + 10615626210406381148U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 10536484278007898620U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 39U)) + 13320663045139972700U) + aNonceWordL;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 57U)) + 17127001787268166583U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 11U)) + 16742574590844166551U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8347719720758228053U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13502468705946051986U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13822952083584784695U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3512687886188904904U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 495660316165795934U;
            aOrbiterI = RotL64((aOrbiterI * 6724596801190194913U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5092722552034477356U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15641128019608284015U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 3621036395703527059U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15421873776811085458U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17978775513204574125U;
            aOrbiterD = RotL64((aOrbiterD * 18359600395119440183U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16617179197537669849U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1931805387534012528U;
            aOrbiterF = RotL64((aOrbiterF * 3400139345857733775U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9544923119559308431U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12930999400470173353U;
            aOrbiterB = RotL64((aOrbiterB * 16791006919271490005U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13673733276226249890U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2032263473309124738U;
            aOrbiterE = RotL64((aOrbiterE * 3088728329261360607U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 51U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterF, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterH, 5U)) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 26U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 30U)) + aOrbiterI) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30310U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 27056U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 30578U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27536U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31340U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 32080U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 56U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = (((aWandererK + RotL64(aScatter, 60U)) + 16016931609704150191U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 14511433515861302636U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 27U)) + 11691237442613269593U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (aWandererH + RotL64(aIngress, 13U)) + 16383220587320484649U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 21U)) + 14293015313458219868U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 4407695248205526670U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 35U)) + 1158323195324398372U) + aNonceWordB;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6577683409653864555U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 171080079472863843U;
            aOrbiterG = RotL64((aOrbiterG * 3063978974927752653U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 5766333425872228205U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 16173508656917582960U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12187968015372936695U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11781450063402219202U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13033139686637576694U;
            aOrbiterF = RotL64((aOrbiterF * 4331137994135472025U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4006310759400926020U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13156817947481574467U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 563189239835001483U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12791290558893516411U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 989729955679243234U;
            aOrbiterJ = RotL64((aOrbiterJ * 8757228712495095017U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 838379839663022790U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2830743864262313606U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10173947177104802797U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 2146646527331684652U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4629168181742174906U;
            aOrbiterI = RotL64((aOrbiterI * 9046124907945045131U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (RotL64(aOrbiterK, 4U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 60U)) + aOrbiterG) + aNonceWordN) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 21U)) + aOrbiterG) + aNonceWordL) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 5U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + aNonceWordJ);
            aWandererK = aWandererK + ((((RotL64(aCross, 12U) + RotL64(aOrbiterF, 27U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 34U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_WaterPolo_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xADB97B286373ADEDULL + 0xE5C0667430695172ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDBC40A5730F937F3ULL + 0x8669275FED406715ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD74B16EBB6440F0BULL + 0x9B31D8BD4C7059DCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD8802A843BBCA457ULL + 0xF344598D46DD97AEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB4D11AE5C1149933ULL + 0xA54101333983DF63ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD3F92B0D9A3142B3ULL + 0xB55BA9E64A09B115ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x89044EE72AE00C33ULL + 0xA565C65F64CE25D3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x96A3B441CBB48D91ULL + 0xBC59FBD4E0E2D2CFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF7885AC1A44FA68BULL + 0xD1F2975BDAE80D17ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEB1CEF2985A330BDULL + 0x8ABAF9E6E09AA26EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB75D530A414546EFULL + 0xB2AE59AE2FCDA786ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC342A3383212C9E1ULL + 0x9F1E004376B17263ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x830B9A5F1B13FBDDULL + 0xF33C26F8AC31CDFCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA51BAFABAB258831ULL + 0xF5200700D7751BD0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x95396BFD520CC8C9ULL + 0x865D40E77A6EEA3DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB7492C7B5B7592CFULL + 0xC0662CD8E5A13E71ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aFireLaneA, aOperationLaneA, aWorkLaneD, aFireLaneB, aOperationLaneB, aWorkLaneA, aWorkLaneC, aOperationLaneC, aFireLaneD, aWorkLaneB
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6274U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 6831U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 5795U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3731U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4375U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 385U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 5906639480605353429U) + aNonceWordJ;
            aOrbiterI = ((aWandererB + RotL64(aCross, 51U)) + 5293518570213287605U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 19U)) + 15383185501428521377U) + aNonceWordK;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 47U)) + 15364072512743978902U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 56U)) + 4525473357144014271U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aScatter, 13U)) + 10400911938125603074U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 29U)) + 16417506293824627550U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 39U)) + 2419329331753341815U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 14929222427923332069U) + aNonceWordO;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 10U)) + 16771573504983922586U) + aNonceWordI;
            aOrbiterG = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 1863466450051787622U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12895350137096692415U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3700979086526298327U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 10279730254867618193U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1977099106211282426U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 6144698304096915742U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 5039822990560519609U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3858895556659724975U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1283646340363435327U;
            aOrbiterH = RotL64((aOrbiterH * 11622421841377018069U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6240532051889108891U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 757364889381634634U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 943852137901972945U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5272945693977418174U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 6850528198786172283U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1966383079897679953U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14431587733859573714U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16124590257870999553U;
            aOrbiterI = RotL64((aOrbiterI * 7755796211433191143U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14912695018110241411U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11098623474413346520U;
            aOrbiterD = RotL64((aOrbiterD * 15167688959990872051U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3484847683376368686U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2295388097292719800U;
            aOrbiterJ = RotL64((aOrbiterJ * 1240808318176106909U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 923199510066894111U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 311875852510926196U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9797881750305289335U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3543141837224843684U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12889943043568922084U;
            aOrbiterE = RotL64((aOrbiterE * 8682278766727990427U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6105656539077757510U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5906639480605353429U;
            aOrbiterK = RotL64((aOrbiterK * 9555916235293954383U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 14U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterC, 41U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterB, 56U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterF, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 35U)) + aOrbiterI);
            aWandererD = aWandererD + (((((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 23U)) + aNonceWordM) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + aNonceWordN);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterH, 47U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 14U)) + aOrbiterB) + aNonceWordH);
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererH, 22U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneD
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11281U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 13144U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12841U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9371U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9554U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 13047U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = (aWandererA + RotL64(aIngress, 47U)) + 7825479804710770560U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 38U)) + 5298124167101358123U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 23U)) + 17774541024369233726U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 43U)) + 7679371833537454082U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 5385914900748772224U) + aNonceWordP;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 35U)) + 3879781930908486531U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 659110346638873236U) + aNonceWordM;
            aOrbiterD = (((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 13U)) + 10749021728538539749U) + aNonceWordC;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 60U)) + 3631252455767429457U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 5U)) + 2271978810960685021U) + aNonceWordN;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 53U)) + 5963558780692551176U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 974909966119198104U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 9296998242911152296U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 2613629915877957661U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 2245318466901521959U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13391076374843288568U;
            aOrbiterB = RotL64((aOrbiterB * 18094558036982107419U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6184487746594236737U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1563385912137291418U;
            aOrbiterE = RotL64((aOrbiterE * 4805455299959232321U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1744840092006498629U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2100927276837188416U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3541788262067077997U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9998911862807246338U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12239948725635220096U;
            aOrbiterK = RotL64((aOrbiterK * 7098620484129489129U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3307447094994950246U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12746613971448298932U;
            aOrbiterF = RotL64((aOrbiterF * 9463975886346934681U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11577488293733790649U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 191108997585598809U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9574978681405356871U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 18096145693841273722U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10026281133603934071U;
            aOrbiterD = RotL64((aOrbiterD * 17261343107314203471U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2346682418062064668U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2996178204018644206U;
            aOrbiterA = RotL64((aOrbiterA * 2552965800703390909U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15085425896818988223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1589593231782852588U;
            aOrbiterI = RotL64((aOrbiterI * 1535556765195388675U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17170695588248383518U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7825479804710770560U;
            aOrbiterC = RotL64((aOrbiterC * 7434218282170150533U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 50U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 12U) + aOrbiterK) + RotL64(aOrbiterH, 56U)) + aNonceWordE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterA, 43U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 21U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + aNonceWordL);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            aWandererA = aWandererA + (((RotL64(aIngress, 10U) + RotL64(aOrbiterD, 23U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 39U)) + aNonceWordH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterA, 48U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 39U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18801U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((aIndex + 19582U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 22944U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20639U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20420U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22845U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 38U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (aWandererB + RotL64(aIngress, 13U)) + 15813325389431304548U;
            aOrbiterE = (aWandererI + RotL64(aCross, 53U)) + 2223874171125403602U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 23U)) + 5510483568496824130U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 29U)) + 15474152493495661876U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 16846339705130829195U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 39U)) + 1289670576865739669U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 27U)) + 18017354919647006944U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 19U)) + 8539685539928984921U) + aNonceWordE;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 10U)) + RotL64(aCarry, 21U)) + 3333721400836704048U) + aNonceWordP;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 47U)) + 2261560416623815491U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 41U)) + 4377786131746816567U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18047393176583722719U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8184724021940434631U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 9800116157750921119U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10469895939183324807U) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14543391765109879223U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4817987697437667225U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5757225781746158178U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3539000495894022869U;
            aOrbiterC = RotL64((aOrbiterC * 1032298408884695925U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11288971092707065923U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2761384065186568294U;
            aOrbiterF = RotL64((aOrbiterF * 3323838837427471051U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7120580145300417101U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6977246291769372866U;
            aOrbiterA = RotL64((aOrbiterA * 15170353875184253779U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 17625434527765525937U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3299714663631376190U;
            aOrbiterG = RotL64((aOrbiterG * 6532628892760776767U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10331889953489885250U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8550932256881727932U;
            aOrbiterJ = RotL64((aOrbiterJ * 13085531621192583719U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 11151195711186126257U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2552002192824926483U;
            aOrbiterB = RotL64((aOrbiterB * 9754056316698523849U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8038115194286715268U) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16594489591573505305U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 1241387574663818247U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13476964484361081681U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2136330439951908303U;
            aOrbiterH = RotL64((aOrbiterH * 12728359054660550527U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 231990686776499700U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15813325389431304548U;
            aOrbiterD = RotL64((aOrbiterD * 9155088985405261637U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 14U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 60U)) + aOrbiterB) + aNonceWordK);
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + aNonceWordM);
            aWandererI = aWandererI + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 47U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 51U));
            aWandererK = aWandererK + ((RotL64(aIngress, 26U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 21U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterF, 19U));
            aWandererA = aWandererA + (((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterB, 26U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32371U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 29762U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24868U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24609U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27947U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 26242U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 40U) + RotL64(aIngress, 19U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 12692813903177772178U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 7112496446691277899U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 2112247138290568813U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 14U)) + 3699421080882855947U) + aNonceWordG;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 11U)) + 13761832028354380922U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 21U)) + 9243822514887600214U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 57U)) + 6863833516853046129U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 24U)) + 8863897995943098018U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 19U)) + 13346785686701467520U) + aNonceWordD;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 27U)) + 15309543066305531619U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 5U)) + 17515530938817919111U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 760493237816424254U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7282586354117620860U;
            aOrbiterJ = RotL64((aOrbiterJ * 2327153408185290635U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4129706068526969105U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7020175432730888755U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10095158356907592239U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9102258982216515596U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10822031305361453690U;
            aOrbiterA = RotL64((aOrbiterA * 2036205056490578491U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12571477440964330246U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8436347026653095199U;
            aOrbiterH = RotL64((aOrbiterH * 17930734781213681573U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14214789872073941940U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12915911919403385001U;
            aOrbiterG = RotL64((aOrbiterG * 13161681603528031511U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15443240166233851298U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7311369180113240915U;
            aOrbiterD = RotL64((aOrbiterD * 13339195007946889423U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12976516224995960015U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7823308381434556721U;
            aOrbiterI = RotL64((aOrbiterI * 502385172763861451U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4829417661664149137U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16306394751966719700U;
            aOrbiterK = RotL64((aOrbiterK * 5294376579588592157U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16769868341852572677U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7107433163189177642U;
            aOrbiterC = RotL64((aOrbiterC * 5279050651595743649U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11896784111967113871U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 389626690429371003U;
            aOrbiterF = RotL64((aOrbiterF * 10665914532159182181U), 41U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 8226849597052979358U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12692813903177772178U;
            aOrbiterB = RotL64((aOrbiterB * 17909062471564422847U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 30U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 22U) + aOrbiterI) + RotL64(aOrbiterC, 5U));
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 21U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 43U)) + aOrbiterG) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterE, 35U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 10U) + aOrbiterA) + RotL64(aOrbiterI, 11U));
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 54U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 57U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterD, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 51U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterH, 30U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 57U);
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

void TwistExpander_WaterPolo_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE5FDAA3A70559283ULL + 0xF9F4F97F6740EB00ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCCE45C7FFAB4575FULL + 0xB8E1C227FC7DFA93ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB0B27FE92F6E4EFFULL + 0xE1756A1B17992B86ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF98EF3C4755FCB2FULL + 0xBAE079879295EF95ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x851204703A1FE9FBULL + 0xB3A0BC74A259180FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDB2C4C2D82A28CB7ULL + 0xE0BFFB018D345101ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE54A433659BFE769ULL + 0xC2C8E52B0441A695ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCBD1190558284DA1ULL + 0xBA3AAED4605AC794ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD75CF2675413F4FFULL + 0xED94A8CF0574D1F6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEB19D89C80FB7027ULL + 0xD348E77760BFBD32ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF450EB029CE3846BULL + 0x90A7C5E1FE275462ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDCF88B68FB1F1DEDULL + 0x851EBF4163D2FEE7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xACD4724BD0173305ULL + 0x82190FB068B544DFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB35EE5CF865DBE31ULL + 0xA29E01CE96956C85ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF65EEBA87C1DD221ULL + 0xECE23E5CAB53E8F5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC35B01307F5348E7ULL + 0xD290F70D136EA6AAULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneD, aExpandLaneA, aWorkLaneD, aFireLaneB, aExpandLaneB, aWorkLaneC, aWorkLaneA, aExpandLaneC, aFireLaneC, aWorkLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3562U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 5713U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6501U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1520U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 177U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 2027U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = ((aWandererE + RotL64(aCross, 13U)) + 17936518874386450467U) + aNonceWordJ;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 34U)) + 13722737841589910344U) + aNonceWordO;
            aOrbiterH = (aWandererA + RotL64(aScatter, 23U)) + 11774969167948715796U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 51U)) + 3640101505680493777U;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 1369495382725650822U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 60U)) + 11827310354654653345U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 186037671377175394U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 11428829344234627340U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 43U)) + 2275016369870029068U) + aNonceWordC;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15471646673734798328U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12172082573115640145U;
            aOrbiterH = RotL64((aOrbiterH * 9629417882787847753U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6626736341348283154U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 12220614992483863623U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 8137086205714097487U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13157102324253760215U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4143587482368093601U;
            aOrbiterF = RotL64((aOrbiterF * 5060677690991506895U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11007575246013796426U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11721585930088637162U;
            aOrbiterC = RotL64((aOrbiterC * 15009627907125738519U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5720789204450196217U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 3094696226821431648U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4412033981712165541U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14675830108100986773U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9444071495289719645U;
            aOrbiterG = RotL64((aOrbiterG * 10983136361953366557U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 5106753847015199956U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7585421898593510010U;
            aOrbiterI = RotL64((aOrbiterI * 140996914192351011U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11746948407655524690U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16336323220286344483U;
            aOrbiterK = RotL64((aOrbiterK * 6590417628835864497U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8030445186765781136U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 276034088015165891U;
            aOrbiterD = RotL64((aOrbiterD * 7626025612710225099U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 6U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterC, 53U)) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aCross, 34U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 18U)) + aOrbiterH) + aNonceWordA) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterI, 13U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 47U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 28U) + aOrbiterK) + RotL64(aOrbiterC, 37U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 28U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 23U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererH, 30U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aWorkLaneD
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14821U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 11291U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 12646U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11182U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13056U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 12837U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 50U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = ((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 39U)) + 11700815697312060726U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 43U)) + 11808423452327465441U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aWandererC + RotL64(aIngress, 29U)) + 8670503858631730886U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 23U)) + 2400061067991988544U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aCross, 56U)) + 16163118178366229686U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 51U)) + 3280178595904941068U) + aNonceWordC;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 47U)) + 3298683600817047727U) + aNonceWordD;
            aOrbiterK = (aWandererK + RotL64(aScatter, 19U)) + 16321624053445183574U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 6730229877611375225U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10162830636713641322U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15646771327759599256U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15333053762177144775U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 14841751262270544102U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9545541117228834895U;
            aOrbiterI = RotL64((aOrbiterI * 11529769874752969377U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 14676615635857599982U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1231768638470558855U;
            aOrbiterC = RotL64((aOrbiterC * 2716808508509014677U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1945905595345404833U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1406171421638586846U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 4577864352425476233U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1970292335806697198U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12309719390375013297U;
            aOrbiterB = RotL64((aOrbiterB * 16540660957923687327U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5352135521358954576U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15465675376193501658U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16385761112921041387U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2842123638916600369U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3544764287036748668U;
            aOrbiterA = RotL64((aOrbiterA * 3360772950777850115U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6038297172906492282U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10249342332287140970U;
            aOrbiterG = RotL64((aOrbiterG * 16701083081566042277U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 1662076777040529446U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1949705569959740274U;
            aOrbiterE = RotL64((aOrbiterE * 11340691546658994529U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 38U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 53U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aNonceWordB) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterG, 35U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterI, 44U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterI, 57U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterE, 27U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterC, 21U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 57U)) + aNonceWordO);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 58U) + aOrbiterE) + RotL64(aOrbiterC, 39U));
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterF, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23477U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 20583U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 24095U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19834U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20467U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17498U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((aWandererE + RotL64(aIngress, 60U)) + 4068921616130916949U) + aNonceWordL;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 43U)) + 12077715273915151726U) + aNonceWordA;
            aOrbiterH = ((aWandererK + RotL64(aCross, 13U)) + 16047546802670596833U) + aOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 9690277462716999763U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 14484814700447992628U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 6U)) + 17089267243053958210U) + aNonceWordG;
            aOrbiterA = (aWandererB + RotL64(aCross, 23U)) + 9138746214446211147U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 10181001536979097045U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 51U)) + 6657458969093373191U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7515983477876590988U) + aNonceWordE;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 3039935555863947600U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 12511160550780270119U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16209389224740851136U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 725253312098083182U;
            aOrbiterE = RotL64((aOrbiterE * 17535989492095522597U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 13307041115748941383U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7159572004825238263U;
            aOrbiterJ = RotL64((aOrbiterJ * 4855009895002398449U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12027236743251643820U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8717826175991286553U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 1175614802543098451U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4769096034227659937U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11201226563992939616U;
            aOrbiterC = RotL64((aOrbiterC * 15595355978388159931U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17295978531215563256U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11850923890626719833U;
            aOrbiterA = RotL64((aOrbiterA * 3854851059897397075U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 14139441565288097706U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 988684899382304485U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 11929090869999700891U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6159251276942253175U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4849529993914550651U;
            aOrbiterB = RotL64((aOrbiterB * 18240712676783671317U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6679745455842119497U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15838404437552215214U;
            aOrbiterI = RotL64((aOrbiterI * 17357853511591350887U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 18U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + aNonceWordK);
            aWandererI = aWandererI + ((((RotL64(aCross, 30U) + aOrbiterE) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterD, 39U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterE, 28U)) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 47U));
            aWandererB = aWandererB + ((RotL64(aScatter, 12U) + aOrbiterB) + RotL64(aOrbiterC, 51U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterK) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31547U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 29073U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29303U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30506U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 30216U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 29306U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 18U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = ((aWandererD + RotL64(aScatter, 22U)) + RotL64(aCarry, 3U)) + 16651241552253078315U;
            aOrbiterC = (aWandererA + RotL64(aCross, 47U)) + 4558144676982478003U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 41U)) + 8814884320080367550U) + aNonceWordL;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 27U)) + 16011579668555672117U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 57U)) + 4738918668759862438U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 12526083125540985108U;
            aOrbiterK = (aWandererI + RotL64(aCross, 13U)) + 8048723561746000552U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 3U)) + 1082218464034639039U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 52U)) + RotL64(aCarry, 29U)) + 8432043246965946816U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9982080524048636852U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6720069955755215919U;
            aOrbiterD = RotL64((aOrbiterD * 1025046364205332059U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1019035028070247757U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7360619079463870467U;
            aOrbiterF = RotL64((aOrbiterF * 6623074813047915863U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10893918488381348474U) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1390297670907738019U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11909657437658597735U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12512200589031203480U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14741471280748399540U;
            aOrbiterK = RotL64((aOrbiterK * 3012135242889901095U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8543897248359826770U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8545972622733791272U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11793879362775346821U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7049384618581928664U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14730773807906925408U;
            aOrbiterA = RotL64((aOrbiterA * 10711566871536755073U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11480717275652449986U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1135397594974536859U;
            aOrbiterC = RotL64((aOrbiterC * 6347492892938856497U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6897207625849516702U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10920630712550287148U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4140705091806993359U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1094056478999931332U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6784487144549717207U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 6295177724167067891U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 24U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 34U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterE, 53U)) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterK, 41U)) + aOrbiterC) + aNonceWordJ);
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 28U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterK, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 11U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aIngress, 26U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_WaterPolo_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD622162E417603FDULL + 0xF76A1519FD605E03ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAF5D2F9A6C5599E1ULL + 0xDB3395D001652BC1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAEB861AC850E32EDULL + 0xC1BC98DE744B3447ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDEB49784D2F049CDULL + 0xD334BC35D99B14D0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB24F2E94B6BE77B5ULL + 0xE554A99E5EEE295EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC2E133B569FAD041ULL + 0xD61A785F1D3C1892ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9A715158F5CAB4E7ULL + 0x9D75D772EF0215EFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xECC10D8F52C1C921ULL + 0x9768C131726BA0E3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF627F846305C7E95ULL + 0xC649EB00EC73BCD7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD682E67A6C6261D3ULL + 0xE2DAB1D4503DED69ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF8E95DE3A1676481ULL + 0xAF113424A53B48A3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCDE9FD5DA9D3B499ULL + 0xEE2F29BF1E9159C2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBFE485B5B1E9E8DFULL + 0xE364195E5E234130ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCD9B3DAE3BAAA5F7ULL + 0x9F9DB8EDEF58CB2EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE1B2B4FA52396459ULL + 0x8D5CAF28A0105450ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBE88EB16BD45488DULL + 0xEBF6F2495E7236C9ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aOperationLaneC, aFireLaneA, aExpandLaneB, aOperationLaneD, aFireLaneB, aExpandLaneC, aOperationLaneA, aFireLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6156U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 1960U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1188U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3170U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3340U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 5138U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 50U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 13U)) + 13481227414590594621U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 17425964381118918026U) + aNonceWordK;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 20U)) + RotL64(aCarry, 39U)) + 4792004356135956581U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 57U)) + 11926849936000639098U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 3U)) + 990697329347742142U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 41U)) + 9307721505373076588U) + aNonceWordM;
            aOrbiterH = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 17605732738841908719U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13110764518634187439U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17970109897810645911U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 10395095143998920213U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10273133817644703654U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11239046688920468137U;
            aOrbiterJ = RotL64((aOrbiterJ * 5197802934333553327U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 8355821483275763145U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 15522151127786049345U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 4844278537850520413U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5381663179722418112U) + aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9551368011768104906U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 14202470972121732997U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 16264476585232221270U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7721417776432288282U;
            aOrbiterH = RotL64((aOrbiterH * 10267770327791051869U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 339418090653475277U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3247926250495935511U;
            aOrbiterD = RotL64((aOrbiterD * 16824669543765729097U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3390560045236418590U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3894024951542543635U;
            aOrbiterC = RotL64((aOrbiterC * 10599637790900418767U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 50U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aCross, 22U) + aOrbiterD) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 37U)) + aNonceWordO) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 42U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 21U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterC, 51U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15380U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 8681U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 15104U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9174U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15958U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12537U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 48U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = ((aWandererC + RotL64(aScatter, 53U)) + 12535417189990029950U) + aNonceWordB;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 6204401443676390273U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 37U)) + 869613505613154672U) + aNonceWordD;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 27U)) + 15053590879563855802U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 13U)) + 13338989605204591428U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (((aWandererI + RotL64(aCross, 6U)) + RotL64(aCarry, 5U)) + 18306470022403825392U) + aNonceWordI;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 43U)) + 1150696349434090218U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13549541786420596437U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14302878430259588461U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16813606782134305513U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4660437084477165225U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1653628537860912069U;
            aOrbiterI = RotL64((aOrbiterI * 2624835201155303123U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5594199757006711631U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11008472193138708891U;
            aOrbiterA = RotL64((aOrbiterA * 13645764762027798301U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3668516817279364310U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 128159531749679984U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4523246859249826987U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 6378674346113979108U) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11438762460659123362U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 2733309638158283953U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 10624263004446482910U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12546839706919241411U;
            aOrbiterG = RotL64((aOrbiterG * 11468326687628079347U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8466639576503293921U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5828694979857951504U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7835487310289634515U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 4U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 14U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 53U)) + aOrbiterG) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterA, 11U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19039U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((aIndex + 18813U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 21873U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22850U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20933U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 21807U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = ((aWandererF + RotL64(aIngress, 5U)) + 3236820517816085022U) + aNonceWordB;
            aOrbiterC = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 741288875914097926U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 50U)) + RotL64(aCarry, 21U)) + 8417246926007729580U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 37U)) + 9715717805774537170U) + aNonceWordA;
            aOrbiterK = (aWandererJ + RotL64(aCross, 11U)) + 14360243844821619482U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 57U)) + 10760908100206775334U) + aNonceWordC;
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 3434641779946167811U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7885568822756234567U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3041563437672051294U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 11440300917533482297U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15761355327564963516U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1158633562785937421U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 15511324886867188235U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9338581575871970653U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9172038894262857354U;
            aOrbiterK = RotL64((aOrbiterK * 3110871165285625807U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14653924713599790081U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3854497592598563309U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11737111068815795303U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 16286980180327600557U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5092583772591249756U;
            aOrbiterF = RotL64((aOrbiterF * 13955105624639442903U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4288397994175567333U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15584236478994873104U;
            aOrbiterC = RotL64((aOrbiterC * 1860480595862755379U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5557463939827483792U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2659814275753280856U;
            aOrbiterE = RotL64((aOrbiterE * 17702430405693184643U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aScatter, 12U) + aOrbiterC) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 11U)) + aNonceWordO) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterK, 39U)) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterE, 10U)) + aNonceWordF);
            aWandererF = aWandererF + ((((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 57U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ) + aNonceWordP);
            aWandererA = aWandererA + ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterA, 47U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28403U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 29938U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26639U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26347U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26262U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 28346U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 52U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = (((aWandererI + RotL64(aIngress, 47U)) + 785861751704720606U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 11U)) + 15968088718435606299U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 57U)) + 1393976526590347151U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererC + RotL64(aCross, 20U)) + RotL64(aCarry, 23U)) + 17240750947292745884U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 35U)) + 4921576136163183137U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 43U)) + 3334047873553153032U) + aNonceWordB;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 15086509978458408698U) + aNonceWordI;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 892391205397581998U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2965686403183767521U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 709160942482770225U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14632215393655706170U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15740589515342377322U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 15677716942904794913U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 11131164813943086445U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6988080581278900960U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6412189142344044255U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 16021254613117657178U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6183615599897921154U;
            aOrbiterC = RotL64((aOrbiterC * 9976411093264211033U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12533992547026652747U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3104325358982904219U;
            aOrbiterG = RotL64((aOrbiterG * 14977348108778147265U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3878525937957474644U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2120435259884368445U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15964718652193073177U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14928658302694194856U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9121310461310309348U;
            aOrbiterH = RotL64((aOrbiterH * 17304439784647477491U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterK, 5U)) + aNonceWordN) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterH, 47U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterD, 35U));
            aWandererG = aWandererG + ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterC, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterA, 56U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_WaterPolo_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEC94A67A7FEB36E1ULL + 0xD5C9BF8338DD276EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDCA8F9274B0BEBC7ULL + 0x861728BE1CF9DF4AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAF25C80FC22AD8D5ULL + 0xA87CF4FA29B90047ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBFDD9C2B26F6F989ULL + 0x88CE5C7706A93CA7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF942FF26137C9253ULL + 0x8C7482A7DC8D3ECCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF746F7E8F725FE8FULL + 0xC902CA6A6A235814ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCB9906CEB4E8882FULL + 0xE4A08CD66202BED8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x986D30A8D7164477ULL + 0x8C98D3E32FEEE3F2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA5226D228ED2E5A1ULL + 0xDE40141308C4C42AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA5763D51A9A50DFFULL + 0xAF093546088B96EFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8075B58E9BF13B27ULL + 0xDADF353B0D3D6BF2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF62D654E70A5673BULL + 0xCAC5A60EA2900927ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF93987B221C7CEA5ULL + 0xE9E1BF976FCB3CBDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x80C0017A36CC1139ULL + 0xF7F487A3E1C58FECULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x979A0EF293788D25ULL + 0xB1DEFC25F2DD3E4AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC9ED01A861C8E42DULL + 0xF0F3C4FBBF6695F8ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1642U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 2412U)) & W_KEY1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1605U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2516U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 6U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 22U)) + 13481227414590594621U) + aNonceWordA;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 17425964381118918026U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 4792004356135956581U) + aNonceWordJ;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 57U)) + 11926849936000639098U) + aNonceWordG;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 37U)) + 990697329347742142U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 13U)) + 9307721505373076588U) + aPhaseEOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 17605732738841908719U) + aNonceWordK;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13110764518634187439U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17970109897810645911U;
            aOrbiterE = RotL64((aOrbiterE * 10395095143998920213U), 11U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 10273133817644703654U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11239046688920468137U;
            aOrbiterB = RotL64((aOrbiterB * 5197802934333553327U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8355821483275763145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15522151127786049345U;
            aOrbiterA = RotL64((aOrbiterA * 4844278537850520413U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5381663179722418112U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9551368011768104906U;
            aOrbiterI = RotL64((aOrbiterI * 14202470972121732997U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16264476585232221270U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7721417776432288282U;
            aOrbiterD = RotL64((aOrbiterD * 10267770327791051869U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 339418090653475277U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3247926250495935511U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16824669543765729097U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3390560045236418590U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3894024951542543635U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10599637790900418767U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 19U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 3U)) + aOrbiterB) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 11U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 37U)) + aPhaseEWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 22U) + RotL64(aOrbiterB, 27U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 60U)) + aOrbiterI) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 43U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4903U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4014U)) & W_KEY1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5326U)) & W_KEY1], 44U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3479U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = ((aWandererE + RotL64(aIngress, 20U)) + RotL64(aCarry, 5U)) + 7075016829833562104U;
            aOrbiterG = ((((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 8783765886115517036U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (aWandererF + RotL64(aCross, 3U)) + 2996723892384565829U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 35U)) + 9494134707342189476U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 5052642981395679904U) + aNonceWordE;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 43U)) + 8766787055127962238U) + aPhaseEOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 51U)) + 4467211954388738079U) + aNonceWordM;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8030255604633658608U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16962408063455702251U;
            aOrbiterB = RotL64((aOrbiterB * 11171737929747471631U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3768222186567699076U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14930990410207899871U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10930005786146268241U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14179761938395502502U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1879084742719898108U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 16783034788172670121U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 5535012408925981515U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 12792553516710295939U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 8577530993755159329U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8979253163346099252U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5559189896063990740U;
            aOrbiterE = RotL64((aOrbiterE * 8832485423727331621U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13937564337299044079U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2393376759689394948U;
            aOrbiterJ = RotL64((aOrbiterJ * 2352815657830413941U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12647519563697356479U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10946871249960389549U;
            aOrbiterG = RotL64((aOrbiterG * 6272580371881237173U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 22U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 14U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + aNonceWordJ);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterB, 39U)) + aNonceWordO);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterG, 56U)) + aNonceWordC);
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7421U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 7716U)) & W_KEY1], 34U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7295U)) & W_KEY1], 56U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5985U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7125U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 28U) + RotL64(aIngress, 43U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 11U)) + 3199575576585871314U) + aNonceWordH;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 3U)) + 2533378188975571824U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 6819782112558312658U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 43U)) + 12690060987724798497U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 20U)) + 7088375139715629606U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aWandererF + RotL64(aCross, 53U)) + 17785618677423695666U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 1714999280296491277U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17611338506932491624U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6475727359297421201U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15133348244242438069U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2347744591204119530U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2739317903351401068U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 15435029315209475631U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8663535261373274338U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8205245127823536479U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13857005110466856439U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8916510616749754516U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3944805940148512932U;
            aOrbiterE = RotL64((aOrbiterE * 18082271583211389701U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14094751253118853302U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 14094299829196076311U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 6370012560657108493U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3940673811518673802U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3015106523254484839U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 9655401190755573379U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15404103131982599922U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1828655763233900875U;
            aOrbiterI = RotL64((aOrbiterI * 13024358077740310049U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 57U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterI, 29U));
            aWandererC = aWandererC + (((RotL64(aIngress, 22U) + aOrbiterH) + RotL64(aOrbiterE, 35U)) + aPhaseEWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 48U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterA, 19U)) + aNonceWordI);
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9726U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 9826U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(mSource[((aIndex + 10708U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10047U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9275U)) & W_KEY1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10525U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = ((((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 6243113109470883144U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 6U)) + RotL64(aCarry, 41U)) + 3891552123999605832U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 8758797898587019128U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 51U)) + 1005891374086408851U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 37U)) + 3713426782180050764U) + aNonceWordE;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 29U)) + 18358143862391573534U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 13U)) + 17504394029693712404U) + aNonceWordA;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5312729289027417014U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2560873623431186029U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 16843728573219210173U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16309322822806704211U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10195513918020652600U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14569219741824123715U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2552116263258744287U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7732784879810980089U;
            aOrbiterD = RotL64((aOrbiterD * 15041929399477790999U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16499127570665381507U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10890036715535519036U;
            aOrbiterF = RotL64((aOrbiterF * 9065115450010475187U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16288944603478791554U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 14542766121469312846U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 8435383464425875209U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5973595239494084696U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1820492719977197097U;
            aOrbiterA = RotL64((aOrbiterA * 16164917159141304405U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 10489529555776381736U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6392552206958240484U;
            aOrbiterE = RotL64((aOrbiterE * 11761477994533503307U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 13U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterF, 19U)) + aNonceWordI) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterE, 44U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 53U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterD, 27U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12370U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[((aIndex + 12129U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13272U)) & W_KEY1], 39U) ^ RotL64(mSource[((aIndex + 11882U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12416U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11385U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11821U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 54U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 964165145848253292U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 22U)) + 10645976767204934746U) + aNonceWordG;
            aOrbiterI = ((((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 8241612229349212650U) + aPhaseFOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 4159196033256913347U) + aPhaseFOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 37U)) + 7194795864620233507U) + aNonceWordL;
            aOrbiterK = (aWandererA + RotL64(aScatter, 13U)) + 7638928444536778384U;
            aOrbiterC = (aWandererF + RotL64(aCross, 5U)) + 11819105916503968109U;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 18052213302858186237U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8663575313970041570U;
            aOrbiterI = RotL64((aOrbiterI * 14131073322476609161U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16644136720439299786U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 16930316530442679864U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2650922074098320859U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16251107616988250593U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7171986193609401665U;
            aOrbiterK = RotL64((aOrbiterK * 3543709971414550087U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17885046834432626644U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7757069274715713557U;
            aOrbiterG = RotL64((aOrbiterG * 15766885299397923879U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2212805322061155615U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6368539134638838822U;
            aOrbiterD = RotL64((aOrbiterD * 13383744883433594259U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5264326094252925613U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 6126345334815012938U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17180934809764905307U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13826731214018407061U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6621261811613643620U;
            aOrbiterB = RotL64((aOrbiterB * 2823596473596114171U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterK, 54U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 35U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 21U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterB, 13U)) + aOrbiterC) + aNonceWordJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 47U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 41U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 35U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16351U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13937U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16316U)) & W_KEY1], 37U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14641U)) & W_KEY1], 5U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15229U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15819U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14181U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 26U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (aWandererE + RotL64(aCross, 23U)) + 16016931609704150191U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 14U)) + 14511433515861302636U) + aNonceWordO;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 11691237442613269593U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 16383220587320484649U;
            aOrbiterK = (aWandererD + RotL64(aCross, 57U)) + 14293015313458219868U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 4407695248205526670U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 51U)) + 1158323195324398372U) + aPhaseFOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6577683409653864555U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 171080079472863843U;
            aOrbiterG = RotL64((aOrbiterG * 3063978974927752653U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5766333425872228205U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16173508656917582960U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 12187968015372936695U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11781450063402219202U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13033139686637576694U;
            aOrbiterE = RotL64((aOrbiterE * 4331137994135472025U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4006310759400926020U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13156817947481574467U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 563189239835001483U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12791290558893516411U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 989729955679243234U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 8757228712495095017U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 838379839663022790U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 2830743864262313606U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 10173947177104802797U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 2146646527331684652U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4629168181742174906U;
            aOrbiterC = RotL64((aOrbiterC * 9046124907945045131U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 58U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterI, 29U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 6U) + aOrbiterD) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterA, 10U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 13U)) + aNonceWordA) + aPhaseFWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterA, 51U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16694U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 17152U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(mSource[((aIndex + 17789U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16707U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17412U)) & W_KEY1], 48U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18426U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17037U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 8367680518550579791U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 21U)) + 11491674725611181241U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 16673861720782164214U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 9786610124108350855U) + aNonceWordD;
            aOrbiterH = ((aWandererD + RotL64(aCross, 57U)) + 5745080601557577637U) + aNonceWordK;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 51U)) + 1959402215131684684U) + aNonceWordP;
            aOrbiterF = (aWandererA + RotL64(aIngress, 42U)) + 6121650036079196522U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12016309761037342392U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5986936646177049603U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 3585650475703294895U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1000367700904043468U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17425288243569101032U;
            aOrbiterH = RotL64((aOrbiterH * 2174614006719048535U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4856917474950325209U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 16312111093223166419U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 11046477664487805241U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 456110002032422270U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11393724374787795662U;
            aOrbiterG = RotL64((aOrbiterG * 1176984359123668389U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8378176867715697176U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8086186452345234815U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8450438271765985235U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8470349167474173245U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2528229938740192694U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8717790851266520943U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13247168811545753141U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8745293957516815264U;
            aOrbiterC = RotL64((aOrbiterC * 14270617180621072619U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 43U)) + aOrbiterG) + aNonceWordM);
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterD, 12U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 37U)) + aOrbiterF) + aNonceWordB);
            aWandererK = aWandererK + (((((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 43U)) + aNonceWordG) + aPhaseGWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + aPhaseGWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21446U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((aIndex + 21532U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19500U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 21093U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19190U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21589U)) & W_KEY1], 3U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21584U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21330U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 47U)) + 15910560457440369082U) + aPhaseGOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 17953072986407436888U) + aNonceWordG;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 57U)) + 15446940721193538669U) + aNonceWordN;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 3020785262774422009U) + aPhaseGOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 26U)) + RotL64(aCarry, 27U)) + 7001288645424994404U) + aNonceWordA;
            aOrbiterF = (aWandererD + RotL64(aScatter, 5U)) + 13385250665458462689U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 39U)) + 4841895644623005949U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 13053476783239482065U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 641996979335975244U;
            aOrbiterC = RotL64((aOrbiterC * 3697673197256549833U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16211238020928688299U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12715448751323279480U;
            aOrbiterK = RotL64((aOrbiterK * 2116880429675303291U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 17784406727699995290U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16626339815786580778U;
            aOrbiterF = RotL64((aOrbiterF * 13940754474750138041U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9035070625716345139U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6085848172494001945U;
            aOrbiterA = RotL64((aOrbiterA * 10405728912339646693U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 1177103851507561053U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2281901691017816407U;
            aOrbiterE = RotL64((aOrbiterE * 3142197009403602497U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9040984343694325070U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13334258224023902365U;
            aOrbiterB = RotL64((aOrbiterB * 4782523727707164869U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1079824790138592518U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 14024082692012948652U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 3219489374333737903U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterF, 19U));
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterB, 50U)) + aNonceWordK);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 3U) + RotL64(aOrbiterB, 35U)) + aOrbiterE) + aNonceWordH) + aPhaseGWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 43U)) + aOrbiterC) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 38U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 57U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22505U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 24234U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23261U)) & W_KEY1], 18U) ^ RotL64(aFireLaneC[((aIndex + 23337U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22494U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23333U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22010U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21853U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 40U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 51U)) + 17711946802293254150U) + aNonceWordM;
            aOrbiterJ = ((((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 41U)) + 16652362590489569378U) + aPhaseGOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 11U)) + 6972810344198183097U) + aPhaseGOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aCross, 3U)) + 13117100889782940546U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 29U)) + 13199305696782626591U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 5U)) + 992156184392760945U;
            aOrbiterH = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 13791265442074543880U) + aNonceWordI;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17057087245252294859U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 13444195995883541046U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 13067044288608808777U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6723678233676059420U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7913379431208430475U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 2295062944289127123U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4481887195529300665U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11892724101424384078U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3468639499716604111U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7700902083270424194U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1888001433557140271U;
            aOrbiterJ = RotL64((aOrbiterJ * 8975562955027025349U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14996753906788986929U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 939004845422123765U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2507090308972292313U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 11922230289291941807U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15681187459741147199U;
            aOrbiterD = RotL64((aOrbiterD * 10124947739653819101U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9119043713532718155U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8327697433992362166U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11157657162184304567U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 48U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 41U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 58U)) + aOrbiterK) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterG, 23U)) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + aNonceWordH);
            aWandererA = aWandererA + (((((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 3U)) + aNonceWordL) + aPhaseGWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25830U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 25409U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25573U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 24818U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27199U)) & W_KEY1], 48U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26855U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26779U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 25358U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (aWandererJ + RotL64(aCross, 35U)) + 2672739400294801233U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 43U)) + 8475624545015101850U) + aNonceWordJ;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 13U)) + 1252755112289831257U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 7938039507649183387U;
            aOrbiterJ = ((((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 8167413146948861022U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (aWandererH + RotL64(aIngress, 26U)) + 17712313989694374353U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 7637042279892596975U) + aNonceWordA;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 15770412950033467341U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3951812021898608685U;
            aOrbiterH = RotL64((aOrbiterH * 6623127125223204737U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8656983621098246507U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17943342344730687317U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16495519451034883813U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3087677463651608668U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16493240011924342788U;
            aOrbiterA = RotL64((aOrbiterA * 16898479041530771871U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7750923317452683057U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2185924841611106546U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 708072658250726381U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14676868738946722416U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6849098251696302393U;
            aOrbiterG = RotL64((aOrbiterG * 2599806275837778069U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 17817755047153606419U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9900465270314068757U;
            aOrbiterF = RotL64((aOrbiterF * 9267925873983176685U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11380000891112113701U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15930503831156546113U;
            aOrbiterJ = RotL64((aOrbiterJ * 14450535035065393845U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterK, 57U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterG, 35U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 4U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            aWandererB = aWandererB + (((((RotL64(aPrevious, 54U) + aOrbiterD) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 5U)) + aNonceWordI) + aPhaseHWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29807U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((aIndex + 29516U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28862U)) & W_KEY1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28945U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27360U)) & W_KEY1], 48U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28148U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28935U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 27998U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 58U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 8020711767807230555U) + aNonceWordB;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 15368693777246341570U) + aNonceWordF;
            aOrbiterA = (aWandererH + RotL64(aScatter, 47U)) + 5117523734225562401U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 21U)) + 13155269151097507808U) + aPhaseHOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 41U)) + 9879303753623578272U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 14U)) + 1165799257173794826U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 930641942062732091U) + aPhaseHOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11330571332221123153U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2862963158282518899U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13782195862525974199U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6019186399361476659U) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1924419843785161958U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9485557122500346869U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12618629043591380461U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9334176504266512405U;
            aOrbiterE = RotL64((aOrbiterE * 18239109235362925739U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16829692481030013551U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5604784396927022709U;
            aOrbiterI = RotL64((aOrbiterI * 2833893610883508353U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16124030106598549644U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16571659812830230677U;
            aOrbiterJ = RotL64((aOrbiterJ * 4668250364992383549U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 15171089673591843703U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2826755560293849328U;
            aOrbiterC = RotL64((aOrbiterC * 9397017963457655287U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9976785768283589291U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11845100564714691809U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4935139932585319251U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 24U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 18U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + aNonceWordL);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterI, 21U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 38U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aNonceWordD) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterG) + aNonceWordN);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterD, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31378U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 31481U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30153U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31196U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31846U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadB[((aIndex + 30344U)) & W_KEY1], 23U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 17074147006464019918U;
            aOrbiterB = ((((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 10559516626129419928U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 27U)) + 13280363679503946221U) + aPhaseHOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 17657115422132457413U) + aNonceWordI;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 13U)) + 13325837013304973008U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 34U)) + 3059707750486106037U) + aNonceWordB;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 19U)) + 4529045702503050852U) + aNonceWordO;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10726578475550904292U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 14832537837996659885U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 808060368961520519U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 220094417441809246U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15343130035105342194U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7984652435043810845U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16592263353426409884U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15649290906447931918U;
            aOrbiterJ = RotL64((aOrbiterJ * 8405875177836650731U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11437410545843708269U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5859769136073011444U;
            aOrbiterC = RotL64((aOrbiterC * 1065016088086441107U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15188064100307340341U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 4367466521843260049U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15916715854192820923U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8482617283860566845U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2585745804937342972U;
            aOrbiterF = RotL64((aOrbiterF * 8267269625632139809U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1687641344403425541U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13667916445979421400U;
            aOrbiterE = RotL64((aOrbiterE * 8191322670355590027U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 36U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 47U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + aNonceWordD) + aPhaseHWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterF, 58U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 13U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE) + aNonceWordK) + aPhaseHWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_WaterPolo_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE9121F751FF9439FULL + 0xE22237C5A217C34AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8734E52E6375FD4DULL + 0xDE567827E71A048EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDC0340630998B54FULL + 0xAC8F5446F2FAC989ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE3212F84F26263CDULL + 0xB67F967560D8CB5FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8126983DC4C73C71ULL + 0xB61123A7F9C01AAFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA94AAC330BEFBC03ULL + 0xE651C402A75C4F2EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE3A91F47E34E8555ULL + 0xCEC11E3328B9F3B9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD44094CFD4B154EBULL + 0xCD61974E84C47237ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEA8C73D6317FEB1DULL + 0x99131423302CEBA2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA8FA025F57EA491FULL + 0xC98FB791144831A2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC33EFFEBFA148F61ULL + 0xDCCB3F4C615B1837ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDEF2BFC5FFBC9CE5ULL + 0xEDF65038A22ED9C9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8B570023BFD19967ULL + 0xD01F9A81A17F1EC9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9FFADE599B1BD945ULL + 0x9E8E4DE20BF12401ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC9BFFD5568AE3E51ULL + 0xDFAB6B80AFA31C74ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFEB407DA4E593DD3ULL + 0xDEB7FFA685C72079ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneC, aInvestLaneB, aFireLaneA, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5036U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 958U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 563U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5288U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 1009U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 10U) + RotL64(aCarry, 37U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 3339283916456813609U) + aPhaseAOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 11339086426180649584U;
            aOrbiterI = ((((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 16819191669329316585U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aWandererH + RotL64(aCross, 60U)) + 8361916937762630725U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 51U)) + 18031328374429899857U) + aNonceWordI;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 18261756894092897276U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4250319792907645666U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7053489184750217963U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1492411503643460886U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17369549067879344180U;
            aOrbiterD = RotL64((aOrbiterD * 2947354306696216579U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7301713524358676722U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2985193736033012535U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 7473297294949338265U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14086975808140927408U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10390516547834639800U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11441293212275890819U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 18205555540941493267U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 16967799565443938873U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3009081009044782443U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 37U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterJ, 21U)) + aPhaseAWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 38U) + RotL64(aOrbiterD, 53U)) + aOrbiterC) + aNonceWordE) + aPhaseAWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 6U)) + aOrbiterA) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 12U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8367U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 6198U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 5887U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7860U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 7205U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 41U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 57U)) + 4773124477323378268U) + aNonceWordI;
            aOrbiterE = (aWandererD + RotL64(aScatter, 5U)) + 16848723289435796005U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 13846642134917107058U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 6472057872482789939U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aCross, 38U)) + RotL64(aCarry, 51U)) + 2747019500690707226U) + aNonceWordB;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9003965289739733880U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3013390651936257377U;
            aOrbiterC = RotL64((aOrbiterC * 11081353600889943167U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3331004709895625067U) + aNonceWordA;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15355010435553517129U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8322759117004876831U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7709870658004280052U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13568728443963926564U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6736090830113688981U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12409548853419307131U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 969183352023661537U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 5549220554838837145U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 15370309834426476775U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3896803894396631184U;
            aOrbiterG = RotL64((aOrbiterG * 11018830202891911603U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 39U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 58U)) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 21U)) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aPrevious, 38U) + RotL64(aOrbiterD, 5U)) + aOrbiterC) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12109U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 11471U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15220U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 16061U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14532U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13652U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 54U)) + (RotL64(aCarry, 23U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = ((((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 15188686795415908074U) + aPhaseAOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 17310049041983079779U) + aNonceWordH;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 46U)) + 8246925977992441471U) + aNonceWordL;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 8644260919918112781U) + aNonceWordF;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 57U)) + 13401663736874819483U) + aPhaseAOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7940358935238314973U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13278990328548007839U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 285726811877787411U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11346868298353840706U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2374077904806833579U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 1765686942154321425U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6978903378645019166U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11951633297870965212U;
            aOrbiterE = RotL64((aOrbiterE * 12778236598654492185U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17398460995357409673U) + aNonceWordK;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 1215437945597836770U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 9322970054123481621U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1878751468043972239U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5343002808239712390U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11878640995447558811U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterB, 28U)) + aNonceWordD);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 57U) + RotL64(aOrbiterE, 5U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 38U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + aPhaseAWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 47U)) + aNonceWordP) + aPhaseAWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18641U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneA[((aIndex + 20338U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 17637U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21507U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18662U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 18337U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererJ + RotL64(aCross, 5U)) + 13714409587461539863U) + aNonceWordF;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 27U)) + 14101156723903265839U) + aNonceWordA;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 27U)) + 7063754562895369001U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 12320578575245519386U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 11744826789631008424U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8744816505096675597U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10405435520084528645U;
            aOrbiterI = RotL64((aOrbiterI * 13279521344071568023U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1463157688070683543U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 12379603577919617703U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 14858901470015109311U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1343439118031348146U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16118850268070235540U;
            aOrbiterD = RotL64((aOrbiterD * 11184386483735388257U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14116264435819277136U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5251698273012432109U;
            aOrbiterF = RotL64((aOrbiterF * 1495818611622063967U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14806408656041403829U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11569345414052398227U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9913158908301414861U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + aNonceWordJ);
            aWandererG = aWandererG + (((((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 37U)) + aNonceWordK) + aPhaseAWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 14U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 28U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22248U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 23348U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26904U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23832U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25579U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 21948U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 56U)) ^ (RotL64(aIngress, 29U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 9133751643283278896U) + aNonceWordD;
            aOrbiterI = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 8971581804375380408U) + aNonceWordA;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 37U)) + 12559650383714566592U) + aPhaseAOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 15753206088872859163U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aWandererK + RotL64(aScatter, 18U)) + 7640756270450762350U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7340073357551376125U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5270256573644196046U;
            aOrbiterD = RotL64((aOrbiterD * 13286406906662922841U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3567367996479995928U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11939634537492733738U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 5640541900117183639U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 7051817732424527120U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1730487669951837941U;
            aOrbiterH = RotL64((aOrbiterH * 15191634337956285841U), 23U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 18009252467909454817U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2361024272031696442U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15215151562500226027U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15902755877642960397U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12243517544704116184U;
            aOrbiterF = RotL64((aOrbiterF * 2576071074148141447U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 21U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 52U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 12U)) + aOrbiterF) + aNonceWordH);
            aWandererF = aWandererF + ((((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 57U)) + aOrbiterI) + aNonceWordL) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28143U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 28807U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30682U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32505U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29025U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 28524U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 11U)) ^ (RotL64(aCarry, 60U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 12632404972795375757U) + aNonceWordP;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 57U)) + 5351879979055988456U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 29U)) + 3597737727467443413U) + aNonceWordA;
            aOrbiterC = ((aWandererF + RotL64(aCross, 48U)) + RotL64(aCarry, 37U)) + 2830846754917852318U;
            aOrbiterE = ((((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 17311925960294518018U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2083584640523695383U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 15049343611387010158U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5567816356477420399U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6443050378205811147U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 6021965178697344070U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6054064448935006741U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5080289878758029976U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 576927745306972983U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 16008958833683246115U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 4728489691382690859U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6184355840165758855U;
            aOrbiterG = RotL64((aOrbiterG * 1515043910404156423U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11220539885798595450U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11091438724966718214U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 8225347114759391961U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterE, 13U)) + aNonceWordO);
            aWandererA = aWandererA + (((((RotL64(aCross, 36U) + RotL64(aOrbiterD, 23U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordF) + aPhaseAWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterC, 51U));
            aWandererF = aWandererF + (((((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 3U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aNonceWordC) + aPhaseAWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 38U)) + aOrbiterE) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 28U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 19U);
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

void TwistExpander_WaterPolo_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA33456139A48E97BULL + 0xD84A4C5005138888ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC730B9C85B105691ULL + 0xE12027709A54219AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDD824885F9BE5C5BULL + 0x88F7C6CA9B3F36FBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF3F5A4F724813B53ULL + 0x85DCF1D8310B18E2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9A0DBE75253D0A7DULL + 0xD0D6BA47154DF0CDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD90960727ABC3D39ULL + 0xACFDA9D34EEAA130ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDD45326CE8EBEE71ULL + 0xA9B0E1DFB2EF7BB0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD50EBDDB3D07A711ULL + 0xA225470751D11548ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x915C9D1E56B3EA6FULL + 0xA5DE0B72F5223447ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDCE7BAEBACB302FBULL + 0xD307D3182BA4B80BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x95530C2C48D97841ULL + 0x97B89128BD5EA9EDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF26F7054C5D1460FULL + 0xA1FDF38764F34C2EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA89E3609AAD8CDADULL + 0x83F8EC0AFD50224EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xFF58C6EBCABAAA31ULL + 0xA37E579FCCBA5EE9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x87AB3FDB444D025BULL + 0x81F7E88A56CC799DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xABA58FF986AC8005ULL + 0xC4B6C5F2B8168C53ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aExpandLaneC, aInvestLaneC, aExpandLaneD, aFireLaneD, aInvestLaneD, aExpandLaneA, aWorkLaneA, aExpandLaneB, aWorkLaneB, aFireLaneC, aWorkLaneC, aFireLaneA
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 993U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 3294U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 225U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5383U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3019U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4246U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCarry, 3U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 53U)) + 3248574644570178787U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aWandererB + RotL64(aScatter, 47U)) + 4506961512959200024U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 13U)) + 8423739774540738590U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 3U)) + 6593975869641735337U) + aNonceWordD;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 51U)) + 16441716090557369103U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 7936601450453207914U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 29U)) + 13333752583560167065U) + aNonceWordK;
            aOrbiterD = ((aWandererK + RotL64(aCross, 41U)) + 8013703284795432973U) + aPhaseBOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aIngress, 56U)) + RotL64(aCarry, 5U)) + 2349852779887439236U) + aNonceWordI;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5318539364763284138U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11450957608502944376U;
            aOrbiterG = RotL64((aOrbiterG * 1957880366707810635U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9058992558327552687U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 632095686920230926U;
            aOrbiterA = RotL64((aOrbiterA * 12460364388358520799U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 14734218428913777098U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16344357661370784442U;
            aOrbiterB = RotL64((aOrbiterB * 15049472842002138369U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2981145363531184308U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14176472085175714494U;
            aOrbiterJ = RotL64((aOrbiterJ * 2584623327412130939U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11198457590069700889U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 952584436750426828U;
            aOrbiterC = RotL64((aOrbiterC * 1165713888651280355U), 19U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 4311591763498985972U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16194341833989936369U;
            aOrbiterK = RotL64((aOrbiterK * 9997934560195932575U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7560794022401107431U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10683789740265711603U;
            aOrbiterI = RotL64((aOrbiterI * 15637823045351977883U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11614366395125937178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10750771385100564416U;
            aOrbiterD = RotL64((aOrbiterD * 4987921274272444283U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2934697034132204529U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4646873794658020363U;
            aOrbiterH = RotL64((aOrbiterH * 10555456865641580175U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 46U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 39U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 18U)) + aOrbiterG) + aNonceWordN);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 23U));
            aWandererF = aWandererF + (((((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 11U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordB) + aPhaseBWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterI, 27U));
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterK, 51U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 20U) + RotL64(aOrbiterI, 58U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererB, 36U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneD
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8161U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((aIndex + 9461U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7406U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8146U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8146U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8008U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8600U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (aWandererA + RotL64(aScatter, 47U)) + 12027839670755583592U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 30U)) + 15380130703509859843U) + aPhaseBOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aCross, 35U)) + 4590907433867798074U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 1754574023602519724U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 9832756659564903767U) + aNonceWordK;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 5U)) + 5035088494491470403U) + aNonceWordO;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 18U)) + RotL64(aCarry, 57U)) + 14199170923323644638U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 39U)) + 8325619421264440438U) + aPhaseBOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 51U)) + 969534320779067977U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 270575869402913847U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13344806516599578910U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 10193544126281901579U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15143147951139409101U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 14425582489214169238U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 16893787086337916355U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13951127523239064584U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14177925225918293579U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13079514031864998485U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8258920744278218901U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7408161179397242453U;
            aOrbiterK = RotL64((aOrbiterK * 975737128100519169U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8581481606764773468U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10078416198417433133U;
            aOrbiterI = RotL64((aOrbiterI * 1102721083915858247U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 18299772198826189580U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18304668908084397946U;
            aOrbiterG = RotL64((aOrbiterG * 10589455451200578687U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 16729632621573817223U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13362300981585573239U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9824473895535518785U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8629682832849915380U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 6852852009091469641U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 11912646687050011915U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7433098156961745198U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10931806208899417308U;
            aOrbiterF = RotL64((aOrbiterF * 14699197041038067483U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 41U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 18U) + aOrbiterI) + RotL64(aOrbiterG, 27U));
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + aNonceWordF);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterB, 48U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterE, 19U)) + aPhaseBWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 6U) + aOrbiterG) + RotL64(aOrbiterJ, 23U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 4U)) + aOrbiterE) + aNonceWordH);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aExpandLaneA
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aExpandLaneA forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 12178U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 13489U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13093U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12413U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 14898U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 9471546960258473684U) + aNonceWordL;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 18U)) + RotL64(aCarry, 11U)) + 18050235435948942244U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 57U)) + 3005107102671544641U) + aNonceWordA;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 39U)) + 17898396434573801850U) + aNonceWordB;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 23U)) + 15071602525497771648U) + aPhaseBOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 5780119462702672108U) + aPhaseBOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 52U)) + 13301326224151025687U) + aNonceWordC;
            aOrbiterK = (aWandererI + RotL64(aCross, 11U)) + 18129323022260575961U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 3U)) + 1199228670638790709U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1839199978088021020U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4999517042246790165U;
            aOrbiterG = RotL64((aOrbiterG * 4585813675677234577U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8788607633376516299U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15143903839930468749U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12735914889325422675U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16674732686428431869U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15908873150953195581U;
            aOrbiterH = RotL64((aOrbiterH * 18049755517524334107U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11204775359756474667U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2525984309543939465U;
            aOrbiterI = RotL64((aOrbiterI * 3988529812023791571U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4566345170476825512U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14876612901557406267U;
            aOrbiterK = RotL64((aOrbiterK * 9047956948845135339U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14926290877038883931U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12710203178186614846U;
            aOrbiterE = RotL64((aOrbiterE * 14841163494801662515U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7315094513967387996U) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 11050116830482816766U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 3702999495721152019U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 4505368486032503953U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17905748055257551092U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14775870175093453197U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5728886950801376350U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17998141690182325170U;
            aOrbiterA = RotL64((aOrbiterA * 16008599930125391379U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 6U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aCross, 19U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + aNonceWordJ) + aPhaseBWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 12U) + RotL64(aOrbiterE, 18U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterF, 51U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 27U)) + aOrbiterH) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 11U)) + aOrbiterC) + aNonceWordH);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 40U) + aOrbiterA) + RotL64(aOrbiterC, 36U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 57U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 43U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aExpandLaneB
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aExpandLaneB forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19162U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((aIndex + 20130U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19883U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21423U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((aIndex + 21439U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aIngress, 56U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 7948891781097675369U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 35U)) + 13928362874228230226U) + aNonceWordN;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 52U)) + 10776180542602258926U) + aNonceWordK;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 5735115172149470447U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 27U)) + 5353591822981766987U) + aNonceWordD;
            aOrbiterK = (aWandererA + RotL64(aIngress, 57U)) + 562301708107268570U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 13U)) + 10467810247578364868U;
            aOrbiterC = ((((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 14541630141152308564U) + aPhaseBOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aWandererE + RotL64(aScatter, 22U)) + 2350076897065139429U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17519109078651162228U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6061035173339902910U;
            aOrbiterJ = RotL64((aOrbiterJ * 10021905773432907835U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15654836633731000065U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 13723521735153718904U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14459516479283070563U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2849680038315532197U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17336102435576647923U;
            aOrbiterD = RotL64((aOrbiterD * 10984689101753586739U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7671010488872356142U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11485114338165600777U;
            aOrbiterH = RotL64((aOrbiterH * 4162584865462407791U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8759060657343458985U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11009137869375286581U;
            aOrbiterF = RotL64((aOrbiterF * 8741417343929809115U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15792999392743144135U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6180808423175992479U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13681230339693676907U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 361487389591183005U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 15292753806514404853U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 17478232597253311153U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 14929153438443362045U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 7904556383593914086U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 2484130486635511403U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3793180909904286848U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 10391957637467171320U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 505484041943467117U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 44U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + aNonceWordM) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterC, 20U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 13U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI + ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterF, 5U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterA, 58U)) + aNonceWordE) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 36U) + aOrbiterI) + RotL64(aOrbiterC, 29U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 42U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25353U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneD[((aIndex + 22038U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 25257U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24970U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneC[((aIndex + 26240U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 26U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 16189787374324972735U) + aNonceWordB;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 39U)) + 17563763730956242224U;
            aOrbiterH = (aWandererF + RotL64(aCross, 5U)) + 10572803498593789385U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 35U)) + 7713105232072974166U) + aPhaseBOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 56U)) + 10760839534772718139U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 13397069448391230253U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 47U)) + 4569255679998375682U) + aNonceWordG;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 9888769350817876949U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 52U)) + 11351796060878856300U) + aNonceWordI;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 18153775071965707204U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1282846411145853435U;
            aOrbiterH = RotL64((aOrbiterH * 12294455920906257823U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16457743979262460660U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 173493260775251032U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4935807229040883505U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 3927345926316409630U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5158769729850853623U;
            aOrbiterI = RotL64((aOrbiterI * 2446452358663812945U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12331351600010165154U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3940794200348684050U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 13248997263062075043U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11248514843822945425U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1391497323278226522U;
            aOrbiterD = RotL64((aOrbiterD * 8376841806072565005U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13265623528678787307U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2802033745265647317U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 3437626962562016147U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6938444301018051844U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1086544666755559028U;
            aOrbiterG = RotL64((aOrbiterG * 16039728388882079889U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16156443117365816536U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3619942859562697142U;
            aOrbiterC = RotL64((aOrbiterC * 7589346043159112151U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17681848914912743292U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8848238631758130416U;
            aOrbiterB = RotL64((aOrbiterB * 810402256099500607U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 6U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 23U)) + aPhaseBWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 28U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 39U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aScatter, 34U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterB, 43U));
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterD, 10U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterG, 57U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31442U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 28464U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 29360U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28551U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 29297U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 56U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (aWandererF + RotL64(aCross, 51U)) + 5906639480605353429U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 35U)) + 5293518570213287605U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 47U)) + 15383185501428521377U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 18U)) + 15364072512743978902U) + aNonceWordP;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 4525473357144014271U;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 10400911938125603074U) + aNonceWordM;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 16417506293824627550U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 10U)) + 2419329331753341815U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 27U)) + 14929222427923332069U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 16771573504983922586U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1863466450051787622U;
            aOrbiterK = RotL64((aOrbiterK * 2585626547126027053U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 12895350137096692415U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3700979086526298327U;
            aOrbiterJ = RotL64((aOrbiterJ * 10279730254867618193U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1977099106211282426U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6144698304096915742U;
            aOrbiterI = RotL64((aOrbiterI * 5039822990560519609U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 3858895556659724975U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1283646340363435327U;
            aOrbiterD = RotL64((aOrbiterD * 11622421841377018069U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6240532051889108891U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 757364889381634634U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 943852137901972945U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5272945693977418174U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6850528198786172283U;
            aOrbiterH = RotL64((aOrbiterH * 1966383079897679953U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14431587733859573714U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16124590257870999553U;
            aOrbiterB = RotL64((aOrbiterB * 7755796211433191143U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14912695018110241411U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11098623474413346520U;
            aOrbiterA = RotL64((aOrbiterA * 15167688959990872051U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3484847683376368686U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2295388097292719800U;
            aOrbiterG = RotL64((aOrbiterG * 1240808318176106909U), 53U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (RotL64(aOrbiterE, 24U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterH, 28U)) + RotL64(aCarry, 37U)) + aNonceWordA) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 30U) + aOrbiterK) + RotL64(aOrbiterJ, 11U));
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 5U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterE, 19U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterA, 57U));
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 24U) + aOrbiterK) + RotL64(aOrbiterE, 43U)) + aPhaseBWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterB, 50U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_WaterPolo_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8FDC521CA11BB325ULL + 0xBB466D7084B902DAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE24F9F1178F6BD93ULL + 0xABD7FFC5E2EC25C2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE568F78EC4D7A17DULL + 0xF8E3D3E3AC2EA390ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE5D6CDC2BC2174DFULL + 0xF1C15C6167D0FDFFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD077722DC11C8CB7ULL + 0xD4D260248B5CE230ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF89ED7735B8FD6AFULL + 0xB8DF23F59CDF1DCBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC86CDFA6069D7AFDULL + 0xBF56D1045D24329CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD0C77F4E62034AC7ULL + 0xA0881F3103EF9F8CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA7D5FA7E258C973BULL + 0xD44ADC585F66BDD3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x926CFC42BA1B8EDFULL + 0xF6CAA653F4CD979AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE063D841A7FB7FD1ULL + 0x85209AEAEAD6C8F1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB283F01160FE8B77ULL + 0xDD2D9E62782F7787ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x871CE829B9771B8FULL + 0xF6369F5017B8D67CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC681E1BDADDB5BF5ULL + 0xECC1F67AEBC7BB33ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD31F6C22FBFA372BULL + 0x8DAE8785028CDF2DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB3DF1D2CE5A4D5AFULL + 0xA92E49CC27DD0C95ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2089U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 897U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 4315U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4524U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3249U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 4401U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 39U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 5160910997561396461U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 23U)) + 14920764751058512062U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 11U)) + 6080952401749660022U) + aNonceWordE;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 17667234330526298627U) + aPhaseDOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 760630072638686756U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 41U)) + 3504157162816997476U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 50U)) + 9489022223422585882U) + aNonceWordN;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1149898536879968964U) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 10492284328940025310U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7893416766300156495U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13213275606286399312U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 10557118912847180413U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10077877991284587845U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15618980209023994776U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5268600749854045564U;
            aOrbiterD = RotL64((aOrbiterD * 3849660559223919613U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8011552687609649990U) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 3148133096349525066U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 5245156554959620007U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12032847944237867285U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14999005703490824673U;
            aOrbiterG = RotL64((aOrbiterG * 6631584955208646049U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5426735969392906710U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3593177531650386729U;
            aOrbiterK = RotL64((aOrbiterK * 12997284886192717043U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1701444719333347373U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 15928731228196894960U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1919318226904213433U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 10U) + RotL64(aOrbiterD, 53U)) + aOrbiterC) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + aNonceWordM);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 21U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 29U)) + aOrbiterF) + aNonceWordA);
            aWandererG = aWandererG + ((((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterC, 12U)) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 47U)) + aOrbiterG) + aPhaseDWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterK, 37U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7745U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 7449U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8820U)) & S_BLOCK1], 22U) ^ RotL64(aInvestLaneC[((aIndex + 5832U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5695U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6757U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 9030U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 44U)) ^ (RotL64(aCross, 57U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 12U)) + RotL64(aCarry, 57U)) + 4848316479321533394U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 57U)) + 6919360256662636195U) + aNonceWordI;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 9897013582181108544U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 7319353809896158678U) + aPhaseDOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 29U)) + 2848175435514849859U) + aNonceWordF;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 5U)) + 6967780718720437934U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 19U)) + 10143884766603388136U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8675965006150972051U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 16350117755560994281U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 15072308930382994425U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17976597517118423760U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1399631141355370237U;
            aOrbiterK = RotL64((aOrbiterK * 16537788276543236833U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3590613762034716792U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5134624314245932157U;
            aOrbiterB = RotL64((aOrbiterB * 13077589037975283371U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 10082236952942943654U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4015535035905433450U;
            aOrbiterJ = RotL64((aOrbiterJ * 4961808568701908559U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 611474103801573800U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5786708483794098001U;
            aOrbiterF = RotL64((aOrbiterF * 7694007039340089267U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5201943497363274455U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 9282160506938328489U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5368182164239021367U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4932320527498940158U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11576526341731392916U;
            aOrbiterH = RotL64((aOrbiterH * 1712051774729439363U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 53U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 30U) + aOrbiterH) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterG, 47U));
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + aNonceWordD);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF) + aNonceWordK) + aPhaseDWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterG, 10U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14620U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 14599U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13137U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13806U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 13839U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (((aWandererG + RotL64(aScatter, 53U)) + 4259993311776766595U) + aPhaseDOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 2857813330021126753U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 19U)) + 1345396841329442896U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 320992148982301024U) + aNonceWordB;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 47U)) + 5619109532065293074U) + aNonceWordH;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 10380157329426706345U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 60U)) + 12449831150625409695U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7847096607042268396U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11707184096803214678U;
            aOrbiterF = RotL64((aOrbiterF * 1959476948106553973U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9893643746186827088U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 333687403830908774U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17911256836121454271U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 13837360705077441580U) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 4367119682175710689U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10295744669174603401U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1193493435041306784U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15062951612027370606U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2509383510565136549U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16000173839235429105U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15294482444605409961U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1031800997944302665U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5720749055549773527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17248674962996093668U;
            aOrbiterK = RotL64((aOrbiterK * 15730637462755795591U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16956840483882091059U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9637715107943515594U;
            aOrbiterB = RotL64((aOrbiterB * 8878362378343603463U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterD, 57U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 35U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterE, 43U)) + aNonceWordJ) + aPhaseDWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 56U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + aNonceWordF) + aPhaseDWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterG, 10U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 19093U)) & S_BLOCK1], 34U) ^ RotL64(aSnowLaneA[((aIndex + 20680U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18293U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20149U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19724U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aIngress, 47U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 1297415699043177788U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 17583786534509260153U) + aNonceWordJ;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 28U)) + RotL64(aCarry, 57U)) + 643197858925708798U) + aNonceWordF;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 57U)) + 5062653766915694874U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 41U)) + 7034273638367180511U) + aPhaseDOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 3U)) + 2026909726972916996U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 35U)) + 2785690475553211646U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2910341716302991892U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2834181605200829791U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1510617068750957651U), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 13323052600571281928U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10434901530315760460U;
            aOrbiterD = RotL64((aOrbiterD * 2042210188346767033U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 247903955625194782U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 5196515747387257163U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 1799024689023272275U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7196305682377987476U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14777739876892587484U;
            aOrbiterF = RotL64((aOrbiterF * 95220583948241581U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10609060796540136671U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8386027207212484155U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 4855610536246556893U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 729659744301903424U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2350564261412606157U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16713856782349084977U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 16611987556673864177U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1525195188708550503U;
            aOrbiterI = RotL64((aOrbiterI * 10045858602151004553U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 21U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterF, 5U)) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aCross, 50U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + aPhaseDWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterB, 50U)) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterB, 21U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24594U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneB[((aIndex + 24190U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 22092U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25040U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 23708U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 13880995121909552664U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 35U)) + 14534942818069300546U) + aNonceWordJ;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 12U)) + 17745973100886007133U;
            aOrbiterD = ((((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 2249805580771946872U) + aPhaseDOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aWandererB + RotL64(aScatter, 57U)) + 4460116116396439410U;
            aOrbiterF = (aWandererE + RotL64(aCross, 29U)) + 3378683994078106878U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 3992996501048809123U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12057768808864451929U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4115362079047921130U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12263015903331031345U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15297384955502206698U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17623548383481905636U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7487278217901483685U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3559213898000162417U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12311605719074507335U;
            aOrbiterD = RotL64((aOrbiterD * 3982199462062847697U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14807313864347885885U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11222085523291581822U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12580941911587215653U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 916681229436292462U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2441350114032314686U;
            aOrbiterJ = RotL64((aOrbiterJ * 7336079498999018067U), 37U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 7361470539894653271U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12153585147213579808U;
            aOrbiterF = RotL64((aOrbiterF * 3040327545467672961U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13566300726101613579U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14875254144748509128U;
            aOrbiterG = RotL64((aOrbiterG * 13699179902908972403U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 30U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + aNonceWordN) + aPhaseDWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterG, 41U));
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterG, 53U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + aNonceWordL);
            aWandererF = aWandererF + ((((RotL64(aCross, 12U) + aOrbiterH) + RotL64(aOrbiterF, 6U)) + RotL64(aCarry, 29U)) + aNonceWordD);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 18U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 31971U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneA[((aIndex + 28596U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31736U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32021U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28814U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 13U)) + 9041099828460168106U) + aNonceWordH;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 47U)) + 12883711604096848454U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 58U)) + RotL64(aCarry, 39U)) + 17420968786226443079U) + aNonceWordA;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 5U)) + 3448213891716125104U) + aPhaseDOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (((aWandererB + RotL64(aIngress, 27U)) + 11866455977445336560U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 4119356835384495905U) + aNonceWordC;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 2186212599698637068U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6506144898969301620U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12556800923644051626U;
            aOrbiterG = RotL64((aOrbiterG * 15961043406612913121U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 4075551535185182945U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17877694808492008749U;
            aOrbiterE = RotL64((aOrbiterE * 901315308379887473U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5553428900598223316U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14362304852277160675U;
            aOrbiterK = RotL64((aOrbiterK * 11415103199856419303U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9174200302876075831U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16110739511917638547U;
            aOrbiterA = RotL64((aOrbiterA * 7004356839428657949U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10189881974519849402U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2128076632642616677U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8860453653433114929U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18133523799074400083U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9916472958834153766U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 3454601168808001733U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10274457562795569227U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14134814273275356425U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15912501063665343159U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 29U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 23U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 43U)) + aOrbiterA) + aNonceWordL);
            aWandererB = aWandererB + ((((RotL64(aCross, 21U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterI, 37U)) + aNonceWordK) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 4U) + RotL64(aOrbiterI, 21U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterG, 4U)) + aOrbiterE) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 28U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_WaterPolo_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBF381573A51771E5ULL + 0xCADC3F32BD9260F7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE5F3016D10D543E5ULL + 0xFC02ACA5BA9783D9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF83C5F2184B59ECDULL + 0xEB7E25B344DD54E2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9888653293AAC5CDULL + 0xCD0213FC9062983BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCFD7381917FA73A1ULL + 0xC29A6AAF9D90683EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC560C238CB992A9BULL + 0x8B349791D4FA3DC1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB25F38230489DF99ULL + 0xDF38AE9D8E2F40FDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBB5B7F7082F49339ULL + 0xADF0360E9E36B78AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC99ED8F1C59B7D33ULL + 0xE3445C2FC2C62EE5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x90024D5DC471C4BFULL + 0xDBDAC95B92BDD635ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x90915BCB29044E37ULL + 0x8AF991E193EB0008ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB555B43FA3206FEDULL + 0xB016B57B60A245ECULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAB3C204D087CC183ULL + 0xC0DB2C4382183CFEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x93707733A63C1D93ULL + 0x9F703117038E8FE3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9036166614083D39ULL + 0x8D15BFD674FC02BBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB1C1B705402F692DULL + 0x97E4ADEA395EB9EFULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 3037U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneB[((aIndex + 1338U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5221U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 7U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 4291U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3310U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = ((((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 11698283336767769359U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererD + RotL64(aCross, 46U)) + 13297826354831483872U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 21U)) + 15254999058287530795U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 5U)) + 17474166585085346567U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 27U)) + 15684783498452840289U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 19U)) + 5061229733465216486U) + aPhaseEOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aWandererE + RotL64(aCross, 37U)) + 15370981279168377944U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 11U)) + 17966672773619554092U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 14685092893994491068U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 60U)) + 12798804186209406389U) + aNonceWordF;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 2848444181474221574U) + aNonceWordH;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8551142075919636146U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8833198159158950723U;
            aOrbiterC = RotL64((aOrbiterC * 7650289040764974737U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7351473160893666232U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14204899612487622222U;
            aOrbiterI = RotL64((aOrbiterI * 6317485031956448029U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 7008985178526543258U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13576796403863120356U;
            aOrbiterJ = RotL64((aOrbiterJ * 13745839827679114077U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5769784656937900699U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14075925808204936705U;
            aOrbiterE = RotL64((aOrbiterE * 5844894088757604713U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17818667502858010896U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16016922065572683130U;
            aOrbiterA = RotL64((aOrbiterA * 7525645833898085373U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1582458237855075977U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10830440354527138227U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10499386926982228251U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10653964151654643772U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11218475491129483859U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 3338108067044357141U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9863649760189649255U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 13790281439048354358U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 4682098083538482849U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14846954923718136337U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 522207783972623813U;
            aOrbiterD = RotL64((aOrbiterD * 14299798934454852811U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 426829715716262697U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7482977730216354509U;
            aOrbiterK = RotL64((aOrbiterK * 6317437989422015173U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10736099808538972990U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11698283336767769359U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17230175904095995929U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 48U) + aOrbiterF) + RotL64(aOrbiterG, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterI, 12U));
            aWandererI = aWandererI + (((((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aNonceWordA) + aPhaseEWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterH, 21U)) + aNonceWordI) + aPhaseEWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 23U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 43U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 41U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 10U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterC, 39U));
            aWandererH = aWandererH + (((RotL64(aCross, 46U) + RotL64(aOrbiterA, 53U)) + aOrbiterD) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 22U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 8485U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((aIndex + 10646U)) & S_BLOCK1], 30U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7306U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 9311U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 10760U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10567U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9403U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 54U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = ((aWandererF + RotL64(aCross, 57U)) + 17912271996338180948U) + aNonceWordP;
            aOrbiterC = (aWandererI + RotL64(aIngress, 23U)) + 13259276608841847058U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 30U)) + RotL64(aCarry, 29U)) + 16225936008657276089U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 37U)) + 2243058962151834071U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 53U)) + 10637439274127347861U) + aPhaseEOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aIngress, 11U)) + 15312219216405992627U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 51U)) + 2393933972129878613U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 13U)) + 4327069337247976513U) + aNonceWordJ;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 47U)) + 8307656353434167837U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 17299145556933889336U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 6U)) + RotL64(aCarry, 51U)) + 14458100581172798164U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6410095654927998067U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6168964796264687686U;
            aOrbiterA = RotL64((aOrbiterA * 16218071040190475953U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3667999465041020730U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 16021552859323602007U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6427266472526362663U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12941668202330045095U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4222032891850449934U;
            aOrbiterB = RotL64((aOrbiterB * 17292856787431308097U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 1346342592002730785U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16860611785008118820U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 384963420804756607U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3193572711804730241U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5866881282680588589U;
            aOrbiterE = RotL64((aOrbiterE * 9226331800853634597U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 17180332731328479126U) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10222097519535882241U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 9422887302872778795U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8863502179821584859U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14872318155712512999U;
            aOrbiterH = RotL64((aOrbiterH * 11830641277356873233U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16478790641892781150U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8414944141232294781U;
            aOrbiterI = RotL64((aOrbiterI * 17443775794621154023U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13204056527590476037U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15084952142545813228U;
            aOrbiterJ = RotL64((aOrbiterJ * 17183888602469193015U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13051035678904490854U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17565188004293304987U;
            aOrbiterF = RotL64((aOrbiterF * 12785271107667631897U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 814245676602237400U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17912271996338180948U;
            aOrbiterC = RotL64((aOrbiterC * 14557769257469623169U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 50U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 54U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 43U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 46U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterC, 39U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterA, 13U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 36U)) + aOrbiterI) + aNonceWordL);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterD, 11U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 56U) + aOrbiterF) + RotL64(aOrbiterE, 29U)) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 20U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 13229U)) & S_BLOCK1], 12U) ^ RotL64(aInvestLaneA[((aIndex + 16200U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 12582U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15071U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12798U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 12U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((aWandererK + RotL64(aCross, 30U)) + RotL64(aCarry, 27U)) + 4980738603982643969U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 13U)) + 17660278413018470020U) + aNonceWordI;
            aOrbiterD = (aWandererD + RotL64(aIngress, 11U)) + 17598114429859543466U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 19U)) + 10993929335279994739U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 26U)) + 17967203122976322481U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 37U)) + 1872290205549034384U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 16607778671782810797U) + aNonceWordO;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 23U)) + 4895226930754394376U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aWandererE + RotL64(aCross, 53U)) + 14960359005982301383U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 41U)) + 9921642352377700630U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 893281964367208693U) + aNonceWordD;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8232519988397858732U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4433022122758913407U;
            aOrbiterD = RotL64((aOrbiterD * 834240393225479419U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12689609831247168353U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 404535388957472176U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14534020545479806593U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3349108201964013155U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4386449511297371730U;
            aOrbiterI = RotL64((aOrbiterI * 9596273264321140229U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14314587717949070586U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10923886625271054985U;
            aOrbiterK = RotL64((aOrbiterK * 7838969002623486809U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17634909585329833520U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2021301459918350372U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1388242915918642741U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5219599112498224367U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10641339455385046206U;
            aOrbiterH = RotL64((aOrbiterH * 1022283727595400719U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5003342156562330058U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10951027475628404336U;
            aOrbiterA = RotL64((aOrbiterA * 17836928292555158461U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13040991872592235460U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11149099984302782267U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4248667283139686251U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2202253777854402763U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16679038924474862612U;
            aOrbiterG = RotL64((aOrbiterG * 2624443661523083597U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1959650241410955571U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8415989510614674816U;
            aOrbiterB = RotL64((aOrbiterB * 16340289102832732519U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2344501711730399821U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4980738603982643969U;
            aOrbiterC = RotL64((aOrbiterC * 6419275275477478723U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterF, 13U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 58U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + aNonceWordM);
            aWandererC = aWandererC + ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterJ, 41U)) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterG, 21U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 3U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterF, 56U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ) + aNonceWordL) + aPhaseEWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererG, 6U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20889U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneA[((aIndex + 20056U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 19784U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16826U)) & S_BLOCK1], 6U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17658U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 26U) + RotL64(aCross, 13U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 53U)) + 12535417189990029950U) + aNonceWordL;
            aOrbiterG = ((aWandererI + RotL64(aCross, 19U)) + 6204401443676390273U) + aNonceWordA;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 28U)) + 869613505613154672U) + aPhaseEOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 13U)) + 15053590879563855802U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 13338989605204591428U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 21U)) + 18306470022403825392U) + aNonceWordB;
            aOrbiterI = ((((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 1150696349434090218U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 13549541786420596437U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 5U)) + 14302878430259588461U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 11U)) + 4660437084477165225U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 24U)) + 1653628537860912069U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5594199757006711631U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11008472193138708891U;
            aOrbiterE = RotL64((aOrbiterE * 13645764762027798301U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3668516817279364310U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 128159531749679984U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 4523246859249826987U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6378674346113979108U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11438762460659123362U;
            aOrbiterG = RotL64((aOrbiterG * 2733309638158283953U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10624263004446482910U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12546839706919241411U;
            aOrbiterJ = RotL64((aOrbiterJ * 11468326687628079347U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8466639576503293921U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5828694979857951504U;
            aOrbiterF = RotL64((aOrbiterF * 7835487310289634515U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16496305151014092976U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 589464613876410567U;
            aOrbiterI = RotL64((aOrbiterI * 13190816610718051897U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4168532743415647825U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15944887793736489375U;
            aOrbiterB = RotL64((aOrbiterB * 17273403561158196717U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 11642456814106259483U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1609897693632334867U;
            aOrbiterH = RotL64((aOrbiterH * 12912773555616819941U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14950238412766325479U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11862438528287402255U;
            aOrbiterA = RotL64((aOrbiterA * 7635864312080265695U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5900629306795222263U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3221591991392500536U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7188525011266868855U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16938699391746264010U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12535417189990029950U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18212319484142613215U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 50U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterI, 53U)) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 3U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterH, 23U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterB, 56U));
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 20U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 23U)) + aNonceWordF);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 43U)) + aOrbiterF) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 46U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterI, 29U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 42U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23014U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneB[((aIndex + 24020U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24817U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26530U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21858U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 26165U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 23U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 28U)) + 16016931609704150191U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 5U)) + 14511433515861302636U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 37U)) + 11691237442613269593U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 3U)) + 16383220587320484649U) + aPhaseEOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 47U)) + 14293015313458219868U) + aNonceWordI;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 58U)) + RotL64(aCarry, 19U)) + 4407695248205526670U;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 43U)) + 1158323195324398372U) + aPhaseEOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = (((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 6577683409653864555U) + aNonceWordE;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 39U)) + 171080079472863843U) + aNonceWordP;
            aOrbiterD = (aWandererK + RotL64(aCross, 35U)) + 5766333425872228205U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 13U)) + 16173508656917582960U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11781450063402219202U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13033139686637576694U;
            aOrbiterK = RotL64((aOrbiterK * 4331137994135472025U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4006310759400926020U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13156817947481574467U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 563189239835001483U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12791290558893516411U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 989729955679243234U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8757228712495095017U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 838379839663022790U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2830743864262313606U;
            aOrbiterE = RotL64((aOrbiterE * 10173947177104802797U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2146646527331684652U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 4629168181742174906U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9046124907945045131U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1150129989168501777U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 619659995945229440U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 13734821008174603409U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8120315647582116952U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13754584116324996165U;
            aOrbiterC = RotL64((aOrbiterC * 12295486140772079747U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6084566798869999580U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5731665119233722504U;
            aOrbiterB = RotL64((aOrbiterB * 5921510209025133639U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16134513471149338456U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9841695976256666234U;
            aOrbiterH = RotL64((aOrbiterH * 7417023101762286049U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2559042046155066240U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14065288635273112125U;
            aOrbiterA = RotL64((aOrbiterA * 10464173719695109147U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18228257734024217020U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16016931609704150191U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 2874343578276710555U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 35U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterK, 51U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterC, 60U)) + aNonceWordD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterC, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterA, 37U));
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 30U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 51U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterK, 53U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 43U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31822U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 27950U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27766U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27862U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29231U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 14U)) + RotL64(aCarry, 43U)) + 13204735390996728477U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 851171359595647173U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 16745304202825290723U) + aNonceWordF;
            aOrbiterI = ((aWandererH + RotL64(aCross, 5U)) + 562392736584913979U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 51U)) + 3244267012529053918U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 43U)) + 17282536111067869133U) + aNonceWordJ;
            aOrbiterG = (aWandererI + RotL64(aCross, 39U)) + 14851130066471729068U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 47U)) + 5256130407952363129U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 60U)) + 2904742485828362001U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 29U)) + 3723346325449225387U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 37U)) + 5344621093694027341U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12919263300833603026U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17989801264160996071U;
            aOrbiterE = RotL64((aOrbiterE * 15468293047311883751U), 43U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 5022175042377172157U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16684822380107847758U;
            aOrbiterC = RotL64((aOrbiterC * 2834049270263837537U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2740326510600876682U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13981423865219318820U;
            aOrbiterF = RotL64((aOrbiterF * 14593082145080056441U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 231945878229848395U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14139797734944312580U;
            aOrbiterH = RotL64((aOrbiterH * 6492256080432266407U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16704102101387552373U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 8506734780526852552U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 4684566118627414659U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2774630043988894695U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12490034334296488127U;
            aOrbiterI = RotL64((aOrbiterI * 16765455396278233145U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 545238171291436006U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1023872898002379590U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 8626333831510136515U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5065187021047872560U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10391809965648089863U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10912471108849550469U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5576919045471579002U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9761904001375034639U;
            aOrbiterD = RotL64((aOrbiterD * 8612901811320541361U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2001472279505185946U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11576457012366242134U;
            aOrbiterG = RotL64((aOrbiterG * 1070815118051466731U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17713147845216099336U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13204735390996728477U;
            aOrbiterK = RotL64((aOrbiterK * 10889281795183444943U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 36U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 56U) + aOrbiterB) + RotL64(aOrbiterC, 41U)) + aNonceWordM) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 51U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 57U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 30U) + aOrbiterI) + RotL64(aOrbiterJ, 27U));
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 43U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterF) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 13U)) + aOrbiterE) + aPhaseEWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterD, 22U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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

void TwistExpander_WaterPolo_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8D4F4065C3E1564BULL + 0x95E0138789481E7AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFEFB30A68A3FA5F1ULL + 0x8EE6B56C262950C7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD36655CBB85B3B5FULL + 0xDAB78F700EDB4C46ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFE229861E1894039ULL + 0xB32FE59BF0BD326BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFB994DC7A6BE8B19ULL + 0x89BB0472633458EDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBFCA04AB318C19D9ULL + 0xE67DC8E47490C26FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE11F59119D811B0BULL + 0xAAB9F23B98108BABULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9F6132C065AAAC41ULL + 0xB0A6C159CBF5AF04ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC3EC9AE5F5AB95EDULL + 0xB1DA7C5270E10771ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x97EC3F477A7BDD23ULL + 0x992DC005E6CA2AF9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFAEB26DFDC5EFDBFULL + 0x9476A94C2CADD090ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB6D6F66512C2DDEBULL + 0x92607551F2C0FAAAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF9A30024876A5B59ULL + 0x8A7F14F0B3049885ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE2CAC16871D4234FULL + 0xAD8FFC13DA81DEA0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x812CAF4BD621F51BULL + 0xCED57B0CC92DBD53ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA52F04306B4BD791ULL + 0xFC0097D6F8E7C897ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneC, aWorkLaneC, aSnowLaneB, aSnowLaneD, aSnowLaneA, aExpandLaneA, aInvestLaneB, aExpandLaneB, aInvestLaneA, aExpandLaneC, aInvestLaneD
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5193U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((aIndex + 1415U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 2790U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4812U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 564U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 1992U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (aWandererE + RotL64(aIngress, 43U)) + 6069475454765660321U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 30U)) + 11483704742497268068U;
            aOrbiterH = (aWandererI + RotL64(aCross, 3U)) + 11055697447388986418U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 10897095046039997004U) + aNonceWordC;
            aOrbiterB = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 4731637118230457840U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 13855839187084986751U) + aNonceWordG;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 35U)) + 5328208115460188239U) + aNonceWordP;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 50U)) + 12479538544291412985U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 19U)) + 10740165998792608231U) + aPhaseFOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 6492798157284955373U) + aNonceWordE;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13056825957483891921U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14882112110627751751U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2068184064919194657U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5656302738780746294U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 16493021179127646345U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11193756120230763294U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17306750816837208999U;
            aOrbiterA = RotL64((aOrbiterA * 7949360041241439741U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12952818800389361804U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15380412293642628312U;
            aOrbiterJ = RotL64((aOrbiterJ * 2914662289178925547U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7706090204767242996U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14598802276412649570U;
            aOrbiterE = RotL64((aOrbiterE * 4821408736292041399U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 17819762117328075515U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6481384240915075101U;
            aOrbiterG = RotL64((aOrbiterG * 4836701121865783029U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 754936290510338717U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15510875946573720154U;
            aOrbiterF = RotL64((aOrbiterF * 2994718968852184303U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9245381722813944586U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2629847912019726214U;
            aOrbiterB = RotL64((aOrbiterB * 6718795794951106961U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3909987749797113773U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9277056074757335265U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11580847505996697115U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 38U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 52U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + aNonceWordO);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterH, 58U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 11U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterC, 37U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 24U) + aOrbiterB) + RotL64(aOrbiterA, 27U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 48U)) + aOrbiterG) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aSnowLaneC[((aIndex + 9126U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 5494U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9442U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6717U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5985U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8702U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aSnowLaneB[((aIndex + 5659U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 51U) + RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 4980738603982643969U) + aNonceWordL;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 17660278413018470020U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 53U)) + 17598114429859543466U) + aPhaseFOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 58U)) + 10993929335279994739U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 29U)) + 17967203122976322481U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 1872290205549034384U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 19U)) + 16607778671782810797U) + aPhaseFOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 14U)) + 4895226930754394376U) + aNonceWordO;
            aOrbiterD = (aWandererE + RotL64(aCross, 39U)) + 14960359005982301383U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9921642352377700630U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 893281964367208693U;
            aOrbiterK = RotL64((aOrbiterK * 2345509157333444217U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8232519988397858732U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4433022122758913407U;
            aOrbiterH = RotL64((aOrbiterH * 834240393225479419U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12689609831247168353U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 404535388957472176U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14534020545479806593U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3349108201964013155U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4386449511297371730U;
            aOrbiterD = RotL64((aOrbiterD * 9596273264321140229U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14314587717949070586U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10923886625271054985U;
            aOrbiterI = RotL64((aOrbiterI * 7838969002623486809U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17634909585329833520U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2021301459918350372U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 1388242915918642741U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5219599112498224367U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10641339455385046206U;
            aOrbiterA = RotL64((aOrbiterA * 1022283727595400719U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5003342156562330058U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10951027475628404336U;
            aOrbiterB = RotL64((aOrbiterB * 17836928292555158461U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13040991872592235460U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11149099984302782267U;
            aOrbiterG = RotL64((aOrbiterG * 4248667283139686251U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 56U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterK, 28U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterA, 43U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 48U) + aOrbiterC) + RotL64(aOrbiterJ, 5U));
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterB, 52U)) + aNonceWordK);
            aWandererH = aWandererH + ((((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 12U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + aNonceWordH);
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aSnowLaneA
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aSnowLaneA forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 12677U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 16128U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 15368U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15529U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14187U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 53U)) + (RotL64(aCarry, 10U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (aWandererA + RotL64(aScatter, 35U)) + 3448371607470865612U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 58U)) + RotL64(aCarry, 21U)) + 3743742913651580573U) + aNonceWordC;
            aOrbiterC = (aWandererD + RotL64(aIngress, 51U)) + 13069491287948807280U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 47U)) + 16872779275586545632U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 17945792656755062795U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aCross, 5U)) + 18199747196793731853U) + aNonceWordN;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 18U)) + 15953311878379809513U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 13U)) + 941268763494588338U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 10090221530365796809U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8335698093307607001U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6147498804734306100U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6904444049941211327U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5980246079567570090U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4152167624425912978U;
            aOrbiterK = RotL64((aOrbiterK * 10019421651535123573U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14990418790239735916U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3418668387496597219U;
            aOrbiterJ = RotL64((aOrbiterJ * 12814077238529863119U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4206650904177199425U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 3905470780938996069U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16030122739273137005U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9968672788233080924U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 602258075661864866U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 2615726693066300065U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17751667243048041383U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2414054413585296027U;
            aOrbiterA = RotL64((aOrbiterA * 1049512574773201893U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6523322402744047752U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6729901917767398779U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 8039939871405367139U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11460169185076814539U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 7559640379553110573U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 9864654321914036135U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 17271150091827475028U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3541809324556914646U;
            aOrbiterF = RotL64((aOrbiterF * 12655168871428868639U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 47U)) + aNonceWordH);
            aWandererE = aWandererE + ((((RotL64(aScatter, 28U) + aOrbiterK) + RotL64(aOrbiterF, 19U)) + aNonceWordI) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 23U)) + aOrbiterA) + aNonceWordD);
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterB, 43U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 30U));
            aWandererF = aWandererF + (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 52U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18985U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneC[((aIndex + 19015U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 18517U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17469U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20772U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 46U)) + RotL64(aCarry, 3U)) + 16451272412693907816U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 35U)) + 10099485419723255462U) + aNonceWordB;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 3U)) + 17668900099534923192U) + aNonceWordF;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 5497093724143181753U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 11U)) + 10354044773550071706U) + aPhaseFOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 57U)) + 12728258851198019099U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 39U)) + 4144050505314242618U) + aNonceWordD;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 22U)) + RotL64(aCarry, 37U)) + 14133805325480076530U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 53U)) + 308863673210602899U) + aNonceWordK;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11741180130160569753U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12926863156769180448U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 9726030996091054939U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 211920854786494259U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13234608842479411078U;
            aOrbiterH = RotL64((aOrbiterH * 2556747209733759467U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9164711974854618892U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6667377062281954219U;
            aOrbiterF = RotL64((aOrbiterF * 2603737166987437649U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4559040002406721850U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1749875480850675109U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15822640067349481089U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9555365165561936366U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 18289733999504213574U;
            aOrbiterE = RotL64((aOrbiterE * 14156217554673229429U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8727162691639622461U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 291406782452963706U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 8413500075082350243U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8294911802626492257U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15853578397277298548U;
            aOrbiterB = RotL64((aOrbiterB * 13256191781365357747U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 11535146194939658681U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2177540476748375661U;
            aOrbiterK = RotL64((aOrbiterK * 15791341922007841029U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2705306323728084136U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17617871830709148043U;
            aOrbiterA = RotL64((aOrbiterA * 3449981219502809255U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 30U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 42U) + RotL64(aOrbiterB, 48U)) + aOrbiterE) + aNonceWordH) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterC, 37U)) + aNonceWordC) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterG, 19U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterG, 52U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterI, 57U));
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterF, 29U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 13U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterE, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25240U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneD[((aIndex + 24670U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 22590U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24009U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 26601U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 50U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = (aWandererD + RotL64(aScatter, 27U)) + 18087125778766689269U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 41U)) + 13710545066503235196U) + aPhaseFOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aCross, 23U)) + 1701939704736254645U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 18U)) + 8064093611384019909U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 53U)) + 16623332751533885431U) + aNonceWordN;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 35U)) + 15590129153794910109U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 7413312683079107383U) + aNonceWordA;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 4186064478651458810U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 10U)) + RotL64(aCarry, 5U)) + 5501191643940735954U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11064645242200570835U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13825922087298055833U;
            aOrbiterK = RotL64((aOrbiterK * 7529317892716108867U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5944980709887369970U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8181136916070569646U;
            aOrbiterD = RotL64((aOrbiterD * 395183021205661827U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15442336949157292482U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11580554435240641337U;
            aOrbiterE = RotL64((aOrbiterE * 6654637892858767739U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11240018128174598322U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 2027565596050777471U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 18048186560314431815U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16425887196883725233U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16828683527588834095U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 17746289103235902485U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9923829146479008804U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6669171007279929454U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 681823450939955099U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3902430046523165149U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6739998149289590041U;
            aOrbiterB = RotL64((aOrbiterB * 2675037435528416821U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 16014401255534234075U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14741857638680634564U;
            aOrbiterJ = RotL64((aOrbiterJ * 8723611021403369393U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5064807861673260054U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 968747317273200299U;
            aOrbiterI = RotL64((aOrbiterI * 14122304002722582329U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 54U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 60U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 51U)) + aOrbiterB) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterE) + aNonceWordC);
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 10U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 38U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32389U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((aIndex + 31655U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 30936U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29351U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28211U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 19U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 19U)) + 13442819395490639310U) + aNonceWordH;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 57U)) + 8187292523194120936U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 41U)) + 11469697159823131388U) + aNonceWordD;
            aOrbiterE = ((aWandererI + RotL64(aCross, 36U)) + RotL64(aCarry, 29U)) + 13414083692375929653U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 5U)) + 11404010733687907517U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 29U)) + 6783212827186218247U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 13U)) + 8561131439340372614U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aScatter, 48U)) + RotL64(aCarry, 3U)) + 6252609642004429113U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 12804867444200448952U) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2739648749603690781U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14808861217017399752U;
            aOrbiterK = RotL64((aOrbiterK * 373911885694012101U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 17588866502571268888U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 5882260142735642980U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7688252946143263869U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 15493099088132862949U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5175647411532429582U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 15226544495598541883U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14279707376173642767U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6826363572161275158U;
            aOrbiterB = RotL64((aOrbiterB * 5263708315440161809U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13267185753040999992U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 9980987858092888720U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 13210290848800728635U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3582972937645514549U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10140409019562890804U;
            aOrbiterJ = RotL64((aOrbiterJ * 6944490201647678479U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6160444117287330557U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16344602960561293113U;
            aOrbiterE = RotL64((aOrbiterE * 2319964919335633293U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3497141036108337171U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 91269118352540308U;
            aOrbiterG = RotL64((aOrbiterG * 5160060720189045505U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12739932748793144857U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12820180915064791197U;
            aOrbiterF = RotL64((aOrbiterF * 5843849637411948699U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 46U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 54U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 11U)) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 29U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterD, 23U)) + aNonceWordA) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 37U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterD, 46U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + aNonceWordI) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterF, 41U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 56U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_WaterPolo_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDA44E590A6406DBFULL + 0x9599D66978A8CCD5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDA99EF2C1DED00FFULL + 0xBE99E7265E9FE760ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8203F41FB3000203ULL + 0xFA628B3822E37FB9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8602A6853338A845ULL + 0xD2808F22BCC048ADULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9A164C56777C8533ULL + 0xBA5147C548AEF8D2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD0D3F743E842EE7FULL + 0xD87F62034732D61EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE1CFFFCCF04D845FULL + 0xA60624008D81519EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD69D9B29850564CBULL + 0xDE9707F086C255A9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC24090C87CD7F703ULL + 0xE40F67425C76C8E8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8D23F8ED7219E525ULL + 0xACD7D38970BC0D6CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF260E97F473FF0C3ULL + 0xB7663A66A69DD66AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB1A33147F7557D2FULL + 0x9C112F7101FB2719ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8174EE9582BD88D7ULL + 0xE6F3DE27C46683E7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8233E0ABBB375789ULL + 0x84CDF45BC8D40A69ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB2380152DC6E29C5ULL + 0x84F88126772C604DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD4E1E2B1D18A2ADFULL + 0x8EE45891C8F96DA7ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneC, aSnowLaneC, aSnowLaneD, aFireLaneD, aWorkLaneA, aInvestLaneD, aInvestLaneB, aWorkLaneB, aFireLaneB, aExpandLaneA, aFireLaneC, aExpandLaneB, aFireLaneA, aExpandLaneC, aInvestLaneA
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneC
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 716U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((aIndex + 2617U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 2040U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 3960U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 424U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 1124U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCross, 21U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = ((((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 3238389262925516513U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 12381787182611386995U) + aNonceWordH;
            aOrbiterG = (aWandererC + RotL64(aCross, 34U)) + 7883885539305181549U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 27U)) + 1185413044597727092U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 15219353497204773135U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 5U)) + 7533774715626734082U) + aNonceWordJ;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 43U)) + 2599930450937763464U) + aNonceWordP;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 16074720663961214284U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15483613196360051221U;
            aOrbiterG = RotL64((aOrbiterG * 11717479088020532861U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9396557867081376268U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9668459976852660245U;
            aOrbiterH = RotL64((aOrbiterH * 11748505665890567063U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9037269914643207212U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16936742640861088240U;
            aOrbiterJ = RotL64((aOrbiterJ * 1040172193161012227U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16481274825758546398U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 481851372837611166U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 2225030139210599207U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13608921517203544108U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16930740723286214636U;
            aOrbiterI = RotL64((aOrbiterI * 2605108503821980865U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 902242902582149908U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 1510861213079342977U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 3309753895727400707U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7116243600304980310U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 6631412278359709602U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 11452627691392637463U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 13U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterB, 19U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 11U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + aNonceWordB) + aPhaseHWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterB, 44U)) + aNonceWordM);
            aWandererH = aWandererH + (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + aNonceWordK);
            aWandererC = aWandererC + (((((RotL64(aScatter, 4U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aNonceWordF) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 28U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneD
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneB
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9161U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneC[((aIndex + 10541U)) & S_BLOCK1], 54U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 6238U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneD[((aIndex + 7583U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 7895U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 6521U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 7101U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 24U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = ((aWandererD + RotL64(aScatter, 46U)) + RotL64(aCarry, 43U)) + 7651355040951791298U;
            aOrbiterG = (aWandererB + RotL64(aCross, 27U)) + 13988210277931659312U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 11U)) + 9846849412579537783U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 12746719939495876158U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 11498066185182895284U) + aNonceWordI;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 57U)) + 11101058955193080232U) + aPhaseHOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 21U)) + 15513734459555672046U) + aNonceWordD;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15711108675349394643U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4771231759949468556U;
            aOrbiterE = RotL64((aOrbiterE * 9806191054594333615U), 21U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 11449258010811305256U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17036938391509986723U;
            aOrbiterI = RotL64((aOrbiterI * 7411466953205347639U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6999245666776654250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2106819066263369528U;
            aOrbiterG = RotL64((aOrbiterG * 13005885810757743129U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12716183358903477216U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16752724547046059889U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11475905692393034141U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17623077680983093163U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6726003022297274986U;
            aOrbiterC = RotL64((aOrbiterC * 14709385877103232653U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2842410225096524740U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9235178377537910514U;
            aOrbiterK = RotL64((aOrbiterK * 11813751114775673845U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2619888019860844610U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 6295481948199619613U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 15429161806953951205U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 54U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterI, 10U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 14U) + aOrbiterG) + RotL64(aOrbiterK, 27U));
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + aPhaseHWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + aNonceWordL);
            aWandererF = aWandererF + ((((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 3U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aFireLaneB
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 11614U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 10926U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14337U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12938U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11176U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 39U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = ((aWandererE + RotL64(aScatter, 5U)) + 4751694786009671052U) + aPhaseHOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aPrevious, 53U)) + 16362725160370844224U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 41U)) + 6360885380915941057U) + aNonceWordJ;
            aOrbiterK = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 5154536007972297036U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 29U)) + 9362540581874808253U) + aNonceWordD;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 13902493871525612934U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 19U)) + 10208452885367546542U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3117030377279160998U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17286247690414027870U;
            aOrbiterA = RotL64((aOrbiterA * 4896931759653832095U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3930314320040949141U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7289525252391668404U;
            aOrbiterD = RotL64((aOrbiterD * 15452162299105112187U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3434167955466809185U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17852573095128575663U;
            aOrbiterI = RotL64((aOrbiterI * 1485660158767033425U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6137259687928853253U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 13992510605237574698U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 15346263295995333395U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6470556523400123474U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4333255670390099293U;
            aOrbiterF = RotL64((aOrbiterF * 11089933812030082647U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7700424876430257995U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 16920736951239453071U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 8920407493132380497U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1635071690430295730U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9966700845966398620U;
            aOrbiterJ = RotL64((aOrbiterJ * 17210048121896546867U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ) + aNonceWordK) + aPhaseHWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterE, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 3U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + aNonceWordN);
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 58U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17076U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 17392U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 21720U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19585U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneD[((aIndex + 19075U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (aWandererK + RotL64(aIngress, 10U)) + 1898718075389870739U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 39U)) + 5631794889237247403U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 18219714659484524607U) + aNonceWordM;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 15419581386225732921U) + aPhaseHOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 9125575431710198210U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 47U)) + 12205871520544965505U) + aNonceWordN;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 27U)) + 7617534300497343422U) + aPhaseHOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 18017579105368135814U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 10693882161946020042U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2326507900303932855U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11669615701700895306U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11045110212889232165U;
            aOrbiterG = RotL64((aOrbiterG * 5965171269273719849U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 18019107802806469913U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12315940560472528716U;
            aOrbiterC = RotL64((aOrbiterC * 4505122470351404065U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4899009736070044310U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17412253404253730364U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10791901166391946485U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4826286251927854181U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4523455921321845084U;
            aOrbiterI = RotL64((aOrbiterI * 14534103906736598099U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4132514462154182215U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7164745605985109269U;
            aOrbiterK = RotL64((aOrbiterK * 14107325508977225261U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6297434295807635654U) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 8813887638672996646U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17495632530773158201U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterF, 54U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 11U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 5U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterB, 47U)) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 21U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 18U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25158U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 24149U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24198U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23943U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25890U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 47U)) + 18087125778766689269U) + aNonceWordK;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 13710545066503235196U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 5U)) + 1701939704736254645U) + aNonceWordD;
            aOrbiterH = ((aWandererD + RotL64(aCross, 11U)) + 8064093611384019909U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 18U)) + 16623332751533885431U) + aPhaseHOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 15590129153794910109U) + aNonceWordH;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 7413312683079107383U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4186064478651458810U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5501191643940735954U;
            aOrbiterC = RotL64((aOrbiterC * 14254804649177125269U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11064645242200570835U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13825922087298055833U;
            aOrbiterB = RotL64((aOrbiterB * 7529317892716108867U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5944980709887369970U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 8181136916070569646U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 395183021205661827U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15442336949157292482U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 11580554435240641337U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 6654637892858767739U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11240018128174598322U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2027565596050777471U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18048186560314431815U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16425887196883725233U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16828683527588834095U;
            aOrbiterH = RotL64((aOrbiterH * 17746289103235902485U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9923829146479008804U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6669171007279929454U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 681823450939955099U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aNonceWordC);
            aWandererE = aWandererE + ((((RotL64(aCross, 42U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + aNonceWordL) + aPhaseHWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterD, 58U)) + aNonceWordF);
            aWandererH = aWandererH + ((((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterK, 51U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 3U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30089U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 29648U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 27872U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31789U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((aIndex + 30548U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 44U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 4848316479321533394U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 6919360256662636195U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 57U)) + 9897013582181108544U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 6U)) + 7319353809896158678U) + aNonceWordF;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 23U)) + 2848175435514849859U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 51U)) + 6967780718720437934U) + aPhaseHOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 10143884766603388136U) + aNonceWordD;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8675965006150972051U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16350117755560994281U;
            aOrbiterD = RotL64((aOrbiterD * 15072308930382994425U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17976597517118423760U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1399631141355370237U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 16537788276543236833U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3590613762034716792U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 5134624314245932157U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 13077589037975283371U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 10082236952942943654U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4015535035905433450U;
            aOrbiterC = RotL64((aOrbiterC * 4961808568701908559U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 611474103801573800U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5786708483794098001U;
            aOrbiterH = RotL64((aOrbiterH * 7694007039340089267U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5201943497363274455U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9282160506938328489U;
            aOrbiterK = RotL64((aOrbiterK * 5368182164239021367U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4932320527498940158U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11576526341731392916U;
            aOrbiterG = RotL64((aOrbiterG * 1712051774729439363U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 4U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + aNonceWordB);
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterD, 29U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 5U)) + aOrbiterA) + aNonceWordC) + aPhaseHWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterK, 58U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 37U)) + aOrbiterG) + aNonceWordK);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 21U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_WaterPolo_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2515U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 2524U)) & W_KEY1], 46U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2008U)) & W_KEY1], 6U) ^ RotL64(mSource[((aIndex + 2359U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCross, 37U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 13296600294247799698U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 58U)) + 5818503518080877515U) + aPhaseAOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aIngress, 3U)) + 6735784238734173597U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 7368398209488856201U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 37U)) + 961734029066455638U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 797011946660892011U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 51U)) + 12841876018396622350U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 24U)) + 16213253970483895623U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 41U)) + 15186950557113470375U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5117930310827477341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12265429373166094162U;
            aOrbiterE = RotL64((aOrbiterE * 1522823535151532249U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13920531346698601568U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14695405206998211456U;
            aOrbiterH = RotL64((aOrbiterH * 13950964363414164279U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 7851960904825938443U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9501511171732550190U;
            aOrbiterB = RotL64((aOrbiterB * 5614164120361489613U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5663365182245722077U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9607860124321315555U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3461820361914280601U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 18171052650586819280U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3442698321538580861U;
            aOrbiterI = RotL64((aOrbiterI * 6317525514963824829U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1491052813469258970U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3956599824067616133U;
            aOrbiterD = RotL64((aOrbiterD * 2928600779267623085U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10963841237346073453U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2303020125591252534U;
            aOrbiterJ = RotL64((aOrbiterJ * 9969099842343321981U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14503856057958162356U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11147548150090597694U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11856382308792700441U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9191681438318311481U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13556072770381999852U;
            aOrbiterK = RotL64((aOrbiterK * 18316231099054203683U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 23U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 10U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterE, 5U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterH, 57U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterD, 14U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 27U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterI, 53U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 36U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5381U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 4607U)) & W_KEY1], 20U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3177U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4978U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererB + RotL64(aIngress, 39U)) + 6318740973868639425U;
            aOrbiterB = (aWandererA + RotL64(aCross, 47U)) + 5487840061430920881U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 22U)) + RotL64(aCarry, 43U)) + 10258706763248072672U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 18356875269730338208U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 12883160282903147010U) + aPhaseAOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 5U)) + 1010140474942697730U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 57U)) + 17733939421700898293U;
            aOrbiterH = (aWandererK + RotL64(aCross, 14U)) + 13693055887924981201U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 27U)) + 14574732452793385269U) + aPhaseAOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10832873941223609012U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8212600587135328040U;
            aOrbiterG = RotL64((aOrbiterG * 5334613996794796145U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5312744319781971178U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6173741211706546923U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12854414066390848249U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3693249147883790810U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 18365859989736602556U;
            aOrbiterC = RotL64((aOrbiterC * 3348463719324104997U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10645056678337549771U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1175668356822251045U;
            aOrbiterI = RotL64((aOrbiterI * 6579675292775345579U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13556844570541823717U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4790355739411849736U;
            aOrbiterB = RotL64((aOrbiterB * 4083544011788850307U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14905575502272644116U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17047244574558476634U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2356386971503880047U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10161614295718414869U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13413914082651612468U;
            aOrbiterD = RotL64((aOrbiterD * 16224039093981079491U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6072693130156927774U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4333656233793103787U;
            aOrbiterH = RotL64((aOrbiterH * 9374745547133955709U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17209776289202130250U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11752001118070361543U;
            aOrbiterJ = RotL64((aOrbiterJ * 4416523594812872339U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 40U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 22U) + aOrbiterE) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterC, 3U));
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterC, 47U)) + aPhaseAWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 34U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 39U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 23U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aScatter, 34U) + RotL64(aOrbiterH, 51U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererD = aWandererD + ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterI, 58U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6749U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6383U)) & W_KEY1], 4U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7311U)) & W_KEY1], 22U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5788U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5736U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 30U)) + RotL64(aCarry, 51U)) + 9855743441035905047U;
            aOrbiterB = (aWandererI + RotL64(aCross, 19U)) + 8426286937143990276U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 23U)) + 7146752367170267002U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 3U)) + 12947210066678101726U) + aPhaseAOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aScatter, 53U)) + 15902163559925328965U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 47U)) + 8506649889346449469U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 8226286036430263052U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 36U)) + RotL64(aCarry, 27U)) + 2703047093452420216U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 41U)) + 6769351326360139560U) + aPhaseAOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9857025533281333281U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 238297452132277585U;
            aOrbiterG = RotL64((aOrbiterG * 12974709749856065985U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7203572312072908931U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12497027346166575632U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1703586436725662307U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 473851890609048879U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1664484956453886047U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8566500756326590209U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4635095143004754116U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17695676150967345793U;
            aOrbiterH = RotL64((aOrbiterH * 5780416541584439301U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15628965269863402796U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9190117464399730235U;
            aOrbiterA = RotL64((aOrbiterA * 5586437438425999715U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17835918238346011086U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4398005402429282682U;
            aOrbiterB = RotL64((aOrbiterB * 14828737209913317463U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10902589938246551273U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15124274429081385923U;
            aOrbiterC = RotL64((aOrbiterC * 13524180348258805367U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8747233520702236018U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5445611443463112371U;
            aOrbiterD = RotL64((aOrbiterD * 10294109295823410447U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16296005217836151910U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 6468336224317602364U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7369779919748367133U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 14U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterH, 47U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterB, 28U));
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterK) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 18U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterB, 56U));
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9849U)) & S_BLOCK1], 26U) ^ RotL64(aKeyRowReadB[((aIndex + 9206U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(mSource[((aIndex + 9729U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10229U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10466U)) & W_KEY1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 10746U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 57U)) + 5041131702736607991U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 11U)) + 9295010428212681446U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 52U)) + RotL64(aCarry, 5U)) + 6235875895358766017U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 21U)) + 2622227802531866918U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 3888894734834524972U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 241682012014701753U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 37U)) + 15758000422451568079U) + aPhaseBOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 41U)) + 2061944548396976912U;
            aOrbiterK = (aWandererI + RotL64(aCross, 26U)) + 8177144990755754531U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 554978075608818497U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 250408260560714933U;
            aOrbiterJ = RotL64((aOrbiterJ * 1295379390497107727U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 8700027645880997552U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10026130047465480902U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12417270861933696623U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9785843014096326696U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9998582683258411251U;
            aOrbiterH = RotL64((aOrbiterH * 7197956237569462269U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13817734599383455151U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6647207154174092691U;
            aOrbiterK = RotL64((aOrbiterK * 1578528131687283531U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4957715980509035719U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4994885315786213197U;
            aOrbiterF = RotL64((aOrbiterF * 5676683798126497011U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5072908311783966503U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5535039946192891515U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2989412783482309753U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6594577050344146271U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8750154123258714856U;
            aOrbiterC = RotL64((aOrbiterC * 6942158167127532003U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3514769314840874873U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8626045200273524281U;
            aOrbiterD = RotL64((aOrbiterD * 4315441782689789689U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8524870284841706517U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1841819423572964209U;
            aOrbiterI = RotL64((aOrbiterI * 9802481758007234681U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 10U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterD, 42U));
            aWandererE = aWandererE + (((RotL64(aScatter, 4U) + aOrbiterA) + RotL64(aOrbiterH, 19U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 57U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterG, 5U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 23U)) + aPhaseBWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 51U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 46U) + RotL64(aOrbiterK, 28U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 10944U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 12746U)) & W_KEY1], 28U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11331U)) & W_KEY1], 39U) ^ RotL64(mSource[((aIndex + 11074U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 11227U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12440U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12509U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 13278949403988203974U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 9213599924054673756U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 48U)) + 1255746482932381798U;
            aOrbiterF = (aWandererA + RotL64(aCross, 27U)) + 11575321997144516122U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 21U)) + 15881587525529432437U) + aPhaseBOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 41U)) + 9846195809864862707U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 13U)) + 12319815691858217670U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 58U)) + 16322617427294439587U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 16332130810525887437U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 4920951156015336794U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16767126455124552329U;
            aOrbiterD = RotL64((aOrbiterD * 4440352337076842603U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12553595911087945223U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1437522202135436142U;
            aOrbiterH = RotL64((aOrbiterH * 2001992794165550905U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12313100454852227143U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2761983020631055729U;
            aOrbiterG = RotL64((aOrbiterG * 3874839760378039509U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17635303588421554367U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 788212489507463763U;
            aOrbiterF = RotL64((aOrbiterF * 17896475584538528059U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5192552894670654434U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6784748488807738811U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8077237651953896479U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 16113417046719114943U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1096874945215225916U;
            aOrbiterK = RotL64((aOrbiterK * 17308604412622879833U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7610274704570171595U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 10466070212284342550U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6449728258497920613U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6777845928873855221U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5251515022021984126U;
            aOrbiterB = RotL64((aOrbiterB * 9018277343404261611U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13849343158824111498U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7977711210181714021U;
            aOrbiterI = RotL64((aOrbiterI * 4182053966171053577U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 54U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterB, 56U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 10U) + aOrbiterG) + RotL64(aOrbiterH, 27U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterI, 52U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterD, 47U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 30U) + aOrbiterD) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + aPhaseBWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterI, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15310U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14581U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15173U)) & W_KEY1], 20U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15670U)) & W_KEY1], 47U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14256U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15654U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14010U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aIngress, 35U)) + (RotL64(aCarry, 47U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 10881271196314989997U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 58U)) + 6406461249988567558U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 3U)) + 17255067918280095959U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 37U)) + 16690850682497718411U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 47U)) + 5576201059361086866U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 13U)) + 11991259685693687554U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 14652535244217836909U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 30U)) + RotL64(aCarry, 57U)) + 1701789037170782122U) + aPhaseBOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aScatter, 19U)) + 953429054903473833U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12064513610469714211U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 7993881398822002424U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11572884842788918377U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14421313768013320050U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11112386845630998889U;
            aOrbiterD = RotL64((aOrbiterD * 11771526352030371669U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17069630896535699015U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3308240081138623373U;
            aOrbiterI = RotL64((aOrbiterI * 10449509484417835159U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17615529807112933619U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11782807146851563541U;
            aOrbiterE = RotL64((aOrbiterE * 12992075832343669221U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14401645829607611983U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6736397344219993532U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1667287547938175641U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6446974060524700550U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7840991992443308254U;
            aOrbiterG = RotL64((aOrbiterG * 6891023544882740107U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10362169906019794305U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4503700997923168911U;
            aOrbiterJ = RotL64((aOrbiterJ * 15066164494038852559U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13492041134973259041U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14337899277551397976U;
            aOrbiterH = RotL64((aOrbiterH * 5966740718899290915U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13693100781608180748U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16177545026405910052U;
            aOrbiterA = RotL64((aOrbiterA * 6019231448444020563U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 54U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterI, 50U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 21U));
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 60U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterG, 39U));
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 6U) + aOrbiterI) + RotL64(aOrbiterC, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererA, 14U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16653U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 18971U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(mSource[((aIndex + 18225U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 18862U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17878U)) & W_KEY1], 52U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17897U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17724U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 11U)) + (RotL64(aIngress, 58U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererI + RotL64(aIngress, 21U)) + 3339283916456813609U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 12U)) + 11339086426180649584U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 16819191669329316585U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 8361916937762630725U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 47U)) + 18031328374429899857U;
            aOrbiterA = (aWandererA + RotL64(aCross, 35U)) + 18261756894092897276U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 51U)) + 4250319792907645666U) + aPhaseCOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 39U)) + 1492411503643460886U) + aPhaseCOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 56U)) + RotL64(aCarry, 5U)) + 17369549067879344180U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7301713524358676722U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2985193736033012535U;
            aOrbiterK = RotL64((aOrbiterK * 7473297294949338265U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14086975808140927408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10390516547834639800U;
            aOrbiterA = RotL64((aOrbiterA * 11441293212275890819U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 18205555540941493267U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16967799565443938873U;
            aOrbiterG = RotL64((aOrbiterG * 3009081009044782443U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9209505304067579944U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3522631966146762306U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3441982898533162599U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8811497120829041188U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14707301680850257294U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11383709499376464085U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10080595991787801029U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6822892187784299166U;
            aOrbiterI = RotL64((aOrbiterI * 7417016898027778287U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1981637172055758689U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16463077485583119324U;
            aOrbiterE = RotL64((aOrbiterE * 2876782050665869121U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8383837717361569465U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2788511294985017326U;
            aOrbiterJ = RotL64((aOrbiterJ * 2809163242875130677U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3529607472855930041U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8850940802020173766U;
            aOrbiterB = RotL64((aOrbiterB * 7821450253655655943U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 52U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterD, 11U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 22U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 30U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aIngress, 10U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 51U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterD, 41U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterD, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20647U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((aIndex + 20890U)) & S_BLOCK1], 30U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19122U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 20746U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20045U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20498U)) & W_KEY1], 23U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20703U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19786U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 27U)) + (RotL64(aCross, 52U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aIngress, 13U)) + 18191288703716505885U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 39U)) + 9824014524910417136U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 11953012029254917548U) + aPhaseCOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 4U)) + 6297568011027199089U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 21U)) + 2576999400457367975U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 13176139160575558254U;
            aOrbiterK = (aWandererF + RotL64(aCross, 53U)) + 9978408174563621810U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 16765834875061607142U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 60U)) + 16534507305459121344U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3114710944346151807U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10240517868726718592U;
            aOrbiterH = RotL64((aOrbiterH * 4645691562915606463U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10721450637990777883U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16689590768796583952U;
            aOrbiterC = RotL64((aOrbiterC * 3046344179729901637U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2427422768928450209U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13495584061816457831U;
            aOrbiterI = RotL64((aOrbiterI * 6670984773768885119U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7058636403765106682U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9897341853944713767U;
            aOrbiterG = RotL64((aOrbiterG * 14286816859999869231U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17749559755733386064U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12515645083926326659U;
            aOrbiterB = RotL64((aOrbiterB * 6582878478865838245U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2625692458813609962U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10596240255026143019U;
            aOrbiterD = RotL64((aOrbiterD * 11605800195771080135U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 12374290338067865540U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1507386663796330249U;
            aOrbiterA = RotL64((aOrbiterA * 1210241080424446087U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9288099549484146726U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 15159312464747000702U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 500055502081347757U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14998608679505446229U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17625038109437732009U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14785862243019841689U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 6U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 43U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterD, 60U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterA, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 29U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterK, 47U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterB, 56U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 18U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22870U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadA[((aIndex + 22082U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22469U)) & W_KEY1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23013U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 21970U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23942U)) & S_BLOCK1], 41U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22577U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneB[((aIndex + 23440U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aPrevious, 3U)) + (RotL64(aCross, 22U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 35U)) + 16124889768301047791U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aCross, 28U)) + RotL64(aCarry, 27U)) + 11912338587186717280U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 19U)) + 8594012868813114354U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 18281043566156682815U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 16853106130200942302U;
            aOrbiterB = (aWandererK + RotL64(aCross, 39U)) + 2611212958619673086U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 4U)) + 18039472325066855180U) + aPhaseCOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 13U)) + 14495785571345122046U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 23U)) + 4556063793412832418U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14896419970271244358U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 880028529183500036U;
            aOrbiterJ = RotL64((aOrbiterJ * 14228281807461251361U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2379557167489415783U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11854373946064529806U;
            aOrbiterG = RotL64((aOrbiterG * 150755294320438887U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1487252775956449964U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12777924204511625545U;
            aOrbiterC = RotL64((aOrbiterC * 1366019527386994789U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15998631485222477969U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8864212892296191613U;
            aOrbiterD = RotL64((aOrbiterD * 579242788050369815U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17069347835763226743U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7443008171694679791U;
            aOrbiterB = RotL64((aOrbiterB * 748894368884566607U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17334256152350782002U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8986626119086556393U;
            aOrbiterK = RotL64((aOrbiterK * 2258172145924120235U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8528180968228358674U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 12702290928064582589U;
            aOrbiterH = RotL64((aOrbiterH * 15673603224146737631U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7742438100860023610U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3729687240959702198U;
            aOrbiterI = RotL64((aOrbiterI * 3756794766163746783U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 426129097367382096U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16782175452274911213U;
            aOrbiterE = RotL64((aOrbiterE * 1041477289638333659U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 54U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterI, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterK, 14U));
            aWandererI = aWandererI + ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 19U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterD, 23U));
            aWandererH = aWandererH + (((RotL64(aIngress, 10U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 39U));
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterC, 51U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterG, 10U)) + aPhaseCWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 22U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26445U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 25477U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26634U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24963U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25163U)) & W_KEY1], 52U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26238U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25680U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26762U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 54U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aIngress, 18U)) + 11480359716598965890U) + aPhaseDOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 47U)) + 15431182525482873419U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 11360504974812776707U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 43U)) + 9292576416573382769U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 39U)) + 1549257414531028975U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 5347769463033129317U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 23U)) + 17019199177478377234U) + aPhaseDOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 12U)) + RotL64(aCarry, 3U)) + 16558106007323125094U;
            aOrbiterC = (aWandererE + RotL64(aCross, 53U)) + 3976182233825939422U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2889047161195954395U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 2241831345026962605U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5757458560979927857U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12850802412140579294U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13541744735436450160U;
            aOrbiterF = RotL64((aOrbiterF * 906089290000537439U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2085863085516538212U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2969034221711544086U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7768528124408400403U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6482666944512391472U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16969153556875844613U;
            aOrbiterI = RotL64((aOrbiterI * 9483462388353216219U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5161314086757363678U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 7150282484670673211U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8522427002337918663U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5465304381272305847U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2344610773390354017U;
            aOrbiterH = RotL64((aOrbiterH * 17010258514288089191U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8335906578006588582U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 13668796013474193793U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8228000547141147777U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9663362594301419686U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3683773739120343413U;
            aOrbiterA = RotL64((aOrbiterA * 8319320803406104749U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2538583190438044942U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4454069062219406996U;
            aOrbiterK = RotL64((aOrbiterK * 16329554225309389599U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 52U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + aPhaseDWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 21U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterA, 43U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 60U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 39U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterH, 35U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 24U) + aOrbiterA) + RotL64(aOrbiterK, 5U));
            aWandererI = aWandererI + ((((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterK, 12U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27987U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((aIndex + 29364U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28899U)) & W_KEY1], 60U) ^ RotL64(aFireLaneC[((aIndex + 29719U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29349U)) & W_KEY1], 20U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29688U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27853U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28930U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 40U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererJ + RotL64(aCross, 42U)) + RotL64(aCarry, 21U)) + 7825479804710770560U) + aPhaseDOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 57U)) + 5298124167101358123U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 23U)) + 17774541024369233726U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aPrevious, 47U)) + 7679371833537454082U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 19U)) + 5385914900748772224U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 30U)) + RotL64(aCarry, 13U)) + 3879781930908486531U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 659110346638873236U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 3U)) + 10749021728538539749U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 37U)) + 3631252455767429457U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2271978810960685021U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5963558780692551176U;
            aOrbiterK = RotL64((aOrbiterK * 4772055335210781149U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 974909966119198104U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9296998242911152296U;
            aOrbiterJ = RotL64((aOrbiterJ * 2613629915877957661U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 2245318466901521959U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13391076374843288568U;
            aOrbiterG = RotL64((aOrbiterG * 18094558036982107419U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6184487746594236737U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1563385912137291418U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4805455299959232321U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1744840092006498629U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2100927276837188416U;
            aOrbiterI = RotL64((aOrbiterI * 3541788262067077997U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 9998911862807246338U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12239948725635220096U;
            aOrbiterB = RotL64((aOrbiterB * 7098620484129489129U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3307447094994950246U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12746613971448298932U;
            aOrbiterF = RotL64((aOrbiterF * 9463975886346934681U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11577488293733790649U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 191108997585598809U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9574978681405356871U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18096145693841273722U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10026281133603934071U;
            aOrbiterH = RotL64((aOrbiterH * 17261343107314203471U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 56U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 30U) + aOrbiterI) + RotL64(aOrbiterB, 57U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 20U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterF, 39U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 34U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            aWandererG = aWandererG + ((((RotL64(aCross, 56U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30448U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadA[((aIndex + 30050U)) & W_KEY1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30662U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32704U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30207U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 32590U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 58U)) + (RotL64(aIngress, 41U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 23U)) + 9107326720193244489U;
            aOrbiterK = (aWandererI + RotL64(aCross, 56U)) + 10868585484401664145U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 13637736741437846622U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 19U)) + 6130725216183918844U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 39U)) + 2063834478521338187U) + aPhaseDOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 8564870627911949158U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 10U)) + RotL64(aCarry, 53U)) + 6524015751064086390U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 3U)) + 9874937766875388236U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 43U)) + 14723718409522680894U) + aPhaseDOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13767059954741528279U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6387608251033722169U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6601902195707980693U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5391425980008431000U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11524218415655093779U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12508457981779189389U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 155510463350385905U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10554591788433641311U;
            aOrbiterH = RotL64((aOrbiterH * 5412084824127934293U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8662160162966241542U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5092555636369853727U;
            aOrbiterI = RotL64((aOrbiterI * 433807340167635499U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7163345798448796101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 695089002178413267U;
            aOrbiterG = RotL64((aOrbiterG * 17302689458565434475U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5409173939213468972U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15349690077393827541U;
            aOrbiterD = RotL64((aOrbiterD * 10984681254001609841U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12376011890751302027U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7809614158898158383U;
            aOrbiterK = RotL64((aOrbiterK * 13845113198736843629U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13031938699536449576U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3983178190194056516U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1341678482929213405U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5567935037909671790U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17137042627663349797U;
            aOrbiterA = RotL64((aOrbiterA * 13535586899620672373U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterH, 29U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterK, 19U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterA, 34U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 38U) + aOrbiterG) + RotL64(aOrbiterH, 3U));
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 23U));
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 48U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterD, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_WaterPolo_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneD, aInvestLaneD, aFireLaneB, aOperationLaneA, aFireLaneA, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 761U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneB[((aIndex + 172U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 736U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1944U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4690U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererA + RotL64(aScatter, 43U)) + 10805654776556844351U;
            aOrbiterB = (aWandererF + RotL64(aCross, 35U)) + 582794182442795335U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 2858343650974681068U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 8189584049022064284U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 57U)) + 1565100751996962893U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 6U)) + RotL64(aCarry, 29U)) + 8062028016947611891U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 51U)) + 8280504280578451745U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11326869194491655350U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1671695656567777163U;
            aOrbiterC = RotL64((aOrbiterC * 7511554500524257921U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2349843105293943452U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13015545152052004254U;
            aOrbiterD = RotL64((aOrbiterD * 1316662811685429983U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16703354404749291869U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8713231044374305801U;
            aOrbiterB = RotL64((aOrbiterB * 9242480982197688625U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11118401674497783533U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14857556493734710364U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3452566050389715195U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12953419670951660965U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12666121730825089017U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14049925256934142519U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11075249639473053423U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9374217688244187867U;
            aOrbiterI = RotL64((aOrbiterI * 5261156325627117877U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17608340953291367867U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13159437499327086340U;
            aOrbiterF = RotL64((aOrbiterF * 4882100944453534805U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 56U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 35U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneD
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9429U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 7662U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6623U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10787U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10205U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 48U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererJ + RotL64(aScatter, 23U)) + 16651241552253078315U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 4558144676982478003U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 5U)) + 8814884320080367550U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 16011579668555672117U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 35U)) + 4738918668759862438U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 12U)) + 12526083125540985108U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 8048723561746000552U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1082218464034639039U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8432043246965946816U;
            aOrbiterI = RotL64((aOrbiterI * 7801965585991025451U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9982080524048636852U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6720069955755215919U;
            aOrbiterH = RotL64((aOrbiterH * 1025046364205332059U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 1019035028070247757U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7360619079463870467U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6623074813047915863U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10893918488381348474U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1390297670907738019U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11909657437658597735U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12512200589031203480U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14741471280748399540U;
            aOrbiterB = RotL64((aOrbiterB * 3012135242889901095U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8543897248359826770U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8545972622733791272U;
            aOrbiterF = RotL64((aOrbiterF * 11793879362775346821U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7049384618581928664U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14730773807906925408U;
            aOrbiterE = RotL64((aOrbiterE * 10711566871536755073U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 28U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterH, 12U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 41U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterK, 19U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 11258U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 14658U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14302U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11854U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11279U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 13558U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 43U)) + (RotL64(aCross, 29U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 5U)) + 9914837590440975587U) + aPhaseEOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 29U)) + 6706125076401958051U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 37U)) + 16570817772679258409U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 13U)) + 6843705658115186948U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 16099930446791572351U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 5420550009556030459U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 3U)) + 5729549069420177477U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15590601126188675834U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13044027390998620029U;
            aOrbiterB = RotL64((aOrbiterB * 16845199115313444123U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11068338135659636772U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 6584988841809544332U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1683336180438945439U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8516813219883915404U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10647314042912492785U;
            aOrbiterJ = RotL64((aOrbiterJ * 15559481057047148785U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 201691689889605304U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15512161798401184003U;
            aOrbiterI = RotL64((aOrbiterI * 11473219183982564709U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 3883760518944464145U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13861805129175491145U;
            aOrbiterF = RotL64((aOrbiterF * 17194438894492581181U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12019138626550801486U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13030350224959652248U;
            aOrbiterH = RotL64((aOrbiterH * 11724200983306280107U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2643807255422544248U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4127143302485631794U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5441038881111578487U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 41U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 53U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterB, 27U));
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterK, 12U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19509U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneC[((aIndex + 16857U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18194U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21248U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19837U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 19114U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 37U)) + (RotL64(aCarry, 4U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererD + RotL64(aIngress, 21U)) + 5960680319644404115U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 27U)) + 16050752633567034185U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 8447503223226854741U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 57U)) + 14176813813397917591U;
            aOrbiterG = (aWandererA + RotL64(aCross, 3U)) + 10534915376130006644U;
            aOrbiterK = (((aWandererI + RotL64(aScatter, 14U)) + RotL64(aCarry, 5U)) + 6866224454375302514U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 16506374165041008396U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7167814023968794098U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13870852197416596664U;
            aOrbiterA = RotL64((aOrbiterA * 17015971222069856463U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 18064038854848993105U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9869630811507771691U;
            aOrbiterK = RotL64((aOrbiterK * 13723164383800461387U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 863613100452759380U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16597969741225436529U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2680793528887208903U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6575347108051310653U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17062262265485019063U;
            aOrbiterE = RotL64((aOrbiterE * 7601045488473620019U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7193399224636409133U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14146747818810433849U;
            aOrbiterG = RotL64((aOrbiterG * 5273185769989530041U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9441449106442431427U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4303295336545399503U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8829695296836242587U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12604760768543193458U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15779327512379787715U;
            aOrbiterI = RotL64((aOrbiterI * 14000905201441272597U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterF, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterK, 57U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterD, 6U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterA) + aPhaseEWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22671U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 25739U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22972U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26423U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25637U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 24250U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 35U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 48U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererG + RotL64(aScatter, 29U)) + 5573188770530340913U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 4U)) + 1431772230889897111U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 4809192776429682319U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 13U)) + 5576603692574369341U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 2720143226007220386U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 39U)) + 17220328778565331629U) + aPhaseEOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 9629485808442089423U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1136998437010390983U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11893390497814523841U;
            aOrbiterK = RotL64((aOrbiterK * 5329621622743089531U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1764986431917532370U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1741014798007010376U;
            aOrbiterJ = RotL64((aOrbiterJ * 13414914086049500731U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12221368453236547044U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7694538641172350430U;
            aOrbiterG = RotL64((aOrbiterG * 8439120733670016501U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17472344518811560603U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3308740700728172984U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15290400462887712083U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9535358833412446771U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11192312491731312451U;
            aOrbiterE = RotL64((aOrbiterE * 17405609148475445743U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14850451970047190039U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11932493299452443256U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7964808728820467795U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5972619895614731870U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17174497535809891690U;
            aOrbiterI = RotL64((aOrbiterI * 15471084511364572533U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterG, 23U));
            aWandererB = aWandererB + ((RotL64(aScatter, 34U) + aOrbiterI) + RotL64(aOrbiterG, 44U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 51U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterF, 11U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterF, 35U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28645U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 32732U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28656U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31218U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27923U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 28062U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 58U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererB + RotL64(aScatter, 21U)) + 1708250618750199233U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 38U)) + RotL64(aCarry, 3U)) + 12009147777553691142U) + aPhaseEOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 8393982703399156592U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 27U)) + 3247327098356831221U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 3403590155376353737U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 57U)) + 18197244558104735044U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 13U)) + 3096253642040701606U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 8012692688785412179U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17531946907545680745U;
            aOrbiterK = RotL64((aOrbiterK * 16510602981731506381U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17687695944270225817U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16147773866007628769U;
            aOrbiterE = RotL64((aOrbiterE * 16926442582711557877U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18244641303026196497U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8839160526348897457U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14268021129087663397U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10599266240854068246U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2056723540756216155U;
            aOrbiterH = RotL64((aOrbiterH * 13311591601230386375U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4629354220460621284U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9505955649473204942U;
            aOrbiterC = RotL64((aOrbiterC * 17775391885312236187U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17078153810088721310U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9470436761716263000U;
            aOrbiterI = RotL64((aOrbiterI * 5431855497250357229U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3305863413630104742U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 14377172434239576161U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6880176890091033423U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 28U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 3U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 47U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterE, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 36U) + RotL64(aOrbiterJ, 21U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 35U));
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterI, 28U)) + aPhaseEWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 22U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_WaterPolo_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneB, aSnowLaneA, aInvestLaneA, aInvestLaneD, aSnowLaneB, aExpandLaneD, aWorkLaneA, aExpandLaneA, aWorkLaneB, aExpandLaneB, aWorkLaneC, aInvestLaneC
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 465U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((aIndex + 2038U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 102U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4656U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4107U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 4063U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 30U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 34U)) + RotL64(aCarry, 27U)) + 16424657151168221875U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 17150123681886380361U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 43U)) + 16041993588694572757U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 13U)) + 9871185846434828537U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 11227236398354430757U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 29U)) + 5399325217402192631U;
            aOrbiterC = (aWandererA + RotL64(aCross, 11U)) + 9248828789282890454U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 4U)) + 9041370494203701062U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 21U)) + 14944424084524970764U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 19U)) + 5481938174456671041U) + aPhaseFOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 53U)) + 14783648629543752715U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12355573914530445723U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9863991559011968318U;
            aOrbiterF = RotL64((aOrbiterF * 8495251211794343179U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16149688605937250965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 106041828692026825U;
            aOrbiterB = RotL64((aOrbiterB * 12199934305374582599U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8076098639554567792U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11155119311895580013U;
            aOrbiterC = RotL64((aOrbiterC * 1495180896564818647U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6847612160595917702U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16094377920388017367U;
            aOrbiterH = RotL64((aOrbiterH * 4875801863643206333U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13584719866672696684U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13446209321646234607U;
            aOrbiterA = RotL64((aOrbiterA * 9945349065094781529U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15829806645369560988U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12573767256739062550U;
            aOrbiterE = RotL64((aOrbiterE * 5649504278826069077U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3850030870300393809U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11857593987748189858U;
            aOrbiterD = RotL64((aOrbiterD * 15942863910931814193U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 5505918410521728373U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12949653497121247860U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 90944913639560027U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2448323375614082955U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4386059032042654583U;
            aOrbiterK = RotL64((aOrbiterK * 11730132905525317201U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 108129028178045299U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 18292666533864994149U;
            aOrbiterJ = RotL64((aOrbiterJ * 2599590507178673531U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 10771402979550786312U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16424657151168221875U;
            aOrbiterI = RotL64((aOrbiterI * 6255743082177474607U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterF, 51U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 43U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterF, 6U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 47U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 41U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterF, 34U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterB, 57U)) + aPhaseFWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 14U) + RotL64(aOrbiterI, 27U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterG, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 44U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneA
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6475U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 7481U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6007U)) & S_BLOCK1], 50U) ^ RotL64(aInvestLaneA[((aIndex + 6942U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7144U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7730U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 9552U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 12U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererH + RotL64(aCross, 27U)) + 11480359716598965890U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 15431182525482873419U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 11360504974812776707U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 60U)) + 9292576416573382769U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 13U)) + 1549257414531028975U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 5347769463033129317U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 23U)) + 17019199177478377234U;
            aOrbiterK = (aWandererG + RotL64(aCross, 53U)) + 16558106007323125094U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 19U)) + 3976182233825939422U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 47U)) + 2889047161195954395U) + aPhaseFOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 4U)) + 2241831345026962605U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12850802412140579294U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13541744735436450160U;
            aOrbiterE = RotL64((aOrbiterE * 906089290000537439U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2085863085516538212U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2969034221711544086U;
            aOrbiterF = RotL64((aOrbiterF * 7768528124408400403U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6482666944512391472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16969153556875844613U;
            aOrbiterD = RotL64((aOrbiterD * 9483462388353216219U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5161314086757363678U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7150282484670673211U;
            aOrbiterK = RotL64((aOrbiterK * 8522427002337918663U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5465304381272305847U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2344610773390354017U;
            aOrbiterC = RotL64((aOrbiterC * 17010258514288089191U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8335906578006588582U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13668796013474193793U;
            aOrbiterH = RotL64((aOrbiterH * 8228000547141147777U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9663362594301419686U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3683773739120343413U;
            aOrbiterB = RotL64((aOrbiterB * 8319320803406104749U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2538583190438044942U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4454069062219406996U;
            aOrbiterA = RotL64((aOrbiterA * 16329554225309389599U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17177136683616247897U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3680497519697457252U;
            aOrbiterI = RotL64((aOrbiterI * 6479357366957384599U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16812938441063719463U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 4545693142067578891U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17479957806084346527U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 9232311730019478327U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11480359716598965890U;
            aOrbiterG = RotL64((aOrbiterG * 6678546065399772697U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 40U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 50U) + aOrbiterI) + RotL64(aOrbiterH, 37U));
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + aPhaseFWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterB, 14U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterG, 43U));
            aWandererC = aWandererC + ((RotL64(aIngress, 36U) + aOrbiterK) + RotL64(aOrbiterH, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterB, 35U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneD
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12833U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((aIndex + 14846U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 12982U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14065U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 12737U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 29U) + RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 10726035965553989335U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 23U)) + 967354339530195662U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 52U)) + 10834593005478605624U) + aPhaseFOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 1012888282838656933U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 3U)) + 15283530351725183253U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 21U)) + 11724495956731703750U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 10U)) + 4288330117317505776U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 10894778070022873473U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 37U)) + 15563886747621617467U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 47U)) + 11182488628562891937U;
            aOrbiterA = (aWandererA + RotL64(aCross, 39U)) + 10420140066310588580U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11775138062167543111U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16545391898578161683U;
            aOrbiterB = RotL64((aOrbiterB * 14588306527161321535U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1550144656312299266U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14903504853138279883U;
            aOrbiterF = RotL64((aOrbiterF * 8003033561266164387U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 309935535526750396U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13991265868040011411U;
            aOrbiterG = RotL64((aOrbiterG * 2887531132228588441U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1755976294857114222U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2259275858478396846U;
            aOrbiterI = RotL64((aOrbiterI * 7416165760067878161U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4838175912944552936U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12307900457200936013U;
            aOrbiterE = RotL64((aOrbiterE * 14719363144850838805U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 18025411832912225805U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 981375022769564523U;
            aOrbiterD = RotL64((aOrbiterD * 15869361544011831483U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3174014054982742562U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8119692378748963609U;
            aOrbiterH = RotL64((aOrbiterH * 3072354179707448489U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14502863160788675807U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1207582534593709516U;
            aOrbiterC = RotL64((aOrbiterC * 3045412087535529357U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5838011917777875072U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 434594114594643600U;
            aOrbiterJ = RotL64((aOrbiterJ * 1591023655239709931U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15711060039063734443U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8307150522686198490U;
            aOrbiterA = RotL64((aOrbiterA * 2082452039297764679U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5805686529930815226U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10726035965553989335U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5563221485243331689U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 40U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 20U) + aOrbiterH) + RotL64(aOrbiterG, 41U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 37U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 44U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 29U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterB, 27U));
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 13U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterE, 48U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 18U) + aOrbiterE) + RotL64(aOrbiterH, 23U)) + aPhaseFWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 57U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 42U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aExpandLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aExpandLaneA forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16457U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneA[((aIndex + 19670U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20660U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17150U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneD[((aIndex + 19287U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererE + RotL64(aCross, 21U)) + 2974056819475622600U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 42U)) + RotL64(aCarry, 57U)) + 7345051759236356098U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 12738468816846628882U) + aPhaseFOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aScatter, 27U)) + 7694520596043297922U;
            aOrbiterE = (aWandererH + RotL64(aCross, 23U)) + 5530753590015084774U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 40U)) + 3776309161718383105U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 5U)) + 784780304358106404U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 57U)) + 8999942326995036509U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 19U)) + 5194986506064092779U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 7920040007459652762U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 37U)) + 11311997270710107937U) + aPhaseFOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5365231114813547251U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8630110234623825263U;
            aOrbiterG = RotL64((aOrbiterG * 2735881715888325759U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2358235238039571072U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 18059414891616491807U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17150786106857185467U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14526050556461782864U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6937282036603272474U;
            aOrbiterF = RotL64((aOrbiterF * 14954512365270028029U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10105832250694931310U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3884223553012098137U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16340956813003906195U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10385284339549648087U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1257633893341505930U;
            aOrbiterE = RotL64((aOrbiterE * 2669950791270500977U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5528890519572824318U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15664241747527713256U;
            aOrbiterA = RotL64((aOrbiterA * 16670884497088220497U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14264122979415331887U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17985061405540198036U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2729487440173395133U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1663986734997903415U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3706166884286400587U;
            aOrbiterJ = RotL64((aOrbiterJ * 10549736618301955745U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12736963182099961466U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 95411267612114381U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8011937916302325057U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4966620136499917388U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8478316876240452401U;
            aOrbiterH = RotL64((aOrbiterH * 13297718919105366563U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11123814701411614557U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2974056819475622600U;
            aOrbiterC = RotL64((aOrbiterC * 5913569942407618997U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterE, 42U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 20U) + aOrbiterG) + RotL64(aOrbiterF, 5U));
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterK, 11U));
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 24U) + aOrbiterB) + RotL64(aOrbiterD, 26U));
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 13U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterI, 51U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aExpandLaneB
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26598U)) & S_BLOCK1], 40U) ^ RotL64(aSnowLaneB[((aIndex + 24486U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 23470U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22311U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 24009U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 4U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererC + RotL64(aCross, 41U)) + 12809562813316740345U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 58U)) + 17084212535326321199U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 3U)) + 16074921689983846769U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 53U)) + 14027986153007120145U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 29U)) + 7633455951809250227U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 340989348513370174U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 35U)) + 5307820377645020116U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 18U)) + 5605285015771527274U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 5293500434746182790U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 27U)) + 7263156475892261811U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 10672879570907433005U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16659226780900986107U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9774892622769850665U;
            aOrbiterC = RotL64((aOrbiterC * 7487477727543183211U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10728057184108279042U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5032485856947407217U;
            aOrbiterD = RotL64((aOrbiterD * 16651577903809154285U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14642241075374862345U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8386481273395203518U;
            aOrbiterI = RotL64((aOrbiterI * 11649977733867003445U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2874153265304098104U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11519900149177261000U;
            aOrbiterA = RotL64((aOrbiterA * 2010158758971864505U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8885690878540115768U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4482143389870987714U;
            aOrbiterG = RotL64((aOrbiterG * 7105332459437434281U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 17469068567801886615U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 5121422018622394837U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14823827133212643467U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3130788210672745618U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6139244627510113216U;
            aOrbiterK = RotL64((aOrbiterK * 2640754184921507389U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10488511756324474710U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1760223670304953696U;
            aOrbiterB = RotL64((aOrbiterB * 4007062295003769311U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2232708414171096783U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17497492434939621063U;
            aOrbiterF = RotL64((aOrbiterF * 9850565931511937725U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8199114561613022892U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15432482434863050835U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14271143436318169871U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14991531324947777062U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12809562813316740345U;
            aOrbiterE = RotL64((aOrbiterE * 4487021480964944879U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 30U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 34U) + aOrbiterG) + RotL64(aOrbiterI, 43U));
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterK, 23U)) + aPhaseFWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterH, 35U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 11U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 40U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aCross, 50U) + aOrbiterI) + RotL64(aOrbiterD, 51U)) + aPhaseFWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 21U)) + aOrbiterH) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32291U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 31861U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 29853U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29206U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32433U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererG + RotL64(aPrevious, 23U)) + 16160838483846078448U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 54U)) + 15404960896190227946U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 11U)) + 16904160594024977199U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 51U)) + 17790460246821031802U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 16395168254086971959U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 7484373204039901786U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 3U)) + 18026814691322913510U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 15244817793136966450U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 42U)) + 5795491730356335666U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 27U)) + 3163873518027801504U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 5U)) + 2690791759507349172U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17898067251167087906U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8028010015006604239U;
            aOrbiterA = RotL64((aOrbiterA * 5601629670521300241U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7304739457289910555U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6476837815096530043U;
            aOrbiterE = RotL64((aOrbiterE * 16380545138701113267U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14242499233467960602U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 17305645693017634630U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14442976693206929569U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9772864059444171908U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7897200728282156408U;
            aOrbiterH = RotL64((aOrbiterH * 816306719390807411U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4890999319172950996U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8165132649356094963U;
            aOrbiterJ = RotL64((aOrbiterJ * 17297706071263690189U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9342923520083533265U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7213639583505088067U;
            aOrbiterI = RotL64((aOrbiterI * 1349251979649428909U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4079475132684197272U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3350998022472827283U;
            aOrbiterG = RotL64((aOrbiterG * 948841791460066265U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2479140576609216238U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7703147534931674972U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11419116495223970801U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9050277787914448469U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13295888852307317371U;
            aOrbiterC = RotL64((aOrbiterC * 3027097172772140975U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15380254190549884741U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17653690414528791774U;
            aOrbiterK = RotL64((aOrbiterK * 15923958179714368315U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6825072759468337036U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16160838483846078448U;
            aOrbiterD = RotL64((aOrbiterD * 11690325563580492415U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 52U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterB, 21U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterF, 56U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterH, 19U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterG, 11U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 30U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 39U));
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 50U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterK, 43U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 54U) + RotL64(aOrbiterK, 47U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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

void TwistExpander_WaterPolo_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7071U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 8001U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 4297U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1732U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7804U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 3190U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererE + RotL64(aIngress, 38U)) + RotL64(aCarry, 23U)) + 6342299552323486695U) + aPhaseGOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 12692748514781367538U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aScatter, 57U)) + 8202639945493229155U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 4439975701793231639U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 19U)) + 16774235182859553759U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8764155413335405667U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7167848811974967685U;
            aOrbiterH = RotL64((aOrbiterH * 1052856924757654735U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16768278912125334220U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9090838954826296201U;
            aOrbiterF = RotL64((aOrbiterF * 5459329624017272077U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 7644075729758006298U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 17326182797908071215U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2408330168749256075U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16158809721888137555U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8029938783858263694U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12628072435324195483U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8716553521415553404U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7012599977009208840U;
            aOrbiterA = RotL64((aOrbiterA * 8775355876188948851U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 46U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 14U) + aOrbiterC) + RotL64(aOrbiterA, 3U)) + aPhaseGWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 46U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9981U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 9681U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10773U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9333U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12933U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14156U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 40U) ^ RotL64(aCross, 21U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 6733949564325516029U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 7304098437143918796U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 28U)) + 3923949518391777800U) + aPhaseGOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 14243591003388927124U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aIngress, 5U)) + 18329498724605410406U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13118172167747037249U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5272025143849174212U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9935990954321437743U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16075917179214318424U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15263590648674658399U;
            aOrbiterF = RotL64((aOrbiterF * 9918239923411740337U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13730046728289525921U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7703141464499623408U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5886009900621521987U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1382279753822135359U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 2973369221699098292U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7440242040663550631U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11578274119583013219U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3419411247737896674U;
            aOrbiterG = RotL64((aOrbiterG * 17814942652262802991U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterF, 3U));
            aWandererI = aWandererI + (((RotL64(aCross, 38U) + RotL64(aOrbiterK, 11U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 57U)) + aOrbiterK) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 35U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterD, 44U)) + aPhaseGWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19919U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 19932U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 19680U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18210U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21060U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 19141U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 9774364261626083532U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 47U)) + 18059001521926116420U) + aPhaseGOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 10615626210406381148U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 6U)) + RotL64(aCarry, 41U)) + 10536484278007898620U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 39U)) + 13320663045139972700U) + aPhaseGOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17127001787268166583U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16742574590844166551U;
            aOrbiterH = RotL64((aOrbiterH * 17828964140627204983U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8347719720758228053U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13502468705946051986U;
            aOrbiterI = RotL64((aOrbiterI * 13822952083584784695U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3512687886188904904U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 495660316165795934U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6724596801190194913U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5092722552034477356U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15641128019608284015U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3621036395703527059U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15421873776811085458U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17978775513204574125U;
            aOrbiterF = RotL64((aOrbiterF * 18359600395119440183U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 42U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 52U)) + aOrbiterE) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 13U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 20U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25094U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 27049U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 26729U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31744U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26977U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24981U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 24U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 1888427424966603593U) + aPhaseGOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 5436761445660415091U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 5U)) + 17322876217962143270U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 56U)) + RotL64(aCarry, 5U)) + 9728299982740564979U) + aPhaseGOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aPrevious, 39U)) + 301720335271716921U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8069685428854814396U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1973715500949100991U;
            aOrbiterD = RotL64((aOrbiterD * 7940531594430629427U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 87666408799854155U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12195436904339035245U;
            aOrbiterK = RotL64((aOrbiterK * 15427739165893738105U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4578742069143400295U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7828776048774876484U;
            aOrbiterB = RotL64((aOrbiterB * 4047964518501081039U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17203146364542781833U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16913369550858890466U;
            aOrbiterC = RotL64((aOrbiterC * 13534417587921978507U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9632761514552265402U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9106637671877341286U;
            aOrbiterA = RotL64((aOrbiterA * 9073709119482640391U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 40U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 27U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererC, 52U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_WaterPolo_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1350U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 5079U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5362U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3813U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6442U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 2993U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aIngress, 53U)) + (RotL64(aCross, 39U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 1210605127156905516U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 11964595428173569519U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 16277319029916258482U) + aPhaseHOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 3U)) + 12369497463101824572U) + aPhaseHOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 30U)) + 6201248574067068202U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1727477025667206661U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1404510627789806851U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4810039298122529021U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6948213591282018925U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6688865181284421478U;
            aOrbiterC = RotL64((aOrbiterC * 12619122841662247279U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 3351130769402360855U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12681032488906270823U;
            aOrbiterJ = RotL64((aOrbiterJ * 3680893896579741263U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3591412591193726763U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16153817571210878589U;
            aOrbiterD = RotL64((aOrbiterD * 4165137036092246349U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3808228354421006630U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1427373776207504205U;
            aOrbiterK = RotL64((aOrbiterK * 4534374093769595531U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterC, 27U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 18U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aCross, 30U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12114U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 13729U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16079U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10040U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15575U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 16252U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 9023059520606551446U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 39U)) + 662441755115638133U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 12U)) + RotL64(aCarry, 57U)) + 16957253361196144712U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 7840955025765308605U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 57U)) + 346855809270395799U) + aPhaseHOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16099139781586668343U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3706457327118322098U;
            aOrbiterK = RotL64((aOrbiterK * 7810030620470889591U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12166825885547622870U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7792658665720344200U;
            aOrbiterJ = RotL64((aOrbiterJ * 16305542632794270697U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7128477606152986326U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11116533962780290084U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11993485572912492297U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10443889548568288532U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 4402387036946561017U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9032964741841833277U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13002706161178447654U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13929727277530310708U;
            aOrbiterH = RotL64((aOrbiterH * 7005639090871200285U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 41U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 50U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE) + aPhaseHWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterE, 58U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23937U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 20779U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 17715U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18043U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21124U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21354U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 50U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 3236820517816085022U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 741288875914097926U) + aPhaseHOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aIngress, 3U)) + 8417246926007729580U) + aPhaseHOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 9715717805774537170U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 20U)) + 14360243844821619482U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10760908100206775334U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3434641779946167811U;
            aOrbiterB = RotL64((aOrbiterB * 3305698324169010803U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7885568822756234567U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3041563437672051294U;
            aOrbiterE = RotL64((aOrbiterE * 11440300917533482297U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15761355327564963516U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1158633562785937421U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15511324886867188235U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9338581575871970653U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 9172038894262857354U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3110871165285625807U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14653924713599790081U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 3854497592598563309U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11737111068815795303U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 4U);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + aPhaseHWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 28U) + aOrbiterH) + RotL64(aOrbiterE, 36U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + aPhaseHWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27381U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 28246U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 30580U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27275U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30540U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24697U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 15045917390223766480U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 10763054007033668758U) + aPhaseHOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 14U)) + 13190170142593666607U) + aPhaseHOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 9657025731441167065U;
            aOrbiterC = (aWandererF + RotL64(aCross, 5U)) + 11433367178975954211U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17904920143996810366U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3244383020512113283U;
            aOrbiterG = RotL64((aOrbiterG * 552521443123433353U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6538815775171139091U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7195368312757976343U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10515679176134176565U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18134430713910279374U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6571776588427107976U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11916502085252589161U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11830778129647517758U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 9793702760907767365U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4096246227968677179U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2287235876793192036U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8951959188326141794U;
            aOrbiterE = RotL64((aOrbiterE * 9968356718110753845U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 6U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 44U) + RotL64(aOrbiterE, 4U)) + aOrbiterG) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 21U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterF, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
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
